#include "libmy.h"

/**
 * Check if current char is alpha >= 'a' & <= 'z' or >= 'A' & <= 'Z' OR numeric
 * >= '0' & <= '9'
 *
 * @param C char
 *
 * @return 1 if true 0 otherwise
 *
 * @since 1.0
 *
 */
int my_is_alpha_num(char c) { return my_is_alpha(c) || my_is_digit(c); }
