#include "fournisseur.h"
#include<QSqlQuery>
#include<QDebug>

    Fournisseur::Fournisseur()
    {
    id=0;
    nom="";
    mf="";
    tele=0;
    email="";
    adresse="";
    is_costumers=0;
    is_costumers=0;



    }
    Fournisseur::Fournisseur(int id,QString nom,QString mf,int tele,QString email,QString adresse,int is_vendors,int is_costumers,QString ville)

    {
      this->id=id;
      this->nom=nom;
      this->mf=mf;
         this->tele=tele;
         this->email=email;
         this->adresse=adresse;
         this->is_vendors=is_vendors;
         this->is_costumers=is_costumers;
        this->ville=ville;
    }
    QString  Fournisseur::getAdresse(){return adresse;}
    QString Fournisseur::getEmail(){return email;}
    QString Fournisseur::getMf(){return mf;}
    QString Fournisseur::getNom(){return nom;}
    int Fournisseur::getID(){return  id;}
    int Fournisseur::getTele(){return  tele;}
    int Fournisseur::getIsV(){return  is_vendors;}
    int Fournisseur::getIsC(){return  is_costumers;}


    void   Fournisseur::setAdresse( QString addr){this->adresse=addr;}
    void   Fournisseur::setNom(QString nom ){this->nom=nom;}
    void   Fournisseur::setMf(QString mf) {this->mf=mf;}
     void   Fournisseur::setEmail(QString email) {this->email=email;}
      void   Fournisseur::setTele(int tele) {this->tele=tele;}
       void   Fournisseur::setID(int id) {this->id=id;}
        void   Fournisseur::setIsV(int v) {this->is_vendors=v;}
         void   Fournisseur::setIsC(int c) {this->is_costumers=c;}

    bool Fournisseur::ajouter()
    {
    QSqlQuery query;
    QString idd=QString::number(id);
    QString is_v=QString::number(is_vendors);
    QString is_c=QString::number(is_costumers);
    QString teles=QString::number(tele);

      qDebug()<<idd;
       qDebug()<<is_c;
        qDebug()<<is_v;
        qDebug()<<teles;

    query.prepare("INSERT INTO partenaire (id,nom,mf,tele,adresse,email,ville,is_vendors,is_costumers) VALUES (:id,:nom,:mf,:tele,:adresse,:email,:ville,:is_vendors,:is_costumers)");
    query.bindValue(":id", idd); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
    query.bindValue(":nom", nom);
     query.bindValue(":mf", mf);
      query.bindValue(":tele",teles);
       query.bindValue(":email",email);
       query.bindValue(":adresse", adresse);
        query.bindValue(":ville", ville);
         query.bindValue(":is_vendors", 1);
         query.bindValue(":is_costumers", 0);

      return query.exec();
    }

    QSqlQueryModel * Fournisseur::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

    model->setQuery("select * from partenaire where is_vendors='1'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Ville"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Matricule Fiscale"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));




        return model;
    }


    QSqlQueryModel * Fournisseur::afficher_cp()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from partenaire where is_vendors='1'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        return model;
    }



    bool Fournisseur::supprimer(int id )
    {
    QSqlQuery query;
    query.prepare("Delete from partenaire where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();
    }

    bool Fournisseur::modifier(int id)
    {
        QSqlQuery query;
        query.prepare("update partenaire set nom=:nom,mf=:mf,tele=:tele,adresse=:adresse,email=:email,ville=:ville,is_vendors=:is_vendors,is_costumers=:is_costumers where id=:id");
        query.bindValue(":id", id); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
        query.bindValue(":nom", nom);
         query.bindValue(":mf", mf);
          query.bindValue(":tele", tele);
           query.bindValue(":adresse", adresse);
            query.bindValue(":ville", ville);
             query.bindValue(":is_vendors", is_vendors);
             query.bindValue(":is_costumers", is_costumers);
        return query.exec();


    }



    QSqlQueryModel *Fournisseur::rechercher(QString rech)
    {

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from partenaire where nom LIKE '"+rech+"%'");
        return model;
    }



    QSqlQueryModel *Fournisseur::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM partenaire ORDER BY nom ");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    QSqlQueryModel *Fournisseur::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM partenaire ORDER BY nom DESC");
       q->exec();
       model->setQuery(*q);

       return model;
    }




