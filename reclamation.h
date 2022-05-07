#ifndef RECLAMATION_H
#define RECLAMATION_H


#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QDateTime>
#include "connexion.h"


class Reclamation
{
private :

    int idrecl ;
    QString titre ;
    QDate datee ;
    QString description ;
    QString status ;

public:
    Reclamation();
    Reclamation(int a,QString b ,QDate c ,QString d ,QString e);
    //getter
    int get_idrecl ()
    {
        return idrecl ;
    }
    QString get_titre()
    {
        return titre ;
    }
    QDate get_datee()
    {
        return datee ;
    }
    QString get_desc()
    {
        return description ;
    }
    QString get_status()
    {
        return status ;
    }
//setter
    void set_id(int id)
    {
     idrecl = id ;
    }
    void set_titre(QString x)
    {
        titre=x ;
    }
    void set_datee(QDate x)
    {
        datee=x ;
    }
    void set_desc(QString x)
    {
        description=x ;
    }
    void set_status(QString x)
    {
        status=x ;
    }
    bool ajouter() ;
    QSqlQueryModel *  afficher()  ;
    bool  modifier(int id)  ;
    bool  supprimer(int)  ;
    QSqlQueryModel * Recherche(QString a)   ;//cls=ASC ou DESC
    QSqlQueryModel * trinom()  ;
    QSqlQueryModel* Trier(QString critere) ;


};

#endif // RECLAMATION_H
