#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef struct
{
SDL_Surface *jouer;//position de bouton jouer

SDL_Surface*image;//l'image sur laquelle sera afficher
SDL_Surface*image1;//limage de credit

//les parametres de menu les boutons
SDL_Surface*parametre;
SDL_Surface*quitter;
SDL_Surface*personnage;
SDL_Surface*jouer1;
SDL_Surface*parametre1;
SDL_Surface*quitter1;
SDL_Surface*credit;
SDL_Surface*credit1;
//son 
SDL_Surface*son;
SDL_Surface*son1;
//bouton de retour
SDL_Surface*retour;
SDL_Surface*retour1;

//bouton de new game
SDL_Surface*newgame;
SDL_Surface*newgame1;
//bouton de load game
SDL_Surface*loadgame;
SDL_Surface*loadgame1;
//mode d'affichage de menu
SDL_Surface*modescreen;
SDL_Surface*modescreen1;
//play music
SDL_Surface*volume;
SDL_Surface*volume1;
//limage 2
SDL_Surface*image2;
//le mode de lafichge de son +ou -
SDL_Surface*plus;
SDL_Surface*moins;
SDL_Surface*plus1;
SDL_Surface*moins1;
//l'animation 
SDL_Surface *background;
SDL_Rect posbackground;

SDL_Rect posretour,posson,posmodescreen,posmodescreen1,posvolume,posvolume1,postionimage2,posplus,posmoins,postionimage1,posnewgame,posloadgame;
SDL_Rect postionimage,posjouer,posparametre,posquitter,postionjoueur,poscredit;

//pointeur sur la musique
Mix_Chunk *music;
}menu;


int int_menu(SDL_Surface *screen , Mix_Music *musique,menu *m);
void setting(SDL_Surface *screen , Mix_Music *musique,int *c ,int *a ,int *i , float *e,menu *m) ;
void play(SDL_Surface *screen , Mix_Music *musique,menu *m );
void animation(SDL_Surface *screen,menu *m ) ;

void txtee(SDL_Surface *ecran) ;
void creditt(SDL_Surface *screen , Mix_Music *musique,menu *m);
