QT       += core gui network webenginewidgets multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_FILE = icon.rc

win32{
    INCLUDEPATH += C:\Qt\Tools\OpenSSL\Win_x64\include
    LIBS += -L"C:\Qt\Tools\OpenSSL\Win_x64\lib" -llibcrypto

    INCLUDEPATH += C:\Program Files\MySQL\MySQL Server 8.0\include
    LIBS += -L"C:\Program Files\MySQL\MySQL Server 8.0\lib" -llibmysql

    LIBS += -L"C:\Qt\VLC-Qt_1.1.0_win64_msvc2015\lib" -lVLCQtCore -lVLCQtWidgets
    INCLUDEPATH += C:\Qt\VLC-Qt_1.1.0_win64_msvc2015\include


# Edit below for custom library location
#LIBS       += -L"C:\Users\MSLM\Downloads\VLC-Qt_1.1.0_win64_msvc2015\lib" -lVLCQtCored -lVLCQtWidgetsd
#INCLUDEPATH += C:\Users\MSLM\Downloads\VLC-Qt_1.1.0_win64_msvc2015\include
}

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    secdialog.cpp

HEADERS += \
    TEST_DEFINE.h \
    mainwindow.h \
    secdialog.h

FORMS += \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    CCTV_Resource.qrc

DISTFILES +=
