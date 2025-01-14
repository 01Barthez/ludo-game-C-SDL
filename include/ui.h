#ifndef _UI_H
#define _UI_H

    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "game.h"

    typedef struct {
        int x_KLB;
        int y_KLB;
        int position_case_KLB;
    } Coordonnees_Case_KLB;

    void intialise_ludo_KLB(
        int * valeur_de_KLB,
        int * tour_joueur_KLB,
        int * nombre_joueurs_KLB,
        Joueur_KLB joueurs_KLB[]
    );

    SDL_Texture * cree_texture_image_KLB(
        const char chemin_image_KLB[], 
        SDL_Renderer * renderer_KLB
    );

    int verifie_click_KLB(
        int event_x_KLB, 
        int event_y_KLB, 
        int start_x_KLB, 
        int start_y_KLB, 
        int width_KLB, 
        int height_KLB
    );

    void dessiner_rectangle_grosse_bordure_KLB(
        SDL_Renderer * renderer_KLB,
        SDL_Rect rect_KLB,
        int epaisseur_KLB
    );

    void gere_click_pion_KLB(
        SDL_Renderer * renderer_KLB,
        Joueur_KLB joueurs_KLB[],
        int event_x_KLB,
        int event_y_KLB,
        int valeur_de_KLB,
        int * tour_joueur_KLB,
        int * click_du_de_autorise,
        int nombre_joueur,
        int * affiche_message_erreur_KLB,
        Uint32 * start_time_message_KLB,
        int * affiche_message_victoire_KLB
    );

    Coordonnees_Case_KLB recherche_coordonnees_KLB(int postion_KLB);

    void verification_et_action_de_manger_pion_KLB(
        Joueur_KLB joueur_KLB[],
        int tour_joueur_KLB,
        int nb_joueur_KLB,
        int position_darrive_KLB,
        Couleur_KLB couleur_KLB
    );

    static Coordonnees_Case_KLB cases_KLB[100] = {
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

#endif