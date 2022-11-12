#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QPushButton SimpleMsgBtn;       //简单消息对话框
    QPushButton CustomMsgBtn;       //复杂消息对话框
    QPushButton OpenFileBtn;        //打开文件对话框
    QPushButton SaveFileBtn;        //保存文件对话框
    QPushButton InputDialogBtn;     //输入对话框
    QPushButton ColorDialogBtn;     //颜色对话框
    QPushButton FontDialogBtn;      //字体对话框
    QPushButton ProgressDialogBtn;  //进程对话框
    QPushButton PrintDialogBtn;     //打印对话框

private slots:
    void SimpleMsgBtn_Clicked();
    void CustomMsgBtn_Clicked();
    void OpenFileBtn_Clicked();
    void SaveFileBtn_Clicked();
    void InputDialogBtn_Clicked();
    void ColorDialogBtn_Clicked();
    void FontDialogBtn_Clicked();
    void ProgressDialogBtn_Clicked();
    void PrintDialogBtn_Clicked();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
