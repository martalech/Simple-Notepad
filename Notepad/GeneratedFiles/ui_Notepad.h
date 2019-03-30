/********************************************************************************
** Form generated from reading UI file 'Notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <TabWidget.h>

QT_BEGIN_NAMESPACE

class Ui_NotepadClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNewFile;
    QAction *actionopenFile;
    QAction *actionsaveFile;
    QAction *actionsaveAll;
    QAction *actioncloseFile;
    QAction *actioncloseAll;
    QAction *actionSave_as;
    QAction *actionSave_all;
    QAction *actionClose;
    QAction *actionClose_all;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionClear;
    QAction *actionSelect_all;
    QAction *actionPaste;
    QAction *actioncut;
    QAction *actioncopy;
    QAction *actionpaste;
    QAction *actionundo;
    QAction *actionredo;
    QAction *actionzoomIn;
    QAction *actionzoomOut;
    QAction *actionfind;
    QAction *actionfont;
    QAction *actiontextColor;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionFind_in_file;
    QAction *actionRestore_default;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    TabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuFind;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NotepadClass)
    {
        if (NotepadClass->objectName().isEmpty())
            NotepadClass->setObjectName(QStringLiteral("NotepadClass"));
        NotepadClass->resize(637, 600);
        NotepadClass->setStyleSheet(QStringLiteral(""));
        actionOpen = new QAction(NotepadClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(NotepadClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionNewFile = new QAction(NotepadClass);
        actionNewFile->setObjectName(QStringLiteral("actionNewFile"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Notepad/Resources/newFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewFile->setIcon(icon);
        actionopenFile = new QAction(NotepadClass);
        actionopenFile->setObjectName(QStringLiteral("actionopenFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Notepad/Resources/openFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopenFile->setIcon(icon1);
        actionsaveFile = new QAction(NotepadClass);
        actionsaveFile->setObjectName(QStringLiteral("actionsaveFile"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Notepad/Resources/saveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsaveFile->setIcon(icon2);
        actionsaveAll = new QAction(NotepadClass);
        actionsaveAll->setObjectName(QStringLiteral("actionsaveAll"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Notepad/Resources/saveAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsaveAll->setIcon(icon3);
        actioncloseFile = new QAction(NotepadClass);
        actioncloseFile->setObjectName(QStringLiteral("actioncloseFile"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Notepad/Resources/closeFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncloseFile->setIcon(icon4);
        actioncloseAll = new QAction(NotepadClass);
        actioncloseAll->setObjectName(QStringLiteral("actioncloseAll"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Notepad/Resources/closeAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncloseAll->setIcon(icon5);
        actionSave_as = new QAction(NotepadClass);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave_all = new QAction(NotepadClass);
        actionSave_all->setObjectName(QStringLiteral("actionSave_all"));
        actionClose = new QAction(NotepadClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClose_all = new QAction(NotepadClass);
        actionClose_all->setObjectName(QStringLiteral("actionClose_all"));
        actionUndo = new QAction(NotepadClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(NotepadClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionCut = new QAction(NotepadClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(NotepadClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionClear = new QAction(NotepadClass);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionSelect_all = new QAction(NotepadClass);
        actionSelect_all->setObjectName(QStringLiteral("actionSelect_all"));
        actionPaste = new QAction(NotepadClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actioncut = new QAction(NotepadClass);
        actioncut->setObjectName(QStringLiteral("actioncut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Notepad/Resources/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncut->setIcon(icon6);
        actioncopy = new QAction(NotepadClass);
        actioncopy->setObjectName(QStringLiteral("actioncopy"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Notepad/Resources/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncopy->setIcon(icon7);
        actionpaste = new QAction(NotepadClass);
        actionpaste->setObjectName(QStringLiteral("actionpaste"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Notepad/Resources/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpaste->setIcon(icon8);
        actionundo = new QAction(NotepadClass);
        actionundo->setObjectName(QStringLiteral("actionundo"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Notepad/Resources/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionundo->setIcon(icon9);
        actionredo = new QAction(NotepadClass);
        actionredo->setObjectName(QStringLiteral("actionredo"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Notepad/Resources/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionredo->setIcon(icon10);
        actionzoomIn = new QAction(NotepadClass);
        actionzoomIn->setObjectName(QStringLiteral("actionzoomIn"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Notepad/Resources/zoomIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionzoomIn->setIcon(icon11);
        actionzoomOut = new QAction(NotepadClass);
        actionzoomOut->setObjectName(QStringLiteral("actionzoomOut"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Notepad/Resources/zoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionzoomOut->setIcon(icon12);
        actionfind = new QAction(NotepadClass);
        actionfind->setObjectName(QStringLiteral("actionfind"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Notepad/Resources/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfind->setIcon(icon13);
        actionfont = new QAction(NotepadClass);
        actionfont->setObjectName(QStringLiteral("actionfont"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Notepad/Resources/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfont->setIcon(icon14);
        actiontextColor = new QAction(NotepadClass);
        actiontextColor->setObjectName(QStringLiteral("actiontextColor"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Notepad/Resources/blackSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontextColor->setIcon(icon15);
        actionZoom_in = new QAction(NotepadClass);
        actionZoom_in->setObjectName(QStringLiteral("actionZoom_in"));
        actionZoom_out = new QAction(NotepadClass);
        actionZoom_out->setObjectName(QStringLiteral("actionZoom_out"));
        actionFind_in_file = new QAction(NotepadClass);
        actionFind_in_file->setObjectName(QStringLiteral("actionFind_in_file"));
        actionRestore_default = new QAction(NotepadClass);
        actionRestore_default->setObjectName(QStringLiteral("actionRestore_default"));
        centralWidget = new QWidget(NotepadClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new TabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String(" background-color: rgb(239, 239, 239);\n"
"\n"
""));

        horizontalLayout->addWidget(tabWidget);

        NotepadClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NotepadClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 637, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QStringLiteral("menuFind"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        NotepadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NotepadClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NotepadClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NotepadClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NotepadClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave_all);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_all);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionClear);
        menuEdit->addAction(actionSelect_all);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);
        menuFind->addAction(actionFind_in_file);
        menuSettings->addAction(actionRestore_default);
        mainToolBar->addAction(actionNewFile);
        mainToolBar->addAction(actionopenFile);
        mainToolBar->addAction(actionsaveFile);
        mainToolBar->addAction(actionsaveAll);
        mainToolBar->addAction(actioncloseFile);
        mainToolBar->addAction(actioncloseAll);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actioncut);
        mainToolBar->addAction(actioncopy);
        mainToolBar->addAction(actionpaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionundo);
        mainToolBar->addAction(actionredo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionzoomIn);
        mainToolBar->addAction(actionzoomOut);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionfind);
        mainToolBar->addAction(actionfont);
        mainToolBar->addAction(actiontextColor);

        retranslateUi(NotepadClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(NotepadClass);
    } // setupUi

    void retranslateUi(QMainWindow *NotepadClass)
    {
        NotepadClass->setWindowTitle(QApplication::translate("NotepadClass", "Notepad", nullptr));
        actionOpen->setText(QApplication::translate("NotepadClass", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("NotepadClass", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("NotepadClass", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("NotepadClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionNewFile->setText(QApplication::translate("NotepadClass", "NewFile", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNewFile->setToolTip(QApplication::translate("NotepadClass", "New", nullptr));
#endif // QT_NO_TOOLTIP
        actionopenFile->setText(QApplication::translate("NotepadClass", "openFile", nullptr));
#ifndef QT_NO_TOOLTIP
        actionopenFile->setToolTip(QApplication::translate("NotepadClass", "Open..", nullptr));
#endif // QT_NO_TOOLTIP
        actionsaveFile->setText(QApplication::translate("NotepadClass", "saveFile", nullptr));
#ifndef QT_NO_TOOLTIP
        actionsaveFile->setToolTip(QApplication::translate("NotepadClass", "Save", nullptr));
#endif // QT_NO_TOOLTIP
        actionsaveAll->setText(QApplication::translate("NotepadClass", "saveAll", nullptr));
#ifndef QT_NO_TOOLTIP
        actionsaveAll->setToolTip(QApplication::translate("NotepadClass", "Save all", nullptr));
#endif // QT_NO_TOOLTIP
        actioncloseFile->setText(QApplication::translate("NotepadClass", "closeFile", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncloseFile->setToolTip(QApplication::translate("NotepadClass", "Close", nullptr));
#endif // QT_NO_TOOLTIP
        actioncloseAll->setText(QApplication::translate("NotepadClass", "closeAll", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncloseAll->setToolTip(QApplication::translate("NotepadClass", "Close all", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave_as->setText(QApplication::translate("NotepadClass", "Save as", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("NotepadClass", "Ctrl+Alt+\305\232", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_all->setText(QApplication::translate("NotepadClass", "Save all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_all->setShortcut(QApplication::translate("NotepadClass", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("NotepadClass", "Close", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("NotepadClass", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose_all->setText(QApplication::translate("NotepadClass", "Close all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose_all->setShortcut(QApplication::translate("NotepadClass", "Ctrl+Shift+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("NotepadClass", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("NotepadClass", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("NotepadClass", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("NotepadClass", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("NotepadClass", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("NotepadClass", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("NotepadClass", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("NotepadClass", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionClear->setText(QApplication::translate("NotepadClass", "Clear", nullptr));
        actionSelect_all->setText(QApplication::translate("NotepadClass", "Select all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSelect_all->setShortcut(QApplication::translate("NotepadClass", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("NotepadClass", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("NotepadClass", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actioncut->setText(QApplication::translate("NotepadClass", "cut", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncut->setToolTip(QApplication::translate("NotepadClass", "Cut", nullptr));
#endif // QT_NO_TOOLTIP
        actioncopy->setText(QApplication::translate("NotepadClass", "copy", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncopy->setToolTip(QApplication::translate("NotepadClass", "Copy", nullptr));
#endif // QT_NO_TOOLTIP
        actionpaste->setText(QApplication::translate("NotepadClass", "paste", nullptr));
#ifndef QT_NO_TOOLTIP
        actionpaste->setToolTip(QApplication::translate("NotepadClass", "Paste", nullptr));
#endif // QT_NO_TOOLTIP
        actionundo->setText(QApplication::translate("NotepadClass", "undo", nullptr));
#ifndef QT_NO_TOOLTIP
        actionundo->setToolTip(QApplication::translate("NotepadClass", "Undo", nullptr));
#endif // QT_NO_TOOLTIP
        actionredo->setText(QApplication::translate("NotepadClass", "redo", nullptr));
#ifndef QT_NO_TOOLTIP
        actionredo->setToolTip(QApplication::translate("NotepadClass", "Redo", nullptr));
#endif // QT_NO_TOOLTIP
        actionzoomIn->setText(QApplication::translate("NotepadClass", "zoomIn", nullptr));
#ifndef QT_NO_TOOLTIP
        actionzoomIn->setToolTip(QApplication::translate("NotepadClass", "Zoom in", nullptr));
#endif // QT_NO_TOOLTIP
        actionzoomOut->setText(QApplication::translate("NotepadClass", "zoomOut", nullptr));
#ifndef QT_NO_TOOLTIP
        actionzoomOut->setToolTip(QApplication::translate("NotepadClass", "Zoom out", nullptr));
#endif // QT_NO_TOOLTIP
        actionfind->setText(QApplication::translate("NotepadClass", "find", nullptr));
#ifndef QT_NO_TOOLTIP
        actionfind->setToolTip(QApplication::translate("NotepadClass", "Find", nullptr));
#endif // QT_NO_TOOLTIP
        actionfont->setText(QApplication::translate("NotepadClass", "font", nullptr));
#ifndef QT_NO_TOOLTIP
        actionfont->setToolTip(QApplication::translate("NotepadClass", "Font", nullptr));
#endif // QT_NO_TOOLTIP
        actiontextColor->setText(QApplication::translate("NotepadClass", "textColor", nullptr));
#ifndef QT_NO_TOOLTIP
        actiontextColor->setToolTip(QApplication::translate("NotepadClass", "Text color", nullptr));
#endif // QT_NO_TOOLTIP
        actionZoom_in->setText(QApplication::translate("NotepadClass", "Zoom in", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_in->setShortcut(QApplication::translate("NotepadClass", "Ctrl+=", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_out->setText(QApplication::translate("NotepadClass", "Zoom out", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_out->setShortcut(QApplication::translate("NotepadClass", "Ctrl+_", nullptr));
#endif // QT_NO_SHORTCUT
        actionFind_in_file->setText(QApplication::translate("NotepadClass", "Find in file", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFind_in_file->setShortcut(QApplication::translate("NotepadClass", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionRestore_default->setText(QApplication::translate("NotepadClass", "Restore default", nullptr));
        menuFile->setTitle(QApplication::translate("NotepadClass", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("NotepadClass", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("NotepadClass", "View", nullptr));
        menuFind->setTitle(QApplication::translate("NotepadClass", "Find", nullptr));
        menuSettings->setTitle(QApplication::translate("NotepadClass", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotepadClass: public Ui_NotepadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
