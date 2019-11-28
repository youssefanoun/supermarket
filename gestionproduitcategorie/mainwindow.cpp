#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "produit.h"
#include "categorie.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabproduit->setModel(tmpproduit.afficher());
ui->tabcat->setModel(tmpcat.afficher());
mysystem= new QSystemTrayIcon(this);
mysystem->setIcon(QIcon(":/icon.png"));
mysystem->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    int prix= ui->lineEdit_3->text().toInt();
    QString categorie= ui->lineEdit_4->text();
    int cyclevie= ui->lineEdit_5->text().toInt();
    int code= ui->lineEdit_6->text().toInt();
  produit e(id,nom,prix,categorie,cyclevie,code);
  bool test=e.ajouter();
  if(test)
{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
      mysystem->showMessage(tr("Gestion Produits"),tr("Ajout d'un produit avec succes"));

      /*QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pushButton_10_clicked()
{
    int idcat=ui->lineEdit_40->text().toInt();
    QString nomcat= ui->lineEdit_41->text();
    categorie c(idcat,nomcat);
    bool test=c.ajouter();
    if(test)
  {ui->tabcat->setModel(tmpcat.afficher());//refresh
        mysystem->showMessage(tr("Gestion Categories"),tr("Ajout d'une categorie avec succes"));
  /*QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                    QObject::tr("Categorie ajoutée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_pushButton_12_clicked()
{
int idcat = ui->lineEdit_52->text().toInt();
bool test=tmpcat.supprimer(idcat);
if(test)
{ui->tabcat->setModel(tmpcat.afficher());//refresh
     mysystem->showMessage(tr("Gestion Categories"),tr("Supression effectuée"));
    /*QMessageBox::information(nullptr, QObject::tr("Supprimer une Categorie"),
                QObject::tr("Categorie supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);*/

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une Categorie"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_7->text().toInt();
        bool test=tmpproduit.supprimer(id);
        if(test)
        {ui->tabproduit->setModel(tmpproduit.afficher());//refresh
            mysystem->showMessage(tr("Gestion Produits"),tr("Supression effectuée"));

            /*QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                        QObject::tr("Produit supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);*/

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_17->text().toInt();

        QString nom= ui->lineEdit_20->text();

        int prix = ui->lineEdit_15->text().toInt();

        QString categorie= ui->lineEdit_19->text();

         int cyclevie= ui->lineEdit_16->text().toInt();

         int code= ui->lineEdit_18->text().toInt();

         bool test = tmpproduit.modifier(id,nom,prix,categorie,cyclevie,code);

                  if (test)

                  {

                       ui->tabproduit->setModel(tmpproduit.afficher());



                      QMessageBox::information(nullptr, QObject::tr("Modification avec sucées !"),

                                  QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

                  }

                  else

                      QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),

                                  QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_11_clicked()
{
    int idcat = ui->lineEdit_48->text().toInt();

        QString nomcat= ui->lineEdit_51->text();
        bool test = tmpcat.modifier(idcat,nomcat);
        if (test)

        {

            ui->tabcat->setModel(tmpcat.afficher());


            QMessageBox::information(nullptr, QObject::tr("Modification avec sucées !"),

                        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

        }

        else

            QMessageBox::critical(nullptr, QObject::tr("Modification non sucess !"),

                        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_8->text().toInt();

       produit test= tmpproduit.rechercher(id);

       if (test.get_id()==id)

             {
                     ui->tabproduit->setModel(tmpproduit.afficher_recherche(id));
              /*  mysystem->showMessage(tr("Recherche"),tr("Recherche d'un produit effectué"));

           QMessageBox::information(nullptr, QObject::tr("Rechercher un Produit"),

                           QObject::tr("Produit trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);
*/
             }

       else


       {

           QMessageBox::critical(nullptr, QObject::tr("Error !"),

           QObject::tr("Le Produit n'est pas disponible !.\n"

                        "Click Cancel to exit."), QMessageBox::Cancel);

       }

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tabproduit->setModel(tmpproduit.afficherTri());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tabcat->setModel(tmpcat.afficherTri());
}

void MainWindow::on_pushButton_7_clicked()
{
    int idcat = ui->lineEdit_9->text().toInt();

       categorie test= tmpcat.rechercher(idcat);

       if (test.get_idcat()==idcat)

             { QMessageBox::critical(nullptr, QObject::tr("Error !"),

                                     QObject::tr("Categorie n'est pas disponible !.\n"

                                                  "Click Cancel to exit."), QMessageBox::Cancel);

           // mysystem->showMessage(tr("Recherche"),tr("Recherche d'un produit effectué"));

          /* QMessageBox::information(nullptr, QObject::tr("Rechercher un Produit"),

                           QObject::tr("Categorie trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);*/

             }

       else


       {  ui->tabcat->setModel(tmpcat.afficher_recherche(idcat));



}
}
