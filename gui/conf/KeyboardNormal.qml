import QtQuick 2.6
import QtQuick.Controls 2.0
//import io.qt.examples.backend 1.0

import "util.js" as Util

Rectangle {
	id: root
	visible: true
	color: "#80000000"
	property int _geometrySet: 0 // 1 - width are set, 2 - height are set, 3 - all set

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

	/*BackEnd {
		id: backend
	}*/

	// Максимальное число кнопок в ряде: 14 => логическая ширина строки: 14 * 3 = 42

	Botton { id: "b0"; text: "E"; key: "Esc";}
	Botton { id: "b1"; text: "F1"; key: "F1";}
	Botton { id: "b2"; text: "F2"; key: "F1";}
	Botton { id: "b3"; text: "F3"; key: "F1";}
	Botton { id: "b4"; text: "F4"; key: "F1";}
	Botton { id: "b5"; text: "F5"; key: "F1";}
	Botton { id: "b6"; text: "F6"; key: "F1";}
	Botton { id: "b7"; text: "F7"; key: "F1";}
	Botton { id: "b8"; text: "F8"; key: "F1";}
	Botton { id: "b9"; text: "F9"; key: "F1";}
	Botton { id: "b10"; text: "F10"; key: "F1";}
	Botton { id: "b11"; text: "F11"; key: "F1";}
	Botton { id: "b12"; text: "F12"; key: "F1";}

	Botton { id: "b21"; text: "`"; key: "";}
	Botton { id: "b22"; text: "1"; key: "";}
	Botton { id: "b23"; text: "2"; key: "";}
	Botton { id: "b24"; text: "3"; key: "";}
	Botton { id: "b25"; text: "4"; key: "";}
	Botton { id: "b26"; text: "5"; key: "";}
	Botton { id: "b27"; text: "6"; key: "";}
	Botton { id: "b28"; text: "7"; key: "";}
	Botton { id: "b29"; text: "8"; key: "";}
	Botton { id: "b30"; text: "9"; key: "";}
	Botton { id: "b31"; text: "0"; key: "";}
	Botton { id: "b32"; text: "-"; key: "";}
	Botton { id: "b33"; text: "="; key: "";}
	Botton { id: "b34"; text: "<-"; key: "";}

	Botton { id: "b221"; text: "~"; key: "";}
	Botton { id: "b222"; text: "!"; key: "";}
	Botton { id: "b223"; text: "@"; key: "";}
	Botton { id: "b224"; text: "#"; key: "";}
	Botton { id: "b225"; text: "$"; key: "";}
	Botton { id: "b226"; text: "%"; key: "";}
	Botton { id: "b227"; text: "^"; key: "";}
	Botton { id: "b228"; text: "&"; key: "";}
	Botton { id: "b229"; text: "*"; key: "";}
	Botton { id: "b230"; text: "("; key: "";}
	Botton { id: "b231"; text: ")"; key: "";}
	Botton { id: "b232"; text: "_"; key: "";}
	Botton { id: "b233"; text: "+"; key: "";}
	Botton { id: "b234"; text: "<-"; key: "";}

	Botton { id: "b41"; text: "Tab"; key: "";}
	Botton { id: "b42"; text: "q"; key: "";}
	Botton { id: "b43"; text: "w"; key: "";}
	Botton { id: "b44"; text: "e"; key: "";}
	Botton { id: "b45"; text: "r"; key: "";}
	Botton { id: "b46"; text: "t"; key: "";}
	Botton { id: "b47"; text: "y"; key: "";}
	Botton { id: "b48"; text: "u"; key: "";}
	Botton { id: "b49"; text: "i"; key: "";}
	Botton { id: "b50"; text: "o"; key: "";}
	Botton { id: "b51"; text: "p"; key: "";}
	Botton { id: "b52"; text: "["; key: "";}
	Botton { id: "b53"; text: "]"; key: "";}
	//Botton { id: "b"; text: ""; key: "";}

	/*Botton { id: "b241"; text: "Tab"; key: "";}
	Botton { id: "b242"; text: "Q"; key: "";}
	Botton { id: "b243"; text: "W"; key: "";}
	Botton { id: "b244"; text: "E"; key: "";}
	Botton { id: "b245"; text: "R"; key: "";}
	Botton { id: "b246"; text: "T"; key: "";}
	Botton { id: "b247"; text: "Y"; key: "";}
	Botton { id: "b248"; text: "U"; key: "";}
	Botton { id: "b249"; text: "I"; key: "";}
	Botton { id: "b250"; text: "O"; key: "";}
	Botton { id: "b251"; text: "P"; key: "";}
	Botton { id: "b252"; text: "{"; key: "";}
	Botton { id: "b253"; text: "}"; key: "";}*/
	//Botton { id: "b"; text: ""; key: "";}

	/*Botton { id: "b261"; text: "Cap"; key: "";}
	Botton { id: "b262"; text: "A"; key: "";}
	Botton { id: "b263"; text: "S"; key: "";}
	Botton { id: "b264"; text: "D"; key: "";}
	Botton { id: "b265"; text: "F"; key: "";}
	Botton { id: "b266"; text: "G"; key: "";}
	Botton { id: "b267"; text: "H"; key: "";}
	Botton { id: "b268"; text: "J"; key: "";}
	Botton { id: "b269"; text: "K"; key: "";}
	Botton { id: "b270"; text: "L"; key: "";}
	Botton { id: "b271"; text: ":"; key: "";}
	Botton { id: "b272"; text: "\""; key: "";}
	Botton { id: "b273"; text: "|"; key: "";}
	Botton { id: "b274"; text: "Ent"; key: "";}*/

	Botton { id: "b61"; text: "Cap"; key: "";}
	Botton { id: "b62"; text: "a"; key: "";}
	Botton { id: "b63"; text: "s"; key: "";}
	Botton { id: "b64"; text: "d"; key: "";}
	Botton { id: "b65"; text: "f"; key: "";}
	Botton { id: "b66"; text: "g"; key: "";}
	Botton { id: "b67"; text: "h"; key: "";}
	Botton { id: "b68"; text: "j"; key: "";}
	Botton { id: "b69"; text: "k"; key: "";}
	Botton { id: "b70"; text: "l"; key: "";}
	Botton { id: "b71"; text: ";"; key: "";}
	Botton { id: "b72"; text: "'"; key: "";}
	Botton { id: "b73"; text: "\\"; key: "";}
	Botton { id: "b74"; text: "Ent"; key: "";}

	Botton { id: "b81"; text: "Shi"; key: "";}
	Botton { id: "b82"; text: "Z"; key: "";}
	Botton { id: "b83"; text: "X"; key: "";}
	Botton { id: "b84"; text: "C"; key: "";}
	Botton { id: "b85"; text: "V"; key: "";}
	Botton { id: "b86"; text: "B"; key: "";}
	Botton { id: "b87"; text: "N"; key: "";}
	Botton { id: "b88"; text: "M"; key: "";}
	Botton { id: "b89"; text: ","; key: "";}
	Botton { id: "b90"; text: "."; key: "";}
	Botton { id: "b91"; text: "/"; key: "";}
	Botton { id: "b92"; text: "Shi"; key: "";}

	/*Botton { id: "b281"; text: "Shi"; key: "";}
	Botton { id: "b82"; text: "z"; key: "";}
	Botton { id: "b83"; text: "x"; key: "";}
	Botton { id: "b84"; text: "c"; key: "";}
	Botton { id: "b85"; text: "v"; key: "";}
	Botton { id: "b86"; text: "b"; key: "";}
	Botton { id: "b87"; text: "n"; key: "";}
	Botton { id: "b88"; text: "m"; key: "";}
	Botton { id: "b89"; text: ","; key: "";}
	Botton { id: "b90"; text: "."; key: "";}
	Botton { id: "b91"; text: "/"; key: "";}
	Botton { id: "b92"; text: "Shi"; key: "";}*/

	Botton { id: "b101"; text: "Ctrl"; key: "";}
	Botton { id: "b102"; text: "Win"; key: "";}
	Botton { id: "b103"; text: "Alt"; key: "";}
	Botton { id: "b104"; text: "Space"; key: ""; relWidth: 9}
	//Botton { id: "b105"; text: "Alt"; key: "";}
	//Botton { id: "b106"; text: "Win"; key: "";}
	//Botton { id: "b107"; text: "Ctrl"; key: "";}
	Botton { id: "b111"; text: "<-"; key: "";}
	Botton { id: "b112"; text: "V"; key: "";}
	Botton { id: "b113"; text: "/\\"; key: "";}
	Botton { id: "b114"; text: "->"; key: "";}

	Botton { id: "b1010"; text: "Brightness"; key: "Brightness"; }

	/*
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	Botton { id: "b"; text: ""; key: "";}
	*/

	Botton { id: "b400"; text: "mouse emulation"; key: "MouseArea"; }
	Botton { id: "b401"; text: "mouse left"; key: "MouseArea"; }
	Botton { id: "b402"; text: "mouse middle"; key: "MouseArea"; }
	Botton { id: "b403"; text: "mouse right"; key: "MouseArea"; }
	Botton { id: "b410"; text: "Home"; key: "";}
	Botton { id: "b411"; text: "End"; key: "";}
	Botton { id: "b412"; text: "Ins"; key: "";}
	Botton { id: "b413"; text: "Del"; key: "";}

	/*Rectangle {
		width: 1280
		height: 256
		border.color: "red"
		border.width: 2
	}*/

	//Component.onCompleted: Util.adjustButtons({
	function onGeometrySet() {
		console.log('geometry set');
		Util.adjustButtons({
			rows:[
				{ h: 2, buttons: [0,1,2,3,4,5,6,7,8,9,10,11,12] },
				{ h: 2, buttons: [221,222,223,224,225,226,227,228,229,230,231,232,233,234] },
				{ h: 2, buttons: [21,22,23,24,25,26,27,28,29,30,31,32,33,34] },
				{ h: 3, title: 'mouse emulation', buttons: [400,401,402,403,410,411,412,413] },
				//{ h: 1, buttons: [241,242,243,244,245,246,247,248,249,250,251,252,253] },
				{ h: 2, buttons: [41,42,43,44,45,46,47,48,49,50,51,52,53] },
				//{ h: 1, buttons: [261,262,263,264,265,266,267,268,269,270,271,272,273,274] },
				{ h: 2, buttons: [61,62,63,64,65,66,67,68,69,70,71,72,73,74] },
				//{ h: 1, buttons: [281,282,283,284,285,286,287,288,289,290,291,292] },
				{ h: 2, buttons: [81,82,83,84,85,86,87,88,89,90,91,92] },
				{ h: 2, buttons: [101,102,103,104,111,112,113,114] },
				{
					h: 3,
					title: 'brightness control',
					buttons: [1010]
				}
			],
			width: root.width,
			height: root.height
		});
	}
	//onResized: console.log(123);
}
