// Includes
#include <stdio.h>
#include <stdlib.h>
#include "../../include/common.h"
#include "../../include/client.h"

int main(int argc, char **argv){
	
	int i_idguichet = 0; 

	// Nombre d'argument
	if(argc != 2)
	{
		printf("Erreur dans le fichier client.c, problème au niveau du nombre d'arguments !\n");
		return -1;
	}

	// Récupération du numéro, ex : Client 1
	i_idguichet = atoi(argv[1]);

	if(i_idguichet == 0 || i_idguichet > 4)
	{
		printf("Erreur argument passé non valide (client.c) !\n");
		return -1;
	}
	
	init_client(i_idguichet);
} 

