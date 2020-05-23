#include "layout.h"

Layout layNormal {
	"Normal",
/*
Esc,
!
1
Q
q
A
a
Z
z
Alt
*/
	48, // width: 16 * 3
	18, // height: 2, 1+2, 1+2, 1+2, 1+2, 4
//	{ // buttons
//		{2, { {6,{{KEY_A, "Esc"}}},{3,{{KEY_A, "F1"}}},{3,{{KEY_A, "F2"}}},{3,{{KEY_A, "F3"}}},{5,{{KEY_A, "F4"}}},{3,{{KEY_A, "F5"}}},{3,{{KEY_A, "F6"}}},{3,{{KEY_A, "F7"}}},{5,{{KEY_A, "F8"}}},{3,{{KEY_A, "F9"}}},{3,{{KEY_A, "F10"}}},{3,{{KEY_A, "F11"}}},{3,{{KEY_A, "F12"}}} }}, // 00
//		{3, { {3,{{KEY_A, "~"},{KEY_A, "`"}}},{3,{{KEY_A, "!"},{KEY_A,"1"}}},{3,{{KEY_A, "@"},{KEY_A,"2"}}},{3,{{KEY_A, "#"},{KEY_A,"3"}}},{3,{{KEY_A, "$"},{KEY_A,"4"}}},{3,{{KEY_A, "%"},{KEY_A,"5"}}},{3,{{KEY_A, "^"},{KEY_A,"6"}}},{3,{{KEY_A, "&"},{KEY_A,"7"}}},{3,{{KEY_A, "*"},{KEY_A,"8"}}},{3,{{KEY_A, "("},{KEY_A,"9"}}},{3,{{KEY_A, ")"},{KEY_A,"0"}}},{3,{{KEY_A, "_"},{KEY_A,"-"}}},{3,{{KEY_A, "+"},{KEY_A,"="}}},{7,{{KEY_A, "BS"}}} }}, // 01
//		{3, { {4,{{KEY_A, "Tab"}}},{3,{{KEY_A, "Q"},{KEY_A,"q"}}},{3,{{KEY_A, "W"},{KEY_A,"w"}}},{3,{{KEY_A, "E"},{KEY_A,"e"}}},{3,{{KEY_A, "R"},{KEY_A,"r"}}},{3,{{KEY_A, "T"},{KEY_A,"t"}}},{3,{{KEY_A, "Y"},{KEY_A,"y"}}},{3,{{KEY_A, "U"},{KEY_A,"u"}}},{3,{{KEY_A, "I"},{KEY_A,"i"}}},{3,{{KEY_A, "O"},{KEY_A,"o"}}},{3,{{KEY_A, "P"},{KEY_A,"p"}}},{3,{{KEY_A, "{"},{KEY_A,"["}}},{3,{{KEY_A, "}"},{KEY_A,"]"}}},{6,{{KEY_A, "NumPad"}}} }}, // 03
//		{3, { {5,{{KEY_A, "Caps"}}},{3,{{KEY_A, "A"},{KEY_A,"a"}}},{3,{{KEY_A, "S"},{KEY_A,"s"}}},{3,{{KEY_A, "D"},{KEY_A,"d"}}},{3,{{KEY_A, "F"},{KEY_A,"f"}}},{3,{{KEY_A, "G"},{KEY_A,"g"}}},{3,{{KEY_A, "H"},{KEY_A,"h"}}},{3,{{KEY_A, "J"},{KEY_A,"j"}}},{3,{{KEY_A, "K"},{KEY_A,"k"}}},{3,{{KEY_A, "L"},{KEY_A,"l"}}},{3,{{KEY_A, ":"},{KEY_A,";"}}},{3,{{KEY_A, "\\\""},{KEY_A,"'"}}},{3,{{KEY_A, "|"},{KEY_A,"\\\\"}}},{5,{{KEY_A, "Ent"}}} }}, // 05
//		{3, { {6,{{KEY_A, "Sh"}}},{3,{{KEY_A, "Z"},{KEY_A,"z"}}},{3,{{KEY_A, "X"},{KEY_A,"x"}}},{3,{{KEY_A, "C"},{KEY_A,"c"}}},{3,{{KEY_A, "V"},{KEY_A,"v"}}},{3,{{KEY_A, "B"},{KEY_A,"b"}}},{3,{{KEY_A, "N"},{KEY_A,"n"}}},{3,{{KEY_A, "M"},{KEY_A,"m"}}},{3,{{KEY_A, "<"},{KEY_A,","}}},{3,{{KEY_A, ">"},{KEY_A,"."}}},{3,{{KEY_A, "?"},{KEY_A,"/"}}},{10,{{KEY_A, "Sh"}}} }}, // 07
//		{2, { {4,{{KEY_A, "Ctrl"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Alt"}}},{22,{{KEY_A, "Space"}}},{4,{{KEY_A, "Alt"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Ctrl"}}} }} // 09
//	}

//	{ // buttons
//		{2, { {7,{{KEY_A, "Esc"}}},{3,{{KEY_A, "F1"}}},{3,{{KEY_A, "F2"}}},{3,{{KEY_A, "F3"}}},{4,{{KEY_A, "F4"}}},{3,{{KEY_A, "F5"}}},{3,{{KEY_A, "F6"}}},{3,{{KEY_A, "F7"}}},{4,{{KEY_A, "F8"}}},{3,{{KEY_A, "F9"}}},{3,{{KEY_A, "F10"}}},{3,{{KEY_A, "F11"}}},{3,{{KEY_A, "F12"}}} }}, // 00
//		{3, { {3,{{KEY_A, "` ~"}}},{3,{{KEY_A,"1 !"}}},{3,{{KEY_A, "2 @"}}},{3,{{KEY_A, "3 #"}}},{3,{{KEY_A, "4 $"}}},{3,{{KEY_A, "5 %"}}},{3,{{KEY_A, "6 ^"}}},{3,{{KEY_A, "7 &"}}},{3,{{KEY_A, "8 *"}}},{3,{{KEY_A, "9 ("}}},{3,{{KEY_A, "0 )"}}},{3,{{KEY_A, "- _"}}},{3,{{KEY_A, "= +"}}},{6,{{KEY_A, "BS"}}} }}, // 01
//		{3, { {4,{{KEY_A, "Tab"}}},{3,{{KEY_A, "Q"}}},{3,{{KEY_A, "W"}}},{3,{{KEY_A, "E"}}},{3,{{KEY_A, "R"}}},{3,{{KEY_A, "T"}}},{3,{{KEY_A, "Y"}}},{3,{{KEY_A, "U"}}},{3,{{KEY_A, "I"}}},{3,{{KEY_A, "O"}}},{3,{{KEY_A, "P"}}},{3,{{KEY_A, "[ {"}}},{3,{{KEY_A, "] }"}}},{5,{{KEY_A, "NumPad"}}} }}, // 03
//		{3, { {5,{{KEY_A, "Caps"}}},{3,{{KEY_A, "A"}}},{3,{{KEY_A, "S"}}},{3,{{KEY_A, "D"}}},{3,{{KEY_A, "F"}}},{3,{{KEY_A, "G"}}},{3,{{KEY_A, "H"}}},{3,{{KEY_A, "J"}}},{3,{{KEY_A, "K"}}},{3,{{KEY_A, "L"}}},{3,{{KEY_A, ": ;"}}},{3,{{KEY_A, "' \\\""}}},{3,{{KEY_A, "\\\\ |"}}},{4,{{KEY_A, "Ent"}}} }}, // 05
//		{3, { {6,{{KEY_A, "Sh"}}},{3,{{KEY_A, "Z"}}},{3,{{KEY_A, "X"}}},{3,{{KEY_A, "C"}}},{3,{{KEY_A, "V"}}},{3,{{KEY_A, "B"}}},{3,{{KEY_A, "N"}}},{3,{{KEY_A, "M"}}},{3,{{KEY_A, ", <"}}},{3,{{KEY_A, ". >"}}},{3,{{KEY_A, "/ ?"}}},{9,{{KEY_A, "Sh"}}} }}, // 07
//		{2, { {4,{{KEY_A, "Ctrl"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Alt"}}},{22,{{KEY_A, "Space"}}},{4,{{KEY_A, "Alt"}}},{4,{{KEY_A, "Win"}}},{3,{{KEY_A, "Ctrl"}}} }} // 09
//	}

	{ // buttons
		{2, {
			{3,{{KEY_A, "Esc"}}},
			{3,{{KEY_A, "F1"}}},
			{3,{{KEY_A, "F2"}}},
			{3,{{KEY_A, "F3"}}},
			{3,{{KEY_A, "F4"}}},
			{3,{{KEY_A, "F5"}}},
			{3,{{KEY_A, "F6"}}},
			{3,{{KEY_A, "F7"}}},
			{3,{{KEY_A, "F8"}}},
			{3,{{KEY_A, "F9"}}},
			{3,{{KEY_A, "F10"}}},
			{3,{{KEY_A, "F11"}}},
			{3,{{KEY_A, "F12"}}},
			{3,{{KEY_A, "PrtSc"}}},
			//{2,{{KEY_A, "Pause"}}},
			{3,{{KEY_A, "Ins"}}},
			{3,{{KEY_A, "Del"}}}
		}}, // 00
		{3, {
			{3,{{KEY_A, "` ~"}}},
			{3,{{KEY_A,"1 !"}}},
			{3,{{KEY_A, "2 @"}}},
			{3,{{KEY_A, "3 #"}}},
			{3,{{KEY_A, "4 $"}}},
			{3,{{KEY_A, "5 %"}}},
			{3,{{KEY_A, "6 ^"}}},
			{3,{{KEY_A, "7 &"}}},
			{3,{{KEY_A, "8 *"}}},
			{3,{{KEY_A, "9 ("}}},
			{3,{{KEY_A, "0 )"}}},
			{3,{{KEY_A, "- _"}}},
			{3,{{KEY_A, "= +"}}},
			{6,{{KEY_A, "BS"}}},
			{3,{{KEY_A, "Home"}}}
		}}, // 01
		{3, {
			{4,{{KEY_A, "Tab"}}},
			{3,{{KEY_A, "Q"}}},
			{3,{{KEY_A, "W"}}},
			{3,{{KEY_A, "E"}}},
			{3,{{KEY_A, "R"}}},
			{3,{{KEY_A, "T"}}},
			{3,{{KEY_A, "Y"}}},
			{3,{{KEY_A, "U"}}},
			{3,{{KEY_A, "I"}}},
			{3,{{KEY_A, "O"}}},
			{3,{{KEY_A, "P"}}},
			{3,{{KEY_A, "[ {"}}},
			{3,{{KEY_A, "] }"}}},
			{5,{{KEY_A, "\\\\ |"}}},
			{3,{{KEY_A, "PgUp"}}}
		}}, // 03
		{3, {
			{5,{{KEY_A, "Caps"}}},
			{3,{{KEY_A, "A"}}},
			{3,{{KEY_A, "S"}}},
			{3,{{KEY_A, "D"}}},
			{3,{{KEY_A, "F"}}},
			{3,{{KEY_A, "G"}}},
			{3,{{KEY_A, "H"}}},
			{3,{{KEY_A, "J"}}},
			{3,{{KEY_A, "K"}}},
			{3,{{KEY_A, "L"}}},
			{3,{{KEY_A, ": ;"}}},
			{3,{{KEY_A, "' \\\""}}},
			{7,{{KEY_A, "Ent"}}},
			{3,{{KEY_A, "PgDn"}}}
		}}, // 05
		{3, {
			{6,{{KEY_A, "Sh"}}},
			{3,{{KEY_A, "Z"}}},
			{3,{{KEY_A, "X"}}},
			{3,{{KEY_A, "C"}}},
			{3,{{KEY_A, "V"}}},
			{3,{{KEY_A, "B"}}},
			{3,{{KEY_A, "N"}}},
			{3,{{KEY_A, "M"}}},
			{3,{{KEY_A, ", <"}}},
			{3,{{KEY_A, ". >"}}},
			{3,{{KEY_A, "/ ?"}}},
			{9,{{KEY_A, "Sh"}}},
			{3,{{KEY_A, "End"}}}
		}}, // 07
		{4, {
			{4,{{KEY_A, "Ctrl"}}},
			{4,{{KEY_A, "Win"}}},
			{4,{{KEY_A, "Alt"}}},
			{16,{{KEY_A, "Space"}}},
			{4,{{KEY_A, "Alt"}}},
			{4,{{KEY_A, "Win"}}},
			{3,{{KEY_A, "Ctrl"}}},
			{3,{{KEY_A, "<-"}}},
			{3,{{KEY_A, "Up"},{KEY_A, "Down"}}},
			{3,{{KEY_A, "->"}}},
		}} // 09
	}
};

Layout layNumPad = {
	"TouchPad",
	12, // width
	6, // height
	{ // buttons
		{ // row 0
			5,
			{ // cells
				{
					9,
					{
						{KEY_A, "TouchPad"}
					}
				},
				{
					1,
					{
						{KEY_A, "PS"},{KEY_A, "Ins"},{KEY_A, "Del"},{KEY_A,"-"},{KEY_A,"-"}
					}
				},
				{
					1,
					{
						{KEY_A, "SL"},{KEY_A, "Home"},{KEY_A, "End"},{KEY_A,"-"},{KEY_A,"/\\\\"}
					}
				},
				{
					1,
					{
						{KEY_A, "P/B"},{KEY_A, "PU"},{KEY_A, "PD"},{KEY_A,"-"},{KEY_A,"-"}
					}
				}
			}
		},
		{ // row 1
			1,
			{ // cells
				{
					3,
					{{KEY_A,"MouseLeft"}}
				},
				{
					3,
					{{KEY_A,"MouseMiddle"}}
				},
				{
					3,
					{{KEY_A,"MouseRight"}}
				},
				{
					1,
					{{KEY_A,"<-"}}
				},
				{
					1,
					{{KEY_A,"V"}}
				},
				{
					1,
					{{KEY_A,"->"}}
				}
			}
		}
	}
};


Layout layOpacity = {
	"Opacity",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					1,
					{
						{KEY_A, "A"},
						{KEY_A2, "A2"}
					}
				},
				{
					1,
					{
						{KEY_B, "B"}
					}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					1,
					{
						{KEY_C, "C"}
					}
				},
				{
					1,
					{
						{KEY_D, "D"}
					}
				}
			}
		}
	}
};

Layout LAYOUTS[LAYOUT__COUNT] {
	layNormal,
//	layNumPad,
	//layOpacity
};
