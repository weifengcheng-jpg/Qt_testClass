#include "mouseevent.h"
#include "ui_mouseevent.h"
#include <QMouseEvent>

MouseEvent::MouseEvent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MouseEvent)
{
    ui->setupUi(this);
    setWindowTitle(QString("鼠标事件"));

    m_statusLabel = new QLabel(QString("当前位置"));
    m_statusLabel->setFixedWidth(100); //设置固定宽度

    m_posLabel = new QLabel(QString(""));
    m_posLabel->setFixedWidth(100);

    statusBar()->addPermanentWidget(m_statusLabel); //statusBar:返回主窗口的状态栏。如果状态栏'不存在，这个函数会创建并返回一个空的状态栏。
    statusBar()->addPermanentWidget(m_posLabel); //添加永久控件
    resize(400, 200);


}

MouseEvent::~MouseEvent()
{
    delete ui;
}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    QString str = "(" +
            QString::number(e->x()) +
            "," +
            QString::number(e->y()) +
            ")";

    if (e->button() == Qt::LeftButton) {
        statusBar()->showMessage(QString("左键: ") + str);

    } else if (e->button() == Qt::MidButton){
        statusBar()->showMessage(QString("中键: ") + str);
    } else if (e->button() == Qt::RightButton) {
        statusBar()->showMessage(QString("右键: ") + str);
    }
}

void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    QString strPos;
    strPos = "(" + QString::number(e->x()) +
            "," +
            QString::number(e->y()) +
            ")";
    m_posLabel->setText(strPos);
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    QString strPos;
    strPos = "(" + QString::number(e->x()) +
            "," +
            QString::number(e->y()) +
            ")";
    statusBar()->showMessage(QString("释放在: ") + strPos, 3000); //显示3秒钟
}
