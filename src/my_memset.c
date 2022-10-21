/**
 * memset - fill memory with a constant byte
 * The memset() function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * @param s
 * @param c
 * @param n
 *
 * @return The memset() function returns a pointer to the memory area s.
 */

void *my_memset(void *s, int c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++)
        ((unsigned char *) s)[i] = c;

    return s;
}