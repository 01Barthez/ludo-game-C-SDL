#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/ui.h"
#include "../include/game.h"
// #include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH_TS 800
#define WINDOW_HEIGHT_TS 650
#define DICE_WIDTH_TS 80
#define DICE_HEIGHT_TS 80
#define DICE_X_TS (WINDOW_WIDTH_TS / 2) - (DICE_WIDTH_TS / 2)
#define DICE_Y_TS (WINDOW_HEIGHT_TS / 2) - (DICE_HEIGHT_TS / 2)
#define BASE_WIDTH_TS 300
#define BASE_HEIGHT_TS 230
#define PION_WIDTH_TS 40
#define PION_HEIGHT_TS 40

void intialise_ludo_TS(
    int *valeur_de_TS,
    int *tour_joueur_TS,
    int *nombre_joueurs_TS,
    Joueur_TS joueurs_TS[])
{
    SDL_Window *window_TS = SDL_CreateWindow("Barthez Kenwou 22T2959 LUDO GAME",
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED,
                                             WINDOW_WIDTH_TS,
                                             WINDOW_HEIGHT_TS,
                                             SDL_WINDOW_SHOWN);

    // test de la creation de la fenetre
    if (!window_TS)
    {
        printf("Erreur lors de la creation de la fenetre \n");
        SDL_Quit();
        return;
    }

    SDL_Renderer *renderer_TS = SDL_CreateRenderer(window_TS, -1, SDL_RENDERER_ACCELERATED);

    if (IMG_Init(IMG_INIT_JPG) == 0 )
    {
        SDL_DestroyRenderer(renderer_TS);
        SDL_DestroyWindow(window_TS);
        SDL_Quit();
        return;
    }

    /*
    if (TTF_Init() == -1)
    {
        SDL_DestroyRenderer(renderer_TS);
        SDL_DestroyWindow(window_TS);
        SDL_Quit();
        return;
    }*/

    SDL_Surface *surface_TS = IMG_Load("./images/ludo.jpg");
    SDL_Texture *texture_TS = SDL_CreateTextureFromSurface(renderer_TS, surface_TS);

    SDL_Rect plateau_ludo_TS = {0, 0, WINDOW_WIDTH_TS, WINDOW_HEIGHT_TS};

    SDL_Rect de_TS = {DICE_X_TS, DICE_Y_TS, DICE_WIDTH_TS, DICE_HEIGHT_TS};

    // texture du de
    SDL_Texture *texture_de_1_TS = cree_texture_image_TS("./images/dice1.jpeg", renderer_TS);
    SDL_Texture *texture_de_2_TS = cree_texture_image_TS("./images/dice2.jpeg", renderer_TS);
    SDL_Texture *texture_de_3_TS = cree_texture_image_TS("./images/dice3.jpeg", renderer_TS);
    SDL_Texture *texture_de_4_TS = cree_texture_image_TS("./images/dice4.jpeg", renderer_TS);
    SDL_Texture *texture_de_5_TS = cree_texture_image_TS("./images/dice5.jpeg", renderer_TS);
    SDL_Texture *texture_de_6_TS = cree_texture_image_TS("./images/dice6.jpeg", renderer_TS);

    SDL_Texture *textures_de_TS[] = {
        texture_de_1_TS,
        texture_de_2_TS,
        texture_de_3_TS,
        texture_de_4_TS,
        texture_de_5_TS,
        texture_de_6_TS,
    };

    SDL_Texture *texture_pion_rouge_TS = cree_texture_image_TS("./images/pion_rouge.png", renderer_TS);
    SDL_Texture *texture_pion_vert_TS = cree_texture_image_TS("./images/pion_vert.png", renderer_TS);
    SDL_Texture *texture_pion_jaune_TS = cree_texture_image_TS("./images/pion_jaune.png", renderer_TS);
    SDL_Texture *texture_pion_bleu_TS = cree_texture_image_TS("./images/pion_bleu.png", renderer_TS);

    joueurs_TS[0].position_depart_joueur_TS = 1;
    joueurs_TS[1].position_depart_joueur_TS = 14;
    joueurs_TS[2].position_depart_joueur_TS = 27;
    joueurs_TS[3].position_depart_joueur_TS = 40;

    // initialisation des pions
    for (int i_TS = 0; i_TS < 4; i_TS++)
    {
        joueurs_TS[0].pions_TS[i_TS].case_sortie_TS = 51;
        joueurs_TS[0].pions_TS[i_TS].couleur_TS = ROUGE;
        joueurs_TS[0].pions_TS[i_TS].position_case_TS = 0; // case 1
        joueurs_TS[0].pions_TS[i_TS].case_de_fin_de_sortie_TS = 105;
        joueurs_TS[0].pions_TS[i_TS].est_sortie = NON; // case 1

        joueurs_TS[1].pions_TS[i_TS].case_sortie_TS = 12;
        joueurs_TS[1].pions_TS[i_TS].case_de_fin_de_sortie_TS = 205;
        joueurs_TS[1].pions_TS[i_TS].couleur_TS = VERT;
        joueurs_TS[1].pions_TS[i_TS].position_case_TS = 0; // case de depart 14
        joueurs_TS[1].pions_TS[i_TS].est_sortie = NON;     // case 1

        joueurs_TS[2].pions_TS[i_TS].case_sortie_TS = 25;
        joueurs_TS[2].pions_TS[i_TS].couleur_TS = JAUNE;
        joueurs_TS[2].pions_TS[i_TS].case_de_fin_de_sortie_TS = 305;
        joueurs_TS[2].pions_TS[i_TS].position_case_TS = 0; // case de depart 27
        joueurs_TS[2].pions_TS[i_TS].est_sortie = NON;     // case 1

        joueurs_TS[3].pions_TS[i_TS].case_sortie_TS = 38;
        joueurs_TS[3].pions_TS[i_TS].couleur_TS = BLEU;
        joueurs_TS[3].pions_TS[i_TS].case_de_fin_de_sortie_TS = 405;
        joueurs_TS[3].pions_TS[i_TS].position_case_TS = 0; // case de depart 40
        joueurs_TS[3].pions_TS[i_TS].est_sortie = NON;     // case 1
    }
    // pions rouge sur x +54 environ sur y +43 environ
    joueurs_TS[0].pions_TS[0].rectangle_TS = (SDL_Rect){85, 65, 40, 40}; // 85, 65
    joueurs_TS[0].pions_TS[0].start_position = (SDL_Point){85, 65};

    joueurs_TS[0].pions_TS[1].rectangle_TS = (SDL_Rect){195, 65, 40, 40};
    joueurs_TS[0].pions_TS[1].start_position = (SDL_Point){195, 65};

    joueurs_TS[0].pions_TS[2].rectangle_TS = (SDL_Rect){85, 160, 40, 40};
    joueurs_TS[0].pions_TS[2].start_position = (SDL_Point){85, 160};

    joueurs_TS[0].pions_TS[3].rectangle_TS = (SDL_Rect){195, 160, 40, 40};
    joueurs_TS[0].pions_TS[3].start_position = (SDL_Point){195, 160};

    // pion vert
    joueurs_TS[1].pions_TS[0].rectangle_TS = (SDL_Rect){565, 65, 40, 40};
    joueurs_TS[1].pions_TS[0].start_position = (SDL_Point){565, 65};

    joueurs_TS[1].pions_TS[1].rectangle_TS = (SDL_Rect){675, 65, 40, 40};
    joueurs_TS[1].pions_TS[1].start_position = (SDL_Point){675, 65};

    joueurs_TS[1].pions_TS[2].rectangle_TS = (SDL_Rect){565, 160, 40, 40};
    joueurs_TS[1].pions_TS[2].start_position = (SDL_Point){565, 160};

    joueurs_TS[1].pions_TS[3].rectangle_TS = (SDL_Rect){675, 160, 40, 40};
    joueurs_TS[1].pions_TS[3].start_position = (SDL_Point){675, 160};

    // pion jaune
    joueurs_TS[2].pions_TS[0].rectangle_TS = (SDL_Rect){565, 460, 40, 40};
    joueurs_TS[2].pions_TS[0].start_position = (SDL_Point){565, 460};

    joueurs_TS[2].pions_TS[1].rectangle_TS = (SDL_Rect){675, 460, 40, 40};
    joueurs_TS[2].pions_TS[1].start_position = (SDL_Point){675, 460};

    joueurs_TS[2].pions_TS[2].rectangle_TS = (SDL_Rect){565, 545, 40, 40};
    joueurs_TS[2].pions_TS[2].start_position = (SDL_Point){565, 545};

    joueurs_TS[2].pions_TS[3].rectangle_TS = (SDL_Rect){675, 545, 40, 40};
    joueurs_TS[2].pions_TS[3].start_position = (SDL_Point){675, 545};

    // pion jaune
    joueurs_TS[3].pions_TS[0].rectangle_TS = (SDL_Rect){85, 460, 40, 40};
    joueurs_TS[3].pions_TS[0].start_position = (SDL_Point){85, 460};

    joueurs_TS[3].pions_TS[1].rectangle_TS = (SDL_Rect){195, 460, 40, 40};
    joueurs_TS[3].pions_TS[1].start_position = (SDL_Point){195, 460};

    joueurs_TS[3].pions_TS[2].rectangle_TS = (SDL_Rect){85, 545, 40, 40};
    joueurs_TS[3].pions_TS[2].start_position = (SDL_Point){85, 545};

    joueurs_TS[3].pions_TS[3].rectangle_TS = (SDL_Rect){195, 545, 40, 40};
    joueurs_TS[3].pions_TS[3].start_position = (SDL_Point){195, 545};

    // e

    int running_TS = 1;
    SDL_Event event_TS;
    SDL_Rect tour_rectangle_TS = {10, 10, BASE_WIDTH_TS, BASE_HEIGHT_TS};
    int tour_j_TS = *tour_joueur_TS;
    int click_du_de_autorise = OUI;

    int position_case = 1;

    int affiche_message_erreur_TS = NON;
    Uint32 start_time_message_TS = 3000;
    int affiche_message_victoire_TS = NON;

    int compte_de_lance_TS = 1;

    while (running_TS)
    {
        tour_j_TS = *tour_joueur_TS;

        /* debut de la gestion des evenements*/
        while (SDL_PollEvent(&event_TS))
        {
            if (event_TS.type == SDL_QUIT)
            {
                running_TS = 0;
            }
            else if (event_TS.type == SDL_MOUSEBUTTONDOWN || event_TS.type == SDL_KEYUP)
            {
                // Gestion du clavier pour la sorti du pions grace au pions 4
                if (click_du_de_autorise == NON)
                {
                    // Si la valeur est egale a 4
                    if (*valeur_de_TS == VALEUR_DE_SORTIE_TS)
                    {
                        int index_pion_trouve_TS = -1;
                        // et qu'il y'a un pion de ce joueur encore a la maison recuperer l'index du pion en question
                        for (int p_TS = 0; p_TS < 4; p_TS++)
                        {
                            if (joueurs_TS[tour_j_TS].pions_TS[p_TS].position_case_TS == 0)
                            {
                                index_pion_trouve_TS = p_TS;
                                break;
                            }
                        }

                        if (index_pion_trouve_TS != -1)
                        {
                            if (event_TS.key.keysym.sym == SDLK_4)
                            {
                                gere_click_pion_TS(
                                    renderer_TS,
                                    joueurs_TS,
                                    joueurs_TS[tour_j_TS].pions_TS[index_pion_trouve_TS].rectangle_TS.x,
                                    joueurs_TS[tour_j_TS].pions_TS[index_pion_trouve_TS].rectangle_TS.y,
                                    *valeur_de_TS,
                                    tour_joueur_TS,
                                    &click_du_de_autorise,
                                    *nombre_joueurs_TS,
                                    &affiche_message_erreur_TS,
                                    &start_time_message_TS,
                                    &affiche_message_victoire_TS);
                                compte_de_lance_TS = 1;
                                
                                
                            }
                            continue;
                        }
                    }
                    // attendre l'evenement du de la touche 4 pour deplace ce pion
                }
                
                if (event_TS.type == SDL_MOUSEBUTTONDOWN)
                {
                    int x_TS = event_TS.button.x;
                    int y_TS = event_TS.button.y;

                    // printf("x_TS = %d, y_TS = %d, position_case_TS = %d \n", x_TS, y_TS, position_case);
                    position_case++;
                    // verifie clic du de
                    if (click_du_de_autorise == OUI &&
                        verifie_click_TS(x_TS, y_TS, DICE_X_TS, DICE_Y_TS, DICE_WIDTH_TS, DICE_HEIGHT_TS) == OUI)
                    {
                        tourne_de_TS(valeur_de_TS);
                        click_du_de_autorise = NON;

                        // verification si tous les pions du joueur sont a la maison autorise a tourner mais la valeur du de
                        // n'est pas 6
                        // valeur du de
                        if (*valeur_de_TS != VALEUR_DE_SORTIE_TS)
                        {
                            int pions_tous_a_la_maison = OUI;
                            for (int p_TS = 0; p_TS < 4; p_TS++)
                            {
                                if (joueurs_TS[tour_j_TS].pions_TS[p_TS].position_case_TS != 0)
                                {
                                    pions_tous_a_la_maison = NON;
                                }
                            }
                            if (pions_tous_a_la_maison == OUI)
                            {
                                click_du_de_autorise = OUI;
                                if(compte_de_lance_TS == 3)
                                {
                                    compte_de_lance_TS = 1;
                                    *tour_joueur_TS = tour_suivant_TS(joueurs_TS, tour_joueur_TS, *nombre_joueurs_TS, *valeur_de_TS);
                                }
                            }
                            compte_de_lance_TS++;
                            continue;
                        }
                    }
                    // gestion des click sur les pions
                    gere_click_pion_TS(
                        renderer_TS,
                        joueurs_TS,
                        x_TS,
                        y_TS,
                        *valeur_de_TS,
                        tour_joueur_TS,
                        &click_du_de_autorise,
                        *nombre_joueurs_TS,
                        &affiche_message_erreur_TS,
                        &start_time_message_TS,
                        &affiche_message_victoire_TS);
                }
            }
        }
        /* fin de la gestion des evenements */
        SDL_RenderClear(renderer_TS);
        SDL_RenderCopy(renderer_TS, texture_TS, NULL, &plateau_ludo_TS);

        // textures_de_TS
        int val_de_TS = *valeur_de_TS;
        SDL_RenderCopy(renderer_TS, textures_de_TS[val_de_TS - 1], NULL, &de_TS);

        // Gestion de la position du cadre de tour
        if (tour_j_TS == 0)
        {
            tour_rectangle_TS.x = 10;
            tour_rectangle_TS.y = 10;
        }
        else if (tour_j_TS == 1)
        {
            tour_rectangle_TS.x = (WINDOW_WIDTH_TS - BASE_WIDTH_TS) - 10;
            tour_rectangle_TS.y = 10;
        }
        else if (tour_j_TS == 2)
        {
            tour_rectangle_TS.x = (WINDOW_WIDTH_TS - BASE_WIDTH_TS) - 10;
            tour_rectangle_TS.y = (WINDOW_HEIGHT_TS - BASE_HEIGHT_TS) - 15;
        }
        else if (tour_j_TS == 3)
        {
            tour_rectangle_TS.x = 10;
            tour_rectangle_TS.y = (WINDOW_HEIGHT_TS - BASE_HEIGHT_TS) - 15;
        }

        SDL_SetRenderDrawColor(renderer_TS, 255, 255, 255, 255);
        dessiner_rectangle_grosse_bordure_TS(renderer_TS, tour_rectangle_TS, 7);

        for (int i_TS = 0; i_TS < 4; i_TS++)
        {
            SDL_RenderCopy(
                renderer_TS,
                texture_pion_rouge_TS,
                NULL,
                &joueurs_TS[0].pions_TS[i_TS].rectangle_TS);

            SDL_RenderCopy(
                renderer_TS,
                texture_pion_vert_TS,
                NULL,
                &joueurs_TS[1].pions_TS[i_TS].rectangle_TS);

            SDL_RenderCopy(
                renderer_TS,
                texture_pion_jaune_TS,
                NULL,
                &joueurs_TS[2].pions_TS[i_TS].rectangle_TS);

            SDL_RenderCopy(
                renderer_TS,
                texture_pion_bleu_TS,
                NULL,
                &joueurs_TS[3].pions_TS[i_TS].rectangle_TS);
        }

        SDL_RenderPresent(renderer_TS);
    }

    SDL_DestroyTexture(texture_TS);
    IMG_Quit();
    SDL_DestroyRenderer(renderer_TS);
    SDL_DestroyWindow(window_TS);
    SDL_Quit();
}

SDL_Texture *cree_texture_image_TS(const char chemin_image_TS[], SDL_Renderer *renderer_TS)
{
    SDL_Texture *texture_TS = IMG_LoadTexture(renderer_TS, chemin_image_TS);

    if (texture_TS == NULL)
    {
        printf("erreur de chargement de la texture\n");
        return NULL;
    }

    return texture_TS;
}

int verifie_click_TS(
    int event_x_TS,
    int event_y_TS,
    int start_x_TS,
    int start_y_TS,
    int width_TS,
    int height_TS)
{
    if (event_x_TS >= start_x_TS && event_x_TS <= (start_x_TS + width_TS) && event_y_TS >= start_y_TS && event_y_TS <= (start_y_TS + height_TS))
        return 1;

    return 0;
}

void dessiner_rectangle_grosse_bordure_TS(
    SDL_Renderer *renderer_TS, SDL_Rect rect_TS, int epaisseur_TS)
{
    for (int i_TS = 0; i_TS < epaisseur_TS; i_TS++)
    {
        SDL_Rect bordure_TS = {rect_TS.x - i_TS, rect_TS.y - i_TS, rect_TS.w + 2 * i_TS, rect_TS.h + 2 * i_TS};
        SDL_RenderDrawRect(renderer_TS, &bordure_TS);
    }
}

void gere_click_pion_TS(
    SDL_Renderer *renderer_TS,
    Joueur_TS joueurs_TS[],
    int event_x_TS,
    int event_y_TS,
    int valeur_de_TS,
    int *tour_joueur_TS,
    int *click_du_de_autorise,
    int nombre_joueurs_TS,
    int *affiche_message_erreur_TS,
    Uint32 *start_time_message_TS,
    int *affiche_message_victoire_TS)
{
    //
    if (*click_du_de_autorise == NON)
    {
        for (int j_TS = 0; j_TS < nombre_joueurs_TS; j_TS++)
        {
            for (int p_TS = 0; p_TS < 4; p_TS++)
            {
                if (verifie_click_TS(
                        event_x_TS, event_y_TS,
                        joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.x,
                        joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.y,
                        PION_WIDTH_TS,
                        PION_HEIGHT_TS) == OUI)
                {

                    // verification que le tour correspond a la couleur du pion clique
                    int tour_j_TS = *tour_joueur_TS;
                    if (joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.x == joueurs_TS[tour_j_TS].pions_TS[p_TS].rectangle_TS.x && joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.y == joueurs_TS[tour_j_TS].pions_TS[p_TS].rectangle_TS.y && joueurs_TS[j_TS].couleur_TS == joueurs_TS[tour_j_TS].couleur_TS)
                    {
                        // si le pion est dans la maison
                        if (joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS == 0)
                        {
                            // la valeur du de doit etre 6
                            if (valeur_de_TS != VALEUR_DE_SORTIE_TS)
                                return;

                            // si le pion n'est pas dans la maison
                            /*
                            verification_et_action_de_manger_pion_TS(
                                joueurs_TS,
                                tour_j_TS,
                                nombre_joueurs_TS,
                                joueurs_TS[j_TS].position_depart_joueur_TS,
                                joueurs_TS[j_TS].couleur_TS);
                            */
                            joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = joueurs_TS[j_TS].position_depart_joueur_TS;
                            Coordonnees_Case_TS case_TS = recherche_coordonnees_TS(joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS);

                            joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.x = case_TS.x_TS;
                            joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.y = case_TS.y_TS;
                            *click_du_de_autorise = OUI;
                            *tour_joueur_TS = tour_suivant_TS(joueurs_TS, tour_joueur_TS, nombre_joueurs_TS, valeur_de_TS);
                            return;
                        }

                        /*

                        verification_et_action_de_manger_pion_TS(
                            joueurs_TS,
                            tour_j_TS,
                            nombre_joueurs_TS,
                            joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS + valeur_de_TS,
                            joueurs_TS[j_TS].couleur_TS);
                        */

                        // gestion de fin de sortie
                        if (joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS > 100)
                        {
                            if (valeur_de_TS > (joueurs_TS[j_TS].pions_TS[p_TS].case_de_fin_de_sortie_TS - joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS))
                                return;

                            if (joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS == joueurs_TS[j_TS].pions_TS[p_TS].case_de_fin_de_sortie_TS)
                            {
                                joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = 1000;
                            }
                        }
                        // si le pion n'est pas dans la maison
                        joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS += valeur_de_TS;

                        // initialisation du debut de sortie
                        // si le joueur la position du joueur depasse sa case de debut de sortie
                        // et la position du joueur - la valeur du de est inferieur ou egale a case de sortie
                        if (
                            joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS > joueurs_TS[j_TS].pions_TS[p_TS].case_sortie_TS && (joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS - valeur_de_TS) <= joueurs_TS[j_TS].pions_TS[p_TS].case_sortie_TS)
                        {
                            int deplacement_restant_TS = (joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS - joueurs_TS[j_TS].pions_TS[p_TS].case_sortie_TS) - 1;

                            // si le joueur est rouge
                            if (joueurs_TS[j_TS].couleur_TS == ROUGE)
                            {
                                // stocker la valeur de pion superieur
                                joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = 100;
                            }
                            else if (joueurs_TS[j_TS].couleur_TS == VERT)
                            {
                                joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = 200;
                            }
                            else if (joueurs_TS[j_TS].couleur_TS == JAUNE)
                            {
                                joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = 300;
                            }
                            else if (joueurs_TS[j_TS].couleur_TS == BLEU)
                            {
                                joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = 400;
                            }
                            joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS += deplacement_restant_TS;
                            // printf("2-position: %d & case de debut sortie: %d & deplacement: %d \n", joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS, joueurs_TS[j_TS].pions_TS[p_TS].case_sortie_TS, deplacement_restant_TS);
                        }

                        // quand les position est superieur a 52 reinitialise a 1 et rajouter le reste pour l'avancement
                        if (joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS > 52 && joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS < 100)
                        {
                            int reste_TS = joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS - 52;
                            joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS = 1 + reste_TS;
                        }

                        Coordonnees_Case_TS case_TS = recherche_coordonnees_TS(joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS);

                        joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.x = case_TS.x_TS;
                        joueurs_TS[j_TS].pions_TS[p_TS].rectangle_TS.y = case_TS.y_TS;
                        *click_du_de_autorise = OUI;
                        *tour_joueur_TS = tour_suivant_TS(joueurs_TS, tour_joueur_TS, nombre_joueurs_TS, valeur_de_TS);

                        // printf("3-position: %d & case de debut sortie: %d \n", joueurs_TS[j_TS].pions_TS[p_TS].position_case_TS, joueurs_TS[j_TS].pions_TS[p_TS].case_sortie_TS);
                        return;
                    }

                    // si la valeur du de est egale a 6
                    // si le pion est dans la maison
                    // Si un pion de couleur differente est placer a la position d'atterissage du pion (fonction de verification de mangement)
                    // mettre le joueur manger dans sa maison
                    // reinitialiser la position du joueur manger
                    // sinon
                    // mouvement impossible
                    // afficher au coin de l'ecran pendant 2 secondes mouvement impossible (PIONS appartenant au meme joueur)
                    // sortir de la fonction
                    // Si Verification de la case de sortie du joueur  grace a sa position + la valeur du de
                    // si le joueur est l'exterieur des cases de sorties definitives
                    // Si le joueur est sur la case de sortie
                    // le pion peut sortir du jeu directement car la valeur du de est egale a 6
                    // mettre a jour sa position (hors du jeu)
                    // mettre a jour sa position visuellement
                    //
                    // Sinon
                    // calculer l'ecart entre le joueur
                    // Si la valeur obtenu est superieur a la case de debut de sortie du pion
                    //
                    // Si le joueur n'est pas proche de la case de sortie
                    // mettre le pion a la position de depart
                    // mettre a jour sa position visuellement

                    // si verification de la victoire == OUI
                    // afficher un message de success et un boutton permettant de reinitialiser le jeu
                    // sortie de la fonction de verification

                    // tour suivant (le meme joueur)
                    // autorisation du de a etre utilisable OUI
                    // sinon
                    // Si un pion de couleur differente est placer a la position d'atterissage du pion (fonction de verification de mangement)
                    // mettre le joueur manger dans sa maison
                    // reinitialiser la position du joueur manger
                    // sinon
                    // mouvement impossible
                    // afficher au coin de l'ecran pendant 2 secondes mouvement impossible (PIONS appartenant au meme joueur)
                    // sortir de la fonction
                    // mettre a jour la position du joueur par incrementation de 6
                    // mettre a jour sa position visuelle
                    // tour suivant (joueur suivant)
                    // si la valeur du de est differente de 6

                    break;
                }
            }
        }
    }
}

Coordonnees_Case_TS recherche_coordonnees_TS(int postion_TS)
{
    Coordonnees_Case_TS coor_TS;

    for (int i_TS = 0; i_TS < 100; i_TS++)
    {
        if (postion_TS == cases_TS[i_TS].position_case_TS)
        {
            coor_TS.x_TS = cases_TS[i_TS].x_TS;
            coor_TS.y_TS = cases_TS[i_TS].y_TS;
            break;
        }
    }

    return coor_TS;
}

void verification_et_action_de_manger_pion_TS(
    Joueur_TS joueur_TS[],
    int tour_joueur_TS,
    int nb_joueur_TS,
    int position_darrive_TS,
    Couleur_TS couleur_TS)
{
    printf("entrer");
    // si la couleur du pion est similaire a celle du pion arrivant(aucune action requise)
    if (joueur_TS[tour_joueur_TS].couleur_TS == couleur_TS)
    {
        return;
    }

    printf("ok pas meme couleur");
    // sinon recherche dans la liste des pions, les pions qui se trouve a la position d'arriver
    for (int j_TS = 0; j_TS < nb_joueur_TS; j_TS++)
    {
        for (int p_TS = 0; p_TS < 4; p_TS++)
        {
            if (joueur_TS[j_TS].pions_TS[p_TS].position_case_TS == position_darrive_TS)
            {
                printf("pion manger");
                joueur_TS[j_TS].pions_TS[p_TS].est_sortie = NON;
                joueur_TS[j_TS].pions_TS[p_TS].position_case_TS = 0;
                joueur_TS[j_TS].pions_TS[p_TS].rectangle_TS.x = joueur_TS[j_TS].pions_TS[p_TS].start_position.x;
                joueur_TS[j_TS].pions_TS[p_TS].rectangle_TS.y = joueur_TS[j_TS].pions_TS[p_TS].start_position.y;
            }
        }
    }
}