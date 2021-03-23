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
    QMatrix matrix;
    QImage tmpImg; //这个是用来存放图片的变化的

    //放大图片
    matrix.scale(2.0, 2.0);
    if (watched == m_label1) {
        //鼠标按下事件的处理
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if (mouseEvent->buttons() & Qt::LeftButton) {
                m_stateLabel->setText(QString("左键按下图片1"));
            }
            if (mouseEvent->buttons() & Qt::MidButton) {
                m_stateLabel->setText(QString("中键按下图片1"));
            }
            if (mouseEvent->buttons() & Qt::RightButton) {
                m_stateLabel->setText(QString("右键按下图片1"));
            }

            tmpImg = m_image1.transformed(matrix);
            m_label1->setPixmap(QPixmap::fromImage(tmpImg));
        }

        //鼠标释放, 恢复图片大小
        if (event->type() == QEvent::MouseButtonRelease) {
            m_stateLabel->setText(QString("鼠标释放图片1"));
            m_label1->setPixmap(QPixmap::fromImage(m_image1));
        }
    } else if (watched == m_label2) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if (mouseEvent->buttons() & Qt::LeftButton) {
                m_stateLabel->setText(QString("左键按下图片2"));
            }
            if (mouseEvent->buttons() & Qt::MidButton) {
                m_stateLabel->setText(QString("中键按下图片2"));
            }
            if (mouseEvent->buttons() & Qt::RightButton) {
                m_stateLabel->setText(QString("右键按下图片2"));
            }

            tmpImg = m_image2.transformed(matrix);
            m_label2->setPixmap(QPixmap::fromImage(tmpImg));
        }

        //鼠标释放, 恢复图片大小
        if (event->type() == QEvent::MouseButtonRelease) {
            m_stateLabel->setText(QString("鼠标释放图片2"));
            m_label2->setPixmap(QPixmap::fromImage(m_image2));
        }
    } else if (watched == m_label3) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if (mouseEvent->buttons() & Qt::LeftButton) {
                m_stateLabel->setText(QString("左键按下图片3"));
            }
            if (mouseEvent->buttons() & Qt::MidButton) {
                m_stateLabel->setText(QString("中键按下图片3"));
            }
            if (mouseEvent->buttons() & Qt::RightButton) {
                m_stateLabel->setText(QString("右键按下图片3"));
            }

            tmpImg = m_image3.transformed(matrix);
            m_label3->setPixmap(QPixmap::fromImage(tmpImg));
        }

        //鼠标释放, 恢复图片大小
        if (event->type() == QEvent::MouseButtonRelease) {
            m_stateLabel->setText(QString("鼠标释放图片3"));
            m_label3->setPixmap(QPixmap::fromImage(m_image3));
        }
    }


    //事件交个上层对话框进行处理
    return QDialog::eventFilter(watched, event);
}
