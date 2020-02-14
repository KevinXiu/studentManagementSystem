#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include <QWidget>
class StudentInfo
{
public:
    StudentInfo();
    //有参构造
    StudentInfo(QString name,int id,double math,double english,double languageC);
    void setName(QString name);
    void setId(int id);
    void setMath(double math);
    void setEnglish(double english);
    void setLanguageC(double languageC);
    QString getName();
    int getId();
    double getMath();
    double getEnglish();
    double getLanguageC();
    double getSum();
private:
    QString m_name;
    int m_id;
    double m_math;
    double m_english;
    double m_languageC;
    double m_sum;
};

#endif // STUDENTINFO_H
