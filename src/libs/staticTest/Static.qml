import QtQuick
import QtQuick.Layouts


import QtMultimedia


Rectangle
{
    color:"green"

    ColumnLayout
    {
        Rectangle
        {
            color:"blue"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        VideoOutput
        {
            id: vidOutput
            Layout.fillWidth: true
            Layout.fillHeight: true
            fillMode: VideoOutput.PreserveAspectFit
        }
    }
}