#ifndef _UI_H
#define _UI_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"

typedef struct {
    int x_TS;
    int y_TS;
    int position_case_TS;
} Coordonnees_Case_TS;

void intialise_ludo_TS(
    int * valeur_de_TS,
    int * tour_joueur_TS,
    int * nombre_joueurs_TS,
    Joueur_TS joueurs_TS[]);

/// @brief cette fonction va creer texture pour l image passe en parametres
/// @param chemin_image_TS 
/// @param renderer_TS 
SDL_Texture * cree_texture_image_TS(const char chemin_image_TS[], SDL_Renderer * renderer_TS);

/// @brief verifie si un object est bien celui clique par la souris
/// @param event_x_TS 
/// @param event_y_TS 
/// @param start_x_TS 
/// @param start_y_TS 
/// @param width_TS 
/// @param height_TS 
/// @return 1 si oui 0 sinon
int verifie_click_TS(int event_x_TS, int event_y_TS, int start_x_TS, int start_y_TS, int width_TS, int height_TS);

void dessiner_rectangle_grosse_bordure_TS(
    SDL_Renderer * renderer_TS,
    SDL_Rect rect_TS,
    int epaisseur_TS
    );

void gere_click_pion_TS(
    SDL_Renderer * renderer_TS,
    Joueur_TS joueurs_TS[],
    int event_x_TS,
    int event_y_TS,
    int valeur_de_TS,
    int * tour_joueur_TS,
    int * click_du_de_autorise,
    int nombre_joueur,
    int * affiche_message_erreur_TS,
    Uint32 * start_time_message_TS,
    int * affiche_message_victoire_TS);

Coordonnees_Case_TS recherche_coordonnees_TS(int postion_TS);

/// @brief cette fonction assure la verification de la posibilite de manger un pion
/// @param joueur_TS 
/// @param tour_joueur_TS 
/// @param position_darrive_TS 
/// @param couleur_TS 
void verification_et_action_de_manger_pion_TS(
    Joueur_TS joueur_TS[],
    int tour_joueur_TS,
    int nb_joueur_TS,
    int position_darrive_TS,
    Couleur_TS couleur_TS);

static Coordonnees_Case_TS cases_TS[100] = {
    { 0, 0, 0 }, // case pour eviter la valeur 0
    { 60, 260, 1 },
    { 114, 260, 2 },
    { 168, 260, 3 },
    { 222, 260, 4 },
    { 276, 260, 5 },
    //
    { 326, 219, 6 },
    { 326, 174, 7 },
    { 326, 132, 8 },
    { 326, 88, 9 },
    { 326, 45, 10 },
    { 326, 2, 11 },
    //
    { 380, 2, 12 },
    { 433, 2, 13 },
    //
    { 433, 45, 14 },
    { 433, 88, 15 },
    { 433, 131, 16 },
    { 433, 174, 17 },
    { 433, 217, 18 },
    //
    { 487, 261, 19 },
    { 541, 261, 20 },
    { 595, 261, 21 },
    { 649, 261, 22 },
    { 703, 261, 23 },
    { 757, 261, 24 },
    //
    { 754, 304, 25 },
    { 754, 347, 26 },
    //
    { 703, 347, 27 },
    { 649, 347, 28 },
    { 595, 347, 29 },
    { 541, 347, 30 },
    { 487, 347, 31 },
    //
    { 434, 390, 32 },
    { 434, 435, 33 },
    { 434, 478, 34 },
    { 434, 522, 35 },
    { 434, 564, 36 },
    { 434, 607, 37 },
    //
    { 380, 607, 38 },
    { 326, 607, 39 },
    //
    { 326, 564, 40 },
    { 326, 522, 41 },
    { 326, 478, 42 },
    { 326, 435, 43 },
    { 326, 390, 44 },
    //
    { 272, 347, 45 },
    { 218, 347, 46 },
    { 164, 347, 47 },
    { 110, 347, 48 },
    { 56, 347, 49 },
    { 2, 347, 50 },
    //
    { 6, 304, 51 },
    { 6, 261, 52 },
    // sortie rouge
    { 60, 304, 100 },
    { 114, 304, 101 },
    { 168, 304, 102 },
    { 222, 304, 103 },
    { 276, 304, 104 },
    //sortie verte
    { 380, 45, 200 },
    { 380, 88, 201 },
    { 380, 131, 202 },
    { 380, 174, 203 },
    { 380, 217, 204 },
    // sortie jaune
    { 700, 304, 300 },
    { 646, 304, 301 },
    { 592, 304, 302 },
    { 538, 304, 303 },
    { 484, 304, 304 },
    // sortie bleu
    { 380, 564, 400 },
    { 380, 521, 401 },
    { 380, 478, 402 },
    { 380, 435, 403 },
    { 380, 392, 404 },

    // position de sortie du jeu
    { 900, 800, 1000 },

};

// tache restantes
// coordonnees des pions
// gestion du click pour l'avancer des pions (en maison ou sur le terrain)
// la gestion des mangement des pions
// la gestion des sortie des pions
// la gestion de l'affichage de la victoire
// la gestion de la nouvelle partie
#endif