/* probleme_0003.c */

#include <stdint.h> /* uint32_t */
#include "Classe_Entier.h"

uint32_t Resoudre_Probleme_0003( void )
{
    uint32_t reponse = 0;
    Classe_Entier nb = ENTIER_Creer_De_Chaine( "+600851475143" );
    Classe_Entier facteur_max = NULL;
    Classe_Liste liste_facteurs = NULL;

    liste_facteurs = ENTIER_Decomposer_Fact_Premiers( nb );

    facteur_max = LISTE_Lire_Dernier_Elmt( liste_facteurs );

    reponse = ENTIER_Convertir( facteur_max );

    ENTIER_Detruire( &nb );
    ENTIER_Detruire_Liste( &liste_facteurs );
	return reponse;
}
