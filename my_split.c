#include <stdlib.h>
#include "libmy.h"

static int      is_sep(char current, char sep)
{
    return current == sep;
}

static int      get_next_size(const char *str, int from, char sep)
{
    int to = 0;

    while (str[from] && !is_sep(str[from], sep))
    {
        from++;
        to++;
    }

    return to;
}

static int      count_words(const char *str, char sep)
{
    int i = 0;
    int words = 0;

    while (str[i++])
    {
        if (i == 0 && (my_is_alpha(str[i]) || my_is_digit(str[i])))
            words++;
        if (is_sep(str[i], sep) && str[i + 1] && (my_is_alpha(str[i]) || my_is_digit(str[i])))
            words++;
    }

    return words;
}

char**          my_split(const char *str, char sep)
{
    int i = 0;
    int j = 0;
    char **ret = malloc(sizeof(char *) * count_words(str, sep));

    while (i++ < my_strlen(str))
    {
        if (str[i] != sep)
        {
            int malloc_size_line = get_next_size(str, i, sep);
            ret[j] = malloc(sizeof(char) * malloc_size_line);
            int k = 0;
            while (str[i] && !is_sep(str[i], sep))
                ret[j][k++] = str[i++];
            ret[j++][k] = 0;
            j++;
        }
    }
    ret[i] = 0;

    return ret;
}
