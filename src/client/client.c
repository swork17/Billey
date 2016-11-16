// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/common.h"
#include "../../include/client.h"


#define BLUE "\x1B[34m"
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

void init_client(int i_guichet){

	int i_choix = 0;

	char c_zone;

	bool f_saisie_categ = false;

	system("clear");
	printf("*** Bienvenu au guichet n°%i ***\n", i_guichet);

	while (f_saisie_categ == false)
	{

		printf("\nListe des catégories\n");
		printf("1) Spectateur de l'équipe locale\n"); 
		printf("2) Spectateur de l'équipe visiteur\n"); 
		printf("3) Un Officiel\n"); 
		printf("Veuillez sélectionner la catégorie qui vous correspond : ");
		scanf("%i", &i_choix);

		f_saisie_categ = true;

/*
		if(i_choix > 0 && i_choix < 4)
			f_saisie_categ = true;
		else 
			system("clear");*/
	} 


	printf("%i\n", i_choix);


/*
	printf("1 - Saisie des clients manuellement \n", );
	printf("2 - Saisie des clients depuis un fichier \n", ); => si on a le temps


// 3 - Officiel / 1 - supporters locale / 2 - supporters visiteur ?

	// Choix de la zone
	printf("Bienvenu au guichet n°%i\n", i_guichet);
	printf("%s\n");
	printf("Veuillez saisir la zone où vous souhaitez être situé :");
*/

/*	Choix de la zone

	// Vérifie et converti le numéro du guichet par son code, ex : 1 = 'A'
	c_guichet = convert_type_guichet(i_idguichet);

	if(c_guichet == ' ')
	{

	}
	
	printf("Bienvenu au guichet %c\n", c_cdguichet);
*/


	/*
	char c_zone[1] = {0};
	
	printf("Dans quelle zone souhaitez-vous être situé ? ");

  scanf("%s", c_zone);

  printf("Vous avez choisi la zone : %s\n", c_zone);

	*/
}

/*
	 Vérifie et converti le numéro du guichet par son code (ex: 1 => A)
	 ' ' si pas de guichet
*/
char convert_type_guichet(int i_num){

	char c_guichet = ' ';
	char *c_lst_guichet  = "ABCD";
	int i_lst_guichet[4] = {1,2,3,4};

	for (int i = 0; i < 4; ++i)
	{
		if(i_lst_guichet[i] == i_num)
			c_guichet = c_lst_guichet[i];
	}

	return c_guichet;
}