/**
  Edit Scene.
*/
#ifndef EDITSCENE_H_INCLUDED
#define EDITSCENE_H_INCLUDED

#include <QtWidgets/QGraphicsScene>

namespace SpriteEditor {

/**
  スプライトチップ作成ビュー.
*/
class EditScene : public QGraphicsScene
{
Q_OBJECT
public:
  EditScene(QObject* = 0);

private:
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent*);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
  virtual void mouseMoveEvent(QGraphicsSceneDragDropEvent*);
  virtual void mousePressEvent(QGraphicsSceneDragDropEvent*);

private:
  std::vector<QGraphicsItem*> grabbedItemList;
  QPointF  dragStartingPoint;
};

} // namespace SpriteEditor

#endif // EDITSCENE_H_INCLUDED
