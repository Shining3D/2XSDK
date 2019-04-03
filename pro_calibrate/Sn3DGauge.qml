import QtQuick 2.7
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item{
    id: gaugeRoot
    width: 610
    height: 530
    property real distance: 0
    property bool tooFarWarning: true//distance > 580
    Component{
        id: gaugeStepComp
        RowLayout{
            id: rowLayout
            width: 250
            height: 52
            property bool reached: gaugeRoot.distance >= modelData
            Text{
                id: gaugeValue
                font{family: "Arial"; pointSize: 24; bold: true}
                //width: 70
                Layout.fillWidth: true
                height: contentHeight
                text: modelData
                color: "#5c5c5c"
            }
            Item{
                id: statusItem
                Layout.preferredWidth: 175
                Layout.preferredHeight:  52
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Item {
                    id: src
                    anchors.fill: backgroundRect

                    Rectangle {
                        anchors.centerIn: parent
                        width: src.width - 2
                        height: src.height - 2
                        color: "#262626"
                        radius: backgroundRect.radius
                    }
                }
                InnerShadow {
                    anchors.fill: src
                    cached: true
                    horizontalOffset: 0
                    verticalOffset: 5
                    radius: 20
                    samples: 32
                    color: "black"
                    smooth: true
                    source: src
                }
                Rectangle{
                    id: backgroundRect
                    anchors.fill: parent
                    border{color: "#515151"; width: 1}
                    color: "transparent"
                }

                Item{
                    id: reatechItem
                    anchors.fill: parent
                    visible: rowLayout.reached
                    RectangularGlow {
                        id: reatechItemEffect
                        anchors.fill: parent
                        glowRadius: 10
                        spread: 0.2
                        color: "#8885ff00"
                        cornerRadius: reachedRect.radius + glowRadius
                    }
                    Rectangle{
                        id: reachedRect
                        border{color: "#85ff00"; width: 2}
                        color: "#598b22"
                        anchors.fill: parent
                    }
                    Canvas{
                        id: checkedMarkCanvas
                        width: 40
                        height: 32
                        anchors.centerIn: parent
                        property real lineWidth: 8
                        property real margins: 5
                        onPaint: {
                            var ctx = getContext("2d");
                            var px = 0;
                            var py = 0;
                            px = width -  margins;
                            py = margins;
                            ctx.moveTo(px, py);
                            px = width - margins - (height - 2 * margins);
                            py = height - margins;
                            ctx.lineTo(px, py);
                            py = height - px;
                            px = margins;
                            ctx.lineTo(px, py);
                            ctx.lineWidth = 6;
                            ctx.lineCap = "butt";
                            ctx.strokeStyle = "#85ff00";
                            ctx.lineJoin = "miter";
                            ctx.stroke();
                        }
                    }
                }
            }
        }
    }// Component: gaugeStepComp

    Text{
        id: unitText
        text: "mm"
        anchors{bottom: stepsLayout.top; left: stepsLayout.left; leftMargin: 10}
        height: contentHeight
        width: contentWidth
        font{family: "Arial"; pointSize: 15; bold: true}
        color: "#5c5c5c"
    }

    ColumnLayout{
        id: stepsLayout
        width: 250
        height: 394
        anchors{left:parent.left; verticalCenter: parent.verticalCenter}
        Repeater{
            id: repeater
            model: [560, 530, 500, 470, 430]
            delegate: gaugeStepComp
        }
    }
    Canvas{
        id: warnCanvas
        width: 330
        height: 134
        visible: false
        x: 280
        y: 0
        property real margins: 5
        property real arrowHeight: 25
        onPaint: {
            var ctx = getContext("2d");
            var px = margins;
            var py = margins;
            py = height / 2 - margins;
            ctx.beginPath();
            ctx.moveTo(px, py);
            px += arrowHeight;
            py -= arrowHeight;
            ctx.lineTo(px, py);
            py = margins
            ctx.lineTo(px, py);
            px = width - margins;
            ctx.lineTo(px, py);
            py = height - margins;
            ctx.lineTo(px, py);
            px = margins + arrowHeight;
            ctx.lineTo(px, py);
            py = height-margins - (height / 2 - arrowHeight - margins);
            ctx.lineTo(px, py);
            px = margins;
            py = height / 2 - margins;
            ctx.lineTo(px, py);
            ctx.closePath();
            ctx.lineWidth = 4;
            ctx.lineCap = "butt";
            ctx.strokeStyle = "#b17c23";
            ctx.lineJoin = "miter";
            ctx.stroke();
            ctx.fillStyle = "#362e23";
            ctx.fill();
        }
    }
    Glow {
        id: warnCanvasEffect
        anchors.fill: warnCanvas
        radius: 10
        spread: 0.2
        color: "#aab17c23"
        source: warnCanvas
        smooth: true
        cached: true
        visible: gaugeRoot.tooFarWarning
    }

    Canvas{
        id: downArrow
        width: 50
        height: 50
        property real margins: 5
        property real arrowLength: 16
        anchors{centerIn: warnCanvas; horizontalCenterOffset: -80}
        visible: warnCanvasEffect.visible
        onPaint: {
            var ctx = getContext("2d");
            var px = margins;
            var py = margins;
            px = width / 2 - margins - arrowLength
            py = margins + 5;
            ctx.moveTo(px, py);
            px += arrowLength;
            py += arrowLength;
            ctx.lineTo(px, py);
            px += arrowLength;
            py -= arrowLength;
            ctx.lineTo(px, py);
            px -= arrowLength;
            py = margins + 5 + arrowLength - arrowLength / Math.sin(Math.PI / 4);
            ctx.moveTo(px, py);
            py += arrowLength / Math.sin(Math.PI / 4);
            ctx.lineTo(px, py);
            px = width / 2 - arrowLength - margins;
            py += 12;
            ctx.moveTo(px, py);
            px += arrowLength * 2;
            ctx.lineTo(px, py);
            ctx.lineWidth = 6;
            ctx.lineCap = "butt";
            ctx.strokeStyle = "#f4a523";
            ctx.lineJoin = "miter";
            ctx.stroke();
        }

    }
    Item{
        id: warnTextItem
        visible: warnCanvasEffect.visible
        height: 80
        width: 200
        anchors{verticalCenter: warnCanvas.verticalCenter; right: warnCanvas.right}
        Text{
            id: warnTextLarge
            text: "Too Far"
            font{family: "Arial"; bold: true; pointSize: 30}
            anchors{top: parent.top; left: parent.left}
            color:  "#f4a523"
        }
        Text{
            id: warnTextSmall
            text: "pull down"
            font{family: "Arial"; pointSize: 25}
            anchors{bottom: parent.bottom; left: parent.left; leftMargin: 5}
            color:  "#f4a523"
        }
    }
}
