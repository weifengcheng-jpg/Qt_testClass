#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon,
              Polyline, Points, Arc, Path, Text, Pixmap};
    explicit PaintArea(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // PAINTAREA_H
