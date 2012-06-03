#-----------------------------------------------------------------------------
#
# lmc-clone
#
# lmc : LAN Messenger, Instant messaging client.
#   http://lanmsngr.sourceforge.net/
#   http://sourceforge.net/projects/lanmsngr/
#
#-----------------------------------------------------------------------------

TARGET = lmc-clone

VERSION = 2.0.0

TEMPLATE = app

QT += core gui network xml webkit
### Qt version should be 4, or over.
### greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
### DEBUG MODE CONFIG ###

    DESTDIR = ./debug
    MOC_DIR = ./debug/moc
    OBJECTS_DIR = ./debug/obj
    RCC_DIR = ./debug/rcc
    UI_DIR = ./debug/ui

    DEFINES += DEBUG _DEBUG

} else {
### RELEASE MODE CONFIG ###

    DESTDIR = ./release
    MOC_DIR = ./release/moc
    OBJECTS_DIR = ./release/obj
    RCC_DIR = ./release/rcc
    UI_DIR = ./release/ui

    DEFINES += NDEBUG _NDEBUG

}

# main source code

#-----------------------------------------------------------------------------
#   OpenSSL (version 1.0.0e)
#       http://www.openssl.org
#       http://slproweb.com/products/Win32OpenSSL.html
#-----------------------------------------------------------------------------

INCLUDEPATH += ./openssl/include
DEPENDPATH  += ./openssl/include

# MinGW
win32:win32-g++: LIBS += -L./openssl/lib/MinGW -leay32

# Visual C++
win32:win32-msvc2008: LIBS += -L./openssl/lib/VC -leay32
win32:win32-msvc2010: LIBS += -L./openssl/lib/VC -leay32

win32:LIBS += -liphlpapi

unix:!symbian: LIBS += -L./openssl/lib/ -lcrypto

#-----------------------------------------------------------------------------
# main source code 

include( ./lmcapp/lmcapp.pri )

include( ./lmc/lmc.pri )

# todo: check path
include( ./lmc/resources/lang/translations.pri )

#-----------------------------------------------------------------------------







