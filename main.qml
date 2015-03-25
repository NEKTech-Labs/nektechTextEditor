import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import NEKeditor 1.0


Window {
    visible: true
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    TextArea {
        Accessible.name: "document"
        id: textArea
        width: parent.width
        anchors.top: newButton.bottom
        anchors.bottom: parent.bottom
        baseUrl: "qrc:/"
        text: document.text
        font.pointSize: 12
        Component.onCompleted: forceActiveFocus()
    }

    ToolButton {
        id: newButton
        x: 0
        y: 0
        text: "New"
        onClicked: document.fileUrl = "qrc:/"
    }

    ToolButton {
        id: openButton
        y: 0
        anchors.left: newButton.right
        text: "Open"
        onClicked: fileDialog.open()
    }



    FileDialog{
        id: fileDialog
        nameFilters: ["C Files (*.c)", "C++ Files (*.cpp)"]
        onAccepted: {
            document.fileUrl = fileUrl
        }
    }

    NEKTech_Doc_Handler{
        id: document
        target: textArea
        Component.onCompleted: document.fileUrl = ""
    }

}
