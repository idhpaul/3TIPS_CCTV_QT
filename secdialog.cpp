#include "secdialog.h"
#include "ui_secdialog.h"

#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    QMediaPlayer *player = new QMediaPlayer(this);

    QGraphicsVideoItem *item = new QGraphicsVideoItem;
    QGraphicsScene *scene = new QGraphicsScene(this);

    player->setVideoOutput(item);
    ui->graphicsView->scene()->addItem(item);
    ui->graphicsView->show();

    player->setMedia(QUrl("https://www.radiantmediaplayer.com/media/bbb-360p.mp4"));
    player->play();

}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_Button_PTZ_UP_clicked()
{
    QMessageBox::information(this, "PTZ UP", "TODO: implement PTZ UP button ");
}

void SecDialog::on_Button_PTZ_DOWN_clicked()
{
    QMessageBox::information(this, "PTZ DOWN", "TODO: implement PTZ DOWN button ");
}

void SecDialog::on_Button_PTZ_RIGHT_clicked()
{
    QMessageBox::information(this, "PTZ RIGHT", "TODO: implement PTZ RIGHT button ");
}

void SecDialog::on_Button_PTZ_LEFT_clicked()
{
    QMessageBox::information(this, "PTZ LEFT", "TODO: implement PTZ LEFT button ");
}

void SecDialog::on_pushButton_clicked()
{
    QSslSocket::sslLibraryBuildVersionString();
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished);
    const QUrl url = QUrl("https://smartcctvsystems.s3.amazonaws.com/vtest.avi/frame/frame_0%282019-10-09%2001%3A18%3A44%29.jpg?AWSAccessKeyId=AKIAJRMH7FS7TDMNHKHA&Signature=Kzl54xuulix5v1mUrkxYKn27%2BpY%3D&Expires=1872951527");
    QNetworkRequest request(url);
    nam->get(request);
}

void SecDialog::on_pushButton_2_clicked()
{
    QSslSocket::sslLibraryBuildVersionString();
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished);
    const QUrl url = QUrl("https://smartcctvsystems.s3.amazonaws.com/vtest.avi/heatmap/heatmap_1%282019-10-09%2001%3A21%3A56%29.jpg?AWSAccessKeyId=AKIAJRMH7FS7TDMNHKHA&Signature=87w9StnxmNGxEYaZY7gozmRGhso%3D&Expires=1872951717");
    QNetworkRequest request(url);
    nam->get(request);
}

void SecDialog::on_pushButton_3_clicked()
{
    QSslSocket::sslLibraryBuildVersionString();
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished);
    const QUrl url = QUrl("https://kbob.github.io/images/sample-3.jpg");
    QNetworkRequest request(url);
    nam->get(request);
}

void SecDialog::downloadFinished(QNetworkReply *reply)
{
    QPixmap pm;
    pm.loadFromData(reply->readAll());
    ui->label_downloadimage->setPixmap(pm);
}
