//#define DEBUG			// <--conditional compiling, enable this line to turn into Debug mode-->
// constant definitions
#define SAMPLERATE 16000

/*
The WAVE file format is a subset of Microsoft's RIFF specification for the storage of multimedia files.
A RIFF file starts out with a file header followed by a sequences of data chunks. A WAVE file is often
just a RIFF file with a single "WAVE" chuck which consists of two sub-chunks--a "fmt" chunk specififying
the data format and a "data" chunk containing the actual sample data.
*/

// struct/ union definitions
typedef struct{
	char chunkID[4];	// "RIFF"
	unsigned int chunkSize;		// 4 bytes
	char format[4];			// "WAVE"
	char subchunk1ID[4];		// "fmt"
	unsigned int subchunk1Size;
	unsigned short audioFormat;	// 16 for PCM
	unsigned short numChannels;	//1 for mono
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2ID[4];		//"Data"
	unsigned int subchunk2Size;
}WAVHeader;

// function prototypes
void dispWAVHeader(char filename[]);
void dispWAVData(char filename[]);
void printID(char []);

