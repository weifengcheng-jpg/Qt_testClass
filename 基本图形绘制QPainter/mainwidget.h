#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include "paintarea.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void initWidgets();

private slots:
    void ShowShape(int value);
    void ShowPenColor()

private:
    PaintArea* m_paintArea; //绘图区域

    QLabel* m_shapeLabel; //形状
    QComboBox* m_shapeCombox;

    QLabel* m_penColorLabel; //画笔颜色
    QFrame* m_penColorFrame;
    QPushButton* m_penColorBtn;

    QLabel* m_penWidthLabel; //线宽
    QSpinBox* m_penwWidthSpinBox;

    QLabel* m_penStyleLabel; //画笔风格
    QComboBox* m_penStyleComboBox;

    QLabel* m_penCapLabel; //笔帽风格
    QComboBox* m_penCapComboBox;

    QLabel* m_penJoinLabel; //画笔连接点
    QComboBox* m_penJoinComboBox;

    QLabel* m_fillRuleLabel; //填充模式
    QComboBox* m_fillRuleComboBox;

    QLabel* m_spreadLabel; //铺展效果
    QComboBox* m_spreadComboBox;

    QLabel* m_brushColorLabel; //画刷颜色
    QFrame* m_brushColorFrame;
    QPushButton* m_brushColorBtn;

    QLabel* m_brushStyleLabel; //画刷风格
    QComboBox* m_brushStyleComboBox;

    QGridLayout* m_rightLayout;

};

#endif // MAINWIDGET_H
