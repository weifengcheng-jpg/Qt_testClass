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
    m_shapeCombox = new QComboBox;

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
    m_penWidthSpinBox = new QSpinBox;
    m_penWidthSpinBox->setRange(1, 20);
    connect(m_penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));

    m_penStyleLabel = new QLabel(tr("画笔风格"));
    m_penStyleComboBox = new QComboBox;
    m_penStyleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    m_penStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    m_penStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    m_penStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    m_penStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    m_penStyleComboBox->addItem(tr("CustomDashLine"), static_cast<int>(Qt::CustomDashLine));
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
    m_brushStyleComboBox->addItem(tr("Dense1Pattern"), static_cast<int>(Qt::Dense1Pattern));
    m_brushStyleComboBox->addItem(tr("Dense2Pattern"), static_cast<int>(Qt::Dense2Pattern));
    m_brushStyleComboBox->addItem(tr("Dense3Pattern"), static_cast<int>(Qt::Dense3Pattern));
    m_brushStyleComboBox->addItem(tr("Dense4Pattern"), static_cast<int>(Qt::Dense4Pattern));
    m_brushStyleComboBox->addItem(tr("Dense5Pattern"), static_cast<int>(Qt::Dense5Pattern));
    m_brushStyleComboBox->addItem(tr("Dense6Pattern"), static_cast<int>(Qt::Dense6Pattern));
    m_brushStyleComboBox->addItem(tr("Dense7Pattern"), static_cast<int>(Qt::Dense7Pattern));
    m_brushStyleComboBox->addItem(tr("HorPattern"), static_cast<int>(Qt::HorPattern));
    m_brushStyleComboBox->addItem(tr("VerPattern"), static_cast<int>(Qt::VerPattern));
    m_brushStyleComboBox->addItem(tr("CrossPattern"), static_cast<int>(Qt::CrossPattern));
    m_brushStyleComboBox->addItem(tr("BDiagPattern"), static_cast<int>(Qt::BDiagPattern));
    m_brushStyleComboBox->addItem(tr("FDiagPattern"), static_cast<int>(Qt::FDiagPattern));
    m_brushStyleComboBox->addItem(tr("DiagCrossPattern"), static_cast<int>(Qt::DiagCrossPattern));
    m_brushStyleComboBox->addItem(tr("LinearGradientPattern"), static_cast<int>(Qt::LinearGradientPattern));
    m_brushStyleComboBox->addItem(tr("ConicalGradientPattern"), static_cast<int>(Qt::ConicalGradientPattern));
    m_brushStyleComboBox->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
    m_brushStyleComboBox->addItem(tr("TexturePattern"), static_cast<int>(Qt::TexturePattern));
    connect(m_brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowBrush(int)));

    //右侧布局
    m_rightLayout = new QGridLayout;

    //形状
    m_rightLayout->addWidget(m_shapeLabel, 0, 0);
    m_rightLayout->addWidget(m_shapeCombox, 0 ,1);

    //画笔颜色
    m_rightLayout->addWidget(m_penColorLabel, 1, 0);
    m_rightLayout->addWidget(m_penColorFrame, 1, 1);
    m_rightLayout->addWidget(m_penColorBtn, 1, 2);

    //画线宽度
    m_rightLayout->addWidget(m_penWidthLabel, 2, 0);
    m_rightLayout->addWidget(m_penWidthSpinBox, 2, 1);

    //画笔风格
    m_rightLayout->addWidget(m_penStyleLabel, 3, 0);
    m_rightLayout->addWidget(m_penStyleComboBox, 3, 1);

    m_rightLayout->addWidget(m_penCapLabel, 4, 0);
    m_rightLayout->addWidget(m_penCapComboBox, 4, 1);


    m_rightLayout->addWidget(m_penJoinLabel, 5, 0);
    m_rightLayout->addWidget(m_penJoinComboBox, 5, 1);

    m_rightLayout->addWidget(m_fillRuleLabel, 6, 0);
    m_rightLayout->addWidget(m_fillRuleComboBox, 6, 1);

    m_rightLayout->addWidget(m_spreadLabel, 7, 0);
    m_rightLayout->addWidget(m_spreadComboBox, 7, 1);

    m_rightLayout->addWidget(m_brushColorLabel, 8, 0);
    m_rightLayout->addWidget(m_brushColorFrame, 8, 1);
    m_rightLayout->addWidget(m_brushColorBtn, 8, 2);

    m_rightLayout->addWidget(m_brushStyleLabel, 9, 0);
    m_rightLayout->addWidget(m_brushStyleComboBox, 9, 1);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_paintArea);
    mainLayout->addLayout(m_rightLayout);

    ShowShape(m_shapeCombox->currentIndex());

}



void MainWidget::ShowShape(int value)
{
    PaintArea::Shape shape = PaintArea::Shape(m_shapeCombox->itemData(value).toInt());
    m_paintArea->setShape(shape);


}


void MainWidget::ShowPenColor()
{
    QColor color = QColorDialog::getColor(Qt::black);
    m_penColorFrame->setPalette(QPalette(color)); //
    int value = m_penWidthSpinBox->value();

    int styleIndex = m_penStyleComboBox->currentIndex(); //风格
    Qt::PenStyle style = Qt::PenStyle(m_penStyleComboBox->itemData(styleIndex).toInt());

    int capIndex = m_penCapComboBox->currentIndex(); //笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(m_penCapComboBox->itemData(capIndex).toInt());

    int joinIndex = m_penJoinComboBox->currentIndex(); //笔帽
    Qt::PenJoinStyle join = Qt::PenJoinStyle(m_penJoinComboBox->itemData(joinIndex).toInt());

    m_paintArea->setPen(QPen(color, value, style, cap, join));


}

void MainWidget::ShowPenWidth(int value)
{
    QColor color = m_penColorFrame->palette().color(QPalette::Window);
    int penWidth = value;

    int styleIndex = m_penStyleComboBox->currentIndex();
    Qt::PenStyle style = Qt::PenStyle(m_penStyleComboBox->itemData(styleIndex).toInt());

    int capIndex = m_penCapComboBox->currentIndex(); //笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(m_penCapComboBox->itemData(capIndex).toInt());

    int joinIndex = m_penJoinComboBox->currentIndex(); //笔帽
    Qt::PenJoinStyle join = Qt::PenJoinStyle(m_penJoinComboBox->itemData(joinIndex).toInt());

    m_paintArea->setPen(QPen(color, penWidth, style, cap, join));

}

void MainWidget::ShowPenCap(int value)
{
    QColor color = m_penColorFrame->palette().color(QPalette::Window);
    int penWidth = m_penWidthSpinBox->value();

    int styleIndex = m_penStyleComboBox->currentIndex();
    Qt::PenStyle style = Qt::PenStyle(m_penStyleComboBox->itemData(styleIndex).toInt());

    //int capIndex = m_penCapComboBox->currentIndex();
    Qt::PenCapStyle cap = Qt::PenCapStyle(m_penCapComboBox->itemData(value).toInt());

    int joinIndex = m_penJoinComboBox->currentIndex();
    Qt::PenJoinStyle join = Qt::PenJoinStyle(m_penJoinComboBox->itemData(joinIndex).toInt());

    m_paintArea->setPen(QPen(color, penWidth, style, cap, join));
}

//画笔连接点
void MainWidget::ShowPenJoin(int value)
{
    QColor color = m_penColorFrame->palette().color(QPalette::Window);
    int penWidth = m_penWidthSpinBox->value();

    int styleIndex = m_penStyleComboBox->currentIndex();
    Qt::PenStyle style = Qt::PenStyle(m_penStyleComboBox->itemData(styleIndex).toInt());

    int capIndex = m_penCapComboBox->currentIndex();
    Qt::PenCapStyle cap = Qt::PenCapStyle(m_penCapComboBox->itemData(capIndex).toInt());

    //int joinIndex = m_penJoinComboBox->currentIndex();
    Qt::PenJoinStyle join = Qt::PenJoinStyle(m_penJoinComboBox->itemData(value).toInt());

    m_paintArea->setPen(QPen(color, penWidth, style, cap, join));
}

//填充矩形
void MainWidget::ShowFillRule(int value)
{
    Qt::FillRule rule = Qt::FillRule(value);
    m_paintArea->setFillRule(rule);


}

void MainWidget::ShowSpreadStyle(int value)
{
    m_spread = QGradient::Spread(value);
}

void MainWidget::ShowBrushColor()
{
    QColor color = QColorDialog::getColor(Qt::green);
    m_brushColorFrame->setPalette(QPalette(color));
    ShowBrush(m_brushStyleComboBox->currentIndex());
}

void MainWidget::ShowBrush(int value)
{
    QColor color = m_brushColorFrame->palette().color(QPalette::Window);

    int brush = m_brushStyleComboBox->itemData(value).toInt();
    Qt::BrushStyle style = Qt::BrushStyle(brush);
    //线性渐变
    if (style == Qt::LinearGradientPattern) {
        //指定线性渐变的区域
        QLinearGradient lineGradient(0, 0, 400, 400);

        //指定某个位置的渐变色, pos取值0~1
        lineGradient.setColorAt(0.0, Qt::white);
        lineGradient.setColorAt(0.2, color);
        lineGradient.setColorAt(1.0, Qt::black);
        lineGradient.setSpread(m_spread);

        m_paintArea->setBrush(lineGradient);
    } else if (style == Qt::RadialGradientPattern) { //环形渲染
        //中心坐标, 半径长度, 焦点坐标, 如果需要对称则中心坐标和焦点坐标保持一致
        QRadialGradient radialGrdient(200, 200, 150, 200, 200);
        radialGrdient.setColorAt(0.0, Qt::white);
        radialGrdient.setColorAt(0.2, color);
        radialGrdient.setColorAt(1.0, Qt::black);

        m_paintArea->setBrush(radialGrdient);
    } else if (style == Qt::ConicalGradientPattern) { //弧度渲染(锥形渲染)
        //中心坐标, 角度
        QConicalGradient conicaoGradient(200, 200, 30);
        conicaoGradient.setColorAt(0.0, Qt::white);
        conicaoGradient.setColorAt(0.2, color);
        conicaoGradient.setColorAt(1.0, Qt::black);

        m_paintArea->setBrush(conicaoGradient);
    } else if (style == Qt::TexturePattern) {
        m_paintArea->setBrush(QBrush(QPixmap("fly3")));
    } else {
        m_paintArea->setBrush(QBrush(color, style));
    }
}

void MainWidget::ShowPenStyle(int value)
{
    QColor color = m_penColorFrame->palette().color(QPalette::Window);
    int penWidth = m_penWidthSpinBox->value();

    Qt::PenStyle style = Qt::PenStyle(m_penStyleComboBox->itemData(value).toInt());
    if (style == Qt::CustomDashLine) { //自定义
        QVector<qreal> dashes;
        qreal space = 4;
        dashes<< 1 << space << 2 << space << 3 << space << 4 << space;
        m_paintArea->m_pen.setDashPattern(dashes);
        m_paintArea->update();
    } else { //非自定义
        int capIndex = m_penCapComboBox->currentIndex();
        Qt::PenCapStyle cap = Qt::PenCapStyle(m_penCapComboBox->itemData(capIndex).toInt());

        int joinIndex = m_penJoinComboBox->currentIndex();
        Qt::PenJoinStyle join = Qt::PenJoinStyle(m_penJoinComboBox->itemData(joinIndex).toInt());

        m_paintArea->setPen(QPen(color, penWidth, style, cap, join));
    }


}



