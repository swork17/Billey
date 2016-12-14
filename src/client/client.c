// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <errno.h> 
#include <netdb.h>
#include <ifaddrs.h>
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


  char * c_ip = get_ip();

  // Fermeture de la socket
  close(socket);

  while(1);


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

  // Erreur si le serveur retourne 0
   if(strcmp(server_reply, "0") == 0)
   {
      close(sock);
      show_error("Impossible serveur occupé !");
   }

  return sock;
} // Fin connect_server


// Récupère l'ip de la machine
char * get_ip()
{


FILE *f;
    char line[100] , *p , *c;
     
    f = fopen("/proc/net/route" , "r");
     
    while(fgets(line , 100 , f))
    {
        p = strtok(line , " \t");
        c = strtok(NULL , " \t");
         
        if(p!=NULL && c!=NULL)
        {
            if(strcmp(c , "00000000") == 0)
            {
                printf("Default interface is : %s \n" , p);
                break;
            }
        }
    }
     
    //which family do we require , AF_INET or AF_INET6
    int fm = AF_INET;
    struct ifaddrs *ifaddr, *ifa;
    int family , s;
    char host[NI_MAXHOST];
 
    if (getifaddrs(&ifaddr) == -1) 
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
 
    //Walk through linked list, maintaining head pointer so we can free list later
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
        {
            continue;
        }
 
        family = ifa->ifa_addr->sa_family;
 
        if(strcmp( ifa->ifa_name , p) == 0)
        {
            if (family == fm) 
            {
                s = getnameinfo( ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6) , host , NI_MAXHOST , NULL , 0 , NI_NUMERICHOST);
                 
                if (s != 0) 
                {
                    printf("getnameinfo() failed: %s\n", gai_strerror(s));
                    exit(EXIT_FAILURE);
                }
                 
                printf("address: %s", host);
            }
            printf("\n");
        }
    }
 
    freeifaddrs(ifaddr);
     
    return 0;






  /*
    char *c_ip;
    int fd;
    struct ifreq ifr;
     
    char iface[] = "eth0";
     
    fd = socket(AF_INET, SOCK_DGRAM, 0);
 
    //Type of address to retrieve - IPv4 IP address
    ifr.ifr_addr.sa_family = AF_INET;
 
    //Copy the interface name in the ifreq structure
    strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);
     
    //get the ip address
    ioctl(fd, SIOCGIFADDR, &ifr);
     
  
    //display ip
    printf("IP address of %s - %s\n" , iface , inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
     
    //get the netmask ip
    ioctl(fd, SIOCGIFNETMASK, &ifr);
     
    //display netmask
    printf("Netmask of %s - %s\n" , iface , inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
     
    close(fd);
     
    return 0;*/
}