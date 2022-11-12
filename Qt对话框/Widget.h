#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QPushButton SimpleMsgBtn;       //����Ϣ�Ի���
    QPushButton CustomMsgBtn;       //������Ϣ�Ի���
    QPushButton OpenFileBtn;        //���ļ��Ի���
    QPushButton SaveFileBtn;        //�����ļ��Ի���
    QPushButton InputDialogBtn;     //����Ի���
    QPushButton ColorDialogBtn;     //��ɫ�Ի���
    QPushButton FontDialogBtn;      //����Ի���
    QPushButton ProgressDialogBtn;  //���̶Ի���
    QPushButton PrintDialogBtn;     //��ӡ�Ի���

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
