//This file
#include "comm.h"
#include "sound.h"
#include <stdio.h>
#include <math.h>
#include "screen.h"
/*--- function definition of printID()---
 print out the id 
*/
void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);
	printf("\n");

}

/*--- Funtion definition for dispWAVData--- 

This function read the input file (the sound file) and calculate the amplitude of input sound
To do so, 1600 samples has been create in the sound file. The program read the amplituce of each sample from the input file
However there are too many samples need to calculate and That needs a huge calcuation as well as a lot of memory capacity to store the data

To simplify the process 200 pieces of data sample has been group together and their root mean square will be calculated
Then results then be stored in the array and can be accessed by other functions.
Therefore, 80 values of the amplitube of sound has been stored, instead of 1600 values.
*/
void dispWAVData(char filename[]){
	int i,j;					// loop counter
	FILE *fp;					//file handler to opern the file "test.wav"
	double rms[80],sum;			//80 pieces of RMS value
	short samples[SAMPLERATE];	//totally 16000 samplie in 1 sec
	WAVHeader mh;				// just used to skip over the header of the wav file
	fp= fopen(filename, "r");
	if(fp==NULL){
		printf("Error when open the file!");
		return;
	}
	fread(&mh, sizeof(mh),1,fp);						//skip over the header of wave file
	fread(samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	clearScreen();
	for(i=0; i<80; i++){
		for(j=0,sum=0.0; j<SAMPLERATE/80; j++){
			sum += samples[j+i*200] * samples[j+i*200];
		}
		rms[i]=sqrt(sum/200);
		
// if DEBUG mode is eable then the program will print the rms value and rms value in decibel 
// Otherwise the disBar() function will be called
#ifdef DEBUG
		printf("rms[%d]: %10.4f, dB = %10.4f \n",i,rms[i],20*log10(rms[i]));
#else
		dispBar(i,20*log10(rms[i]));						// the function definition is written in screen.c
#endif
	}
// After calculating the rms value of input wave sound. The program send this data to server
// Refer comm.c to see function definition
#ifdef COMM
	sendToServer(rms);
	
#endif
}

/*--- Function definition for disWAVHeader()--- 
This function will print out the Canonical form of the input sound file

*/
void dispWAVHeader(char filename[]){
	FILE *fp;
	WAVHeader mh;		//an instace of WAVHeader struct
	// open the test.wav file for reading
	fp = fopen(filename, "r");
	if(fp == NULL){		// if fopen fails
		printf("Error when open the file! \n");
		return;		// function stops
	}
	fread(&mh, sizeof(mh), 1, fp);
	fclose(fp); 		// close the opened file
	printf("Chunk ID: ");
	printID(mh.chunkID);
	printf("Chunk size: %d\n", mh.chunkSize);
	printf("Format: ");
	printID(mh.format);
	printf(" subchunk 1 ID: ");
	printID(mh.subchunk1ID);
	printf(" subchunk 1 size: %d\n", mh.subchunk1Size);
	printID(mh.subchunk1ID);
	printf(" subchunk 1 size: %d\n", mh.subchunk1Size);

	printf(" Audio formate: %d\n", mh.audioFormat);						
	printf(" Channel number: %d\n", mh.numChannels);					
	printf(" Sample rate: %d\n", mh.sampleRate);
	printf(" Block align: %d\n", mh.blockAlign);
	printf(" Bits per sample: %d\n", mh.bitsPerSample);
	printf(" Subchunk ID:");
	printID(mh.subchunk2ID);
	printf(" Sub chunk 2 size: %d\n", mh.subchunk2Size);
}
