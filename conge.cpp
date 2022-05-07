#include "conge.h"
#include<QSqlQuery>
#include<QDebug>

    conge::conge()
    {
    id=0;
    emp="";
    date_debut="";
    nb_jours=0;
    date_fin="";



    }
    conge::conge(int id,QString emp,QString date_debut,QString date_fin,int nb_jours)

    {
      this->id=id;
      this->emp=emp;
      this->date_debut=date_debut;
         this->date_fin=date_fin;
         this->nb_jours=nb_jours;


    }
    QString  conge::getEmp(){return emp;}
    QString conge::getDateDebut(){return date_debut;}
    QString conge::getDateFin(){return date_fin;}
   int conge::getNbJours(){return nb_jours;}
    int conge::getID(){return  id;}

    void  conge::setEmp(QString emp){this->emp=emp;}
   void conge::setDateDebut(QString date_debut){this->date_debut=date_debut;}
    void conge::setDateFin(QString date_fin){this->date_fin=date_fin;}
  void conge::setNbJours(int nb_jours){this->nb_jours=nb_jours;}
    void conge::setID(int id){this->id=id;}


    bool conge::ajouter()
    {
    QSqlQuery query;
    QString idd=QString::number(id);

    QString nb=QString::number(nb_jours);

      qDebug()<<idd;

        qDebug()<<nb;

    query.prepare("INSERT INTO congee (id,emp,date_debut,date_fin,nb_jours) VALUES (:id,:emp,:date_debut,:date_fin,:nb_jours)");
    query.bindValue(":id", idd); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
    query.bindValue(":emp", emp);
     query.bindValue(":date_debut", date_debut);
      query.bindValue(":date_fin",date_fin);
       query.bindValue(":nb_jours",nb_jours);


      return query.exec();
    }

    QSqlQueryModel * conge::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

    model->setQuery("select * from congee ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("emp"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));

    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nb_jours"));






        return model;
    }


    QSqlQueryModel * conge::afficher_cp()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from congee ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        return model;
    }



    bool conge::supprimer(int id )
    {
    QSqlQuery query;
    query.prepare("Delete from congee where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();
    }

    bool conge::modifier(int id)
    {
        QSqlQuery query;
        query.prepare("update congee set emp=:emp,date_debut=:date_debut,date_fin=:date_fin,nb_jours=:nb_jours where id=:id");
        query.bindValue(":id", id); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
        query.bindValue(":emp", emp);
         query.bindValue(":date_debut",date_debut);
          query.bindValue(":date_fin", date_fin);
           query.bindValue(":nb_jours", nb_jours);

        return query.exec();


    }



    QSqlQueryModel *conge::rechercher(QString rech)
    {

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from congee where emp LIKE '"+rech+"%'");
        return model;
    }



    QSqlQueryModel *conge::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM congee ORDER BY emp ");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    QSqlQueryModel *conge::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM emp ORDER BY emp DESC");
       q->exec();
       model->setQuery(*q);

       return model;
    }




