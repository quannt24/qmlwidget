import QtQuick 1.1
import MyMap 1.0

Rectangle {
    width: 800
    height: 600


    MyMap {
        id: map

        width: parent.width / 2
        height: parent.height
        anchors.top: parent.top
        anchors.left: parent.left
        objectName: "map1"
    }

    MyMap {
        id: map2

        width: parent.width / 2
        height: parent.height
        anchors.top: parent.top
        anchors.left: map.right
    }

    Text {
        id: textGeoInfo

        height: 40
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: map.geoInfo
    }
}
