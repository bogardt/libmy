#include "libmy.h"

/**
 * Concatenate two strings
 *
 * @param dest string If dest is not large enough, program behavior is unpredictable; buffer overruns are a favorite avenue for attacking secure programs.
 * @param src string If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src plus the terminating null byte). Therefore, the size of dest must be at least strlen(dest)+n+1.
 * @param n unsigned integer which
 *
 * @return The my_strcat() and strncat() functions return a pointer to the
       resulting string dest.
 *
 * @note The my_strncat() is similar to the strcat() function, except that
        - it will use at most n bytes from src
        - src does not need to be null-terminated if it contains n or more bytes.
    If src contains n or more bytes, strncat() writes n+1 bytes to
    dest (n from src plus the terminating null byte).  Therefore, the
    size of dest must be at least strlen(dest)+n+1.
 *
 * @since 1.0
 */
char *my_strncat(char *dest, const char *src, size_t n)
{
    size_t len = my_strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;

    return dest;
}