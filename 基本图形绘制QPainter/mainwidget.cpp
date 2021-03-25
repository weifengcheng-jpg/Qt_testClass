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

    m_penWidthLabel = new QLabel(tr("画线宽度"));
    m_penwWidthSpinBox = new QSpinBox;
    m_penwWidthSpinBox->setRange(1, 20);
    connect(m_penwWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));

    m_penStyleLabel = new QLabel(tr("画笔风格"));
    m_penStyleComboBox = new QComboBox;
    m_penStyleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    m_penStyleComboBox->addItem(tr("DashLine"), static_cast<int>Qt::DashLine);
    m_penStyleComboBox->addItem(tr("DotLine"), static_cast<int>Qt::DotLine);
    m_penStyleComboBox->addItem((tr("DashDotLine"), static_cast<int>Qt::DashDotLine));
    m_penStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>Qt::DashDotDotLine);
    m_penStyleComboBox->addItem(tr("CustomDashLine"), static_cast<int>Qt::CustomDashLine);
    connect(m_penStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenStyle(int)));

    m_penCapLabel = new QLabel(tr("画笔笔帽"));
    m_penCapComboBox = new QComboBox;
    m_penCapComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
    m_penCapComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
    m_penCapComboBox->addItem(tr("RoundCap"), Qt::RoundCap);
    connect(m_penCapComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenCap(int)));

    m_penJoinLabel = new QLabel(tr("画笔连接点"));
    m_penJoinComboBox = new QComboBox;
    m_penJoinComboBox->addItem(tr("BeveJoin"), Qt::BevelJoin);
    m_penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
    m_penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);
    connect(m_penJoinComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenJoin(int)));

    m_fillRuleLabel = new QLabel(tr("填充模式"));
    m_fillRuleComboBox = new QComboBox;
    m_fillRuleComboBox->addItem(tr("Odd Event"), Qt::OddEvenFill);
    m_fillRuleComboBox->addItem(tr("Winding"), Qt::WindingFill);
    connect(m_fillRuleComboBox, SIGNAL(activated(int)), this, SLOT(ShowFillRule(int)));

    //铺展效果
    m_spreadLabel = new QLabel(tr("铺展效果"));
    m_spreadComboBox = new QComboBox;
    m_spreadComboBox->addItem(tr("PadStread"), QGradient::PadSpread);
    m_spreadComboBox->addItem(tr("RepeatSpread"), QGradient::RepeatSpread);
    m_spreadComboBox->addItem(tr("ReflectSpread"), QGradient::ReflectSpread);
    connect(m_spreadComboBox, SIGNAL(activated(int)), this, SLOT(ShowSpreadStyle(int)));

    //画刷颜色
    m_brushColorLabel = new QLabel(tr("画刷颜色"));
    m_brushColorFrame = new QFrame;
    m_brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_brushColorFrame->setAutoFillBackground(true);
    m_brushColorFrame->setPalette(QPalette(Qt::green));
    m_brushColorBtn = new QPushButton(tr("更改"));
    connect(m_brushColorBtn, SIGNAL(clicked(bool)), this, SLOT(ShowBrushColor()));

    //画刷风格
    m_brushStyleLabel = new QLabel(tr("画刷风格"));
    m_brushStyleComboBox = new QComboBox;
    m_brushStyleComboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
    m_brushStyleComboBox->addItem(tr("Dense1Pattern", static_cast<int>(Qt::Dense1Pattern)));
    m_brushStyleComboBox->addItem(tr("Dense2Pattern", static_cast<int>(Qt::Dense2Pattern)));
    m_brushStyleComboBox->addItem(tr("Dense3Pattern", static_cast<int>(Qt::Dense3Pattern)));
    m_brushStyleComboBox->addItem(tr("Dense4Pattern", static_cast<int>(Qt::Dense4Pattern)));
    m_brushStyleComboBox->addItem(tr("Dense5Pattern", static_cast<int>(Qt::Dense5Pattern)));
    m_brushStyleComboBox->addItem(tr("Dense6Pattern", static_cast<int>(Qt::Dense6Pattern)));
    m_brushStyleComboBox->addItem(tr("Dense7Pattern", static_cast<int>(Qt::Dense7Pattern)));
    m_brushStyleComboBox->addItem(tr("HorPattern", static_cast<int>(Qt::HorPattern)));
    m_brushStyleComboBox->addItem(tr("VerPattern", static_cast<int>(Qt::VerPattern)));
    m_brushStyleComboBox->addItem(tr("CrossPattern", static_cast<int>(Qt::CrossPattern)));
    m_brushStyleComboBox->addItem(tr("BDiagPattern", static_cast<int>(Qt::BDiagPattern)));
    m_brushStyleComboBox->addItem(tr("FDiagPattern", static_cast<int>(Qt::FDiagPattern)));
    m_brushStyleComboBox->addItem(tr("DiagCrossPattern", static_cast<int>(Qt::DiagCrossPattern)));
    m_brushStyleComboBox->addItem(tr("LinearGradientPattern", static_cast<int>(Qt::LinearGradientPattern)));
    m_brushStyleComboBox->addItem(tr("ConicalGradientPattern", static_cast<int>(Qt::ConicalGradientPattern)));
    m_brushStyleComboBox->addItem(tr("RadialGradientPattern", static_cast<int>(Qt::RadialGradientPattern)));
    m_brushStyleComboBox->addItem(tr("TexturePattern", static_cast<int>(Qt::TexturePattern)));
    connect(m_brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowBrush(int)));


}



void MainWidget::ShowShape(int value)
{

}

void MainWidget::ShowPenColor()
{

}

void MainWidget::ShowPenWidth(int value)
{

}

void MainWidget::ShowPenCap(int value)
{

}

void MainWidget::ShowPenJoin(int value)
{

}

void MainWidget::ShowSpreadStyle(int value)
{

}

void MainWidget::ShowBrush(int value)
{

}

void MainWidget::ShowPenStyle(int value)
{

}
