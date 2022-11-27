QT       += core gui charts sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db_operation.cpp \
    equation.cpp \
    expressionEstimator.cpp \
    functions.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp

HEADERS += \
    equation.h \
    expressionEstimator.h \
    mainwindow.h \
    node.h \
    operatorEnum.h \


FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    differential_equations_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32{
    RC_ICONS = $$PWD/favicon.ico

#CONFIG += qt static
#QMAKE_LFLAGS += -static-libgcc -static-libstdc++

    # Select the executable assembly directory depending on project build mode
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/Debug
    } else {
        DESTDIR = $$PWD/Release
    }


    CONFIG(debug, debug|release) {
        QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt --debug  $$PWD/Debug
    } else {
        QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$PWD/Release
    }

} else {

    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/Debug_Linux
    } else {

        DESTDIR = $$PWD/Release_Linux
    }

    CONFIG(debug, debug|release) {
        QMAKE_POST_LINK = cqtdeployer -bin $$DESTDIR/$$TARGET -targetDir $$PWD/Deploy_Linux
    } else {
        QMAKE_POST_LINK = cqtdeployer -bin $$DESTDIR/$$TARGET -targetDir $$PWD/Deploy_Linux
    }

}

DISTFILES += \
    database/equation.sql

RESOURCES += \
    resources.qrc



