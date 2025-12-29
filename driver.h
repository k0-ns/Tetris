#define HEIGHT 32
#define WIDTH 8
#define PIXEL_OFF 46
#define PIXEL_INVIS 47
#define PIXEL_ON 64
#define TIME_SLEEP 20
#define DATA_PIN GPIO_PIN_8
#define CLOCK_PIN GPIO_PIN_13
#define CS_PIN GPIO_PIN_15

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;

void ResetMatrix();
void PrintMatrix(u8 is_upside_down);

u8 RandomGen(u8 min, u8 max);

u8 GetPixel(i8 x, i8 y);
void SetPixel(i8 x, i8 y);
void SetPixelInvis(i8 x, i8 y);
void ResetPixel(i8 x, i8 y);
u8 TogglePixel(i8 x, i8 y);
u8 IsButton(u8 num);

void DebugPoint();
void SleepMs(u16 ms);
