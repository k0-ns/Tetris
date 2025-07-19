#include <iostream>
#include <windows.h>
#define HEIGHT 16
#define WIDTH 8
#define PIXEL_OFF 46
#define PIXEL_ON 64
#define TIME_SLEEP 100
#define ROTATE_KEY 87
#define DROP_KEY 83
#define LEFT_KEY 65
#define RIGHT_KEY 68
#define AMOUNT_OF_ADJ 3
#define TICKS_FOR_MOVE 5

using namespace std;

typedef uint8_t u8;
typedef int8_t i8;

enum {
    ITEM_L_FRONT,
    ITEM_L_BACK,
    ITEM_SQUARE,
    ITEM_LINE,
    ITEM_Z,
    ITEM_Z_BACK,
    ITEM_T,
    ITEM_PENIS
};

enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    ROTATION,
    NOWHERE
};

enum {
    N = 0,
    U = -1,
    UU = -2,
    D = 1,
    R = 1,
    L = -1
};

struct item_t {
    u8 type;
    u8 rotation;
    u8 x;
    u8 y;
};

u8 matrix[HEIGHT][WIDTH];
item_t item;
u8 timer = 0;

i8 L_FRONT[AMOUNT_OF_ADJ][2] = { {N,U},{N,D},{R,D} };
i8 L_BACK[AMOUNT_OF_ADJ][2] = { {N,U},{N,D},{L,D} };
i8 SQUARE[AMOUNT_OF_ADJ][2] = { {N,U},{R,U},{R,N} };
i8 LINE[AMOUNT_OF_ADJ][2] = { {N,U},{N,D},{N,UU} };
i8 Z[AMOUNT_OF_ADJ][2] = { {N,U},{L,U},{R,N} };
i8 Z_BACK[AMOUNT_OF_ADJ][2] = { {N,U},{L,N},{R,U} };
i8 T[AMOUNT_OF_ADJ][2] = { {N,U},{L,N},{R,N} };
i8 PENIS[AMOUNT_OF_ADJ][2] = { {N,U},{L,D},{R,D} };

u8 RandomGen(u8 min, u8 max) {
    max++;
    return (rand() % (max - min) + min);
}

void ResetMatrix() {
    for (u8 i = 0; i < HEIGHT; i++) {
        for (u8 j = 0; j < WIDTH; j++) {
            matrix[i][j] = PIXEL_OFF;
        }
    }
}

void PrintMatrix() {
    system("cls");
    for (u8 i = 0; i < HEIGHT; i++) {
        for (u8 j = 0; j < WIDTH; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

u8 GetPixel(u8 x, u8 y) {
    if (x < 0 || x >= WIDTH) return PIXEL_ON;
    if (y < 0 || x >= HEIGHT) return PIXEL_ON;

    return matrix[y][x];
}

u8 IsAllowedPixel(u8 x, u8 y) {
    return (GetPixel(x, y) == PIXEL_OFF) ? 1 : 0;
}

u8 IsAllowedPixelRight(u8 x, u8 y) {
    return (GetPixel(x + 1, y) == PIXEL_OFF) ? 1 : 0;
}

u8 IsAllowedPixelLeft(u8 x, u8 y) {
    return (GetPixel(x - 1, y) == PIXEL_OFF) ? 1 : 0;
}

u8 IsAllowedPixelDown(u8 x, u8 y) {
    return (GetPixel(x, y + 1) == PIXEL_OFF) ? 1 : 0;
}

void SetPixel(u8 x, u8 y) {
    if (x < 0 || x >= WIDTH) return;
    if (y < 0 || x >= HEIGHT) return;

    matrix[y][x] = PIXEL_ON;
}

void ResetPixel(u8 x, u8 y) {
    if (x < 0 || x >= WIDTH) return;
    if (y < 0 || x >= HEIGHT) return;

    matrix[y][x] = PIXEL_OFF;
}

u8 TogglePixel(u8 x, u8 y) {
    if (x < 0 || x >= WIDTH) return 0;
    if (y < 0 || x >= HEIGHT) return 0;

    if (matrix[y][x] == PIXEL_ON) {
        matrix[y][x] = PIXEL_OFF;
    }
    else {
        matrix[y][x] = PIXEL_ON;
    }
    return 0;
}

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

void CheckPosition(u8& value, u8(*Function)(u8, u8)) {
    u8 x = item.x;
    u8 y = item.y;
    value &= Function(x, y);
    i8 item_rotated[AMOUNT_OF_ADJ][2];
    FillItem(item_rotated);
    for (int i = 0; i < item.rotation; i++) {
        for (int i = 0; i < AMOUNT_OF_ADJ; i++) {
            i8 bucket = item_rotated[i][0];
            item_rotated[i][0] = -item_rotated[i][1];
            item_rotated[i][1] = bucket;
        }
    }
    value &= Function(x + item_rotated[0][0], y + item_rotated[0][1]);
    value &= Function(x + item_rotated[1][0], y + item_rotated[1][1]);
    value &= Function(x + item_rotated[2][0], y + item_rotated[2][1]);
}

u8 IsMoveable(u8 direction) {
    u8(*checkFunction)(u8, u8) = IsAllowedPixel;
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
    CheckPosition(is_moveable, checkFunction);
    if (direction == ROTATION) {
        item.rotation = (item.rotation + 3) % 4;
    }
    return is_moveable;
}

void ResetItem() {
    item.type = RandomGen(ITEM_L_FRONT, ITEM_T);
    item.x = WIDTH / 2;
    item.y = 2;
    item.rotation = RandomGen(UP, LEFT);
    if (!IsMoveable(NOWHERE)) {
        ResetMatrix();
    }
}

void ToggleItem() {
    u8 nothing = 0;
    CheckPosition(nothing, TogglePixel);
}

u8 IsRotate() {
    return (GetKeyState(ROTATE_KEY) & 0x8000) ? 1 : 0;
}

u8 IsDrop() {
    return (GetKeyState(DROP_KEY) & 0x8000) ? 1 : 0;
}

u8 IsLeft() {
    return GetKeyState(LEFT_KEY) & 0x8000 ? 1 : 0;
}

u8 IsRight() {
    return GetKeyState(RIGHT_KEY) & 0x8000 ? 1 : 0;
}

void DeleteLine(u8 y) {
    for (u8 i = y; i > 1; i--) {
        for (u8 j = 0; j < WIDTH; j++) {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
}

void CheckLines() {
    for (u8 i = HEIGHT - 1; i > 1; i--) {
        for (u8 j = 0; j < WIDTH; j++) {
            if (matrix[i][j] == PIXEL_OFF) {
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
    if (!IsMoveable(DOWN)) {
        ToggleItem();
        CheckLines();
        ResetItem();
        return;
    }
    timer = (timer + 1) % TICKS_FOR_MOVE;
    if(timer == 0) item.y++;
    if (IsDrop()) {
        while (IsMoveable(DOWN)) {
            item.y++;
        }
        return;
    }
    if (IsRotate() && IsMoveable(ROTATION)) {
        item.rotation = (item.rotation + 1) % 4;
    }
    if (IsLeft() && IsMoveable(LEFT)) {
        item.x--;
    }
    if (IsRight() && IsMoveable(RIGHT)) {
        item.x++;
    }
}

int main()
{
    ResetItem();
    ResetMatrix();
    ToggleItem();
    PrintMatrix();

    while (true)
    {
        ToggleItem();
        Update();
        ToggleItem();
        PrintMatrix();
        Sleep(TIME_SLEEP);
    }
}
