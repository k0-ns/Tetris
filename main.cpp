#include "main.h"
#include "menu.h"
#include "driver.h"
#include "tetris.h"
#include "text.h"

int main()
{

    while (true)
    {
        ResetMatrix();
        u8 text_str_old[] = "AbBgdEx3iKlMHOpPCTYfXc4wsjmqaur";
        u8 text_str[] = "TETPiC";
        u8* text = &text_str[0];
        SetPixel(0, 0);
        PrintTextCentered(1, HEIGHT / 2 , text, 6);
        //Tetris();
        DebugPoint();
    }
}