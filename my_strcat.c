#include "libmy.h"

/**
 * Concatenate two strings
 *
 * @param dest string If dest is not large enough, program behavior is unpredictable; buffer overruns are a favorite avenue for attacking secure programs.
 * @param src string If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from src plus the terminating null byte). Therefore, the size of dest must be at least strlen(dest)+n+1.
 *
 * @return The my_strcat() and strncat() functions return a pointer to the
       resulting string dest.
 *
 * @note The my_strcat() function appends the src string to the dest string,
       overwriting the terminating null byte ('\0') at the end of dest,
       and then adds a terminating null byte.  The strings may not
       overlap, and the dest string must have enough space for the
       result.
 *
 * @since 1.0
 */
char *my_strcat(char *dest, const char *src)
{
    size_t len = my_strlen(dest);
    size_t i;

    for (i = 0; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;

    return dest;
}
