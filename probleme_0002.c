/* probleme_0002.c */

#include <stdint.h> /* uint32_t */

#define PREMIER_TERME_FIBONACCI 1
#define SECOND_TERME_FIBONACCI 2
#define LIMITE 4000000

uint32_t Resoudre_Probleme_0002( void )
{
	uint32_t reponse = 0;
	uint32_t fibonacci_nb_1 = PREMIER_TERME_FIBONACCI;
	uint32_t fibonacci_nb_2 = SECOND_TERME_FIBONACCI;
	uint32_t fibonacci_nb_tmp = 0;

	while( fibonacci_nb_2 < LIMITE )
	{
        if( (fibonacci_nb_2%2)==0 )
		{
			reponse += fibonacci_nb_2;
		}
		fibonacci_nb_tmp = fibonacci_nb_2;
		fibonacci_nb_2 = fibonacci_nb_1 + fibonacci_nb_2;
		fibonacci_nb_1 = fibonacci_nb_tmp;

	}
	return reponse;
}
