// Includes
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../include/server.h"

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

void start_server() {
	system("clear");
	printf ("   _____ __________ _    ____________ \n");
	printf ("  / ___// ____/ __ \\ |  / / ____/ __ \\\n");
	printf ("  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n");
	printf (" ___/ / /___/ _, _/| |/ / /___/ _, _/ \n");
	printf ("/____/_____/_/ |_| |___/_____/_/ |_| \n\n\n");
}

int	main(int argc, char **argv) {
	start_server();
	if (argc == 2) {
		run_server(atoi(argv[1]));
	}
	else
		printf(RED "Erreur d'arguments..\n" RESET);
}
