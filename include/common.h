#ifndef COMMON_H
# define COMMON_H

void show_msg(int type, const char *msg);
void error(const char *msg);
int split (char *str, char c, char ***arr);
void getMyConf(char *path_file);
char **splitMyConf(char *conf);
char **splitIt(char *string);

#endif /* !COMMON_H */