/**
  Sprite Editor
*/
#include "sprite_editor_core.h"
#include "sprite_editor.h"
#include "statebox.h"
#include <QtWidgets/QGraphicsPixmapItem>
#include <functional>

/**
  �X�v���C�g�G�f�B�^�p�̖��O���.
*/
namespace SpriteEditor {

enum ChipListColumnId {
  Left,
  Top,
  Width,
  Height,
  XPos,
  YPos,
  XOffset,
  YOffset,
  XScale,
  YScale,
  Rotation,
};

enum EditSceneCustomDataId {
  ItemType
};

enum EditSceneItemType {
  ChipPicture
};

void drawDashFrame(QPixmap* pixmap, const QColor& color)
{
  QPainter p;
  QPen  pen(color);
  pen.setStyle(Qt::DashLine);
  p.begin(pixmap);
  p.setPen(pen);
  p.drawRect(0, 0, pixmap->width() - 1, pixmap->height() - 1);
  p.end();
}

QPixmap copyPixmap(const QPixmap& pixmap, const Rect& rect)
{
    const Float width = rect.right - rect.left;
    const Float height = rect.bottom - rect.top;
    QPixmap tmp = pixmap.copy(rect.left, rect.top, width, height);
    drawDashFrame(&tmp, QColor(0xff, 0, 0, 0x7f));
    return tmp;
}

/**
  �`�b�v�f�[�^����ϊ��s����쐬����.

  @param  chip ���ɂȂ�`�b�v�f�[�^.
  @return �`�b�v�f�[�^�̉�]�E�g�k�p�����[�^����쐬���ꂽ�ϊ��s��.
*/
QTransform makeTransformMatrix(const Chip& chip)
{
  QTransform mtx;
  const Float centerX = (chip.rect.right - chip.rect.left) / Float(2);
  const Float centerY = (chip.rect.bottom - chip.rect.top) / Float(2);
  mtx.translate(chip.center.x - centerX, chip.center.y - centerY);
  mtx.scale(chip.scale.x, chip.scale.y);
  mtx.rotate(chip.angle);
  return mtx;
}

/**
  �R���X�g���N�^.
*/
Main::Main(QWidget* parent) :
  QMainWindow(parent),
  pUi(new Ui::MainWindow),
  pTextureImage(new QPixmap(1, 1)),
  pStateBox(new StateBox),
  pTextureScene(new QGraphicsScene),
  pEditScene(new QGraphicsScene),
  chipPtrList(),
  currentSheetIndex(0)
{
  pUi->setupUi(this);
  pStateBox->setPos(200, 200);
  pTextureScene->addPixmap(*pTextureImage);
  pTextureScene->addItem(pStateBox.get());
  pUi->textureView->setScene(pTextureScene.get());
  pUi->editView->setScene(pEditScene.get());
  pUi->sheetList->verticalHeader()->resizeSection(0, 128);
  pUi->sheetList->horizontalHeader()->setDefaultSectionSize(128);
  pUi->sheetList->setIconSize(QSize(128, 128));
  insertSheet();

  pEditScene->addLine(0, 255, 512, 255);
  pEditScene->addLine(255, 0, 255, 512);

  connect(pUi->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(pUi->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
  connect(pUi->actionOpenTexture, SIGNAL(triggered()), this, SLOT(openTextureFile()));
  connect(pUi->actionInsertChip, SIGNAL(triggered()), this, SLOT(insertChip()));
  connect(pUi->actionDeleteChip, SIGNAL(triggered()), this, SLOT(deleteChip()));
  connect(pUi->actionInsertSheet, SIGNAL(triggered()), this, SLOT(insertSheet()));
  connect(pUi->actionDeleteSheet, SIGNAL(triggered()), this, SLOT(deleteSheet()));
  connect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
  connect(pUi->sheetList, SIGNAL(itemSelectionChanged()), this, SLOT(onSheetListSelectionChanged()));
  connect(pUi->sheetList, SIGNAL(cellChanged(int,int)), this, SLOT(onSheetListCellChanged(int, int)));
  setChipInsertionEnabled(false);
}

/**
  �`�b�v�̑}���E�폜�̗L���E������ݒ肷��.

  @param  flag  - true  �L���ɂ���.
                - false �����ɂ���.
*/
void Main::setChipInsertionEnabled(bool flag)
{
  pUi->actionInsertChip->setEnabled(flag);
  pUi->actionDeleteChip->setEnabled(flag);
  pUi->actionInsertSheet->setEnabled(flag);
  pUi->actionDeleteSheet->setEnabled(flag);
}

/**
  �w�肳�ꂽ�X�v���C�g�V�[�g�f�[�^���r���[�ɔ��f����.

  @param  imageIndex  �X�v���C�g�V�[�g�̃C���f�b�N�X.
*/
void Main::setAnimation(size_t imageIndex)
{
  if (imageIndex >= animation.sheetList.size()) {
    return;
  }
  disconnect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
  clearChipListView();
  for (auto i : animation.sheetList[imageIndex].chipList) {
    insertChip(i);
  }
  updateSheetPicture(getCurrentSheetIndex());
  connect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
}

/**
  �X�v���C�g�f�[�^�t�@�C�����J��.
*/
void Main::openFile()
{
  QString filename = QFileDialog::getOpenFileName(
    this,
    tr("Open Sprite data file"),
    QString(),
    tr("Sprite data files (*.knsp);;All Files (*)")
  );
  if (filename.isEmpty()) {
    return;
  }
  LoadFromFile(filename.toLocal8Bit(), &animation);

  // �r���[�̓��e���Đݒ肷��.
  clearSheetList();
  clearChipListView();
  insertSheet();
  setAnimation(0);
}

/**
  �X�v���C�g�f�[�^�t�@�C����ۑ�����.
*/
void Main::saveFile()
{
  QString filename = QFileDialog::getSaveFileName(
    this,
    tr("Save Sprite data file"),
    QString(),
    tr("Sprite data files (*.knsp);;All Files (*)")
  );
  if (filename.isEmpty()) {
    return;
  }
  SaveToFile(filename.toLocal8Bit(), animation);
}

/**
  �e�N�X�`���t�@�C�����J��.
*/
void Main::openTextureFile()
{
  QString filename = QFileDialog::getOpenFileName(
    this,
    tr("Open Texture File"),
    QString(),
    tr("Texture Files (*.png *.jpg *.bmp);;All Files (*)")
  );
  if (filename.isEmpty()) {
    return;
  }
  QImage image;
  if (!image.load(filename)) {
    QMessageBox::information(this, tr("Unable to open file."), filename);
    return;
  }
  pTextureImage->convertFromImage(image, Qt::ColorOnly);
  pTextureScene->setSceneRect(0, 0, image.width(), image.height());
  pUi->textureView->setMinimumSize(image.width(), image.height());
  pUi->textureView->repaint();
  pUi->textureDock->setWindowTitle(filename + '(' + QString::number(image.width()) + ',' + QString::number(image.height()) + ')');

  setAnimation(getCurrentSheetIndex());

  setChipInsertionEnabled(true);
}

/**
  �I��͈͂��V�[�g�ɒǉ�����.

  �e�N�X�`���r���[�̑I��͈͂��X�v���C�g�`�b�v�Ƃ��āA���ݑI������Ă���V�[�g�ɒǉ�����.
*/
void Main::insertChip()
{
  const float x = pStateBox->pos().x();
  const float y = pStateBox->pos().y();
  const float w = pStateBox->size().x();
  const float h = pStateBox->size().y();
  const int imageIndex = getCurrentSheetIndex();
  const Rect rect(x, y, x + w, y + h);
  const Point2 position(0, 0);
  const Vector2 offset(0, 0);
  const Vector2 scale(1, 1);
  Sheet::ChipList& chipList = animation.sheetList[imageIndex].chipList;
  chipList.insert(chipList.begin() + getCurrentChipIndex(), Chip(rect, position, offset, scale));
  disconnect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
  insertChip(chipList[getCurrentChipIndex()]);
  updateSheetPicture(getCurrentSheetIndex());
  connect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
}

/**
  �`�b�v�摜���ڃN���X.

  �`�b�v�r���[�ɕ\�������A�`�b�v���X�g�̊e��ɑΉ�����`�b�v�摜����.
<pre>
    +-------+
    |       |
  O-+---*   |
    |       |
    +-------+

  O  ��]�E�g�k�̊���W.
  *  �摜�̒��S���W.
</pre>
*/
class ChipItem : public QGraphicsPixmapItem {
public:
  typedef std::function<void(const QPointF&, const ChipItem&)> FuncType;

  ChipItem(FuncType func, const QPixmap& pixmap, QGraphicsItem* parent = 0) :
    func_(func),
    QGraphicsPixmapItem(pixmap, parent)
  {
    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    setOffset(0, 0);
    setData(ItemType, QVariant(ChipPicture));
  }

private:
  QVariant itemChange(GraphicsItemChange change, const QVariant& value) {
    if (change == ItemPositionChange) {
      func_(value.toPointF(), *this);
    }
    return QGraphicsPixmapItem::itemChange(change, value);
  }

private:
  FuncType func_;
};

/**
  �w�肳�ꂽ�f�[�^���V�[�g�ɒǉ�����.

  @param  rect �e�N�X�`���͈�.
  @param  pos  �`�b�v�z�u���W.
  @param  offset �`�b�v��]�g�k���S���W.
  @param  scale �`�b�v�g�k��.
*/
void Main::insertChip(const Chip& chip)
{
  const int row = getCurrentChipIndex();
  pUi->chipList->insertRow(row);
  pUi->chipList->setItem(row, Left, new QTableWidgetItem(tr("%1").arg(chip.rect.left)));
  pUi->chipList->setItem(row, Top, new QTableWidgetItem(tr("%1").arg(chip.rect.top)));
  pUi->chipList->setItem(row, Width, new QTableWidgetItem(tr("%1").arg(chip.rect.right - chip.rect.left)));
  pUi->chipList->setItem(row, Height, new QTableWidgetItem(tr("%1").arg(chip.rect.bottom - chip.rect.top)));
  pUi->chipList->setItem(row, XPos, new QTableWidgetItem(tr("%1").arg(chip.position.x)));
  pUi->chipList->setItem(row, YPos, new QTableWidgetItem(tr("%1").arg(chip.position.y)));
  pUi->chipList->setItem(row, XOffset, new QTableWidgetItem(tr("%1").arg(chip.center.x)));
  pUi->chipList->setItem(row, YOffset, new QTableWidgetItem(tr("%1").arg(chip.center.y)));
  pUi->chipList->setItem(row, XScale, new QTableWidgetItem(tr("%1").arg(chip.scale.x)));
  pUi->chipList->setItem(row, YScale, new QTableWidgetItem(tr("%1").arg(chip.scale.y)));
  pUi->chipList->setItem(row, Rotation, new QTableWidgetItem(tr("%1").arg(chip.angle)));

  ChipItem* pItem = new ChipItem(
    ChipItem::FuncType([this](const QPointF& point, const ChipItem& item){ onChangeChipItem(point, item); }),
    copyPixmap(*pTextureImage, chip.rect)
  );
  pItem->setPos(chip.position.x, chip.position.y);
  pItem->setTransform(makeTransformMatrix(chip));
  pEditScene->addItem(pItem);
  chipPtrList.insert(chipPtrList.begin() + row, pItem);
}

void Main::onChangeChipItem(const QPointF& point, const ChipItem& item)
{
  const auto itr = std::find(chipPtrList.begin(), chipPtrList.end(), &item);
  if (itr != chipPtrList.end()) {
    disconnect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
    const int row = itr - chipPtrList.begin();
    QTableWidgetItem* pLeftItem = pUi->chipList->item(row, XPos);
    if (pLeftItem) {
      pLeftItem->setText(QString::number(point.x()));
    }
    QTableWidgetItem* pTopItem = pUi->chipList->item(row, YPos);
    if (pTopItem) {
      pTopItem->setText(QString::number(point.y()));
    }
    Chip& chip = animation.sheetList[getCurrentSheetIndex()].chipList[row];
    chip.position.x = point.x();
    chip.position.y = point.y();
    connect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
    updateSheetPicture(getCurrentSheetIndex());
  }
}

/**
  �`�b�v���X�g�r���[�őI������Ă���`�b�v���V�[�g����폜����.
*/
void Main::deleteChip()
{
  for (auto range : pUi->chipList->selectedRanges()) {
    const int row = range.topRow();
    pEditScene->removeItem(chipPtrList[row]);
    chipPtrList.erase(chipPtrList.begin() + row); // �f�[�^����폜.
    for (int i = 0; i < range.rowCount(); ++i) {
      pUi->chipList->removeRow(row);
    }
  }
}

/**
  �`�b�v���X�g�r���[����ɂ���.

  �`�b�v���X�g�r���[�Đݒ�̂��߂̃w���p�֐�. �V�[�g�f�[�^����͍폜����Ȃ����Ƃɒ���.
*/
void Main::clearChipListView()
{
  pUi->chipList->setRowCount(0);
  for (auto i : chipPtrList) {
    pEditScene->removeItem(i);
  }
  chipPtrList.clear();
}

/**
  �V�[�g��ǉ�����.

  �V�[�g���X�g�ɂ���̃X�v���C�g�V�[�g��ǉ�����.
*/
void Main::insertSheet()
{
  animation.sheetList.insert(animation.sheetList.begin() + getCurrentSheetIndex(), Sheet());
  pUi->sheetList->insertColumn(getCurrentSheetIndex());
  if (pUi->sheetList->rowCount() == 1) {
    pUi->sheetList->setRangeSelected(QTableWidgetSelectionRange(0, 0, 1, 1), true);
  }
}

/**
  �V�[�g���X�g�őI������Ă���V�[�g���폜����.
*/
void Main::deleteSheet()
{
  for (auto range : pUi->sheetList->selectedRanges()) {
    const int col = range.leftColumn();
    animation.sheetList.erase(animation.sheetList.begin() + col); // �f�[�^����폜.
    for (int i = 0; i < range.columnCount(); ++i) {
      pUi->sheetList->removeColumn(col);
    }
  }
}

/**
  �V�[�g���X�g�r���[����ɂ���.
*/
void Main::clearSheetList()
{
  animation.sheetList.clear(); // �f�[�^����ɂ���.
  pUi->sheetList->clear();
  pUi->sheetList->setColumnCount(0);
}

/**
  ���ݑI������Ă���V�[�g�̃C���f�b�N�X���擾����.

  @return ���ݑI������Ă���V�[�g�̃C���f�b�N�X.
*/
int Main::getCurrentSheetIndex() const
{
  return currentSheetIndex;
}

/**
  ���ݑI������Ă���`�b�v�̃C���f�b�N�X���擾����.
*/
int Main::getCurrentChipIndex() const
{
  const int index = pUi->chipList->currentRow();
  return index >= 0 ? index : 0;
}

void Main::updateSheetPicture(int index)
{
  QPixmap  image(512, 512);
  QPainter  painter(&image);
  painter.setRenderHint(QPainter::Antialiasing);
  pEditScene->render(&painter);
  QTableWidgetItem* pItem = new QTableWidgetItem(QIcon(image), "");
  pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
  pUi->sheetList->setItem(0, index, pItem);
  pUi->sheetList->setItem(1, index, new QTableWidgetItem(tr("1")));
}

/**
  �`�b�v���X�g�r���[�̒l���X�V���ꂽ.
*/
void Main::onChipListChanged(int row, int column)
{
  const QTableWidgetItem& item = *pUi->chipList->item(row, column);
  const Float value = item.text().toFloat();
  Chip& chip = animation.sheetList[getCurrentSheetIndex()].chipList[row];
  QGraphicsPixmapItem* pPixmap = chipPtrList[row];
  switch(column) {
  case Left:
    chip.rect.right += value - chip.rect.left;
    chip.rect.left = value;
    pPixmap->setPixmap(copyPixmap(*pTextureImage, chip.rect));
    break;
  case Top:
    chip.rect.bottom += value - chip.rect.top;
    chip.rect.top = value;
    pPixmap->setPixmap(copyPixmap(*pTextureImage, chip.rect));
    break;
  case Width:
    chip.rect.right = chip.rect.left + value;
    pPixmap->setPixmap(copyPixmap(*pTextureImage, chip.rect));
    break;
  case Height:
    chip.rect.bottom = chip.rect.top + value;
    pPixmap->setPixmap(copyPixmap(*pTextureImage, chip.rect));
    break;
  case XPos:
    chip.position.x = value;
    pPixmap->setPos(chip.position.x, chip.position.y);
    break;
  case YPos:
    chip.position.y = value;
    pPixmap->setPos(chip.position.x, chip.position.y);
    break;
  case XOffset:
    chip.center.x = value;
    pPixmap->setTransform(makeTransformMatrix(chip));
    break;
  case YOffset:
    chip.center.y = value;
    pPixmap->setTransform(makeTransformMatrix(chip));
    break;
  case XScale:
    chip.scale.x = value;
    pPixmap->setTransform(makeTransformMatrix(chip));
    break;
  case YScale:
    chip.scale.y = value;
    pPixmap->setTransform(makeTransformMatrix(chip));
    break;
  case Rotation:
    chip.angle = value;
    pPixmap->setTransform(makeTransformMatrix(chip));
    break;
  }
  updateSheetPicture(getCurrentSheetIndex());
}

void Main::onSheetListCellChanged(int row, int column)
{
  if (row == 1/* index of frames item */) {
    const QTableWidgetItem& item = *pUi->sheetList->item(row, column);
    animation.sheetList[column].frames = item.text().toInt();
  }
}

void Main::onSheetListSelectionChanged()
{
  currentSheetIndex = pUi->sheetList->currentColumn();
  setAnimation(currentSheetIndex);
}

} // namespace SpriteEditor

/**
  �G���g���|�C���g.
*/
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  SpriteEditor::Main* pMainWindow = new SpriteEditor::Main();
  pMainWindow->show();

  return app.exec();
}
