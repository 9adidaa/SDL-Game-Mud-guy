#include <SDL/SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct 
{
 SDL_Surface * img;
 SDL_Rect p,pv,pf;
 int l ; 
 char txt[200] ;
}enigme;

void init_enigme1(enigme * e, char nomfichier[20]);
 void generate_afficher1 (SDL_Surface * screen  ,  enigme e)  ; 
 int solution_e1 (int x) ;
int resolution1 (int *run ,enigme * e ,SDL_Surface *screen) ; 
void afficher_resultat1 (SDL_Surface * screen,int s,int r ) ;
void pregame(SDL_Surface*screen);
int enigme_jeu1(SDL_Surface *screen);
int enigme_jeu(SDL_Surface *screen);
