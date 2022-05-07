#ifndef GFINANCE_H
#define GFINANCE_H
#include"commande.h"
#include"facture.h"
#include "connexion.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GFinance; }
QT_END_NAMESPACE

class GFinance : public QMainWindow
{
    Q_OBJECT

public:
    GFinance(QWidget *parent = nullptr);
    ~GFinance();

private slots:


    void on_pushButton_choisir_2_clicked();

   // void on_pushButton_choisir_3_clicked();

    void on_modfier_region_b_clicked();

    //void on_pb_supprimer_2_clicked();

    void on_supp_region_2_clicked();

    void on_ajouter_regionE_clicked();

    void on_modfier_region_b_E_clicked();

    void on_supp_region_E_clicked();

    void on_chercher_cp_F_clicked();


    void on_chercher_tri_reg_clicked();

    void on_chercher_tri_reg_2_clicked();

    void on_retourEE_clicked();

    void on_retourFF_clicked();

    void on_tri_croissant_reg_clicked();

    void on_tri_decroissant_reg_clicked();

    void on_tri_croissant_reg_2_clicked();

    void on_tri_decroissant_reg_2_clicked();

    void on_stat_regionF_clicked();

    void on_stat_regionE_clicked();

    void on_ajouter_regionE_2_clicked();

    void on_ajouter_four_clicked();

    void on_idf_currentIndexChanged(const QString &arg1);

    void on_modfier_four_clicked();

    void on_supp_clicked();

    void on_ajouter_s_clicked();

    void on_button_reg_E_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void update_label();

private:
    Ui::GFinance *ui;
     Commande cmde;
     Facture fact;
     QByteArray data;


};

#endif // GFINANCE_H
