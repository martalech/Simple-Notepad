/********************************************************************************
** Form generated from reading UI file 'KeywordFinder.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYWORDFINDER_H
#define UI_KEYWORDFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeywordFinder
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *KeywordFinder)
    {
        if (KeywordFinder->objectName().isEmpty())
            KeywordFinder->setObjectName(QStringLiteral("KeywordFinder"));
        KeywordFinder->resize(641, 93);
        horizontalLayout = new QHBoxLayout(KeywordFinder);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(KeywordFinder);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(KeywordFinder);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(KeywordFinder);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(KeywordFinder);

        QMetaObject::connectSlotsByName(KeywordFinder);
    } // setupUi

    void retranslateUi(QWidget *KeywordFinder)
    {
        KeywordFinder->setWindowTitle(QApplication::translate("KeywordFinder", "KeywordFinder", nullptr));
        label->setText(QApplication::translate("KeywordFinder", "Keyword:", nullptr));
        pushButton->setText(QApplication::translate("KeywordFinder", "Find next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeywordFinder: public Ui_KeywordFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYWORDFINDER_H
