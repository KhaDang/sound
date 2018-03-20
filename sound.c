//This file
#include "sound.h"
#include <stdio.h>
#include <math.h>

//function definition of printID()
void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);
	printf("\n");

}

// function definition of dispWAVData()
void dispWAVData(char filename[]){
	int i,j;					// loop counter
	FILE *fp;					//file handler to opern the file "test.wav"
	double rms[80],sum;			//80 pieces of RMS value
	short samples[SAMPLERATE];	//totally 19000 samplie in 1 sec
	WAVHeader mh;				// just used to skip over the header of the waw file
	fp= fopen(filename, "r");
	if(fp==NULL){
		printf("Error when open the file!");
	return;
	}
	fread(&mh, sizeof(mh),1,fp);
	fread(samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	for(i=0; i<80; i++){
		for(j=0,sum=0.0; j<SAMPLERATE/80; j++){
			sum+= samples[j+i*200]*samples[j+i*200];
		}
		rms[i]=sqrt(sum/200);
		printf("rms[%d]: %10.4f \n",i,rms[i]);
	}
}


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

	printf(" Audio formate: %d\n", mh.audioFormat);						// The 16 should been placed
	printf(" Channel number: %d\n", mh.numChannels);					// The channel should been 1
	printf(" Sample rate: %d\n", mh.sampleRate);
	printf(" Block align: %d\n", mh.blockAlign);
	printf(" Bits per sample: %d\n", mh.bitsPerSample);
	printf(" Subchunk ID:");
	printID(mh.subchunk2ID);
	printf(" Sub chunk 2 size: %d\n", mh.subchunk2Size);
}
