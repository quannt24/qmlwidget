import QtQuick 1.1
import MyMap 1.0

Rectangle {
    width: 800
    height: 600


    MyMap {
        id: map

        anchors.fill: parent
        objectName: "myMap"
    }

    Text {
        id: textGeoInfo

        height: 40
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: map.geoInfo
    }
}
