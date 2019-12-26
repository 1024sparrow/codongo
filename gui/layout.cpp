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
	45, // width: 15 * 3
	10, // height
	{ // buttons
		/*00*/{1, { {6,{{KEY_A, "Esc"}}},{3,{{KEY_A, "F1"}}},{3,{{KEY_A, "F2"}}},{3,{{KEY_A, "F3"}}},{5,{{KEY_A, "F4"}}},{3,{{KEY_A, "F5"}}},{3,{{KEY_A, "F6"}}},{3,{{KEY_A, "F7"}}},{5,{{KEY_A, "F8"}}},{3,{{KEY_A, "F9"}}},{3,{{KEY_A, "F10"}}},{3,{{KEY_A, "F11"}}},{3,{{KEY_A, "F12"}}} }},
		/*01*/{1, { {3,{{KEY_A, "~"}}},{3,{{KEY_A, "!"}}},{3,{{KEY_A, "@"}}},{3,{{KEY_A, "#"}}},{3,{{KEY_A, "$"}}},{3,{{KEY_A, "%"}}},{3,{{KEY_A, "^"}}},{3,{{KEY_A, "&"}}},{3,{{KEY_A, "*"}}},{3,{{KEY_A, "("}}},{3,{{KEY_A, ")"}}},{3,{{KEY_A, "_"}}},{3,{{KEY_A, "+"}}},{7,{{KEY_A, "BS"}}} }},
		/*02*/{1, { {3,{{KEY_A, "`"}}},{3,{{KEY_A, "1"}}},{3,{{KEY_A, "2"}}},{3,{{KEY_A, "3"}}},{3,{{KEY_A, "4"}}},{3,{{KEY_A, "5"}}},{3,{{KEY_A, "6"}}},{3,{{KEY_A, "7"}}},{3,{{KEY_A, "8"}}},{3,{{KEY_A, "9"}}},{3,{{KEY_A, "0"}}},{3,{{KEY_A, "-"}}},{3,{{KEY_A, "="}}},{7,{{KEY_A, "-"}}} }},
		/*03*/{1, { {4,{{KEY_A, "Tab"}}},{3,{{KEY_A, "Q"}}},{3,{{KEY_A, "W"}}},{3,{{KEY_A, "E"}}},{3,{{KEY_A, "R"}}},{3,{{KEY_A, "T"}}},{3,{{KEY_A, "Y"}}},{3,{{KEY_A, "U"}}},{3,{{KEY_A, "I"}}},{3,{{KEY_A, "O"}}},{3,{{KEY_A, "P"}}},{3,{{KEY_A, "{"}}},{3,{{KEY_A, "}"}}},{6,{{KEY_A, "NumPad"}}} }},
		/*04*/{1, { {4,{{KEY_A, "-"}}},{3,{{KEY_A, "q"}}},{3,{{KEY_A, "w"}}},{3,{{KEY_A, "e"}}},{3,{{KEY_A, "r"}}},{3,{{KEY_A, "t"}}},{3,{{KEY_A, "y"}}},{3,{{KEY_A, "u"}}},{3,{{KEY_A, "i"}}},{3,{{KEY_A, "o"}}},{3,{{KEY_A, "p"}}},{3,{{KEY_A, "["}}},{3,{{KEY_A, "]"}}},{6,{{KEY_A, "-"}}} }},
		/*05*/{1, { {5,{{KEY_A, "Caps"}}},{3,{{KEY_A, "A"}}},{3,{{KEY_A, "S"}}},{3,{{KEY_A, "D"}}},{3,{{KEY_A, "F"}}},{3,{{KEY_A, "G"}}},{3,{{KEY_A, "H"}}},{3,{{KEY_A, "J"}}},{3,{{KEY_A, "K"}}},{3,{{KEY_A, "L"}}},{3,{{KEY_A, ":"}}},{3,{{KEY_A, "\\\""}}},{3,{{KEY_A, "|"}}},{5,{{KEY_A, "Ent"}}} }},
		/*06*/{1, { {5,{{KEY_A, "-"}}},{3,{{KEY_A, "a"}}},{3,{{KEY_A, "s"}}},{3,{{KEY_A, "d"}}},{3,{{KEY_A, "f"}}},{3,{{KEY_A, "g"}}},{3,{{KEY_A, "h"}}},{3,{{KEY_A, "j"}}},{3,{{KEY_A, "k"}}},{3,{{KEY_A, "l"}}},{3,{{KEY_A, ";"}}},{3,{{KEY_A, "'"}}},{3,{{KEY_A, "\\\\"}}},{5,{{KEY_A, "-"}}} }},
		/*07*/{1, { {6,{{KEY_A, "Sh"}}},{3,{{KEY_A, "Z"}}},{3,{{KEY_A, "X"}}},{3,{{KEY_A, "C"}}},{3,{{KEY_A, "V"}}},{3,{{KEY_A, "B"}}},{3,{{KEY_A, "N"}}},{3,{{KEY_A, "M"}}},{3,{{KEY_A, "<"}}},{3,{{KEY_A, ">"}}},{3,{{KEY_A, "?"}}},{10,{{KEY_A, "Sh"}}} }},
		/*08*/{1, { {6,{{KEY_A, "-"}}},{3,{{KEY_A, "z"}}},{3,{{KEY_A, "x"}}},{3,{{KEY_A, "c"}}},{3,{{KEY_A, "v"}}},{3,{{KEY_A, "b"}}},{3,{{KEY_A, "n"}}},{3,{{KEY_A, "m"}}},{3,{{KEY_A, ","}}},{3,{{KEY_A, "."}}},{3,{{KEY_A, "/"}}},{10,{{KEY_A, "-"}}} }},
		/*09*/ //{1, { {4,{{KEY_A, "Ctrl"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Alt"}}},{10,{{KEY_A, "Space"}}},{3,{{KEY_A, "<-"}}},{3,{{KEY_A, "V"}}},{3,{{KEY_A, "/\\\\"}}},{3,{{KEY_A, "->"}}},{4,{{KEY_A, "Alt"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Ctrl"}}} }}
		/*09*/{1, { {4,{{KEY_A, "Ctrl"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Alt"}}},{22,{{KEY_A, "Space"}}},{4,{{KEY_A, "Alt"}}},{4,{{KEY_A, "Win"}}},{4,{{KEY_A, "Ctrl"}}} }}
		/*10*/ //{1, { {1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}},{1,{{KEY_A, "A"}}} }},
		/*{ // row 0
			1, // height
			{ // cells
				{
					1,
					{
						{KEY_A, "A"},
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
						{KEY_C, "C"},
					}
				},
				{
					1,
					{
						{KEY_D, "D"}
					}
				}
			}
		}*/
	}
};

Layout layMice = {
	"TouchPad",
	2, // width
	4, // height
	{ // buttons
		{ // row 0
			3, // height
			{ // cells
				{
					1,
					{
						{KEY_MOUSE_AREA, "MA"}
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
						{KEY_MOUSE_LB, "LB"}
					}
				},
				{
					1,
					{
						{KEY_MOUSE_RB, "RB"}
					}
				}
			}
		}
	}
};

Layout layNumPad = {
	"NumPad",
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
	layMice,
	layNumPad,
	layOpacity
};
