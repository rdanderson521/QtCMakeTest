/**
 * @file main.cpp
 * @author Ryan Anderson <rdanderson521@gmail.com>
 * @date 22 May 2023
 * @copyright 2023 Ryan Anderson (AllSteady Ltd)
 * @brief <brief>
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QDirIterator>
#include <QQuickWindow>
#include <QLibraryInfo>
#include <QPluginLoader>

#include <iostream>

int main(int argc, char *argv[])
{
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);

    QGuiApplication app(argc, argv);
  
    // print QT resources tree
    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext())
    {
    	qDebug() << it.next();
    }


    QQmlApplicationEngine engine;

    QPluginLoader sharedPluginLoader("sharedTestplugin", &engine);

    std::cout << "construct err: " << sharedPluginLoader.errorString().toStdString() << std::endl;

    std::cout << "load: " << sharedPluginLoader.load() << std::endl;

    std::cout << "load err: " << sharedPluginLoader.errorString().toStdString() << std::endl;

    std::cout << "isLoaded: " << sharedPluginLoader.isLoaded() << std::endl;

        const std::string appLocation = QCoreApplication::applicationDirPath().toStdString();

    engine.addImportPath(QString::fromStdString(appLocation + "/../plugins"));

    std::cout << "app location: " << appLocation << std::endl;

    std::cout << "plug path  " << QLibraryInfo::path(QLibraryInfo::PluginsPath).toStdString() << std::endl;

            QList<QString>
                paths = engine.importPathList();

    for (QString path: paths)
    {
        std::cout << "path: " << path.toStdString() << std::endl;
    }

    const QUrl url(u"qrc:/qt/qml/mainApp/main.qml"_qs);

    engine.addImportPath(QStringLiteral(":/"));

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl)
        {
    if (!obj && url == objUrl)
        QCoreApplication::exit(-1); },
    Qt::QueuedConnection);

    engine.load(url);

    int ret = app.exec();

    return ret;
}
