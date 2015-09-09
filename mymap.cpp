#include "mymap.h"

MyMap::MyMap(QDeclarativeItem *parent) : QDeclarativeItem(parent)
{
    map = new Marble::MarbleWidget();
    map->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
    map->setShowOverviewMap(false);
    map->setShowCrosshairs(false);

    proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(map);
    proxy->setPos(this->x(), this->y());

    QObject::connect(this, SIGNAL(widthChanged()), this, SLOT(onSizeChanged()));
    QObject::connect(this, SIGNAL(heightChanged()), this, SLOT(onSizeChanged()));
}

double MyMap::centerLon()
{
    return map->centerLongitude();
}

double MyMap::centerLat()
{
    return map->centerLatitude();
}

void MyMap::onSizeChanged()
{
    // Resize the child marble widget
    proxy->resize(this->width(), this->height());
}

void MyMap::centerOn(double lon, double lat)
{
    map->centerOn(lon, lat, false);
}

void MyMap::pan(double orgLon, double orgLat, double deltaLon, double deltaLat)
{
    double sensivity = 50;
    double ratio;
    if (map->zoom() > 0) {
        ratio = sensivity / map->zoom();
    } else {
        ratio = sensivity / 1000;
    }

    centerOn(orgLon + deltaLon * ratio, orgLat + deltaLat * ratio);
}
