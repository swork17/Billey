#include <stdlib.h>
#include <stdio.h>
#include "../../include/server.h"

int init_server(char *adress, char *port) {

	int _port = atoi(port);
	printf("Adress : %s\nPort : %d\n\n", adress, _port);

	return 0;
}
