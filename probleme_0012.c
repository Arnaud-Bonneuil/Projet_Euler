/* probleme_0012.c */

#include <stdint.h> /* uint32_t */
#include "Classe_Entier.h"

#define NOMBRE_DIVISEUR_MIN 500

uint32_t Resoudre_Probleme_0012( void )
{
    uint32_t reponse = 0;
    int trouve = 0;
    Classe_Entier UN = ENTIER_Creer_De_Chaine("+1");
    Classe_Entier indice = ENTIER_Creer_Nul();
    Classe_Entier nb_triangulaire = ENTIER_Creer_Nul();
    Classe_Entier nb_prm = NULL;
    Classe_Liste decomposition = NULL;
    Classe_Liste lst_fact_prem = NULL;
    uint32_t multiplicite = 0;
    uint32_t nb_diviseurs = 0;


    while( trouve==0 )
    {
        /* Calculer le nombre triangulaire suivant */
        ENTIER_Incrementer( indice, UN );
        ENTIER_Incrementer( nb_triangulaire, indice );

        /* Extraire la liste des facteurs premiers */
        decomposition = ENTIER_Decomposer_Fact_Premiers( nb_triangulaire );

        /* */
        lst_fact_prem = ENTIER_Extraire_Unique( decomposition );

        /* Calculer le nombre de diviseurs du nombre triangulaire */
        nb_prm = LISTE_Lire_Premier_Elmt( lst_fact_prem );
        while( nb_prm!=NULL )
        {
            /* Calculer la multiplicité des facteurs premiers */
            multiplicite = ENTIER_Compter_Occurrences( decomposition, nb_prm );
            nb_diviseurs *= (multiplicite + 1);
            nb_prm = LISTE_Lire_Elmt_Suivant( lst_fact_prem );
        }

        /* Verifier le nombre de diviseur */
        if( nb_diviseurs > NOMBRE_DIVISEUR_MIN )
        {
            trouve = 1;
        }
        else
        {
            /* Reinitialiser la liste des facteurs premiers */
            ENTIER_Detruire_Liste( &lst_fact_prem );
            nb_diviseurs = 1;
        }
    }

    reponse = ENTIER_Convertir( nb_triangulaire );

    ENTIER_Detruire( &UN );
    ENTIER_Detruire( &indice );
    ENTIER_Detruire( &nb_triangulaire);
    ENTIER_Detruire_Liste( &decomposition );
    ENTIER_Detruire_Liste( &lst_fact_prem );

    return reponse;
}
