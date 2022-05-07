#include "connexion.h"
//TEST GIT
connexion::connexion()
{

}
bool connexion::creatconnexion()
{
    bool test=false;
       QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("Source_projet2A");
       db.setUserName("system");
       db.setPassword("rai010502");
       if (db.open())
           test=true;

       return test;
}

