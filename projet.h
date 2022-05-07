#ifndef PROJET_H
#define PROJET_H


#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QMainWindow>
#include "connexion.h"

class Projet
{

private :
    int idprojet ;
    QString titre_projet ;

    QString date_debut ;
    QString date_fin ;
   QString image ;

public:
    Projet();
    Projet(int a ,QString b,QString e,QString f ,QString  im);
    //getter
    int get_id_projet()
    {
        return idprojet ;
    }
    QString get_titre()
    {
        return titre_projet ;
    }
    QString get_date_debut()
    {
        return date_debut ;
    }
    QString get_date_fin()
    {
        return date_fin ;
    }
    QString get_image()
    {
        return image ;
    }
//setter
     void set_idprojet(int a )

     {
         idprojet=a ;
     }
     void set_titre_projet(QString a )

     {
         titre_projet=a ;
     }
     void set_titre_image(QString a )

     {
         image=a ;
     }
     void set_dated_projet(QString a )

     {
         date_debut=a ;
     }
     void set_datef_projet(QString a )

     {
         date_fin=a ;
     }

     bool ajouter() ;
     QSqlQueryModel *  afficher()  ;
     bool  modifier(int id)  ;
     bool  supprimer(int)  ;
     QSqlQueryModel * Recherche(QString a)   ;//cls=ASC ou DESC ;
     QSqlQueryModel*  Trier(QString critere)    ;


};
#endif // PROJET_H
