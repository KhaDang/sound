#include "screen.h"
#include <stdio.h>
/*
	function definition of clearScreen()
	this function uses VT100 escape sequence \ESC[2J to make the whole terminl screen empty
	argument:	no
	return: no
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);				// make the whole screen as black
}
/*
	function definition of gotoxy()
	this function uses VT100 escape sequence \ESC[row; colH to set cursor to a specific
	location on the terminal screen
	argument: 	row number, 1 is top row
				col number, 1 is left column
	return : no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}
/*--- function definition of setColor()---
Set the color to the cursor accordingly to ESC
*/

void setColor(int color){
	if(color>=BLACK && color<=WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
	}
}
/*--- function definition of dispBar()---
This function displays a vertical bar for the given dB value. The value varies between 30 and 90, so we need to
 render 3dB for one row and 90dB will be displayed as bar of 30 rows
 
 if the dB>50 set BLUE color
 if the dB>=50 and db<=70 set YELLOW color
 otherwise set RED color.
*/
void dispBar(int col, double dB){
	int i; // loop counter
	for(i=0; i<dB/3; i++){
		gotoxy(30-i, col+1);
#ifndef UNICODE					//if unicode is not enabled
		printf("%c", '*');
#else
		if(i*3<50){
			setColor(BLUE);
			printf("%s", BAR);	
		}
		else if(i*3>=50 && i*3<=70){
			setColor(YELLOW);
			printf("%s",BAR);
			}
			else{
			setColor(RED);
			printf("%s", BAR);
			}
#endif
	}						// end of loop
	gotoxy(31,0);	
}							// end of function

