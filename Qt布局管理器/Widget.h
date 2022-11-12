#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QStackedLayout>

//任意容器类的组件都可以指定布局管理器，同一个布局管理器中的组件拥有相同的父组件
//设置布局管理器的同时隐式的指定了父子关系
class Widget : public QWidget
{
    Q_OBJECT

private:
    //两个按键组件
    QPushButton preBtn;
    QPushButton nextBtn;

    //定义好的四个标签组件
    QLabel fLbl1;
    QLabel fLbl2;
    QLabel fLbl3;
    QLabel fLbl4;
    //QLineEdit 组件
    QLineEdit sLineEdit;

    QPushButton tPushBtn1;
    QPushButton tPushBtn2;
    QStackedLayout sLayout;

    void initControl();
    QWidget *get1stPage(); //创建页面1
    QWidget *get2ndPage(); //创建页面2
    QWidget *get3rdPage(); //创建页面3

    //定义两个槽函数
private slots:
    void onPreBtnClicked();
    void onNextBtnClicked();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // _WIDGET_H_
