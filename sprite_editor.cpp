/**
  Sprite Editor
*/
#include "sprite_editor_core.h"
#include "sprite_editor.h"
#include "statebox.h"
#include <QtWidgets/QGraphicsPixmapItem>

/**
  �X�v���C�g�G�f�B�^�p�̖��O���.
*/
namespace SpriteEditor {

/**
  �R���X�g���N�^.
*/
Main::Main(QWidget* parent) :
  QMainWindow(parent),
  pUi(new Ui::MainWindow),
  pTextureImage(new QPixmap(1, 1)),
  pStateBox(new StateBox),
  pTextureScene(new QGraphicsScene),
  pEditScene(new QGraphicsScene)
{
  pUi->setupUi(this);
  pStateBox->setPos(200, 200);
  pTextureScene->addPixmap(*pTextureImage);
  pTextureScene->addItem(pStateBox.get());
  pUi->textureView->setScene(pTextureScene.get());
  pUi->editView->setScene(pEditScene.get());
  insertSheet();

  connect(pUi->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(pUi->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
  connect(pUi->actionOpenTexture, SIGNAL(triggered()), this, SLOT(openTextureFile()));
  connect(pUi->actionInsertChip, SIGNAL(triggered()), this, SLOT(insertChip()));
  connect(pUi->actionDeleteChip, SIGNAL(triggered()), this, SLOT(deleteChip()));
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
  clearChipList();
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
  clearSheetList();
  clearChipList();
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
}

/**
  �I��͈͂��V�[�g�ɒǉ�����.

  �e�N�X�`���r���[�̑I��͈͂��X�v���C�g�`�b�v�Ƃ��Č��ݑI������Ă���V�[�g�ɒǉ�����.
*/
void Main::insertChip()
{
  const float x = pStateBox->pos().x();
  const float y = pStateBox->pos().y();
  const float w = pStateBox->size().x();
  const float h = pStateBox->size().y();
  const int imageIndex = pUi->sheetList->selectionModel()->currentIndex().column();
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
  enum ChipListColumnId {
    Left,
    Top,
    Width,
    Height,
    XPos,
    YPos,
    XOffset,
    YOffset
  };
  pUi->chipList->insertRow(0);
  pUi->chipList->setItem(0, Left, new QTableWidgetItem(tr("%1").arg(rect.left)));
  pUi->chipList->setItem(0, Top, new QTableWidgetItem(tr("%1").arg(rect.top)));
  pUi->chipList->setItem(0, Width, new QTableWidgetItem(tr("%1").arg(rect.right - rect.left)));
  pUi->chipList->setItem(0, Height, new QTableWidgetItem(tr("%1").arg(rect.bottom - rect.top)));
  pUi->chipList->setItem(0, XPos, new QTableWidgetItem(tr("%1").arg(pos.x)));
  pUi->chipList->setItem(0, YPos, new QTableWidgetItem(tr("%1").arg(pos.y)));
  pUi->chipList->setItem(0, XOffset, new QTableWidgetItem(tr("%1").arg(offset.x)));
  pUi->chipList->setItem(0, YOffset, new QTableWidgetItem(tr("%1").arg(offset.y)));

  QGraphicsPixmapItem* pItem = pEditScene->addPixmap(
    pTextureImage->copy(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top)
  );
  pItem->setOffset(0, 0);
  chipPtrList.push_back(pItem);
}

/**
  �`�b�v���X�g�r���[�őI������Ă���`�b�v���V�[�g����폜����.
*/
void Main::deleteChip()
{
  for (auto range : pUi->chipList->selectedRanges()) {
    const int row = range.topRow();
    chipPtrList.erase(chipPtrList.begin() + row);
    for (int i = 0; i < range.rowCount(); ++i) {
      pUi->chipList->removeRow(row);
    }
  }
}

/**
  �`�b�v���X�g�r���[����ɂ���.

  �`�b�v���X�g�r���[�Đݒ�̂��߂̃w���p�֐�. �V�[�g�f�[�^����͍폜����Ȃ����Ƃɒ���.
*/
void Main::clearChipList()
{
  pUi->chipList->clear();
  pUi->chipList->setRowCount(0);
}

/**
  �V�[�g��ǉ�����.

  �V�[�g���X�g�ɂ���̃X�v���C�g�V�[�g��ǉ�����.
*/
void Main::insertSheet()
{
  animation.sheetList.push_back(Sheet());
  pUi->sheetList->insertColumn(0);
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
  animation.sheetList.clear();
  pUi->sheetList->clear();
  pUi->sheetList->setColumnCount(0);
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
