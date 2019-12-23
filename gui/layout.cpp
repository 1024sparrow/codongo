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
