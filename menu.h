#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "gclient.h"
#include "employee.h"
#include "gfournisseur.h"
#include "gfinance.h"
#include "greclamation.h"
#include "connexion.h"
#include "gprojet.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_CLIENT_clicked();

    void on_EMPLOYEE_clicked();

    void on_pushButton_clicked();

    void on_FOURNISSEUR_clicked();

    void on_FINANCE_clicked();

    void on_RECLMATION_clicked();

    void on_PROJET_clicked();

private:
    Ui::Menu *ui;
};
#endif // MENU_H
