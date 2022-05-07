#include "client.h"
#include <QtDebug>
#include <QSystemTrayIcon>
client::client()
{

}
client::client(int i,QString p,QString n,int a)
{
    id=i;
    prenom=p;
    nom=n;
    age=a;
   // fidelite=f;
}
bool client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTCC (id,prenom,nom,age) VALUES (:id,:prenom,:nom,:age)");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);
    return query.exec();
}
bool client::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTCC where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}


bool client::modifer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Update CLIENTCC set NOM=:nom,PRENOM=:prenom AGE=:age where ID=:id");

        query.bindValue(":prenom",prenom);
        query.bindValue(":nom",nom);
        query.bindValue(":age", age);

        return query.exec();
}


QSqlQueryModel * client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTCC ");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * client::trierid()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTCC ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * client::trierprenom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTCC ORDER BY prenom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * client::triernom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTCC ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * client::trierage()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENTCC ORDER BY age");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * client::afficher_nom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CLIENTCC WHERE id = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}

QSqlQueryModel* client::recherche(QString nom )
{


    QSqlQueryModel * model= new QSqlQueryModel();
        QString qry="select * from CLIENTCC where nom like '%"+nom+"%' ";
        qDebug()<<qry;
        model->setQuery(qry);
        return model;



}
void client::regionC(QString data,int a)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif"));

    notifyIcon->show();
    if (a==1)
   {QString t1,t2;
        t1="l'employé ayant l'id:";
        t1=t1+data;
        t2=" a utilisé la porte privé maintenant";
        t2=t1+t2;
        notifyIcon->showMessage("Notification ",t2,QSystemTrayIcon::Information,15000);}
else if(a==0)
       {QString t1;
        t1="une personne inconnue a essayé d'utiliser la porte privé sous l'id:";
        t1=t1+data;
        notifyIcon->showMessage("Attention ",t1,QSystemTrayIcon::Information,15000);}
}
