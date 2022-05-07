#include "gprojet.h"
#include "ui_gprojet.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include "projet.h"

gprojet::gprojet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gprojet)
{
    ui->setupUi(this);
    connect(ui->Browse_img, SIGNAL(clicked()), this, SLOT(browse_img()));
 Projet p ;
 ui->Tab_Projet->setModel(p.afficher())    ;


}
gprojet::~gprojet()
{
    delete ui;
}

void gprojet::on_bt_Ajouter_clicked()
{
    int idprojet = ui->lineEdit_Id->text().toInt();
    QString titre_projet= ui->lineEdit_titre->text();
     QString datedebut= ui->lineEdit_dd->text();
     QString datefin = ui->lineEdit_df->text();
     QString image=ui->lineEdit_image->text();

    Projet p(idprojet, titre_projet, datedebut, datefin,image);

    bool test=p.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("Ajout effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

       ui->Tab_Projet->setModel(p.afficher())    ;

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Not Ok"),
             QObject::tr("Ajout non effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);}
}

void gprojet::on_bt_Ajouter_md_clicked()
{
    int idprojet = ui->lineEdit_Id->text().toInt();
    QString titre_projet= ui->lineEdit_titre->text();
     QString datedebut= ui->lineEdit_dd->text();
     QString datefin = ui->lineEdit_df->text();
     QString image=ui->lineEdit_image->text();

     Projet p(idprojet, titre_projet, datedebut, datefin,image);
    bool test=p.modifier(idprojet);
    if(test)
    {

        ui->Tab_Projet->setModel(p.afficher());//refresh

              QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEdit_Id->clear();
               ui->lineEdit_titre->clear();
               ui->lineEdit_dd->clear();
               ui->lineEdit_df->clear();
   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_Id->clear();
        ui->lineEdit_titre->clear();
        ui->lineEdit_dd->clear();
        ui->lineEdit_df->clear();
    }
    ui->Tab_Projet->setModel(p.afficher());//refresh

}

void gprojet::on_Tab_Projet_activated(const QModelIndex &index)
{
    QSqlQuery query;

    QString val=ui->Tab_Projet->model()->data(index).toString();
      query.prepare("Select * from projet where id=:id");

      query.bindValue(":id",val);


      if(query.exec())
         {
             while(query.next())
             {

                 ui->lineEdit_Id->setText(query.value(0).toString());
                 ui->lineEdit_titre->setText(query.value(1).toString());
                 ui->lineEdit_dd->setText(query.value(2).toString());
                 ui->lineEdit_df->setText(query.value(3).toString());
                 ui->lineEdit_image->setText(query.value(4).toString())  ;

                 QString image=query.value(4).toString() ;
                 QString im = "C:/Users/Amen Services/Documents";//+image;
                 QPixmap px (im+image) ;
                 ui->label_img->setPixmap(px) ;

             }
         }


}

void gprojet::on_Supp_Button_clicked()
{
    QString ids =ui->lineEdit_Id->text() ;
       // Client C1;
      // C1.set_id(ui->Id_supp->text().toInt())    ;

    int id=ui->lineEdit_Id->text().toInt()  ;
    Projet p1;
    p1.set_idprojet(id)    ;
      // if ( C1.chercherParCin () ==0 )

      // {
       bool test =p1.supprimer(id)    ;
       if(test)
       {
                ui->Tab_Projet->setModel(p1.afficher())    ;

           QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("Suppression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
      ui->Tab_Projet->setModel(p1.afficher())    ;
       }
       else
       {
           QMessageBox::information(nullptr, QObject::tr("Not Ok"),
                QObject::tr("Suppression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


       }
      //  }
       // else
       // {
       //     QMessageBox::warning(this, "Echec", "identifiant non existant !");


       // }
}

void gprojet::on_lineEdit_rech_textChanged(const QString &arg1)
{

    ui->Tab_Projet->setModel((P.Recherche(arg1)));
    if(ui->lineEdit_rech->text().isEmpty())
    {
        ui->Tab_Projet->setModel(P.afficher());
    }
}

void gprojet::on_trier_clicked()
{
    QString type = ui->comboBox->currentText();
    QString critere ="select * from Projet ORDER BY "+type;
    ui->Tab_Projet->setModel(P.Trier(critere));
   // H.set_event("Tri Par "+type ) ;
  //if(H.ajouter())
 // {
   //  critere ="select * from Historique ORDER BY Time ";
    //  ui->Tab_reclamation->setModel(R.Trier("select * from Historique ORDER BY TIME DESC" ));
  // ui->Tab_History->setModel(H.afficher())    ;

 // }
}

void gprojet::on_pdf_clicked()
{
    QSqlDatabase db;
                    QTableView projet;
                    QSqlQueryModel * Model=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT ID, TITRE as TITRE, DATE_DEBUT, DATE_FIN FROM projet ");
                     qry.exec();
                     Model->setQuery(qry);
                     projet.setModel(Model);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);


                     const int rowCount = projet.model()->rowCount();
                     const int columnCount =  projet.model()->columnCount();


                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                             "<img src='C:/Users/Amen Services/Documents/b.jpg' height='120' width='120'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             "<img src='e-care.png'>"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des projets")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!projet.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(projet.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!projet.isColumnHidden(column)) {
                                 QString data = projet.model()->data(projet.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         QLabel lab;
                          QPixmap pixmap(":/img/aze.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         //QPrinter printer(QPrinter::PrinterResolution);

                         //pixmap.load("aze.png");
                         //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                         //painter.drawPixmap(10,10,50,50, pixmap);

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/produit.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}

