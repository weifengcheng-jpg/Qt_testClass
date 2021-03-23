#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QHBoxLayout>
#include <QVBoxLayout>

class EventFilter : public QDialog
{
    Q_OBJECT

public:
    EventFilter(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~EventFilter();

public slots:
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    QLabel* m_label1;
    QLabel* m_label2;
    QLabel* m_label3;
    QLabel* m_stateLabel;
    QImage m_image1;
    QImage m_image2;
    QImage m_image3;



};

#endif // EVENTFILTER_H
