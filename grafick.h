#ifndef GRAFICK_H
#define GRAFICK_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QPoint>
#include "polinom.h"

//class Polinom;

class Grafick : public QWidget
{
    Q_OBJECT
public:
    //explicit Grafick(QWidget *parent = 0);
    explicit Grafick(float a, float b, float scale_of_number, Polinom f, QWidget *parent=0);
private:

    QGraphicsScene scene;
    QGraphicsView * view=new QGraphicsView(&scene);

    const float size_of_g_W=1000;
    const float size_of_g_H=500;
    const float scale_H=50;
    const float scale_W;
    const float number_of_numbers_H=2;
    const float size_of_helping_line=20;
    const float delta_x_for_g;//=0.005f;
    const QPen color_of_helping_line;
    const QPen color_of_g;
    //const float


    //QGraphicsLineItem *[10000];
signals:

public slots:

};

#endif // GRAFICK_H
