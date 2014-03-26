/**
  Sprite Editor
*/
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QMainWindow>
#include <memory>

class StateBox;

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
  void insertChip();
  void deleteChip();

private:
  std::shared_ptr<Ui::MainWindow> pUi;
  std::shared_ptr<QPixmap>  pTextureImage;
  std::shared_ptr<StateBox>  pStateBox;
  QGraphicsScene* pTextureScene;
  QGraphicsPixmapItem* pItem;
};

} // namespace SpriteEditor
