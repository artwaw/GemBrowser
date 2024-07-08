/********************************************************************************
** Form generated from reading UI file 'gembrowser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEMBROWSER_H
#define UI_GEMBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GemBrowser
{
public:
    QAction *actionPreferences;
    QAction *actionPrint;
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelect_all;
    QAction *actionGo_to;
    QAction *actionBack;
    QAction *actionForward;
    QAction *actionHome;
    QAction *actionStart;
    QAction *actionIndex;
    QAction *actionContents;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *homeBtn;
    QToolButton *BackBtn;
    QToolButton *forwardBtn;
    QLineEdit *address;
    QToolButton *stopBtn;
    QTabWidget *content;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuNavigation;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GemBrowser)
    {
        if (GemBrowser->objectName().isEmpty())
            GemBrowser->setObjectName("GemBrowser");
        GemBrowser->resize(800, 600);
        actionPreferences = new QAction(GemBrowser);
        actionPreferences->setObjectName("actionPreferences");
        actionPrint = new QAction(GemBrowser);
        actionPrint->setObjectName("actionPrint");
        actionQuit = new QAction(GemBrowser);
        actionQuit->setObjectName("actionQuit");
        actionCut = new QAction(GemBrowser);
        actionCut->setObjectName("actionCut");
        actionCopy = new QAction(GemBrowser);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(GemBrowser);
        actionPaste->setObjectName("actionPaste");
        actionDelete = new QAction(GemBrowser);
        actionDelete->setObjectName("actionDelete");
        actionSelect_all = new QAction(GemBrowser);
        actionSelect_all->setObjectName("actionSelect_all");
        actionGo_to = new QAction(GemBrowser);
        actionGo_to->setObjectName("actionGo_to");
        actionBack = new QAction(GemBrowser);
        actionBack->setObjectName("actionBack");
        actionForward = new QAction(GemBrowser);
        actionForward->setObjectName("actionForward");
        actionHome = new QAction(GemBrowser);
        actionHome->setObjectName("actionHome");
        actionStart = new QAction(GemBrowser);
        actionStart->setObjectName("actionStart");
        actionIndex = new QAction(GemBrowser);
        actionIndex->setObjectName("actionIndex");
        actionContents = new QAction(GemBrowser);
        actionContents->setObjectName("actionContents");
        actionAbout = new QAction(GemBrowser);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(GemBrowser);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        homeBtn = new QToolButton(frame);
        homeBtn->setObjectName("homeBtn");

        horizontalLayout->addWidget(homeBtn);

        BackBtn = new QToolButton(frame);
        BackBtn->setObjectName("BackBtn");

        horizontalLayout->addWidget(BackBtn);

        forwardBtn = new QToolButton(frame);
        forwardBtn->setObjectName("forwardBtn");

        horizontalLayout->addWidget(forwardBtn);

        address = new QLineEdit(frame);
        address->setObjectName("address");
        address->setMinimumSize(QSize(581, 0));

        horizontalLayout->addWidget(address);

        stopBtn = new QToolButton(frame);
        stopBtn->setObjectName("stopBtn");

        horizontalLayout->addWidget(stopBtn);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        content = new QTabWidget(centralwidget);
        content->setObjectName("content");
        tab = new QWidget();
        tab->setObjectName("tab");
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(15, 11, 751, 411));
        textBrowser->setOpenExternalLinks(false);
        textBrowser->setOpenLinks(false);
        content->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        content->addTab(tab_2, QString());

        gridLayout->addWidget(content, 1, 0, 1, 1);

        GemBrowser->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GemBrowser);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuNavigation = new QMenu(menubar);
        menuNavigation->setObjectName("menuNavigation");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        GemBrowser->setMenuBar(menubar);
        statusbar = new QStatusBar(GemBrowser);
        statusbar->setObjectName("statusbar");
        GemBrowser->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuNavigation->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionPreferences);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_all);
        menuNavigation->addAction(actionGo_to);
        menuNavigation->addAction(actionBack);
        menuNavigation->addAction(actionForward);
        menuNavigation->addSeparator();
        menuNavigation->addAction(actionHome);
        menuNavigation->addSeparator();
        menuNavigation->addAction(actionStart);
        menuHelp->addAction(actionIndex);
        menuHelp->addAction(actionContents);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(GemBrowser);

        QMetaObject::connectSlotsByName(GemBrowser);
    } // setupUi

    void retranslateUi(QMainWindow *GemBrowser)
    {
        GemBrowser->setWindowTitle(QCoreApplication::translate("GemBrowser", "GemBrowser", nullptr));
        actionPreferences->setText(QCoreApplication::translate("GemBrowser", "Preferences", nullptr));
        actionPrint->setText(QCoreApplication::translate("GemBrowser", "Print", nullptr));
        actionQuit->setText(QCoreApplication::translate("GemBrowser", "Quit", nullptr));
        actionCut->setText(QCoreApplication::translate("GemBrowser", "Cut", nullptr));
        actionCopy->setText(QCoreApplication::translate("GemBrowser", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("GemBrowser", "Paste", nullptr));
        actionDelete->setText(QCoreApplication::translate("GemBrowser", "Delete", nullptr));
        actionSelect_all->setText(QCoreApplication::translate("GemBrowser", "Select all", nullptr));
        actionGo_to->setText(QCoreApplication::translate("GemBrowser", "Go to...", nullptr));
        actionBack->setText(QCoreApplication::translate("GemBrowser", "Back", nullptr));
        actionForward->setText(QCoreApplication::translate("GemBrowser", "Forward", nullptr));
        actionHome->setText(QCoreApplication::translate("GemBrowser", "Home", nullptr));
        actionStart->setText(QCoreApplication::translate("GemBrowser", "Start", nullptr));
        actionIndex->setText(QCoreApplication::translate("GemBrowser", "Index", nullptr));
        actionContents->setText(QCoreApplication::translate("GemBrowser", "Contents", nullptr));
        actionAbout->setText(QCoreApplication::translate("GemBrowser", "About...", nullptr));
        homeBtn->setText(QCoreApplication::translate("GemBrowser", "...", nullptr));
        BackBtn->setText(QCoreApplication::translate("GemBrowser", "...", nullptr));
        forwardBtn->setText(QCoreApplication::translate("GemBrowser", "...", nullptr));
        address->setPlaceholderText(QCoreApplication::translate("GemBrowser", "gemini://", nullptr));
        stopBtn->setText(QCoreApplication::translate("GemBrowser", "...", nullptr));
        content->setTabText(content->indexOf(tab), QCoreApplication::translate("GemBrowser", "Tab 1", nullptr));
        content->setTabText(content->indexOf(tab_2), QCoreApplication::translate("GemBrowser", "Tab 2", nullptr));
        menuFile->setTitle(QCoreApplication::translate("GemBrowser", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("GemBrowser", "Edit", nullptr));
        menuNavigation->setTitle(QCoreApplication::translate("GemBrowser", "Navigation", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("GemBrowser", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GemBrowser: public Ui_GemBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEMBROWSER_H
