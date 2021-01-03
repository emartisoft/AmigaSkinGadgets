QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amigacheckbox.cpp \
    amigacombobox.cpp \
    amigaframe.cpp \
    amigahorizontalline.cpp \
    amigahorizontalslider.cpp \
    amigalabel.cpp \
    amigalineedit.cpp \
    amigalistwidget.cpp \
    amigastandartbutton.cpp \
    amigatextedit.cpp \
    main.cpp \
    amigabutton.cpp \
    amigatitlebar.cpp \
    amigawindow.cpp

HEADERS += \
    amigacheckbox.h \
    amigacolors.h \
    amigacombobox.h \
    amigaframe.h \
    amigahorizontalline.h \
    amigahorizontalslider.h \
    amigalabel.h \
    amigalineedit.h \
    amigalistwidget.h \
    amigastandartbutton.h \
    amigatextedit.h \
    amigabutton.h \
    amigatitlebar.h \
    amigawindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
