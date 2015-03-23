/*
 * main.cpp - nektechTextEditor
 *
 * Copyright (C) NEK Tech 2013
 * Developers V1.0:  	Pankaj Saraf
 *			            Jitendra Khasdev
 *                      Pooja Shukla
 *                      Akshay Rastogi
 *                      Poovika Ujjaini
 * Copyright (C) NEK Tech 2015
 *
 * Author and Architect: Pankaj Saraf
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms and conditions of NEK Tech.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "nektech_doc_handler.h"

#define NETECH_APP_NAME "NEKTech Text Editor"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<NEKTech_Doc_Handler>("NEKeditor", 1, 0, "NEKTech_Doc_Handler");
    app.setApplicationName(NETECH_APP_NAME);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
