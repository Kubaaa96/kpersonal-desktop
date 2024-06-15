#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class ButtonHandler : public QObject {
    Q_OBJECT
public slots:
    void onButtonClicked() {
        qInfo("Button clicked!");
    }
};


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ButtonHandler buttonHandler;
    engine.rootContext()->setContextProperty("buttonHandler", &buttonHandler);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("kpersonal-desktop", "Main");

    return app.exec();
}

#include "main.moc"
