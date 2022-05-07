#ifndef GPROJET_H
#define GPROJET_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QMainWindow>
#include "connexion.h"
#include "projet.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include "ui_gprojet.h"
namespace Ui {
class gprojet;
}

class gprojet : public QMainWindow
{
    Q_OBJECT

public:
    explicit gprojet(QWidget *parent = nullptr);
    ~gprojet();

private slots:
    void on_bt_Ajouter_clicked();

    void on_bt_Ajouter_md_clicked();

    void on_Tab_Projet_activated(const QModelIndex &index);

    void on_Supp_Button_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_trier_clicked();

    void on_pdf_clicked();

    void on_stat_clicked();

private:
    Ui::gprojet *ui;
    Projet P ;

    QStringList filesim ;

};

#endif // GPROJET_H
