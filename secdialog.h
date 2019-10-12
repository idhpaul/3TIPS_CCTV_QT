#ifndef SECDIALOG_H
#define SECDIALOG_H

#include "filedownloader.h"

#include <QDialog>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimediaWidgets/QGraphicsVideoItem>
#include <QGraphicsScene>

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

private slots:
    void on_Button_PTZ_UP_clicked();

    void on_Button_PTZ_DOWN_clicked();

    void on_Button_PTZ_RIGHT_clicked();

    void on_Button_PTZ_LEFT_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SecDialog *ui;
    QPixmap m_img[3];

    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *playlist;
    QGraphicsVideoItem *item;
    QGraphicsScene *scene;
};

#endif // SECDIALOG_H
