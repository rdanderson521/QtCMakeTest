import QtQuick
import QtQuick.Layouts

import QtQuick.Controls

import staticTest
import sharedTest



ApplicationWindow 
{
    id: root
	width: 1280
	height: 720
	visible: true
	title: qsTr("Test")
	flags: Qt.Window
	minimumWidth: 1280
	minimumHeight: 720

    ColumnLayout
    {
        anchors.fill: parent

        

        Shared
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Static
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

    }
}