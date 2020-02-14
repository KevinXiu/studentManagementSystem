#include "studentinfo.h"

StudentInfo::StudentInfo()
{

}
StudentInfo::StudentInfo(QString name,int id,double math,double english,double languageC)
{
    this->m_name = name;
    this->m_id = id;
    this->m_math = math;
    this->m_english = english;
    this->m_languageC = languageC;
   this->m_sum = (this->m_math+this->m_english+this->m_languageC);
}
void StudentInfo:: setName(QString name)
{
    this->m_name = name;
}
void StudentInfo:: setId(int id)
{
    this->m_id = id;
}
void StudentInfo:: setMath(double math)
{
    this->m_math = math;
     this->m_sum = (this->m_math+this->m_english+this->m_languageC);
}
void StudentInfo:: setEnglish(double english)
{
    this->m_english = english;
     this->m_sum = (this->m_math+this->m_english+this->m_languageC);
}
void StudentInfo:: setLanguageC(double languageC)
{
    this->m_languageC = languageC;
     this->m_sum = (this->m_math+this->m_english+this->m_languageC);
}
QString StudentInfo:: getName()
{
    return this->m_name;
}
int StudentInfo :: getId()
{
    return this->m_id;
}
double StudentInfo:: getMath()
{
    return this->m_math;
}
double StudentInfo:: getEnglish()
{
    return this->m_english;
}
double StudentInfo:: getLanguageC()
{
    return this->m_languageC;
}
double StudentInfo:: getSum()
{
    return this->m_sum;
}
