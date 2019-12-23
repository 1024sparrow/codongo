import QtQuick 2.6
import QtQuick.Controls 2.0
import "util.js" as Util

Rectangle {
	id: root
	color: "#80000000"

	Botton {
		text: "MA"
		x: 0
		y: 0
		width: 640
		height: 768
	}

	Botton {
		text: "LB"
		x: 0
		y: 768
		width: 640
		height: 256
	}

	Botton {
		text: "RB"
		x: 640
		y: 768
		width: 640
		height: 256
	}
}
