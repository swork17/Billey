// Includes
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include "../../include/common.h"
#include "../../include/client.h"


void init_client(int i_guichet){

  int i_choix = 0;
  char c_zone;
  char *msg;
  bool f_saisie_categ = false;
  bool f_saisie_zone  = false;


  system("clear");

  int socket = connect_server(i_guichet);

  printf("*** Bienvenu au guichet n°%i ***\n", i_guichet);

  do
  {
    printf("\nListe des catégories :\n");
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


  // Dans le cas des supporters locaux, deux zones possibles
  if(i_choix == 1)
  {
    do
    {
      printf("Deux zones possibles pour les supporters locaux, zone A ou zone B ? ");
      scanf(" %c", &c_zone);

      if(c_zone == 'a') c_zone = 'A';
      if(c_zone == 'b') c_zone = 'B';

      if(c_zone == 'A' || c_zone == 'B')
      {
        f_saisie_zone = true;
      }
      else
      {
        system("clear");
      }

    } while (f_saisie_zone == false);
  }

  if(i_choix == 2)
    c_zone = 'C';


  if(i_choix == 3)
    c_zone = 'D';

  printf("Combien de place souhaitez-vous dans la zone %c ?", c_zone);



/*
  // Envoie de la zone et du nombre de place souhaité
  send_msg(sock, msg);
*/
/*

  char w_categ[1];
  sprintf(w_categ, "%d", i_choix);

  int i_reponse= send_msg(socket, c_zone);
*/


  printf("\n");

  // Fermeture de la socket
  close(socket);

} // Fin init_client
