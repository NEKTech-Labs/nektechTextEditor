# *
# * nektechTextEditor.pro - nektechTextEditor
# *
# * Copyright (C) NEK Tech 2013
# * Developers V1.0:  	Pankaj Saraf
# *			            Jitendra Khasdev
# *                      Pooja Shukla
# *                      Akshay Rastogi
# *                      Poovika Ujjaini
# * Copyright (C) NEK Tech 2015
# *
# * Author and Architect: Pankaj Saraf
# *
# * This program is free software; you can redistribute it and/or modify
# * it under the terms and conditions of NEK Tech.
# *
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# *
# *
 
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
