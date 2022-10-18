#ifndef     __LIB_MY_H__
# define    __LIB_MY_H__

#include    <unistd.h>

int         my_is_alpha(char c);
int         my_is_digit(char c);
int         my_is_alpha_num(char c);
void        my_putstr(const char *str);
int         my_strlen(const char *str);
int         my_count_words(const char *str, char sep);
char**      my_split(const char *str, char sep);

#endif