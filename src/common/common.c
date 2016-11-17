//Common Function

#include <stdio.h>
#include <stdlib.h>
#include "../../include/common.h"

#define BLUE "\x1B[34m"
#define GREEN "\x1B[42m"
#define RED "\x1B[41m"
#define RESET "\x1B[0m"

void show_error(const char *msg)
{
	printf(RED "%s" RESET, msg);
	printf("\n");
	exit(0);
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

