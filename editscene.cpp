/**
  Edit Scene.
*/
#include "editscene.h"
#include "sprite_editor_core.h"
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtGui/QMouseEvent>

namespace SpriteEditor {

/**
  �R���X�g���N�^.
*/
EditScene::EditScene(QObject* parent) :
  QGraphicsScene(parent),
  grabbedItemList(),
  dragStartingPoint(0, 0)
{
}

/**
  �}�E�X�J�[�\���ʒu�̃I�u�W�F�N�g������.
  �I�u�W�F�N�g�����I���̏ꍇ�ACtrl�L�[��������Ă���ΑI�����X�g�ɉ�����.
  ������Ă��Ȃ���ΑI�����X�g����ɂ��Ă��������.
  ���̌�A�h���b�O���[�h�ɂ���.
*/
void EditScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  QList<QGraphicsItem*> itemList = items();
  const QPointF pos = event->pos();
  for (auto i : itemList) {
    if (i->sceneBoundingRect().contains(pos)) {
      // Ctrl�L�[��������Ă��鎞�A���ɑI������Ă���Ȃ牽�����Ȃ�. �����łȂ���ΑI��.
      // Ctrl�L�[��������Ă��Ȃ����A���ɑI������Ă���Ȃ�I������. �����łȂ���ΑI��.
      auto end = grabbedItemList.end();
      auto grabbedItem = std::find(grabbedItemList.begin(), end, i);
     QGraphicsPixmapItem* pItem = static_cast<QGraphicsPixmapItem*>(i);
      QPixmap pixmap = pItem->pixmap();
      if ( grabbedItem != end) {
        if (!(event->modifiers() & Qt::ControlModifier)) {
          drawDashFrame(&pixmap, QColor(0xff, 0x00, 0x00, 0x7f));
          pItem->setPixmap(pixmap);
          grabbedItemList.erase(grabbedItem);
          continue;
        }
      }
      drawDashFrame(&pixmap, QColor(0x00, 0xff, 0x00, 0x7f));
      pItem->setPixmap(pixmap);
      grabbedItemList.push_back(i);
    }
  }
  dragStartingPoint = event->scenePos();
  event->setAccepted(true);
}

/**
  �I�����X�g�̃I�u�W�F�N�g���ړ�������.
*/
void EditScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
  const QPointF moveVector = event->scenePos() - event->lastScenePos();
  for (auto i : grabbedItemList) {
    i->setPos(i->pos() + moveVector);
  }
  event->setAccepted(true);
}

/**
  �h���b�O���[�h���I������.
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
