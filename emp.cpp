#include "emp.h"
#include<QSqlQuery>
#include<QDebug>

    Emp::Emp()
    {
    id=0;
    nom="";
    cin="";
    tele=0;
    email="";
    adresse="";




    }
    Emp::Emp(int id,QString nom,QString cin,int tele,QString email,QString adresse,QString ville)

    {
      this->id=id;
      this->nom=nom;
      this->cin=cin;
         this->tele=tele;
         this->email=email;
         this->adresse=adresse;

        this->ville=ville;
    }
    QString  Emp::getAdresse(){return adresse;}
    QString Emp::getEmail(){return email;}
    QString Emp::getCin(){return cin;}
    QString Emp::getNom(){return nom;}
    int Emp::getID(){return  id;}
    int Emp::getTele(){return  tele;}



    void   Emp::setAdresse( QString addr){this->adresse=addr;}
    void   Emp::setNom(QString nom ){this->nom=nom;}
    void   Emp::setCin(QString cin) {this->cin=cin;}
     void   Emp::setEmail(QString email) {this->email=email;}
      void   Emp::setTele(int tele) {this->tele=tele;}
       void   Emp::setID(int id) {this->id=id;}


    bool Emp::ajouter()
    {
    QSqlQuery query;
    QString idd=QString::number(id);

    QString teles=QString::number(tele);

     qDebug()<<idd;

     qDebug()<<teles;

    query.prepare("INSERT INTO EMP (id,nom,cin,tele,adresse,email,ville) VALUES (:id,:nom,:cin,:tele,:adresse,:email,:ville)");
    query.bindValue(":id", idd); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
    query.bindValue(":nom", nom);
     query.bindValue(":cin", cin);
      query.bindValue(":tele",teles);
       query.bindValue(":email",email);
       query.bindValue(":adresse", adresse);
        query.bindValue(":ville", ville);


      return query.exec();
    }

    QSqlQueryModel * Emp::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

    model->setQuery("select * from emp");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Ville"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));




        return model;
    }


    QSqlQueryModel * Emp::afficher_cp()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from emp");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        return model;
    }



    bool Emp::supprimer(int id )
    {
    QSqlQuery query;
    query.prepare("Delete from emp where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();
    }

    bool Emp::modifier(int id)
    {
        QSqlQuery query;
        query.prepare("update emp set nom=:nom,cin=:cin,tele=:tele,adresse=:adresse,email=:email,ville=:ville where id=:id");
        query.bindValue(":id", id); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
        query.bindValue(":nom", nom);
         query.bindValue(":cin", cin);
          query.bindValue(":tele", tele);
           query.bindValue(":adresse", adresse);
            query.bindValue(":ville", ville);

        return query.exec();


    }



    QSqlQueryModel *Emp::rechercher(QString rech)
    {

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from emp where nom LIKE '"+rech+"%'");
        return model;
    }



    QSqlQueryModel *Emp::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM emp ORDER BY nom ");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    QSqlQueryModel *Emp::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM emp ORDER BY nom DESC");
       q->exec();
       model->setQuery(*q);

       return model;
    }




