#include "reclamation.h"

Reclamation::Reclamation()
{

     idrecl=0 ;
     titre="" ;
     //datee="" ;
     description="" ;
     status="" ;

}
Reclamation :: Reclamation(int a,QString b ,QDate c ,QString d ,QString e)
{

    idrecl=a ;
    titre=b ;
    datee=c ;
    description=d ;
    status=e ;
}

bool Reclamation ::  ajouter()
{
QSqlQuery query;
QString id_string =QString::number(idrecl) ;

query.prepare("INSERT INTO reclamation (idrecl,Titre, datee,description,status)    VALUES (:idrecl, :Titre, :datee , :description,:status)");
query.bindValue(":idrecl", id_string);
query.bindValue(":Titre", titre);
query.bindValue(":datee", datee);
query.bindValue(":description", description);
query.bindValue(":status", status);


return query.exec() ;

}


QSqlQueryModel * Reclamation :: afficher()
{
    QSqlQueryModel *  model = new QSqlQueryModel ()    ;
        model->setQuery("select * from reclamation");
        model->setHeaderData(0, Qt::Horizontal,QObject :: tr("idrecl"));
        model->setHeaderData(1, Qt::Horizontal, QObject :: tr("Titre"));
        model->setHeaderData(2, Qt::Horizontal, QObject :: tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, QObject :: tr("Description "));
        model->setHeaderData(4, Qt::Horizontal, QObject :: tr("Status "));


return model ;
}

bool Reclamation :: modifier(int id)
{
     QSqlQuery query;

       // QString res= QString::number(identifiant);

        QString res= QString::number(id);
        query.prepare("UPDATE reclamation SET  idrecl=:idrecl,Titre=:Titre,datee=:datee ,description=:description ,status =:statuss  WHERE idrecl=:idrecl");
        query.bindValue(":idrecl", idrecl);
        query.bindValue(":Titre", titre);
        query.bindValue(":datee", datee);
        query.bindValue(":description", description);
        query.bindValue(":status", status);


           return    query.exec();

}


bool Reclamation :: supprimer(int)
{
    QSqlQuery query;

    query.prepare("Delete from reclamation where idrecl=:idrecl ") ;
    query.bindValue(":idrecl",idrecl);


    query.exec();
    return query.exec() ;


}


QSqlQueryModel * Reclamation ::Recherche(QString a)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from Reclamation WHERE IDRECL LIKE '%"+a+"%' OR TITRE LIKE '%"+a+"%' OR DATEE LIKE '%"+a+"%' "
    "OR DESCRIPTION LIKE '%"+a+"%' OR STATUS LIKE '%"+ a +"%' ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDRECL"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("TITRE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATEE"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESCRIPTION"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("STATUS"));
return model ;

}

QSqlQueryModel * Reclamation::trinom()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * from Reclamation order by IDRECL ");
    q->exec();
    model->setQuery(*q);
    return model;
}




QSqlQueryModel*  Reclamation:: Trier(QString critere)
{


    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare(critere) ;
    query->exec() ;
    model->setQuery(*query) ;

 return model;
}
