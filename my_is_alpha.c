/**
 * Check if current char is alpha >= 'a' & <= 'z' or >= 'A' & <= 'Z'
 *
 * @param C char
 *
 * @return 1 if true 0 otherwise
 *
 * @since 1.0
 *
 */
int my_is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}