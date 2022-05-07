
#include "greclamation.h"
#include "ui_greclamation.h"
#include"reclamation.h"
#include <QMessageBox>
#include "smtpp.h"


greclamation::greclamation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::greclamation)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn_2, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    ui->Tab_reclamation->setModel(R.afficher())    ;
    ui->Tab_History->setModel(H.afficher())    ;
    ui->lineEdit_Id->setValidator( new QIntValidator(0, 999999, this));
    QDate datefact = QDate::currentDate();
    ui->dateEdit->setDate(datefact);


}

greclamation::~greclamation()
{
    delete ui;
}

void greclamation::on_bt_Ajouter_clicked()
{

    QString idrecls = ui->lineEdit_Id->text();

    int idrecl = ui->lineEdit_Id->text().toInt();
    QString titre= ui->lineEdit_titre->text();
    QDate datee = ui->dateEdit->date() ;
    QString description = ui->lineEdit_description->text();
QString status =  ui->lineEdit_status->text();
     Reclamation R(idrecl, titre, datee, description,status);

    bool test=R.ajouter();

    if(test)
    {
        H.set_event("Ajouter de Reclamation  "+idrecls) ;

       if( H.ajouter())

           ui->Tab_History->setModel(H.Trier("select * from Historique ORDER BY TIME DESC" ));


        QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("Ajout effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

       ui->Tab_reclamation->setModel(R.afficher())    ;

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Not Ok"),
             QObject::tr("Ajout non effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);}
}

void greclamation::on_bt_Ajouter_md_clicked()
{
    QString idrecls = ui->lineEdit_Id->text();

    int idrecl = ui->lineEdit_Id->text().toInt();
    QString titre= ui->lineEdit_titre->text();
    QDate datee = ui->dateEdit->date() ;
     QString description = ui->lineEdit_description->text();
QString status =  ui->lineEdit_status->text();
     Reclamation R(idrecl, titre, datee, description,status);
    bool test=R.modifier(idrecl);
    if(test)
    {

        ui->Tab_reclamation->setModel(R.afficher());//refresh


        H.set_event("Modification de Reclamation  "+idrecls) ;

       if( H.ajouter())

           ui->Tab_History->setModel(H.Trier("select * from Historique ORDER BY TIME DESC" ));


              QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEdit_Id->clear();
               ui->lineEdit_titre->clear();
               ui->lineEdit_status->clear();
               ui->lineEdit_description->clear();
               //ui->lineEdit_date->clear();

   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_Id->clear();
        ui->lineEdit_titre->clear();
        ui->lineEdit_status->clear();
        ui->lineEdit_description->clear();
        //ui->lineEdit_date->clear();

    }
    ui->Tab_reclamation->setModel(R.afficher());//refresh

}

void greclamation::on_Supp_Button_clicked()
{
    QString ids =ui->lineEdit_Id->text() ;
       // Client C1;
      // C1.set_id(ui->Id_supp->text().toInt())    ;

    int id=ui->lineEdit_Id->text().toInt()  ;
    Reclamation R1;
    R1.set_id(id)    ;
      // if ( C1.chercherParCin () ==0 )

      // {
       bool test =R1.supprimer(id)    ;
       if(test)
       {
                ui->Tab_reclamation->setModel(R1.afficher())    ;

                H.set_event("Suprresion de Reclamation  "+ids) ;

               if( H.ajouter())

                   ui->Tab_History->setModel(H.Trier("select * from Historique ORDER BY TIME DESC" ));


           QMessageBox::information(nullptr, QObject::tr("Ok"),
                QObject::tr("Suppression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
      ui->Tab_reclamation->setModel(R1.afficher())    ;
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

void greclamation::on_Tab_reclamation_activated(const QModelIndex &index)
{
    QSqlQuery query;

    QString val=ui->Tab_reclamation->model()->data(index).toString();
      query.prepare("Select * from reclamation where IDRECL=:IDRECL");

      query.bindValue(":IDRECL",val);


      if(query.exec())
         {
             while(query.next())
             {

                 ui->lineEdit_Id->setText(query.value(0).toString());
                 ui->lineEdit_titre->setText(query.value(1).toString());
                 ui->dateEdit->setDate(query.value(2).toDate()) ;
                 ui->lineEdit_description->setText(query.value(3).toString());
                 ui->lineEdit_status->setText(query.value(4).toString());

             }
         }
}

void greclamation::on_lineEdit_rech_textChanged(const QString &arg1)
{

    ui->Tab_reclamation->setModel((R.Recherche(arg1)));
    if(ui->lineEdit_rech->text().isEmpty())
    {
        ui->Tab_reclamation->setModel(R.afficher());
    }

}


void greclamation::browse()
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

    ui->file->setText( fileListString );

}

void greclamation::sendMail()
{
    Smtpp* smtp = new Smtpp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void greclamation::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void greclamation::on_pushButton_clicked()
{
    QString type = ui->comboBox->currentText();
    QString critere ="select * from Reclamation ORDER BY "+type;
    ui->Tab_reclamation->setModel(R.Trier(critere));
   // H.set_event("Tri Par "+type ) ;
  //if(H.ajouter())
 // {
   //  critere ="select * from Historique ORDER BY Time ";
    //  ui->Tab_reclamation->setModel(R.Trier("select * from Historique ORDER BY TIME DESC" ));
  // ui->Tab_History->setModel(H.afficher())    ;

 // }
}

void greclamation::on_mail_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void greclamation::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void greclamation::on_hist_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void greclamation::on_Back2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void greclamation::on_sendBtn_2_clicked()
{
    sendMail() ;
}

void greclamation::on_Delete_button_clicked()
{
    if(H.supprimer())
    {
        ui->Tab_History->setModel(H.Trier("select * from Historique ORDER BY TIME DESC" ));

    }
}

void greclamation::on_radioButton_jour_toggled(bool checked)
{
    QList<QWidget *> widgets = this->findChildren<QWidget *>();

    QFile styleSheetFile("C:/Users/azizb/OneDrive/Bureau/Aziz ben salah/1.qss")    ;
     styleSheetFile.open(QFile::ReadOnly) ;
     QString styleSheet = QLatin1String(styleSheetFile.readAll())  ;
       widgets.at(0)->setStyleSheet(styleSheet);
}

void greclamation::on_radioButton_nuit_toggled(bool checked)
{
    QList<QWidget *> widgets = this->findChildren<QWidget *>();

    QFile styleSheetFile("C:/Users/azizb/OneDrive/Bureau/Aziz ben salah/2.qss")    ;
     styleSheetFile.open(QFile::ReadOnly) ;
     QString styleSheet = QLatin1String(styleSheetFile.readAll())  ;
       widgets.at(0)->setStyleSheet(styleSheet);
}

void greclamation::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);


}

void greclamation::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}

