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
	printf("*** Bienvenu au guichet n°%i ***\n", i_guichet);

	do
	{
		printf("\nListe des catégories\n");
		printf("1) Spectateur de l'équipe locale\n"); 
		printf("2) Spectateur de l'équipe visiteur\n"); 
		printf("3) Un Officiel\n"); 
		printf("Veuillez sélectionner la catégorie qui vous correspond : ");
		scanf("%i", &i_choix);
		// Gérer les characteres !!!
		if(i_choix > 0 && i_choix < 4)
			f_saisie_categ = true;
		else 
			system("clear");
	} while ( f_saisie_categ == false );

	printf("Choix : %i\n", i_choix);



    int sock;
    struct sockaddr_in server;
    char message[1000] = "10.0.2.15 1";
    char server_reply[2000];
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        show_error("Impossible de créer la socket !");
    }
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 4243 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        show_error("Erreur, connexion impossible au serveur !");
    }
          
    //keep communicating with server
    printf("Envoi du message : %s", message);
     
    //Send some data

    if( send(sock , message , strlen(message) , 0) < 0)
    {
        show_error("Echec de l'envoi au serveur !");
    }
     
    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        show_error("Pas de réponse du serveur !");
    }
     
    printf("\nRéponse du serveur :");
    
     
    close(sock);
/*
    char *buf[1000];

    int ph = popen("sudo ifconfig | grep 'inet addr' | cut -d':' -f2 | cut -d' ' -f1", "r");
    while (fgets(buf, sizeof buf, ph)) {
        // ip address, in nul-terminated string format, is in `buf` 

    }
    pclose(ph);

    printf("Ip : %s\n", buf);



    getifaddrs(&addrs);
    tmp = addrs;

    while (tmp) 
    {
        if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET)
        {
            struct sockaddr_in *pAddr = (struct sockaddr_in *)tmp->ifa_addr;
            printf("%s: %s\n", tmp->ifa_name, inet_ntoa(pAddr->sin_addr));
        }

        tmp = tmp->ifa_next;
    }

    freeifaddrs(addrs);

    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);
    }
     
    close(sock);
    return 0;

*/

/*
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  //--- Create the socket. The three arguments are: ----
  // 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) 
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  //---- Configure settings of the server address struct ----
  // Address family = Internet 
  serverAddr.sin_family = AF_INET;
  // Set port number, using htons function to use proper byte order 
  serverAddr.sin_port = htons(4242);
  // Set IP address to localhost 
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // Set all bits of the padding field to 0 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  //---- Connect the socket to the server using the address struct ----
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  //---- Read the message from the server into the buffer ----
  recv(clientSocket, buffer, 1024, 0);

  // ---- Print the received message ----
  printf("Data received: %s\n",buffer);   

*/

/*
	printf("1 - Saisie des clients manuellement \n", );
	printf("2 - Saisie des clients depuis un fichier \n", ); => si on a le temps


// 3 - Officiel / 1 - supporters locale / 2 - supporters visiteur ?

	// Choix de la zone
	printf("Bienvenu au guichet n°%i\n", i_guichet);
	printf("%s\n");
	printf("Veuillez saisir la zone où vous souhaitez être situé :");
*/

/*	Choix de la zone

	// Vérifie et converti le numéro du guichet par son code, ex : 1 = 'A'
	c_guichet = convert_type_guichet(i_idguichet);

	if(c_guichet == ' ')
	{

	}
	
	printf("Bienvenu au guichet %c\n", c_cdguichet);
*/


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