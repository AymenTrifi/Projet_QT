#include "gclient.h"
#include "ui_gclient.h"
#include <QThread>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QFile>
#include <QFileDialog>

GClient::GClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GClient)
{
    ui->setupUi(this);

    connect(ui->envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));  // Ajouter Boutton
        connect(ui->browse, SIGNAL(clicked()), this, SLOT(browse())); // Ajouter Boutton
}

GClient::~GClient()
{
    delete ui;

}





void GClient::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_supprimer->text().toInt();
    bool test = tempclient.supprimer(id);
    if (test)
    {


        ui->tableView->setModel(tempclient.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER CLIENT","CLIENT SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER CLIENT","CLIENT NON SUPPRIMER !");
    }

}



void GClient::on_pushButton_ajoute_clicked()
{
    int i=ui->lineEdit_id->text().toInt();
    QString p=ui->lineEdit_prenom->text();
    QString n=ui->lineEdit_nom->text();
    int a=ui->lineEdit_age->text().toInt();
        client tmpclient(i,p,n,a);
        bool test=tmpclient.ajouter();
        if (test)
        {


            ui->tableView->setModel(tempclient.afficher());

            QMessageBox::information(nullptr,"AJOUT CLIENT","CLIENT AJOUTEE");
        }
        else
        {
            QMessageBox::warning(nullptr,"AJOUT CLIENT","CLIENT NON AJOUTEE");
        }

}

void GClient::on_pushButton_rechercher_clicked()
{
    ui->tableView->setModel(tempclient.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(tempclient.afficher_nom(prenom));
}

void GClient::on_pushButton_modifer_clicked()
{
    int id=ui->lineEdit_id_modifier->text().toInt();
        QString nom=ui->lineEdit_prenom_modifier->text();
        QString prenom=ui->lineEdit_nom_modifier->text();
        int age=ui->lineEdit_age_modifier->text().toInt();
        client c( id, nom, prenom, age );
                         bool test=c.modifer(id);
                         if(test)
                         {   ui->tableView->setModel(c.afficher());
                     QMessageBox::information(nullptr,QObject::tr("OK"),
                                            QObject::tr("update effectue.\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);

                         }
                 else
                     {
                             ui->tableView->setModel(c.afficher());
                 QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                            QObject::tr("update non effectue.\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);}
}



void GClient::on_radioButton_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.trierid());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void GClient::on_radioButton_2_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.trierprenom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void GClient::on_radioButton_3_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.triernom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void GClient::on_radioButton_4_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempclient.afficher());

              ui->tableView->setModel(tempclient.trierage());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void GClient::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
             model->setQuery("select * from CLIENTCC where AGE>18 ");
             int number1=model->rowCount();
             model->setQuery("select * from CLIENTCC where AGE<18 ");
             int number2=model->rowCount();
             //model->setQuery("select * from CLIENTCC where AGE ");
             //int number3=model->rowCount();
             int total=number1+number2;
             QString a = QString(1+QString::number((number1*100)/total,'f',2)+"%" );
             QString b = QString(2+QString::number((number2*100)/total,'f',2)+"%" );
            // QString c = QString(3+QString::number((number3*100)/total,'f',2)+"%" );
             QPieSeries *series = new QPieSeries();
             series->append(a,number1); // te9sem char
             series->append(b,number2);
            // series->append(c,number3);
             if (number1!= 0)
             {
                 QPieSlice *slice = series->slices().at(0);
                 slice->setLabelVisible();
                 slice->setPen(QPen());
             }
             if (number2!=0)
             {
                      // Add label, explode and define brush for 2nd slice
                      QPieSlice *slice1 = series->slices().at(1);
                      //slice1->setExploded();
                      slice1->setLabelVisible();
             }

                     // Create the chart widget
                     QChart *chart = new QChart();
                     // Add data to chart with title and hide legend
                     chart->addSeries(series);
                     chart->setTitle("pourcentage sur les etats des clients "+ QString::number(total));
                     chart->legend()->hide();
                     // Used to display the chart
                     QChartView *chartView = new QChartView(chart);
                     chartView->setRenderHint(QPainter::Antialiasing);
                     chartView->resize(1000,500);
                     chartView->show();


}


// Mailing
void  GClient::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->pieceJ->setText( fileListString );

}

void   GClient::sendMail()
{

}

void   GClient::mailSent(QString )
{


}


void GClient::on_browse_clicked()
{
//browse();
}

void GClient::on_envoyer_clicked()
{
//sendMail();
//QString status;
//mailSent(QString status);
}

void GClient::on_pushButton_rechcercher_clicked()
{
    ui->tableView_recherche->setModel( tempclient.recherche(ui->lineEdit_recherche->text()));

}


