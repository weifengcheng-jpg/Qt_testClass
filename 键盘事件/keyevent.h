#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QKeyEvent>

namespace Ui {
class KeyEvent;
}

class KeyEvent : public QWidget
{
    Q_OBJECT

public:
    explicit KeyEvent(QWidget *parent = 0);
    ~KeyEvent();
    void drawPix();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void paintEvent(QPaintEvent* event) override;



private:
    Ui::KeyEvent *ui;
    QPixmap* m_pix;
    QImage m_image;
    int m_startX; //图标定点位置
    int m_startY;
    int m_width; //界面的宽度 高度
    int m_height;
    int m_step; //步长


};

#endif // KEYEVENT_H
