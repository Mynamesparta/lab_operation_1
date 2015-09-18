#include "grafick.h"
/*/
Grafick::Grafick(QWidget *parent) :
    QWidget(parent),scale_W(0),
{
    view->QAbstractScrollArea::setViewport(this);
    view->QGraphicsView::centerOn(500,500);
    scene.addLine(-size_of_g_W/2,0,size_of_g_W/2,0,QPen(Qt::black,2));
    scene.addLine(0,-size_of_g_H/2,0,size_of_g_H/2,QPen(Qt::black,2));
    view->setMinimumSize(size_of_g_W+10,size_of_g_H+10);
    view->setMaximumSize(size_of_g_W+10,size_of_g_H+10);
    view->show();
}
/*/
Grafick::Grafick(float a, float b, float scale_of_number, Polinom f, QWidget *parent):
    QWidget(parent),scale_W(size_of_g_W/(b-a)),
    color_of_helping_line(Qt::gray,1),color_of_g(Qt::red,2),
    delta_x_for_g((b-a)*0.005f)
{
    scale_of_number=size_of_g_W/(scale_of_number-1);

    view->QAbstractScrollArea::setViewport(this);
    view->QGraphicsView::centerOn(-a*scale_W,500);
    //view->scale(1,-1);

    scene.addLine(+a*scale_W,0,+a*scale_W+size_of_g_W,0,QPen(Qt::black,2));

    for(int i=0;i<10;i++)
    {
        //scene.addText(QString::number(i))->setPos(i*10,0);
    }


    if(a>=0||b<=0)
    {
        scene.addLine(a*scale_W,-size_of_g_H/2-20,a*scale_W,size_of_g_H/2+20,QPen(Qt::black,2));

        float delta=size_of_g_H/(number_of_numbers_H-1);
        float c=-size_of_g_H/2,d=-c;
        for(float i=c;i<=d;i+=delta)
        {
            scene.addText(QString::number((i/scale_H)))->setPos(a*scale_W,-i);
            scene.addLine(a*scale_W-size_of_helping_line,-i,a*scale_W+size_of_helping_line,-i,color_of_helping_line);
        }

        delta=scale_of_number;
        c=0,d=size_of_g_W;
        //scene.addText(QString::number(a))->setPos(a*scale_W,0);

    }
    else
    {
        scene.addLine(0,-size_of_g_H/2,0,size_of_g_H/2,QPen(Qt::black,2));

        float delta=size_of_g_H/(number_of_numbers_H-1);
        float c=-size_of_g_H/2,d=-c;
        for(float i=c;i<=d;i+=delta)
        {
            scene.addText(QString::number((i/scale_H)))->setPos(0,-i);
            scene.addLine(-size_of_helping_line,-i,size_of_helping_line,-i,color_of_helping_line);
        }
        //scene.addText(QString::number(0))->setPos(0,0);
    }
    for(float i=0;i<=size_of_g_W;i+=scale_of_number)
    {
        scene.addText(QString::number(a+i/scale_W))->setPos(a*scale_W+i,0);
        scene.addLine(a*scale_W+i,-size_of_helping_line,a*scale_W+i,size_of_helping_line,color_of_helping_line);
    }
    QPoint last_point(a*scale_W,-f(a)*scale_H),current_point;
    for(float x=a+delta_x_for_g;x<=b;x+=delta_x_for_g)
    {
        current_point.setX(x*scale_W);
        current_point.setY(-f(x)*scale_H);
        scene.addLine(QLine(last_point,current_point),color_of_g);
        last_point=current_point;
    }


    view->setMinimumSize(size_of_g_W+40,size_of_g_H+50);
    view->setMaximumSize(size_of_g_W+40,size_of_g_H+50);
    view->show();

}
