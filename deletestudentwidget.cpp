#include "deletestudentwidget.h"
#include "ui_deletestudentwidget.h"
QList<StudentInfo>DeleteStudentWidget::stuInfo;
QList<StudentInfo>::iterator DeleteStudentWidget::pos;
DeleteStudentWidget::DeleteStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteStudentWidget)
{
    ui->setupUi(this);
}

DeleteStudentWidget::~DeleteStudentWidget()
{
    delete ui;
}

void DeleteStudentWidget::on_returnButton_clicked()
{
     display(0);
}

void DeleteStudentWidget::on_selButton_clicked()
{
    int id = ui->idLineEdit->text().toInt();
    if(ui->idLineEdit->text()=="")//输入学号为空
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
        stuInfo.push_back(stu);
    }
    file.close();//关闭文件
    if(!stuInfo.empty())
    {
        stuInfo.pop_back();//扔掉无用的数据
    }
   // findId fId(id);
   // pos=qFind(stuInfo.begin(),stuInfo.end(),fId);
    pos=stuInfo.begin();
    while((pos!=stuInfo.end())&&((*pos).getId()!=id))
    {
     pos++;
    }
    QString qStr;
    if(pos!=stuInfo.end())
    {
         qStr ="该学生信息为：\n"\
               "姓名：\t"+(*pos).getName()+"\n"\
               "学号：\t"+QString::number((*pos).getId())+"\n"\
               "数学成绩：\t"+QString::number((*pos).getMath())+"\n"\
               "英语成绩：\t"+QString::number((*pos).getEnglish())+"\n"\
               "C语言成绩：\t"+QString::number((*pos).getLanguageC())+"\n"\
               "总成绩：\t"+QString::number((*pos).getSum())+"\n";
    }
    else
    {

        qStr="未查到学号为" + ui->idLineEdit->text()+"的学生";
    }
    ui->stuTextBrowser->setText(qStr);
}

void DeleteStudentWidget::on_delButton_clicked()
{

   QMessageBox::StandardButton result = QMessageBox::information(nullptr,"提示","是否要删除该学生信息？",QMessageBox::Yes|QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        stuInfo.erase(pos);
    }
    else
    {
        return;
    }
    QFile file("student.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(!file.isOpen())
    {
        QMessageBox::critical(nullptr,"错误！","打开文件失败！");
        return ;
    }
    QTextStream out(&file);
    for(QList<StudentInfo>::iterator it = stuInfo.begin() ; it != stuInfo.end() ; it++)
    {
        out << (*it).getName() << " " << (*it).getId() << " " << (*it).getMath() << " " << (*it).getEnglish() << " " << (*it).getLanguageC() << endl;

    }
    file.close();
    QMessageBox::about(nullptr,"提示：","删除该学生信息成功！");
}
