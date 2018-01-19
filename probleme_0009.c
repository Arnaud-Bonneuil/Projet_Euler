/* probleme_0009.c */

#include <stdint.h> /* uint32_t */

#define LIMITE 1000

uint32_t Resoudre_Probleme_0009( void )
{
	uint32_t reponse = 0;
    uint32_t a;
    uint32_t b;
    uint32_t c;

    for( a=1 ; a<=(LIMITE/3) ; a++ )
    {
        for( b=1; b<=(LIMITE-a) ; b++ )
        {
            c = LIMITE - ( a + b );
            if( (a*a+b*b)==(c*c) )
            {
                if( a < b )
                {
                    reponse = a*b*c;
                }
            }
        }
    }
	return reponse;
}
