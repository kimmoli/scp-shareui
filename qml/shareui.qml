import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.TransferEngine 1.0
import org.nemomobile.configuration 1.0

ShareDialog 
{
    id: root
    allowedOrientations: Orientation.Portrait

    property string path: source

    canAccept: true

    onAccepted: 
	{
        linkpath.value = ti.text
        Clipboard.text = fileNameLabel.text
        shareItem.start()
    }

    SailfishShare 
	{
        id: shareItem
        source: root.path
        metadataStripped: true
        serviceId: root.methodId
        userData: {"linkpath": fileNameLabel.text,
                   "targetpath": targetpath.value }
    }

    DialogHeader
    {
        id: dh
        acceptText: "Copy"
    }

    Column
    {
        anchors.top: dh.bottom
        anchors.topMargin: Theme.paddingLarge
        width: parent.width - Theme.horizontalPageMargin
        x: Theme.horizontalPageMargin

        Label
        {
            id: fileNameLabel
            width: parent.width
            height: implicitHeight + Theme.paddingSmall
            wrapMode: Text.Wrap
            font.pixelSize: Theme.fontSizeExtraSmall
            text: ti.text + root.path.split("/").pop()
        }

        TextField
        {
            id: ti
            width: parent.width
            focus: true
            text: linkpath.value
            EnterKey.iconSource: "image://theme/icon-m-enter-accept"
            EnterKey.onClicked:
            {
                root.accept()
            }
        }
        TextField
        {
            id: tari
            width: parent.width
            focus: false
            text: targetpath.value
            EnterKey.iconSource: "image://theme/icon-m-enter-accept"
            onTextChanged: targetpath.value = text
        }
    }

    ConfigurationValue
    {
        id: targetpath
        key: "/scp-shareui/target-path"
        defaultValue: "user@somehost.com:./www/"
    }
    ConfigurationValue
    {
        id: linkpath
        key: "/scp-shareui/link-path"
        defaultValue: "http://somehost.com/"
    }

}
