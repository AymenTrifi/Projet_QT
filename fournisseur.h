#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include"QString"
#include <QSqlQueryModel>
#include "connexion.h"

class Fournisseur
{public:
    Fournisseur();
    Fournisseur(int,QString,QString,int,QString,QString,int,int,QString);
    int  getID();
    QString  getNom();
    QString  getMf();
    QString  getEmail();
    QString  getAdresse();
    QString  getVille();
    int getTele();
    int getIsC();
    int getIsV();



    void  setID(int);
    void  setNom(QString);
    void  setMf(QString);
    void  setEmail(QString);
    void  setAdresse(QString);
    void  setVille(QString);
    void setTele(int);
     void setIsC(int);
      void setIsV(int);


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
    QString nom,mf,email,adresse,ville;
    int id,tele,is_vendors,is_costumers;
};

#endif // FOURNISSEUR_H
