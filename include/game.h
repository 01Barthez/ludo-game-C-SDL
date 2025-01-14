#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#define OUI 1
#define NON 0
#define VALEUR_DE_SORTIE_KLB 4

typedef enum {
    ROUGE,
    VERT,
    JAUNE,
    BLEU
} Couleur_KLB;

typedef struct {
    int case_sortie_KLB; // defini a quel case le pion doit commencer la sortie
    int case_de_fin_de_sortie_KLB; // case qui defini la fin de sortie du pion
    int position_case_KLB;
    SDL_Point start_position;
    int est_sortie;
    SDL_Rect rectangle_KLB;    
    Couleur_KLB couleur_KLB;
} Pion_KLB;


typedef struct {
    Couleur_KLB couleur_KLB;
    Pion_KLB pions_KLB[4];
    int position_depart_joueur_KLB;
} Joueur_KLB;


int tourne_de_KLB(int * valeur_de_KLB);

int tour_suivant_KLB(Joueur_KLB joueurs[], int * tour_joueur_KLB, int nombre_joueurs, int valeur_de_KLB);

int possede_encore_un_pion_sur_le_terrain_KLB(Joueur_KLB joueurs_KLB[], int nombre_joueurs_KLB);

int verifie_victoire_KLB(Joueur_KLB joueurs_KLB[], int nombre_joueurs_KLB);



#endif