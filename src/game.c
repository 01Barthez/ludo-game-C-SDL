#include "../include/game.h"
#include <math.h>

int tourne_de_KLB(int *valeur_de_KLB)
{
    *valeur_de_KLB = (rand() % 6) + 1;
    return *valeur_de_KLB;
}

int tour_suivant_KLB(Joueur_KLB joueurs[], int *tour_joueur_KLB, int nombre_joueurs, int valeur_de_KLB)
{
    int tour_j_KLB = *tour_joueur_KLB;

    if (valeur_de_KLB == VALEUR_DE_SORTIE_KLB)
    {
        return tour_j_KLB;
    }

    if (valeur_de_KLB != VALEUR_DE_SORTIE_KLB)
        if (tour_j_KLB >= (nombre_joueurs - 1))
            return 0;
        else
            return ++tour_j_KLB;

    return 1;
}

// valeur de retour constante OUI ou NON
int possede_encore_un_pion_sur_le_terrain_KLB(Joueur_KLB joueurs_KLB[], int nombre_joueurs_KLB)
{
    int compte_pion_non_sortie = 0;

    for (int i_KLB = 0; i_KLB < nombre_joueurs_KLB; i_KLB++)
        for (int p_KLB = 0; p_KLB < 4; p_KLB++)
            if (joueurs_KLB[i_KLB].pions_KLB[p_KLB].est_sortie == NON)
                compte_pion_non_sortie++;


    return compte_pion_non_sortie > 0 ? OUI : NON;
}

int verifie_victoire_KLB(Joueur_KLB joueurs_KLB[], int nombre_joueurs_KLB)
{
    int compte_pions_sortie_KLB = 0;
    int compte_joueur_sortie_KLB = 0;

    for (int i_KLB = 0; i_KLB < nombre_joueurs_KLB; i_KLB++)
    {
        compte_joueur_sortie_KLB = 0;
        for (int p_KLB = 0; p_KLB < 4; p_KLB++)
            if (joueurs_KLB[i_KLB].pions_KLB[p_KLB].est_sortie == OUI)
                compte_joueur_sortie_KLB++;
        
        if(compte_pions_sortie_KLB >= 4)
            compte_joueur_sortie_KLB++;
    }


    return compte_joueur_sortie_KLB >= 3 ? OUI : NON;

}