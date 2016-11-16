// Includes
#include <stdio.h>
#include <stdlib.h>
#include "../../include/client.h"


void init_client(char c_cdguichet){

	printf("Bienvenu au guichet %c\n", c_cdguichet);

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