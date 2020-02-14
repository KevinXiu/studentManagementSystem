#include "addstudentwidget.h"
#include "ui_addstudentwidget.h"
#include<QTextCodec>
AddStudentWidget::AddStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudentWidget)
{
    ui->setupUi(this);
}

void AddStudentWidget::on_returnButton_clicked()//返回主菜单按钮
{
    display(0);
}
void AddStudentWidget::on_addButton_clicked()//添加按钮
{
    QString name = ui->nameLineEdit->text();
    int id = ui->idLineEdit->text().toInt();
    double math = ui->mathLineEdit->text().toDouble();
    double english = ui->englishLineEdit->text().toDouble();
    double languageC = ui->cLineEdit->text().toDouble();
    if( ui->nameLineEdit->text()==""||ui->idLineEdit->text()==""|| ui->mathLineEdit->text()==""\
        || ui->englishLineEdit->text()==""|| ui->cLineEdit->text()=="" )
    {
        QMessageBox::warning(nullptr,"警告！","请检查是否都有输入");
        return ;
    }
    QFile file("student.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(!file.isOpen())
    {
        QMessageBox::critical(nullptr,"错误！","写入文件失败！");
        return ;
    }
    QTextStream out(&file);

    out<< name<<" "<< id<<" "<< math<<" "<< english<<" "<< languageC<<endl;
    file.close();
    QMessageBox::about(nullptr,"提示：","添加学生信息成功！");
    ui->nameLineEdit->clear();
    ui->idLineEdit->clear();
    ui->mathLineEdit->clear();
    ui->englishLineEdit->clear();
    ui->cLineEdit->clear();
}
AddStudentWidget::~AddStudentWidget()
{
    delete ui;
}
