/* probleme_0010.c */

#include <stdint.h> /* uint32_t */
#include <stdlib.h> /* free */
#include "Classe_Entier.h"
#include "Classe_Liste.h"

#define LIMITE "+2000000"


Classe_Entier Resoudre_Probleme_0010( void )
{
    Classe_Liste liste_premiers = NULL;
    Classe_Liste limite = NULL;
    Classe_Liste reponse = NULL;

    limite = ENTIER_Creer_De_Chaine( LIMITE );
    liste_premiers = ENTIER_Charger_Nombres_Premiers( limite );
    reponse = ENTIER_Sommer_Liste( liste_premiers );

    ENTIER_Detruire( &limite );
    ENTIER_Detruire_Liste( &liste_premiers );

	return reponse;
}
