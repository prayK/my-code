#include "Widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QDebug>

//任意容器类的组件都可以指定布局管理器，同一个布局管理器中的组件拥有相同的父组件
//设置布局管理器的同时隐式的指定了父子关系
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    initControl();
}

void Widget::initControl()
{
    QVBoxLayout *vLayout = new QVBoxLayout(); //垂直布局管理器
    QHBoxLayout *hLayout = new QHBoxLayout(); //水平布局管理器

    //设置按键
    preBtn.setText("Pre Page");
    preBtn.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); //设置布局方式，水平方向是扩展，垂直方向上是固定高度
    preBtn.setMinimumSize(160, 30);

    nextBtn.setText("Next Page");
    nextBtn.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    nextBtn.setMinimumSize(160, 30);

    //将按键放入到水平布局管理器中
    hLayout->addWidget(&preBtn);  //将按键放入到水平布局管理器中去
    hLayout->addWidget(&nextBtn); //将按键放入到水平布局管理器中去

    connect(&preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));
    connect(&nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));

    //把三个页面加入到栈式布局管理器中
    sLayout.addWidget(get1stPage());
    sLayout.addWidget(get2ndPage());
    sLayout.addWidget(get3rdPage());

    //将栈式布局管理器和水平布局管理器放置到垂直布局管理器中
    vLayout->addLayout(&sLayout); //上半部分是栈式布局管理器
    vLayout->addLayout(hLayout);  //下半部分是水平布局管理器

    setLayout(vLayout);
}

//使用 GridLayout 布局管理器
QWidget *Widget::get1stPage()
{
    QWidget *ret = new QWidget();
    QGridLayout *layout = new QGridLayout();

    fLbl1.setText("This");
    fLbl2.setText("is");
    fLbl3.setText("1st");
    fLbl4.setText("page");

    //将四个标签组件设置到 GridLayout 布局管理器
    layout->addWidget(&fLbl1, 0, 0); //网格布局需要指定每个组件在网格中的坐标
    layout->addWidget(&fLbl2, 0, 1);
    layout->addWidget(&fLbl3, 1, 0);
    layout->addWidget(&fLbl4, 1, 1);

    ret->setLayout(layout); //需要将 GridLayout 指定到返回的 widget 对象中去
    //虽然在定义这四个标签组件时未指定这四个组价的父组件，但是在这里将这四个组件设置到
    //widget时就隐式的指定了父子关系，亦即这四个组件与栈式布局管理器同为QWidget的子组件

    qDebug() << ret; //地址相同

    qDebug() << fLbl1.parent(); //地址相同
    qDebug() << fLbl2.parent();
    qDebug() << fLbl3.parent();
    qDebug() << fLbl4.parent();

    return ret;
}

//使用 FormLayout 布局管理器
QWidget *Widget::get2ndPage()
{
    QWidget *ret = new QWidget();
    QFormLayout *layout = new QFormLayout();

    sLineEdit.setText("This is 2rd page");

    layout->addRow("Hint:", &sLineEdit);

    ret->setLayout(layout);

    return ret;
}

//使用垂直布局管理器
QWidget *Widget::get3rdPage()
{
    QWidget *ret = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    tPushBtn1.setText("This is");
    tPushBtn2.setText("3rd page");

    layout->addWidget(&tPushBtn1);
    layout->addWidget(&tPushBtn2);

    ret->setLayout(layout);

    return ret;
}

void Widget::onPreBtnClicked()
{
    int index = ((sLayout.currentIndex() - 1) + 3) % 3; //减1可能溢出，先加3再取余

    sLayout.setCurrentIndex(index);
}

void Widget::onNextBtnClicked()
{
    int index = (sLayout.currentIndex() + 1) % 3;

    sLayout.setCurrentIndex(index);
}

Widget::~Widget()
{
}
