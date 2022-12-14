#include "libmy.h"

/**
 * The strnlen() function returns the number of bytes in the string pointed to
 * by s, excluding the terminating null bye ('\0'), but at most maxlen. In doing
 * this, strnlen() looks only at the first maxlen bytes at s and never beyond
 * s+maxlen.
 *
 * @param str string
 * @param maxlen unsigned int
 *
 * @return The strnlen() function returns strlen(s), if that is less than
 * maxlen, or maxlen if there is no null byte ('\0') among the first maxlen
 * bytes pointed to by s.
 *
 * @since 1.0
 */
unsigned int my_strnlen(const char *str, unsigned int maxlen) {
    unsigned int i = 0;

    while (str[i] && i < maxlen)
        i++;
    return i;
}