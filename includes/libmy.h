#ifndef     __LIB_MY_H__
# define    __LIB_MY_H__

#include    <unistd.h>

void        my_putstr(const char *str);

int         my_is_alpha(char c);
int         my_is_digit(char c);
int         my_is_alpha_num(char c);
int         my_strlen(const char *str);
int         my_strcmp(const char *s1, const char *s2);
int         my_strncmp(const char *s1, const char *s2, int n);
int         my_count_words(const char *str, char sep);
int         my_tolower(int c);
int         my_toupper(int c);

char*       my_strcat(char *dest, const char *src);
char*       my_strncat(char *dest, const char *src, int n);

char**      my_split(const char *str, char sep);

#endif      /* !__LIB_MY_H__ */