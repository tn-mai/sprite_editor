/**
  Edit View.
*/
#include "editview.h"
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsItem>

namespace SpriteEditor {

/**
  コンストラクタ.
*/
EditView::EditView(QWidget* parent) :
  QGraphicsView(parent),
  grabbedItemList(),
  dragStartingPoint(0, 0)
{
}

/**
  マウスカーソル位置のオブジェクトをつかむ.
  オブジェクトが未選択の場合、Ctrlキーが押されていれば選択リストに加える.
  押されていなければ選択リストを空にしてから加える.
  その後、ドラッグモードにする.
*/
void EditView::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  QList<QGraphicsItem*> itemList = scene()->items();
  const QPointF pos = event->pos();
  for (auto i : itemList) {
    if (i->boundingRect().contains(pos)) {
      // Ctrlキーが押されている時、既に選択されているなら何もしない. そうでなければ選択.
      // Ctrlキーが押されていない時、既に選択されているなら選択解除. そうでなければ選択.
      auto grabbedItem = std::find(grabbedItemList.begin(), grabbedItemList.end(), i);
      if ( grabbedItem != grabbedItemList.end()) {
        if (!(event->modifiers() & Qt::ControlModifier)) {
          grabbedItemList.erase(grabbedItem);
          continue;
        }
      }
      grabbedItemList.push_back(i);
    }
  }
  dragStartingPoint = event->pos();
  event->setAccepted(true);
}

/**
  選択リストのオブジェクトを移動させる.
*/
void EditView::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
  const QPointF moveVector = event->pos() - dragStartingPoint;
  for (auto i : grabbedItemList) {
    i->setPos(i->pos() + moveVector);
  }
  event->setAccepted(true);
}

/**
  ドラッグモードを終了する.
*/
void EditView::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
  event->setAccepted(false);
}

void EditView::mouseMoveEvent(QGraphicsSceneDragDropEvent* event)
{
  event->setAccepted(false);
}

void EditView::mousePressEvent(QGraphicsSceneDragDropEvent* event)
{
  event->setAccepted(false);
}


} // namespace SpriteEditor
