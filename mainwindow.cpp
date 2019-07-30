#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <math.h>
#include "var.h"

#define PI 3.14159265

extern double S23, C23, a23, S4, C4, a4, xt, yt, zt, xp, yp, zp,  l1, l2, l3, d, e, l4, l, phi, theta, s1, s5, s2, S1, C1, a1, S5, C5, a5, S3, C3, a3, C234, S234, a234, xr, yr, zr, a, b, S2, C2, a2;
extern double x01, y01, z01, x01_, y01_, z01_, x02, y02, z02, x02_, y02_, z02_, xrs, yrs, zrs, xps, yps, zps, xts, yts, zts;
extern double n,xcel,ycel,zcel,deltax,deltay,deltaz,xt_,yt_,zt_,T;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //wartości domyślne
    xt=400;
    yt=400;
    zt=400;
    l1=100;
    l2=200;
    l3=200;
    d=100;
    e=200;
    l4=200;
    l=200;
    phi=60;
    theta=30;
    s1=-1;
    s5=1;
    s2=1;
    ui->RobPar->setItem(0,0,new QTableWidgetItem(QString::number(xt)));
    ui->RobPar->setItem(1,0,new QTableWidgetItem(QString::number(yt)));
    ui->RobPar->setItem(2,0,new QTableWidgetItem(QString::number(zt)));
    ui->RobPar->setItem(3,0,new QTableWidgetItem(QString::number(l1)));
    ui->RobPar->setItem(4,0,new QTableWidgetItem(QString::number(l2)));
    ui->RobPar->setItem(5,0,new QTableWidgetItem(QString::number(l3)));
    ui->RobPar->setItem(6,0,new QTableWidgetItem(QString::number(l4)));
    ui->RobPar->setItem(7,0,new QTableWidgetItem(QString::number(d)));
    ui->RobPar->setItem(8,0,new QTableWidgetItem(QString::number(e)));
    ui->RobPar->setItem(9,0,new QTableWidgetItem(QString::number(l)));
    ui->RobPar->setItem(10,0,new QTableWidgetItem(QString::number(theta)));
    ui->RobPar->setItem(11,0,new QTableWidgetItem(QString::number(phi)));
    ui->RobPar->setItem(12,0,new QTableWidgetItem(QString::number(s1)));
    ui->RobPar->setItem(13,0,new QTableWidgetItem(QString::number(s2)));
    ui->RobPar->setItem(14,0,new QTableWidgetItem(QString::number(s5)));
    T=50;
    n=100;
    xcel=300;
    ycel=100;
    zcel=200;
    ui->FinishCord->setItem(0,0,new QTableWidgetItem(QString::number(T)));
    ui->FinishCord->setItem(1,0,new QTableWidgetItem(QString::number(n)));
    ui->FinishCord->setItem(2,0,new QTableWidgetItem(QString::number(xcel)));
    ui->FinishCord->setItem(3,0,new QTableWidgetItem(QString::number(ycel)));
    ui->FinishCord->setItem(4,0,new QTableWidgetItem(QString::number(zcel)));

    sceneXY=new QGraphicsScene();
    sceneXZ=new QGraphicsScene();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sceneXY;
    delete sceneXZ;
}

void MainWindow::rysuj()
{


    xznak=1;
    yznak=-1;
    zznak=-1;
    sceneXY->clear();
    sceneXZ->clear();
    ui->graphicsViewXY->setScene(sceneXY);
    ui->graphicsViewXZ->setScene(sceneXZ);
    ui->graphicsViewXY->show();

    penXY.setStyle(Qt::SolidLine);
    penXY.setWidth(3*ui->graphicsViewXY->scaleGlobal);
    penXY.setBrush(Qt::red);
    penXY.setCapStyle(Qt::RoundCap);
    penXY.setJoinStyle(Qt::RoundJoin);

    sceneXY->addLine(0,0,x01*xznak,y01*yznak,penXY);
    sceneXY->addLine(x01*xznak,y01*yznak,x01_*xznak,y01_*yznak,penXY);
    sceneXY->addLine(x01_*xznak,y01_*yznak,x02_*xznak,y02_*yznak,penXY);
    sceneXY->addLine(x02_*xznak,y02_*yznak,x02*xznak,y02*yznak,penXY);
    sceneXY->addLine(x02*xznak,y02*yznak,xrs*xznak,yrs*yznak,penXY);
    sceneXY->addLine(xrs*xznak,yrs*yznak,xps*xznak,yps*yznak,penXY);
    sceneXY->addLine(xps*xznak,yps*yznak,xts*xznak,yts*yznak,penXY);

    penXY.setWidth(3*ui->graphicsViewXY->scaleGlobal);
    penXY.setBrush(Qt::black);

    double correctXY=12/2*ui->graphicsViewXY->scaleGlobal;

    sceneXY->addRect(0-correctXY,0-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    sceneXY->addEllipse(x01*xznak-correctXY,y01*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    sceneXY->addEllipse(x02*xznak-correctXY,y02*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    sceneXY->addEllipse(x01_*xznak-correctXY,y01_*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    sceneXY->addEllipse(x02_*xznak-correctXY,y02_*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    sceneXY->addEllipse(xrs*xznak-correctXY,yrs*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    sceneXY->addEllipse(xps*xznak-correctXY,yps*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::black));
    penXY.setBrush(Qt::green);
    sceneXY->addEllipse(xts*xznak-correctXY,yts*yznak-correctXY,12*ui->graphicsViewXY->scaleGlobal,12*ui->graphicsViewXY->scaleGlobal,penXY,QBrush(Qt::green));

    penXZ.setStyle(Qt::SolidLine);
    penXZ.setWidth(3*ui->graphicsViewXZ->scaleGlobal);
    penXZ.setBrush(Qt::red);
    penXZ.setCapStyle(Qt::RoundCap);
    penXZ.setJoinStyle(Qt::RoundJoin);

    sceneXZ->addLine(0,0,x01*xznak,z01*zznak,penXZ);
    sceneXZ->addLine(x01*xznak,z01*zznak,x01_*xznak,z01_*zznak,penXZ);
    sceneXZ->addLine(x01_*xznak,z01_*zznak,x02_*xznak,z02_*zznak,penXZ);
    sceneXZ->addLine(x02_*xznak,z02_*zznak,x02*xznak,z02*zznak,penXZ);
    sceneXZ->addLine(x02*xznak,z02*zznak,xrs*xznak,zrs*zznak,penXZ);
    sceneXZ->addLine(xrs*xznak,zrs*zznak,xps*xznak,zps*zznak,penXZ);
    sceneXZ->addLine(xps*xznak,zps*zznak,xts*xznak,zts*zznak,penXZ);

    penXZ.setBrush(Qt::black);
    penXZ.setWidth(3*ui->graphicsViewXZ->scaleGlobal);

    double correctXZ=12/2*ui->graphicsViewXZ->scaleGlobal;

    sceneXZ->addRect(0-correctXZ,0-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    sceneXZ->addEllipse(x01*xznak-correctXZ,z01*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    sceneXZ->addEllipse(x02*xznak-correctXZ,z02*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    sceneXZ->addEllipse(x01_*xznak-correctXZ,z01_*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    sceneXZ->addEllipse(x02_*xznak-correctXZ,z02_*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    sceneXZ->addEllipse(xrs*xznak-correctXZ,zrs*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    sceneXZ->addEllipse(xps*xznak-correctXZ,zps*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::black));
    penXZ.setBrush(Qt::green);
    sceneXZ->addEllipse(xts*xznak-correctXZ,zts*zznak-correctXZ,12*ui->graphicsViewXZ->scaleGlobal,12*ui->graphicsViewXZ->scaleGlobal,penXZ,QBrush(Qt::green));

    penXY.setStyle(Qt::DashLine);
    penXY.setBrush(Qt::black);
    penXY.setWidth(2*ui->graphicsViewXY->scaleGlobal);
    sceneXY->addLine(-l1-l2-l3-l4-l,0,l1+l2+l3+l4+l,0,penXY);
    sceneXY->addLine(0,-l1-l2-l3-l4-l,0,l1+l2+l3+l4+l,penXY);
    penXZ.setStyle(Qt::DashLine);
    penXZ.setBrush(Qt::black);
    penXZ.setWidth(2*ui->graphicsViewXZ->scaleGlobal);
    sceneXZ->addLine(-l1-l2-l3-l4-l,0,l1+l2+l3+l4+l,0,penXZ);
    sceneXZ->addLine(0,-l1-l2-l3-l4-l,0,l1+l2+l3+l4+l,penXZ);

//    sceneXY->setBackgroundBrush(QBrush(Qt::gray,Qt::CrossPattern));
//    sceneXZ->setBackgroundBrush(QBrush(Qt::gray,Qt::CrossPattern));

    ui->graphicsViewXY->update();
    ui->graphicsViewXZ->update();

}

void MainWindow::licz()
{
    xznak=1;
    yznak=1;
    zznak=1;
    xp=xt-l*cos(phi*PI/180)*cos(theta*PI/180);
    yp=yt-l*cos(phi*PI/180)*sin(theta*PI/180);
    zp=zt-l*sin(phi*PI/180);
    S1=1/(pow(xp,2)+pow(yp,2))*(e*xp+s1*yp*sqrt(abs(pow(xp,2)+pow(yp,2)-pow(e,2))));
    C1=1/(pow(xp,2)+pow(yp,2))*(-e*yp+s1*xp*sqrt(abs(pow(xp,2)+pow(yp,2)-pow(e,2))));
    if (abs(S1)<1.0)
        a1=asin(S1)*180/PI;
    else{
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;
        return;
    }

    // S5, C5
    S5=cos(phi*PI/180)*(sin(theta*PI/180)*C1-cos(theta*PI/180)*S1);
    C5=s5*sqrt(1-pow(S5,2));
    if (abs(S5)<1.0)
        a5=asin(S5)*180/PI;
    else{
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;
        return;
    }

    // S234, C234

    S234=sin(phi*PI/180)/C5;
    C234=cos(phi*PI/180)/C5*(cos(theta*PI/180)*C1+sin(theta*PI/180)*S1);
    if (abs(S234)<1.0)
        a234=asin(S234)*180/PI;
    else{
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;
        return;
    }
    // xr, yr, zr

    xr=xp-l4*C1*C234;
    yr=yp-l4*S1*C234;
    zr=zp-l4*S234;
    // a,b

    a=-l1+s1*sqrt(abs(pow(xr,2)+pow(yr,2)-pow(e,2)));
    b=1/(2*l2)*(pow(a,2)+pow(zr, 2)+pow(l2,2)-pow(l3,2));
    // S1, C2

    S2=1/(pow(a,2)+pow(zr,2))*(zr*b+s2*a*sqrt(abs(pow(a,2)+pow(zr,2)-pow(b,2))));
    C2=1/(pow(a,2)+pow(zr,2))*(a*b-s2*zr*sqrt(abs(pow(a,2)+pow(zr,2)-pow(b,2))));
    if (abs(S2)<1.0)
        a2=asin(S2)*180/PI;
    else{
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;
        return;
    }
    // S3, C3

    S3=1/l3*(zr*C2-a*S2);
    C3=1/l3*(a*C2+zr*S2-l2);
    if (abs(S3)<1.0)
        a3=asin(S3)*180/PI;
    else{
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;
        return;
    }

    // S23, C23, a23

    S23=1/l3*(zr-l2*S2);
    C23=1/l3*(a-l2*C2);
    if (abs(S23)<1.0)
        a23=asin(S23)*180/PI;
    else{
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;
        return;
    }

    // S4, C4, a4

    S4=S234*C23-C234*S23;
    C4=C234*C23+S234*S23;
    if (abs(S4)<1.0)
        a4=asin(S4)*180/PI;
    else {
        ui->ErrLabel->setText("Nieosiagalna\npozycja");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ErrStatus=true;        //       ShowMessage("Wystapilo nieosiagalne polozenie! Zmien parametry ruchu");
        return;
    }

    // sprawdxajace:

    x01=l1*C1;
    y01=l1*S1;
    z01=0;

    x01_=x01+d*S1;
    y01_=y01-d*C1;
    z01_=0;

    x02_=x01_+l2*C2*C1;
    y02_=y01_+l2*C2*S1;
    z02_=l2*S2;

    x02=x02_-(d-e)*S1;
    y02=y02_+(d-e)*C1;
    z02=z02_;

    xrs=x02+l3*C1*C23;
    yrs=y02+l3*S1*C23;
    zrs=z02+l3*S23;

    xps=xrs+l4*C1*C234;
    yps=yrs+l4*S1*C234;
    zps=zrs+l4*S234;

    xts=xps+l*cos(phi*PI/180)*cos(theta*PI/180);
    yts=yps+l*cos(phi*PI/180)*sin(theta*PI/180);
    zts=zps+l*sin(phi*PI/180);
}

void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(T);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::tabRefresh()
{
    xznak=1;
    yznak=1;
    zznak=1;
    int col=0;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(x01)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(x01_)));
    ui->ValueTab->setItem(2,col,new QTableWidgetItem(QString::number(x02_)));
    ui->ValueTab->setItem(3,col,new QTableWidgetItem(QString::number(x02)));
    ui->ValueTab->setItem(4,col,new QTableWidgetItem(QString::number(xr)));
    ui->ValueTab->setItem(5,col,new QTableWidgetItem(QString::number(xp)));
    ui->ValueTab->setItem(6,col,new QTableWidgetItem(QString::number(xt)));
    col++;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(y01)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(y01_)));
    ui->ValueTab->setItem(2,col,new QTableWidgetItem(QString::number(y02_)));
    ui->ValueTab->setItem(3,col,new QTableWidgetItem(QString::number(y02)));
    ui->ValueTab->setItem(4,col,new QTableWidgetItem(QString::number(yr)));
    ui->ValueTab->setItem(5,col,new QTableWidgetItem(QString::number(yp)));
    ui->ValueTab->setItem(6,col,new QTableWidgetItem(QString::number(yt)));
    col++;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(z01)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(z01_)));
    ui->ValueTab->setItem(2,col,new QTableWidgetItem(QString::number(z02_)));
    ui->ValueTab->setItem(3,col,new QTableWidgetItem(QString::number(z02)));
    ui->ValueTab->setItem(4,col,new QTableWidgetItem(QString::number(zr)));
    ui->ValueTab->setItem(5,col,new QTableWidgetItem(QString::number(zp)));
    ui->ValueTab->setItem(6,col,new QTableWidgetItem(QString::number(zt)));
    col+=2;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(a1)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(a2)));
    ui->ValueTab->setItem(2,col,new QTableWidgetItem(QString::number(a3)));
    ui->ValueTab->setItem(3,col,new QTableWidgetItem(QString::number(a4)));
    ui->ValueTab->setItem(4,col,new QTableWidgetItem(QString::number(a5)));
    ui->ValueTab->setItem(5,col,new QTableWidgetItem(QString::number(a23)));
    ui->ValueTab->setItem(6,col,new QTableWidgetItem(QString::number(a234)));
    col+=2;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(S1)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(S2)));
    ui->ValueTab->setItem(2,col,new QTableWidgetItem(QString::number(S3)));
    ui->ValueTab->setItem(3,col,new QTableWidgetItem(QString::number(S4)));
    ui->ValueTab->setItem(4,col,new QTableWidgetItem(QString::number(S5)));
    ui->ValueTab->setItem(5,col,new QTableWidgetItem(QString::number(S23)));
    ui->ValueTab->setItem(6,col,new QTableWidgetItem(QString::number(S234)));
    col+=2;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(C1)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(C2)));
    ui->ValueTab->setItem(2,col,new QTableWidgetItem(QString::number(C3)));
    ui->ValueTab->setItem(3,col,new QTableWidgetItem(QString::number(C4)));
    ui->ValueTab->setItem(4,col,new QTableWidgetItem(QString::number(C5)));
    ui->ValueTab->setItem(5,col,new QTableWidgetItem(QString::number(C23)));
    ui->ValueTab->setItem(6,col,new QTableWidgetItem(QString::number(C234)));
    col+=2;
    ui->ValueTab->setItem(0,col,new QTableWidgetItem(QString::number(a)));
    ui->ValueTab->setItem(1,col,new QTableWidgetItem(QString::number(b)));
    ui->ValueTab->update();
}

void MainWindow::on_Show_clicked()
{
    if(ErrStatus){
        ui->ErrLabel->setText("Brak\nbłędów");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : green; color : blue; }");
        ErrStatus=false;
    }
    licz();
    rysuj();
    tabRefresh();
}

void MainWindow::on_Move_clicked()
{
    if(ErrStatus){
        ui->ErrLabel->setText("Brak\nbłędów");
        ui->ErrLabel->setStyleSheet("QLabel { background-color : green; color : blue; }");
        ErrStatus=false;
    }
    ui->Move->setEnabled(false);
    ui->RobPar->setEnabled(false);
    ui->FinishCord->setEnabled(false);
    xt_=xt;
    yt_=yt;
    zt_=zt;
    deltax=(xcel-xt)/n;
    deltay=(ycel-yt)/n;
    deltaz=(zcel-zt)/n;
    for(int i=n;i>=0;i--){
        licz();
        if(!ErrStatus){
            rysuj();
            xt+=deltax;
            yt+=deltay;
            zt+=deltaz;
            tabRefresh();
            delay();
        }
    }
    for(int i=n;i>=0;i--){
        if(!ErrStatus){
            delay();
            xt-=deltax;
            yt-=deltay;
            zt-=deltaz;
            licz();
            rysuj();
            tabRefresh();
        }
    }
    xt=xt_;
    yt=yt_;
    zt=zt_;
    ui->Move->setEnabled(true);
    ui->RobPar->setEnabled(true);
    ui->FinishCord->setEnabled(true);
}

void MainWindow::on_RobPar_cellChanged(int row, int column)
{
    QString itemText=ui->RobPar->item(row,column)->text();
    double temp=itemText.toDouble();
    qDebug() << "temp: " << temp;
    switch(row)
    {
    case 0:
        xt=temp;
        break;
    case 1:
        yt=temp;
        break;
    case 2:
        zt=temp;
        break;
    case 3:
        l1=temp;
        break;
    case 4:
        l2=temp;
        break;
    case 5:
        l3=temp;
        break;
    case 6:
        l4=temp;
        break;
    case 7:
        d=temp;
        break;
    case 8:
        e=temp;
        break;
    case 9:
        l=temp;
        break;
    case 10:
        theta=temp;
        break;
    case 11:
        phi=temp;
        break;
    case 12:
        s1=temp;
        break;
    case 13:
        s2=temp;
        break;
    case 14:
        s5=temp;
        break;
    default:
        break;

    }

}

void MainWindow::on_FinishCord_cellChanged(int row, int column)
{
    QString itemText=ui->FinishCord->item(row,column)->text();
    double temp=itemText.toDouble();
    qDebug() << "temp: " << temp;
    switch(row)
    {
    case 0:
        T=temp;
        break;
    case 1:
        n=temp;
        break;
    case 2:
        xcel=temp;
        break;
    case 3:
        ycel=temp;
        break;
    case 4:
        zcel=temp;
        break;
    default:
        break;
    }
}
