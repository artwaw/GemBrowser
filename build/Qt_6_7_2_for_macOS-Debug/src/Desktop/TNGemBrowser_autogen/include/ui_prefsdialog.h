/********************************************************************************
** Form generated from reading UI file 'prefsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFSDIALOG_H
#define UI_PREFSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrefsDialog
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QPushButton *generalDefaults;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *saveHistoryBox;
    QPushButton *clearHistoryBtn;
    QGroupBox *historyDetailsGroup;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *mainPageRadio;
    QRadioButton *allGemsRadio;
    QGroupBox *historyTimingGroup;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *foreverBtn;
    QRadioButton *daysBtn;
    QSpinBox *historyDays;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *cacheGems;
    QCheckBox *cacheImages;
    QLabel *label_7;
    QSpinBox *cacheSize;
    QLabel *cacheUnits;
    QPushButton *clearCacheBtn;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QListWidget *styleItems;
    QPushButton *visualDefaults;
    QVBoxLayout *verticalLayout;
    QCheckBox *overrideBox;
    QGroupBox *itemOptionsGroup;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *fontFamilyBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QComboBox *fontBox;
    QToolButton *fontPicker;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSpinBox *fontSize;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *textBgLine;
    QToolButton *txtBgPicker;
    QLabel *label_3;
    QDoubleSpinBox *intednationBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *textClrLine;
    QToolButton *txtColorPicker;
    QCheckBox *BoldBox;
    QCheckBox *ItalicBox;
    QCheckBox *underlineBox;
    QWidget *tab_3;
    QWidget *Browsing;
    QGroupBox *groupBox_2;
    QRadioButton *geminiNewTab;
    QRadioButton *geminiInPlace;
    QGroupBox *groupBox_3;
    QRadioButton *ignoreHttp;
    QRadioButton *systemHttp;
    QRadioButton *customHttp;
    QGroupBox *groupBox_4;
    QLineEdit *startPage;
    QHBoxLayout *horizontalLayout;
    QPushButton *HelpBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *defaultsBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *CancelBtn;

    void setupUi(QDialog *PrefsDialog)
    {
        if (PrefsDialog->objectName().isEmpty())
            PrefsDialog->setObjectName("PrefsDialog");
        PrefsDialog->setWindowModality(Qt::WindowModal);
        PrefsDialog->resize(701, 349);
        PrefsDialog->setModal(true);
        gridLayout_2 = new QGridLayout(PrefsDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidget = new QTabWidget(PrefsDialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName("gridLayout_4");
        generalDefaults = new QPushButton(tab);
        generalDefaults->setObjectName("generalDefaults");

        gridLayout_4->addWidget(generalDefaults, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        saveHistoryBox = new QCheckBox(tab);
        saveHistoryBox->setObjectName("saveHistoryBox");

        verticalLayout_2->addWidget(saveHistoryBox);

        clearHistoryBtn = new QPushButton(tab);
        clearHistoryBtn->setObjectName("clearHistoryBtn");

        verticalLayout_2->addWidget(clearHistoryBtn);


        horizontalLayout_7->addLayout(verticalLayout_2);

        historyDetailsGroup = new QGroupBox(tab);
        historyDetailsGroup->setObjectName("historyDetailsGroup");
        horizontalLayout_5 = new QHBoxLayout(historyDetailsGroup);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        mainPageRadio = new QRadioButton(historyDetailsGroup);
        mainPageRadio->setObjectName("mainPageRadio");

        horizontalLayout_5->addWidget(mainPageRadio);

        allGemsRadio = new QRadioButton(historyDetailsGroup);
        allGemsRadio->setObjectName("allGemsRadio");

        horizontalLayout_5->addWidget(allGemsRadio);


        horizontalLayout_7->addWidget(historyDetailsGroup);

        historyTimingGroup = new QGroupBox(tab);
        historyTimingGroup->setObjectName("historyTimingGroup");
        horizontalLayout_6 = new QHBoxLayout(historyTimingGroup);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        foreverBtn = new QRadioButton(historyTimingGroup);
        foreverBtn->setObjectName("foreverBtn");

        horizontalLayout_6->addWidget(foreverBtn);

        daysBtn = new QRadioButton(historyTimingGroup);
        daysBtn->setObjectName("daysBtn");

        horizontalLayout_6->addWidget(daysBtn);

        historyDays = new QSpinBox(historyTimingGroup);
        historyDays->setObjectName("historyDays");

        horizontalLayout_6->addWidget(historyDays);


        horizontalLayout_7->addWidget(historyTimingGroup);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        cacheGems = new QCheckBox(groupBox);
        cacheGems->setObjectName("cacheGems");

        horizontalLayout_9->addWidget(cacheGems);

        cacheImages = new QCheckBox(groupBox);
        cacheImages->setObjectName("cacheImages");

        horizontalLayout_9->addWidget(cacheImages);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        cacheSize = new QSpinBox(groupBox);
        cacheSize->setObjectName("cacheSize");
        cacheSize->setMinimumSize(QSize(71, 22));
        cacheSize->setReadOnly(true);
        cacheSize->setMaximum(1024);

        horizontalLayout_9->addWidget(cacheSize);

        cacheUnits = new QLabel(groupBox);
        cacheUnits->setObjectName("cacheUnits");

        horizontalLayout_9->addWidget(cacheUnits);


        verticalLayout_5->addLayout(horizontalLayout_9);

        clearCacheBtn = new QPushButton(groupBox);
        clearCacheBtn->setObjectName("clearCacheBtn");

        verticalLayout_5->addWidget(clearCacheBtn);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        styleItems = new QListWidget(tab_2);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        new QListWidgetItem(styleItems);
        styleItems->setObjectName("styleItems");

        verticalLayout_3->addWidget(styleItems);

        visualDefaults = new QPushButton(tab_2);
        visualDefaults->setObjectName("visualDefaults");

        verticalLayout_3->addWidget(visualDefaults);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        overrideBox = new QCheckBox(tab_2);
        overrideBox->setObjectName("overrideBox");

        verticalLayout->addWidget(overrideBox);

        itemOptionsGroup = new QGroupBox(tab_2);
        itemOptionsGroup->setObjectName("itemOptionsGroup");
        verticalLayout_4 = new QVBoxLayout(itemOptionsGroup);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(itemOptionsGroup);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        fontFamilyBox = new QComboBox(itemOptionsGroup);
        fontFamilyBox->setObjectName("fontFamilyBox");

        horizontalLayout_4->addWidget(fontFamilyBox);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_5 = new QLabel(itemOptionsGroup);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        fontBox = new QComboBox(itemOptionsGroup);
        fontBox->setObjectName("fontBox");

        horizontalLayout_4->addWidget(fontBox);

        fontPicker = new QToolButton(itemOptionsGroup);
        fontPicker->setObjectName("fontPicker");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("preferences-desktop-locale")));
        fontPicker->setIcon(icon);

        horizontalLayout_4->addWidget(fontPicker);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_6 = new QLabel(itemOptionsGroup);
        label_6->setObjectName("label_6");

        horizontalLayout_8->addWidget(label_6);

        fontSize = new QSpinBox(itemOptionsGroup);
        fontSize->setObjectName("fontSize");
        fontSize->setMinimum(8);

        horizontalLayout_8->addWidget(fontSize);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(itemOptionsGroup);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        textBgLine = new QLineEdit(itemOptionsGroup);
        textBgLine->setObjectName("textBgLine");

        horizontalLayout_3->addWidget(textBgLine);

        txtBgPicker = new QToolButton(itemOptionsGroup);
        txtBgPicker->setObjectName("txtBgPicker");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("applications-graphics")));
        txtBgPicker->setIcon(icon1);

        horizontalLayout_3->addWidget(txtBgPicker);

        label_3 = new QLabel(itemOptionsGroup);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        intednationBox = new QDoubleSpinBox(itemOptionsGroup);
        intednationBox->setObjectName("intednationBox");
        intednationBox->setMinimum(1.000000000000000);

        horizontalLayout_3->addWidget(intednationBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(itemOptionsGroup);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        textClrLine = new QLineEdit(itemOptionsGroup);
        textClrLine->setObjectName("textClrLine");

        horizontalLayout_2->addWidget(textClrLine);

        txtColorPicker = new QToolButton(itemOptionsGroup);
        txtColorPicker->setObjectName("txtColorPicker");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("accessories-character-map")));
        txtColorPicker->setIcon(icon2);

        horizontalLayout_2->addWidget(txtColorPicker);

        BoldBox = new QCheckBox(itemOptionsGroup);
        BoldBox->setObjectName("BoldBox");

        horizontalLayout_2->addWidget(BoldBox);

        ItalicBox = new QCheckBox(itemOptionsGroup);
        ItalicBox->setObjectName("ItalicBox");

        horizontalLayout_2->addWidget(ItalicBox);

        underlineBox = new QCheckBox(itemOptionsGroup);
        underlineBox->setObjectName("underlineBox");

        horizontalLayout_2->addWidget(underlineBox);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(itemOptionsGroup);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        Browsing = new QWidget();
        Browsing->setObjectName("Browsing");
        groupBox_2 = new QGroupBox(Browsing);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 10, 291, 71));
        geminiNewTab = new QRadioButton(groupBox_2);
        geminiNewTab->setObjectName("geminiNewTab");
        geminiNewTab->setGeometry(QRect(10, 30, 121, 20));
        geminiInPlace = new QRadioButton(groupBox_2);
        geminiInPlace->setObjectName("geminiInPlace");
        geminiInPlace->setGeometry(QRect(140, 30, 141, 20));
        groupBox_3 = new QGroupBox(Browsing);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(320, 10, 341, 71));
        ignoreHttp = new QRadioButton(groupBox_3);
        ignoreHttp->setObjectName("ignoreHttp");
        ignoreHttp->setGeometry(QRect(20, 30, 81, 20));
        systemHttp = new QRadioButton(groupBox_3);
        systemHttp->setObjectName("systemHttp");
        systemHttp->setGeometry(QRect(100, 30, 151, 20));
        customHttp = new QRadioButton(groupBox_3);
        customHttp->setObjectName("customHttp");
        customHttp->setGeometry(QRect(260, 30, 71, 20));
        groupBox_4 = new QGroupBox(Browsing);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 90, 651, 61));
        startPage = new QLineEdit(groupBox_4);
        startPage->setObjectName("startPage");
        startPage->setGeometry(QRect(20, 30, 621, 21));
        startPage->setMinimumSize(QSize(621, 0));
        startPage->setClearButtonEnabled(true);
        tabWidget->addTab(Browsing, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        HelpBtn = new QPushButton(PrefsDialog);
        HelpBtn->setObjectName("HelpBtn");

        horizontalLayout->addWidget(HelpBtn);

        horizontalSpacer_3 = new QSpacerItem(120, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        defaultsBtn = new QPushButton(PrefsDialog);
        defaultsBtn->setObjectName("defaultsBtn");

        horizontalLayout->addWidget(defaultsBtn);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(PrefsDialog);
        okBtn->setObjectName("okBtn");

        horizontalLayout->addWidget(okBtn);

        CancelBtn = new QPushButton(PrefsDialog);
        CancelBtn->setObjectName("CancelBtn");

        horizontalLayout->addWidget(CancelBtn);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(PrefsDialog);

        tabWidget->setCurrentIndex(0);
        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(PrefsDialog);
    } // setupUi

    void retranslateUi(QDialog *PrefsDialog)
    {
        PrefsDialog->setWindowTitle(QCoreApplication::translate("PrefsDialog", "Dialog", nullptr));
        generalDefaults->setText(QCoreApplication::translate("PrefsDialog", "Defaults", nullptr));
        saveHistoryBox->setText(QCoreApplication::translate("PrefsDialog", "Save history", nullptr));
        clearHistoryBtn->setText(QCoreApplication::translate("PrefsDialog", "Clear now!", nullptr));
        historyDetailsGroup->setTitle(QCoreApplication::translate("PrefsDialog", "History details", nullptr));
        mainPageRadio->setText(QCoreApplication::translate("PrefsDialog", "Main pages only", nullptr));
        allGemsRadio->setText(QCoreApplication::translate("PrefsDialog", "All gems visited", nullptr));
        historyTimingGroup->setTitle(QCoreApplication::translate("PrefsDialog", "Timing", nullptr));
        foreverBtn->setText(QCoreApplication::translate("PrefsDialog", "Forever", nullptr));
        daysBtn->setText(QCoreApplication::translate("PrefsDialog", "Days:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PrefsDialog", "Caching", nullptr));
        cacheGems->setText(QCoreApplication::translate("PrefsDialog", "Cache gems", nullptr));
        cacheImages->setText(QCoreApplication::translate("PrefsDialog", "Cache images", nullptr));
        label_7->setText(QCoreApplication::translate("PrefsDialog", "Current cache size:", nullptr));
        cacheUnits->setText(QString());
        clearCacheBtn->setText(QCoreApplication::translate("PrefsDialog", "Clear cache", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("PrefsDialog", "General", nullptr));

        const bool __sortingEnabled = styleItems->isSortingEnabled();
        styleItems->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = styleItems->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("PrefsDialog", "Plain text", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = styleItems->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("PrefsDialog", "Links", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = styleItems->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("PrefsDialog", "Quotations", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = styleItems->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("PrefsDialog", "Heading 1", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = styleItems->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("PrefsDialog", "Heading 2", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = styleItems->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("PrefsDialog", "Heading 3", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = styleItems->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("PrefsDialog", "Preformatted ", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = styleItems->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("PrefsDialog", "Lists", nullptr));
        styleItems->setSortingEnabled(__sortingEnabled);

        visualDefaults->setText(QCoreApplication::translate("PrefsDialog", "Restore defaults", nullptr));
        overrideBox->setText(QCoreApplication::translate("PrefsDialog", "Override defaults", nullptr));
        itemOptionsGroup->setTitle(QCoreApplication::translate("PrefsDialog", "Item options", nullptr));
        label_4->setText(QCoreApplication::translate("PrefsDialog", "Font family:", nullptr));
        label_5->setText(QCoreApplication::translate("PrefsDialog", "Font:", nullptr));
        fontPicker->setText(QString());
        label_6->setText(QCoreApplication::translate("PrefsDialog", "Font size (pt):", nullptr));
        label_2->setText(QCoreApplication::translate("PrefsDialog", "Text background:", nullptr));
        textBgLine->setPlaceholderText(QCoreApplication::translate("PrefsDialog", "#aabbcc", nullptr));
        txtBgPicker->setText(QString());
        label_3->setText(QCoreApplication::translate("PrefsDialog", "Intendation (px):", nullptr));
        label->setText(QCoreApplication::translate("PrefsDialog", "Text colour:", nullptr));
        textClrLine->setPlaceholderText(QCoreApplication::translate("PrefsDialog", "#aabbcc", nullptr));
        txtColorPicker->setText(QString());
        BoldBox->setText(QCoreApplication::translate("PrefsDialog", "Bold", nullptr));
        ItalicBox->setText(QCoreApplication::translate("PrefsDialog", "Italic", nullptr));
        underlineBox->setText(QCoreApplication::translate("PrefsDialog", "Underline", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("PrefsDialog", "Visual", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("PrefsDialog", "TLS", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PrefsDialog", "Gemini links", nullptr));
        geminiNewTab->setText(QCoreApplication::translate("PrefsDialog", "Open in new tab", nullptr));
        geminiInPlace->setText(QCoreApplication::translate("PrefsDialog", "Follow in place", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("PrefsDialog", "Other protocols", nullptr));
        ignoreHttp->setText(QCoreApplication::translate("PrefsDialog", "Ignore", nullptr));
        systemHttp->setText(QCoreApplication::translate("PrefsDialog", "Use system browser", nullptr));
        customHttp->setText(QCoreApplication::translate("PrefsDialog", "Custom", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("PrefsDialog", "Start page (leave empty for nothing)", nullptr));
        startPage->setPlaceholderText(QCoreApplication::translate("PrefsDialog", "gemini://", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Browsing), QCoreApplication::translate("PrefsDialog", "Browsing", nullptr));
        HelpBtn->setText(QCoreApplication::translate("PrefsDialog", "Help", nullptr));
        defaultsBtn->setText(QCoreApplication::translate("PrefsDialog", "Restore all", nullptr));
        okBtn->setText(QCoreApplication::translate("PrefsDialog", "Accept", nullptr));
        CancelBtn->setText(QCoreApplication::translate("PrefsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrefsDialog: public Ui_PrefsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFSDIALOG_H
