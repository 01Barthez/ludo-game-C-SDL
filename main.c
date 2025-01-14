#include "include/ui.h"
#include "include/game.h"

int main() 
{
    int valeur_de_TS = 1;
    int tour_joueur_TS = 0;
    int nombre_joueurs_TS = 4;

    Joueur_TS joueurs_TS[nombre_joueurs_TS];
    intialise_ludo_TS(&valeur_de_TS, &tour_joueur_TS, &nombre_joueurs_TS, joueurs_TS);
    
    return 0;
}