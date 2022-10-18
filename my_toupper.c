/**
 * Convert letter to upper case if possible
 *
 * @param c integer
 *
 * @return The value returned is that of the converted letter,
    or c if the conversion was not possible.
 *
 * @since 1.0
 *
 */
int my_toupper(int c)
{
    return c >= 'a' && c <= 'z' ? c - 32 : c;
}