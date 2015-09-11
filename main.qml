import QtQuick 1.1
import MyMap 1.0

Rectangle {
    width: 800
    height: 600

    MyMap {
        id: map
        objectName: "myMap"
        anchors.fill: parent

        /*
        MouseArea {
            id: mouseArea
            anchors.fill: parent

            property int pressedX: parent.width / 2
            property int pressedY: parent.height / 2
            property real panOrgLon: 0
            property real panOrgLat: 0

            onPressed: {
                pressedX = mouseX
                pressedY = mouseY
                panOrgLon = map.centerLon()
                panOrgLat = map.centerLat()
            }

            onMousePositionChanged: {
                if (pressed) {
                    map.pan(panOrgLon, panOrgLat, pressedX - mouseX, mouseY - pressedY);
                }
            }
        }
        */
    }
}
