#include "libmy.h"

/**
 * Calculate the length of a string
    The my_strlen() function calculates the length of the string pointed to by str,
    excluding the terminating null byte ('\0').
 *
 * @param str string
 *
 * @return The strlen() function returns the number of bytes in the string
       pointed to by s.
 *
 * @since 1.0
 */
size_t my_strlen(const char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}