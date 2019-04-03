import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

TabButton {
    id: control
    height: parent.height

    contentItem: Text {
        anchors.centerIn: parent
        text: control.text
        font{family: "Arial"; pointSize: 15}
        opacity: enabled ? 1.0 : 0.3
        color: control.checked ? "#2e91ed" : "#747474";
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        height: contentHeight
    }

    background: Rectangle {
        color: "transparent"
    }
}
