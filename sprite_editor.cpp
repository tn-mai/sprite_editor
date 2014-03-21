/**
  Sprite Editor
*/
#include "sprite_editor_core.h"

namespace SpriteEditor {

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
  if (!pTextureImage) {
    pTextureImage = new QPixmap(256, 256);
    QGraphicsPixmapItem* pItem = pTextureScene->addPixmap(*pTextureImage);
    pItem->setVisible(true);
    pTextureScene->addRect(10, 10, 100, 100);
  }
  if (!pTextureImage->load(filename)) {
    QMessageBox::information(this, tr("Unable to open file."), filename);
    return;
  }
  pUi->textureView->repaint();
}

} // namespace SpriteEditor

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  SpriteEditor::Main* pMainWindow = new SpriteEditor::Main();
  pMainWindow->show();

  return app.exec();
}
