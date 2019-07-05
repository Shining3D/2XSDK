import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import "common/"
import "pro_calibrate/"
import "tittle_bar/"
 

Item {
    id: window
	objectName:"main_item"
    visible: true
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    property alias caliSwitch: caliSwitch
   // title: qsTrId("Hello World")
  //  flags: Qt.FramelessWindowHint | Qt.Window

    //visibility: Window.FullScreen
    RadialGradient {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        cached: true
        smooth: true
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#454546" }
            GradientStop { position: 0.3; color: "#2c2b30" }
            GradientStop { position: 1; color: "black" }
        }
        verticalOffset: 125 - window.height / 2
    }

    Sn3DStepBar{
        id: stepBar
        anchors{left: parent.left; top: parent.top; right: parent.right}
    }

    Image{

        source: Qt.resolvedUrl("file:res/icon/logo-shining3D-small.png")
        anchors{verticalCenter: stepBar.verticalCenter; left: parent.left; leftMargin: 50}
    }

    Sn3DSwitch{
        id: caliSwitch
        x: 463
        y: 171
        clip: false
    }

    Text{
        id: switchText1
        text: qsTrId("Calibration")
        color: caliSwitch.checked? "#969697" : "#3ea1fd"
        anchors{verticalCenter: caliSwitch.verticalCenter; right: caliSwitch.left; rightMargin: 50}
        font{family: "Arial"; pointSize: 18}
    }
    Text{
        id: switchText2
        text: qsTrId("Accuracy Diagnostic")
        color: caliSwitch.checked? "#3ea1fd" : "#969697"
        anchors{verticalCenter: caliSwitch.verticalCenter; left: caliSwitch.right; leftMargin: 50}
        font{family: "Arial"; pointSize: 18}
    }

    Sn3DGauge{
        id: gauge
        anchors{right: parent.right; verticalCenter: parent.verticalCenter; rightMargin: 80; verticalCenterOffset: 50}
        distance: 470
    }

    Sn3DTabView{
        id: tabView
        anchors{top: caliSwitch.bottom; horizontalCenter: caliSwitch.horizontalCenter; topMargin: 50}
    }

    ColumnLayout{
        id: notationLayout
        anchors{left: tabView.left; top: tabView.bottom; right: tabView.right; topMargin: 37}
        spacing: 15
        Sn3DNotation{
            id: text1
            order: "a."
            Layout.fillWidth: true
            content: qsTrId("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
        }

        Sn3DNotation{
            id: text3
            order: "b."
            Layout.fillWidth: true
            content: qsTrId("Accuracy Diagnostic Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.")
        }

        Sn3DNotation{
            id: text4
            order: "c."
            Layout.fillWidth: true
            content: qsTrId("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.")
        }
    }


}
