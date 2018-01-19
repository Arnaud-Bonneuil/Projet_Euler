/* probleme_0015.c */


#include "Classe_Entier.h"


/* De façon générale si le chemin a une longueur n avec p pas à droite et (n-p)
   vers le bas, le nombre de possibilités est C(p,n) = C(n-p,n) */


#define DIMENSION_GRILLE 20


Classe_Entier Resoudre_Probleme_0015( void )
{
    Classe_Entier reponse = ENTIER_Creer_Nul();
    Classe_Entier long_chemin = ENTIER_Creer_De_Nombre( DIMENSION_GRILLE*2 );
    Classe_Entier nb_pas_a_drte = ENTIER_Creer_De_Nombre( DIMENSION_GRILLE );

    ENTIER_Combinaison( reponse, long_chemin, nb_pas_a_drte );

    return reponse;
}

