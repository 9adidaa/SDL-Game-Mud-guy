#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "perso.h"
#include "enigme.h"
#include "enigme6.h"
#include <time.h>

int main()
{ 

/*------partie declaration des variables-------*/

clock_t start_time, end_time;
double elapsed_time,elapsed_seconds,elapsed_minutes;
SDL_Surface *screen;
Background B,a,Back [20];
Background Red,Blue,Green,Yellow;
int hit,hit1,hit2,hit3,hit4;
	char ch[10];
	int n;
	TEXT t;
	int mult=0;
	char *fileName;
	SDL_Rect left_rect, right_rect;
	SDL_Surface *left_section, *right_section;
	right_section = IMG_Load("backg.jpg");
	SDL_Rect pos2;pos2.x=0;pos2.y=200;pos2.w=1000;pos2.h=1000;
    // Positionner les rectangles pour chaque section
    left_rect.x = 0;
    left_rect.y = 0;
    right_rect.x = 800;
    right_rect.y = 0;
    int enigmee=1;
TTF_Init();
SDL_Event event;
SDL_Surface *back;
SDL_Surface *coll;
perso p;
perso p2;
int now1=0, ex1=0;
int continuer=1,droite=0,gauche=0,up=0,dir=2,droite2=0,gauche2=0,up2=0,dir2=2;
Uint32 dt, t_prev;
p.vie = 3;

a.x = 0;
	initBackground(&B);
	
	initanimation(&a);


/*-------partie initialisation-------*/
screen=SDL_SetVideoMode (1600,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("Game",NULL);//titre de la fenetre

initPerso(&p);
initPerso2(&p2);
init_score(&p);
init_score1(&p2);
direction d;
start_time = clock();
p.image_vie[0]=IMG_Load("hearts/0%.png") ;
p.image_vie[1]=IMG_Load("hearts/30%.png") ;
p.image_vie[2]=IMG_Load("hearts/70%.png") ;
p.image_vie[3]=IMG_Load("hearts/100%.png") ;
// positions
 p.position_vie.x=60;
 p.position_vie.y=57;
 p.vie=3;
 int vies=3;
 
 p2.image_vie[0]=IMG_Load("hearts/0%.png") ;
p2.image_vie[1]=IMG_Load("hearts/30%.png") ;
p2.image_vie[2]=IMG_Load("hearts/70%.png") ;
p2.image_vie[3]=IMG_Load("hearts/100%.png") ;
// positions
 p2.position_vie.x=60;
 p2.position_vie.y=57;
 p2.vie=3;
 //------------gestion de vie--------//

 
 
vies--;
    if (vies==2)
    {
	SDL_FreeSurface(p.image_vie[0]);}
    else if (vies==1)
    {SDL_FreeSurface(p.image_vie[1]);}  
    else if (vies==0)
    {SDL_FreeSurface(p.image_vie[2]);}

/*--------- debut dboucle de jeu -----------*/
while (continuer)
{


 

now1=SDL_GetTicks();
t_prev=SDL_GetTicks();//prélevement du temps
	if(now1-ex1>500)
	{
		p.score+=10;
		p2.score+=10;
		ex1=now1;
	}
d.right=0;
d.left=0;
d.up=0;
d.down=0;
  /*-------- gestion de l'input--------*/  
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
	d.up = 0;
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                    up = 1;
                break;  
         case SDLK_d:
                droite2=1;
                break;
            case SDLK_q:
                gauche2=1;
                break;
            case SDLK_z:
                up2=1;
                break; 

      
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
                break;
            case SDLK_UP:
                up=0;
                d.up=1;
                saut(&p);
                
                break;    
		case SDLK_DOWN:
                d.down=1;
                scrolling(&B,&d);
                break; 

           case SDLK_d:
                droite2=0;
                dir2=2;
                p2.vitesse=0;
                break;
            case SDLK_q:
                gauche2=0;
                p2.vitesse=0;
                dir2=3;
                break;
            case SDLK_z:
                up2=0;
                break; 

    
        }
    break;
    
    }
}
           	 //fin de linput



/*-------------update----------*/

if (droite==1)
{
    p.vitesse=5;
    p.acceleration+=0.3;
    p.direction=0;


}
if (gauche==1)
{
    p.vitesse=5;
    p.acceleration+=0.3;
    p.direction=1;

}
if (up==1){ 
saut(&p);
}
if (droite2==1)
{
    p2.vitesse=5;
    p2.acceleration+=0.3;
    p2.direction=0;
}
if (gauche2==1)
{
    p2.vitesse=5;
    p2.acceleration+=0.3;
    p2.direction=1;
}
if (up2==1) 
{
saut(&p2);
}


p.acceleration -=0.3;
p2.acceleration -=0.3;
if (p.acceleration<0 ) p.acceleration=0;
if (p.acceleration>4) p.acceleration=4;



if (p2.acceleration<0 ) p2.acceleration=0;
if (p2.acceleration>4 ) p2.acceleration=4;

SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;//dt=t2-t1
deplacerPerso(&p,dt);
animerPerso(&p);
deplacerPerso(&p2,dt);
animerPerso(&p2);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;//mémorisation de direction droite de personne1
}

p.position.y += p.vitesseV;
p.vitesseV += 10; 
if (p.position.y >= 600)
{
    p.vitesseV=0;//yahbt wa7dou
    p.position.y=600;
}

if ((p2.vitesse==0)&&(p2.acceleration==0))
{
    p2.direction=dir2;//mémorisation de direction droite de personne2
}

p2.position.y += p2.vitesseV;
p2.vitesseV += 10; 
if (p2.position.y >= 600)
{
    p2.vitesseV=0;//perso2 yahbt wa7dou
    p2.position.y=600;
}

if(B.camera.x>7500){

FILE * fichier ;

end_time = clock();
fichier = fopen("ez.txt","w+");
elapsed_seconds = ((double) (end_time - start_time) / CLOCKS_PER_SEC);
int elapsed_seconds_int = (int) elapsed_seconds;
fprintf(fichier,"%d %d", 2, elapsed_seconds_int);
fclose(fichier);

SDL_Quit();
system("./game");
SDL_Flip(screen);
}

if((p.position.x ==hit)&&( p.position.y >= 600 && p.position.y<680)) {
p.vie--;
}







/*---------------affichage------------*/

SDL_BlitSurface(back,NULL,screen,NULL);
animation (&B,screen);
		animationsprite(&a,screen);
		B.L = 0;
		afficherBack (B,screen,left_section);
		
		a.x = a.x - 10;
		hit = afficherannimation(a,screen);
		B.L = 1;
		
		SDL_BlitSurface(right_section, &pos2, screen, &right_rect);
		//getdirection(&d,continuer,screen);
//scrolling(&B,&d);
afficherPerso(p,screen);
afficherPerso(p2,screen);
afficher_score(p,screen);
afficher_score1(p2,screen);
afficher_vie(p, screen);
afficher_vie1(p2, screen);
SDL_Flip(screen);
SDL_Delay(50);
printf("background :%d\n",B.camera.x);
printf("car :%d\n",hit);
printf("perso x:%d\n",p.position.x);
printf("perso y:%d\n",p.position.y);
printf("anim :%d\n",a.anim);


if((B.camera.x>2000)&&(enigmee)) {
enigmee=0;
enigme_jeu(screen);
d.up = 0;
screen = SDL_SetVideoMode(1600, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

if((B.camera.x>5000)&&(enigmee == 0)) {
enigmee=-1;
enigme_jeu1(screen);
d.up = 0;
screen = SDL_SetVideoMode(1600, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);}

if(p.position.x>400){
p.position.x=400;
d.right=1;
scrolling(&B,&d);
}
if(p.position.x<100){
p.position.x=100;
d.left=1;
scrolling(&B,&d);
}
if(p2.position.x<900)
p2.position.x=900;
if(p2.position.x>1500)
p2.position.x=1500;

}

}

