#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include"QString"
#include <QSqlQueryModel>
#include "connexion.h"

class conge
{public:
    conge();
    conge(int,QString,QString,QString,int);
    int  getID();
    QString  getEmp();
    QString  getDateDebut();
    QString  getDateFin();
    int  getNbJours();




    void  setID(int);
   void  setEmp(QString);
    void  setDateDebut(QString);
    void  setDateFin(QString);
    void  setNbJours(int);




    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_cp();

    bool supprimer(int);
    bool modifier(int);
  QSqlQueryModel * rechercher(QString);
   // bool rechercher_cp(int);
   QSqlQueryModel *tri();
   QSqlQueryModel * trid();


private:
    QString emp,date_debut,date_fin;
    int id,nb_jours;
};

#endif // CONGE_H
