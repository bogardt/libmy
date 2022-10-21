#ifndef __LIB_MY_H__
#define __LIB_MY_H__

#include <unistd.h>

void my_putstr(const char *str);
void *my_memcpy(void *dest, const void *src, unsigned int n);
void *my_memset(void *s, int c, unsigned int n);

int my_is_alpha(char c);
int my_is_digit(char c);
int my_is_alpha_num(char c);
int my_tolower(int c);
int my_toupper(int c);

int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, unsigned int n);

unsigned int my_count_words(const char *str, char sep);
unsigned int my_strlen(const char *str);
unsigned int my_strnlen(const char *str, unsigned int maxlen);
unsigned int my_strlcat(char *dest, const char *src, unsigned int size);
unsigned int my_strlcpy(char *dest, const char *src, unsigned int size);

char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, unsigned int n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, unsigned int n);

char **my_split(const char *str, char sep);

#endif /* !__LIB_MY_H__ */