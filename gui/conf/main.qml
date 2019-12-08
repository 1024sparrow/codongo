import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0

ApplicationWindow {
	id: root
	width: 200
	height: 200
	visible: true
	color: "#80000000"
	property var modeList: [
		{
			title: 'kb',
			widget: 'kb.qml',
			mouseEventsProcessor: function(p_event){
			}
		},
		{
			title: 'm1',
			widget: 'm1.qml',
			mouseEventsProcessor: function(p_event){
			}
		},
		{
			title: 'm2',
			widget: 'm2.qml',
			mouseEventsProcessor: function(p_event){
			}
		}
	]
	property var _mouseEvent: undefined //mouser.mouseEvent

	BackEnd {
		id: backend
	}

	/*RadioButtonsBlock {
		//
	}
	WorkArea {
		//
	}*/
	MultiPointTouchArea {
		id: mouser
		anchors.fill: parent
		minimumTouchPoints: 1
		maximumTouchPoints: 2
		enabled: true;
		touchPoints: [
			TouchPoint { id: touch1; objectName: "touch 1"; },
			TouchPoint { id: touch2; objectName: "touch 2"; }
		]

		onGestureStarted: {
			gesture.grab();
		}
		onTouchUpdated: {
			// kick processing
			console.log("---onTouchUpdated---");
			console.log(touch1.objectName, "pressed:", touch1.pressed, touch1.x, touch1.y);
			console.log(touch2.objectName, "pressed:", touch2.pressed, touch2.x, touch2.y);
		}
	}

	on_MouseEventChanged: function() {
		console.log('clcked');
	}
	function processMouseEvent(p_event){
	}

	// Максимальное число кнопок в ряде: 14 => логическая ширина строки: 14 * 3 = 42

	Rectangle {
		id: modeswitcher // переключалка между видами(режимами) клавиатур
		//anchors.fill: parent
		anchors.top: parent.top
		width: root.width
		height: 64
		color: "transparent"
		border.color: "red"
		border.width: 2

		RadioButtonsBlock
		{
			height: modeswitcher.height
			width: modeswitcher.width/2
			anchors.left: modeswitcher.left
			variants: ['111','22','3']
		}
	}

	KeyboardNormal {
		id: workarea
		anchors.top: modeswitcher.bottom
		anchors.bottom: parent.bottom
		width: root.width
		//color: "blue"
	}

	/*MouseArea {
		anchors.fill: parent
		onClicked: function() {
			console.log('clicked');
		}
		onPressed: function() { }
		onMoved: function() { }
		onMoved: function() { }
		onMoved: function() { }
		onMoved: function() { }
	}*/

	/*MultiPointTouchArea {
		anchors.fill: parent
		touchPoints: [
			TouchPoint { id: point1 },
			TouchPoint { id: point2 }
		]
	}
	Rectangle {
		width: 30; height: 30
		color: "green"
		x: point1.x
		y: point1.y
	}

	Rectangle {
		width: 30; height: 30
		color: "yellow"
		x: point2.x
		y: point2.y
	}*/

	//Component.onCompleted:
}
