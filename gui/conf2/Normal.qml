import QtQuick 2.6
import QtQuick.Controls 2.0
import "util.js" as Util

Rectangle {
	id: root
	color: "#80000000"

	Botton {
		text: "A"
		x: 0
		y: 0
		width: 640
		height: 512
	}

	Botton {
		text: "B"
		x: 640
		y: 0
		width: 640
		height: 512
	}

	Botton {
		text: "C"
		x: 0
		y: 512
		width: 640
		height: 512
	}

	Botton {
		text: "D"
		x: 640
		y: 512
		width: 640
		height: 512
	}
}
