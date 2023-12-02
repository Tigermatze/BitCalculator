/********************************************************************************
** Form generated from reading UI file 'BitCalculator.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BITCALCULATOR_H
#define UI_BITCALCULATOR_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BitCalculatorClass
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *hexLabel;
    QLabel *decLabel;
    QLabel *binLabel;
    QLabel *shiftLabel;
    QLineEdit *hexEdit_Row1;
    QLineEdit *decEdit_Row1;
    QLineEdit *binEdit_Row1;
    QSpinBox *shiftSpinBox_Row1;
    QLineEdit *hexEdit_Row2;
    QLineEdit *decEdit_Row2;
    QLineEdit *binEdit_Row2;
    QLineEdit *hexEdit_Row3;
    QLineEdit *decEdit_Row3;
    QLineEdit *binEdit_Row3;
    QSpinBox *shiftSpinBox_Row2;
    QGridLayout *gridLayout1;
    QPushButton *andButton;
    QPushButton *orButton;
    QPushButton *xorButton;
    QPushButton *nandButton;
    QPushButton *norButton;
    QPushButton *xnorButton;
    QPushButton *moduloButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BitCalculatorClass)
    {
        if (BitCalculatorClass->objectName().isEmpty())
            BitCalculatorClass->setObjectName("BitCalculatorClass");
        BitCalculatorClass->resize(516, 322);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Bilder/Bilder/gtk-preferences.png"), QSize(), QIcon::Normal, QIcon::Off);
        BitCalculatorClass->setWindowIcon(icon);
        BitCalculatorClass->setLayoutDirection(Qt::LeftToRight);
        BitCalculatorClass->setAutoFillBackground(false);
        BitCalculatorClass->setLocale(QLocale(QLocale::German, QLocale::Germany));
        BitCalculatorClass->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        BitCalculatorClass->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        BitCalculatorClass->setUnifiedTitleAndToolBarOnMac(false);
        actionExit = new QAction(BitCalculatorClass);
        actionExit->setObjectName("actionExit");
        actionExit->setShortcutContext(Qt::WindowShortcut);
        actionAbout = new QAction(BitCalculatorClass);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setIcon(icon);
        actionAboutQt = new QAction(BitCalculatorClass);
        actionAboutQt->setObjectName("actionAboutQt");
        centralwidget = new QWidget(BitCalculatorClass);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        hexLabel = new QLabel(centralwidget);
        hexLabel->setObjectName("hexLabel");

        gridLayout->addWidget(hexLabel, 0, 0, 1, 1);

        decLabel = new QLabel(centralwidget);
        decLabel->setObjectName("decLabel");

        gridLayout->addWidget(decLabel, 0, 1, 1, 1);

        binLabel = new QLabel(centralwidget);
        binLabel->setObjectName("binLabel");

        gridLayout->addWidget(binLabel, 0, 2, 1, 1);

        shiftLabel = new QLabel(centralwidget);
        shiftLabel->setObjectName("shiftLabel");
        shiftLabel->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(shiftLabel, 0, 3, 1, 1);

        hexEdit_Row1 = new QLineEdit(centralwidget);
        hexEdit_Row1->setObjectName("hexEdit_Row1");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hexEdit_Row1->sizePolicy().hasHeightForWidth());
        hexEdit_Row1->setSizePolicy(sizePolicy);
        hexEdit_Row1->setAutoFillBackground(false);
        hexEdit_Row1->setFrame(true);
        hexEdit_Row1->setEchoMode(QLineEdit::Normal);
        hexEdit_Row1->setDragEnabled(false);

        gridLayout->addWidget(hexEdit_Row1, 1, 0, 1, 1);

        decEdit_Row1 = new QLineEdit(centralwidget);
        decEdit_Row1->setObjectName("decEdit_Row1");
        sizePolicy.setHeightForWidth(decEdit_Row1->sizePolicy().hasHeightForWidth());
        decEdit_Row1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(decEdit_Row1, 1, 1, 1, 1);

        binEdit_Row1 = new QLineEdit(centralwidget);
        binEdit_Row1->setObjectName("binEdit_Row1");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(binEdit_Row1->sizePolicy().hasHeightForWidth());
        binEdit_Row1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(binEdit_Row1, 1, 2, 1, 1);

        shiftSpinBox_Row1 = new QSpinBox(centralwidget);
        shiftSpinBox_Row1->setObjectName("shiftSpinBox_Row1");
        shiftSpinBox_Row1->setMinimum(-99);

        gridLayout->addWidget(shiftSpinBox_Row1, 1, 3, 1, 1);

        hexEdit_Row2 = new QLineEdit(centralwidget);
        hexEdit_Row2->setObjectName("hexEdit_Row2");
        sizePolicy.setHeightForWidth(hexEdit_Row2->sizePolicy().hasHeightForWidth());
        hexEdit_Row2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(hexEdit_Row2, 2, 0, 1, 1);

        decEdit_Row2 = new QLineEdit(centralwidget);
        decEdit_Row2->setObjectName("decEdit_Row2");
        sizePolicy.setHeightForWidth(decEdit_Row2->sizePolicy().hasHeightForWidth());
        decEdit_Row2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(decEdit_Row2, 2, 1, 1, 1);

        binEdit_Row2 = new QLineEdit(centralwidget);
        binEdit_Row2->setObjectName("binEdit_Row2");

        gridLayout->addWidget(binEdit_Row2, 2, 2, 1, 1);

        hexEdit_Row3 = new QLineEdit(centralwidget);
        hexEdit_Row3->setObjectName("hexEdit_Row3");
        hexEdit_Row3->setEnabled(false);
        sizePolicy.setHeightForWidth(hexEdit_Row3->sizePolicy().hasHeightForWidth());
        hexEdit_Row3->setSizePolicy(sizePolicy);
        hexEdit_Row3->setMaxLength(1024);
        hexEdit_Row3->setReadOnly(false);

        gridLayout->addWidget(hexEdit_Row3, 3, 0, 1, 1);

        decEdit_Row3 = new QLineEdit(centralwidget);
        decEdit_Row3->setObjectName("decEdit_Row3");
        decEdit_Row3->setEnabled(false);
        sizePolicy.setHeightForWidth(decEdit_Row3->sizePolicy().hasHeightForWidth());
        decEdit_Row3->setSizePolicy(sizePolicy);
        decEdit_Row3->setMaxLength(1024);

        gridLayout->addWidget(decEdit_Row3, 3, 1, 1, 1);

        binEdit_Row3 = new QLineEdit(centralwidget);
        binEdit_Row3->setObjectName("binEdit_Row3");
        binEdit_Row3->setEnabled(false);
        binEdit_Row3->setMaxLength(1024);
        binEdit_Row3->setFrame(true);

        gridLayout->addWidget(binEdit_Row3, 3, 2, 1, 1);

        shiftSpinBox_Row2 = new QSpinBox(centralwidget);
        shiftSpinBox_Row2->setObjectName("shiftSpinBox_Row2");
        shiftSpinBox_Row2->setMinimum(-99);

        gridLayout->addWidget(shiftSpinBox_Row2, 2, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName("gridLayout1");
        andButton = new QPushButton(centralwidget);
        andButton->setObjectName("andButton");
        andButton->setEnabled(true);
        andButton->setMinimumSize(QSize(100, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(118, 118, 117, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        andButton->setPalette(palette);
        andButton->setCheckable(true);

        gridLayout1->addWidget(andButton, 2, 1, 1, 1);

        orButton = new QPushButton(centralwidget);
        orButton->setObjectName("orButton");
        orButton->setMinimumSize(QSize(100, 0));
        orButton->setCheckable(true);

        gridLayout1->addWidget(orButton, 2, 2, 1, 1);

        xorButton = new QPushButton(centralwidget);
        xorButton->setObjectName("xorButton");
        xorButton->setMinimumSize(QSize(100, 0));
        xorButton->setCheckable(true);

        gridLayout1->addWidget(xorButton, 2, 3, 1, 1);

        nandButton = new QPushButton(centralwidget);
        nandButton->setObjectName("nandButton");
        nandButton->setCheckable(true);

        gridLayout1->addWidget(nandButton, 3, 1, 1, 1);

        norButton = new QPushButton(centralwidget);
        norButton->setObjectName("norButton");
        norButton->setCheckable(true);

        gridLayout1->addWidget(norButton, 3, 2, 1, 1);

        xnorButton = new QPushButton(centralwidget);
        xnorButton->setObjectName("xnorButton");
        xnorButton->setCheckable(true);

        gridLayout1->addWidget(xnorButton, 3, 3, 1, 1);

        moduloButton = new QPushButton(centralwidget);
        moduloButton->setObjectName("moduloButton");
        moduloButton->setCheckable(true);

        gridLayout1->addWidget(moduloButton, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer, 3, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout1->addItem(verticalSpacer_3, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(verticalSpacer, 5, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout1, 1, 0, 1, 1);

        BitCalculatorClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BitCalculatorClass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 516, 20));
        menubar->setLayoutDirection(Qt::LeftToRight);
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu->setLayoutDirection(Qt::LeftToRight);
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        BitCalculatorClass->setMenuBar(menubar);
        statusbar = new QStatusBar(BitCalculatorClass);
        statusbar->setObjectName("statusbar");
        statusbar->setLayoutDirection(Qt::LeftToRight);
        BitCalculatorClass->setStatusBar(statusbar);
        QWidget::setTabOrder(hexEdit_Row1, decEdit_Row1);
        QWidget::setTabOrder(decEdit_Row1, binEdit_Row1);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionExit);
        menu_2->addAction(actionAbout);
        menu_2->addAction(actionAboutQt);

        retranslateUi(BitCalculatorClass);

        QMetaObject::connectSlotsByName(BitCalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *BitCalculatorClass)
    {
        BitCalculatorClass->setWindowTitle(QCoreApplication::translate("BitCalculatorClass", "BitCalculator", nullptr));
        actionExit->setText(QCoreApplication::translate("BitCalculatorClass", "&Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("BitCalculatorClass", "Alt+F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("BitCalculatorClass", "&About", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("BitCalculatorClass", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutQt->setText(QCoreApplication::translate("BitCalculatorClass", "&Qt", nullptr));
#if QT_CONFIG(shortcut)
        actionAboutQt->setShortcut(QCoreApplication::translate("BitCalculatorClass", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        hexLabel->setText(QCoreApplication::translate("BitCalculatorClass", "Hex", nullptr));
        decLabel->setText(QCoreApplication::translate("BitCalculatorClass", "Dec", nullptr));
        binLabel->setText(QCoreApplication::translate("BitCalculatorClass", "Bin", nullptr));
        shiftLabel->setText(QCoreApplication::translate("BitCalculatorClass", "Shift", nullptr));
#if QT_CONFIG(tooltip)
        hexEdit_Row1->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Put your hexadecimal value.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        decEdit_Row1->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Put your decimal value.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        binEdit_Row1->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Put your binary value.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        shiftSpinBox_Row1->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Shift the value up or down", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        hexEdit_Row2->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Put your hexadecimal value.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        decEdit_Row2->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Put your decimal value.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        binEdit_Row2->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Put your binary value.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        shiftSpinBox_Row2->setToolTip(QCoreApplication::translate("BitCalculatorClass", "Shift the value up or down", nullptr));
#endif // QT_CONFIG(tooltip)
        andButton->setText(QCoreApplication::translate("BitCalculatorClass", "AND", nullptr));
        orButton->setText(QCoreApplication::translate("BitCalculatorClass", "OR", nullptr));
        xorButton->setText(QCoreApplication::translate("BitCalculatorClass", "XOR", nullptr));
        nandButton->setText(QCoreApplication::translate("BitCalculatorClass", "NAND", nullptr));
        norButton->setText(QCoreApplication::translate("BitCalculatorClass", "NOR", nullptr));
        xnorButton->setText(QCoreApplication::translate("BitCalculatorClass", "XNOR", nullptr));
        moduloButton->setText(QCoreApplication::translate("BitCalculatorClass", "MODULO", nullptr));
        menu->setTitle(QCoreApplication::translate("BitCalculatorClass", "Datei", nullptr));
        menu_2->setTitle(QCoreApplication::translate("BitCalculatorClass", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BitCalculatorClass: public Ui_BitCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BITCALCULATOR_H
