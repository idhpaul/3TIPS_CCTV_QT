# 3TIPS_CCTV_QT
This is  senier project that CCTV GUI Application. Use QT

# Dependence
##### [QT SSL]

QT does not include ssl library
  If you don't have ssl libaray you will fail to load https URL Image Data
  So Download OpenSSL Library at [OpenSSL Download Link](http://slproweb.com/products/Win32OpenSSL.html)
  And Open QT projectfile(.pro) after add this 

> win32{ \
> LIBS += -L"C:\Program Files\OpenSSL-Win64\lib" -llibcrypto \
> INCLUDEPATH += C:\Program Files\OpenSSL-Win64\include \
> }

Or You can download openssl in qtdownloadmanager(MaintenanceTool.exe)

------

##### [QT VLC video]

QT Media Player have not to good low latency for watching network stream

So i used QT VLC lib

Site :  https://vlc-qt.tano.si/ 

Example :  https://github.com/vlc-qt/examples 



Than you setting to used VlcWidgetVideo class

1. Goto .ui file

2. select 'Widget'

3. set you want to view widget
4. click right mouse botton on QWidget
5. select 'promoted widget' and select vlc

------

##### [QT MediaPlayer]

When you use QGrapicView with http stream video
You got this error like this

  > DirectShowPlayerService::doRender: Unresolved error code 0x80040218 (IDispatch error #24)

  The error code mean is "No combination of filters could be found to render the stream"
  and the typical cause is that the application cannot decode media.

  Try tod download this project

  Download installer : http://forum.doom9.org/showthread.php?t=156191

  And the source code : https://github.com/Nevcairiel/LAVFilters

