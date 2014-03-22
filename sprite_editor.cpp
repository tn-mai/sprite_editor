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
  QImage image;
  if (!image.load(filename)) {
    QMessageBox::information(this, tr("Unable to open file."), filename);
    return;
  }
  if (!pTextureImage) {
    pTextureImage.reset(new QPixmap(512, 512));
    pItem = pTextureScene->addPixmap(*pTextureImage);
  }
  pTextureImage->convertFromImage(image, Qt::ColorOnly);
  pUi->textureDock->setWindowTitle(filename);
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
