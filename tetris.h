#define AMOUNT_OF_ADJ 3
#define HOLD_DELAY 10
#define HOLD_PAUSE 4

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
    i8 x;
    i8 y;
};

void Tetris();
