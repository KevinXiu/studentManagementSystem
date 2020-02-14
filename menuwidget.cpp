#include "menuwidget.h"
#include "ui_menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);

}
void MenuWidget::on_traStudentButton_clicked()
{
    emit display(1);
}
void MenuWidget::on_addButton_clicked()
{
    emit display(2);
}
void MenuWidget::on_selectButton_clicked()
{
    emit display(3);
}

void MenuWidget::on_modifyButton_clicked()
{
    emit display(4);
}
void MenuWidget::on_delStudentButton_clicked()
{
    emit display(5);
}
void MenuWidget::on_sortButton_clicked()
{
    emit display(6);
}
void MenuWidget::on_clearStudentButton_clicked()
{
   // emit display(6);
   QMessageBox::StandardButtons result =  QMessageBox::information(nullptr,"警告：","该操作会清空学生信息，是否清空",QMessageBox::Yes|QMessageBox::No);
    if(result == QMessageBox::No)
    {
        return ;
    }
    QFile file("student.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(!file.isOpen())
    {
        QMessageBox::critical(nullptr,"错误！","清空学生信息失败");
        return;
    }
    file.close();
    QMessageBox::about(nullptr,"提示：","清空学生信息成功！");
}

void MenuWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
MenuWidget::~MenuWidget()
{
    delete ui;
}

