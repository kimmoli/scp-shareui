TEMPLATE = lib

TARGET = $$qtLibraryTarget(scp-shareplugin)
target.path = /usr/lib/nemo-transferengine/plugins

qml.path = /usr/share/scp-shareui/qml
qml.files = qml/shareui.qml \
    qml/notification.png

QT += dbus
CONFIG += plugin link_pkgconfig
PKGCONFIG += nemotransferengine-qt5

HEADERS += \
    scp-transferiface.h \
    scp-plugininfo.h \
    scp-mediatransfer.h

SOURCES += \
    scp-transferiface.cpp \
    scp-plugininfo.cpp \
    scp-mediatransfer.cpp


OTHER_FILES += rpm/shareui.spec \
    qml/notification.png \
    qml/shareui.qml

INSTALLS += target qml
