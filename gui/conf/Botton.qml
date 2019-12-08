import QtQuick 2.6
import QtQuick.Controls 2.0

Rectangle {
	property string text: "XX"
	property string key: "YY"
	property int relWidth: 3 // ширина стандартной (квадратной) кнопки - 3
	property int leftMargin: 0

	id: "root"
	width: 80
	height: 80
	x: 0
	y: 0
	color: "transparent"
	border.color: "#44FFFFFF"
	border.width: 1
	Label {
		text: root.text
		font.pixelSize: 36
		color: "#44FFFFFF"
	}
	//Component.onCompleted: Util.buttons.push(id)
}
