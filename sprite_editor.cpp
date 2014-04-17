/**
  Sprite Editor
*/
#include "sprite_editor_core.h"
#include "sprite_editor.h"
#include "statebox.h"
#include "editscene.h"
#include <QtWidgets/QGraphicsPixmapItem>

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
  �R���X�g���N�^.
*/
Main::Main(QWidget* parent) :
  QMainWindow(parent),
  pUi(new Ui::MainWindow),
  pTextureImage(new QPixmap(1, 1)),
  pStateBox(new StateBox),
  pTextureScene(new QGraphicsScene),
  pEditScene(new EditScene)
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

  connect(pUi->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(pUi->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
  connect(pUi->actionOpenTexture, SIGNAL(triggered()), this, SLOT(openTextureFile()));
  connect(pUi->actionInsertChip, SIGNAL(triggered()), this, SLOT(insertChip()));
  connect(pUi->actionDeleteChip, SIGNAL(triggered()), this, SLOT(deleteChip()));
  connect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
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
  clearChipListView();
  for (auto i : animation.sheetList[imageIndex].chipList) {
    insertChip(i.rect, i.position, i.center, i.scale);
  }
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
  animation.sheetList[imageIndex].chipList.push_back(Chip(rect, position, offset, scale));
  insertChip(rect, position, offset, scale);
}

/**
  �w�肳�ꂽ�f�[�^���V�[�g�ɒǉ�����.

  @param  rect �e�N�X�`���͈�.
  @param  pos  �`�b�v�z�u���W.
  @param  offset �`�b�v��]�g�k���S���W.
  @param  scale �`�b�v�g�k��.
*/
void Main::insertChip(const Rect& rect, const Point2& pos, const Vector2& offset, const Vector2& scale)
{
  disconnect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));

  const int row = getCurrentChipIndex();
  pUi->chipList->insertRow(row);
  pUi->chipList->setItem(row, Left, new QTableWidgetItem(tr("%1").arg(rect.left)));
  pUi->chipList->setItem(row, Top, new QTableWidgetItem(tr("%1").arg(rect.top)));
  pUi->chipList->setItem(row, Width, new QTableWidgetItem(tr("%1").arg(rect.right - rect.left)));
  pUi->chipList->setItem(row, Height, new QTableWidgetItem(tr("%1").arg(rect.bottom - rect.top)));
  pUi->chipList->setItem(row, XPos, new QTableWidgetItem(tr("%1").arg(pos.x)));
  pUi->chipList->setItem(row, YPos, new QTableWidgetItem(tr("%1").arg(pos.y)));
  pUi->chipList->setItem(row, XOffset, new QTableWidgetItem(tr("%1").arg(offset.x)));
  pUi->chipList->setItem(row, YOffset, new QTableWidgetItem(tr("%1").arg(offset.y)));
  pUi->chipList->setItem(row, XScale, new QTableWidgetItem(tr("%1").arg(scale.x)));
  pUi->chipList->setItem(row, YScale, new QTableWidgetItem(tr("%1").arg(scale.y)));
  pUi->chipList->setItem(row, Rotation, new QTableWidgetItem(tr("0")));

  QGraphicsPixmapItem* pItem = pEditScene->addPixmap(copyPixmap(*pTextureImage, rect));
  pItem->setOffset(0, 0);
  chipPtrList.insert(chipPtrList.begin() + row, pItem);
  updateSheetPicture(getCurrentSheetIndex());

  connect(pUi->chipList, SIGNAL(cellChanged(int,int)), this, SLOT(onChipListChanged(int, int)));
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
  animation.sheetList.push_back(Sheet());
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
  const int index = pUi->sheetList->currentColumn();
  return index >= 0 ? index : 0;
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
  pUi->sheetList->setItem(
    index,
    0,
    new QTableWidgetItem(
      QIcon(
        image
      ),
      ""
    )
  );
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
    pPixmap->setOffset(chip.position.x, chip.position.y);
    break;
  case YPos:
    chip.position.y = value;
    pPixmap->setOffset(chip.position.x, chip.position.y);
    break;
  case XOffset:
    chip.center.x = value;
    break;
  case YOffset:
    chip.center.y = value;
    break;
  case XScale:
    chip.scale.x = value;
    break;
  case YScale:
    chip.scale.y = value;
    break;
  case Rotation:
    chip.angle = value;
    break;
  }
  updateSheetPicture(getCurrentSheetIndex());
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
