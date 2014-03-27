/**
  Sprite Editor
*/
#include "sprite_editor_core.h"
#include "sprite_editor.h"
#include "statebox.h"

namespace SpriteEditor {

Main::Main(QWidget* parent) :
  QMainWindow(parent),
  pUi(new Ui::MainWindow),
  pTextureImage(new QPixmap(1, 1)),
  pStateBox(new StateBox),
  pTextureScene(0),
  pItem(0)
{
  pUi->setupUi(this);
  pTextureScene = new QGraphicsScene(this);
  pStateBox->setPos(200, 200);
  pItem = pTextureScene->addPixmap(*pTextureImage);
  pTextureScene->addItem(pStateBox.get());
  pUi->textureView->setScene(pTextureScene);

  connect(pUi->action_Open, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(pUi->action_Insert, SIGNAL(triggered()), this, SLOT(insertChip()));
  connect(pUi->action_Delete, SIGNAL(triggered()), this, SLOT(deleteChip()));
}

void Main::openFile()
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
  pUi->chipList->setItem(0, Left, new QTableWidgetItem(tr("%1").arg(pStateBox->pos().x())));
  pUi->chipList->setItem(0, Top, new QTableWidgetItem(tr("%1").arg(pStateBox->pos().y())));
  pUi->chipList->setItem(0, Width, new QTableWidgetItem(tr("%1").arg(pStateBox->size().x())));
  pUi->chipList->setItem(0, Height, new QTableWidgetItem(tr("%1").arg(pStateBox->size().y())));
  pUi->chipList->setItem(0, XPos, new QTableWidgetItem(tr("%1").arg(0)));
  pUi->chipList->setItem(0, YPos, new QTableWidgetItem(tr("%1").arg(0)));
  pUi->chipList->setItem(0, XOffset, new QTableWidgetItem(tr("%1").arg(0)));
  pUi->chipList->setItem(0, YOffset, new QTableWidgetItem(tr("%1").arg(0)));
}

void Main::deleteChip()
{
  for (auto range : pUi->chipList->selectedRanges()) {
    const int row = range.topRow();
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
