#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QStackedLayout>
#include"addstudentwidget.h"
#include"menuwidget.h"
#include"modifywidget.h"
#include"selectwiget.h"
#include"sortwidget.h"
#include"traversestudentwidget.h"
#include"deletestudentwidget.h"
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QStackedLayout *m_qstackedlayout;
    MenuWidget *m_menuWidget;
    AddStudentWidget *m_addStudentWidget;
    ModifyWidget *m_modifyWidget;
    SelectWiget *m_selectWidget;
    SortWidget *m_sortWidget;
    TraverseStudentWidget *m_traStudentWidget;
    DeleteStudentWidget *m_delStudentWidget;
    //ClearStudentWidget *m_clSrudentWidget;

};

#endif // MAINWIDGET_H
