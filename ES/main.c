#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "es.h"

int main(void)
{
	SDL_Surface *screen=NULL,*back;
	SDL_Rect screenpos;
	SDL_Event event;
	enemy e,p;
	int loop=1,collision=0;

//init
	SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER);

	if(SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER)!=0)
{
	printf("error : %s\n",SDL_GetError());
	return 1;
}


screen=SDL_SetVideoMode(700,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL)
{
	printf("unable to set video mode : %s\n", SDL_GetError());
	return 1;

}

//init de la pos
screenpos.x=0;
screenpos.y=0;
e.pos.x=0;
e.pos.y=0;

p.pos.x=400;
p.pos.y=100;
p.pos.w=100;
p.pos.h=100;
p.poss.x=200;
p.poss.y=0;
p.img=IMG_Load("hero_spr.png");
back=IMG_Load("fond_ecran_option.png");

initEnnemi(&e);

while(loop)
{	
	SDL_BlitSurface(back,NULL,screen,&screenpos);
	afficherEnnemi(e,screen);
	p.dir=1;
	p.pos.y=100;
	afficherEnnemi(p,screen);

	deplacer(&e);
	p.dir=1;
	p.pos.y=100;
	deplacerp(&p);
	animerEnnemi(&e);
	p.dir=1;
	p.pos.y=100;
	animerEnnemi(&p);
	
	//collision bounding box
	collision=collisionBB(p,e);

	if(collision==1)
		printf("collision\n");
	//quitevent
	while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT://quitter en appuiant sur x
				loop=0;
				break;
			}
		}
	SDL_Flip(screen);
	SDL_Delay(50);

}

SDL_Quit();

	return 0;
}