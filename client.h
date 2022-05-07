#ifndef CLIENT_H
#define CLIENT_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDialog>
#include "connexion.h"


class client
{
    int id;
    QString prenom;
    QString nom;
    int age;
    //int fidelite;


public:
    client();
    client(int,QString,QString,int);
    int get_id(){return id;}
    QString get_prenom(){return prenom;}
    QString get_nom(){return nom;}
    int get_age(){return age;}
    bool ajouter();
    bool supprimer(int);
    bool modifer(int);
    bool  calc_fidelite();
    QSqlQueryModel *afficher();
    QSqlQueryModel  *trierid();
    QSqlQueryModel  *trierprenom();
    QSqlQueryModel  *triernom();
    QSqlQueryModel  *trierage();
    QSqlQueryModel *afficher_nom(QString);
  QSqlQueryModel* recherche(QString nom );
  void regionC(QString data,int a);
//private:


};

#endif // CLIENT_H
