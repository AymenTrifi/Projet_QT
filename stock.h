#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<QSqlQueryModel>
class stock
{public:
    stock();
    stock(int,QString,QString,QString);
    int  getID();
    QString  getDatee();
    QString  getProduit();
    QString  getQte();


    void  setID(int);
    void  setDatee(QString);
     void  setProduit(QString);
     void setQte(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_cp();

    bool supprimer(int);
    bool modifier(int);
  QSqlQueryModel * rechercher(QString);
   // bool rechercher_cp(int);
   QSqlQueryModel *tri();
   QSqlQueryModel * trid();
   QSqlQueryModel * getAlertes();


private:
    QString datee,produit,qte;
    int id;
};
#endif // FOURNISSEUR_H

