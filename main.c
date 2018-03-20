// this file contains the main function of our project

#include "sound.h" 
#include <stdlib.h>

int main(void){
	while(1){
		// Run system command "arecord" to record 1 sec of wave
		system("arecord -r16000 -c1 -f S16_LE -d1 test.wav");
		
		// Display WAV header
		dispWAVHeader("test.wav");
		// Display WAV strength as decibel values
		dispWAVData("test.wav");
		
		break;			// loop runs just once
	}
	return 0;
}
