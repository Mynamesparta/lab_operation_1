#include <QApplication>
#include <QVector>
#include <QDebug>
#include "polinom.h"
#include "grafick.h"
#include "table_of_result.h"
#include <math.h>

const float A=-2,B=7,N=12;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector<float> input;
    input<<1<<2.5<<3.14<<5;

    Polinom f;
    for(int i=0;i<input.length();i++)
    {
        f=f*input[i];
    }
    qDebug()<<f.toString();

    Grafick window(A,B,N,f);
    return a.exec();
}
