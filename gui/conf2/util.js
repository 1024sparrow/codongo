var buttons = []

/*function adjustButtons(p_ids){
	let x = 0;
	for (const o of p_ids)
	{
		let item = this[`b${o}`];
		item.x = x;
		x += item.width;
	}
}*/

function adjustButtons(p_o){
	// 1280x1024
	//let W = 1200, H = 1024 - 12;
	let W = p_o.width, H = p_o.height;
	//W /= 2; H /= 2;

	const margin = 4; // расстояние между кнопками

	//let rowHeight = H / p_o.rows.length;//root.height;
	//console.log(rowHeight);
	let
		x = 0,
		y = 0,
		maxButtonCount
	;
	let rowsRelHeight = 0;
	for (const oRow of p_o.rows){
		rowsRelHeight += oRow.h;
	}
	const hRowCoef = (H - p_o.rows.length * margin) / rowsRelHeight;
	for (const oRow of p_o.rows){
		const hRow = oRow.h * hRowCoef;
		if (oRow.buttons){
			let rowRelWidth = 0, buttonCount = 0, wButton;
			for (const oButton of oRow.buttons){
				let item = this[`b${oButton}`];
				rowRelWidth += item.relWidth + item.leftMargin
				++buttonCount;
			}
			wButton = (W - buttonCount * margin) / rowRelWidth; // ширина единицы длины кнопки
			x = 0;
			for (const oButton of oRow.buttons){
				let item = this[`b${oButton}`];
				item.width = wButton * item.relWidth;
				item.height = hRow;
				item.x = x;
				item.y = y;
				x += item.width + margin;
			}
		}
		y += hRow + margin;
	}
}
