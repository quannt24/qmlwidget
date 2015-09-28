/**
  * Map declarative item for QML
  *
  * Usage:
  * Register in C++:
  *     qmlRegisterType<MyMap>("MyMap", 1, 0, "MyMap");
  * Import and declare in QML
  *     import MyMap 1.0
  *     MyMap {}
  */

#ifndef MYMAP_H
#define MYMAP_H


#include <QtDeclarative>
#include <vmarblewidget.h>

#include "carworker.h"
#include <marble/GeoDataPlacemark.h>

class MyMap : public QDeclarativeItem
{
    Q_OBJECT

private:
    QGraphicsProxyWidget *proxy;
    Marble::VMarbleWidget *map;

    CarWorker *m_firstWorker;
    Marble::GeoDataPlacemark *m_carFirst;
    QThread *m_threadFirst;

public:
    MyMap(QDeclarativeItem *parent = 0);

    void startCars();

public slots:
    void onSizeChanged();

    void setCarCoordinates(const Marble::GeoDataCoordinates &coord);
};

#endif // MYMAP_H
