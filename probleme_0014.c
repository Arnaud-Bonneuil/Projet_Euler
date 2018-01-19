/* probleme_0014.c */

#include <stdint.h> /* uint32_t */

#define LIMITE_DEBUT 1000000


uint32_t Resoudre_Probleme_0014( void )
{
    uint32_t reponse = 0;
    uint32_t nombre = 0;
    uint32_t debut;
    uint32_t longeur_chaine;
    uint32_t longeur_chaine_max;

    for( nombre = 1 ; nombre<=LIMITE_DEBUT ; nombre++ )
    {
        debut = nombre;
        longeur_chaine = 1;
        while( debut!=1 )
        {
            longeur_chaine = longeur_chaine + 1;
            if( !(debut&0x00000001) )
            {
                debut = debut/2;
            }
            else
            {
                debut = 3*debut + 1;
            }
        }
        if( longeur_chaine>longeur_chaine_max )
        {
            longeur_chaine_max = longeur_chaine;
            reponse = nombre;
        }
    }
    return reponse;
}
