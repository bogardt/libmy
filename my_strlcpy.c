#include "libmy.h"

/**
 *  The strlcpy() and strlcat() functions copy and concatenate strings respectively.
    They are designed to be safer, more consistent, and less error prone replacements
    for strncpy(3) and strncat(3). Unlike those functions, strlcpy() and strlcat() take
    the full size of the buffer (not just the length) and guarantee to NUL-terminate the
    result (as long as size is larger than 0 or, in the case of strlcat(),
    as long as there is at least one byte free in dest).
    Note that a byte for the NUL should be included in size.
    Also note that strlcpy() and strlcat() only operate on true ''C'' strings.
    This means that for strlcpy() src must be NUL-terminated and for strlcat() both src and dest must be NUL-terminated.

    The strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dest,
    NUL-terminating the result.

    The strlcat() function appends the NUL-terminated string src to the end of dest.
    It will append at most size - strlen(dest) - 1 bytes, NUL-terminating the result.
 *
 * @param dest
 * @param src
 * @param size
 *
 * @return The strlcpy() and strlcat() functions return the total length of the string they tried to create.
 * For strlcpy() that is simply the length of the source;
 * for strlcat() it is the length of the destination (before concatenation) plus the length of the source. 
 *
*/
unsigned int my_strlcpy(char *dest, const char *src, unsigned int size)
{
   if (src == NULL)
      return 0;

   unsigned int len = my_strlen(src);

   my_strncpy(dest, src, size);

   return len;
}