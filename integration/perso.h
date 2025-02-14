#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct
{
SDL_Surface *img;
SDL_Rect pos1,pos2;
}IMAGE;

typedef struct{
SDL_Rect postxt;
TTF_Font *font;
SDL_Surface *windtxt;
SDL_Color col;
}TEXT;

typedef struct perso
{
int num;
int ms;
SDL_Surface *spritesheet;
SDL_Rect position;
int direction;
SDL_Rect pos_sprite; 
double vitesse,acceleration;
int vitesseV;
int score , vie;
SDL_Surface *image_vie[5]; 
TEXT scoreT;
IMAGE scoreI;
SDL_Rect position_vie ;
}perso;



void initPerso(perso *p);
void initPerso2(perso *p2);
void init_score(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void afficher_score(perso p, SDL_Surface * screen);
void deplacerPerso (perso *p,int dt);
void animerPerso (perso* p);
void saut (perso* p) ;
void gestion_vie(perso *p);
void init_vie(perso *p); 
void init_score1(perso *p);
void afficher_score1(perso p, SDL_Surface * screen);
void afficher_vie(perso p, SDL_Surface * screen);
void afficher_vie1(perso p, SDL_Surface * screen);
 #endif
