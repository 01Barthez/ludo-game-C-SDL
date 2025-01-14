#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/ui.h"
#include "../include/game.h"

#define WINDOW_WIDTH_KLB 800
#define WINDOW_HEIGHT_KLB 650
#define DICE_WIDTH_KLB 80
#define DICE_HEIGHT_KLB 80
#define DICE_X_KLB (WINDOW_WIDTH_KLB / 2) - (DICE_WIDTH_KLB / 2)
#define DICE_Y_KLB (WINDOW_HEIGHT_KLB / 2) - (DICE_HEIGHT_KLB / 2)
#define BASE_WIDTH_KLB 300
#define BASE_HEIGHT_KLB 230
#define PION_WIDTH_KLB 40
#define PION_HEIGHT_KLB 40

void intialise_ludo_KLB(
    int *valeur_de_KLB,
    int *tour_joueur_KLB,
    int *nombre_joueurs_KLB,
    Joueur_KLB joueurs_KLB[]
)
{
    SDL_Window *window_KLB = SDL_CreateWindow("LUDO GAME - Barthez_Kenwou_22T2959",
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED,
                                             WINDOW_WIDTH_KLB,
                                             WINDOW_HEIGHT_KLB,
                                             SDL_WINDOW_SHOWN);

    if (!window_KLB)
    {
        printf("Erreur lors de la creation de la fenetre \n");
        SDL_Quit();
        return;
    }

    SDL_Renderer *renderer_KLB = SDL_CreateRenderer(window_KLB, -1, SDL_RENDERER_ACCELERATED);

    if (IMG_Init(IMG_INIT_JPG) == 0 )
    {
        SDL_DestroyRenderer(renderer_KLB);
        SDL_DestroyWindow(window_KLB);
        SDL_Quit();
        return;
    }

    SDL_Surface *surface_KLB = IMG_Load("./images/ludo.jpg");
    SDL_Texture *texture_KLB = SDL_CreateTextureFromSurface(renderer_KLB, surface_KLB);

    SDL_Rect plateau_ludo_KLB = {0, 0, WINDOW_WIDTH_KLB, WINDOW_HEIGHT_KLB};

    SDL_Rect de_KLB = {DICE_X_KLB, DICE_Y_KLB, DICE_WIDTH_KLB, DICE_HEIGHT_KLB};

    // texture du de
    SDL_Texture *texture_de_1_KLB = cree_texture_image_KLB("./images/dice1.jpeg", renderer_KLB);
    SDL_Texture *texture_de_2_KLB = cree_texture_image_KLB("./images/dice2.jpeg", renderer_KLB);
    SDL_Texture *texture_de_3_KLB = cree_texture_image_KLB("./images/dice3.jpeg", renderer_KLB);
    SDL_Texture *texture_de_4_KLB = cree_texture_image_KLB("./images/dice4.jpeg", renderer_KLB);
    SDL_Texture *texture_de_5_KLB = cree_texture_image_KLB("./images/dice5.jpeg", renderer_KLB);
    SDL_Texture *texture_de_6_KLB = cree_texture_image_KLB("./images/dice6.jpeg", renderer_KLB);

    SDL_Texture *textures_de_KLB[] = {
        texture_de_1_KLB,
        texture_de_2_KLB,
        texture_de_3_KLB,
        texture_de_4_KLB,
        texture_de_5_KLB,
        texture_de_6_KLB,
    };

    SDL_Texture *texture_pion_rouge_KLB = cree_texture_image_KLB("./images/pion_rouge.png", renderer_KLB);
    SDL_Texture *texture_pion_vert_KLB = cree_texture_image_KLB("./images/pion_vert.png", renderer_KLB);
    SDL_Texture *texture_pion_jaune_KLB = cree_texture_image_KLB("./images/pion_jaune.png", renderer_KLB);
    SDL_Texture *texture_pion_bleu_KLB = cree_texture_image_KLB("./images/pion_bleu.png", renderer_KLB);

    joueurs_KLB[0].position_depart_joueur_KLB = 1;
    joueurs_KLB[1].position_depart_joueur_KLB = 14;
    joueurs_KLB[2].position_depart_joueur_KLB = 27;
    joueurs_KLB[3].position_depart_joueur_KLB = 40;

    // initialisation des pions
    for (int i_KLB = 0; i_KLB < 4; i_KLB++)
    {
        joueurs_KLB[0].pions_KLB[i_KLB].case_sortie_KLB = 51;
        joueurs_KLB[0].pions_KLB[i_KLB].couleur_KLB = ROUGE;
        joueurs_KLB[0].pions_KLB[i_KLB].position_case_KLB = 0; // case 1
        joueurs_KLB[0].pions_KLB[i_KLB].case_de_fin_de_sortie_KLB = 105;
        joueurs_KLB[0].pions_KLB[i_KLB].est_sortie = NON; // case 1

        joueurs_KLB[1].pions_KLB[i_KLB].case_sortie_KLB = 12;
        joueurs_KLB[1].pions_KLB[i_KLB].case_de_fin_de_sortie_KLB = 205;
        joueurs_KLB[1].pions_KLB[i_KLB].couleur_KLB = VERT;
        joueurs_KLB[1].pions_KLB[i_KLB].position_case_KLB = 0; // case de depart 14
        joueurs_KLB[1].pions_KLB[i_KLB].est_sortie = NON;     // case 1

        joueurs_KLB[2].pions_KLB[i_KLB].case_sortie_KLB = 25;
        joueurs_KLB[2].pions_KLB[i_KLB].couleur_KLB = JAUNE;
        joueurs_KLB[2].pions_KLB[i_KLB].case_de_fin_de_sortie_KLB = 305;
        joueurs_KLB[2].pions_KLB[i_KLB].position_case_KLB = 0; // case de depart 27
        joueurs_KLB[2].pions_KLB[i_KLB].est_sortie = NON;     // case 1

        joueurs_KLB[3].pions_KLB[i_KLB].case_sortie_KLB = 38;
        joueurs_KLB[3].pions_KLB[i_KLB].couleur_KLB = BLEU;
        joueurs_KLB[3].pions_KLB[i_KLB].case_de_fin_de_sortie_KLB = 405;
        joueurs_KLB[3].pions_KLB[i_KLB].position_case_KLB = 0; // case de depart 40
        joueurs_KLB[3].pions_KLB[i_KLB].est_sortie = NON;     // case 1
    }
    // pions rouge sur x +54 environ sur y +43 environ
    joueurs_KLB[0].pions_KLB[0].rectangle_KLB = (SDL_Rect){85, 65, 40, 40}; // 85, 65
    joueurs_KLB[0].pions_KLB[0].start_position = (SDL_Point){85, 65};

    joueurs_KLB[0].pions_KLB[1].rectangle_KLB = (SDL_Rect){195, 65, 40, 40};
    joueurs_KLB[0].pions_KLB[1].start_position = (SDL_Point){195, 65};

    joueurs_KLB[0].pions_KLB[2].rectangle_KLB = (SDL_Rect){85, 160, 40, 40};
    joueurs_KLB[0].pions_KLB[2].start_position = (SDL_Point){85, 160};

    joueurs_KLB[0].pions_KLB[3].rectangle_KLB = (SDL_Rect){195, 160, 40, 40};
    joueurs_KLB[0].pions_KLB[3].start_position = (SDL_Point){195, 160};

    // pion vert
    joueurs_KLB[1].pions_KLB[0].rectangle_KLB = (SDL_Rect){565, 65, 40, 40};
    joueurs_KLB[1].pions_KLB[0].start_position = (SDL_Point){565, 65};

    joueurs_KLB[1].pions_KLB[1].rectangle_KLB = (SDL_Rect){675, 65, 40, 40};
    joueurs_KLB[1].pions_KLB[1].start_position = (SDL_Point){675, 65};

    joueurs_KLB[1].pions_KLB[2].rectangle_KLB = (SDL_Rect){565, 160, 40, 40};
    joueurs_KLB[1].pions_KLB[2].start_position = (SDL_Point){565, 160};

    joueurs_KLB[1].pions_KLB[3].rectangle_KLB = (SDL_Rect){675, 160, 40, 40};
    joueurs_KLB[1].pions_KLB[3].start_position = (SDL_Point){675, 160};

    // pion jaune
    joueurs_KLB[2].pions_KLB[0].rectangle_KLB = (SDL_Rect){565, 460, 40, 40};
    joueurs_KLB[2].pions_KLB[0].start_position = (SDL_Point){565, 460};

    joueurs_KLB[2].pions_KLB[1].rectangle_KLB = (SDL_Rect){675, 460, 40, 40};
    joueurs_KLB[2].pions_KLB[1].start_position = (SDL_Point){675, 460};

    joueurs_KLB[2].pions_KLB[2].rectangle_KLB = (SDL_Rect){565, 545, 40, 40};
    joueurs_KLB[2].pions_KLB[2].start_position = (SDL_Point){565, 545};

    joueurs_KLB[2].pions_KLB[3].rectangle_KLB = (SDL_Rect){675, 545, 40, 40};
    joueurs_KLB[2].pions_KLB[3].start_position = (SDL_Point){675, 545};

    // pion jaune
    joueurs_KLB[3].pions_KLB[0].rectangle_KLB = (SDL_Rect){85, 460, 40, 40};
    joueurs_KLB[3].pions_KLB[0].start_position = (SDL_Point){85, 460};

    joueurs_KLB[3].pions_KLB[1].rectangle_KLB = (SDL_Rect){195, 460, 40, 40};
    joueurs_KLB[3].pions_KLB[1].start_position = (SDL_Point){195, 460};

    joueurs_KLB[3].pions_KLB[2].rectangle_KLB = (SDL_Rect){85, 545, 40, 40};
    joueurs_KLB[3].pions_KLB[2].start_position = (SDL_Point){85, 545};

    joueurs_KLB[3].pions_KLB[3].rectangle_KLB = (SDL_Rect){195, 545, 40, 40};
    joueurs_KLB[3].pions_KLB[3].start_position = (SDL_Point){195, 545};

    // Gestion des evenements 

    int running_KLB = 1;
    SDL_Event event_KLB;
    SDL_Rect tour_rectangle_KLB = {10, 10, BASE_WIDTH_KLB, BASE_HEIGHT_KLB};
    int tour_j_KLB = *tour_joueur_KLB;
    int click_du_de_autorise = OUI;

    int position_case = 1;

    int affiche_message_erreur_KLB = NON;
    Uint32 start_time_message_KLB = 3000;
    int affiche_message_victoire_KLB = NON;

    int compte_de_lance_KLB = 1;

    while (running_KLB)
    {
        tour_j_KLB = *tour_joueur_KLB;

        /* debut de la gestion des evenemenKLB*/
        while (SDL_PollEvent(&event_KLB))
        {
            if (event_KLB.type == SDL_QUIT)
            {
                running_KLB = 0;
            }
            else if (event_KLB.type == SDL_MOUSEBUTTONDOWN || event_KLB.type == SDL_KEYUP)
            {
                // Gestion du clavier pour la sorti du pions grace au pions 4
                if (click_du_de_autorise == NON)
                {
                    // Si la valeur est egale a 4
                    if (*valeur_de_KLB == VALEUR_DE_SORTIE_KLB)
                    {
                        int index_pion_trouve_KLB = -1;
                        // et qu'il y'a un pion de ce joueur encore a la maison recuperer l'index du pion en question
                        for (int p_KLB = 0; p_KLB < 4; p_KLB++)
                        {
                            if (joueurs_KLB[tour_j_KLB].pions_KLB[p_KLB].position_case_KLB == 0)
                            {
                                index_pion_trouve_KLB = p_KLB;
                                break;
                            }
                        }

                        if (index_pion_trouve_KLB != -1)
                        {
                            if (event_KLB.key.keysym.sym == SDLK_4)
                            {
                                gere_click_pion_KLB(
                                    renderer_KLB,
                                    joueurs_KLB,
                                    joueurs_KLB[tour_j_KLB].pions_KLB[index_pion_trouve_KLB].rectangle_KLB.x,
                                    joueurs_KLB[tour_j_KLB].pions_KLB[index_pion_trouve_KLB].rectangle_KLB.y,
                                    *valeur_de_KLB,
                                    tour_joueur_KLB,
                                    &click_du_de_autorise,
                                    *nombre_joueurs_KLB,
                                    &affiche_message_erreur_KLB,
                                    &start_time_message_KLB,
                                    &affiche_message_victoire_KLB);
                                compte_de_lance_KLB = 1;
                                
                                
                            }
                            continue;
                        }
                    }
                    // attendre l'evenement du de la touche 4 pour deplace ce pion
                }
                
                if (event_KLB.type == SDL_MOUSEBUTTONDOWN)
                {
                    int x_KLB = event_KLB.button.x;
                    int y_KLB = event_KLB.button.y;

                    // printf("x_KLB = %d, y_KLB = %d, position_case_KLB = %d \n", x_KLB, y_KLB, position_case);
                    position_case++;
                    // verifie clic du de
                    if (click_du_de_autorise == OUI &&
                        verifie_click_KLB(x_KLB, y_KLB, DICE_X_KLB, DICE_Y_KLB, DICE_WIDTH_KLB, DICE_HEIGHT_KLB) == OUI)
                    {
                        tourne_de_KLB(valeur_de_KLB);
                        click_du_de_autorise = NON;

                        // verification si tous les pions du joueur sont a la maison autorise a tourner mais la valeur du de
                        // n'est pas 6
                        // valeur du de
                        if (*valeur_de_KLB != VALEUR_DE_SORTIE_KLB)
                        {
                            int pions_tous_a_la_maison = OUI;
                            for (int p_KLB = 0; p_KLB < 4; p_KLB++)
                            {
                                if (joueurs_KLB[tour_j_KLB].pions_KLB[p_KLB].position_case_KLB != 0)
                                {
                                    pions_tous_a_la_maison = NON;
                                }
                            }
                            if (pions_tous_a_la_maison == OUI)
                            {
                                click_du_de_autorise = OUI;
                                if(compte_de_lance_KLB == 3)
                                {
                                    compte_de_lance_KLB = 1;
                                    *tour_joueur_KLB = tour_suivant_KLB(joueurs_KLB, tour_joueur_KLB, *nombre_joueurs_KLB, *valeur_de_KLB);
                                }
                            }
                            compte_de_lance_KLB++;
                            continue;
                        }
                    }
                    // gestion des click sur les pions
                    gere_click_pion_KLB(
                        renderer_KLB,
                        joueurs_KLB,
                        x_KLB,
                        y_KLB,
                        *valeur_de_KLB,
                        tour_joueur_KLB,
                        &click_du_de_autorise,
                        *nombre_joueurs_KLB,
                        &affiche_message_erreur_KLB,
                        &start_time_message_KLB,
                        &affiche_message_victoire_KLB);
                }
            }
        }
        /* fin de la gestion des evenemenKLB */
        SDL_RenderClear(renderer_KLB);
        SDL_RenderCopy(renderer_KLB, texture_KLB, NULL, &plateau_ludo_KLB);

        // textures_de_KLB
        int val_de_KLB = *valeur_de_KLB;
        SDL_RenderCopy(renderer_KLB, textures_de_KLB[val_de_KLB - 1], NULL, &de_KLB);

        // Gestion de la position du cadre de tour
        if (tour_j_KLB == 0)
        {
            tour_rectangle_KLB.x = 10;
            tour_rectangle_KLB.y = 10;
        }
        else if (tour_j_KLB == 1)
        {
            tour_rectangle_KLB.x = (WINDOW_WIDTH_KLB - BASE_WIDTH_KLB) - 10;
            tour_rectangle_KLB.y = 10;
        }
        else if (tour_j_KLB == 2)
        {
            tour_rectangle_KLB.x = (WINDOW_WIDTH_KLB - BASE_WIDTH_KLB) - 10;
            tour_rectangle_KLB.y = (WINDOW_HEIGHT_KLB - BASE_HEIGHT_KLB) - 15;
        }
        else if (tour_j_KLB == 3)
        {
            tour_rectangle_KLB.x = 10;
            tour_rectangle_KLB.y = (WINDOW_HEIGHT_KLB - BASE_HEIGHT_KLB) - 15;
        }

        SDL_SetRenderDrawColor(renderer_KLB, 255, 255, 255, 255);
        dessiner_rectangle_grosse_bordure_KLB(renderer_KLB, tour_rectangle_KLB, 7);

        for (int i_KLB = 0; i_KLB < 4; i_KLB++)
        {
            SDL_RenderCopy(
                renderer_KLB,
                texture_pion_rouge_KLB,
                NULL,
                &joueurs_KLB[0].pions_KLB[i_KLB].rectangle_KLB);

            SDL_RenderCopy(
                renderer_KLB,
                texture_pion_vert_KLB,
                NULL,
                &joueurs_KLB[1].pions_KLB[i_KLB].rectangle_KLB);

            SDL_RenderCopy(
                renderer_KLB,
                texture_pion_jaune_KLB,
                NULL,
                &joueurs_KLB[2].pions_KLB[i_KLB].rectangle_KLB);

            SDL_RenderCopy(
                renderer_KLB,
                texture_pion_bleu_KLB,
                NULL,
                &joueurs_KLB[3].pions_KLB[i_KLB].rectangle_KLB);
        }

        SDL_RenderPresent(renderer_KLB);
    }

    SDL_DestroyTexture(texture_KLB);
    IMG_Quit();
    SDL_DestroyRenderer(renderer_KLB);
    SDL_DestroyWindow(window_KLB);
    SDL_Quit();
}

SDL_Texture *cree_texture_image_KLB(const char chemin_image_KLB[], SDL_Renderer *renderer_KLB)
{
    SDL_Texture *texture_KLB = IMG_LoadTexture(renderer_KLB, chemin_image_KLB);

    if (texture_KLB == NULL)
    {
        printf("erreur de chargement de la texture\n");
        return NULL;
    }

    return texture_KLB;
}

int verifie_click_KLB(
    int event_x_KLB,
    int event_y_KLB,
    int start_x_KLB,
    int start_y_KLB,
    int width_KLB,
    int height_KLB)
{
    if (event_x_KLB >= start_x_KLB && event_x_KLB <= (start_x_KLB + width_KLB) && event_y_KLB >= start_y_KLB && event_y_KLB <= (start_y_KLB + height_KLB))
        return 1;

    return 0;
}

void dessiner_rectangle_grosse_bordure_KLB(
    SDL_Renderer *renderer_KLB, SDL_Rect rect_KLB, int epaisseur_KLB)
{
    for (int i_KLB = 0; i_KLB < epaisseur_KLB; i_KLB++)
    {
        SDL_Rect bordure_KLB = {rect_KLB.x - i_KLB, rect_KLB.y - i_KLB, rect_KLB.w + 2 * i_KLB, rect_KLB.h + 2 * i_KLB};
        SDL_RenderDrawRect(renderer_KLB, &bordure_KLB);
    }
}

void gere_click_pion_KLB(
    SDL_Renderer *renderer_KLB,
    Joueur_KLB joueurs_KLB[],
    int event_x_KLB,
    int event_y_KLB,
    int valeur_de_KLB,
    int *tour_joueur_KLB,
    int *click_du_de_autorise,
    int nombre_joueurs_KLB,
    int *affiche_message_erreur_KLB,
    Uint32 *start_time_message_KLB,
    int *affiche_message_victoire_KLB)
{
    //
    if (*click_du_de_autorise == NON)
    {
        for (int j_KLB = 0; j_KLB < nombre_joueurs_KLB; j_KLB++)
        {
            for (int p_KLB = 0; p_KLB < 4; p_KLB++)
            {
                if (verifie_click_KLB(
                        event_x_KLB, event_y_KLB,
                        joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.x,
                        joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.y,
                        PION_WIDTH_KLB,
                        PION_HEIGHT_KLB) == OUI)
                {

                    // verification que le tour correspond a la couleur du pion clique
                    int tour_j_KLB = *tour_joueur_KLB;
                    if (joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.x == joueurs_KLB[tour_j_KLB].pions_KLB[p_KLB].rectangle_KLB.x && joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.y == joueurs_KLB[tour_j_KLB].pions_KLB[p_KLB].rectangle_KLB.y && joueurs_KLB[j_KLB].couleur_KLB == joueurs_KLB[tour_j_KLB].couleur_KLB)
                    {
                        // si le pion est dans la maison
                        if (joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB == 0)
                        {
                            // la valeur du de doit etre 6 maintenant 4
                            if (valeur_de_KLB != VALEUR_DE_SORTIE_KLB)
                                return;

                            joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = joueurs_KLB[j_KLB].position_depart_joueur_KLB;
                            Coordonnees_Case_KLB case_KLB = recherche_coordonnees_KLB(joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB);

                            joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.x = case_KLB.x_KLB;
                            joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.y = case_KLB.y_KLB;
                            *click_du_de_autorise = OUI;
                            *tour_joueur_KLB = tour_suivant_KLB(joueurs_KLB, tour_joueur_KLB, nombre_joueurs_KLB, valeur_de_KLB);
                            return;
                        }

                        // gestion de fin de sortie
                        if (joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB > 100)
                        {
                            if (valeur_de_KLB > (joueurs_KLB[j_KLB].pions_KLB[p_KLB].case_de_fin_de_sortie_KLB - joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB))
                                return;

                            if (joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB == joueurs_KLB[j_KLB].pions_KLB[p_KLB].case_de_fin_de_sortie_KLB)
                            {
                                joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 1000;
                            }
                        }
                        // si le pion n'est pas dans la maison
                        joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB += valeur_de_KLB;
                        if (
                            joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB > joueurs_KLB[j_KLB].pions_KLB[p_KLB].case_sortie_KLB && (joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB - valeur_de_KLB) <= joueurs_KLB[j_KLB].pions_KLB[p_KLB].case_sortie_KLB)
                        {
                            int deplacement_restant_KLB = (joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB - joueurs_KLB[j_KLB].pions_KLB[p_KLB].case_sortie_KLB) - 1;

                            // si le joueur est rouge
                            if (joueurs_KLB[j_KLB].couleur_KLB == ROUGE)
                            {
                                // stocker la valeur de pion superieur
                                joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 100;
                            }
                            else if (joueurs_KLB[j_KLB].couleur_KLB == VERT)
                            {
                                joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 200;
                            }
                            else if (joueurs_KLB[j_KLB].couleur_KLB == JAUNE)
                            {
                                joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 300;
                            }
                            else if (joueurs_KLB[j_KLB].couleur_KLB == BLEU)
                            {
                                joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 400;
                            }
                            joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB += deplacement_restant_KLB;
                            // printf("2-position: %d & case de debut sortie: %d & deplacement: %d \n", joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB, joueurs_KLB[j_KLB].pions_KLB[p_KLB].case_sortie_KLB, deplacement_restant_KLB);
                        }

                        // quand les position est superieur a 52 reinitialise a 1 et rajouter le reste pour l'avancement
                        if (joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB > 52 && joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB < 100)
                        {
                            int reste_KLB = joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB - 52;
                            joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 1 + reste_KLB;
                        }

                        Coordonnees_Case_KLB case_KLB = recherche_coordonnees_KLB(joueurs_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB);

                        joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.x = case_KLB.x_KLB;
                        joueurs_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.y = case_KLB.y_KLB;
                        *click_du_de_autorise = OUI;
                        *tour_joueur_KLB = tour_suivant_KLB(joueurs_KLB, tour_joueur_KLB, nombre_joueurs_KLB, valeur_de_KLB);

                        return;
                    }
                    break;
                }
            }
        }
    }
}

Coordonnees_Case_KLB recherche_coordonnees_KLB(int postion_KLB)
{
    Coordonnees_Case_KLB coor_KLB;

    for (int i_KLB = 0; i_KLB < 100; i_KLB++)
    {
        if (postion_KLB == cases_KLB[i_KLB].position_case_KLB)
        {
            coor_KLB.x_KLB = cases_KLB[i_KLB].x_KLB;
            coor_KLB.y_KLB = cases_KLB[i_KLB].y_KLB;
            break;
        }
    }

    return coor_KLB;
}

void verification_et_action_de_manger_pion_KLB(
    Joueur_KLB joueur_KLB[],
    int tour_joueur_KLB,
    int nb_joueur_KLB,
    int position_darrive_KLB,
    Couleur_KLB couleur_KLB)
{
    printf("entrer");
    // si la couleur du pion est similaire a celle du pion arrivant(aucune action requise)
    if (joueur_KLB[tour_joueur_KLB].couleur_KLB == couleur_KLB)
    {
        return;
    }

    printf("ok pas meme couleur");
    // sinon recherche dans la liste des pions, les pions qui se trouve a la position d'arriver
    for (int j_KLB = 0; j_KLB < nb_joueur_KLB; j_KLB++)
    {
        for (int p_KLB = 0; p_KLB < 4; p_KLB++)
        {
            if (joueur_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB == position_darrive_KLB)
            {
                printf("pion manger");
                joueur_KLB[j_KLB].pions_KLB[p_KLB].est_sortie = NON;
                joueur_KLB[j_KLB].pions_KLB[p_KLB].position_case_KLB = 0;
                joueur_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.x = joueur_KLB[j_KLB].pions_KLB[p_KLB].start_position.x;
                joueur_KLB[j_KLB].pions_KLB[p_KLB].rectangle_KLB.y = joueur_KLB[j_KLB].pions_KLB[p_KLB].start_position.y;
            }
        }
    }
}