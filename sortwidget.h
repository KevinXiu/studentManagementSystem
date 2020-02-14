#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include"studentinfo.h"
#include<QButtonGroup>
#include <QWidget>
#include<QMessageBox>
#include<QFile>
#include<QList>
#include<QDebug>
#include<QtAlgorithms>
namespace Ui {
class SortWidget;
}

class SortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SortWidget(QWidget *parent = nullptr);
    ~SortWidget();
    QButtonGroup *sortButtonGroup;


private slots:
   void on_returnButton_clicked();

   void on_sortButton_clicked();

signals:
   void display(int number);
private:
    Ui::SortWidget *ui;
};

#endif // SORTWIDGET_H
