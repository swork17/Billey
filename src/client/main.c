// Includes
#include <stdio.h>
#include <stdlib.h>
#include "../../include/common.h"
#include "../../include/client.h"

int main(int argc, char **argv){
	
	int i_idguichet = 0; 

	system("clear");
	// Nombre d'argument
	if(argc != 3)
		show_msg(0, "Erreur dans le fichier client.c, problème au niveau du nombre d'arguments !");

	// Récupération du numéro, ex : Client 1
	i_idguichet = atoi(argv[2]);

	if(i_idguichet == 0 || i_idguichet > 4)
		show_msg(0, "Erreur argument passé non valide (client.c) !");


	while (42)
		init_client(i_idguichet, atoi(argv[1]));
} 

