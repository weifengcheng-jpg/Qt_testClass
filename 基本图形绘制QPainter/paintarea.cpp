#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setFixedSize(400, 400);



}

void PaintArea::setShape(PaintArea::Shape shape)
{
    m_shape = shape;
    update();

}

void PaintArea::setPen(QPen pen)
{
    m_pen = pen;
    update();
}

void PaintArea::setBrush(QBrush brush)
{
    m_brush = brush;
    update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
    m_fillrule = rule;
    update();
}

void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.setBrush(m_brush);

    QRect rect(50, 100, 300, 200); //矩形 点位置, 宽高
    const QPoint points[4] = {
        QPoint(150, 100),
        QPoint(300, 150),
        QPoint(350, 250),
        QPoint(100, 300)
    };

    //注意: 用QPainter 画弧度所使用的角度值, 是以1/16度 为单位的, 在画弧度的时候1度 用16 表示.
    int startAngle = 30 * 16; //起始位置
    int spanAngle = 120 * 16; //末尾位置

    QPainterPath path;
    path.addRect(150, 150, 100, 100);
    path.moveTo(100, 200);
    path.cubicTo(300, 100, 200, 200, 300, 300);
    path.cubicTo(100, 300, 200, 200, 100, 100);
    path.setFillRule(m_fillrule); //设置填充规则

    /*enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon,
              Polyline, Points, Arc, Path, Text, Pixmap};*/
    switch (m_shape) {

    case Line:
        painter.drawLine(rect.topLeft(), rect.bottomRight());
        break;
    case Rectangle:
        painter.drawRect(rect);
        break;
    case RoundRect:
        painter.drawRoundRect(rect);
        break;
    case Ellipse: //
        painter.drawEllipse(rect);
        break;
    case Polygon: //多边形
        painter.drawPolygon(points, 4);
        break;
    case Polyline:
        painter.drawPolyline(points, 4);
        break;
    case Points:
        painter.drawPoints(points, 4);
        break;
    case Arc:
        painter.drawArc(rect, startAngle, spanAngle);
        break;
    case Path:
        painter.drawPath(path);
        break;
    case Text:
        painter.drawText(rect, Qt::AlignCenter, tr("Hello World!"));
        break;
    case Pixmap:
        painter.drawPixmap(50, 100, QPixmap("fly3.png"));
        break;
    default:
        break;
    }





}
