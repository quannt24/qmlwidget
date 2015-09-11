#include "qtquick1applicationviewer.h"
#include <QApplication>
#include "qdeclarative.h"
#include "mymap.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QtQuick1ApplicationViewer viewer;

    qmlRegisterType<MyMap>("MyMap", 1, 0, "MyMap");

    viewer.setSource(QString("main.qml"));

    MyMap *myMap = (MyMap*) viewer.rootObject()->findChild<MyMap*>("myMap");
    if (myMap) {
        myMap->startCars();
    }

    viewer.showExpanded();
    return app.exec();
}
