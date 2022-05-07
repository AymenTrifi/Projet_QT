#include "gfinance.h"
#include "ui_gfinance.h"
#include "connexion.h"

#include <QMainWindow>
#include "QMessageBox"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<excelexporthelper.h>
#include"smtp.h"
using namespace QtCharts;


using std::string;



GFinance::GFinance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GFinance)
{
    ui->setupUi(this);
    ui->id_s_1_f->setModel(fact.afficher_cp());
    ui->sup_id_s_f->setModel(fact.afficher_cp());
    ui->supp_id->setModel(cmde.afficher_cp());
    ui->tab_reg->setModel(cmde.afficher());
    ui->four->setModel(cmde.afficher());
    ui->four_1->setModel(cmde.afficher());
    ui->afficher_fact->setModel(fact.afficher());
    ui->tab_fact_supp->setModel(fact.afficher());
    ui->tab_fact_tri->setModel(fact.afficher());
   /* ui->tb_region_E->setModel(regE.afficher_E());
    ui->comboBox_RF->setModel(reg.afficher_cp());
    ui->comboBox_RE->setModel(regE.afficher_cp_E());
    ui->comboBox_RF_supp->setModel(reg.afficher_cp());
    ui->comboBox_RE_supp->setModel(regE.afficher_cp_E());
    ui->code_postal_2->setValidator(new QIntValidator (1000,9999 ,this));

      ui->tab_reg_2->setModel(regE.afficher_E());
*/



}

GFinance::~GFinance()
{
    delete ui;
}




void GFinance::on_modfier_region_b_E_clicked()
{
    int id=ui->id_s_1_f->currentText().toInt(); // .toint() : chaine --> entier
    QString fournisseur=ui->fournisseur_4->text();
     QString date=ui->date_4->text();
      QString produit=ui->produit_4->text();
       QString qte=ui->qte_4->text();
        QString ht=ui->ht_4->text();
    QString ttc=ui->ttc_4->text();

   Facture c(id,fournisseur,date,produit,qte,ht,ttc);
    if (fournisseur.isEmpty()) //empty vide
    { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
    }

    else
    {
bool test=c.modifier(id);

if (test)
        { //Actualiser
    ui->afficher_fact->setModel(fact.afficher());

     ui->four_1->setModel(cmde.afficher());
      ui->supp_id->setModel(cmde.afficher_cp());
   ui->id_s_1_f->setModel(fact.afficher_cp());
    ui->sup_id_s_f->setModel(fact.afficher_cp());
    ui->tab_fact_supp->setModel(fact.afficher());
    ui->tab_fact_tri->setModel(fact.afficher());

   /* ui->afficher_s->setModel(st.afficher());
    ui->id_s_1->setModel(st.afficher_cp());
    ui->sup_id_s->setModel(st.afficher_cp());
    ui->tab_s->setModel(st.afficher());
ui->idf->setModel(four.afficher_cp());*/
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


void GFinance::on_supp_region_E_clicked()
{
    ui->sup_id_s_f->currentText().toInt();
      bool test=fact.supprimer(ui->sup_id_s_f->currentText().toInt());
      if(test){

       ui->afficher_fact->setModel(fact.afficher());

         ui->four_1->setModel(cmde.afficher());
         ui->id_s_1_f->setModel(fact.afficher_cp());
         ui->supp_id->setModel(cmde.afficher_cp());

          ui->sup_id_s_f->setModel(fact.afficher_cp());
          ui->tab_fact_supp->setModel(fact.afficher());
          ui->tab_fact_tri->setModel(fact.afficher());

          QMessageBox::information(nullptr,QObject::tr("suppression"),
                                   QObject::tr("suppression avec succés.\n""Click Cancel to exit."),QMessageBox::Cancel);
      }
      else {
          QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                   QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
      }




}
void GFinance::on_chercher_cp_F_clicked()
{

        QString rech =ui->chercher_regionF->text();
         ui->four->setModel(cmde.rechercher(rech));


}





void GFinance::on_chercher_tri_reg_clicked()
{

    QString rech =ui->chercher_REGf->text();
     QString rech2 =ui->chercher_REGf_2->text();
        ui->tab_reg->setModel(cmde.rechercher2(rech,rech2));
}


void GFinance::on_chercher_tri_reg_2_clicked()
{
    QString rech =ui->chercher_REGe->text();
    QString rech2 =ui->chercher_REGe_2->text();

       ui->tab_fact_tri->setModel(fact.rechercher2(rech,rech2));
}




void GFinance::on_retourEE_clicked()
{
    ui->tab_fact_tri->setModel(fact.afficher());
}


void GFinance::on_retourFF_clicked()
{
    ui->tab_reg->setModel(cmde.afficher());
}


void GFinance::on_tri_croissant_reg_clicked()
{
   Commande *R = new Commande();
      ui->tab_reg->setModel(R->tri());
}


void GFinance::on_tri_decroissant_reg_clicked()
{
  Commande *R = new Commande();
            ui->tab_reg->setModel(R->trid());
}


void GFinance::on_tri_croissant_reg_2_clicked()
{
    Facture *R = new Facture();
           ui->tab_fact_tri->setModel(R->tri());

}


void GFinance::on_tri_decroissant_reg_2_clicked()
{
    Facture *R = new Facture();
         ui->tab_fact_tri->setModel(R->trid());
}



void GFinance::on_stat_regionF_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from commande where qte='0' ");
         int number1=model->rowCount();
         model->setQuery("select * from commande where qte<10  ");
         int number2=model->rowCount();
         model->setQuery("select * from commande where ville>10 ");
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
                 chart->setTitle("pourcentage sur les etats des qte "+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();

   }



void GFinance::on_stat_regionE_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from facture where qte=0 ");
         int number1=model->rowCount();
         model->setQuery("select * from facture where qte<10  ");
         int number2=model->rowCount();
         model->setQuery("select * from facture where qte>10 ");
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







void GFinance::on_idf_currentIndexChanged(const QString &arg1)
{



}

void GFinance::on_modfier_four_clicked()
{


    int id=ui->idc->currentText().toInt(); // .toint() : chaine --> entier
     QString fournisseur=ui->fournisseur_2->text();
      QString date=ui->date_2->text();
       QString produit=ui->produit_2->text();
        QString qte=ui->qte_2->text();
         QString ht=ui->ht_2->text();
     QString ttc=ui->ttc_2->text();

    Commande cc(id,fournisseur,date,produit,qte,ht,ttc);


      bool test=cc.modifier(id);


          if(test)
              {

              ui->afficher_fact->setModel(fact.afficher());

                ui->four_1->setModel(cmde.afficher());
                ui->id_s_1_f->setModel(fact.afficher_cp());
                 ui->sup_id_s_f->setModel(fact.afficher_cp());
                 ui->tab_fact_supp->setModel(fact.afficher());
                 ui->tab_fact_tri->setModel(fact.afficher());
                 ui->supp_id->setModel(cmde.afficher_cp());

                 /* ui->afficher_s->setModel(st.afficher());
                  ui->id_s_1->setModel(st.afficher_cp());
                  ui->sup_id_s->setModel(st.afficher_cp());
                  ui->tab_s->setModel(st.afficher());
              ui->idf->setModel(four.afficher_cp());*/

                      QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("update effectue\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);





              }
                  else
                      QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                  QObject::tr("update non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void GFinance::on_supp_clicked()
{

       bool test=cmde.supprimer(  ui->supp_id->currentText().toInt());
       if(test){


           ui->afficher_fact->setModel(fact.afficher());

             ui->four_1->setModel(cmde.afficher());
             ui->id_s_1_f->setModel(fact.afficher_cp());
              ui->sup_id_s_f->setModel(fact.afficher_cp());
              ui->tab_fact_supp->setModel(fact.afficher());
              ui->tab_fact_tri->setModel(fact.afficher());

           /* ui->afficher_s->setModel(st.afficher());
            ui->id_s_1->setModel(st.afficher_cp());
            ui->sup_id_s->setModel(st.afficher_cp());
            ui->tab_s->setModel(st.afficher());
        ui->idf->setModel(four.afficher_cp());*/
            QMessageBox::information(nullptr,QObject::tr("suppression"),
                                     QObject::tr("suppression avec succés.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                     QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
}

void GFinance::on_ajouter_s_clicked()
{
    int id=ui->id_f_2->text().toInt(); // .toint() : chaine --> entier
    QString fournisseur=ui->fournisseur_3->text();
     QString date=ui->date_3->text();
      QString produit=ui->produit_3->text();
       QString qte=ui->qte_3->text();
        QString ht=ui->ht_3->text();
    QString ttc=ui->ttc_3->text();
    ui->supp_id->setModel(cmde.afficher_cp());

    Facture c(id,fournisseur,date,produit,qte,ht,ttc);
    if (fournisseur.isEmpty()) //empty vide
    { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
    }

    else
    {
bool test=c.ajouter();

 if (test)
        { //Actualiser

     ui->afficher_fact->setModel(fact.afficher());

       ui->four_1->setModel(cmde.afficher());
       ui->id_s_1_f->setModel(fact.afficher_cp());
        ui->sup_id_s_f->setModel(fact.afficher_cp());
        ui->tab_fact_supp->setModel(fact.afficher());
        ui->tab_fact_tri->setModel(fact.afficher());
        ui->supp_id->setModel(cmde.afficher_cp());

   /* ui->afficher_s->setModel(st.afficher());
    ui->id_s_1->setModel(st.afficher_cp());
    ui->sup_id_s->setModel(st.afficher_cp());
    ui->tab_s->setModel(st.afficher());
ui->idf->setModel(four.afficher_cp());*/
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

void GFinance::on_button_reg_E_clicked()
{
    QString rech =ui->cp_recherher_E->text();
        ui->afficher_fact->setModel(fact.rechercher(rech));
}

void GFinance::on_pushButton_clicked()
{

        const QString fileName = "C:\\Users\\aloui\\Desktop\\factures.xlsx";

        ExcelExportHelper helper;

        helper.SetCellValue(1,1,"ID");
        helper.SetCellValue(1,2,"Fournisseur");
         helper.SetCellValue(1,3,"Date");
          helper.SetCellValue(1,4,"Produit");
           helper.SetCellValue(1,5,"Qte");
            helper.SetCellValue(1,6,"HT");
             helper.SetCellValue(1,7,"TTC");
            QSqlQuery q;
            q.exec("select * from facture");
            int i=2;
            while(q.next()){
                helper.SetCellValue(i,1,q.value(0).toString());
                helper.SetCellValue(i,2,q.value(1).toString());
                 helper.SetCellValue(i,3,q.value(2).toString());
                  helper.SetCellValue(i,4,q.value(3).toString());
                   helper.SetCellValue(i,5,q.value(4).toString());
                    helper.SetCellValue(i,6,q.value(5).toString());
                     helper.SetCellValue(i,7,q.value(6).toString());
                     i++;
            }

        helper.SaveAs(fileName);

}

void GFinance::on_pushButton_2_clicked()
{

    const QString fileName = "C:\\Users\\aloui\\Desktop\\cmde.xlsx";

    ExcelExportHelper helper;

    helper.SetCellValue(1,1,"ID");
    helper.SetCellValue(1,2,"Nom");
     helper.SetCellValue(1,3,"Date");
      helper.SetCellValue(1,4,"Produit");
       helper.SetCellValue(1,5,"Qte");
        helper.SetCellValue(1,6,"HT");
         helper.SetCellValue(1,7,"TTC");
        QSqlQuery q;
        q.exec("select * from commande");
        int i=2;
        while(q.next()){
            helper.SetCellValue(i,1,q.value(0).toString());
            helper.SetCellValue(i,2,q.value(1).toString());
             helper.SetCellValue(i,3,q.value(2).toString());
              helper.SetCellValue(i,4,q.value(3).toString());
               helper.SetCellValue(i,5,q.value(4).toString());
                helper.SetCellValue(i,6,q.value(5).toString());
                 helper.SetCellValue(i,7,q.value(6).toString());
                 i++;
        }

    helper.SaveAs(fileName);
}

void GFinance::on_pushButton_3_clicked()
{
    Smtp *newMail  = new Smtp("marwan1921@gmail.com","alouimed08@gmail.com"," Your Subject","My body text");
    delete newMail;

}


void GFinance::update_label(){
}

void GFinance::on_ajouter_four_clicked()
{
    int id=ui->id_f->text().toInt(); // .toint() : chaine --> entier
    QString fournisseur=ui->fournisseur->text();
     QString datee=ui->date->text();
      QString produit=ui->produit->text();
       QString qte=ui->qte->text();
        QString ht=ui->ht->text();
    QString ttc=ui->ttc->text();

    Commande c(id,fournisseur,datee,produit,qte,ht,ttc);
    if (fournisseur.isEmpty()) //empty vide
    { QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("le nom est vide."),QMessageBox::Cancel);
    }

    else
    {
bool test=c.ajouter();

if (test)
        { //Actualiser

    ui->afficher_fact->setModel(fact.afficher());

      ui->four_1->setModel(cmde.afficher());
      ui->id_s_1_f->setModel(fact.afficher_cp());
      ui->supp_id->setModel(cmde.afficher_cp());

       ui->sup_id_s_f->setModel(fact.afficher_cp());
       ui->tab_fact_supp->setModel(fact.afficher());
       ui->tab_fact_tri->setModel(fact.afficher());
   /* ui->afficher_s->setModel(st.afficher());
    ui->id_s_1->setModel(st.afficher_cp());
    ui->sup_id_s->setModel(st.afficher_cp());
    ui->tab_s->setModel(st.afficher());
ui->idf->setModel(four.afficher_cp());*/
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
