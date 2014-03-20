/**
  Sprite Editor
*/
#include "sprite_editor.h"
#include <memory>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  QMainWindow* pMainWindow = new QMainWindow;
  Ui::MainWindow ui;
  ui.setupUi(pMainWindow);

  pMainWindow->show();
  return app.exec();
}
