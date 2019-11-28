#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "commandes_achats.h"
#include <QMessageBox>
#include <QString>
#include <QMessageBox>
#include <QtDebug>
#include <QSqlRecord>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabfournisseur->setModel(tmpfournisseur.afficher());
ui->tabcmd->setModel(tmpcmd.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked(){

    int codefournisseur = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString email= ui->lineEdit_email->text();
    int fax= ui->lineEdit_fax->text().toInt();
    int teleph= ui->lineEdit_teleph->text().toInt();
  Fournisseur f(codefournisseur,nom,adresse,email,fax,teleph);
  bool test=f.ajouter();
  if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Fournisseur"),
                  QObject::tr("Fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpfournisseur.supprimer(id);
if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Fournisseur"),
                QObject::tr("Fournisseur supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un Fournisseur"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int qs = ui->lineEdit_id_3->text().toInt();
    QSqlQuery query;
    query.prepare("select * from fournisseur where codefournisseur = :id ;");
    query.bindValue(":id", qs);
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    QSqlRecord sr = model->record(0);
    ui->lineEdit->setText(sr.value(1).toString());
    ui->lineEdit_2->setText(sr.value(2).toString());
    ui->lineEdit_3->setText(sr.value(3).toString());
    ui->lineEdit_4->setText(sr.value(4).toString());
    ui->lineEdit_5->setText(sr.value(5).toString());
}

void MainWindow::on_pushButton_clicked()
{
    int code = ui->lineEdit_id_3->text().toInt();
    QString nom = ui->lineEdit->text();
    QString adress = ui->lineEdit_2->text();
    int tel = ui->lineEdit_3->text().toInt();
    int fax = ui->lineEdit_4->text().toInt();
    QString email = ui->lineEdit_5->text();
    Fournisseur *f = new Fournisseur(code, nom, adress, email, tel, fax);
    f->modifier();
    delete f;
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("select * from fournisseur");
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tabfournisseur->setModel(model);
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    QString s = ui->lineEdit_id_4->text();
    QSqlQuery query;
    query.prepare("select * from fournisseur where codefournisseur = :id ;");
    query.bindValue(":id", s.toInt());
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    QSqlRecord sr = model->record(0);
    if(sr.isEmpty() == true){
        QMessageBox::critical(nullptr, QObject::tr("warning"),
                    QObject::tr("fournisseur not found 404.\n"), QMessageBox::Cancel);
    }else{
        ui->tableView_2->setModel(model);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
   QString ref_cmd =ui->lineEdit_6->text();
   QString date_cmd= ui->lineEdit_7->text();
   int codefournisseur=ui->lineEdit_8->text().toInt();
   QString idproduit=ui->lineEdit_9->text();

   commandes_achats ca(ref_cmd,date_cmd,codefournisseur,idproduit);
   bool test=ca.ajouter();
   if(test)
   {
       ui->tabcmd->setModel(tmpcmd.afficher());
       QMessageBox ::information(nullptr,QObject::tr("Ajouter une commande"),
                                 QObject::tr("Commande ajouté.\n"
                                             "click cancel to exit"),QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit_10->text();
    bool test=tmpcmd.supprimer(id);
    if(test)
    {ui->tabcmd->setModel(tmpcmd.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_pushButton_6_clicked()
{
    commandes_achats ca(ui->lineEdit_11->text(),
                        ui->lineEdit_12->text(),
                        ui->lineEdit_13->text().toInt(),
                        ui->lineEdit_14->text());
ca.modifier();
}



void MainWindow::on_pushButton_7_clicked()
{
    QString qs = ui->lineEdit_15->text();
        QSqlQuery query;
        query.prepare("select * from CMDACHAT where REFCMDA = :id ;");
        query.bindValue(":id", qs);
        query.exec();
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery q;
    QString ss =ui->lineEdit_11->text();
    q.prepare("select * from cmdachat where refcmda = :id");
    q.bindValue(":id", ss);
    q.exec();
   QSqlQueryModel * m = new QSqlQueryModel();
   m->setQuery(q);
   QSqlRecord rec;
   rec = m->record(0);
   if(rec.isEmpty() == false){
   ui->lineEdit_12->setText(rec.value(1).toString());
   ui->lineEdit_13->setText(rec.value(2).toString());
   ui->lineEdit_14->setText(rec.value(3).toString());
   }else{
       std::cout << "efjkf" << std::endl;
   }

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabcmd->setModel(tmpcmd.afficher());
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->tableView_3->setModel(tmpcmd.sort());
}
