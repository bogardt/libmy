#include "libmy.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * The strchr() function returns a pointer to the first occurrence
    of the character c in the string s.

    The strrchr() function returns a pointer to the last occurrence
    of the character c in the string s.

    The strchrnul() function is like strchr() except that if c is not
    found in s, then it returns a pointer to the null byte at the end
    of s, rather than NULL.

    Here "character" means "byte"; these functions do not work with
    wide or multibyte characters.
 *
 * @param str
 * @param c
 *
 * @return The strchr() and strrchr() functions return a pointer to the
    matched character or NULL if the character is not found.  The
    terminating null byte is considered part of the string, so that
    if c is specified as '\0', these functions return a pointer to
    the terminator.

    The strchrnul() function returns a pointer to the matched
    character, or a pointer to the null byte at the end of s (i.e.,
    s+strlen(s)) if the character is not found.
 *
*/

char *my_strchr(const char *s, int c) {
    if (!c)
        return "";

    while (*s) {
        if (*s == c)
            return (char *) s;
        s++;
    }

    return NULL;
}