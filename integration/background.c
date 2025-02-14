#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"


void initBackground(Background *B)
{
	
	B->PositionBg.x=0;
	B->PositionBg.y=0;
	B->camera.x=0;
	B->camera.y=200;
	B->camera.w = 1200;
	B->camera.h = 800;
	B->BgImg= IMG_Load("backg.jpg");
	B->scoreI.img=IMG_Load("score.png");
	B->scoreI.pos1.x=800;
	B->scoreI.pos1.y=0;
	int i;
	char ch[20];
	for(i=0;i<12;i++)
	{
		B->anima[0] = IMG_Load("backg.jpg");
	}

	B->score=0;
	
	B->scoreT.font=TTF_OpenFont("Minecraft.ttf", 50);
	B->scoreT.col.r=0;
	B->scoreT.col.g=0;
	B->scoreT.col.b=0;
	
	B->scoreT.postxt.x=980;
	B->scoreT.postxt.y=20;


}

void initanimation(Background *a)
{       
	a->camera.x=1000;
	a->camera.y=600;
	a->camera.w = 2000;
	a->camera.h = 600;
	
	int i;
	char ch[20];
	for(i=1;i<5;i++)
	{
		sprintf(ch,"car/%d.png",i);
		a->anima[i] = IMG_Load(ch);
	}
}



void initmusic_background(Background *B)
{
	if(SDL_Init(SDL_INIT_AUDIO)==-1)
	{
		printf("SDL_Init: %s\n", SDL_GetError());
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}
	B->music=Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(B->music, -1);
	Mix_AllocateChannels(10);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
}

void afficherBack (Background B,SDL_Surface *screen,SDL_Surface *left_section)
{
        int l = B.scoreI.pos1.x;
	SDL_BlitSurface(left_section,&(B.camera),screen,&(B.PositionBg));
	SDL_BlitSurface(B.anima[B.anim/10],&B.camera,screen,&(B.PositionBg));
	
	SDL_BlitSurface(B.scoreI.img,NULL,screen,&B.scoreI.pos1);
	B.scoreI.pos1.x = 30;
	SDL_BlitSurface(B.scoreI.img,NULL,screen,&B.scoreI.pos1);
	B.scoreI.pos1.x = l;
	char var[10];
	sprintf(var, "%d", B.score);   
	B.scoreT.windtxt = TTF_RenderText_Blended(B.scoreT.font, var, B.scoreT.col);
	SDL_BlitSurface(B.scoreT.windtxt,NULL,screen,&B.scoreT.postxt);
	
}

void animation(Background *B, SDL_Surface * screen) 
{
	B->anim++;
	if(B->anim==90) 
	{
		B->anim=0;
	}

}

void animationsprite(Background *a, SDL_Surface * screen) 
{
	a->anim++;
	if(a->anim==40) 
	{
		a->anim=1;
	}

}

void getdirection(direction *d, int run, SDL_Surface * screen)
{
	run =1;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{	case SDL_QUIT:
		run =0;
		save_score(d->score);
                exit(0);
           	 break;
		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE: 
			run =0;
			save_score(d->score);
                        exit(0);
                    	break;
                    	case SDLK_UP:
			d->up=1;
			SDL_Delay(50);
			break;
			case SDLK_DOWN:
			d->down=1;
			SDL_Delay(50);
			break;
			case SDLK_LEFT:
			d->left=1;
			SDL_Delay(50);
			break;
			case SDLK_RIGHT:
			d->right=1;
			SDL_Delay(50);
			break;
                    	case SDLK_p:
    			SDL_WM_ToggleFullScreen(screen);
			break;
			default:
			break;
									
		}
		break;
		}
		SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
			case SDLK_LEFT:
			d->left=0;
			SDL_Delay(20);
			break;
			case SDLK_UP:
			d->up=0;
			SDL_Delay(20);
			break;
			case SDLK_DOWN:
			d->down=0;
			SDL_Delay(20);
			break;
			case SDLK_RIGHT:
			d->right=0;
			SDL_Delay(20);
			break;
			default:
			break;						
		}
		break;
		}
}

void scrolling(Background *B, direction *d)
{
	if(d->right==1 && B->camera.x < 6400)
	{
		B->camera.x+=10;
		if(B->camera.x >=6400)
		{
			B->camera.x=6400;
			
		}
	}
	else if(d->left==1)
	{
		B->camera.x-=10;
		if (B->camera.x<= 0) 
		{
			B->camera.x=0;
		}
	}
	if(d->up==1)
	{	B->camera.y-=10;
		if (B-> camera.y <= 0)
		{
			B->camera.y=0;
		}
	}
	else if(d->down==1 )
	{
		B->camera.y+=10;
		if (B-> camera.y >= 200)
		{
			B->camera.y = 200;
		}
	}
}

void save_score(int Nscore){
	FILE * fichier = NULL;
	int Lscore;
	fichier = fopen("score.txt","r");
	fscanf(fichier,"%d",&Lscore);
	fclose(fichier);
	if(Nscore > Lscore){
	fichier = fopen("score.txt","w");
	fprintf(fichier,"%d",Nscore);
	}


}

void initialiser_input (direction *d)
{
d->left=0;
d->right=0;
d->down=0;
d->up=0;
}

void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
	Mix_FreeMusic (B->music);
}
int afficherannimation (Background a,SDL_Surface *screen)
{       
        a.camera.x = a.camera.x + a.x;
	SDL_BlitSurface(a.anima[a.anim/10],NULL,screen,&a.camera );

	return a.camera.x;
}

