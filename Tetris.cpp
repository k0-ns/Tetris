#include "main.h"
#include "driver.h"
#include "tetris.h"


struct item_t item;
u8 timer = 0;
u8 ticks_for_move = 30;
u16 ticks_left = 0;
u16 ticks_right = 0;
u16 ticks_rotate = 0;
u16 ticks_drop = 0;
u16 ticks_upside_down = 0;
u8 is_end = 0;
u8 is_upside_down = 0;

i8 L_FRONT[AMOUNT_OF_ADJ][2] = { {N,U},{N,D},{R,D} };
i8 L_BACK[AMOUNT_OF_ADJ][2] = { {N,U},{N,D},{L,D} };
i8 SQUARE[AMOUNT_OF_ADJ][2] = { {N,U},{R,U},{R,N} };
i8 LINE[AMOUNT_OF_ADJ][2] = { {N,U},{N,D},{N,UU} };
i8 Z[AMOUNT_OF_ADJ][2] = { {N,U},{L,U},{R,N} };
i8 Z_BACK[AMOUNT_OF_ADJ][2] = { {N,U},{L,N},{R,U} };
i8 T[AMOUNT_OF_ADJ][2] = { {N,U},{L,N},{R,N} };
i8 PENIS[AMOUNT_OF_ADJ][2] = { {N,U},{L,D},{R,D} };


void CopyItem(i8 item_rotated[AMOUNT_OF_ADJ][2], i8 copyable_item[AMOUNT_OF_ADJ][2]) {
    for (int i = 0; i < AMOUNT_OF_ADJ; i++) {
        item_rotated[i][0] = copyable_item[i][0];
        item_rotated[i][1] = copyable_item[i][1];
    }
}

void FillItem(i8 item_rotated[AMOUNT_OF_ADJ][2]) {
    switch (item.type)
    {
    case ITEM_L_FRONT:
        CopyItem(item_rotated, L_FRONT);
        break;
    case ITEM_L_BACK:
        CopyItem(item_rotated, L_BACK);
        break;
    case ITEM_SQUARE:
        CopyItem(item_rotated, SQUARE);
        break;
    case ITEM_LINE:
        CopyItem(item_rotated, LINE);
        break;
    case ITEM_Z:
        CopyItem(item_rotated, Z);
        break;
    case ITEM_Z_BACK:
        CopyItem(item_rotated, Z_BACK);
        break;
    case ITEM_T:
        CopyItem(item_rotated, T);
        break;
    case ITEM_PENIS:
        CopyItem(item_rotated, PENIS);
        break;
    }
}

void CheckPosition(u8* value, u8(*Function)(i8, i8)) {
    i8 x = item.x;
    i8 y = item.y;
    *value &= Function(x, y);
    i8 item_rotated[AMOUNT_OF_ADJ][2];
    FillItem(item_rotated);
    for (int i = 0; i < item.rotation; i++) {
        for (int i = 0; i < AMOUNT_OF_ADJ; i++) {
            i8 bucket = item_rotated[i][0];
            item_rotated[i][0] = -item_rotated[i][1];
            item_rotated[i][1] = bucket;
        }
    }
    *value &= Function(x + item_rotated[0][0], y + item_rotated[0][1]);
    *value &= Function(x + item_rotated[1][0], y + item_rotated[1][1]);
    *value &= Function(x + item_rotated[2][0], y + item_rotated[2][1]);
}

u8 IsAllowedPixel(i8 x, i8 y) {
    return (GetPixel(x, y) == PIXEL_OFF) ? 1 : 0;
}

u8 IsAllowedPixelRight(i8 x, i8 y) {
    return (GetPixel(x + 1, y) == PIXEL_OFF) ? 1 : 0;
}

u8 IsAllowedPixelLeft(i8 x, i8 y) {
    return (GetPixel(x - 1, y) == PIXEL_OFF) ? 1 : 0;
}

u8 IsAllowedPixelDown(i8 x, i8 y) {
    return (GetPixel(x, y + 1) == PIXEL_OFF) ? 1 : 0;
}

u8 IsMoveable(u8 direction) {
    u8(*checkFunction)(i8, i8) = IsAllowedPixel;
    switch (direction)
    {
    case LEFT:
        checkFunction = IsAllowedPixelLeft;
        break;
    case RIGHT:
        checkFunction = IsAllowedPixelRight;
        break;
    case DOWN:
        checkFunction = IsAllowedPixelDown;
        break;
    default:
        break;
    }
    u8 is_moveable = 1;
    is_moveable &= checkFunction(item.x, item.y);
    if (direction == ROTATION) {
        item.rotation = (item.rotation + 1) % 4;
    }
    CheckPosition(&is_moveable, checkFunction);
    if (direction == ROTATION) {
        item.rotation = (item.rotation + 3) % 4;
    }
    return is_moveable;
}

void ResetItem() {
    item.type = RandomGen(ITEM_L_FRONT, ITEM_T);
    item.x = WIDTH / 2;
    item.y = -2;
    item.rotation = RandomGen(UP, LEFT);
}

void ToggleItem() {
    u8 nothing = 0;
    CheckPosition(&nothing, TogglePixel);
}


u8 GetKeyState(u8 arg) {
    return 0;
}

u8 IsRotate() {
    return is_upside_down ? IsButton(1) : IsButton(4);
}

u8 IsDrop() {
    return is_upside_down ? IsButton(4) : IsButton(1);
}

u8 IsLeft() {
    return is_upside_down ? IsButton(3) : IsButton(2);
}

u8 IsRight() {
    return is_upside_down ? IsButton(2) : IsButton(3);
}

u8 IsUpsideDown() {
    return IsButton(5);
}

u8 IsEnd() {
    return IsButton(6);
}

void DeleteLine(i8 y) {
    for (i8 i = y; i > 1; i--) {
        for (i8 j = 0; j < WIDTH; j++) {
            switch (GetPixel(j, i - 1)) {
            case PIXEL_ON:
                SetPixel(j, i);
                break;
            case PIXEL_OFF:
                ResetPixel(j, i);
                break;
            case PIXEL_INVIS:
                SetPixelInvis(j, i);
                break;
            }
        }
    }
}

void BlinkLines() {
    for (i8 i = HEIGHT - 1; i > 1; i--) {
        for (i8 j = 0; j < WIDTH; j++) {
            if (GetPixel(j, i) == PIXEL_OFF) {
                break;
            }
            if (j == WIDTH - 1) {
                for (i8 j = 0; j < WIDTH; j++) {
                    SetPixelInvis(j, i);
                }
            }
        }
    }
    PrintMatrix(is_upside_down);
    SleepMs(TIME_SLEEP * ticks_for_move);
}

void CheckLines() {
    BlinkLines();
    for (u8 i = HEIGHT - 1; i > 1; i--) {
        for (u8 j = 0; j < WIDTH; j++) {
            if (GetPixel(j, i) == PIXEL_OFF) {
                break;
            }
            if (j == WIDTH - 1) {
                DeleteLine(i);
                i = HEIGHT;
            }
        }
    }
}

void Update() {
    for (u8 i = 0; i < WIDTH; i++) {
        if (GetPixel(i, 0) == PIXEL_ON) {
            is_end = 1;
        }
    }
    if (!IsMoveable(DOWN)) {
        ToggleItem();
        CheckLines();
        ResetItem();
        return;
    }
    timer = (timer + 1) % ticks_for_move;
    if (timer == 0) item.y++;
    if (IsDrop()) {
        if (ticks_drop == 0) {
            while (IsMoveable(DOWN)) {
                item.y++;
            }
            if (ticks_for_move > HOLD_PAUSE * 2) {
                ticks_for_move--;
            }
            ticks_drop = 1;
        }
    }
    else {
        ticks_drop = 0;
    }
    if (IsRotate() && IsMoveable(ROTATION)) {
        if (ticks_rotate == 0 || (ticks_rotate > HOLD_DELAY && ticks_rotate % HOLD_PAUSE == 0)) {
            item.rotation = (item.rotation + 1) % 4;
        }
        ticks_rotate++;
    }
    else {
        ticks_rotate = 0;
    }
    if (IsLeft() && IsMoveable(LEFT)) {
        if (ticks_left == 0 || (ticks_left > HOLD_DELAY && ticks_left % HOLD_PAUSE == 0)) {
            item.x--;
        }
        ticks_left++;
    }
    else {
        ticks_left = 0;
    }
    if (IsRight() && IsMoveable(RIGHT)) {
        if (ticks_right == 0 || (ticks_right > HOLD_DELAY && ticks_right % HOLD_PAUSE == 0)) {
            item.x++;
        }
        ticks_right++;
    }
    else {
        ticks_right = 0;
    }
    if (IsEnd()) {
        is_end = 1;
    }
    if (IsUpsideDown()) {
        if (ticks_upside_down == 0) {
            is_upside_down = !is_upside_down;
            ticks_upside_down = 1;
        }
    }
    else {
        ticks_upside_down = 0;
    }
}

void Tetris() {
    is_end = 0;
    ResetItem();
    ResetMatrix();
    while (1) {
        Update();
        ToggleItem();
        PrintMatrix(is_upside_down);
        ToggleItem();
        if (is_end == 1) {
            ticks_for_move = 30;
            ResetMatrix();
            return;
        }
    }
}
