/**
  Sprite Editor
*/
#include "sprite_editor.h"
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtCore>
#include <memory>

namespace SpriteEditor {

class Main : public QMainWindow
{
  Q_OBJECT

public:
  Main(QWidget* parent = 0) :
    QMainWindow(parent),
    pUi(new Ui::MainWindow),
    pTextureImage(0),
    pTextureScene(0),
    pItem(0)
  {
    pUi->setupUi(this);
    pTextureScene = new QGraphicsScene(this);
    pTextureScene->setSceneRect(pUi->textureView->rect());
    pUi->textureView->setScene(pTextureScene);
    connect(pUi->action_Open, SIGNAL(triggered()), this, SLOT(openFile()));
  }

private slots:
  void openFile();

private:
  std::shared_ptr<Ui::MainWindow> pUi;
  QPixmap*  pTextureImage;
  QGraphicsScene* pTextureScene;
  QGraphicsPixmapItem* pItem;
};

} // namespace SpriteEditor
