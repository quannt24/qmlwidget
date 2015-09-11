#ifndef CARWORKER_H
#define CARWORKER_H

#include <marble/GeoDataCoordinates.h>

#include <QTimer>

class CarWorker : public QObject
{
    Q_OBJECT
public:
    CarWorker(const Marble::GeoDataCoordinates& city, qreal radius, qreal speed);

signals:
    void coordinatesChanged(Marble::GeoDataCoordinates coord);

public slots:
    void startWork();
    void finishWork();

private slots:
    void iterate();

private:
    QTimer *m_timer;
    Marble::GeoDataCoordinates m_city;
    qreal m_radius;
    qreal m_speed;
    qreal m_alpha;
};

#endif // CARWORKER_H
