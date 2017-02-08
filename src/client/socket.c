// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include "../../include/common.h"
#include "../../include/client.h"

#define ip_server "127.0.0.1"
// #define ip_server "37.59.36.109"

// Lance la connexion au serveur
int connect_server(int i_guichet, int port){

  struct sockaddr_in server;
  char message[20] = "2 ";
  
  char w_guichet[5];
  sprintf(w_guichet, "%d", i_guichet);
  strcat(message, w_guichet);
   
  // Création de la socket
  int sock = socket(AF_INET , SOCK_STREAM , 0);
  if (sock == -1)
  {
      show_msg(0, "Impossible de créer la socket !");
  }

  server.sin_addr.s_addr = inet_addr(ip_server);
  server.sin_family = AF_INET;
  server.sin_port = htons( port );

  // Connexion au serveur
  if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
  {
      show_msg(0, "Impossible de se connecter au serveur !");
  }
        
  // Envoie des données au serveurs, adresse ip + numéro client
  send_msg(sock, message);

  return sock;
} // Fin connect_server


// Envoi un message au serveur et récupère sa réponse
char* send_msg(int sock, char* message){

  char *server_reply = malloc(sizeof(char*) + 1);

  // Envoie des données au serveurs, adresse ip + numéro client
  if( send(sock , message , strlen(message) , 0) < 0)
  {
      close(sock);
      show_msg(0, "Echec de l'envoi au serveur !");
  }
   
  // Réception de la réponse du serveur
  if( recv(sock , server_reply , 1024 , 0) < 0)
  {
      close(sock);
      show_msg(0, "Pas de réponse du serveur !");
  }

   return server_reply;

} // Fin send_msg
