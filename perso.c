#include "perso.h"


void initPerso(perso *p)
  
{ p->spritesheet=IMG_Load("perso.png");
    
    p->position.x=50;
    p->position.y=355;
    p->vitesse=0;
    p->vitesseV=0;

    p->pos_sprite.x= 0;
    p->pos_sprite.y= 200;
    p->pos_sprite.h= 100;
    p->pos_sprite.w= 100;
}


void initPerso2(perso *p2)
  
{ p2->spritesheet=IMG_Load("perso2.png");
    
    p2->position.x=50;
    p2->position.y=355;


    p2->vitesse=0;
    p2->vitesseV=0;

    
    p2->pos_sprite.x= 0;
    p2->pos_sprite.y= 200;
    p2->pos_sprite.h= 100;
    p2->pos_sprite.w= 100;
}




void afficherPerso(perso p, SDL_Surface * screen){
    SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.position);
}




void deplacerPerso (perso *p,int dt){
    double dx;
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 
    if ((p->direction==0))// || (p->direction==2))
    {
	if(p->position.x < 1500)
        p->position.x += dx ;
    }
    else if ((p->direction==1))
if(p->position.x > 30)
    p->position.x -= dx ;
   
}

void animerPerso (perso* p){

    p->pos_sprite.x += 100;
    if (p->pos_sprite.x >= 1500) 
    p->pos_sprite.x = 0;
    p->pos_sprite.y = p->direction * 100 ;

}
void saut (perso* p) {
    if (p->position.y==500)
    {
        p->vitesseV=-50;

    }
    if (p->position.y==600)
    {
        p->vitesseV=-50;

    }

    
}


void init_vie(perso *p){

p->image_vie[0]=IMG_Load("vie/3.png") ;
p->image_vie[1]=IMG_Load("vie/2.png") ;
p->image_vie[2]=IMG_Load("vie/1.png") ;
p->image_vie[3]=IMG_Load("vie/0.png") ;
p->position_vie.x = 30;
p->position_vie.y = 30;

}

void gestion_vie(perso *p){
 
p->vie--;

}

void init_score(perso *p){
	FILE *f = NULL;
	int ms;
	f = fopen("score.txt","r");
	fscanf(f,"%d",&ms);
	p->ms = ms;
	fclose(f);
	p->scoreI.img=IMG_Load("score.png");
	p->scoreI.pos1.x=800;
	p->scoreI.pos1.y=0;
	p->scoreT.font=TTF_OpenFont("Minecraft.ttf", 50);
	p->scoreT.col.r=0;
	p->scoreT.col.g=0;
	p->scoreT.col.b=0;
	p->score=0;
	p->scoreT.postxt.x=980;
	p->scoreT.postxt.y=20;
}
void init_score1(perso *p2){
	FILE *f = NULL;
	int ms;
	f = fopen("score.txt","r");
	fscanf(f,"%d",&ms);
	p2->ms = ms;
	fclose(f);
	p2->scoreI.img=IMG_Load("score.png");
	p2->scoreI.pos1.x=800;
	p2->scoreI.pos1.y=0;
	p2->scoreT.font=TTF_OpenFont("Minecraft.ttf", 50);
	p2->scoreT.col.r=0;
	p2->scoreT.col.g=0;
	p2->scoreT.col.b=0;
	p2->score=0;
	p2->scoreT.postxt.x=100;
	p2->scoreT.postxt.y=20;
}


void afficher_score(perso p, SDL_Surface * screen){
	
	char var[10];
	sprintf(var, "%d", p.score);   //concatisation
	p.scoreT.windtxt = TTF_RenderText_Blended(p.scoreT.font, var,p.scoreT.col); 
	SDL_BlitSurface(p.scoreT.windtxt,NULL,screen,&p.scoreT.postxt);
SDL_BlitSurface(p.scoreI.img,NULL,screen,&p.scoreI.pos1);
}

void afficher_score1(perso p2, SDL_Surface * screen){
	
	char var[10];
	sprintf(var, "%d", p2.score);   //concatisation
	p2.scoreT.windtxt = TTF_RenderText_Blended(p2.scoreT.font, var,p2.scoreT.col); 
	SDL_BlitSurface(p2.scoreT.windtxt,NULL,screen,&p2.scoreT.postxt);
SDL_BlitSurface(p2.scoreI.img,NULL,screen,&p2.scoreI.pos1);
}








