#ifndef SELECTWIGET_H
#define SELECTWIGET_H
#include"studentinfo.h"
#include <QWidget>
#include<QMessageBox>
#include<QFile>
#include<QList>
#include<QDebug>
#include<QtAlgorithms>
namespace Ui {
class SelectWiget;
}

class SelectWiget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectWiget(QWidget *parent = nullptr);
    ~SelectWiget();

private slots:
   void on_returnButton_clicked();
   void on_selectButton_clicked();

signals:
   void display(int number);

private:
    Ui::SelectWiget *ui;
};

#endif // SELECTWIGET_H
