#include "projet.h"

Projet::Projet()
{
     idprojet=0 ;
     titre_projet="titre" ;

     date_debut="" ;
     date_fin="" ;
     image = "" ;
}

Projet::Projet(int a ,QString b,QString e,QString f,QString  im)
{
    idprojet=a ;
    titre_projet=b ;
    date_debut=e ;
    date_fin=f ;
    image = im ;

}
bool Projet ::  ajouter()
{
QSqlQuery query;
QString id_string =QString::number(idprojet) ;

query.prepare("INSERT INTO Projet (id,TITRE, date_debut,date_fin,image) " "   VALUES (:id, :TITRE, :date_debut , :date_fin, :image)");
query.bindValue(":id", id_string);
query.bindValue(":TITRE", titre_projet);
query.bindValue(":date_debut", date_debut);
query.bindValue(":date_fin", date_fin);
query.bindValue(":image", image);

return query.exec() ;

}


QSqlQueryModel * Projet :: afficher()
{
    QSqlQueryModel *  model = new QSqlQueryModel ()    ;
        model->setQuery("select * from Projet");
        model->setHeaderData(0, Qt::Horizontal,QObject :: tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject :: tr("TITRE"));
        model->setHeaderData(2, Qt::Horizontal, QObject :: tr("Date_debut"));
        model->setHeaderData(3, Qt::Horizontal, QObject :: tr("Date_fin"));

return model ;
}

bool Projet :: modifier(int id)
{
     QSqlQuery query;

       // QString res= QString::number(identifiant);

        QString res= QString::number(id);
        query.prepare("UPDATE PROJET SET  id=:id,TITRE=:TITRE,date_debut=:date_debut ,date_fin=:date_fin ,image=:image  WHERE id=:id");
        query.bindValue(":id", id);
        query.bindValue(":TITRE", titre_projet);
        query.bindValue(":date_debut", date_debut);
        query.bindValue(":date_fin", date_fin);
        query.bindValue(":image", image);

           return    query.exec();

}


bool Projet :: supprimer(int)
{
    QSqlQuery query;

    query.prepare("Delete from PROJET where id=:id ") ;
    query.bindValue(":id",idprojet);


    query.exec();
    return query.exec() ;


}



QSqlQueryModel * Projet ::Recherche(QString a)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from PROJET WHERE id LIKE '%"+a+"%' OR TITRE LIKE '%"+a+"%' OR DATE_DEBUT LIKE '%"+a+"%' "
    "OR DATE_fin LIKE '%"+a+"%' ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("TITRE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_DEBUT"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_fin"));
return model ;

}



QSqlQueryModel*  Projet:: Trier(QString critere)
{


    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare(critere) ;
    query->exec() ;
    model->setQuery(*query) ;

 return model;
}
