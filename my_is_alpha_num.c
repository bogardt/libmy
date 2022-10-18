#include "libmy.h"

int my_is_alpha_num(char c)
{
    return my_is_alpha(c) || my_is_digit(c);
}
