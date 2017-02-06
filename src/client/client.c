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

  int i_categ;
  int i_nbplace;
  char **w_split_rep_serv;
  char* w_rep_serv;
  char c_zone;
  char msg[40]= "";
  char buffer[60];
  bool f_saisie = false;

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
    if( scanf("%d", &i_categ) == 1){
      if(i_categ > 0 && i_categ < 4)
        f_saisie = true;
      else
        system("clear");
    }
    else{
     system("clear");

     scanf("%*s"); // Ignore la valeur saisie
    }
    
  } while ( f_saisie == false );


  f_saisie = false;

  // Dans le cas des supporters locaux, deux zones possibles
  if(i_categ == 1)
  {
    do
    {
      printf("Deux zones possibles pour les supporters locaux, zone A ou zone B ? ");
      scanf(" %c", &c_zone);

      if(c_zone == 'a') c_zone = 'A';
      if(c_zone == 'b') c_zone = 'B';

      if(c_zone == 'A' || c_zone == 'B')
      {
        f_saisie = true;
      }
      else
      {
        system("clear");
      }

    } while (f_saisie == false);
  }

  if(i_categ == 2)
    c_zone = 'C';


  if(i_categ == 3)
    c_zone = 'D';


  f_saisie = false;

  do
  {
    printf("Combien de place souhaitez-vous dans la zone %c ? ", c_zone);
    scanf("%d", &i_nbplace);

    if(i_nbplace > 0)
    {
      f_saisie = true;
    }
    else
    {
      system("clear");

      scanf("%*s"); // Ignore la valeur saisie
    }

  } while (f_saisie == false);


  msg[0] = c_zone;  
  msg[1] = ' ';

  sprintf(buffer, "%d", i_nbplace);
  strcat(msg, buffer);

  printf("Message : %s\n", msg);

  // Envoie de la zone et du nombre de place souhaité
  w_rep_serv = send_msg(socket, msg);

  w_split_rep_serv = splitIt(w_rep_serv);

  if(w_split_rep_serv[1] == NULL)
    w_split_rep_serv[1] = "0";

  if(strcmp(w_split_rep_serv[1], "-1") != 0)
  {
      show_msg(1, "Commande validée !");
      show_msg(1, " Nombre de places restantes : ");
      show_msg(1, w_split_rep_serv[0]);

  }
  else
  {

      show_msg(0, "Commande refusé, plus de place disponible dans cette zone !\n");
  }


  printf("\n");

  // Fermeture de la socket
  close(socket);


  exit(0);
} // Fin init_client
