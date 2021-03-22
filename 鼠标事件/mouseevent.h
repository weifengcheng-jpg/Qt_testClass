#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MouseEvent;
}

class MouseEvent : public QMainWindow
{
    Q_OBJECT

public:
    explicit MouseEvent(QWidget *parent = 0);
    ~MouseEvent();

protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e); //鼠标移动 && 按下
    void mouseReleaseEvent(QMouseEvent* e);


private:
    Ui::MouseEvent *ui;
    QLabel* m_statusLabel; //状态标签
    QLabel* m_posLabel; //位置标签
};

#endif // MOUSEEVENT_H
