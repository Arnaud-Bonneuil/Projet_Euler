/* probleme_0005.c */

#include <stdint.h> /* uint32_t */
#include <stdlib.h> /* free */
#include "Classe_Entier.h"
#include "Classe_Liste.h"

#define NB_DIVISEURS 20

/* On cherche a decomposer chaque diviseur (de 1 à 20) du nombre recherche en
produits de nombres premiers :
    1 = 1
    2 = 2
    3 = 3
    4 = 2*2
    5 = 5
    6 = 2*3
    7 = 7
    8 = 2*2*2
    ...
    20 = 2*2*5
Pour l'ensemble de ces multiples on cherche la multiplice la plus grande de
chaque entier premier.
Le nombre recherche est egal au produit des entiers premiers "ponderes" de leur
multiplicite. */


uint32_t Resoudre_Probleme_0005( void )
{
    uint32_t reponse = 0;
    Classe_Entier diviseur_max = NULL;
    Classe_Liste lst_prem = NULL;
    Classe_Liste decomposition = NULL;
    Classe_Entier nb_prm = NULL;
    int32_t diviseur = 0;
    Classe_Entier tmp = NULL;
    Classe_Liste table_multiplicite = NULL;
    uint32_t* multiplicite = NULL;
    uint32_t occurrence = 0;
    Classe_Entier resultat = ENTIER_Creer_Nul();
    Classe_Entier resultat_prec = ENTIER_Creer_De_Chaine( "+1" );

    diviseur_max = ENTIER_Creer_De_Nombre( NB_DIVISEURS );

    /* Chercher tous les entiers premiers <= NB_DIVISEURS */
    lst_prem = ENTIER_Charger_Nombres_Premiers( diviseur_max );

    /* Initialiser la table des multiplicite */
    table_multiplicite = LISTE_Creer();
    nb_prm = LISTE_Lire_Premier_Elmt( lst_prem );
    while( nb_prm!=NULL )
    {
        multiplicite = (uint32_t*)malloc( sizeof( uint32_t ) );
        *multiplicite = 0;
        LISTE_Ajouter_Elmt_Fin( table_multiplicite, multiplicite );
        nb_prm = LISTE_Lire_Elmt_Suivant( lst_prem );
    }

    /* Compter la multiplicite de chaque facteur premier */
    for( diviseur = 2 ; diviseur<= NB_DIVISEURS; diviseur++ )
    {
        tmp = ENTIER_Creer_De_Nombre( diviseur );
        decomposition = ENTIER_Decomposer_Fact_Premiers( tmp );

        nb_prm = LISTE_Lire_Premier_Elmt( lst_prem );
        multiplicite = LISTE_Lire_Premier_Elmt( table_multiplicite );
        while( nb_prm!=NULL ) /* les deux liste ont la meme taille */
        {
            occurrence = ENTIER_Compter_Occurrences( decomposition, nb_prm );
            if( occurrence > *multiplicite )
            {
                *multiplicite = occurrence;
            }
            nb_prm = LISTE_Lire_Elmt_Suivant( lst_prem );
            multiplicite = LISTE_Lire_Elmt_Suivant( table_multiplicite );
        }
        ENTIER_Detruire_Liste( &decomposition );
    }

    /* Calculer le resultat */
    nb_prm = LISTE_Lire_Premier_Elmt( lst_prem );
    multiplicite = LISTE_Lire_Premier_Elmt( table_multiplicite );
    while( nb_prm!=NULL ) /* les deux liste ont la meme taille */
    {
        for( occurrence = 1; occurrence<=(*multiplicite); occurrence++ )
        {
            ENTIER_Multiplier( resultat, resultat_prec, nb_prm );
            ENTIER_Copier( resultat, resultat_prec );
        }
        nb_prm = LISTE_Lire_Elmt_Suivant( lst_prem );
        multiplicite = LISTE_Lire_Elmt_Suivant( table_multiplicite );
    }

    reponse = ENTIER_Convertir( resultat );

    /* Liberer de la memoire */
    ENTIER_Detruire( &diviseur_max );
    ENTIER_Detruire( &tmp );
    ENTIER_Detruire( &resultat );
    ENTIER_Detruire( &resultat_prec );
    ENTIER_Detruire_Liste( &lst_prem );
    multiplicite = LISTE_Lire_Premier_Elmt( table_multiplicite );
    while( multiplicite!=NULL )
    {
        free( multiplicite );
        multiplicite = LISTE_Lire_Elmt_Suivant( table_multiplicite );
    }
    LISTE_Detruire( &table_multiplicite );

	return reponse;
}
