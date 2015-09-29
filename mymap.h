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
    Q_PROPERTY(QString geoInfo READ getGeoInfo() WRITE setGetGeoInfo NOTIFY geoInfoChanged)

    QGraphicsProxyWidget *proxy;
    Marble::VMarbleWidget *map;

    CarWorker *m_firstWorker;
    Marble::GeoDataPlacemark *m_carFirst;
    QThread *m_threadFirst;

    QString geoInfo;

public:
    MyMap(QDeclarativeItem *parent = 0);

    QString &getGeoInfo();
    void setGetGeoInfo(QString &info);

    void startCars();

signals:
    void geoInfoChanged();

public slots:
    void onSizeChanged();

    void onMouseMoveGeoLocation(QString geoLoc);

    void setCarCoordinates(const Marble::GeoDataCoordinates &coord);
};

#endif // MYMAP_H
