/********************************************************************************
** Form generated from reading UI file 'sprite_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SPRITE_EDITOR_H
#define SPRITE_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *actionInsertChip;
    QAction *actionDeleteChip;
    QAction *actionInsertSheet;
    QAction *actionDeleteSheet;
    QAction *actionAb;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile_F;
    QMenu *menu_Edit;
    QMenu *menu_Option;
    QMenu *menu_Option_2;
    QStatusBar *statusbar;
    QDockWidget *sequenceDock;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *imageList;
    QDockWidget *editDock;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QScrollArea *editScrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout_2;
    QGraphicsView *editView;
    QTableWidget *chipList;
    QDockWidget *textureDock;
    QWidget *dockWidgetContents_3;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *textureScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout;
    QGraphicsView *textureView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1598, 861);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        actionInsertChip = new QAction(MainWindow);
        actionInsertChip->setObjectName(QStringLiteral("actionInsertChip"));
        actionDeleteChip = new QAction(MainWindow);
        actionDeleteChip->setObjectName(QStringLiteral("actionDeleteChip"));
        actionInsertSheet = new QAction(MainWindow);
        actionInsertSheet->setObjectName(QStringLiteral("actionInsertSheet"));
        actionDeleteSheet = new QAction(MainWindow);
        actionDeleteSheet->setObjectName(QStringLiteral("actionDeleteSheet"));
        actionAb = new QAction(MainWindow);
        actionAb->setObjectName(QStringLiteral("actionAb"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1598, 21));
        menuFile_F = new QMenu(menubar);
        menuFile_F->setObjectName(QStringLiteral("menuFile_F"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Option = new QMenu(menubar);
        menu_Option->setObjectName(QStringLiteral("menu_Option"));
        menu_Option_2 = new QMenu(menubar);
        menu_Option_2->setObjectName(QStringLiteral("menu_Option_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        sequenceDock = new QDockWidget(MainWindow);
        sequenceDock->setObjectName(QStringLiteral("sequenceDock"));
        sequenceDock->setStyleSheet(QStringLiteral(""));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        imageList = new QTableWidget(dockWidgetContents);
        if (imageList->rowCount() < 2)
            imageList->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        imageList->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        imageList->setVerticalHeaderItem(1, __qtablewidgetitem1);
        imageList->setObjectName(QStringLiteral("imageList"));
        imageList->setRowCount(2);
        imageList->setColumnCount(0);
        imageList->verticalHeader()->setVisible(true);

        horizontalLayout_4->addWidget(imageList);

        sequenceDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), sequenceDock);
        editDock = new QDockWidget(MainWindow);
        editDock->setObjectName(QStringLiteral("editDock"));
        editDock->setStyleSheet(QStringLiteral(""));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(dockWidgetContents_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        editScrollArea = new QScrollArea(splitter);
        editScrollArea->setObjectName(QStringLiteral("editScrollArea"));
        editScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        editScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 536, 530));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        editView = new QGraphicsView(scrollAreaWidgetContents);
        editView->setObjectName(QStringLiteral("editView"));
        editView->setMinimumSize(QSize(512, 512));
        editView->setMaximumSize(QSize(512, 512));
        editView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, editView);

        editScrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(editScrollArea);
        chipList = new QTableWidget(splitter);
        if (chipList->columnCount() < 8)
            chipList->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(7, __qtablewidgetitem9);
        chipList->setObjectName(QStringLiteral("chipList"));
        chipList->setMinimumSize(QSize(0, 0));
        chipList->setMaximumSize(QSize(1677215, 1677215));
        chipList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        chipList->setRowCount(0);
        chipList->setColumnCount(8);
        splitter->addWidget(chipList);

        horizontalLayout->addWidget(splitter);

        editDock->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), editDock);
        textureDock = new QDockWidget(MainWindow);
        textureDock->setObjectName(QStringLiteral("textureDock"));
        textureDock->setStyleSheet(QStringLiteral(""));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textureScrollArea = new QScrollArea(dockWidgetContents_3);
        textureScrollArea->setObjectName(QStringLiteral("textureScrollArea"));
        textureScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textureScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 280, 542));
        formLayout = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        textureView = new QGraphicsView(scrollAreaWidgetContents_2);
        textureView->setObjectName(QStringLiteral("textureView"));
        textureView->setMinimumSize(QSize(0, 0));
        textureView->setMaximumSize(QSize(65535, 65535));
        textureView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textureView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(0, QFormLayout::LabelRole, textureView);

        textureScrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_2->addWidget(textureScrollArea);

        textureDock->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), textureDock);

        menubar->addAction(menuFile_F->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_Option->menuAction());
        menubar->addAction(menu_Option_2->menuAction());
        menuFile_F->addAction(action_New);
        menuFile_F->addAction(action_Open);
        menuFile_F->addAction(action_Save);
        menu_Edit->addAction(actionInsertChip);
        menu_Edit->addAction(actionDeleteChip);
        menu_Edit->addAction(actionInsertSheet);
        menu_Edit->addAction(actionDeleteSheet);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "2D Sprite Editor", 0));
        action_New->setText(QApplication::translate("MainWindow", "&New", 0));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", 0));
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionInsertChip->setText(QApplication::translate("MainWindow", "&Insert Chip", 0));
        actionInsertChip->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        actionDeleteChip->setText(QApplication::translate("MainWindow", "&Delete Chip", 0));
        actionDeleteChip->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionInsertSheet->setText(QApplication::translate("MainWindow", "Insert Sheet", 0));
        actionDeleteSheet->setText(QApplication::translate("MainWindow", "Delete Sheet", 0));
        actionAb->setText(QApplication::translate("MainWindow", "ab", 0));
        menuFile_F->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menu_Option->setTitle(QApplication::translate("MainWindow", "&View", 0));
        menu_Option_2->setTitle(QApplication::translate("MainWindow", "&Option", 0));
        QTableWidgetItem *___qtablewidgetitem = imageList->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "image", 0));
        QTableWidgetItem *___qtablewidgetitem1 = imageList->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "frames", 0));
        QTableWidgetItem *___qtablewidgetitem2 = chipList->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Left", 0));
        QTableWidgetItem *___qtablewidgetitem3 = chipList->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Top", 0));
        QTableWidgetItem *___qtablewidgetitem4 = chipList->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Width", 0));
        QTableWidgetItem *___qtablewidgetitem5 = chipList->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Height", 0));
        QTableWidgetItem *___qtablewidgetitem6 = chipList->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "X", 0));
        QTableWidgetItem *___qtablewidgetitem7 = chipList->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Y", 0));
        QTableWidgetItem *___qtablewidgetitem8 = chipList->horizontalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "X Offset", 0));
        QTableWidgetItem *___qtablewidgetitem9 = chipList->horizontalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Y Offset", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPRITE_EDITOR_H
