#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include"studentinfo.h"

#include <QWidget>
#include<QMessageBox>
#include<QFile>
#include<QList>
#include<QDebug>
#include<QtAlgorithms>


namespace Ui {
class ModifyWidget;
}

class ModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = nullptr);
    ~ModifyWidget();
    static QList<StudentInfo>stuInfo;//创建list容器接收数据
    static QList<StudentInfo>::iterator pos;
    static int a;
private slots:
   void on_returnButton_clicked();

   void on_modButton_clicked();

   void on_selectButton_clicked();

signals:
   void display(int number);

private:
    Ui::ModifyWidget *ui;
};
#endif // MODIFYWIDGET_H
