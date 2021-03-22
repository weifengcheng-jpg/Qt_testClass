#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QFrame>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void createCtrlFrame();
    void createContentFrame();

    //给组合框添加颜色列表
    void fillColorList(QComboBox* comboBox);

public slots:
    void ShowWindow(int index);
    void ShowWindowText(int index);
    void ShowButton(int index);
    void ShowButtonText(int index);
    void ShowBase(int index);


private:
    QFrame* m_ctrlFrame;
    QLabel* m_windowsLabel;
    QComboBox* m_windowsComboBox;
    QLabel* m_windowTextLabel;
    QComboBox* m_windowTextComboBox; //组合框
    QLabel* m_buttonLabel; //按钮标签
    QComboBox* m_buttonCombox; //按钮文本标签
    QLabel* m_buttonTextLabel; //按钮文本标题
    QComboBox* m_buttonTextComboBox; //按钮文本组合框
    QLabel* m_baseLabel;
    QComboBox* m_baseComboBox;
    QFrame* m_contentFrame;
    QLabel* m_label1;
    QLabel* m_label2;
    QComboBox* m_comboBox1;
    QLineEdit* m_lineEdit;
    QTextEdit* m_textEdit;
    QPushButton* m_okBtn;
    QPushButton* m_cancelBtn;





private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
