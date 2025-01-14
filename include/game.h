#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#define OUI 1
#define NON 0
#define VALEUR_DE_SORTIE_TS 4

typedef enum {
    ROUGE,
    VERT,
    JAUNE,
    BLEU
} Couleur_TS;

typedef struct {
    int case_sortie_TS; // defini a quel case le pion doit commencer la sortie
    int case_de_fin_de_sortie_TS; // case qui defini la fin de sortie du pion
    int position_case_TS;
    SDL_Point start_position;
    int est_sortie;
    SDL_Rect rectangle_TS;    
    Couleur_TS couleur_TS;
} Pion_TS;


typedef struct {
    Couleur_TS couleur_TS;
    Pion_TS pions_TS[4];
    int position_depart_joueur_TS;
} Joueur_TS;


int tourne_de_TS(int * valeur_de_TS);

int tour_suivant_TS(Joueur_TS joueurs[], int * tour_joueur_TS, int nombre_joueurs, int valeur_de_TS);

int possede_encore_un_pion_sur_le_terrain_TS(Joueur_TS joueurs_TS[], int nombre_joueurs_TS);

int verifie_victoire_TS(Joueur_TS joueurs_TS[], int nombre_joueurs_TS);



#endif