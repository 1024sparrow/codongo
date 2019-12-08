import QtQuick 2.6
import QtQuick.Controls 2.0

Rectangle
{
	property var variants: []
	property var defa: undefined // first in list
	property var current: undefined
	property var _buttons: {}
	property int _geometrySet: 0 // 1 - width are set, 2 - height are set, 3 - all set

	id: root
	color: "transparent"
	border.color: "#44FFFFFF"
	border.width: 1
	//
	onWidthChanged: function(p) {
		_geometrySet |= 1;
		if (_geometrySet === 3)
			onGeometrySet();
	}
	onHeightChanged: function(p) {
		_geometrySet |= 2;
		if (_geometrySet === 3)
			onGeometrySet();
	}
	Component.onCompleted: function() {
		current = defa || variants.length ? variants[0] : undefined
	}
	function onGeometrySet(){
		if (width < 300)
			return;
		var
			buttonWidth = width / variants.length,
			buttonId,
			buttonPos = 0
		;
		for (const o of variants){
			buttonId = 'b_' + o;
			console.log(`create ${buttonId}`);
			Qt.createQmlObject(
`
import QtQuick 2.6
import QtQuick.Controls 2.0

Rectangle
{
	id: ${buttonId}
	height: parent.height
	width: ${buttonWidth}
	x: ${buttonPos}
	color: "transparent"
	border.color: "#44FFFFFF"
	border.width: 1
}
`,
				root,
				"dynamicItem"
			);
			buttonPos += buttonWidth;
		}
	}

	onCurrentChanged: function(p){
		console.log(`new current value: ${p}`);
	}
}
