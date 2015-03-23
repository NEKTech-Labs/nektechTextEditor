import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import NEKeditor 1.0

Window {
    visible: true
    width: 360
    height: 360

    FileDialog{
        id: fileDialog
        nameFilters: ["c files (*.c)"]
        onAccepted: document.fileUrl = fileUrl
    }

    //button 1 for text open


    Rectangle {
        id: but1
        y:10
        x:2
        width: 210
        height: 56
        color: "#a0a3db"
        radius: 23
        border.width: 1

        Text {
            id: txtopen
            x: 74
            y: 20
            text: qsTr("Press me")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("cliked it\n")
                fileDialog.open();
            }
        }
    }

    //button 2 for text

    Rectangle {
        id: but2
        x:but1.width+ 20
        y:10
        width: 210
        height: 56
        color: "#a0a3db"
        radius: 23
        border.width: 1


        Text {
            id: txtsave
            x: 74
            y: 20
            text: qsTr("save button")
        }

        MouseArea {
            anchors.bottomMargin: -106
            anchors.leftMargin: -8
            anchors.topMargin: 106
            anchors.rightMargin: 8
            anchors.fill: parent
            onClicked: {
                fileDialog.open();
            }
        }
    }  
    
    Rectangle {
        id: but3
        y:10
        x:but1.width+but1.width+50
        width: 210
        height: 56
        color: "#a0a3db"
        radius: 23
        border.width: 1

        Text {
            id: txtnew
            x: 74
            y: 20
            text: qsTr("new")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("cliked it\n")
                document.fileUrl="qrc:/"
            }
        }
    }
    TextArea {
        Accessible.name: "document"
        id: textArea
        anchors.top: but3.Bottom
        //frameVisible: false
        anchors.bottom: parent.bottom
        baseUrl: "qrc:/"
        text: document.text
        font.pointSize: 12
        font.bold: false
        anchors.margins: 20
        textFormat: textArea.AutoText
        //Component.onCompleted: forceActiveFocus()
        onFocusChanged: { if(focus){ cursoron.active = true; } }
    }

    NEKTech_Doc_Handler{
        id: document
        target: textArea
        // cursorPosition: textArea.cursorPosition
        //selectionStart: textArea.selectionStart
        //selectionEnd: textArea.selectionEnd
        Component.onCompleted: document.fileUrl = "qrc:/nektech.c"
    }
}
