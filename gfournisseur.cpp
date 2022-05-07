#include "gfournisseur.h"
#include "ui_gfournisseur.h"
#include "connexion.h"
#include <QMainWindow>
#include "QMessageBox"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include"excelexporthelper.h"
#include <QDebug>
using namespace QtCharts;


using std::string;



Gfournisseur::Gfournisseur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gfournisseur)
{
    ui->setupUi(this);
    ui->four->setModel(four.afficher());

     ui->supp_tab->setModel(st.afficher());
    ui->idf->setModel(four.afficher_cp());
    ui->supp_id->setModel(four.afficher_cp());
    ui->four_1->setModel(four.afficher());
    ui->afficher_s->setModel(st.afficher());
    ui->id_s_1->setModel(st.afficher_cp());
    ui->sup_id_s->setModel(st.afficher_cp());
    ui->tab_s->setModel(st.afficher());
   /* ui->tb_region_E->setModel(regE.afficher_E());
    ui->comboBox_RF->setModel(reg.afficher_cp());
    ui->comboBox_RE->setModel(regE.afficher_cp_E());
    ui->comboBox_RF_supp->setModel(reg.afficher_cp());
    ui->comboBox_RE_supp->setModel(regE.afficher_cp_E());
    ui->code_postal_2->setValidator(new QIntValidator (1000,9999 ,this));
     ui->tab_reg->setModel(reg.afficher());
      ui->tab_reg_2->setModel(regE.afficher_E());*/
    ui->tableView_alertes->setModel(st.getAlertes());
    ui->lcdNumber->display(st.getAlertes()->rowCount());



  //  int ret=A.connect_arduino(); // lancer la connexion à arduino
   //switch(ret){
   // case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
     //   break;
   // case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
    //   break;
   // case(-1):qDebug() << "arduino is not available";
    //}
    // QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_temperature())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).


}

Gfournisseur::~Gfournisseur()
{
    delete ui;
}


void Gfournisseur::on_pushButton_choisir_2_clicked()
{

       /* int code_postal=ui->code_postal_2->text().toInt(); // .toint() : chaine --> entier
        QString nom_region=ui->nom_region->text();
        int etat_region=ui->etat_region->text().toInt();


        region R(code_postal ,nom_region,etat_region);



        if (nom_region.isEmpty()) //empty vide
        { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
        }

        else
        {
    bool test=R.ajouter();


    if (test)
            { //Actualiser
        ui->comboBox_RF->setModel(reg.afficher_cp());
        ui->comboBox_RE->setModel(regE.afficher_cp_E());
         ui->tb_region_2->setModel(reg.afficher());
         ui->tb_region->setModel(reg.afficher());
          ui->tab_reg->setModel(reg.afficher());
            QMessageBox:: information(nullptr, QObject::tr("code_postal"),
                                               QObject::tr("Ajout effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("code_postal"),
                                  QObject::tr("Ajout non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
        }*/


}

















void Gfournisseur::on_modfier_region_b_E_clicked()
{
    ui->id_s_1->currentText().toInt();


        int  id=ui->id_s_1->currentText().toInt();
        QString datee=ui->date_s->text();
         QString produit=ui->nom_s->text();
          QString qte=ui->qte_s->text();


        stock sto(id,datee,produit,qte);


      bool test=sto.modifier(id);


              if(test)
              {
                  ui->four->setModel(four.afficher());
                   ui->supp_tab->setModel(st.afficher());
                  ui->idf->setModel(four.afficher_cp());
                  ui->supp_id->setModel(four.afficher_cp());
                  ui->four_1->setModel(four.afficher());
                  ui->afficher_s->setModel(st.afficher());
                  ui->id_s_1->setModel(st.afficher_cp());
                  ui->sup_id_s->setModel(st.afficher_cp());
                  ui->tab_s->setModel(st.afficher());
                      QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("update effectue\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);




              }
                  else
                      QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                  QObject::tr("update non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void Gfournisseur::on_supp_region_E_clicked()
{
      ui->sup_id_s->currentText().toInt();
      bool test=st.supprimer(ui->sup_id_s->currentText().toInt());
      if(test){

          ui->four->setModel(four.afficher());
           ui->supp_tab->setModel(st.afficher());
          ui->idf->setModel(four.afficher_cp());
          ui->supp_id->setModel(four.afficher_cp());
          ui->four_1->setModel(four.afficher());
          ui->afficher_s->setModel(st.afficher());
          ui->id_s_1->setModel(st.afficher_cp());
          ui->sup_id_s->setModel(st.afficher_cp());
          ui->tab_s->setModel(st.afficher());

          QMessageBox::information(nullptr,QObject::tr("suppression"),
                                   QObject::tr("suppression avec succés.\n""Click Cancel to exit."),QMessageBox::Cancel);
      }
      else {
          QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                   QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
      }
}





void Gfournisseur::on_chercher_cp_F_clicked()
{

        QString rech =ui->chercher_regionF->text();
           ui->four->setModel(four.rechercher(rech));


}





void Gfournisseur::on_chercher_tri_reg_clicked()
{

    QString rech =ui->chercher_REGf->text();
        ui->tab_reg->setModel(four.rechercher(rech));
}


void Gfournisseur::on_chercher_tri_reg_2_clicked()
{
    QString rech =ui->chercher_REGe->text();
        ui->tab_s->setModel(st.rechercher(rech));
}




void Gfournisseur::on_retourEE_clicked()
{
    ui->tab_s->setModel(st.afficher());
}


void Gfournisseur::on_retourFF_clicked()
{
    // ui->tab_reg->setModel(reg.afficher());
}


void Gfournisseur::on_tri_croissant_reg_clicked()
{
   Fournisseur *R = new Fournisseur();
         ui->tab_reg->setModel(R->tri());
}


void Gfournisseur::on_tri_decroissant_reg_clicked()
{
   Fournisseur *R = new Fournisseur();
            ui->tab_reg->setModel(R->trid());
}


void Gfournisseur::on_tri_croissant_reg_2_clicked()
{
    stock *R = new stock();
           ui->tab_s->setModel(R->tri());

}


void Gfournisseur::on_tri_decroissant_reg_2_clicked()
{
    stock *R = new stock();
           ui->tab_s->setModel(R->trid());
}



void Gfournisseur::on_stat_regionF_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from partenaire where ville='Tunis' ");
         int number1=model->rowCount();
         model->setQuery("select * from partenaire where ville='Sousse'  ");
         int number2=model->rowCount();
         model->setQuery("select * from partenaire where ville='Sfax' ");
         int number3=model->rowCount();
         int total=number1+number2+number3;
         QString a = QString(1+QString::number((number1*100)/total,'f',2)+"%" );
         QString b = QString(2+QString::number((number2*100)/total,'f',2)+"%" );
         QString c = QString(3+QString::number((number3*100)/total,'f',2)+"%" );
         QPieSeries *series = new QPieSeries();
         series->append(a,number1); // te9sem char
         series->append(b,number2);
         series->append(c,number3);
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
         if(number3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
                 // Create the chart widget
                 QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle("pourcentage sur les etats des regions "+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();

   }



void Gfournisseur::on_stat_regionE_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from stock where qte=0 ");
         int number1=model->rowCount();
         model->setQuery("select * from stock where qte<10  ");
         int number2=model->rowCount();
         model->setQuery("select * from stock where qte>10 ");
         int number3=model->rowCount();
         int total=number1+number2+number3;
         QString a = QString(1+QString::number((number1*100)/total,'f',2)+"%" );
         QString b = QString(2+QString::number((number2*100)/total,'f',2)+"%" );
         QString c = QString(3+QString::number((number3*100)/total,'f',2)+"%" );
         QPieSeries *series = new QPieSeries();
         series->append(a,number1); // te9sem char
         series->append(b,number2);
         series->append(c,number3);
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
         if(number3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
                 // Create the chart widget
                 QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle("pourcentage sur les qte "+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();

  }





void Gfournisseur::on_ajouter_four_clicked()
{
     int id=ui->id_f->text().toInt(); // .toint() : chaine --> entier
     QString nom=ui->nom_f->text();
      QString mf=ui->mf_f->text();
       QString email=ui->email_f->text();
        QString adresse=ui->adresse_f->text();
         QString ville=ui->ville_f->text();
     int tele=ui->tele_f->text().toInt();

     Fournisseur R(id,nom,mf,tele,email,adresse,1,0,ville);
     if (nom.isEmpty()) //empty vide
     { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
     }

     else
     {
 bool test=R.ajouter();

 if (test)
         { //Actualiser
      ui->four->setModel(four.afficher());
       ui->supp_tab->setModel(st.afficher());
       ui->four_1->setModel(four.afficher());
        ui->supp_id->setModel(four.afficher_cp());
 ui->idf->setModel(four.afficher_cp());
         QMessageBox:: information(nullptr, QObject::tr("id"),
                                            QObject::tr("Ajout effectué\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
         }
     else
         QMessageBox::critical(nullptr, QObject::tr("id"),
                               QObject::tr("Ajout non effectué.\n"
                                           "click Cancel to exit."),QMessageBox::Cancel);
 }
}

void Gfournisseur::on_idf_currentIndexChanged(const QString &arg1)
{



}

void Gfournisseur::on_modfier_four_clicked()
{


    int id=ui->idf->currentText().toInt(); // .toint() : chaine --> entier
    QString nom=ui->nom_f_2->text();
     QString mf=ui->mf_f_2->text();
      QString email=ui->email_f_2->text();
       QString adresse=ui->adresse_f_2->text();
        QString ville=ui->ville_f_2->text();
    int tele=ui->tele_f_2->text().toInt();

    Fournisseur R(id,nom,mf,tele,email,adresse,1,0,ville);


      bool test=R.modifier(id);


              if(test)
              {
                  ui->four->setModel(four.afficher());
                   ui->supp_tab->setModel(st.afficher());

                      QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("update effectue\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);





              }
                  else
                      QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                  QObject::tr("update non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gfournisseur::on_supp_clicked()
{

        bool test=four.supprimer(  ui->supp_id->currentText().toInt());
        if(test){

            ui->four->setModel(four.afficher());
             ui->supp_tab->setModel(st.afficher());
            ui->four_1->setModel(four.afficher());
            ui->supp_id->setModel(four.afficher_cp());
            QMessageBox::information(nullptr,QObject::tr("suppression"),
                                     QObject::tr("suppression avec succés.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                     QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
}

void Gfournisseur::on_ajouter_s_clicked()
{
    int id=ui->id_s->text().toInt(); // .toint() : chaine --> entier
    QString datee=ui->date_s->text();
     QString produit=ui->nom_s->text();
      QString qte=ui->qte_s->text();


    stock sto(id,datee,produit,qte);
    if (produit.isEmpty()) //empty vide
    { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
    }

    else
    {
bool test=sto.ajouter();

if (test)
        { //Actualiser
    ui->four->setModel(four.afficher());
     ui->supp_tab->setModel(st.afficher());
    ui->idf->setModel(four.afficher_cp());
    ui->supp_id->setModel(four.afficher_cp());
    ui->four_1->setModel(four.afficher());
    ui->afficher_s->setModel(st.afficher());
    ui->id_s_1->setModel(st.afficher_cp());
    ui->sup_id_s->setModel(st.afficher_cp());
    ui->tab_s->setModel(st.afficher());
        QMessageBox:: information(nullptr, QObject::tr("id"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("id"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}
}

void Gfournisseur::on_button_reg_E_clicked()
{
    QString rech =ui->cp_recherher_E->text();
        ui->afficher_s->setModel(st.rechercher(rech));
}

void Gfournisseur::on_retourFF_2_clicked()
{
    const QString fileName = "C:\\Users\\Dhafer\\Desktop\\fournisseur.xlsx";

        ExcelExportHelper helper;

        helper.SetCellValue(1,1,"ID");
        helper.SetCellValue(1,2,"Nom");
         helper.SetCellValue(1,3,"Matricule Fiscale");
          helper.SetCellValue(1,4,"Téléphone");
           helper.SetCellValue(1,5,"Email");
            helper.SetCellValue(1,6,"Adresse");

            QSqlQuery q;
            q.exec("select * from partenaire");
            int i=2;
            while(q.next()){
                helper.SetCellValue(i,1,q.value(0).toString());
                helper.SetCellValue(i,2,q.value(1).toString());
                 helper.SetCellValue(i,3,q.value(2).toString());
                  helper.SetCellValue(i,4,q.value(3).toString());
                   helper.SetCellValue(i,5,q.value(4).toString());
                    helper.SetCellValue(i,6,q.value(5).toString());

                     i++;
            }

        helper.SaveAs(fileName);
}



void Gfournisseur::update_temperature(){
  //  data = A.read_from_arduino();
    //if(data!=""){
      //  QString DataAsString = QString(data);
//QMessageBox::critical(nullptr, QObject::tr("attention"),
                     // QObject::tr("depassement temperature.\n"
                                 // "click Cancel to exit."),QMessageBox::Cancel);
   // ui->label->setText(DataAsString);
   /* QSqlQuery query;
    query.prepare("INSERT INTO ALERTE (datee) VALUES (:datee)");
    query.bindValue(":datee", QDateTime::currentDateTime());
    query.exec();*/
   // ui->tableView_alertes->setModel(st.getAlertes());
  //  ui->lcdNumber->display(st.getAlertes()->rowCount());

    }


void Gfournisseur::on_pushButton_clicked()
{
   // A.write_arduino("1");
}
