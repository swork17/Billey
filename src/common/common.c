//Common Function

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/common.h"

#define BLUE "\x1B[34m"
#define GREEN "\x1B[42m"
#define RED "\x1B[41m"
#define RESET "\x1B[0m"

#define ZONES 4

void show_msg(int type, const char *msg)
{
    if(type == 0)
    	printf(RED "%s" RESET, msg);
    else
        printf(GREEN "%s" RESET, msg);
    
	printf("\n");
	exit(0);
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int split(char *str, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }
    return count;
}

/*char **splitMyConf(char *conf) {
    char delim[] = ";";
    char *token;
    char tabConf[4][8];
    int i = 0;
    int j;
    //char *conf_cpy = strcpy(conf_cpy, conf);

    for (token = strtok(conf, delim); token; token = strtok(NULL, delim))
    {
        //printf("%s\n", token);
        char _delim[] = ":";
        //printf("First token=%s\n", token);
        strcpy(tabConf[i], token);
        printf("tabConf %d -> %s\n", i, tabConf[i]);
        i++;
        //second_split(token, conf, _delim);
    }
    return tabConf;
}*/

char *append(const char *s, char c) {
    int len = strlen(s);
    char buf[len+2];
    strcpy(buf, s);
    buf[len] = c;
    buf[len + 1] = 0;
    return strdup(buf);
}

char **splitIt(char *string) {
    int i;
    int c = 0;
    char **arr = NULL;

    c = split(string, ' ', &arr);
    return (arr);
}

/*void getMyConf(char *path_file) {
    int c;
    FILE *file;
    file = fopen(path_file, "r");
    char *all_conf = malloc(sizeof(char*) + 1);
    char **tabConf;

    if (file) {
        while ((c = getc(file)) != EOF) {
            all_conf = append(all_conf, c);
        }
        //printf("My conf line : %s\n =============\n", all_conf);
        fclose(file);
        tabConf = splitMyConf(all_conf);
        printf("Places totales du terrain : \n");
        printf("\t\tZone A -> %s\n", tabConf[0]);
        printf("\t\tZone B -> %s\n", tabConf[1]);
        printf("\t\tZone C -> %s\n", tabConf[2]);
        printf("\t\tZone D -> %s\n", tabConf[3]);


    }
}*/