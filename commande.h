#ifndef COMMANDE_H
#define COMMANDE_H
#include"QString"
#include <QSqlQueryModel>
#include "connexion.h"

class Commande
{public:
    Commande();
    Commande(int,QString,QString,QString,QString,QString,QString);
    int  getID();
    QString  getFournisseur();
    QString  getDatee();
    QString  getProduit();
    QString  getQte();
    QString  getHt();
    QString getTTC();



    void  setID(int);
    void  setFournisseur(QString);
    void  setDatee(QString);
    void  setProduit(QString);
    void  setQte(QString);
    void  setHt(QString);
    void setTTC(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_cp();

    bool supprimer(int);
    bool modifier(int);
  QSqlQueryModel * rechercher(QString);
  QSqlQueryModel * rechercher2(QString,QString);
   // bool rechercher_cp(int);
   QSqlQueryModel *tri();
   QSqlQueryModel * trid();


private:
    QString fournisseur,datee,produit,qte,ht,ttc;
    int id;
};
#endif // FOURNISSEUR_H
