#include "main.h"
#include "driver.h"
#include "start.h"
#include "text.h"
#include "tetris.h"
#include "brightness.h"

u8 current_menu_item = 0;
u8 reset_button_lock = 0;

u8 IsMenuLeft() {
    return IsButton(1);
}

u8 IsMenuRight() {
    return IsButton(4);
}

u8 IsMenuSelected() {
    return IsButton(5);
}

u8 IsMenuReset() {
    return IsButton(6) || IsButton(3);
}

void MenuTransition(u8* old_pointer_to_str, u8 old_length, u8* new_pointer_to_str, u8 new_length, u8 direction) {
    ResetMatrix();
    for (i8 i = 0; i < HEIGHT; i++) {
        u8 multiplyer = 1;
        if (direction == LEFT) {
            multiplyer = -1;
        }
        ResetMatrix();
        PrintTextCentered(1, HEIGHT / 2 - 1 + i * multiplyer, old_pointer_to_str, old_length);
        PrintTextCentered(1, HEIGHT / 2 - 1 + (i - HEIGHT) * multiplyer, new_pointer_to_str, new_length);
        PrintMatrix(0);
    }
}

void ResetTransition(u8* old_pointer_to_str, u8 old_length, u8* new_pointer_to_str, u8 new_length) {
    ResetMatrix();
    for (i8 i = 0; i < WIDTH; i++) {
        ResetMatrix();
        PrintTextCentered(1 - i, HEIGHT / 2 - 1, old_pointer_to_str, old_length);
        PrintTextCentered(1 + WIDTH - i, HEIGHT / 2 - 1, new_pointer_to_str, new_length);
        PrintMatrix(0);
    }
}


void DrawMenuArrowRight() {
    i8 base_x = WIDTH / 2;
    i8 base_y = 0;

    SetPixel(base_x - 1, base_y + 1);
    SetPixel(base_x, base_y);
    SetPixel(base_x + 1, base_y + 1);
}

void DrawMenuArrowLeft() {
    i8 base_x = WIDTH / 2;
    i8 base_y = HEIGHT - 1;

    SetPixel(base_x - 1, base_y - 1);
    SetPixel(base_x, base_y);
    SetPixel(base_x + 1, base_y - 1);
}

void DrawFooter(u8 is_blink) {
    i8 base_y = HEIGHT / 2 - 2 + TOTAL_MENU_ITEMS * 2;
    for (i8 i = 0; i < TOTAL_MENU_ITEMS * 4; i += 4) {
        if (is_blink && i / 4 == current_menu_item) {
            continue;
        }
        SetPixel(7, base_y - i - 1);
        SetPixel(7, base_y - i);
    }
}

u8 IsMostLeft() {
    return current_menu_item == TETRIS ? 1 : 0;
}

u8 IsMostRight() {
    return current_menu_item == TEST2 ? 1 : 0;
}


u8 Menu() {
    u8 tetris_str[] = "TETPiC";
    u8 brightness_str[] = "rPKCTq";
    u8 test_str[] = "TECT";
    u8 default_str[] = "AXYEl";
    u8* pointer_to_str = &default_str[0];
    u8 length = 5;
    i8 is_changed = 0;
    i8 footer_timer = 0;
    i8 is_blink = 0;
    while (1) {
        switch (current_menu_item) {
        case TETRIS:
            pointer_to_str = &tetris_str[0];
            length = 6;
            break;
        case BRIGHTNESS:
            pointer_to_str = &brightness_str[0];
            length = 6;
            break;
        case TEST:
            pointer_to_str = &test_str[0];
            length = 4;
            break;
        case TEST2:
            pointer_to_str = &test_str[0];
            length = 4;
            break;
        }
        ResetMatrix();
        PrintTextCentered(1, HEIGHT / 2 - 1, pointer_to_str, length);
        if (footer_timer > FOOTER_TIMER_TICKS) {
            is_blink = !is_blink;
            footer_timer = 0;
        }
        footer_timer++;
        DrawFooter(is_blink);
        if (!IsMostRight()) {
            DrawMenuArrowRight();
        }
        if (!IsMostLeft()) {
            DrawMenuArrowLeft();
        }
        if (IsMenuLeft() && !IsMostLeft()) {
            current_menu_item--;
            is_changed = -1;
        }
        if (IsMenuRight() && !IsMostRight()) {
            current_menu_item++;
            is_changed = 1;
        }
        if (is_changed != 0) {
            u8* new_pointer_to_str = &default_str[0];
            u8 new_length = 5;
            u8 direction = RIGHT;
            if (is_changed == -1) {
                direction = LEFT;
            }
            switch (current_menu_item) {
            case TETRIS:
                new_pointer_to_str = &tetris_str[0];
                new_length = 6;
                break;
            case BRIGHTNESS:
                new_pointer_to_str = &brightness_str[0];
                new_length = 6;
                break;
            case TEST:
                new_pointer_to_str = &test_str[0];
                new_length = 4;
                break;
            case TEST2:
                new_pointer_to_str = &test_str[0];
                new_length = 4;
                break;
            }
            MenuTransition(pointer_to_str, length, new_pointer_to_str, new_length, direction);
            is_changed = 0;
            ResetMatrix();
            PrintTextCentered(1, HEIGHT / 2 - 1, new_pointer_to_str, new_length);
        }
        PrintMatrix(0);
        if (IsMenuReset() && !reset_button_lock) {
            current_menu_item = 0;
            u8* new_pointer_to_str = &tetris_str[0];
            u8 new_length = 6;
            ResetTransition(pointer_to_str, length, new_pointer_to_str, new_length);
            reset_button_lock = 1;
        }
        if (!IsMenuReset()) {
            reset_button_lock = 0;
        }
        if (IsMenuSelected()) {
            return current_menu_item;
        }
    }
}

void Start() {
    ResetMatrix();
    //u8 text_str_old[] = "AbBgdEx3iKlMHOpPCTYfXc4wsjmqaur";
    u8 menu_item = Menu();
    switch (menu_item) {
    case TETRIS:
        Tetris();
        break;
    case BRIGHTNESS:
        Brightness();
        break;
    }
    reset_button_lock = 1;
    //DebugPoint();

}
