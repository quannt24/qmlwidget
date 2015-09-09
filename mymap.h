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
#include <marble/MarbleWidget.h>

class MyMap : public QDeclarativeItem
{
    Q_OBJECT

private:
    QGraphicsProxyWidget *proxy;
    Marble::MarbleWidget *map;

public:
    MyMap(QDeclarativeItem *parent = 0);

    /**
     * Get longitute of map center
     * @brief centerLon
     * @return
     */
    Q_INVOKABLE double centerLon();
    /**
     * Get latitute of map center
     * @brief centerLat
     * @return
     */
    Q_INVOKABLE double centerLat();

public slots:
    void onSizeChanged();
    void centerOn(double lon, double lat);
    /**
     * Pan map from orgLon and orgLat with an amount according to deltaX and deltaY
     * of the screen
     * @brief pan
     * @param orgLon
     * @param orgLat
     * @param deltaX
     * @param deltaY
     */
    void pan(double orgLon, double orgLat, double deltaX, double deltaY);
};

#endif // MYMAP_H