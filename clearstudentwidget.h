#ifndef CLEARSTUDENTWIDGET_H
#define CLEARSTUDENTWIDGET_H

#include <QWidget>

namespace Ui {
class ClearStudentWidget;
}

class ClearStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClearStudentWidget(QWidget *parent = nullptr);
    ~ClearStudentWidget();

private:
    Ui::ClearStudentWidget *ui;
};

#endif // CLEARSTUDENTWIDGET_H
