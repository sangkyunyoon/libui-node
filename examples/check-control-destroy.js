/* eslint-disable unicorn/filename-case */

const libui = require('..');
function createWindow() {
	const win = new libui.UiWindow('UiSpinbox example', 320, 60, true);

	win.margined = true;

	const widget1 = new libui.UiSpinbox();
	widget1.value = 42;
	widget1.onChanged(() => {
		console.log(`widget1 changed to ${widget1.value}`);
	});

	const widget2 = new libui.UiButton('btn1');
	widget2.onClicked(() => {
		console.log(`${widget2.text} clicked`);
	});

	const widget3 = new libui.UiCheckbox('chk1');
	widget3.onToggled(() => {
		console.log(`${widget3.text} toggled`);
	});

	const widget4 = new libui.UiColorButton();
	widget4.onChanged(() => {
		console.log(`widget4 changed to ${widget4.color}`);
	});

	const widget5 = new libui.UiCombobox();
	widget5.append('a');
	widget5.append('b');
	widget5.onSelected(() => {
		console.log(`widget5 changed to ${widget5.selected}`);
	});

	const widget6 = new libui.UiEditableCombobox();
	widget6.onChanged(() => {
		console.log(`widget6 changed to ${widget6.text}`);
	});

	const box = new libui.UiVerticalBox();
	box.append(widget1, true);
	box.append(widget2, true);
	box.append(widget3, true);
	box.append(widget4, true);
	box.append(widget5, true);
	box.append(widget6, true);

	win.setChild(box);

	win.onClosing(() => {
		win.close();
		global.gc();
		libui.stopLoop();
	});

	return win;
}

function op() {
	global.gc();
	const win = createWindow();
	win.show();
	setTimeout(() => {
		win.close();
		op();
	}, 100);
}

libui.startLoop();
op();
