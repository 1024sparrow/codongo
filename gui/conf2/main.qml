import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0

ApplicationWindow {
	id: root
	visible: true
	color: "#80000000"

	BackEnd {
		id: backend
	}

	Normal {
		id: layNormal
		anchors.fill: parent
	}

	TouchPad {
		id: layTouchPad
		anchors.fill: parent
	}

	NumPad {
		id: layNumPad
		anchors.fill: parent
	}

	Opacity {
		id: layOpacity
		anchors.fill: parent
	}

