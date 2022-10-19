#include "libmy.h"

/**
 * Calculate the number of words in a string
 *
 * @param str string
 *
 * @return The my_count_words() function returns the number of words in a sentence
 *
 * @since 1.0
 */
size_t my_count_words(const char *str, char sep)
{
    size_t words = 0;
    size_t i = 0;
    char last_word = 0;

    while (str[i])
    {
        if (str[i] != sep && last_word == 0)
        {
            last_word = !last_word;
            words++;
        }
        else if (str[i] == sep)
            last_word = 0;
        i++;
    }
    return words;
}