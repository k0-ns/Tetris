#include "main.h"
#include "driver.h"

u8 matrix[HEIGHT][WIDTH];
u16 p_rand = 0;

using namespace std;

u8 IsButton(u8 num) {
	u8 result = 0;
	switch (num) {
	case 1:
		result = (GetKeyState(BUTTON_1) & 0x8000) ? 1 : 0;
		break;
	case 2:
		result = (GetKeyState(BUTTON_2) & 0x8000) ? 1 : 0;
		break;
	case 3:
		result = (GetKeyState(BUTTON_3) & 0x8000) ? 1 : 0;
		break;
	case 4:
		result = (GetKeyState(BUTTON_4) & 0x8000) ? 1 : 0;
		break;
	case 5:
		result = (GetKeyState(BUTTON_5) & 0x8000) ? 1 : 0;
		break;
	case 6:
		result = (GetKeyState(BUTTON_6) & 0x8000) ? 1 : 0;
		break;
	}
	return result;
}


u8 RandomGen(u8 min, u8 max) {
	max++;
	return (p_rand % (max - min) + min);
}

void ResetMatrix() {
	for (u8 i = 0; i < HEIGHT; i++) {
		for (u8 j = 0; j < WIDTH; j++) {
			matrix[i][j] = PIXEL_OFF;
		}
	}
}

void PrintMatrix(u8 is_upside_down) {
	system("cls");

	cout << '/';
	for (u8 i = 0; i < HEIGHT + 6; i++) {
		cout << '-';
	}
	cout << '\\' << endl;

	cout << "|  " << '/';
	for (u8 i = 0; i < HEIGHT; i++) {
		cout << '-';
	}

	cout << '\\' << "  |" << endl;
	if (is_upside_down == 0) {
		for (u8 j = 0; j < WIDTH; j++) {
			cout << "|  "  << '|';
			for (i8 i = HEIGHT - 1; i >= 0; i--) {
				cout << matrix[i][j];
			}
			cout << '|' << "  |" << endl;
		}
	}
	else {
		for (i8 j = WIDTH - 1; j >= 0; j--) {
			cout << "|  " << '|';
			for (i8 i = 0; i < HEIGHT; i++) {
				cout << matrix[i][j];
			}
			cout << '|' << "  |" << endl;
		}
	}

	cout << "|  " << '\\';
	for (u8 i = 0; i < HEIGHT; i++) {
		cout << '-';
	}

	cout << '/' << "  |" << endl;
	for (i8 j = 0; j < 3; j++) {
		cout << '|';
		for (u8 i = 0; i < HEIGHT + 6; i++) {
			if (i == 5 && j == 0) {
				cout << (IsButton(2) ? '#' : '.');
				continue;
			}
			if (i == 3 && j == 1) {
				cout << (IsButton(1) ? '#' : '.');
				continue;
			}
			if (i == 7 && j == 1) {
				cout << (IsButton(4) ? '#' : '.');
				continue;
			}
			if (i == 5 && j == 2) {
				cout << (IsButton(3) ? '#' : '.');
				continue;
			}
			if (i == 25 && j == 2) {
				cout << (IsButton(5) ? '#' : '.');
				continue;
			}
			if (i == 29 && j == 1) {
				cout << (IsButton(6) ? '#' : '.');
				continue;
			}
			cout << ' ';
		}
		cout << '|' << endl;
	}
	cout << '\\';
	for (u8 i = 0; i < HEIGHT + 6; i++) {
		cout << '-';
	}
	cout << '/' << endl;
		p_rand++;
}

u8 GetPixel(i8 x, i8 y) {
	if (x < 0 || x >= WIDTH) return PIXEL_ON;
	if (y < 0) return PIXEL_OFF;
	if (y >= HEIGHT) return PIXEL_ON;

	return matrix[y][x];
}


void SetPixel(i8 x, i8 y) {
	if (x < 0 || x >= WIDTH) return;
	if (y < 0 || y >= HEIGHT) return;

	matrix[y][x] = PIXEL_ON;
}

void ResetPixel(i8 x, i8 y) {
	if (x < 0 || x >= WIDTH) return;
	if (y < 0 || y >= HEIGHT) return;

	matrix[y][x] = PIXEL_OFF;
}

u8 TogglePixel(i8 x, i8 y) {
	if (x < 0 || x >= WIDTH) return 0;
	if (y < 0 || y >= HEIGHT) return 0;

	if (matrix[y][x] == PIXEL_ON) {
		matrix[y][x] = PIXEL_OFF;
	}
	else {
		matrix[y][x] = PIXEL_ON;
	}
	return 0;
}

void SetPixelInvis(i8 x, i8 y) {
	if (x < 0 || x >= WIDTH) return;
	if (y < 0 || y >= HEIGHT) return;

	matrix[y][x] = PIXEL_INVIS;
}

void DebugPoint() {
	for (u8 i = 0; i < 10; i++) {
		cout << '!';
		SleepMs(200);
	}
}

void SleepMs(u16 ms) {
	Sleep(ms);
}

