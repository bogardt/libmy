#include "libmy.h"
#include <stdlib.h>

static int current_word_size(const char *str, int from, char sep)
{
    int start = 0;

    while (str[from] && str[from] != sep)
    {
        from++;
        start++;
    }

    return start;
}

/**
 * Split a function into multiple strings by separator
 *
 * @param str string to be splitted
 * @param sep char separator
 *
 * @return char** multidimentional strings, as a matrix (2, 2)
 *
 * @since 1.0
 */
char **my_split(const char *str, char sep)
{
    int i = 0;
    int j = 0;
    int count_total_words = my_count_words(str, sep);
    char **ret = (char **)malloc(sizeof(char *) * count_total_words);

    while (str[i])
    {
        if (str[i] != sep)
        {
            int word_size = current_word_size(str, i, sep);
            ret[j] = (char *)malloc(sizeof(char) * word_size + 1);

            int k = 0;
            while (str[i] && str[i] != sep)
                ret[j][k++] = str[i++];
            ret[j][k] = 0;
            j++;
        }
        else
            i++;
    }
    return ret;
}
