#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_CLIENT_clicked()
{
    GClient *main = new GClient(this);
    main->show();
}

void Menu::on_EMPLOYEE_clicked()
{
    employee *main = new employee(this);
    main->show();
}


void Menu::on_FOURNISSEUR_clicked()
{
    Gfournisseur *main = new Gfournisseur(this);
    main->show();
}



void Menu::on_FINANCE_clicked()
{
    GFinance *main = new GFinance(this);
    main->show();
}

void Menu::on_RECLMATION_clicked()
{
    greclamation *main = new greclamation(this);
    main->show();
}

void Menu::on_PROJET_clicked()
{
    gprojet *main = new gprojet(this);
    main->show();
}
