#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "es.h"

void initEnnemi(enemy *e)
{
	e->dir=0;
	e->pos.x=0;
	e->pos.y=0;
	e->pos.w=100;
	e->pos.h=100;
	e->poss.x=0;
	e->poss.y=0;
	e->img=IMG_Load("ennemi_spr.png");
	//e->s=waiting;
	
}


void afficherEnnemi(enemy e, SDL_Surface * screen)
{

		SDL_BlitSurface(e.img,&e.pos,screen,&e.poss);
}

void animerEnnemi( enemy * e)
{
	//dir=0 maanetha ki bsh ymshi aalimin
	if(e->dir==0)
		{
		if(e->pos.x==300)//ken wslt l ekhr frame
			e->pos.x=0;
		else
			e->pos.x=e->pos.x+e->pos.w;
		}
	if(e->dir==1)
		{
			if(e->pos.x==0)
			e->pos.x=300;
		else
			e->pos.x=e->pos.x-e->pos.w;}		
}


void deplacer( enemy * e)
{
	if(e->pos.x==300)
		{e->dir=1;
			e->pos.y=100;}
	if(e->pos.x==0)
		{e->dir=0;
			e->pos.y=0;}
	if(e->dir==0)
		e->poss.x++;
	else
		e->poss.x--;
}

void deplacerp( enemy * e)
{
	if(e->pos.x==300)
		{e->dir=1;
			e->pos.y=100;}
	//if(e->pos.x==0)
		//{e->dir=0;
			//e->pos.y=0;}
	if(e->dir==0)
		e->poss.x++;
	else
		e->poss.x--;
}

int collisionBB( enemy p, enemy e)
{
	 if ((p.poss.x + p.pos.w< e.poss.x)||(p.poss.x> e.poss.x + e. pos.w))
    return 0;
  else
    return 1;
}

//void updateEnnemi (enemy *e, SDL_Rect p.pos );
//{
	//switch(e->s)
	//{
		//case waiting:
		//animerEnnemi(&(*e));
		//break;
		//case following://follow du perso
		//{animerEnnemi(&(*e)); // walking pics
		//deplacer(&(*e)); // enemy ymshi lel perso
		//case attacking:
		//animerEnnemi(&(*e));//attacking pics
		//deplacer(&(*e)); // enemy ymshi lel perso
	//}
	//calcul distance bin el enemy wl perso
	//maj de e->s
//}