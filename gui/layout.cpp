#include "layout.h"

Layout layNormal {
	"n",
	"Normal",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{"a", "A"},
				},
				{
					{"b", "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{"c", "C"},
				},
				{
					{"d", "D"}
				}
			}
		}
	}
};

Layout layMice = {
	"a",
	"Addon",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{"a", "A"},
					{"a2", "A2"},
				},
				{
					{"b", "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{"c", "C"},
				},
				{
					{"d", "D"}
				}
			}
		}
	}
};

Layout layNumPad = {
	"num",
	"NumPad",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{"a", "A"},
					{"a2", "A2"},
				},
				{
					{"b", "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{"c", "C"},
				},
				{
					{"d", "D"}
				}
			}
		}
	}
};

Layout layOpacity = {
	"o",
	"Opacity",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{"a", "A"},
					{"a2", "A2"},
				},
				{
					{"b", "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{"c", "C"},
				},
				{
					{"d", "D"}
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
