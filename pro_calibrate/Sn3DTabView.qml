import QtQuick 2.7
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item{
    id: tabView
    width: 690
    height: 428

    property real radius: 10
    property real tabHeight: 60 - radius
    property color boundaryColor: "#4c4c4d"
    property real margins: 3

    property real tabWidth: (width - margins * 2) / bar.count;
    Canvas {
        id: canvas
        anchors.fill: parent
        property real px: 0
        property real py: 0

        function drawBackFrame(ctx){
            px = tabView.margins;
            py = tabView.margins;
            py += tabView.tabHeight + tabView.radius;
            ctx.moveTo(px, py);
            py -= tabView.radius;

            ctx.arc(tabView.radius + tabView.margins, tabView.radius + tabView.margins, tabView.radius, Math.PI, Math.PI * 3 / 2, false);
            px = width - tabView.radius - tabView.margins;
            py = tabView.margins;
            ctx.lineTo(px, py);
            ctx.arc(width - tabView.radius - tabView.margins, tabView.radius + tabView.margins, tabView.radius, -Math.PI / 2, 0, false);
            px += tabView.radius;
            py = tabView.radius + tabView.tabHeight + tabView.margins;
            ctx.lineTo(px, py);
            ctx.strokeStyle = tabView.boundaryColor;
            ctx.lineWidth = 1;
            ctx.stroke();

            ctx.beginPath();
            ctx.moveTo(px, py);
            py = height - tabView.margins;
            ctx.lineTo(px, py);
            px = tabView.margins;
            ctx.lineTo(px, py);
            py = tabView.tabHeight + tabView.radius + tabView.margins;
            ctx.lineTo(px, py);

            ctx.strokeStyle = tabView.boundaryColor;
            ctx.lineWidth = 2;
            ctx.stroke();
        }

        function drawTabFrame(ctx){
            for(var i = 0; i != bar.count; ++i){
                // 当前tab
                if(i == bar.currentIndex){
                    if(bar.currentIndex == 0){
                        ctx.arc(tabView.radius + tabView.margins, tabView.radius + tabView.margins, tabView.radius, Math.PI, Math.PI * 3 / 2, false);
                        px += tabView.tabWidth;
                        py = tabView.margins;
                        ctx.lineTo(px, py);
                        py += tabView.tabHeight + tabView.radius;
                        ctx.lineTo(px, py);
                    }else if(bar.currentIndex == bar.count - 1){
                        px = tabView.margins + tabView.tabWidth * (bar.count - 1);
                        py = tabView.margins;
                        ctx.lineTo(px, py);
                        py += tabView.tabWidth - tabView.radius;
                        ctx.arc(width - tabView.radius - tabView.margins, tabView.radius + tabView.margins, tabView.radius, -Math.PI / 2, 0, false);
                        px = width - tabView.margins;
                        py = tabView.margins + tabView.tabHeight + tabView.radius;
                        ctx.lineTo(px, py);
                    }else{
                        py = tabView.margins;
                        ctx.lineTo(px, py);
                        px += tabView.tabWidth;
                        ctx.lineTo(px, py);
                        py += tabView.radius + tabView.tabHeight;
                        ctx.lineTo(px, py);
                    }
                }
                // 非当前tab
                else{
                    px += tabView.tabWidth;
                    ctx.lineTo(px, py);
                }
            }

            ctx.strokeStyle = tabView.boundaryColor;
            ctx.lineWidth = 2;
            ctx.stroke();
        }

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            drawBackFrame(ctx);
            drawTabFrame(ctx);
        }
    }
    TabBar {
        id: bar
        anchors{left: parent.left; right: parent.right; top: parent.top}
        height: tabView.tabHeight + tabView.radius
        onCurrentIndexChanged:{
            canvas.requestPaint();
        }

        background: Item{}

        spacing: 5
        Sn3DTabButton {
            text: qsTr("1 Step")
        }
        Sn3DTabButton {
            text: qsTr("2 Step")
        }
        Sn3DTabButton {
            text: qsTr("3 Step")
        }
        Sn3DTabButton {
            text: qsTr("4 Step")
        }
        Sn3DTabButton {
            text: qsTr("5 Step")
        }
    }

    StackLayout {
        anchors{left: parent.left; right: parent.right; bottom: parent.bottom;margins: 7}
        height: 354
        //visible: false
        currentIndex: bar.currentIndex
        Item {
            id: homeTab
            Image{
                source: "file:res/icon/einscan-pro.png"
                anchors.fill: parent
            }
        }
        Item {
            id: discoverTab
        }
        Item {
            id: activityTab
        }
    }
}
