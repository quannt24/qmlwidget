#include "qtquick1applicationviewer.h"
#include <QApplication>
#include "qdeclarative.h"
#include "pushbuttonitem.h"
#include "mymap.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QDeclarativeView view;
    QtQuick1ApplicationViewer viewer;

    qmlRegisterType<PushButtonItem>("PushButton", 1, 0, "PushButtonItem");
    qmlRegisterType<MyMap>("MyMap", 1, 0, "MyMap");

    //view.setSource(QUrl::fromLocalFile("main.qml"));
    //viewer.setSource(QUrl::fromLocalFile("main.qml"));
    viewer.setMainQmlFile("main.qml");
    MyMap *myMap = (MyMap*) viewer.rootObject()->findChild<MyMap*>("myMap");
    if (myMap) {
        qDebug() << "found map";
    }

    viewer.showExpanded();
    return app.exec();
}
