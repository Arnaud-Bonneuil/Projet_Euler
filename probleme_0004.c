/* probleme_0004.c */

#include <stdint.h> /* uint32_t */
#include <stdio.h> /* sprintf */
#include <string.h> /* strlen */

int Est_Palindrome( uint32_t nombre );

uint32_t Resoudre_Probleme_0004( void )
{
    uint32_t reponse = 0;
    uint32_t nb1 = 0;
    uint32_t nb2 = 0;
    uint32_t produit;
    int est_palindrome;

    for( nb1=100 ; nb1<=999; nb1++ )
    {
        for( nb2=nb1 ; nb2<=999; nb2++ )
        {
            produit = nb1*nb2;
            est_palindrome = Est_Palindrome( produit );
            if( est_palindrome )
            {
                if( produit > reponse )
                {
                    reponse = produit;
                }
            }
        }
    }
	return reponse;
}

int Est_Palindrome( uint32_t nombre )
{
    int est_palindrome = 1;
    char nombre_car[7] = {'\0'};
    size_t nb_chiff;
    int id_chiff;

    sprintf( nombre_car, "%u", nombre );
    nb_chiff = strlen( nombre_car ) -1; /* 0 compte */
    for( id_chiff=0 ; id_chiff<= (nb_chiff)/2 ; id_chiff++ )
    {
        if( nombre_car[id_chiff]!=nombre_car[nb_chiff-id_chiff] )
        {
            est_palindrome = 0;
        }
    }
    return est_palindrome;
}
