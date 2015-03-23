TEMPLATE = app
VERSION = 1.0.0
DEFINES += APP_VERSION="$$VERSION"

QT += qml quick

SOURCES += main.cpp \
    nektech_doc_handler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    nektech_doc_handler.h
