import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Image {
        id: screen0
        source: "image://screen/1"

        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width / 2
        height: parent.height / 2
    }
    Image {
        id: screen1
        source: "image://screen/0"

        anchors.top: parent.top
        anchors.right: parent.right
        width: parent.width / 2
        height: parent.height / 2
    }
}
