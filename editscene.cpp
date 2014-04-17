/**
  Edit Scene.
*/
#include "editscene.h"
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtGui/QMouseEvent>

namespace SpriteEditor {

/**
  コンストラクタ.
*/
EditScene::EditScene(QObject* parent) :
  QGraphicsScene(parent),
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
void EditScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  QList<QGraphicsItem*> itemList = items();
  const QPointF pos = event->pos();
  for (auto i : itemList) {
    if (i->sceneBoundingRect().contains(pos)) {
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
void EditScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
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
void EditScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
  event->setAccepted(false);
}

void EditScene::mouseMoveEvent(QGraphicsSceneDragDropEvent* event)
{
  event->setAccepted(false);
}

void EditScene::mousePressEvent(QGraphicsSceneDragDropEvent* event)
{
  event->setAccepted(false);
}


} // namespace SpriteEditor
