#ifndef SECDIALOG_H
#define SECDIALOG_H

#include "filedownloader.h"

#include <QDialog>

#include <QTcpSocket>
#include <QHostAddress>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <QMovie>
#include <QListWidgetItem>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

    void SecDialog::downloadFinished(QNetworkReply *reply);
    void SecDialog::downloadFinished2(QNetworkReply *reply);

private slots:

    void SecDialog::InitDB();
    void SecDialog::ConnectCamera();
    void error();

    void on_Button_PTZ_UP_clicked();
    void on_Button_PTZ_DOWN_clicked();
    void on_Button_PTZ_RIGHT_clicked();
    void on_Button_PTZ_LEFT_clicked();

//    void on_pushButton_clicked();
//    void on_pushButton_2_clicked();
//    void on_pushButton_3_clicked();

    void on_Button_DetectMode_toggled(bool checked);

    void on_Button_Capture_Image_clicked();
    void on_Button_Crop_Image_clicked();
    void on_Button_Heatmap_Image_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

public:
    QString s_db_CameraIP;
    int i_db_RC_NO;
    int m_imagenum;

    QTcpSocket m_Socket;   //socket

private:
    Ui::SecDialog *ui;

    QSqlDatabase db;

    QMediaPlayer *player;
    QVideoWidget *videoWidget;

};

#endif // SECDIALOG_H
