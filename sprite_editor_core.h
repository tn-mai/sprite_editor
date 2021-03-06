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

class ChipItem;

enum class ChipDragType {
  Position,
  Rotation,
  Scale,
  Offset,
};

class Main : public QMainWindow
{
  Q_OBJECT

public:
  Main(QWidget* parent = 0);

private:
  void clearChipListView();
  void clearSheetList();
  void setAnimation(size_t);
  int getCurrentSheetIndex() const;
  int getCurrentChipIndex() const;
  void updateSheetPicture(int);
  void onChangeChipItem(const QPointF&, const ChipItem&, ChipDragType);
  void setChipInsertionEnabled(bool);

private slots:
  void openFile();
  void saveFile();
  void openTextureFile();
  void insertChip();
  void insertChip(const Chip&);
  void deleteChip();
  void insertSheet();
  void deleteSheet();

  void onChipListChanged(int, int);
  void onSheetListSelectionChanged();
  void onSheetListCellChanged(int, int);

private:
  std::shared_ptr<Ui::MainWindow> pUi;
  std::shared_ptr<QPixmap>  pTextureImage;
  std::shared_ptr<StateBox>  pStateBox;
  std::unique_ptr<QGraphicsScene> pTextureScene;
  std::unique_ptr<QGraphicsScene> pEditScene;
  std::vector<QGraphicsPixmapItem*> chipPtrList;

  Animation  animation;
  int currentSheetIndex;
};

void drawDashFrame(QPixmap*, const QColor&);

} // namespace SpriteEditor
