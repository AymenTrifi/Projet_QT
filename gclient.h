#ifndef GCLIENT_H
#define GCLIENT_H

#include "client.h"
#include <QMainWindow>
#include "connexion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GClient; }
QT_END_NAMESPACE

class GClient : public QMainWindow
{
    Q_OBJECT

public:
    GClient(QWidget *parent = nullptr);
    ~GClient();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    //
    void on_sliderprogress_sliderMoved(int position);

        void on_slidervolume_sliderMoved(int position);

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_positionchanged(qint64 position);

        void on_durationchanged(qint64 position);
        //

        void on_pushButton_ajoute_clicked();

        void on_pushButton_rechercher_clicked();

        void on_pushButton_modifer_clicked();

        void on_checkBox_stateChanged(int arg1);

        void on_radioButton_clicked();

        void on_radioButton_2_clicked();

        void on_radioButton_3_clicked();

        void on_radioButton_4_clicked();

        void on_stat_clicked();

        // Mailing
        void sendMail();
        void mailSent(QString);
        void browse();

        void on_browse_clicked();

        void on_envoyer_clicked();

        void on_pushButton_rechcercher_clicked();

private:

      Ui::GClient *ui;
      client tempclient;

      QStringList files;
};
#endif // GCLIENT_H
