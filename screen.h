// constant definitions
#define UNICODE		// use unicode to make good-looking bars
#define BAR "\u2590"
#define ESC 0x1B

// enum deifinition for COLORS
enum COLORS {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE=37};
// function prototype
void clearScreen(void);
void gotoxy(int row, int col);
void setColor(int color);
void dispBar(int col, double dB);

