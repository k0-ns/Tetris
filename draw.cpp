#include "main.h"
#include "driver.h"
#include "draw.h"

u8 IsMoveDrawLeft() {
	return IsButton(1);
}

u8 IsMoveDrawUp() {
	return IsButton(2);
}

u8 IsMoveDrawDown() {
	return IsButton(3);
}

u8 IsMoveDrawRight() {
	return IsButton(4);
}

u8 IsDraw() {
	return IsButton(5);
}

u8 IsQuitDraw() {
	return IsButton(6);
}

void DrawDrawer(u8 is_blink, i8 draw_x, i8 draw_y) {
	if (!is_blink) {
		SetPixel(draw_x, draw_y);
	}
	else{
		ResetPixel(draw_x, draw_y);
	}
}

void Draw() {
	i8 draw_x = 0;
	i8 draw_y = HEIGHT - 1;
	i8 blink_timer = 0;
	i8 is_blink = 0;
	u8 ticks_move_draw = 0;
	u8 ticks_draw = 1;
	ResetMatrix();
	while (1) {
		if (blink_timer > DRAW_TIMER_TICKS) {
			is_blink = !is_blink;
			blink_timer = 0;
		}
		blink_timer++;
		u8 pixel_state = GetPixel(draw_x, draw_y);
		if (pixel_state == PIXEL_ON) {
			DrawDrawer(!is_blink, draw_x, draw_y);
		}
		else {
			DrawDrawer(is_blink, draw_x, draw_y);
		}
		PrintMatrix(0);
		if (IsDraw()) {
			if (ticks_draw == 0) {
				if (pixel_state == PIXEL_ON) {
					pixel_state = PIXEL_OFF;
				}
				else {
					pixel_state = PIXEL_ON;
				}
				ticks_draw = 1;
			}
		}
		else {
			ticks_draw = 0;
		}
		if (pixel_state == PIXEL_ON) {
			SetPixel(draw_x, draw_y);
		}
		else {
			ResetPixel(draw_x, draw_y);
		}
		if (IsMoveDrawDown() && draw_x < WIDTH - 1) {
			if (ticks_move_draw == 0 || (ticks_move_draw > DRAW_HOLD_DELAY)) {
				draw_x++;
				ticks_draw = 0;
				blink_timer = 0;
				is_blink = 0;
			}
			ticks_move_draw++;
		}
		else if (IsMoveDrawUp() && draw_x > 0) {
			if (ticks_move_draw == 0 || (ticks_move_draw > DRAW_HOLD_DELAY)) {
				draw_x--;
				ticks_draw = 0;
				blink_timer = 0;
				is_blink = 0;
			}
			ticks_move_draw++;
		}
		else if (IsMoveDrawRight() && draw_y > 0) {
			if (ticks_move_draw == 0 || (ticks_move_draw > DRAW_HOLD_DELAY)) {
				draw_y--;
				ticks_draw = 0;
				blink_timer = 0;
				is_blink = 0;
			}
			ticks_move_draw++;
		}
		else if (IsMoveDrawLeft() && draw_y < HEIGHT - 1) {
			if (ticks_move_draw == 0 || (ticks_move_draw > DRAW_HOLD_DELAY)) {
				draw_y++;
				ticks_draw = 0;
				blink_timer = 0;
				is_blink = 0;
			}
			ticks_move_draw++;
		}
		else {
			ticks_move_draw = 0;
		}
		
		if (ticks_move_draw > DRAW_HOLD_DELAY) {
			ticks_move_draw = DRAW_HOLD_DELAY + 1;
		}
		if (IsQuitDraw()) {
			return;
		}
	}
}
