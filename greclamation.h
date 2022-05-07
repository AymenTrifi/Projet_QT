#ifndef GRECLAMATION_H
#define GRECLAMATION_H

#include <QMainWindow>
#include"reclamation.h"
#include <QFileDialog>
#include"historique.h"
#include "connexion.h"


namespace Ui {
class greclamation;
}

class greclamation : public QMainWindow
{
    Q_OBJECT

public:
    explicit greclamation(QWidget *parent = nullptr);
    ~greclamation();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();

    void on_bt_Ajouter_clicked();

    void on_bt_Ajouter_md_clicked();

    void on_Tab_Projet_activated(const QModelIndex &index);

    void on_Supp_Button_clicked();

    void on_Tab_reclamation_activated(const QModelIndex &index);


    void on_lineEdit_rech_textChanged(const QString &arg1);


    void on_comboBox_currentIndexChanged(const QString &arg1);
    QSqlQueryModel * triid()  ;
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_mail_clicked();

    void on_Back_clicked();

    void on_hist_btn_clicked();

    void on_Back2_clicked();

    void on_sendBtn_2_clicked();

    void on_Delete_button_clicked();

    void on_radioButton_jour_toggled(bool checked);

    void on_radioButton_nuit_toggled(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::greclamation *ui;
    Reclamation R ;
    QStringList files;
Historique H ;
};

#endif // GRECLAMATION_H
