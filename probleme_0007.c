/* probleme_0007.c */

#include <stdint.h> /* uint32_t */
#include "Classe_Entier.h"

uint32_t Resoudre_Probleme_0007( void )
{
	uint32_t reponse = 0;
    Classe_Entier entier = NULL;

    entier = ENTIER_Chercher_Premier( 10001 );
    reponse = ENTIER_Convertir( entier );
    ENTIER_Detruire( &entier );

	return reponse;
}
