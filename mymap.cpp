#include "mymap.h"

#include <marble/GeoDataDocument.h>
#include <marble/MarbleModel.h>
#include <marble/GeoDataTreeModel.h>
#include <marble/GeoDataStyle.h>
#include <QtSvg/QSvgRenderer>

MyMap::MyMap(QDeclarativeItem *parent) : QDeclarativeItem(parent)
{
    map = new Marble::VMarbleWidget();
    map->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
    //map->setProjection(Marble::Mercator);
    map->setShowOverviewMap(false);
    map->setShowCrosshairs(false);

    Marble::GeoDataCoordinates Kiev(30.523333, 50.45, 0.0, Marble::GeoDataCoordinates::Degree);
    map->centerOn(Kiev);
    map->setZoom(2300);

    QSvgRenderer renderer(QString("bus.svg"));
    QImage busicon(18, 18, QImage::Format_ARGB32);
    busicon.fill(0x00000000);
    QPainter painter(&busicon);
    renderer.render(&painter);

    for (int y = 0; y < busicon.height(); y++) {
        for (int x = 0; x < busicon.width(); x++) {
            QColor color = busicon.pixel(x, y);
            int r, g, b, a;
            color.getRgb(&r,&g,&b,&a);
            a = qAlpha(busicon.pixel(x, y));
            if (a > 0 && r == 0 && g == 0 && b == 0) {
                color.setBlue(0xff);
                color.setGreen(0);
                color.setAlpha(a);
                busicon.setPixel(x, y, color.rgba());
            }
        }
    }

    Marble::GeoDataStyle *style = new Marble::GeoDataStyle;
    style->setIconStyle(Marble::GeoDataIconStyle(busicon));
    m_carFirst = new Marble::GeoDataPlacemark("Bus");
    m_carFirst->setStyle(style);

    Marble::GeoDataDocument *document = new Marble::GeoDataDocument;
    document->append(m_carFirst);
    map->model()->treeModel()->addDocument(document);

    proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(map);
    proxy->setPos(this->x(), this->y());

    QObject::connect(this, SIGNAL(widthChanged()), this, SLOT(onSizeChanged()));
    QObject::connect(this, SIGNAL(heightChanged()), this, SLOT(onSizeChanged()));
}

void MyMap::onSizeChanged()
{
    // Resize the child marble widget
    proxy->setPos(this->x(), this->y());
    proxy->resize(this->width(), this->height());
}

void MyMap::startCars()
{
    Marble::GeoDataCoordinates Kiev(30.523333, 50.45, 0.0, Marble::GeoDataCoordinates::Degree);

    m_threadFirst = new QThread;
    m_firstWorker = new CarWorker(Kiev, (qreal)0.1, (qreal)0.7);
    m_firstWorker->moveToThread(m_threadFirst);

    connect(m_firstWorker, SIGNAL(coordinatesChanged(Marble::GeoDataCoordinates)),
            this, SLOT(setCarCoordinates(Marble::GeoDataCoordinates)), Qt::BlockingQueuedConnection);

    connect(m_threadFirst, SIGNAL(started()), m_firstWorker, SLOT(startWork()));
    connect(m_threadFirst, SIGNAL(finished()), m_firstWorker, SLOT(finishWork()));

    m_threadFirst->start();
}

void MyMap::setCarCoordinates(const Marble::GeoDataCoordinates &coord)
{
    CarWorker *worker = qobject_cast<CarWorker*>(sender());

    if (worker == m_firstWorker) {
        m_carFirst->setCoordinate(coord);
        map->model()->treeModel()->updateFeature(m_carFirst);
    }
}
