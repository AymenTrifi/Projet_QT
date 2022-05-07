#include "commande.h"
#include<QSqlQuery>
#include<QDebug>

    Commande::Commande()
    {
    id=0;
    fournisseur="";
    datee="";
    produit="";
    qte="";
    ht="";
    ttc="";




    }
     Commande::Commande(int id,QString fournisseur,QString datee,QString produit,QString qte,QString ht,QString ttc)

    {
      this->id=id;
      this->fournisseur=fournisseur;
      this->datee=datee;
         this->produit=produit;
         this->qte=qte;
         this->ht=ht;
         this->ttc=ttc;

    }
    QString  Commande::getFournisseur(){return fournisseur;}
    QString Commande::getDatee(){return datee;}
    QString Commande::getQte(){return qte;}
    QString Commande::getHt(){return ht;}
    int Commande::getID(){return  id;}
    QString Commande::getTTC(){return  ttc;}



    void  Commande::setFournisseur(QString forn){this->fournisseur=forn;}
    void Commande::setDatee(QString dat){this->datee=dat;}
    void Commande::setQte(QString qte){this->qte=qte;}
   void Commande::setHt(QString ht){this->ht=ht;}
    void Commande::setID(int id){this->id=id;}
    void Commande::setTTC(QString ttc){this->ttc=ttc;}

    bool Commande::ajouter()
    {
    QSqlQuery query;
    QString idd=QString::number(id);




    query.prepare("INSERT INTO commande (id,fournisseur,datee,produit,qte,ht,ttc) VALUES (:id,:fournisseur,:datee,:produit,:qte,:ht,:ttc)");
    query.bindValue(":id", idd); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
    query.bindValue(":fournisseur", fournisseur);
     query.bindValue(":date",datee);
      query.bindValue(":produit",produit);
       query.bindValue(":qte",qte);
       query.bindValue(":ht", ht);
        query.bindValue(":ttc", ttc);


      return query.exec();
    }

    QSqlQueryModel * Commande::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

    model->setQuery("select * from commande");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Produit"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Qte"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("HT"));

    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TTC"));





        return model;
    }


    QSqlQueryModel * Commande::afficher_cp()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from commande ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        return model;
    }



    bool Commande::supprimer(int id )
    {
    QSqlQuery query;
    query.prepare("Delete from Commande where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();
    }

    bool Commande::modifier(int id)
    {
        QSqlQuery query;
        query.prepare("update commande set fournisseur=:fournisseur,datee=:datee,produit=:produit,qte=:qte,ht=:ht,ttc=:ttc where id=:id");
        query.bindValue(":id", id); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
        query.bindValue(":fournisseur", fournisseur);
         query.bindValue(":date", datee);
          query.bindValue(":produit",produit);
           query.bindValue(":qte",qte);
           query.bindValue(":ht", ht);
            query.bindValue(":ttc", ttc);
        return query.exec();


    }



    QSqlQueryModel *Commande::rechercher(QString rech)
    {

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from commande where fournisseur LIKE '"+rech+"%'");
        return model;
    }

    QSqlQueryModel *Commande::rechercher2(QString rech,QString rech2)
    {

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from commande where fournisseur LIKE '"+rech+"%' and datee LIKE '"+rech2+"%'");
        return model;
    }

    QSqlQueryModel *Commande::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM commande ORDER BY fournisseur ");
       q->exec();
       model->setQuery(*q);

       return model;
    }

    QSqlQueryModel *Commande::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM commande ORDER BY fournisseur DESC");
       q->exec();
       model->setQuery(*q);

       return model;
    }




