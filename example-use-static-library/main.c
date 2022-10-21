#include "libmy.h"

int main() {
    my_putstr("My lib is working !\n");
    my_strlen("test");
    my_is_alpha('c');
    my_is_digit('7');
    my_split("toto fait la teuf", ' ');

    return 0;
}