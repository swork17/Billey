#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>   
#include <pthread.h> 
#include "../../include/server.h"
#include "../../include/common.h"

int    run_server(int port)
{
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
        printf("Creation socket impossible ..");
    puts("Socket OK");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("bind Error");
        return 1;
    }
    puts("bind OK");
    listen(socket_desc , 3);
    puts("En attente de connections .. ");
    c = sizeof(struct sockaddr_in);
    while((client_sock = accept(socket_desc,(struct sockaddr*) &client, (socklen_t*)&c)))
       {
            puts("Connection OK");
            printf("%s\n", inet_ntoa(client.sin_addr));
            pthread_t sniffer_thread;
            new_sock = malloc(1);
            *new_sock = client_sock;
            if (pthread_create(&sniffer_thread, NULL,  connection_handler, (void*) new_sock) < 0)
            {
                perror("Impossible de créer la thread");
                return 1;
            }
            puts("Handler assigné");
        }
    if (client_sock < 0)
    {
        perror("accept error");
        return 1;
    }
    return 0;
}

void    *connection_handler(void *socket_desc)
{
    int sock = *(int*)socket_desc;
    int n;
    char sendBuff[100], client_message[2000];
    t_info *clientInfo = malloc(sizeof(t_info));



    while ((n = recv(sock,client_message, 2000, 0)) > 0) {
        parseClientInfo(client_message, clientInfo);
        printf("Adresse du client: %s\n", clientInfo->ipAddr);
        printf("Numero du guichet: %d\n", clientInfo->numClient);
        clientInfo->numClient != 0 ? strcpy(sendBuff, "1") : strcpy(sendBuff, "0");
        send(sock, sendBuff, n, 0);
        
    }

    close(sock);
    if (n == 0)
        puts("Client Disconnected");
    else
        perror("recv error");
    return 0;
}

char **splitIt(char *string, t_info *clientInfo) {
    int i;
    int c = 0;
    char **arr = NULL;

    c = split(string, ' ', &arr);
    return (arr);
}

void parseClientInfo(char *message, t_info *clientInfo) {
    char **value = NULL;
    value = splitIt(message, clientInfo);
    strcpy(clientInfo->ipAddr, value[0]);
    clientInfo->numClient = atoi(value[1]);
}



