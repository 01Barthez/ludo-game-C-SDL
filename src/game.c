#include "../include/game.h"
#include <math.h>

int tourne_de_TS(int *valeur_de_TS)
{
    *valeur_de_TS = (rand() % 6) + 1;
    return *valeur_de_TS;
}

int tour_suivant_TS(Joueur_TS joueurs[], int *tour_joueur_TS, int nombre_joueurs, int valeur_de_TS)
{
    int tour_j_TS = *tour_joueur_TS;
    // si la valeur du de est egale a 6
    // le meme joueur rejouera

    // si la valeur du de est differente de 6
    // si la tour joueur superieur ou egale a 4
    // le tour du joueur est mis a 0
    // sinon
    // le tour du joueur est est incrementer

    // verification des joueurs sorties

    if (valeur_de_TS == VALEUR_DE_SORTIE_TS)
    {
        return tour_j_TS;
    }

    if (valeur_de_TS != VALEUR_DE_SORTIE_TS)
        if (tour_j_TS >= (nombre_joueurs - 1))
            return 0;
        else
            return ++tour_j_TS;

    return 1;
}

// valeur de retour constante OUI ou NON
int possede_encore_un_pion_sur_le_terrain_TS(Joueur_TS joueurs_TS[], int nombre_joueurs_TS)
{
    int compte_pion_non_sortie = 0;

    for (int i_TS = 0; i_TS < nombre_joueurs_TS; i_TS++)
        for (int p_TS = 0; p_TS < 4; p_TS++)
            if (joueurs_TS[i_TS].pions_TS[p_TS].est_sortie == NON)
                compte_pion_non_sortie++;


    return compte_pion_non_sortie > 0 ? OUI : NON;
}

int verifie_victoire_TS(Joueur_TS joueurs_TS[], int nombre_joueurs_TS)
{
    int compte_pions_sortie_TS = 0;
    int compte_joueur_sortie_TS = 0;

    for (int i_TS = 0; i_TS < nombre_joueurs_TS; i_TS++)
    {
        compte_joueur_sortie_TS = 0;
        for (int p_TS = 0; p_TS < 4; p_TS++)
            if (joueurs_TS[i_TS].pions_TS[p_TS].est_sortie == OUI)
                compte_joueur_sortie_TS++;
        
        if(compte_pions_sortie_TS >= 4)
            compte_joueur_sortie_TS++;
    }


    return compte_joueur_sortie_TS >= 3 ? OUI : NON;

}