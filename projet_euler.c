#include <stdio.h> /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

#include <stdint.h> /* uint32_t */
#include <inttypes.h> /* PRIu64 */
#include "Classe_Entier.h"

uint32_t Resoudre_Probleme_0001( void );
uint32_t Resoudre_Probleme_0002( void );
uint32_t Resoudre_Probleme_0003( void );
uint32_t Resoudre_Probleme_0004( void );
uint32_t Resoudre_Probleme_0005( void );
uint32_t Resoudre_Probleme_0006( void );
uint32_t Resoudre_Probleme_0007( void );
uint64_t Resoudre_Probleme_0008( void );
uint32_t Resoudre_Probleme_0009( void );
Classe_Entier Resoudre_Probleme_0010( void );
uint32_t Resoudre_Probleme_0011( void );
uint32_t Resoudre_Probleme_0012( void );
Classe_Entier Resoudre_Probleme_0013( void );
uint32_t Resoudre_Probleme_0014( void );
Classe_Entier Resoudre_Probleme_0015( void );
Classe_Entier Resoudre_Probleme_0016( void );
uint32_t Resoudre_Probleme_0017( void );
uint32_t Resoudre_Probleme_0018( void );

int main ( void )
{
	uint32_t reponse;
	uint64_t reponse_64;
	Classe_Entier reponse_entier = NULL;

	reponse = Resoudre_Probleme_0001();
	printf( "Probleme 0001 : %u\n", reponse );

	reponse = Resoudre_Probleme_0002();
	printf( "Probleme 0002 : %u\n", reponse );

	reponse = Resoudre_Probleme_0003();
	printf( "Probleme 0003 : %u\n", reponse );

	reponse = Resoudre_Probleme_0004();
	printf( "Probleme 0004 : %u\n", reponse );

	reponse = Resoudre_Probleme_0005();
	printf( "Probleme 0005 : %u\n", reponse );

	reponse = Resoudre_Probleme_0006();
	printf( "Probleme 0006 : %u\n", reponse );

	reponse = Resoudre_Probleme_0007();
	printf( "Probleme 0007 : %u\n", reponse );

	reponse_64 = Resoudre_Probleme_0008();
	printf( "Probleme 0008 : %"PRIu64"\n", reponse_64 );

	reponse = Resoudre_Probleme_0009();
	printf( "Probleme 0009 : %u\n", reponse );

	reponse_entier = Resoudre_Probleme_0010();
	printf( "Probleme 0010 : ");
	ENTIER_Afficher_Console( reponse_entier );
	ENTIER_Detruire( &reponse_entier );

	reponse = Resoudre_Probleme_0011();
	printf( "Probleme 0011 : %u\n", reponse );

    reponse = Resoudre_Probleme_0012();
	printf( "Probleme 0012 : %u\n", reponse );

	reponse_entier = Resoudre_Probleme_0013();
	printf( "Probleme 0013 : ");
	ENTIER_Afficher_Console( reponse_entier );
	ENTIER_Detruire( &reponse_entier );

    reponse = Resoudre_Probleme_0014();
	printf( "Probleme 0014 : %u\n", reponse );

    reponse_entier = Resoudre_Probleme_0015();
	printf( "Probleme 0015 : " );
    ENTIER_Afficher_Console( reponse_entier );
	ENTIER_Detruire( &reponse_entier );

	reponse_entier = Resoudre_Probleme_0016();
	printf( "Probleme 0016 : " );
    ENTIER_Afficher_Console( reponse_entier );
	ENTIER_Detruire( &reponse_entier );

	reponse = Resoudre_Probleme_0017();
	printf( "Probleme 0017 : %u\n", reponse );

	reponse = Resoudre_Probleme_0018();
	printf( "Probleme 0018 : %u\n", reponse );

	return EXIT_SUCCESS;
}
