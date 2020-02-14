#include "sortwidget.h"
#include "ui_sortwidget.h"

SortWidget::SortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortWidget)
{
    ui->setupUi(this);

    //设置列自动填充
    ui->stuTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格内容只读
     ui->stuTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     sortButtonGroup = new QButtonGroup();
     sortButtonGroup->addButton(ui->mathRadioButton,0);
     sortButtonGroup->addButton(ui->enRadioButton,1);
     sortButtonGroup->addButton(ui->cRadioButton,2);
     sortButtonGroup->addButton(ui->sumRadioButton,3);

     ui->sumRadioButton->setChecked(true);//默认选中总成绩

}
void SortWidget::on_returnButton_clicked()
{
    display(0);
}

SortWidget::~SortWidget()
{
    delete ui;
}
//按数学成绩排序
bool mathCom(StudentInfo stu1,StudentInfo stu2)
{
    return  stu1.getMath()>stu2.getMath();
}

//按英语成绩排序
bool englishCom(StudentInfo stu1,StudentInfo stu2)
{
    return  stu1.getEnglish()>stu2.getEnglish();
}

//按C语言成绩排序
bool cCom(StudentInfo stu1,StudentInfo stu2)
{
    return  stu1.getLanguageC()>stu2.getLanguageC();
}

//按总成绩排序
bool sumCom(StudentInfo stu1,StudentInfo stu2)
{
    return  stu1.getSum()>stu2.getSum();
}



void SortWidget::on_sortButton_clicked()
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
    int sortTag = sortButtonGroup->checkedId();
    switch (sortTag)
    {
    case 0:
    {
        qSort(stuInfo.begin(),stuInfo.end(),mathCom);
        break;
    }
    case 1:
    {
        qSort(stuInfo.begin(),stuInfo.end(),englishCom);
        break;
    }
    case 2:
    {
        qSort(stuInfo.begin(),stuInfo.end(),cCom);
        break;
    }
    case 3:
    {
        qSort(stuInfo.begin(),stuInfo.end(),sumCom);
        break;
    }

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
