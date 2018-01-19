/* probleme_0001.c */

#include <stdint.h> /* uint32_t */

#define LIMITE 1000

uint32_t Resoudre_Probleme_0001( void )
{
	uint32_t reponse = 0;
	uint32_t nombre;

	for( nombre = 1 ; nombre < LIMITE ; nombre++ )
	{
		if( nombre%3==0 || nombre%5==0 )
		{
			reponse += nombre;
		}
	}
	return reponse;
}
