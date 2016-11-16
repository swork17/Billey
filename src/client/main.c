// Includes
#include <stdio.h>
#include <stdlib.h>
#include "../../include/client.h"

int main(int argc, char **argv){
	
	int i_idguichet = 0; 
	char c_guichet;

	// Nombre d'argument
	if(argc != 2)
	{
		printf("Erreur dans le fichier client.c, problème au niveau du nombre d'arguments !\n");
		return -1;
	}

	// Récupération du numéro, ex : Client 1
	i_idguichet = atoi(argv[1]);

	// Vérifie et converti le numéro du guichet par son code, ex : 1 = 'A'
	c_guichet = convert_type_guichet(i_idguichet);

	if(c_guichet == ' ')
	{
		printf("Erreur dans le fichier client.c, argument non valide !\n");
		return -1;
	}
	
	init_client(c_guichet);
} 

