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
  if (pItem) {
    pTextureScene->removeItem(pItem);
    pItem = 0;
  }
  pTextureImage.reset(new QPixmap(image.width(), image.height()));
  pTextureImage->convertFromImage(image, Qt::ColorOnly);
  pItem = pTextureScene->addPixmap(*pTextureImage);
  pTextureScene->setSceneRect(0, 0, image.width(), image.height());
  pUi->textureView->setMinimumSize(image.width(), image.height());
  pUi->textureView->repaint();
  pUi->textureDock->setWindowTitle(filename + '(' + QString::number(image.width()) + ',' + QString::number(image.height()) + ')');
}

} // namespace SpriteEditor

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  SpriteEditor::Main* pMainWindow = new SpriteEditor::Main();
  pMainWindow->show();

  return app.exec();
}
