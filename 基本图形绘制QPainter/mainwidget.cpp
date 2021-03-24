#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    initWidgets();

}

MainWidget::~MainWidget()
{

}

void MainWidget::initWidgets()
{
    m_paintArea = new PaintArea;
    m_shapeLabel = new QLabel(tr("形状"));
    m_shapeCombox = new m_shapeCombox;

    m_shapeCombox->addItem(tr("Line"), PaintArea::Line);
    m_shapeCombox->addItem(tr("Rectangle"), PaintArea::Rectangle);
    m_shapeCombox->addItem(tr("RoundRect"), PaintArea::RoundRect);
    m_shapeCombox->addItem(tr("Ellipse"), PaintArea::Ellipse);
    m_shapeCombox->addItem(tr("Polygon"), PaintArea::Polygon);
    m_shapeCombox->addItem(tr("Polyline"), PaintArea::Polyline);
    m_shapeCombox->addItem(tr("Points"), PaintArea::Points);
    m_shapeCombox->addItem(tr("Arc"), PaintArea::Arc);
    m_shapeCombox->addItem(tr("Path"), PaintArea::Path);
    m_shapeCombox->addItem(tr("Text"), PaintArea::Text);
    m_shapeCombox->addItem(tr("Pixmap"), PaintArea::Pixmap);
    connect(m_shapeCombox, SIGNAL(activated(int)), this, SLOT(ShowShape(int)));

    m_penColorLabel = new QLabel(tr("画笔颜色"));
    m_penColorFrame = new QFrame;
    m_penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_penColorFrame->setAutoFillBackground(true);
    m_penColorFrame->setPalette(QPalette(Qt::black));
    m_penColorBtn = new QPushButton(tr("更改"));
    connect(m_penColorBtn, SIGNAL(clicked(bool)), this, SLOT(ShowPenColor()));



}

void MainWidget::ShowShape(int value)
{

}

void MainWidget::ShowPenColor()
{

}
