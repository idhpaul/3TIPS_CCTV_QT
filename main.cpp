#include "mainwindow.h"
#include "TEST_DEFINE.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if USE_QT
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);
    VlcCommon::setPluginPath("C:/Qt/VLC-Qt_1.1.0_win64_msvc2015/bin/plugins");
#endif

    MainWindow w;
    w.show();
    return a.exec();
}
