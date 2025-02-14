#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
SDL_Surface *img;
SDL_Rect pos1,pos2;
}IMAGEe;



typedef struct{
SDL_Rect postxt;
TTF_Font *font;
SDL_Surface *windtxt;
SDL_Color col;
}TEXTt;

typedef struct
{
	SDL_Surface *BgImg;  
	SDL_Rect PositionBg;
	SDL_Rect pos;
	SDL_Rect camera;
	Mix_Music *music; 
	int anim;
	SDL_Surface *anima[50]; 
	SDL_Rect posanim ;
	IMAGEe scoreI;
	int score , vie;
	TEXTt scoreT;
	int x;
	int L;
}Background;

typedef struct 
{
	int left,right,up,down,score;
}direction;


void initBackground(Background *B);
void initanimation(Background *a);
void initmusic_background();
void afficherBack(Background B, SDL_Surface * screen ,SDL_Surface *left_section);
void partage_background (SDL_Surface *screen,Background *b);
int afficherannimation (Background a,SDL_Surface *screen);
void animation (Background *B,SDL_Surface * screen) ;
void animationsprite(Background *a, SDL_Surface * screen);
void getdirection(direction *d, int run, SDL_Surface * screen);
void scrolling(Background *B, direction *d);
void save_score(int Nscore);
void freeBackground(Background *B);

#endif
