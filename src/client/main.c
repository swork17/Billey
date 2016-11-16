// Includes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	int i_idclient = 0; 


	// Nombre d'argument
	if(argc != 2)
	{
		printf("Erreur dans le fichier client.c, problème au niveau du nombre d'arguments !\n");
		return -1;
	}


	i_idclient = atoi(argv[1]);

	if(i_idclient == 0 || i_idclient > 4)
	{
		printf("Erreur dans le fichier client.c, argument non valide !\n");
		return -1;
	}

	printf("Bienvenu au guichet n°%i\n", i_idclient);

	/*
	char c_zone[1] = {0};
	
	printf("Dans quelle zone souhaitez-vous être situé ? ");

  scanf("%s", c_zone);

  printf("Vous avez choisi la zone : %s\n", c_zone);


	*/

} // Fin main