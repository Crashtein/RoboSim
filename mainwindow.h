#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *sceneXY;
    QGraphicsScene *sceneXZ;
    QPen penXY;
    QPen penXZ;
    bool ErrStatus=false;
    double xznak;
    double yznak=-1;
    double zznak=-1;


private slots:

    void on_Show_clicked();
    void on_Move_clicked();
    void rysuj();
    void licz();
    void delay();
    void tabRefresh();
    void on_RobPar_cellChanged(int row, int column);
    void on_FinishCord_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
