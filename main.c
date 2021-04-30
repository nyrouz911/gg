/**
*@file main.c
*@author MIGUEL ONANA
*@version 1.0
*@date 28/03/2021

*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "PERSO.h"
int main ( int argc, char** argv )
{
    SDL_Surface *ecran=NULL,*background=NULL;
    Personnage perso1,perso2;
    int continuer=1;
    SDL_Event evenement;
    int temps_actuel=0,temps_precedent=0,dt;
    Uint8 *keystate = SDL_GetKeyState(NULL);
SDL_Rect pos;
pos.x=0;
pos.y=0;
 
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    ecran=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    init(&perso1,1);
    init_perso(&perso1,ecran);
    perso1.image_actuel=IMG_Load("perso_vue_droite.png");
background=IMG_Load("background.jpg");
    perso1.position_sprite.x=0;
    perso1.position_sprite.y=0;
    perso1.position_sprite.w=perso1.image_actuel->w;
    perso1.position_sprite.h=perso1.image_actuel->h;



init(&perso2,2);
    init_perso(&perso2,ecran);
perso2.image_actuel=IMG_Load("perso_vue_droite.png");
perso2.position_sprite.x=0;
    perso2.position_sprite.y=0;
    perso2.position_sprite.w=perso1.image_actuel->w;
    perso2.position_sprite.h=perso1.image_actuel->h;
perso2.position.x=100;
perso2.position.y=perso1.position.y;

SDL_BlitSurface(background,NULL,ecran,&pos);
    afficher_perso(perso1,ecran);
    afficher_perso(perso2,ecran);

    SDL_Flip(ecran);

    while(continuer)
    {
        temps_actuel=SDL_GetTicks();
        dt=(temps_actuel-temps_precedent);
        temps_precedent=temps_actuel;

        SDL_PollEvent(&evenement);
        switch(evenement.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

/*perso1*/
        case SDL_KEYDOWN:
            switch(evenement.key.keysym.sym)
            {
            case SDLK_LEFT:
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
                perso1.direction=gauche;
                perso1.action=marcher_gauche;
                deplacer_perso(&perso1,dt);
                animer_perso(&perso1);

                afficher_perso(perso1,ecran);
		afficher_perso(perso2,ecran);
                //SDL_Flip(ecran);
                SDL_Delay(50);
                break;
            case SDLK_RIGHT:
                perso1.direction=droite;
                perso1.action=marcher_droite;
                deplacer_perso(&perso1,dt);
                animer_perso(&perso1);
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
                afficher_perso(perso1,ecran);
		afficher_perso(perso2,ecran);
                //SDL_Flip(ecran);
                SDL_Delay(50);

                break;
            case SDLK_UP:
                perso1.direction=haut;
                perso1.action=monter;
                deplacer_perso(&perso1,dt);
                //animer_perso(&perso1);
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
                afficher_perso(perso1,ecran);
		afficher_perso(perso2,ecran);
               // SDL_Flip(ecran);
                SDL_Delay(50);
                break;
            case SDLK_DOWN:
                perso1.direction=bas;
                perso1.action=descendre;
                deplacer_perso(&perso1,dt);
                //animer_perso(&perso1);
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
                afficher_perso(perso1,ecran);
		afficher_perso(perso2,ecran);
                //SDL_Flip(ecran);
                SDL_Delay(50);
                break;


/*perso2*/

	   case SDLK_j:
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
                perso2.direction=gauche;
                perso2.action=marcher_gauche;
                deplacer_perso(&perso2,dt);
                animer_perso(&perso2);

		afficher_perso(perso1,ecran);
                afficher_perso(perso2,ecran);
                //SDL_Flip(ecran);
                SDL_Delay(50);
                break;
            case SDLK_l:
                perso2.direction=droite;
                perso2.action=marcher_droite;
                deplacer_perso(&perso2,dt);
                animer_perso(&perso2);
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
		afficher_perso(perso1,ecran);
                afficher_perso(perso2,ecran);
                //SDL_Flip(ecran);
                SDL_Delay(50);
                break;
            case SDLK_i:
                perso2.direction=haut;
                perso2.action=monter;
                deplacer_perso(&perso2,dt);
                //animer_perso(&perso1);
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
		afficher_perso(perso1,ecran);
                afficher_perso(perso2,ecran);
                //SDL_Flip(ecran);
                SDL_Delay(50);
                break;
            case SDLK_k:
                perso2.direction=bas;
                perso2.action=descendre;
                deplacer_perso(&perso2,dt);
                //animer_perso(&perso1);
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(background,NULL,ecran,&pos);
		afficher_perso(perso1,ecran);
                afficher_perso(perso2,ecran);
               // SDL_Flip(ecran);
                SDL_Delay(50);
                break;

            case SDLK_q:
                perso1.acceleration=perso1.acceleration+0.005;
                break;
            case SDLK_w:
                perso1.acceleration=perso1.acceleration-0.01;
                break;
            case SDLK_t:
                if(keystate[SDLK_LEFT])
                    perso1.direction=gauche;
                else if(keystate[SDLK_RIGHT])
                    perso1.direction=droite;

                saut(&perso1);
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
SDL_BlitSurface(background,NULL,ecran,&pos);
//perso1.image_actuel=NULL;
                afficher_perso(perso1,ecran);
                perso1.image_actuel=IMG_Load("sauter_droite.png");
               SDL_BlitSurface(perso1.image_actuel,NULL,ecran,&perso1.position);
                SDL_Flip(ecran);
                SDL_Delay(250);

                perso1.position.y+=60;
                SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                SDL_BlitSurface(background,NULL,ecran,&pos);
                perso1.image_actuel=NULL;
                afficher_perso(perso1,ecran);

if(perso1.direction==gauche)
                perso1.image_actuel=IMG_Load("perso_vue_gauche.png");
else
perso1.image_actuel=IMG_Load("perso_vue_droite.png");

               SDL_BlitSurface(perso1.image_actuel,NULL,ecran,&perso1.position);
               // SDL_Flip(ecran);
                SDL_Delay(250);
                break;

            }
            break;
        }


        perso1.acceleration-=0.001;

        if(keystate[SDLK_q])
            perso1.acceleration=perso1.acceleration+0.005;
        if(keystate[SDLK_w])
            perso1.acceleration=perso1.acceleration-0.01;
        
        SDL_Flip(ecran);

    }
}
