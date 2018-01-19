/* probleme_0016.c */


#include "Classe_Entier.h"

Classe_Entier Resoudre_Probleme_0016( void )
{
    Classe_Entier reponse = ENTIER_Creer_Nul();
    Classe_Entier deux_p_mille = ENTIER_Creer_Nul();
    Classe_Entier deux = ENTIER_Creer_De_Nombre( 2 );
    Classe_Entier mille = ENTIER_Creer_De_Nombre( 1000 );

    ENTIER_Puissance( deux_p_mille, deux, mille );
    ENTIER_Sommer_Chiffres( reponse, deux_p_mille );

	return reponse;
}
