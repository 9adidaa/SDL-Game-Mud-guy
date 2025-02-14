#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>


int int_menu(SDL_Surface *screen , Mix_Music *musique,menu *m)
{
int a= 0 , i =0 ; 
float e = 1 ;
int c = 0;
int ez;
FILE* fichier = NULL;
fichier = fopen("ez.txt","r");
fscanf(fichier,"%d",&ez);
  // SDL_Surface *screen;
SDL_Event event;
char ee[30];
int continuer=1,x=0,done=1;
Mix_AllocateChannels(2);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
if(ez == 1){
m->music=Mix_LoadWAV("thunder.wav");
}else{
m->music=Mix_LoadWAV("Click De  Souris.wav");
}
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}


if(ez == 1){
if(c == 0){
m->image=IMG_Load("res1/BACKGROUND.png");
}else{
m->image=IMG_Load("res1/unnamed.png");
}

m->jouer=IMG_Load("res1/PLAY-DEP-HOVER.png");
m->jouer1=IMG_Load("res1/PLAY-DEP.png");
m->parametre1=IMG_Load("res1/OPTION-DEP.png");
m->parametre=IMG_Load("res1/OPTION-DEP-HOVER.png");
m->quitter=IMG_Load("res1/QUIT-DEP.png");
m->quitter1=IMG_Load("res1/QUIT-DEP-HOVER.png");
m->credit=IMG_Load("res1/CARD.png");
m->credit1=IMG_Load("res1/CARD1.png");
}
else{
if(c == 0){
m->image=IMG_Load("res2/BACKGROUND.png");
}else{
m->image=IMG_Load("res2/unnamed.png");
}
m->jouer=IMG_Load("res2/PLAY-HOVER.png");
m->jouer1=IMG_Load("res2/PLAY.png");
m->parametre1=IMG_Load("res2/OPTION.png");
m->parametre=IMG_Load("res2/OPTION-HOVER.png");
m->quitter=IMG_Load("res2/QUIT.png")	;
m->quitter1=IMG_Load("res2/QUIT-HOVER.png");
}
m->personnage=IMG_Load("per.png");
m->credit=IMG_Load("res1/CARD.png");
m->credit1=IMG_Load("res1/CARD1.png");
m->postionimage.x=0;
m->postionimage.y=0;
m->postionjoueur.x=0;
m->postionjoueur.y=0;
m->poscredit.x=550 ; 
m->poscredit.y=220 ; 

m->postionimage.w=m->image->w;
m->postionimage.h=m->image->h;
m->image->w=1200;
m->image->h=900;
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
m->posjouer.x=30;
m->posjouer.y=170;
m->posparametre.x=30;
m->posparametre.y=300;
m->posquitter.x=30;
m->posquitter.y=450;

SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);

    
    
while(continuer)
{
done++;













SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_QUIT:
continuer=0;
break;
case SDL_KEYUP:
        switch(event.key.keysym.sym)
        {   
            case SDLK_UP:
               x-- ; 
               x+=4 ; 
               x=x%4    ;
                break;
            case SDLK_DOWN:
                x++  ;
                x=x%4;
                break;
            case SDLK_SPACE:
            if(x==3)
            continuer=0;
         if(x==1)
{Mix_PlayChannel(1,m->music,0);
setting(screen, musique,&c,&a,&i,&e,&m) ;
}


            if(x==0)
            {
            
            Mix_PlayChannel(1,m->music,0);
          play(screen, musique,&m ) ;
            }
            if(x==2)
            {
            
            
              Mix_PlayChannel(1,m->music,0);
          creditt(screen, musique ,&m) ;
            
            }

           break;

done=1;
}  
if(x==1)
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter) ;
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);}
if(x==2)
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter)  ;
SDL_BlitSurface(m->credit1,NULL,screen,&m->poscredit);
SDL_Flip(screen);}
if(x==0)
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);}
if(x==3)
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter1,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);



}
break;
case SDL_MOUSEMOTION:
        if((event.motion.x<m->posjouer.x+320&&event.motion.x>m->posjouer.x)&&(event.motion.y<m->posjouer.y+97&&event.motion.y>m->posjouer.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);
}
          else if((event.motion.x<m->posparametre.x+320&&event.motion.x>m->posparametre.x)&&(event.motion.y<m->posparametre.y+97&&event.motion.y>m->posparametre.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);

}
         else  if((event.motion.x<m->posquitter.x+320&&event.motion.x>m->posquitter.x)&&(event.motion.y<m->posquitter.y+97&&event.motion.y>m->posquitter.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter1,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);
SDL_Flip(screen);
}
      else  if((event.motion.x<m->poscredit.x+320&&event.motion.x>m->poscredit.x)&&(event.motion.y<m->poscredit.y+97&&event.motion.y>m->poscredit.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit1,NULL,screen,&m->poscredit);
SDL_Flip(screen);
}
else 
{

SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);

SDL_Flip(screen);
}
break;
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posjouer.x+325&&event.button.x>m->posjouer.x)&&(event.button.y<m->posjouer.y+82&&event.button.y>m->posjouer.y))
{
Mix_PlayChannel(1,m->music,0);
play(screen, musique,&m) ;

}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posparametre.x+325&&event.button.x>m->posparametre.x)&&(event.button.y<m->posparametre.y+82&&event.button.y>m->posparametre.y))
{
Mix_PlayChannel(1,m->music,0);
setting(screen, musique,&c,&a,&i,&e,&m) ;
SDL_Flip(screen);
}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posquitter.x+325&&event.button.x>m->posquitter.x)&&(event.button.y<m->posquitter.y+82&&event.button.y>m->posquitter.y))
{
Mix_PlayChannel(1,m->music,0);
continuer=0;
SDL_Quit();
SDL_Flip(screen);
}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->poscredit.x+320&&event.button.x>m->poscredit.x)&&(event.button.y<m->poscredit.y+97&&event.button.y>m->poscredit.y))
{
Mix_PlayChannel(1,m->music,0);
creditt(screen, musique,&m) ;
SDL_Flip(screen);
SDL_Delay(100);
}

break;



}
}




    return continuer ;


 

}


void setting(SDL_Surface *screen , Mix_Music *musique,int *c ,int *a ,int *i , float *e,menu *m) 
{ 


SDL_Event event;

int continuer=1,x=0,done=1;
m->posmoins.x=370 ; 
m->posmoins.y=130 ;
m->moins=IMG_Load("option/MINUS_BUTTON.png") ;
m->moins1=IMG_Load("option/MINUS_BUTTON_HOVER.png") ;
Mix_AllocateChannels(2);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unable to initialize SDL: %s\n",SDL_GetError());
//return 1;
}
//screen=SDL_SetVideoMode(960,660,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
//
int ez;
FILE* fichier = NULL;
fichier = fopen("ez.txt","r");
fscanf(fichier,"%d",&ez);
if(ez == 1){
m->image=IMG_Load("option/final-background.png");
}else{
m->image=IMG_Load("option/final-background.png");
}
m->image2=IMG_Load("option/MENU_OPTION.png");

if((*a)%2==0)
{
m->son=IMG_Load("Mute off.png");

}
else
{
m->son=IMG_Load("Mute on.png");

}
m->retour=IMG_Load("option/BUTTON_BACK.png");
m->retour1=IMG_Load("option/BUTTON_BACK_HOVER.png");
if((*i)%2==0)
{
m->modescreen=IMG_Load("option/BUTTON_FULL_SCREEN.png");

m->posmodescreen.x=500;
m->posmodescreen.y=280;
m->posmodescreen1.x=380;
m->posmodescreen1.y=560;

}
else
{
m->modescreen=IMG_Load("option/BUTTON_WINDOWED.png");
m->posmodescreen.x=500;
m->posmodescreen.y=280;
m->posmodescreen1.x=500;
m->posmodescreen1.y=280;

}
m->volume=IMG_Load("option/azer.png");
m->volume1=IMG_Load("Curseur Volume.png");
m->image->w=1000;
m->image->h=563;


m->posretour.x=280;
m->posretour.y=280;
m->posplus.x=740 ;
m->posplus.y=130 ; 
m->plus=IMG_Load("option/PLUS_BUTTON_HOVER.png");
m->plus1=IMG_Load("option/PLUS_BUTTON.png");
m->posvolume.x =425;
m->posvolume.y=145;
m->posvolume1.x=(*e)*(245)+m->posvolume.x-20 ; 
m->posvolume1.y =130;
m->posson.x=200;
m->posson.y=262 ; 

m->postionimage.x=0 ;
m->postionimage.y=0 ;
m->postionimage2.x=40 ;
m->postionimage2.y=20 ;

SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_BlitSurface(m->son,NULL,screen,&m->posson);
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume);
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1);
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);

    
    

while(continuer)
{
done=1;
SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_QUIT:
continuer=0;
SDL_Flip(screen);
break;
case SDL_MOUSEMOTION:
 if((event.motion.x<m->posretour.x+328&&event.motion.x>m->posretour.x)&&(event.motion.y<m->posretour.y+66&&event.motion.y>m->posretour.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage)      ;
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2)    ;
SDL_BlitSurface(m->retour1,NULL,screen,&m->posretour)       ;
SDL_BlitSurface(m->son,NULL,screen,&m->posson)              ;
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume)        ;
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1)      ;
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);
}
else if((event.motion.x<m->posson.x+71&&event.motion.x>m->posson.x)&&(event.motion.y<m->posson.y+59&&event.motion.y>m->posson.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_BlitSurface(m->son1,NULL,screen,&m->posson);
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume);
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1);
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);

}

  else if((event.motion.x<m->posplus.x+59&&event.motion.x>m->posplus.x)&&(event.motion.y<m->posplus.y+60&&event.motion.y>m->posplus.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_BlitSurface(m->son,NULL,screen,&m->posson);
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume);
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1);
SDL_BlitSurface(m->plus1,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);

}

  else if((event.motion.x<m->posmoins.x+65&&event.motion.x>m->posmoins.x)&&(event.motion.y<m->posmoins.y+34&&event.motion.y>m->posmoins.y))
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_BlitSurface(m->son,NULL,screen,&m->posson);
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume);
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1);
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins1,NULL,screen,&m->posmoins);
SDL_Flip(screen);

}
   
   
else 
{
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage)      ;
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2)    ;
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour)        ;
SDL_BlitSurface(m->son,NULL,screen,&m->posson)              ;
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume)        ;
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1)      ;
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);
}
break;
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posretour.x+328&&event.button.x>m->posretour.x)&&(event.button.y<m->posretour.y+66&&event.button.y>m->posretour.y))
{
continuer=0;
int_menu(screen,musique,&m);
SDL_Flip(screen);


}
else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posson.x+71&&event.button.x>m->posson.x)&&(event.button.y<m->posson.y+59&&event.button.y>m->posson.y))
{
(*a)++ ;

if((*a)%2==1)
{
Mix_PauseMusic();
m->son =IMG_Load("Mute on.png") ;

}
else 
{
	Mix_ResumeMusic();
	m->son =IMG_Load("Mute off.png") ;

}
}
else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posmodescreen.x+227&&event.button.x>m->posmodescreen.x)&&(event.button.y<m->posmodescreen.y+79&&event.button.y>m->posmodescreen.y))
{

           (*i)++  ; 
       if ((*i)%2==0) 
       
       
        	    {
        	    putenv("SDL_VIDEO_CENTERED=1");	 
        	        	    screen = SDL_SetVideoMode(1000, 563,32, SDL_HWSURFACE| SDL_DOUBLEBUF|SDL_FULLSCREEN);
  c = 1;
  SDL_Flip(screen);

        	    }
        else
        	        	   {
        	        	   
        	    m->modescreen=IMG_Load("option/BUTTON_WINDOWED.png");
        	    
m->posmodescreen.x=500;
m->posmodescreen.y=280;
m->posmodescreen1.x=500;
m->posmodescreen1.y=280;

        	        	   putenv("SDL_VIDEO_CENTERED=1");	 
    
        	        	    screen = SDL_SetVideoMode(1000, 563,32, SDL_HWSURFACE| SDL_DOUBLEBUF);
        	 

	SDL_Flip(screen);

        	        	   }
        	

}
else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posvolume.x+245&&event.button.x>m->posvolume.x)&&(event.button.y<m->posvolume.y+25&&event.button.y>m->posvolume.y))
{ 
 
m->posvolume1.x=event.button.x ;
*e=event.button.x - m->posvolume.x;
(*e)=(*e)/245 ; 
Mix_VolumeMusic(MIX_MAX_VOLUME * (*e))  ; 

SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2)    ;
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour)        ;
SDL_BlitSurface(m->son,NULL,screen,&m->posson)              ;
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume)        ;
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1)      ;
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);


}

else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posplus.x+59&&event.button.x>m->posplus.x)&&(event.button.y<m->posplus.y+60&&event.button.y>m->posplus.y))
{ 
(*e)=1;

m->posvolume1.x=(*e)*(245)+m->posvolume.x -20; 

Mix_VolumeMusic(MIX_MAX_VOLUME * (*e))  ; 

SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2)    ;
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour)        ;
SDL_BlitSurface(m->son,NULL,screen,&m->posson)              ;
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume)        ;
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1)      ;
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);


}


else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posmoins.x+65&&event.button.x>m->posmoins.x)&&(event.button.y<m->posmoins.y+34&&event.button.y>m->posmoins.y))
{ 
(*e)=0;

m->posvolume1.x=(*e)*(245)+m->posvolume.x-20 ; 

Mix_VolumeMusic(MIX_MAX_VOLUME * (*e))  ; 

SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2)    ;
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour)        ;
SDL_BlitSurface(m->son,NULL,screen,&m->posson)              ;
SDL_BlitSurface(m->modescreen,NULL,screen,&m->posmodescreen);
SDL_BlitSurface(m->volume,NULL,screen,&m->posvolume)        ;
SDL_BlitSurface(m->volume1,NULL,screen,&m->posvolume1)      ;
SDL_BlitSurface(m->plus,NULL,screen,&m->posplus);
SDL_BlitSurface(m->moins,NULL,screen,&m->posmoins);
SDL_Flip(screen);


}



}
}


}

void play(SDL_Surface *screen , Mix_Music *musique,menu *m )
{


SDL_Event event;


m->image = IMG_Load("option/final-background.png");

m->retour=IMG_Load("option/BUTTON_BACK.png");
m->retour1=IMG_Load("option/BUTTON_BACK_HOVER.png");


m->image2 = IMG_Load("New game/back.png");
m->newgame = IMG_Load("New game/New-Game.png");
m->newgame1 = IMG_Load("New game/New-game-pressed.png");

m->loadgame = IMG_Load("New game/Load-Game.png");
m->loadgame1 = IMG_Load("New game/Load-game-pressed.png");

int continuer=1 ; 
m->postionimage.x=0 ;
m->postionimage.y=0 ;
m->posloadgame.x=500 ;
m->posloadgame.y=150 ;
m->posnewgame.x=150 ;
m->posnewgame.y=150;
m->postionimage2.x=30 ;
m->postionimage2.y=0 ;
m->posretour.x=310 ; 
m->posretour.y=400 ; 




SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
SDL_Flip(screen);

while(continuer)
{

SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_QUIT:
continuer=0;
SDL_Flip(screen);
break;
case SDL_MOUSEMOTION:
                if((event.button.x<m->posretour.x+331&&event.button.x>m->posretour.x)&&(event.button.y<m->posretour.y+66&&event.button.y>m->posretour.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
                SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
                SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->retour1,NULL,screen,&m->posretour);
                SDL_Flip(screen);

                
                }
                else if((event.motion.x< m->posnewgame.x+300 &&event.motion.x> m->posnewgame.x)&&(event.motion.y<m->posnewgame.y+225&&event.motion.y>m->posnewgame.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
                 SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
                 SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->newgame1,NULL,screen,&m->posnewgame);
                SDL_Flip(screen);

                
                }
                                else if((event.motion.x< m->posloadgame.x+300 &&event.motion.x> m->posloadgame.x)&&(event.motion.y<m->posloadgame.y+225&&event.motion.y>m->posloadgame.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
                 SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
                 SDL_BlitSurface(m->loadgame1,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->newgame1,NULL,screen,&m->posnewgame);
                SDL_Flip(screen);

                
                }
                else
                
                {
                
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->image2,NULL,screen,&m->postionimage2);
                SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
                SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
                SDL_Flip(screen);

                
                }
                
                
break;
case SDL_MOUSEBUTTONDOWN :

if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posretour.x+331&&event.button.x>m->posretour.x)&&(event.button.y<m->posretour.y+66&&event.button.y>m->posretour.y))
{
continuer=0;
int_menu(screen,musique,&m);
SDL_Flip(screen);


}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x< m->posnewgame.x+300 &&event.button.x> m->posnewgame.x)&&(event.button.y<m->posnewgame.y+225&&event.button.y>m->posnewgame.y))
{
continuer=0;
Characters(screen,musique,&m);
SDL_Flip(screen);


}

}
}




}void Characters(SDL_Surface *screen , Mix_Music *musique,menu *m )
{


SDL_Event event;


m->image = IMG_Load("option/final-background.png");

m->retour=IMG_Load("option/BUTTON_BACK.png");
m->retour1=IMG_Load("option/BUTTON_BACK_HOVER.png");



m->newgame = IMG_Load("Levels/level-1.png");
m->newgame1 = IMG_Load("Levels/level1-pressed.png");

m->loadgame = IMG_Load("Levels/level-2.png");
m->loadgame1 = IMG_Load("Levels/level-2c-pressed.png");

int continuer=1 ; 
m->postionimage.x=0 ;
m->postionimage.y=0 ;
m->posloadgame.x=500 ;
m->posloadgame.y=80 ;
m->posnewgame.x=150 ;
m->posnewgame.y=30;
m->posretour.x=310 ; 
m->posretour.y=400 ; 




SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
SDL_Flip(screen);

while(continuer)
{

SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_QUIT:
continuer=0;
SDL_Flip(screen);
break;
case SDL_MOUSEMOTION:
                if((event.button.x<m->posretour.x+331&&event.button.x>m->posretour.x)&&(event.button.y<m->posretour.y+66&&event.button.y>m->posretour.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
                SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->retour1,NULL,screen,&m->posretour);
                SDL_Flip(screen);

                
                }
                else if((event.motion.x< m->posnewgame.x+300 &&event.motion.x> m->posnewgame.x)&&(event.motion.y<m->posnewgame.y+100&&event.motion.y>m->posnewgame.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
                SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->newgame1,NULL,screen,&m->posnewgame);
                SDL_Flip(screen);

                
                }
                                else if((event.motion.x< m->posloadgame.x+300 &&event.motion.x> m->posloadgame.x)&&(event.motion.y<m->posloadgame.y+100&&event.motion.y>m->posloadgame.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
                SDL_BlitSurface(m->loadgame1,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
                SDL_Flip(screen);

                
                }
                else
                
                {
                
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
                SDL_BlitSurface(m->loadgame,NULL,screen,&m->posloadgame);
                SDL_BlitSurface(m->newgame,NULL,screen,&m->posnewgame);
                SDL_Flip(screen);

                
                }
                
                
break;
case SDL_MOUSEBUTTONDOWN :

if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posretour.x+331&&event.button.x>m->posretour.x)&&(event.button.y<m->posretour.y+66&&event.button.y>m->posretour.y))
{
continuer=0;
int_menu(screen,musique,&m);
SDL_Flip(screen);


}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x< m->posnewgame.x+300 &&event.button.x> m->posloadgame.x)&&(event.button.y<m->posloadgame.y+100&&event.button.y>m->posloadgame.y))
{
continuer=0;
SDL_Quit();
system("./prog");

SDL_Flip(screen);


}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x< m->posloadgame.x+300 &&event.button.x> m->posnewgame.x)&&(event.button.y<m->posnewgame.y+225&&event.button.y>m->posnewgame.y))
{
continuer=0;
SDL_Quit();
system("./level2");

SDL_Flip(screen);


}
}
}




}


//
void creditt(SDL_Surface *screen , Mix_Music *musique,menu*m )
{



SDL_Event event;
int a= 0 , i =1 ; 
float e = 1 ;
int ez;
FILE* fichier = NULL;
fichier = fopen("ez.txt","r");
fscanf(fichier,"%d",&ez);
if(ez == 1){
m->image = IMG_Load("res1/BACKGROUND.png");
}else{
m->image = IMG_Load("res2/BACKGROUND.png");
}
m->retour=IMG_Load("option/BUTTON_BACK.png");
m->retour1=IMG_Load("option/BUTTON_BACK_HOVER.png");

int continuer=1 ; 
m->postionimage.x=0 ;
m->postionimage.y=0 ;
m->postionimage1.x=0 ;
m->postionimage1.y=0 ;
m->posretour.x=300 ; 
m->posretour.y=460 ; 
SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
SDL_BlitSurface(m->image1,NULL,screen,&m->postionimage1);
                 txtee(screen) ;
SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);
SDL_Flip(screen);

while(continuer)
{

SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_QUIT:
continuer=0;
SDL_Flip(screen);
break;
case SDL_MOUSEMOTION:
                if((event.motion.x<m->posretour.x+173&&event.motion.x>m->posretour.x)&&(event.motion.y<m->posretour.y+158&&event.motion.y>m->posretour.y))
                {
                
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                                SDL_BlitSurface(m->image1,NULL,screen,&m->postionimage1);
                                                 txtee(screen) ;
                SDL_BlitSurface(m->retour1,NULL,screen,&m->posretour);

                SDL_Flip(screen);

                
                }
                else
                
                {
                
                        txtee(screen) ;
                SDL_BlitSurface(m->image,NULL,screen,&m->postionimage);
                SDL_BlitSurface(m->image1,NULL,screen,&m->postionimage1);
                                        txtee(screen) ;
                SDL_BlitSurface(m->retour,NULL,screen,&m->posretour);

                SDL_Flip(screen);

                
                }
                
                
                
break;
case SDL_MOUSEBUTTONDOWN :

if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<m->posretour.x+331&&event.button.x>m->posretour.x)&&(event.button.y<m->posretour.y+69&&event.button.y>m->posretour.y))
{
continuer=0;
int_menu(screen,musique,&m);
SDL_Flip(screen);
SDL_Delay(100);


}

}
}




}


void animation(SDL_Surface *screen,menu *m)
{

m->posbackground.x=m->posbackground.y=0;
char e[30];


m->jouer=IMG_Load("play.png");
m->jouer1=IMG_Load("pp.png");
m->parametre1=IMG_Load("settings.png");
m->parametre=IMG_Load("settings1.png");
m->quitter=IMG_Load("exit1.png");
m->quitter1=IMG_Load("exit.png");
m->personnage=IMG_Load("per.png");
m->credit=IMG_Load("credit1.png");
m->credit1=IMG_Load("credit.png");
m->postionimage.x=0;
m->postionimage.y=0;
m->postionjoueur.x=0;
m->postionjoueur.y=0;
m->poscredit.x=380 ; 
m->poscredit.y=575 ; 


m->posjouer.x=545;
m->posjouer.y=344;
m->posparametre.x=461;
m->posparametre.y=460;
m->posquitter.x=300;
m->posquitter.y=695;
//

    for(int i=1;i<61;i++)
    

    {
        sprintf(e,"animation0/00%d.jpg",i);
                SDL_BlitSurface(IMG_Load(e), NULL, screen, &m->posbackground);
              //  SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(m->jouer1,NULL,screen,&m->posjouer);
SDL_BlitSurface(m->parametre1,NULL,screen,&m->posparametre);
SDL_BlitSurface(m->quitter,NULL,screen,&m->posquitter);
SDL_BlitSurface(m->credit,NULL,screen,&m->poscredit);

          SDL_Flip(screen);
      SDL_Delay(70); 

//

}
        
    
					//txtee(ecran)         ;


}


void txtee(SDL_Surface *ecran)
{

TTF_Font * fonttest=NULL;
SDL_Color colorCoor={0,186,148};
SDL_Surface *a,*z,*e,*r,*t,*y;
SDL_Rect ra,rz,re,rr,rt,ry;


TTF_Init();
ra.x=30 ; 
ra.y=210 ; 
rz.x=30 ; 
rz.y=260 ;
re.x=30 ; 
re.y=310 ;
rr.x=30 ; 
rr.y=360 ; 
rt.x=30 ; 
rt.y=410 ;
ry.x=30 ; 
ry.y=460 ;    
fonttest=TTF_OpenFont("1.ttf",30);
a=TTF_RenderText_Blended (fonttest,"Mohamed Mokdad",colorCoor);
z=TTF_RenderText_Blended (fonttest,"Farah Barka",colorCoor);
e=TTF_RenderText_Blended (fonttest,"Farah Hammami",colorCoor);
r=TTF_RenderText_Blended (fonttest,"Yassine Chagouani",colorCoor);
t=TTF_RenderText_Blended (fonttest,"Boubaker Hachicha",colorCoor);
y=TTF_RenderText_Blended (fonttest,"Youcef Kharoubi",colorCoor);
        SDL_BlitSurface(a, NULL, ecran, &ra);
        SDL_BlitSurface(z, NULL, ecran, &rz);
        SDL_BlitSurface(e, NULL, ecran, &re);
        SDL_BlitSurface(r, NULL, ecran, &rr);
        SDL_BlitSurface(t, NULL, ecran, &rt);
        SDL_BlitSurface(y, NULL, ecran, &ry);

        
        

}




