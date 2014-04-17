/**
  Edit View.
*/
#ifndef EDITVIEW_H_INCLUDED
#define EDITVIEW_H_INCLUDED

#include <QtWidgets/QGraphicsView>

namespace SpriteEditor {

/**
  �X�v���C�g�`�b�v�쐬�r���[.
*/
class EditView : public QGraphicsView
{
Q_OBJECT
public:
  EditView(QWidget* = 0);

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

#endif // EDITVIEW_H_INCLUDED
