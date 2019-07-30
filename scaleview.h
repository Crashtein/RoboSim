#ifndef SCALEVIEW_H
#define SCALEVIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>
#include "mainwindow.h"


class scaleView : public QGraphicsView
{
public:
    scaleView(QWidget* parent = 0);
    double scaleGlobal=1;
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // SCALEVIEW_H
