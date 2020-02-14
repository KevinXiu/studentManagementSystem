#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QWidget>
#include<QFile>
#include<QMessageBox>
#include<QDebug>
namespace Ui {
class AddStudentWidget;
}

class AddStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentWidget(QWidget *parent = nullptr);
    ~AddStudentWidget();
private slots:
   void on_returnButton_clicked();
   void on_addButton_clicked();

signals:
   void display(int number);
private:
    Ui::AddStudentWidget *ui;
};

#endif // ADDSTUDENTWIDGET_H
