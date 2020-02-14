#include <QApplication>
#include<QTextCodec>
#include<QFont>
#include "mainwidget.h"
int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    //QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
   // QTextCodec::setCodecForCStrings(codec);


    QApplication app(argc, argv);


    //设置字体大小
    QFont font = app.font();
    font.setPixelSize(12);
    app.setFont(font);


    MainWidget w;
    w.setWindowTitle("学生管理系统");
    w.show();

    return app.exec();
}
