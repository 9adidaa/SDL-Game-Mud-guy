#include "menu.h"
#define SCREEN_W 1620
#define SCREEN_H 880
int main (void)
{
    int continuee=1;
    SDL_Surface *screen =NULL;
    menu m;
int ez;
FILE* fichier = NULL;
fichier = fopen("ez.txt","r");
fscanf(fichier,"%d",&ez);
    SDL_Init(SDL_INIT_VIDEO);
    Mix_Music *musique;
    screen = SDL_SetVideoMode(1000, 563,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Mad Guy", NULL);
    SDL_Event event;
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }
  
  if(ez == 1){
  musique=Mix_LoadMUS("andre.mp3");
  }else{
  musique=Mix_LoadMUS("music2.mp3");
  }
	   
           






animation(screen,&m) ;
Mix_PlayMusic(musique,-1);
continuee=int_menu(screen ,musique,&m);					



Mix_CloseAudio();
SDL_FreeSurface(screen);

SDL_Quit();
return EXIT_SUCCESS;
}




