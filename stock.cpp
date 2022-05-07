#include "stock.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>

    stock::stock()
    {
    id=0;
    datee="";
    produit="";

    qte="";




    }
    stock::stock(int id,QString datee,QString produit,QString qte)

    {
      this->id=id;
      this->datee=datee;
      this->produit=produit;
         this->qte=qte;

    }
    QString  stock::getQte(){return qte;}
    QString stock::getProduit(){return produit;}
    QString stock::getDatee(){return datee;}

    int stock::getID(){return  id;}



    void   stock::setDatee( QString dat){this->datee=dat;}
    void   stock::setQte(QString qtee){this->qte=qtee;}
    void   stock::setProduit(QString produit) {this->produit=produit;}

       void   stock::setID(int id) {this->id=id;}

    bool stock::ajouter()
    {
    QSqlQuery query;
    QString idd=QString::number(id);


    query.prepare("INSERT INTO stock (id,datee,produit,qte) VALUES (:id,:datee,:produit,:qte)");
    query.bindValue(":id", idd); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
    query.bindValue(":datee", datee);
     query.bindValue(":produit", produit);
      query.bindValue(":qte",qte);

      return query.exec();
    }

    QSqlQueryModel * stock::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

    model->setQuery("select * from stock");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Qte"));






        return model;
    }


    QSqlQueryModel * stock::getAlertes()
    {QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

    model->setQuery("select * from ALERTE");






        return model;
    }
    QSqlQueryModel * stock::afficher_cp()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from stock");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        return model;
    }



    bool stock::supprimer(int id )
    {
    QSqlQuery query;
    query.prepare("Delete from stock where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();
    }

    bool stock::modifier(int id)
    {
        QSqlQuery query;
        query.prepare("update stock set datee=:datee,produit=:produit,qte=:qte, where id=:id");
        query.bindValue(":id", id); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
        query.bindValue(":datee", datee);
         query.bindValue(":produit", produit);
          query.bindValue(":qte", qte);

        return query.exec();


    }



    QSqlQueryModel *stock::rechercher(QString rech)
    {

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from stock where produit LIKE '"+rech+"%'");
        return model;
    }



    QSqlQueryModel *stock::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM stock ORDER BY produit ");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    QSqlQueryModel *stock::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM stock ORDER BY produit DESC");
       q->exec();
       model->setQuery(*q);

       return model;
    }




