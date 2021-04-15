#ifndef ES_H_INCLUDED
#define ES_H_INCLUDED


//structs
typedef enum state state;
enum state {waiting,following,attacking};

typedef struct 
{
	SDL_Surface *img;
	SDL_Rect pos,poss;
	int dir;
	state s;
}enemy;



//declaration des fonctions
void initEnnemi(enemy *e);//done
void afficherEnnemi(enemy e, SDL_Surface * screen);//done
void animerEnnemi( enemy * e);//done
void deplacer( enemy * e);//done
void deplacerp( enemy * e);//testi beha el dep taa lperso
int collisionBB( enemy p, enemy e); // int collisionBB( SDL_Rect posp,  SDL_Rect pose) ; done zeda
//void updateEnnemi (enemy *e, SDL_Rect p.pos );

#endif // ES_H_INCLUDED