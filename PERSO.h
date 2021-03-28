#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

/*constantes pour les actions*/
#define marcher_droite 0
#define marcher_gauche 1
#define monter 2
#define descendre 3
enum {gauche,droite,haut,bas}; //les directions

/*enum {courrir,frapper,marcher}; //les actions*/


typedef struct
{
    int nombre_vie;//le nombre de vie du personnage
    float score;//le score du personnage
    int player_number;//le numero de joueur( player 1 or player 2)
    SDL_Rect position;//la position du joueur
    int direction;//la direction du mouvement
    int action;//l'action effectué actuellement
    int action_precedente;//l'action precedente
    SDL_Surface *image_actuel;//le spritesheet utilise actuelement
    SDL_Rect position_sprite;//la position de la portion a afficher sur le spritesheet
    int vitesse;//la vitesse initial de deplacement du personnage
    int acceleration;//valeur de l'acceleration du personnage
} Personnage;


typedef struct
{
    SDL_Surface *sprite_sheet;//spritesheet
    int largeur;//largeur d'un sprite
    int x_max;//la valeur max de la cordonnee x pour l'affichage
    int num_sprite;//la constantes associé au spritesheet/la position dans le tableau d'animations
    int nombre_image;//le nombre d'images sur le sprite sheet
} animation;



void init(Personnage *p,int num_perso);

void init_perso(Personnage *p,SDL_Surface *ecran);

void afficher_perso(Personnage p,SDL_Surface *ecran);

void deplacer_perso(Personnage *p,int dt);

void charger_image_animation(animation ANIMATION[]);

void initialise_entity(Personnage *p,animation ANIMATION[]);

void animer_perso(Personnage *p);

void saut(Personnage *p);

#endif // PERSO_H_INCLUDED
