#include "eventfilter.h"

EventFilter::EventFilter(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setWindowTitle(QString("事件过滤"));
    m_label1 = new QLabel;
    m_label2 = new QLabel;
    m_label3 = new QLabel;
    m_stateLabel = new QLabel(QString("鼠标按下标志"));
    m_stateLabel->setAlignment(Qt::AlignHCenter); //水平居中

    m_image1.load("fly1.png");
    m_image2.load("fly2.png");
    m_image3.load("fly3.png");

    m_label1->setPixmap(QPixmap::fromImage(m_image1));
    m_label2->setPixmap(QPixmap::fromImage(m_image2));
    m_label3->setPixmap(QPixmap::fromImage(m_image3));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_label1);
    layout->addWidget(m_label2);
    layout->addWidget(m_label3);

    QVBoxLayout* mainlayout = new QVBoxLayout(this);
    mainlayout->addLayout(layout);
    mainlayout->addWidget(m_stateLabel);

    resize(m_image2.width() * 3, m_image2.width() * 2);

    //给图片标签安装事件过滤, 指定整个窗体为监视事件的对象
    m_label1->installEventFilter(this);
    m_label2->installEventFilter(this);
    m_label3->installEventFilter(this);


}

EventFilter::~EventFilter()
{

}

bool EventFilter::eventFilter(QObject* watched, QEvent* event)
{
    //事件交个上层对话框进行处理
    return QDialog::eventFilter(watched, event);
}
