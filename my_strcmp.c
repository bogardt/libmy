/**
 *
 *  The strcmp() function compares the two strings s1 and s2.  The
    locale is not taken into account (for a locale-aware comparison,
    see strcoll(3)).  The comparison is done using unsigned
    characters.

    strcmp() returns an integer indicating the result of the
    comparison, as follows:

    • 0, if the s1 and s2 are equal;

    • a negative value if s1 is less than s2;

    • a positive value if s1 is greater than s2.

    The strncmp() function is similar, except it compares only the
    first (at most) n bytes of s1 and s2.
 *
 * @param s1 string
 * @param s2 string
 *
 * @return The strcmp() and strncmp() functions return an integer less than,
    equal to, or greater than zero if s1 (or the first n bytes
    thereof) is found, respectively, to be less than, to match, or be
    greater than s2.
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++)
        ;
    return s1[i] - s2[i];
}
