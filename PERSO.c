/**
*@file PERSO.c
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
#include <math.h>


/**
* @brief initialize player, attributes player number(initialise le personnage et lui attribut un numero de joueur)
* @param p le personnage
* @param num_perso le numero de joueur(joueur 1,joueur 2,etc)
* @return nothing 
*/
void init(Personnage *p,int num_perso)
{
    p->player_number=num_perso;
}

/**
* @brief initialize player's score,lives and position(initialise le score ,le nombre de vie et la position du personnage)
* @param p le personnage
* @param ecran the screen(l'ecran)
* @return nothing 
*/
void init_perso(Personnage *p,SDL_Surface *ecran)
{
    int vitesse_max=1;

    p->nombre_vie=5;
    p->score=0;
    p->position.y=ecran->h/2;
    p->position.x=0;
    p->direction=-1;
    p->action=-1;
    p->vitesse=vitesse_max;
    p->acceleration=0;
}

/**
* @brief blit's players information
* @param p le personnage
* @param ecran the screen(l'ecran)
* @return nothing 
*/
void afficher_perso(Personnage p,SDL_Surface *ecran)
{
    TTF_Font *police=NULL;
    SDL_Surface *image_vie=NULL,*image_score=NULL,*image_player_num=NULL;
    char score[1000000],player_number[100];
    SDL_Color couleur= {255,255,255};
    SDL_Rect position_vie,position_score,position_num_player;
    int i;

    police=TTF_OpenFont("police.ttf",20);
    image_vie=IMG_Load("vie.png");


    sprintf(player_number,"PLAYER %d",p.player_number);
    image_player_num=TTF_RenderText_Blended(police,&player_number,couleur);

    sprintf(score,"SCORE: %0.f",p.score);
    image_score=TTF_RenderText_Blended(police,&score,couleur);


    if(p.player_number==1)
    {
        position_num_player.x=10;
        position_num_player.y=10;

        position_vie.x=position_num_player.x;
        position_vie.y=image_player_num->h+position_num_player.y;

        position_score.x=position_num_player.x;
        position_score.y=image_vie->h+position_vie.y;
    }
    else if(p.player_number==2)
    {
        position_num_player.x=ecran->w/2;
        position_num_player.y=10;

        position_vie.x=position_num_player.x;
        position_vie.y=image_player_num->h+position_num_player.y;

        position_score.x=position_num_player.x;
        position_score.y=image_vie->h+position_vie.y;
    }


    //SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(image_player_num,NULL,ecran,&position_num_player);
    for(i=0; i<p.nombre_vie; i++)
    {
        SDL_BlitSurface(image_vie,NULL,ecran,&position_vie);
        position_vie.x=position_vie.x+image_vie->w+5;
    }
    SDL_BlitSurface(image_score,NULL,ecran,&position_score);
    SDL_BlitSurface(p.image_actuel,&p.position_sprite,ecran,&p.position);
}

/**
* @brief move player(deplacer le personnage)
* @param p le personnage
* @param dt time(le temps)
* @return nothing 
*/
void deplacer_perso(Personnage *p,int dt)
{
    int dx;

    dx=((p->acceleration/2)*(dt*dt))+(p->vitesse*dt);

    if(p->direction==gauche)
        p->position.x=p->position.x-(dx/10);
    else if(p->direction==droite)
        p->position.x=p->position.x+(dx/10);
    else if(p->direction==haut)
        p->position.y=p->position.y-(dx/10);
    else if(p->direction==bas)
        p->position.y=p->position.y+(dx/10);

    /*p->direction=-1;
    p->action=-1;*/
}


/**
* @brief load image resources into animation array(charger les images dans le tableau d'animation)
* @param ANIMATION animation array(tableau d'animations)
* @return nothing 
*/
void charger_image_animation(animation ANIMATION[])
{
    /*marcher vres la droite*/
    ANIMATION[marcher_droite].sprite_sheet=IMG_Load("marcher_droite.png");
    ANIMATION[marcher_droite].largeur=100;
    ANIMATION[marcher_droite].x_max=ANIMATION[marcher_droite].sprite_sheet->w;
    ANIMATION[marcher_droite].num_sprite=marcher_droite;
    ANIMATION[marcher_droite].nombre_image=7;


    /*marcher vres la gauche*/
    ANIMATION[marcher_gauche].sprite_sheet=IMG_Load("marcher_gauche.png");
    ANIMATION[marcher_gauche].largeur=100;
    ANIMATION[marcher_gauche].x_max=ANIMATION[marcher_gauche].sprite_sheet->w;
    ANIMATION[marcher_gauche].num_sprite=marcher_gauche;
    ANIMATION[marcher_gauche].nombre_image=7;
}


void initialise_entity(Personnage *p,animation ANIMATION[])
{
    if(p->action==p->action_precedente)/*si on effectue la meme action qu'avant*/
    {
        p->position_sprite.x=p->position_sprite.x+ANIMATION[p->action].largeur;

        if(p->position_sprite.x>=ANIMATION[p->action].x_max)
            p->position_sprite.x=0;

        p->position_sprite.h=ANIMATION[p->action].sprite_sheet->h;
        p->position_sprite.w=ANIMATION[p->action].largeur;
        p->position_sprite.y=0;

        p->action=-1;
    }
    else if(p->action!=p->action_precedente)/*si on a changer d'action*/
    {
        p->image_actuel=ANIMATION[p->action].sprite_sheet;

        p->position_sprite.h=ANIMATION[p->action].sprite_sheet->h;
        p->position_sprite.w=ANIMATION[p->action].largeur;
        p->position_sprite.y=0;
        p->position_sprite.x=0;

        p->action_precedente=p->action;
        p->action=-1;
    }
    //p->direction=-1;
}

/**
* @brief animates player from spritessheets
* @param p le personnage
* @return nothing 
*/
void animer_perso(Personnage *p)
{
    animation ANIMATION[10];

    charger_image_animation(ANIMATION);
    initialise_entity(p,ANIMATION);
}



void saut(Personnage *p)
{
    if(p->direction==droite)
    {
        p->position.y-=60;
        p->position.x+=60;
    }
    else if(p->direction==gauche)
    {
        p->position.y-=60;
        p->position.x-=60;
    }
    else
        p->position.y-=60;

    p->image_actuel=NULL;
    p->direction=-1;
    p->action_precedente=p->action;
    p->action=-1;
}
