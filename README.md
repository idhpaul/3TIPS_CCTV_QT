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

------

## How to make exe release file

1. build project at QT creator for release
2. goto release folder
3. make dirctory like '/windeployqt'
4. open qt terminal like 'QT 5.12.5(MSVC 2017 64-bit)'(find at start menu or search at system)
5. run this "windeployqt C:\Users\MSLM\repo\QT_repo\build-3TIPS_CCTV_QT-Desktop_Qt_5_12_5_MSVC2017_64bit-Release\release\windeployqt"
6. now you can see the windeplyqt dirctory which copy dll files that include depency to run your application