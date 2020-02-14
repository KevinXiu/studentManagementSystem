#ifndef TRAVERSESTUDENTWIDGET_H
#define TRAVERSESTUDENTWIDGET_H

#include <QWidget>
#include"studentinfo.h"
#include<QFile>
#include<QDebug>
#include<QMessageBox>
namespace Ui {
class TraverseStudentWidget;
}

class TraverseStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TraverseStudentWidget(QWidget *parent = nullptr);
    void disStudents();
    ~TraverseStudentWidget();

private slots:
    void on_returnButton_clicked();
signals:
    void display(int number);

private:
    Ui::TraverseStudentWidget *ui;
};

#endif // TRAVERSESTUDENTWIDGET_H
