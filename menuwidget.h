#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include"traversestudentwidget.h"
#include"studentinfo.h"
#include<QFile>
#include<QDebug>
#include<QFont>
#include<QMessageBox>
namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

private slots:
    void on_addButton_clicked();
    void on_selectButton_clicked();
    void on_modifyButton_clicked();
    void on_sortButton_clicked();
    void on_exitButton_clicked();
    void on_traStudentButton_clicked();

    void on_delStudentButton_clicked();

    void on_clearStudentButton_clicked();

signals:
    void display(int number);

private:
    Ui::MenuWidget *ui;


};

#endif // MENUWIDGET_H
