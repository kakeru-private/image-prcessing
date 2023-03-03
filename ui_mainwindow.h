/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *openButton;
    QPushButton *saveButton;
    QPushButton *clearButton;
    QPushButton *srcshow;
    QPushButton *changeSrcButton;
    QSpacerItem *verticalSpacer;
    QPushButton *kakudai;
    QPushButton *grayscale;
    QPushButton *edge;
    QPushButton *rotate;
    QPushButton *filtering;
    QPushButton *nitika;
    QPushButton *toukeiButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *QuitButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *doname;
    QLabel *label;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *Image;
    QGridLayout *gridLayout_4;
    QLabel *file;
    QLabel *sizeLabel;
    QHBoxLayout *horizontalLayout_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(795, 529);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");

        verticalLayout_3->addWidget(openButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        verticalLayout_3->addWidget(saveButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        verticalLayout_3->addWidget(clearButton);

        srcshow = new QPushButton(centralwidget);
        srcshow->setObjectName("srcshow");

        verticalLayout_3->addWidget(srcshow);

        changeSrcButton = new QPushButton(centralwidget);
        changeSrcButton->setObjectName("changeSrcButton");

        verticalLayout_3->addWidget(changeSrcButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        kakudai = new QPushButton(centralwidget);
        kakudai->setObjectName("kakudai");

        verticalLayout_3->addWidget(kakudai);

        grayscale = new QPushButton(centralwidget);
        grayscale->setObjectName("grayscale");

        verticalLayout_3->addWidget(grayscale);

        edge = new QPushButton(centralwidget);
        edge->setObjectName("edge");

        verticalLayout_3->addWidget(edge);

        rotate = new QPushButton(centralwidget);
        rotate->setObjectName("rotate");

        verticalLayout_3->addWidget(rotate);

        filtering = new QPushButton(centralwidget);
        filtering->setObjectName("filtering");

        verticalLayout_3->addWidget(filtering);

        nitika = new QPushButton(centralwidget);
        nitika->setObjectName("nitika");

        verticalLayout_3->addWidget(nitika);

        toukeiButton = new QPushButton(centralwidget);
        toukeiButton->setObjectName("toukeiButton");

        verticalLayout_3->addWidget(toukeiButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        QuitButton = new QPushButton(centralwidget);
        QuitButton->setObjectName("QuitButton");
        QuitButton->setMaximumSize(QSize(100, 20));
        QuitButton->setAutoExclusive(false);

        gridLayout->addWidget(QuitButton, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        gridLayout_3->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        doname = new QLabel(centralwidget);
        doname->setObjectName("doname");
        doname->setMinimumSize(QSize(0, 20));
        doname->setFrameShape(QFrame::Box);

        horizontalLayout_4->addWidget(doname);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(label);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setMaximumSize(QSize(50, 20));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(100);
        spinBox_2->setSingleStep(10);
        spinBox_2->setValue(100);

        horizontalLayout_4->addWidget(spinBox_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setInputMethodHints(Qt::ImhNone);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 600, 500));
        Image = new QLabel(scrollAreaWidgetContents);
        Image->setObjectName("Image");
        Image->setGeometry(QRect(0, 0, 211, 161));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Image->sizePolicy().hasHeightForWidth());
        Image->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(15);
        Image->setFont(font);
        Image->setInputMethodHints(Qt::ImhNone);
        Image->setFrameShadow(QFrame::Sunken);
        Image->setScaledContents(true);
        Image->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Image->setWordWrap(false);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        file = new QLabel(centralwidget);
        file->setObjectName("file");
        file->setMinimumSize(QSize(0, 20));
        file->setMaximumSize(QSize(16777215, 20));
        file->setFrameShape(QFrame::Box);

        gridLayout_4->addWidget(file, 1, 0, 1, 1);

        sizeLabel = new QLabel(centralwidget);
        sizeLabel->setObjectName("sizeLabel");
        sizeLabel->setMaximumSize(QSize(16777215, 20));
        sizeLabel->setFrameShape(QFrame::Box);

        gridLayout_4->addWidget(sizeLabel, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(verticalLayout_2, 0, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 795, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(QuitButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\224\273\345\203\217\345\207\246\347\220\206GUI", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\351\226\213\343\201\217", nullptr));
#if QT_CONFIG(shortcut)
        openButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        saveButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        saveButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        clearButton->setText(QCoreApplication::translate("MainWindow", "\343\202\257\343\203\252\343\202\242", nullptr));
#if QT_CONFIG(shortcut)
        clearButton->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        srcshow->setText(QCoreApplication::translate("MainWindow", "\345\216\237\347\224\273\345\203\217\350\241\250\347\244\272", nullptr));
#if QT_CONFIG(shortcut)
        srcshow->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        changeSrcButton->setText(QCoreApplication::translate("MainWindow", "\345\216\237\347\224\273\345\203\217\343\201\256\344\270\212\346\233\270\343\201\215", nullptr));
        kakudai->setText(QCoreApplication::translate("MainWindow", "\346\213\241\345\244\247\347\270\256\345\260\217", nullptr));
#if QT_CONFIG(shortcut)
        kakudai->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        grayscale->setText(QCoreApplication::translate("MainWindow", "\343\202\260\343\203\254\343\203\274\343\202\271\343\202\261\343\203\274\343\203\253\345\214\226", nullptr));
#if QT_CONFIG(shortcut)
        grayscale->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
        edge->setText(QCoreApplication::translate("MainWindow", "\343\202\250\343\203\203\343\202\270\346\244\234\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        edge->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        rotate->setText(QCoreApplication::translate("MainWindow", "\345\233\236\350\273\242", nullptr));
#if QT_CONFIG(shortcut)
        rotate->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        filtering->setText(QCoreApplication::translate("MainWindow", "\345\271\263\346\273\221\345\214\226", nullptr));
#if QT_CONFIG(shortcut)
        filtering->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        nitika->setText(QCoreApplication::translate("MainWindow", "\344\272\214\345\200\244\345\214\226", nullptr));
#if QT_CONFIG(shortcut)
        nitika->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        toukeiButton->setText(QCoreApplication::translate("MainWindow", "\347\265\261\350\250\210\351\207\217\350\241\250\347\244\272", nullptr));
#if QT_CONFIG(shortcut)
        toukeiButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        QuitButton->setText(QCoreApplication::translate("MainWindow", "\347\265\202\344\272\206", nullptr));
#if QT_CONFIG(shortcut)
        QuitButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        doname->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\213\241\345\244\247\347\216\207", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        Image->setText(QString());
        file->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\240\264\346\211\200 ", nullptr));
        sizeLabel->setText(QCoreApplication::translate("MainWindow", "\345\271\205\303\227\351\253\230\343\201\225", nullptr));
        menu->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
