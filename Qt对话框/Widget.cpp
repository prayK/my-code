#include "Widget.h"
#include <QDebug>

#include <QMessageBox> //消息(简单&复杂)对话框
#include <QFileDialog> //文件(打开&关闭)文件对话框

#include <QInputDialog> //输入对话框
#include <QColorDialog> //颜色对话框

#include <QFontDialog>     //字体对话框
#include <QProgressDialog> //进程对话框

#include <QPrinter>      //打印对话框
#include <QPrintDialog>  //打印对话框
#include <QTextDocument> //输入文本对话框

Widget::Widget(QWidget *parent) : QWidget(parent), SimpleMsgBtn(this), CustomMsgBtn(this), OpenFileBtn(this),
                                  SaveFileBtn(this), InputDialogBtn(this), ColorDialogBtn(this),
                                  FontDialogBtn(this), ProgressDialogBtn(this), PrintDialogBtn(this)
{
    SimpleMsgBtn.setText("SimpleMsgBtn");
    SimpleMsgBtn.move(20, 20);
    SimpleMsgBtn.resize(160, 30);

    CustomMsgBtn.setText("CustomMsgBtn");
    CustomMsgBtn.move(20, 70);
    CustomMsgBtn.resize(160, 30);

    OpenFileBtn.setText("OpenFileBtn");
    OpenFileBtn.move(20, 120);
    OpenFileBtn.resize(160, 30);

    SaveFileBtn.setText("SaveFileBtn");
    SaveFileBtn.move(20, 170);
    SaveFileBtn.resize(160, 30);

    InputDialogBtn.setText("InputDialogBtn");
    InputDialogBtn.move(20, 220);
    InputDialogBtn.resize(160, 30);

    ColorDialogBtn.setText("ColorDialogBtn");
    ColorDialogBtn.move(20, 270);
    ColorDialogBtn.resize(160, 30);

    FontDialogBtn.setText("FontDialogBtn");
    FontDialogBtn.move(20, 320);
    FontDialogBtn.resize(160, 30);

    ProgressDialogBtn.setText("ProgressDialogBtn");
    ProgressDialogBtn.move(20, 370);
    ProgressDialogBtn.resize(160, 30);

    PrintDialogBtn.setText("PrintDialogBtn");
    PrintDialogBtn.move(20, 420);
    PrintDialogBtn.resize(160, 30);

    resize(400, 470);
    setFixedSize(400, 470);

    connect(&SimpleMsgBtn, SIGNAL(clicked()), this, SLOT(SimpleMsgBtn_Clicked()));
    connect(&CustomMsgBtn, SIGNAL(clicked()), this, SLOT(CustomMsgBtn_Clicked()));
    connect(&OpenFileBtn, SIGNAL(clicked()), this, SLOT(OpenFileBtn_Clicked()));
    connect(&SaveFileBtn, SIGNAL(clicked()), this, SLOT(SaveFileBtn_Clicked()));
    connect(&InputDialogBtn, SIGNAL(clicked()), this, SLOT(InputDialogBtn_Clicked()));
    connect(&ColorDialogBtn, SIGNAL(clicked()), this, SLOT(ColorDialogBtn_Clicked()));
    connect(&FontDialogBtn, SIGNAL(clicked()), this, SLOT(FontDialogBtn_Clicked()));
    connect(&ProgressDialogBtn, SIGNAL(clicked()), this, SLOT(ProgressDialogBtn_Clicked()));
    connect(&PrintDialogBtn, SIGNAL(clicked()), this, SLOT(PrintDialogBtn_Clicked()));
}

void Widget::SimpleMsgBtn_Clicked()
{
    QMessageBox dlg(this);
    dlg.setWindowTitle("Message Dialog");
    dlg.setText("Message Dialog");
    dlg.exec();
}

void Widget::CustomMsgBtn_Clicked()
{
    QMessageBox dlg(this);
    dlg.setWindowTitle("CustomMessage Dialog");
    dlg.setText("CustomMessage Dialog");
    dlg.setIcon(QMessageBox::Information); //设置ICON
    dlg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    dlg.exec();
}

void Widget::OpenFileBtn_Clicked()
{
    QFileDialog dlg(this);
    dlg.setWindowTitle("OpenFile Dialog");
    dlg.setAcceptMode(QFileDialog::AcceptOpen);
    dlg.setFilter("Test(*.txt)");
    dlg.setFileMode(QFileDialog::ExistingFiles);
    if (dlg.exec() == QFileDialog::Accepted)
    {
        QStringList fs = dlg.selectedFiles();

        for (int i = 0; i < fs.count(); ++i)
        {
            qDebug() << fs[i];
        }
    }
}

void Widget::SaveFileBtn_Clicked()
{
    QFileDialog dlg(this);
    dlg.setWindowTitle("SaveFile Dialog");
    dlg.setAcceptMode(QFileDialog::AcceptSave);
    dlg.setFilter("Test(*.txt)");

    if (dlg.exec() == QFileDialog::Accepted)
    {
        QStringList fs = dlg.selectedFiles();

        for (int i = 0; i < fs.count(); ++i)
        {
            qDebug() << fs[i];
        }
    }
}

void Widget::InputDialogBtn_Clicked()
{
    QInputDialog dlg(this);
    dlg.setWindowTitle("Input Dialog");
    dlg.setLabelText("please input string");
    dlg.setInputMode(QInputDialog::TextInput);
    dlg.setIntMinimum(0);
    dlg.setIntMaximum(255);

    if (dlg.exec() == QInputDialog::Accepted)
    {
        qDebug() << dlg.textValue();
    }
}

void Widget::ColorDialogBtn_Clicked()
{
    QColorDialog dlg(this);
    dlg.setWindowTitle("Color Editor");
    dlg.setCurrentColor(QColor(100, 111, 222));

    if (dlg.exec() == QColorDialog::Accepted)
    {
        QColor color = dlg.selectedColor();

        qDebug() << color;
        qDebug() << color.red();
        qDebug() << color.green();
        qDebug() << color.blue();
        qDebug() << color.hue();
        qDebug() << color.saturation();
        qDebug() << color.value();
    }
}

void Widget::FontDialogBtn_Clicked() //字体对话框
{
    QFontDialog dlg(this);

    dlg.setWindowTitle("Font Dialog Test");
    dlg.setCurrentFont(QFont("Courier New", 10, QFont::Bold));

    if (dlg.exec() == QFontDialog::Accepted) //模态显示，点击ok后显示所选择的颜色
    {
        qDebug() << dlg.selectedFont();
    }
}

void Widget::ProgressDialogBtn_Clicked() //进度对话框
{
    QProgressDialog dlg(this);

    dlg.setWindowTitle("Updating...");
    dlg.setLabelText("Downloading update from server...");
    dlg.setMinimum(0);
    dlg.setMaximum(100);
    dlg.setValue(35);

    // create a new thread(从服务器上面真正的下载东西)

    dlg.exec();
}

void Widget::PrintDialogBtn_Clicked() //打印对话框
{
    QPrintDialog dlg(this);

    dlg.setWindowTitle("Print Dialog Test");

    if (dlg.exec() == QPrintDialog::Accepted)
    {
        //QPrinter是打印设备及其参数的封装，封装了系统中打印设备的驱动接口，以相同的方式使用系统中不同的打印设备
        QPrinter *p = dlg.printer();
        QTextDocument td; //打印文档

        //td.setPlainText("Printer object test!");//文本文档中的内容
        td.setHtml("<h1>Print html object test</hl>"); //打印html

        p->setOutputFileName("D:\\test.xps"); //打印到什么地方

        td.print(p); //打印
    }
}

Widget::~Widget()
{
}
