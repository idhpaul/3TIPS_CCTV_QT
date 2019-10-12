# 3TIPS_CCTV_QT
This is  senier project that CCTV GUI Application. Use QT

#Dependence
QT does not include ssl library
  If you don't have ssl libaray you will fail to load https URL Image Data
  So Download OpenSSL Library at [OpenSSL Download Link](http://slproweb.com/products/Win32OpenSSL.html)
  And Open QT projectfile(.pro) after add this 
  
  >win32{ \
  >  LIBS += -L"C:\Program Files\OpenSSL-Win64\lib" -llibcrypto \
  >  INCLUDEPATH += C:\Program Files\OpenSSL-Win64\include \
  >}
