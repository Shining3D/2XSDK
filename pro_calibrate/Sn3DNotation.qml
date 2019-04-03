import QtQuick 2.7
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item{
    id: root
    height: 35
    property alias order: orderText.text
    property alias content: contentText.text

    Text{
        id: orderText
        text: "a."
        font{family: "Arial"; bold: true; pointSize: 22}
        anchors{left: parent.left; verticalCenter: parent.verticalCenter}
        width: 50
        color: "#9b9b9b"

    }
    TextArea{
        id: contentText
        text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
        font{family: "Arial"; pointSize: 15}
        anchors{left: orderText.right; verticalCenter: parent.verticalCenter; right: parent.right}
        wrapMode: TextEdit.WordWrap
        color: "#9b9b9b"
    }
}
