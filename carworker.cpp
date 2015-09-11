#include "carworker.h"

#include <qmath.h>

CarWorker::CarWorker(const Marble::GeoDataCoordinates &city, qreal radius, qreal speed) :
    QObject(),
    m_timer(new QTimer(this)),
    m_city(city),
    m_radius(radius),
    m_speed(speed),
    m_alpha(0.0)
{}

void CarWorker::startWork()
{
    m_timer->setInterval(0);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(iterate()));
    m_timer->start();
}

void CarWorker::iterate()
{
    qreal lon = m_city.longitude(Marble::GeoDataCoordinates::Degree) + m_radius * qCos(m_alpha * Marble::DEG2RAD);
    qreal lat = m_city.latitude(Marble::GeoDataCoordinates::Degree) + m_radius * qSin(m_alpha * Marble::DEG2RAD);

    Marble::GeoDataCoordinates coord(lon, lat, 0.0, Marble::GeoDataCoordinates::Degree);
    emit coordinatesChanged(coord);

    m_alpha += m_speed;
}

void CarWorker::finishWork()
{
    m_timer->stop();
}
