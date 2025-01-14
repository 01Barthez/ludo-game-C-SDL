#include "include/ui.h"
#include "include/game.h"

int main() 
{
    int valeur_de_KLB = 1;
    int tour_joueur_KLB = 0;
    int nombre_joueurs_KLB = 4;

    Joueur_KLB joueurs_KLB[nombre_joueurs_KLB];
    intialise_ludo_KLB(&valeur_de_KLB, &tour_joueur_KLB, &nombre_joueurs_KLB, joueurs_KLB);
    
    return 0;
}