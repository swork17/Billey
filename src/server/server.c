#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../../include/server.h"

#define MAX_CLIENT 4

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int init_server(char *adress, char *port) {
	int sockfd, newsockfd, _numport;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    _numport = atoi(port);
	printf("Adress : %s\nPort : %d\n\n", adress, _numport);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
         return -1;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(_numport);
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("LISTEN ERROR");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

   int pid;
   int client = 0;
    while (1) {
         newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
         client += 1; 
         if (newsockfd < 0)
                error("SOCK ERROR");
         pid = fork();
         if (pid < 0) 
              error("PID ERROR");
         if (pid == 0) {
            close(sockfd);
            bzero(buffer, 256);
            n = read(newsockfd, buffer, 255);
            if (n < 0)
                error("READ ERROR");
            printf("Client %d :(%d) %s\n", client, pid, buffer);
            n = write(newsockfd, "I got your message", 18);
            if (n < 0)
                 error("WRITE ERROR");
            close(newsockfd);
          }
          else
             close(newsockfd);
    }

    return 0;
}
