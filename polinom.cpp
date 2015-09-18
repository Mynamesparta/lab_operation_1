#include "polinom.h"
Polinom::Polinom()
{
    //number=new QVector<float>();
    number<<0;
}
Polinom::Polinom(float sqrt)
{
    //number=new QVector<float>();
    number<<-sqrt<<1;
}
QString Polinom::toString()

{
    if(number.length()==0)
    {
        return "0";
    }
    QString result=QString::number(number[0]);
    for(int i=1;i<number.length();i++)
    {
        result+="+ "+normalized(QString::number(number[i]))+" x"+normalized("^ "+QString::number(i));
    }

    return result;
}
bool Polinom::isNull()
{
    return number.length()==0||(number.length()==1&&number[0]==0);
}

void Polinom::reSize(int size)
{
    number.clear();
    number.resize(size);
    //qDebug()<<number.length()<<"=="<<size;
    for(int i=0;i<number.length();i++)
    {
        number[i]=0;
    }
}

inline QString Polinom::normalized(QString num)
{
    return (num=="1"||num=="^1")?"":num;
}

/*/
Polinom Polinom::operator*(Polinom& B)
{
    if(this->isNull())
        return B;
    if(B.isNull())
        return *this;
    Polinom C;
    C.reSize(this->number.length()+B.number.length()-1);
    int i,j;
    for(i=0;i<this->number.length();i++)
    {
        if(this->number[i]==0)
        {
            continue;
        }
        for(j=0;j<B.number.length();j++)
        {
            C.number[i+j]+=this->number[i]*B.number[j];
        }
    }
    qDebug()<<C.toString();
    return C;
}
/*/
Polinom Polinom::operator*(float b)
{
    Polinom B(b);
    return (*this)*B;
}

Polinom Polinom::operator*(Polinom B)
{
    if(this->isNull())
        return B;
    if(B.isNull())
        return *this;
    Polinom C;
    C.reSize(this->number.length()+B.number.length()-1);
    int i,j;
    for(i=0;i<this->number.length();i++)
    {
        if(this->number[i]==0)
        {
            continue;
        }
        for(j=0;j<B.number.length();j++)
        {
            C.number[i+j]+=this->number[i]*B.number[j];
        }
    }
    //qDebug()<<C.toString();
    return C;
}
/*/
Polinom Polinom::operator*=(Polinom& B)
{
    (*this)=(*this)*B;
    return *this;
}
Polinom Polinom::operator*=(Polinom B)
{
    *this=*this*B;
    return *this;
}
/*/
Polinom Polinom::operator=(Polinom& B)
{
    if(this->number==B.number)
        return *this;
    this->number=B.number;
}
Polinom Polinom::operator=(Polinom B)
{
    if(this->number==B.number)
        return *this;
    this->number=B.number;
    return *this;
}

float Polinom::operator ()(float x)
{
    //qDebug()<<x;
    if(isNull())
        return 0;
    float result=0;
    float x_qrt=1;
    for(int i=0;i<number.length();i++)
    {
        result+=number[i]*x_qrt;
        x_qrt*=x;
    }
    return result;
}

