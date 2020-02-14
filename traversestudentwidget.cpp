#include "traversestudentwidget.h"
#include "ui_traversestudentwidget.h"

TraverseStudentWidget::TraverseStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TraverseStudentWidget)
{
    ui->setupUi(this);
   // ui->stuTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   //设置列自动填充
    QHeaderView* headerView = ui->stuTableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格只读
    ui->stuTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    disStudents();

}

TraverseStudentWidget::~TraverseStudentWidget()
{
    delete ui;
}

void TraverseStudentWidget::on_returnButton_clicked()
{
    display(0);
}
void TraverseStudentWidget::disStudents()
{
    QList<StudentInfo>stuInfo;//创建list容器接受数据
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
    ui->stuTableWidget->setRowCount(stuInfo.size());
   int i=0;
   for (QList<StudentInfo>::iterator it = stuInfo.begin();it != stuInfo.end();it++)
        {
            //qDebug()<<(*it).getName()<<endl;
            ui->stuTableWidget->setItem(i, 0, new QTableWidgetItem((*it).getName()));
            ui->stuTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number((*it).getId())));
            ui->stuTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number((*it).getMath())));
            ui->stuTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number((*it).getEnglish())));
            ui->stuTableWidget->setItem(i, 4, new QTableWidgetItem(QString::number((*it).getLanguageC())));
            ui->stuTableWidget->setItem(i, 5, new QTableWidgetItem(QString::number((*it).getSum())));
            i++;

        }
    ui->stuTableWidget->show();
}
