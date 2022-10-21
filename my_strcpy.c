#include "libmy.h"

/**
 *  The strcpy() function copies the string pointed to by src,
    including the terminating null byte ('\0'), to the buffer pointed
    to by dest.  The strings may not overlap, and the destination
    string dest must be large enough to receive the copy.  Beware of
    buffer overruns!  (See BUGS.)

    The strncpy() function is similar, except that at most n bytes of
    src are copied.  Warning: If there is no null byte among the
    first n bytes of src, the string placed in dest will not be null-
    terminated.

    If the length of src is less than n, strncpy() writes additional
    null bytes to dest to ensure that a total of n bytes are written.
 *
 * @param dest
 * @param src
 * @param n
 *
*/

char *my_strcpy(char *dest, const char *src) {
  unsigned int i;

  for (i = 0; src[i]; i++)
    dest[i] = src[i];

  dest[i] = 0;

  return dest;
}
