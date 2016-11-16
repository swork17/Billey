// Includes
#include <stdio.h>
#include <stdlib.h>
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
	if (argc == 3) {
		if (init_server(argv[1], argv[2]) == -1)
			printf(RED "Erreur d'initialisation server\n" RESET);
	}
	else
		printf(RED "Erreur d'arguments..\n" RESET);
}
