#include "menu.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include"connexion.h"
#include "QtWidgets/QApplication"
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set the app style sheet
        QFile styleSheetFile("C:/Users/trifi/OneDrive/Documents/Projet_Finale/Incrypt.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
    Menu h;
    connexion c;
    bool test=c.creatconnexion();
    if (test)
    {h.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
      return a.exec();
}
