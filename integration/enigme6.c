#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme6.h"




void init_enigme1(Enigme * e, char nomfichier[20])
{

	e->p.x=0;
	e->p.y=0;
	
	e->pv.x=200;
	e->pv.y=445;	
	
	e->pf.x=700;
	e->pf.y=445;	
	                                                                                                        
	                                                                                                       
	                                                                                                       
	
	
	int  i=0 ;
    srand(time(NULL));
	      e->l=1+rand()%6;

		
	FILE* fichier = NULL;
	
    fichier = fopen(nomfichier, "r");
 
    if (fichier != NULL)
    {
        while ((fgets(e->txt, 200, fichier) != NULL)&&(i<(e->l-1)) )
        {
     i++      ;
        }
   


        fclose(fichier);
    }
	

 

	
	
	        e->img= IMG_Load("background6.gif");
	

}



 void generate_afficher1 (SDL_Surface * screen  ,  Enigme e)
{ 

	char phrase[30];


SDL_Surface *coordinates;
SDL_Rect coordinatespos;


sprintf(phrase,"question/%d.png",e.l);

coordinatespos.x=290;
coordinatespos.y=150;
e.img1 = IMG_Load(phrase);
printf("%s",e.txt);
SDL_BlitSurface(e.img,NULL,screen,&e.p);
SDL_BlitSurface(e.img1, NULL, screen, &coordinatespos);

SDL_Flip(screen) ;                            
  
  
  
}
 

 
 
 
 int solution_e1 (int x)
 {
 	int solution =0 ;
 	
 	if(x==6)
 	{
     solution =1 ;
 	}
 	else  	 	if(x==1)
 	{
 		solution =2;

 	}
 	else 	 	if(x==2)
 	{
 		solution =1;	
 	}
 	else 	 	if(x==3)
 	{
 		solution =1;	
 	}
 	else 	 	if(x==4)
 	{
 		solution =2;	
 	}
 	else 	 	if(x==5)
 	{
 		solution =2;	
 	}
 	
 	
 	
 	
 	
 	return solution;
 }
 
 


int resolution1 (int *run ,Enigme * e ,SDL_Surface *screen)
{
int runn =1 ; 
	SDL_Event event ;
  int r=0 ;
  
  
  
  

	
	while(runn)
	{
	
SDL_WaitEvent(&event);
	
	
	switch(event.type)
	{
		  case SDL_QUIT:
	
                *run = 0;
                runn=0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			   r= 1;
			   runn =0 ; 
			   break ;
			   case  SDLK_z :
			   r= 2;
			     runn =0 ; 
			   break;
			 
			   
			   
			   
	        }
	        
              break ; 
              
                            
                              case SDL_MOUSEBUTTONDOWN:
         if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<e->pv.x+154&&event.button.x>e->pv.x)&&(event.button.y<e->pv.y+123&&event.button.y>e->pv.y))
{

   r= 1;
			   runn =0 ; 


}
else       if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<e->pf.x+154&&event.button.x>e->pf.x)&&(event.button.y<e->pf.y+123&&event.button.y>e->pf.y))
{

   r= 2;
			   runn =0 ; 




}
                 
	}
	
	}

  return r ;
  
  
}




 
 void afficher_resultat1 (SDL_Surface * screen,int s,int r )
 {
 
 
 
SDL_Rect posbackground;
posbackground.x=posbackground.y=100;
char e[30];


 
if (r==s)
 	{
 	
 	
 	   for(int i=0;i<22;i++)
    

    {
        sprintf(e,"loading_t6/%d.gif",i);
                SDL_BlitSurface(IMG_Load(e), NULL, screen, &posbackground);
          SDL_Flip(screen);
          SDL_Delay(100); 



}
 
 	}
 	
 	else if(r!=0)
 	
 	{
 	
 	

 	   for(int i=0;i<32;i++)
    

    {
        sprintf(e,"loading_f6/%d.gif",i);
                SDL_BlitSurface(IMG_Load(e), NULL, screen, &posbackground);
          SDL_Flip(screen);
          SDL_Delay(100); 



}
 	
 	

 	
 	}

 }

void pregame1(SDL_Surface*screen)
{

SDL_Surface *background;
SDL_Rect posbackground;
posbackground.x=0;
posbackground.y=0;
SDL_Event event;
char e[30];


SDL_Surface *x;


int quit = 0;









for (int i = 0; i < 21 && !quit; i++) {
    
    sprintf(e, "animation6/%d.png", i);
    x = IMG_Load(e);
    SDL_BlitSurface(x, NULL, screen, &posbackground);
    
    SDL_Delay(100);
    SDL_Flip(screen);
    SDL_FreeSurface(x);

    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
           
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                quit = 1;
    		
    		
                break;
            }
        }sprintf(e, "animation/%d.png", i);
    x = IMG_Load(e);
    SDL_BlitSurface(x, NULL, screen, &posbackground);
    }
}
    
    

}

 int enigme_jeu1(SDL_Surface *screen)
{ 


	Enigme  e;
	 Mix_Music *musique;
Mix_Music *musique1;
	int s,r,run =1;
	char txt[30]="";
	
	 
  TTF_Init();

	 SDL_Init ( SDL_INIT_VIDEO ) ;

	 screen= SDL_SetVideoMode(1120,630,32,SDL_HWSURFACE |  SDL_DOUBLEBUF ); 

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }
	   musique=Mix_LoadMUS("mesic/begin.mp3");
		
Mix_PlayMusic(musique,-1);
         
	
   pregame1(screen);
	
  
Mix_CloseAudio();

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }
	   musique=Mix_LoadMUS("mesic/letsplay.mp3");
		
Mix_PlayMusic(musique,-1);
         
	Mix_CloseAudio();
	
	

	 
	 while (run)
	 {
	 	 init_enigme1(&e,"fic");


	 r=0 ;
		

         generate_afficher1 (screen,e) ;



     
      
printf("%d",e.l)  ;	
      s=solution_e1 (e.l );
      printf("%d",s)  ;	

			r=resolution1 (&run,&e,screen);
			printf("%d",r)  ;
			printf("\n");	

		if(run==1)	
       afficher_resultat1 (screen,s,r) ; 
   }

      
	return 0;
}
