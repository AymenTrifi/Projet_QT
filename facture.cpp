#include "facture.h"
#include<QSqlQuery>
#include<QDebug>
Facture::Facture()
{
id=0;
fournisseur="";
date="";
produit="";
qte="";
ht="";
ttc="";




}
 Facture::Facture(int id,QString fournisseur,QString date,QString produit,QString qte,QString ht,QString ttc)

{
  this->id=id;
  this->fournisseur=fournisseur;
  this->date=date;
     this->produit=produit;
     this->qte=qte;
     this->ht=ht;
     this->ttc=ttc;

}
QString  Facture::getFournisseur(){return fournisseur;}
QString Facture::getDate(){return date;}
QString Facture::getQte(){return qte;}
QString Facture::getHt(){return ht;}
int Facture::getID(){return  id;}
QString Facture::getTTC(){return  ttc;}



void  Facture::setFournisseur(QString forn){this->fournisseur=forn;}
void Facture::setDate(QString dat){this->date=dat;}
void Facture::setQte(QString qte){this->qte=qte;}
void Facture::setHt(QString ht){this->ht=ht;}
void Facture::setID(int id){this->id=id;}
void Facture::setTTC(QString ttc){this->ttc=ttc;}

bool Facture::ajouter()
{
QSqlQuery query;
QString idd=QString::number(id);




query.prepare("INSERT INTO facture (id,fournisseur,datee,produit,qte,ht,ttc) VALUES (:id,:fournisseur,:date,:produit,:qte,:ht,:ttc)");
query.bindValue(":id", idd); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
query.bindValue(":fournisseur", fournisseur);
 query.bindValue(":date", date);
  query.bindValue(":produit",produit);
   query.bindValue(":qte",qte);
   query.bindValue(":ht", ht);
    query.bindValue(":ttc", ttc);


  return query.exec();
}

QSqlQueryModel * Facture::afficher()
{QSqlQueryModel * model= new QSqlQueryModel(); //fournir des donnÃ©es pour afficher des classes telles que QTableView.

model->setQuery("select * from facture");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Produit"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Qte"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("HT"));

model->setHeaderData(6, Qt::Horizontal, QObject::tr("TTC"));





    return model;
}


QSqlQueryModel * Facture::afficher_cp()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select id from facture ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    return model;
}



bool Facture::supprimer(int id )
{
QSqlQuery query;
query.prepare("Delete from facture where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}

bool Facture::modifier(int id)
{
    QSqlQuery query;
    query.prepare("update facture set fournisseur=:fournisseur,datee=:date,produit=:produit,qte=:qte,ht=:ht,ttc=:ttc where id=:id");
    query.bindValue(":id", id); //bindValue = traja3  donne fi bd w yalzem ykounou des chaines
    query.bindValue(":fournisseur", fournisseur);
     query.bindValue(":date", date);
      query.bindValue(":produit",produit);
       query.bindValue(":qte",qte);
       query.bindValue(":ht", ht);
        query.bindValue(":ttc", ttc);
    return query.exec();


}



QSqlQueryModel *Facture::rechercher(QString rech)
{

    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from facture where fournisseur LIKE '"+rech+"%'");
    return model;
}
QSqlQueryModel *Facture::rechercher2(QString rech,QString rech2)
{

    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from facture where fournisseur LIKE '"+rech+"%' and datee like '"+rech2+"%'");
    return model;
}


QSqlQueryModel *Facture::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM facture ORDER BY fournisseur ");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *Facture::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM facture ORDER BY fournisseur DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}




