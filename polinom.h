#ifndef POLINOM_H
#define POLINOM_H

#include <QVector>
#include <QString>
#include <QDebug>

class Polinom
{
public:
    Polinom();
    Polinom(float sqrt);
    QString toString();
    void reSize(int size);
    bool isNull();

    //Polinom operator*(Polinom& B);
    Polinom operator*(Polinom B);
    Polinom operator*(float B);
    //Polinom operator*=(Polinom& B);
    //Polinom operator*=(Polinom B);
    Polinom operator=(Polinom& B);
    Polinom operator=(Polinom B);
    float operator()(float x);
private:
    inline QString normalized(QString);
    inline QString normalized(float);
    QVector<float> number;

};

#endif // POLINOM_H
