#include "secdialog.h"
#include "ui_secdialog.h"

#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    qDebug() << "Driver List :  " << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("CCTV");
    if(db.open())
    {
        //QMessageBox::information(this, "DB", "DB open OK");
    }
    else
    {
        QMessageBox::information(this, "DB", "DB open failed");
    }

    //QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec("select R_IP from service where C_ID = 'customer'");
    if (query.next()) {
        s_db_CameraIP = query.value(0).toString();
        qDebug() << s_db_CameraIP;
    }

    QSqlQuery query1;
    query1.exec("select RC_NO from service where R_IP = '" + s_db_CameraIP +"'");
    if (query1.next()) {
        i_db_RC_NO = query1.value(0).toInt();
        qDebug() << i_db_RC_NO;
    }

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    player->setVideoOutput(videoWidget);
    ui->graphicsView->setViewport(videoWidget);


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

//void SecDialog::on_pushButton_clicked()
//{
//    QString s_db_rc_url;

//    QSqlQuery query1;
//    query1.exec("select rc_url from capturetable where RC_NO= "+QString::number(i_db_RC_NO)+" order by S_no desc");
//    if (query1.next()) {
//        s_db_rc_url = query1.value(0).toString();
//        qDebug() << s_db_rc_url;
//    }


//    QSslSocket::sslLibraryBuildVersionString();
//    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
//    connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished);
//    const QUrl url = QUrl(s_db_rc_url);
//    QNetworkRequest request(url);
//    nam->get(request);
//}

//void SecDialog::on_pushButton_2_clicked()
//{
//    QString s_db_rc_url;

//    QSqlQuery query1;
//    query1.exec("select rc_url from capturetable where RC_NO= "+QString::number(i_db_RC_NO)+" order by S_no desc");
//    if (query1.next()) {
//        s_db_rc_url = query1.value(0).toString();
//        qDebug() << s_db_rc_url;
//    }


//    QSslSocket::sslLibraryBuildVersionString();
//    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
//    connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished);
//    const QUrl url = QUrl(s_db_rc_url);
//    QNetworkRequest request(url);
//    nam->get(request);
//}

//void SecDialog::on_pushButton_3_clicked()
//{
//    QSslSocket::sslLibraryBuildVersionString();
//    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
//    connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished);
//    const QUrl url = QUrl("https://pngimage.net/wp-content/uploads/2018/06/hd-720p-logo-png.png");
//    QNetworkRequest request(url);
//    nam->get(request);
//}

//void SecDialog::downloadFinished(QNetworkReply *reply)
//{
//    QPixmap pm;
//    pm.loadFromData(reply->readAll());
//    ui->label_downloadimage->setPixmap(pm);
//}

void SecDialog::on_Button_DetectMode_toggled(bool checked)
{
    if(checked == true)
    {
        qDebug()<<"Change ON";
        ui->label_2->show();
        ui->label_2->setStyleSheet("QLabel { background-color : red; }");
//        QSqlQuery query1;
//        query1.exec("update detect set RC_detect = 'f' where RC_NO=" + QString::number(i_db_RC_NO) + "");
//        if (query1.next()) {
//            i_db_RC_NO = query1.value(0).toInt();
//            qDebug() << i_db_RC_NO;
//        }
    }
    else
    {
        qDebug()<<"Change OFF";
        ui->label_2->hide();
//        QSqlQuery query1;
//        query1.exec("update detect set RC_detect = 't' where RC_NO=" + QString::number(i_db_RC_NO) + "");
//        if (query1.next()) {
//            i_db_RC_NO = query1.value(0).toInt();
//            qDebug() << i_db_RC_NO;
//        }
    }
}

void SecDialog::downloadFinished2(QNetworkReply *reply)
{
    m_imagenum++;

    QString title = "Image" + QString::number(m_imagenum);

    QPixmap pm;
    pm.loadFromData(reply->readAll());

    ui->listWidget->addItem(new QListWidgetItem(QIcon(pm),title));
}


void SecDialog::on_Button_Capture_Image_clicked()
{

    m_imagenum = 0;

    ui->listWidget->setIconSize(QSize(200,200));
    ui->listWidget->clear();

    QString s_db_rc_url;

    QSqlQuery query1;
    query1.exec("select rc_url from capturetable where RC_NO= "+QString::number(i_db_RC_NO)+" order by S_no desc");
    while (query1.next())
    {
        s_db_rc_url = query1.value(0).toString();
        //qDebug() << s_db_rc_url;

        QSslSocket::sslLibraryBuildVersionString();
        QNetworkAccessManager *nam = new QNetworkAccessManager(this);
        connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished2);
        const QUrl url = QUrl(s_db_rc_url);
        QNetworkRequest request(url);
        nam->get(request);
    }

}

void SecDialog::on_Button_Crop_Image_clicked()
{

    m_imagenum = 0;

    ui->listWidget->setIconSize(QSize(200,200));
    ui->listWidget->clear();

    QString s_db_rc_url;

    QSqlQuery query1;
    query1.exec("select rc_url from crop where RC_NO= "+QString::number(i_db_RC_NO)+" order by S_no desc");
    while (query1.next())
    {
        s_db_rc_url = query1.value(0).toString();
        //qDebug() << s_db_rc_url;

        QSslSocket::sslLibraryBuildVersionString();
        QNetworkAccessManager *nam = new QNetworkAccessManager(this);
        connect(nam, &QNetworkAccessManager::finished, this, &SecDialog::downloadFinished2);
        const QUrl url = QUrl(s_db_rc_url);
        QNetworkRequest request(url);
        nam->get(request);
    }

}


