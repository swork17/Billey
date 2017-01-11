#ifndef COMMON_H
# define COMMON_H

void show_msg(int type, const char *msg);
void error(const char *msg);
int split (char *str, char c, char ***arr);

#endif /* !COMMON_H */