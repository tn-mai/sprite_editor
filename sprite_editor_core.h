/**
  Sprite Editor
*/
#include "data.h"
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <memory>

class StateBox;
class QGraphicsPixmapItem;

namespace Ui {
class MainWindow;
} // namespace Ui

namespace SpriteEditor {

class Main : public QMainWindow
{
  Q_OBJECT

public:
  Main(QWidget* parent = 0);

private slots:
  void openFile();
  void saveFile();
  void openTextureFile();
  void insertChip();
  void insertChip(int, const Rect&, const Point2&, const Vector2&, const Vector2&);
  void deleteChip();

private:
  std::shared_ptr<Ui::MainWindow> pUi;
  std::shared_ptr<QPixmap>  pTextureImage;
  std::shared_ptr<StateBox>  pStateBox;
  std::unique_ptr<QGraphicsScene> pTextureScene;
  std::unique_ptr<QGraphicsScene> pEditScene;
  std::vector<QGraphicsPixmapItem*> chipPtrList;

  Animation  animation;
};

} // namespace SpriteEditor
