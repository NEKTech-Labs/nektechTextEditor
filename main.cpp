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
