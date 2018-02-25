import QtQuick 2.9
import QtQuick.Controls 2.2
import ScreenPainter 1.0
import ScreenSampler 1.0


Page {
    id: page
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10

        ComboBox {
            model: screenPainter.availableScreens
            textRole: "name"
            id: comboBox
            x: 129
            y: 8
            onCurrentIndexChanged: {
                screenPainter.screenId = currentIndex
            }
        }

        SpinBox {
            id: spinBoxWidth
            x: 290
            y: 8
            value: 16
        }

        SpinBox {
            id: spinBoxHeight
            x: 436
            y: 8
            value: 9
        }
    }

    ScreenSampler {
        id: sampler
    }

    property alias rows: spinBoxHeight.value
    property alias cols: spinBoxWidth.value
    property int topMargin: 0
    property int bottomMargin: 0

    readonly property alias screenWidth: screenPainter.paintedWidth
    readonly property alias screenHeight: screenPainter.paintedHeight
    readonly property int cellWidth: Math.round(screenWidth / cols)
    readonly property int cellHeight: Math.round(screenHeight / rows)

    property var selectedRects: []

    ScreenPainter {
        id: screenPainter

        anchors.fill: parent
        screenId: 0

        Grid {
            id: grid
            anchors.top: parent.top
            anchors.left: parent.left
            width: screenWidth
            height: screenHeight
            columns: cols

            Repeater {
                id: repeater
                model: page.cols * page.rows

                Rectangle {
                    id: rect
                    width: cellWidth
                    height: cellHeight
                    visible: true
                    color: "transparent"
                    border.color: "black"
                    property int xCoord: index % page.cols
                    property int yCoord: index / page.cols

//                    opacity: xCoord === 0 || yCoord === 0 || xCoord === page.cols-1 || yCoord === page.rows-1 ? 1 : 0
                    Text {
                        id: ledNum
                        text: ""
                    }

                    MouseArea {
                        id: clicky
                        anchors.fill: rect
                        onClicked: {
                            console.log("clicked: ", parent.xCoord, ",", parent.yCoord)
                            rect.color = sampler.sampleScreen(screenPainter.screenId, parent.xCoord, parent.yCoord)
                        }
                    }
                }
            }
        }
    }
}
