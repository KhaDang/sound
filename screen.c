#include "screen.h"
#include <stdio.h>

// function definition of clearScreen()
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);				// make the whole screen as black
	
}
// function definition of gotoxy
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}
// function definition of serColor()
void setColor(int color){
	if(color>=BLACK && color<=WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
	}
}
// function definition of dispBar(), this function displays a vertical bar
// for the given dB value. The value varies between 30 and 90, so we need to
// render 3dB for one row and 90dB will be displayed as bar of 30 rows

void dispBar(int col, double dB){
	int i; // loop counter
	for(i=0; i<dB/3; i++){
		gotoxy(30-i, col+1);
		printf("%c", '*');
	}	
}
