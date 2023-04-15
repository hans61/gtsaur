#include <stdlib.h>
#include <string.h>
#include <gigatron/console.h>
#include <gigatron/sys.h>
#include <gigatron/libc.h>
#include <stdarg.h>

// definition of sprites outsource, clearer
#include "sprites.h"

#define WAIT 5

int x,y,i;

void printSprite18(const char** ptrChar, int x, int y)
{
	int i;
	int y1 = y;
	for(i=0; i<3; i++){
		SYS_Sprite6((char*)ptrChar[i], (char*)(y1<<8)+x+6*i);
	}
	y1+=15;
	for(i=0; i<3; i++){
		SYS_Sprite6((char*)ptrChar[i+3], (char*)(y1<<8)+x+6*i);
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
}

int main()
{
	_console_reset(0x003F);
	videoTop_v5 = 20;
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
