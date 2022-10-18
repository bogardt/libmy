int     my_count_words(const char *str, char sep)
{
    int i = 0;
    int words = 0;
    int last_word = 0;

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