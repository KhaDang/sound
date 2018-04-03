// constant definitions
#define UNICODE		// use unicode to make good-looking bars
#define BAR "\u2590"
#define ESC 0x1B
enum COLORS {BLACK=30, RED=31, GREEN=32, YELLOW=33, BLUE=34, MAGENTA=35, CYAN=36, WHITE=37};
// function prototype
void clearScreen(void);
void gotoxy(int row, int col);
void setColor(int color);
void dispBar(int col, double dB);

