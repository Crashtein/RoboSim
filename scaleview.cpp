#include "scaleview.h"

scaleView::scaleView(QWidget *parent) : QGraphicsView(parent)
{

}

void scaleView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor=1.1;


    if(event->delta() > 0)
    {
        scaleGlobal*=1/scaleFactor;
        scale(scaleFactor,scaleFactor);
    }else {
        scaleGlobal*=scaleFactor;
        scale(1/scaleFactor,1/scaleFactor);
    }
    //MainWindow.rysuj();
}


