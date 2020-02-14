#ifndef DELETESTUDENTWIDGET_H
#define DELETESTUDENTWIDGET_H

#include"studentinfo.h"

#include <QWidget>
#include<QMessageBox>
#include<QFile>
#include<QList>
#include<QDebug>
#include<QtAlgorithms>

namespace Ui {
class DeleteStudentWidget;
}

class DeleteStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteStudentWidget(QWidget *parent = nullptr);
    ~DeleteStudentWidget();
    static QList<StudentInfo>stuInfo;//创建list容器接收数据
    static QList<StudentInfo>::iterator pos;

private slots:
    void on_returnButton_clicked();
    void on_selButton_clicked();

    void on_delButton_clicked();

signals:
    void display(int number);

private:
    Ui::DeleteStudentWidget *ui;
};

#endif // DELETESTUDENTWIDGET_H
