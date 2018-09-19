/********************************************************************************
** Form generated from reading UI file 'SpatiiTopologice.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPATIITOPOLOGICE_H
#define UI_SPATIITOPOLOGICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpatiiTopologiceClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpatiiTopologiceClass)
    {
        if (SpatiiTopologiceClass->objectName().isEmpty())
            SpatiiTopologiceClass->setObjectName(QStringLiteral("SpatiiTopologiceClass"));
        SpatiiTopologiceClass->resize(600, 400);
        menuBar = new QMenuBar(SpatiiTopologiceClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SpatiiTopologiceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpatiiTopologiceClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SpatiiTopologiceClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SpatiiTopologiceClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SpatiiTopologiceClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SpatiiTopologiceClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SpatiiTopologiceClass->setStatusBar(statusBar);

        retranslateUi(SpatiiTopologiceClass);

        QMetaObject::connectSlotsByName(SpatiiTopologiceClass);
    } // setupUi

    void retranslateUi(QMainWindow *SpatiiTopologiceClass)
    {
        SpatiiTopologiceClass->setWindowTitle(QApplication::translate("SpatiiTopologiceClass", "SpatiiTopologice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpatiiTopologiceClass: public Ui_SpatiiTopologiceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPATIITOPOLOGICE_H
