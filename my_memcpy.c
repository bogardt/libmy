#include "libmy.h"

/**
 * The memcpy() function copies n bytes from memory area src to
    memory area dest.  The memory areas must not overlap.  Use
    memmove(3) if the memory areas do overlap.
 *
 * @param void* dest
 * @param const void* src
 * @param unsigned int n
 *
 * @return The memcpy() function returns a pointer to dest.
 *
*/
void *my_memcpy(void *dest, const void *src, unsigned int n) {
  for (unsigned int i = 0; i < n; i++)
    ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];

  return dest;
}
