/**
 * Convert letter to lower case if possible
 *
 * @param c integer
 *
 * @return The value returned is that of the converted letter,
    or c if the conversion was not possible.
 *
 * @since 1.0
 *
 */
int my_tolower(int c) { return c >= 'A' && c <= 'Z' ? c + 32 : c; }