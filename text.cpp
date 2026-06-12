#include "main.h"
#include "driver.h"
#include "text.h"

u8 letter_A[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
};

u8 letter_b[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
};

u8 letter_B[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
};

u8 letter_g[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
};

u8 letter_d[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
};

u8 letter_E[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
};

u8 letter_x[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
};

u8 letter_3[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
};

u8 letter_i[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_ON, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0},
};

u8 letter_K[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
};

u8 letter_l[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_ON, 0},
};

u8 letter_M[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
};

u8 letter_H[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
};

u8 letter_O[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
};

u8 letter_p[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
};

u8 letter_P[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
};

u8 letter_C[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
};

u8 letter_T[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0, 0},
};

u8 letter_y[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
};

u8 letter_f[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_OFF},
};

u8 letter_X[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
};

u8 letter_c[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0},
};

u8 letter_4[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
};

u8 letter_w[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON},
};

u8 letter_s[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_ON},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
};

u8 letter_j[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON, 0},
};

u8 letter_m[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
};

u8 letter_q[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_OFF, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
};

u8 letter_a[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_ON, PIXEL_OFF, 0, 0},
};

u8 letter_u[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_ON, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_OFF, PIXEL_ON},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, PIXEL_ON, PIXEL_ON},
};

u8 letter_r[LETTER_HEIGHT][LETTER_WIDTH] = {
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_OFF, PIXEL_ON, PIXEL_ON, 0, 0},
	{PIXEL_ON, PIXEL_OFF, PIXEL_ON, 0, 0},
};


i8 DisplayLetter(i8 x, i8 y, u8 letter[LETTER_HEIGHT][LETTER_WIDTH]) {
	if (x == -100) {
		i8 width = 0;
		for (i8 i = 0; i < LETTER_WIDTH; i++) {
			if (letter[0][i] == 0) {
				return width;
			}
			else {
				width++;
			}
		}
	}
	i8 letter_width = 0;
	for (i8 i = 0; i < LETTER_HEIGHT; i++) {
		i8 width = 0;
		for (i8 j = 0; j < LETTER_WIDTH; j++) {
			if (letter[i][j] == PIXEL_ON) {
				SetPixel(x + i, y - j);
			}
			else if (letter[i][j] == PIXEL_OFF) {
				ResetPixel(x + i, y - j);
			}
			if (letter[i][j] != 0) {
				width++;
			}
			else {
				letter_width = width;
			}
		}
	}
	if (letter_width == 0){
		letter_width = LETTER_WIDTH;
	}
	return letter_width;
}

i8 PrintLetter(i8 x, i8 y, u8 letter) {
	switch (letter)
	{
	case 'A':
		return DisplayLetter(x, y, letter_A);
	case 'b':
		return DisplayLetter(x, y, letter_b);
	case 'B':
		return DisplayLetter(x, y, letter_B);
	case 'g':
		return DisplayLetter(x, y, letter_g);
	case 'd':
		return DisplayLetter(x, y, letter_d);
	case 'E':
		return DisplayLetter(x, y, letter_E);
	case 'x':
		return DisplayLetter(x, y, letter_x);
	case '3':
		return DisplayLetter(x, y, letter_3);
	case 'i':
		return DisplayLetter(x, y, letter_i);
	case 'K':
		return DisplayLetter(x, y, letter_K);
	case 'l':
		return DisplayLetter(x, y, letter_l);
	case 'M':
		return DisplayLetter(x, y, letter_M);
	case 'H':
		return DisplayLetter(x, y, letter_H);
	case 'O':
		return DisplayLetter(x, y, letter_O);
	case 'p':
		return DisplayLetter(x, y, letter_p);
	case 'P':
		return DisplayLetter(x, y, letter_P);
	case 'C':
		return DisplayLetter(x, y, letter_C);
	case 'T':
		return DisplayLetter(x, y, letter_T);
	case 'y':
		return DisplayLetter(x, y, letter_y);
	case 'f':
		return DisplayLetter(x, y, letter_f);
	case 'X':
		return DisplayLetter(x, y, letter_X);
	case 'c':
		return DisplayLetter(x, y, letter_c);
	case '4':
		return DisplayLetter(x, y, letter_4);
	case 'w':
		return DisplayLetter(x, y, letter_w);
	case 's':
		return DisplayLetter(x, y, letter_s);
	case 'j':
		return DisplayLetter(x, y, letter_j);
	case 'm':
		return DisplayLetter(x, y, letter_m);
	case 'q':
		return DisplayLetter(x, y, letter_q);
	case 'a':
		return DisplayLetter(x, y, letter_a);
	case 'u':
		return DisplayLetter(x, y, letter_u);
	case 'r':
		return DisplayLetter(x, y, letter_r);
	default:
		break;
	}
	return 0;
}

void PrintText(i8 x, i8 y, u8* text, u8 length) {
	u8 add_interval = 0;
	for (u8 i = 0; i < length; i++) {
		add_interval += PrintLetter(x, y - add_interval, text[i]) + 1;
	}
	PrintMatrix(0);
}

u8 CalculateLengthLetter(u8 letter) {
	return PrintLetter(-100, -100, letter);
}

u8 CalculateLengthText(u8* text, u8 length) {
	u8 sum = 0;
	for (u8 i = 0; i < length; i++) {
		sum += CalculateLengthLetter(text[i]) + 1;
	}
	sum -= 1;
	return sum;
}

void PrintTextCentered(i8 x, i8 y, u8* text, u8 length) {
	u8 text_length = CalculateLengthText(text, length);
	PrintText(x, y + text_length / 2 - 1 , text, length);
}

