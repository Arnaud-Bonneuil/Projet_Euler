/* probleme_0006.c */

#include <stdint.h> /* uint32_t */

#define LIMITE 100

uint32_t Resoudre_Probleme_0006( void )
{
	uint32_t reponse = 0;
    uint32_t somme_carres = 0;
    uint32_t somme = 0;
    uint32_t nombre = 0;

    for( nombre = 1 ; nombre<=LIMITE ; nombre++ )
    {
        somme_carres += (nombre*nombre);
        somme += nombre;
    }
    reponse = somme*somme - somme_carres;

	return reponse;
}
