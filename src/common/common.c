//Common Function

#include <stdio.h>
#include <stdlib.h>
#include "../../include/common.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

