#include "keyevent.h"
#include "ui_keyevent.h"

KeyEvent::KeyEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyEvent)
{
    ui->setupUi(this);
    setWindowTitle(QString("键盘事件"));
    setAutoFillBackground(true);
    setFixedSize(512, 256);
    m_width = this->size().width();
    m_height = this->size().height();

    m_pix = new QPixmap(m_width, m_height);
    m_pix->fill(Qt::white);

    m_image.load("tiger.png");

    m_startX = 100;
    m_startY = 100;
    m_step = 20;
    drawPix();


}

KeyEvent::~KeyEvent()
{
    delete ui;
}

void KeyEvent::drawPix()
{
    m_pix->fill(Qt::white);

    QPainter painter(this);
    QPen pen(Qt::DotLine);


    //画网格
    painter.begin(m_pix); //指定m_pix为绘图设备
    painter.setPen(pen); //设置笔
    //按照步长画纵向网格线
    for (int i = m_step; i < m_width; i += m_step) {
        painter.drawLine(QPoint(i, 0), QPoint(i, m_height));
    }

    //按照步长画水平网格线
    for (int j = m_step; j < m_height; j += m_step) {
        painter.drawLine(QPoint(0, j), QPoint(m_width, j)); //j: 20 40 60 80
    }
    painter.end();


    //画图片
    painter.begin(m_pix);
    painter.drawImage(QPoint(m_startX, m_startY), m_image);
    painter.end();
}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    //按下Ctrl 键
    if (event->modifiers() == Qt::ControlModifier) { //ControlModifier:控制修改器
        if (event->key() == Qt::Key_Left) { //按下左键 左移
            m_startX = (m_startX - 1) < 0 ? m_startX : m_startX - 1; //判断是否移出窗口
        }
        if (event->key() == Qt::Key_Right) { //右移
            m_startX = (m_startX + 1 + m_image.width()) > m_width ? m_startX : m_startX + 1;
        }
        if (event->key() == Qt::Key_Up) {
            m_startY = (m_startY - 1) < 0 ? m_startY : m_startY - 1;
        }
        if (event->key() == Qt::Key_Down) {
            m_startY = (m_startY + 1 + m_image.height()) > m_height ? m_startY : m_startY + 1;
        }
    } else { //没有按下Ctrl键, 每次移动为一个步长
        //调整图标左上角位置到网格顶点
        m_startX = m_startX - m_startX % m_step;
        m_startY = m_startY - m_startY % m_step;

        if (event->key() == Qt::Key_Left) {
            m_startX = (m_startX - m_step) < 0 ? m_startX : m_startX - m_step;
        }
        if (event->key() == Qt::Key_Right) {
            m_startX = (m_startX + m_step + m_image.width()) > m_width ? m_startX : m_startX + m_step;
        }
        if (event->key() == Qt::Key_Up) {
            m_startY = (m_startY - m_step) < 0 ? m_startY : m_startY - m_step;
        }
        if (event->key() == Qt::Key_Down) {
            m_startY = (m_startY + m_step + m_image.height()) > m_height ? m_startY : m_startY + m_step;
        }
    }

    drawPix(); //根据调整后的图标位置重新在 m_pix 上绘制图像
    update(); //触发窗口重绘

}

void KeyEvent::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0, 0), *m_pix);
    painter.end();
}
