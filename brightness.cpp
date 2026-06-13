#include "main.h"
#include "driver.h"
#include "brightness.h"

u8 brightness = DEFAULT_BRIGHTNESS;

u8 IsIncreaseBrightness() {
	return IsButton(4);
}
u8 IsDecreaseBrightness() {
	return IsButton(1);
}
u8 IsBrightnessSelected() {
	return IsButton(6);
}

void Brightness() {
	i8 base_y = HEIGHT - 9;
	u8 ticks_move_brightness = 0;
	while (1) {
		ResetMatrix();
		SetPixel(2, base_y);
		SetPixel(3, base_y + 1);
		SetPixel(4, base_y + 1);
		SetPixel(5, base_y);
		SetPixel(2, base_y - MAX_BRIGHTNESS);
		SetPixel(3, base_y - 1 - MAX_BRIGHTNESS);
		SetPixel(4, base_y - 1 - MAX_BRIGHTNESS);
		SetPixel(5, base_y - MAX_BRIGHTNESS);
		for (i8 i = 1; i < MAX_BRIGHTNESS; i++) {
			if (i < brightness) {
				SetPixel(3, base_y - i);
				SetPixel(4, base_y - i);
			}
			SetPixel(1, base_y - i);
			SetPixel(6, base_y - i);
		}
		if (IsIncreaseBrightness() && brightness < MAX_BRIGHTNESS) {
			if (ticks_move_brightness == 0 || (ticks_move_brightness > BRIGHTNESS_HOLD_DELAY)) {
				brightness++;
				SetBrightness(brightness);
			}
			ticks_move_brightness++;
		}
		else if (IsDecreaseBrightness() && brightness > 1) {
			if (ticks_move_brightness == 0 || (ticks_move_brightness > BRIGHTNESS_HOLD_DELAY)) {
				brightness--;
				SetBrightness(brightness);
			}
			ticks_move_brightness++;
		}
		else {
			ticks_move_brightness = 0;
		}
		if (ticks_move_brightness > BRIGHTNESS_HOLD_DELAY) {
			ticks_move_brightness = BRIGHTNESS_HOLD_DELAY + 1;
		}
		if (IsBrightnessSelected()) {
			return;
		}

		PrintMatrix(0);
	}
}

