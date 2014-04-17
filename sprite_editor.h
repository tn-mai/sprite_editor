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
#include "editview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionInsertChip;
    QAction *actionDeleteChip;
    QAction *actionInsertSheet;
    QAction *actionDeleteSheet;
    QAction *actionAb;
    QAction *actionOpenTexture;
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
    QTableWidget *sheetList;
    QDockWidget *editDock;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QScrollArea *editScrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout_2;
    SpriteEditor::EditView *editView;
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
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
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
        actionOpenTexture = new QAction(MainWindow);
        actionOpenTexture->setObjectName(QStringLiteral("actionOpenTexture"));
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
        sheetList = new QTableWidget(dockWidgetContents);
        if (sheetList->rowCount() < 2)
            sheetList->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        sheetList->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        sheetList->setVerticalHeaderItem(1, __qtablewidgetitem1);
        sheetList->setObjectName(QStringLiteral("sheetList"));
        sheetList->setRowCount(2);
        sheetList->setColumnCount(0);
        sheetList->verticalHeader()->setVisible(true);

        horizontalLayout_4->addWidget(sheetList);

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
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        editView = new SpriteEditor::EditView(scrollAreaWidgetContents);
        editView->setObjectName(QStringLiteral("editView"));
        editView->setMinimumSize(QSize(512, 512));
        editView->setMaximumSize(QSize(512, 512));
        editView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, editView);

        editScrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(editScrollArea);
        chipList = new QTableWidget(splitter);
        if (chipList->columnCount() < 11)
            chipList->setColumnCount(11);
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
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        chipList->setHorizontalHeaderItem(10, __qtablewidgetitem12);
        chipList->setObjectName(QStringLiteral("chipList"));
        chipList->setMinimumSize(QSize(0, 0));
        chipList->setMaximumSize(QSize(1677215, 1677215));
        chipList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        chipList->setRowCount(0);
        chipList->setColumnCount(11);
        splitter->addWidget(chipList);
        chipList->horizontalHeader()->setDefaultSectionSize(56);

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
        QPalette palette;
        QBrush brush(QColor(120, 120, 120, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        textureView->setPalette(palette);
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
        menuFile_F->addAction(actionNew);
        menuFile_F->addAction(actionOpen);
        menuFile_F->addAction(actionSave);
        menuFile_F->addAction(actionOpenTexture);
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
        actionNew->setText(QApplication::translate("MainWindow", "&New", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionInsertChip->setText(QApplication::translate("MainWindow", "&Insert Chip", 0));
        actionInsertChip->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        actionDeleteChip->setText(QApplication::translate("MainWindow", "&Delete Chip", 0));
        actionDeleteChip->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionInsertSheet->setText(QApplication::translate("MainWindow", "Insert Sheet", 0));
        actionDeleteSheet->setText(QApplication::translate("MainWindow", "Delete Sheet", 0));
        actionAb->setText(QApplication::translate("MainWindow", "ab", 0));
        actionOpenTexture->setText(QApplication::translate("MainWindow", "Open &Texture", 0));
        menuFile_F->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menu_Option->setTitle(QApplication::translate("MainWindow", "&View", 0));
        menu_Option_2->setTitle(QApplication::translate("MainWindow", "&Option", 0));
        QTableWidgetItem *___qtablewidgetitem = sheetList->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "image", 0));
        QTableWidgetItem *___qtablewidgetitem1 = sheetList->verticalHeaderItem(1);
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
        QTableWidgetItem *___qtablewidgetitem10 = chipList->horizontalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "X Scale", 0));
        QTableWidgetItem *___qtablewidgetitem11 = chipList->horizontalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Y Scale", 0));
        QTableWidgetItem *___qtablewidgetitem12 = chipList->horizontalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Rotation", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPRITE_EDITOR_H
