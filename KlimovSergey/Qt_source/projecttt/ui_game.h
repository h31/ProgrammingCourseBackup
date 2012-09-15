/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created: Sat 15. Sep 18:36:44 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QAction *actionStart;
    QAction *actionCheck;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionShow_Answer;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuActions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(400, 300);
        actionStart = new QAction(Game);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionCheck = new QAction(Game);
        actionCheck->setObjectName(QString::fromUtf8("actionCheck"));
        actionExit = new QAction(Game);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSave = new QAction(Game);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(Game);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionShow_Answer = new QAction(Game);
        actionShow_Answer->setObjectName(QString::fromUtf8("actionShow_Answer"));
        centralWidget = new QWidget(Game);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Game->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Game);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        Game->setMenuBar(menuBar);
        statusBar = new QStatusBar(Game);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Game->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuActions->menuAction());
        menuMenu->addAction(actionStart);
        menuMenu->addAction(actionCheck);
        menuMenu->addAction(actionExit);
        menuActions->addAction(actionSave);
        menuActions->addAction(actionLoad);
        menuActions->addSeparator();
        menuActions->addAction(actionShow_Answer);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Game", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("Game", "Start", 0, QApplication::UnicodeUTF8));
        actionCheck->setText(QApplication::translate("Game", "Check", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("Game", "Exit", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("Game", "Save", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("Game", "Load", 0, QApplication::UnicodeUTF8));
        actionShow_Answer->setText(QApplication::translate("Game", "Show Answer", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("Game", "Menu", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("Game", "Actions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
