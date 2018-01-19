/* probleme_0017.c */

#include <stdint.h> /* uint32_t */
#include <stdio.h> /* printf */

#define LIMITE 1000

const uint32_t LONGUEUR_1_A_19[20] = {
    0, /* non utilise */
    3, /* one */
    3, /* two */
    5, /* three */
    4, /* four */
    4, /* five */
    3, /* six */
    5, /* seven */
    5, /* eight */
    4, /* nine */
    3, /* ten */
    6, /* eleven */
    6, /* twelve */
    8, /* thirteen */
    8, /* fourteen */
    7, /* fifteen */
    7, /* sixteen */
    9, /* seventeen */
    8, /* eighteen */
    8  /* nineteen */
};

const uint32_t LONGUEUR_DIZAINES[10] = {
    0, /* non utilise */
    3, /* ten */
    6, /* twenty */
    6, /* thirty */
    5, /* forty */
    5, /* fifty */
    5, /* sixty */
    7, /* seventy */
    6, /* eighty */
    6  /* ninety */
};

#define LONGUEUR_AND 3 /* and */

#define LONGUEUR_100 7 /* hundred */

#define LONGUEUR_1000 11 /* onethousand */

uint32_t Resoudre_Probleme_0017( void )
{
	uint32_t reponse = 0;
	uint32_t nombre = 0;
	uint32_t longeur_nombre = 0;
	uint32_t chiffre_unite = 0;
	uint32_t chiffre_dizaines = 0;
	uint32_t centaine = 0;
	uint32_t reste = 0;
	uint32_t tmp = 0;

	for( nombre = 1 ; nombre <= LIMITE ; nombre++ )
	{
        if( nombre<=19 )
        {
            longeur_nombre = LONGUEUR_1_A_19[nombre];
        }
        else if( nombre<100 &&  ( (nombre%10)==0 ) )
        {
            longeur_nombre = LONGUEUR_DIZAINES[nombre/10];
        }
        else if( nombre<100 )
        {
            chiffre_unite = nombre%10;
            chiffre_dizaines = nombre/10;
            longeur_nombre = LONGUEUR_DIZAINES[chiffre_dizaines]
                           + LONGUEUR_1_A_19[chiffre_unite];
        }
        /* <1000 et centaine "pile" (100, 200,...) */
        else if( nombre<1000 && ( (nombre%100)==0 ) )
        {
            longeur_nombre = LONGUEUR_1_A_19[chiffre_unite] + LONGUEUR_100;
        }
        else if( nombre<1000 )
        {
            centaine = nombre/100;
            reste = nombre - centaine*100;
            if( reste<=19 )
            {
                tmp = LONGUEUR_1_A_19[reste];
            }
            else if( reste<100 && ((reste%10)==0) )
            {
                tmp = LONGUEUR_DIZAINES[reste/10];
            }
            else
            {
                chiffre_unite = reste%10;
                chiffre_dizaines = reste/10;
                tmp = LONGUEUR_DIZAINES[chiffre_dizaines]
                    + LONGUEUR_1_A_19[chiffre_unite];
            }
            longeur_nombre = tmp
                            + LONGUEUR_1_A_19[centaine]
                            + LONGUEUR_100
                            + LONGUEUR_AND;
        }
        else if( nombre==1000 )
        {
            longeur_nombre = LONGUEUR_1000;
        }
        else
        {
            printf( "ATTENTION : CAS IMPREVU\n" );
        }
        reponse = reponse + longeur_nombre;
	}
	return reponse;
}
