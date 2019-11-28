#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include "categorie.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
namespace Ui {

class MainWindow;
}
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    produit tmpproduit;
    categorie tmpcat;
    QSystemTrayIcon * mysystem;


};

#endif // MAINWINDOW_H

