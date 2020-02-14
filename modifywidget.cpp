#include "modifywidget.h"
#include "ui_modifywidget.h"

QList<StudentInfo> ModifyWidget::stuInfo;
QList<StudentInfo>::iterator ModifyWidget::pos;
ModifyWidget::ModifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyWidget)
{
    ui->setupUi(this);
}


void ModifyWidget::on_returnButton_clicked()
{
    display(0);
}

ModifyWidget::~ModifyWidget()
{
    delete ui;
}

void ModifyWidget::on_modButton_clicked()
{
    if(ui->nameLineEdit->text()!="")
    {
        (*pos).setName(ui->nameLineEdit->text());
    }
    if(ui->idLineEdit->text()!="")
    {
        (*pos).setId(ui->idLineEdit->text().toInt());

    }
    if(ui->mathLineEdit->text()!="")
    {
        (*pos).setMath(ui->mathLineEdit->text().toDouble());
    }
    if(ui->enLineEdit->text()!="")
    {
        (*pos).setMath(ui->enLineEdit->text().toDouble());
    }
    if(ui->cLineEdit->text()!="")
    {
        (*pos).setMath(ui->cLineEdit->text().toDouble());
    }
    QFile file("student.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(!file.isOpen())
    {
        QMessageBox::warning(nullptr,"错误！","写入文件失败！");
        return;
    }
    QTextStream out(&file);
    for(QList<StudentInfo>::iterator it = stuInfo.begin();it != stuInfo.end();it++)
    {
        out << (*it).getName() << " " << (*it).getId() << " " << (*it).getMath() << " " << (*it).getEnglish() << " " << (*it).getLanguageC() << endl;
    }
    file.close();
    QMessageBox::about(nullptr,"提示：","学生信息修改成功");
}
void ModifyWidget::on_selectButton_clicked()
{
    int id = ui->s_idLineEdit->text().toInt();
    if(ui->s_idLineEdit->text()=="")//输入学号为空
    {
       QMessageBox::warning(nullptr,"警告！","未输入学号");
       return ;
    }
    QFile file("student.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);//以只读的形式打开student.txt文件
    if(!file.isOpen())
    {
        //打开文件失败
        QMessageBox::critical(nullptr,"错误！","打开文件失败");
        return ;
    }
    //读取数据
    QTextStream inp (&file);
    while(!inp.atEnd())
    {
        QString name;
        int id;
        double math,english,languageC;
        inp>>name>>id>>math>>english>>languageC;
        StudentInfo stu(name,id,math,english,languageC);
        ModifyWidget::stuInfo.push_back(stu);
    }
    file.close();//关闭文件
    if(!stuInfo.empty())
    {
        stuInfo.pop_back();//扔掉无用的数据
    }
   // findId fId(id);
   // pos=qFind(stuInfo.begin(),stuInfo.end(),fId);
   ModifyWidget:: pos=ModifyWidget::stuInfo.begin();
    while((ModifyWidget::pos!=ModifyWidget::stuInfo.end())&&((*ModifyWidget::pos).getId()!=id))
    {
     ModifyWidget::pos++;
    }
    QString qStr;
    if(ModifyWidget::pos!=ModifyWidget::stuInfo.end())
    {
         qStr ="该学生信息为：\n"\
               "姓名：\t"+(*ModifyWidget::pos).getName()+"\n"\
               "学号：\t"+QString::number((*ModifyWidget::pos).getId())+"\n"\
               "数学成绩：\t"+QString::number((*ModifyWidget::pos).getMath())+"\n"\
               "英语成绩：\t"+QString::number((*ModifyWidget::pos).getEnglish())+"\n"\
               "C语言成绩：\t"+QString::number((*ModifyWidget::pos).getLanguageC())+"\n"\
               "总成绩：\t"+QString::number((*ModifyWidget::pos).getSum())+"\n";
    }
    else
    {

        qStr="未查到学号为" + ui->idLineEdit->text()+"的学生";
    }
    ui->pastStuTextBrowser->setText(qStr);
}
