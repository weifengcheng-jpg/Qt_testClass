#include "dialog.h"
#include "ui_dialog.h"

#include <QGridLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    createCtrlFrame();

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_ctrlFrame);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createCtrlFrame()
{
    m_ctrlFrame = new QFrame;
    m_ctrlFrame->setFrameStyle(QFrame::Sunken | QFrame::Box);

    m_windowsLabel = new QLabel("QPalette::Window:");
    m_windowsComboBox = new QComboBox;
    fillColorList(m_windowsComboBox);
    connect(m_windowsComboBox, SIGNAL(activated(int)), this, SLOT(ShowWindow()));

    m_windowTextLabel = new QLabel("QPalette:WindowText:");
    m_windowTextComboBox = new QComboBox;
    fillColorList(m_windowTextComboBox);
    connect(m_windowTextComboBox, SIGNAL(activated(int)), this, SLOT(ShowWindowText()));

    m_buttonLabel = new QLabel("QPatte::Buttton");
    m_buttonCombox = new QComboBox;
    fillColorList(m_buttonCombox);
    connect(m_buttonCombox, SIGNAL(activated(int)), this, SLOT(ShowButton()));

    m_buttonTextLabel = new QLabel("QPatte::ButtonText:");
    m_buttonTextComboBox = new QComboBox;
    fillColorList(m_buttonTextComboBox);
    connect(m_buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(ShowButtonText()));

    m_baseLabel = new QLabel("QPalette::Base:");
    m_baseComboBox = new QComboBox;
    fillColorList(m_baseComboBox);
    connect(m_baseComboBox, SIGNAL(activated(int)), this, SLOT(ShowBase()));

    QGridLayout* mainLayout = new QGridLayout(m_ctrlFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(m_windowsLabel, 0, 0);
    mainLayout->addWidget(m_windowsComboBox, 0, 1);
    mainLayout->addWidget(m_windowTextLabel, 1, 0);
    mainLayout->addWidget(m_windowTextComboBox, 1, 1);
    mainLayout->addWidget(m_buttonLabel, 2, 0);
    mainLayout->addWidget(m_buttonCombox, 2, 1);
    mainLayout->addWidget(m_buttonTextLabel, 3, 0);
    mainLayout->addWidget(m_buttonTextComboBox, 3, 1);
    mainLayout->addWidget(m_baseLabel, 4, 0);
    mainLayout->addWidget(m_baseComboBox, 4, 1);

}

void Dialog::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames();
    QString color;
    foreach (color, colorList) {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        comboBox->addItem(QIcon(pix), NULL);
        comboBox->setIconSize(QSize(70, 20));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);


    }

}

void Dialog::ShowWindow()
{

}

void Dialog::ShowWindowText()
{

}

void Dialog::ShowButton()
{

}

void Dialog::ShowButtonText()
{

}

void Dialog::ShowBase()
{

}
