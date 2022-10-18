#include "libmy.h"

/**
 * Writes the string s and a trailing newline to stdout.
 *
 * @param str string
 *
 * @since 1.0
 */
void my_putstr(const char *str)
{
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
}