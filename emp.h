#ifndef EMP_H
#define EMP_H
#include"QString"
#include <QSqlQueryModel>
#include "connexion.h"

class Emp
{public:
    Emp();
    Emp(int,QString,QString,int,QString,QString,QString);
    int  getID();
    QString  getNom();
    QString  getCin();
    QString  getEmail();
    QString  getAdresse();
    QString  getVille();
    int getTele();




    void  setID(int);
    void  setNom(QString);
    void  setCin(QString);
    void  setEmail(QString);
    void  setAdresse(QString);
    void  setVille(QString);
    void setTele(int);



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
    QString nom,cin,email,adresse,ville;
    int id,tele;
};
#endif // FOURNISSEUR_H
