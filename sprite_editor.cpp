/**
  Sprite Editor
*/
#include "sprite_editor_core.h"
#include "sprite_editor.h"
#include "statebox.h"
#include <QtWidgets/QGraphicsPixmapItem>

namespace SpriteEditor {

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

  connect(pUi->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(pUi->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
  connect(pUi->actionOpenTexture, SIGNAL(triggered()), this, SLOT(openTextureFile()));
  connect(pUi->actionInsertChip, SIGNAL(triggered()), this, SLOT(insertChip()));
  connect(pUi->actionDeleteChip, SIGNAL(triggered()), this, SLOT(deleteChip()));
}

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
}

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

void Main::insertChip()
{
  const float x = pStateBox->pos().x();
  const float y = pStateBox->pos().y();
  const float w = pStateBox->size().x();
  const float h = pStateBox->size().y();
  const int sheetIndex = pUi->imageList->selectedRanges().begin()->leftColumn();
  insertChip(sheetIndex, Rect(x, y, x + w, y + h), Point2(0, 0), Vector2(0, 0), Vector2(1, 1));
}

void Main::insertChip(int sheetIndex, const Rect& rect, const Point2& pos, const Vector2& offset, const Vector2& scale)
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
  animation.sheetList[sheetIndex].chipList.push_back(Chip(rect, pos, offset, scale));
}

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

} // namespace SpriteEditor

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  SpriteEditor::Main* pMainWindow = new SpriteEditor::Main();
  pMainWindow->show();

  return app.exec();
}
