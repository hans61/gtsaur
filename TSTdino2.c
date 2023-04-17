#include <stdlib.h>
#include <string.h>
#include <gigatron/console.h>
#include <gigatron/sys.h>
#include <gigatron/libc.h>
#include <stdarg.h>

// definition of sprites outsource, clearer
#include "sprites2.h"

#define WAIT 10

int x,y,i;

void printSprite18(const char** ptrChar, int x, int y)
{
	int i;
	int y1 = y;
	for(i=0; i<3; i++){
		SYS_Sprite6((char*)ptrChar[i], (char*)(y<<8)+x+6*i);
		//while(serialRaw == 0xff) {}
		//while(serialRaw != 0xff) {}
	}
}

void wait(char value)
{
	//char fc = frameCount + value;
	//while(fc < frameCount){
	//	fc = fc;
	//}
	
	int t,w;
	w = value * 100;
	for(t=0; t<w; t++) t++;
	
	//while(serialRaw == 0xff) {}
	//while(serialRaw != 0xff) {}
}

int main()
{
	char* p1 = (char*)0x0100;
	char l;
	//videoTop_v5 = 20;
	// _console_reset(0x003F);
		
	for(l=0; i<40; i+=2) p1[i] = p1[40];
	
	_console_clear((char*)0x1c00, 0x003F, 100);
	y = 60;
	for(;;){
		for(x=0; x<140; x+=3){
			printSprite18(dino[1], x, y);   // draw sprite 
			wait(WAIT);                     // waiting
			printSprite18(dino[0], x, y);   // delete sprite, restore background

			printSprite18(dino[2], x+1, y);
			wait(WAIT);
			printSprite18(dino[0], x+1, y);

			printSprite18(dino[3], x+2, y);
			wait(WAIT);
			printSprite18(dino[0], x+2, y);
		}

	}
}
