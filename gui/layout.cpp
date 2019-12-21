#include "layout.h"

Layout layNormal {
	"Normal",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{KEY_A, "A"},
				},
				{
					{KEY_B, "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{KEY_C, "C"},
				},
				{
					{KEY_D, "D"}
				}
			}
		}
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
					{KEY_MOUSE_AREA, "MA"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{KEY_MOUSE_LB, "LB"},
				},
				{
					{KEY_MOUSE_RB, "RB"}
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
					{KEY_A, "A"},
					{KEY_A2, "A2"},
				},
				{
					{KEY_B, "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{KEY_C, "C"},
				},
				{
					{KEY_D, "D"}
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
					{KEY_A, "A"},
					{KEY_A2, "A2"},
				},
				{
					{KEY_B, "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{KEY_C, "C"},
				},
				{
					{KEY_D, "D"}
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
