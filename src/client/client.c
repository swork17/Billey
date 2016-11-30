// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../include/common.h"
#include "../../include/client.h"

void init_client(int i_guichet){

	int i_choix = 0;

	char c_zone;

	bool f_saisie_categ = false;

	system("clear");

  int socket = connect_server(i_guichet);

	printf("*** Bienvenu au guichet n°%i ***\n", i_guichet);

	do
	{
		printf("\nListe des catégories\n");
		printf("1) Spectateur de l'équipe locale\n"); 
		printf("2) Spectateur de l'équipe visiteur\n"); 
		printf("3) Un Officiel\n"); 
		printf("Veuillez sélectionner la catégorie qui vous correspond : ");
		
    // Récupération de la saisie et vérification
    if( scanf("%d", &i_choix) == 1){
      if(i_choix > 0 && i_choix < 4)
        f_saisie_categ = true;
      else
        system("clear");
    }
    else{
     system("clear");

     scanf("%*s"); // Ignore la valeur saisie
    }
    
	} while ( f_saisie_categ == false );


	printf("Choix : %i\n", i_choix);






  
  while(1);

  // Fermeture de la socket
  close(socket);

} // Fin init_client

int connect_server(int i_guichet){

  struct sockaddr_in server;
  char message[20] = "10.0.2.15 ";
  char w_guichet[5];
  sprintf(w_guichet, "%d", i_guichet);
  strcat(message, w_guichet);

  char server_reply[2000];
   
  // Création de la socket
  int sock = socket(AF_INET , SOCK_STREAM , 0);
  if (sock == -1)
  {
      show_error("Impossible de créer la socket !");
  }
   
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons( 4242 );

  // Connexion au serveur
  if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
  {
      show_error("Impossible de se connecter au serveur !");
  }
        
  // Garde la connexion avec le serveur
  printf("Envoi du message : '%s'\n", message);
   
  // Envoie des données au serveurs, adresse ip + numéro client
  if( send(sock , message , strlen(message) , 0) < 0)
  {
      show_error("Echec de l'envoi au serveur !");
  }
   
  // Réception de la réponse du serveur
  if( recv(sock , server_reply , 2000 , 0) < 0)
  {
      show_error("Pas de réponse du serveur !");
  }
   
  // printf("\nRéponse du serveur :");

  return sock;
} // Fin connect_server


