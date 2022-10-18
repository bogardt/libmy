#include "mytest.h"
#include <stdio.h>

START_TEST(test_my_split_should_success_easily)
{
    char *comp[3] = {"world", "easy", "test"};
    const char *str = "world easy test";
    char sep = ' ';

    char **tab = my_split(str, sep);

    for (size_t i = 0; i < 3; i++)
        ck_assert_str_eq(comp[i], tab[i]);
}
END_TEST

START_TEST(test_my_split_should_success_mediumly)
{
    char *comp[3] = {"world", "easy", "test"};
    const char *str = "                      world                   easy                  test                     ";
    char sep = ' ';

    char **tab = my_split(str, sep);

    for (size_t i = 0; i < 3; i++)
        ck_assert_str_eq(comp[i], tab[i]);
}
END_TEST

START_TEST(test_my_split_should_success_hardly)
{
    char *comp[6] = {"world", "easy", "test", "from", "another", "world"};
    const char *str = "  world easy test   from   another world  ";
    char sep = ' ';

    char **tab = my_split(str, sep);

    for (size_t i = 0; i < 6; i++)
        ck_assert_str_eq(comp[i], tab[i]);
}
END_TEST

Suite *my_split_suite(void)
{
    Suite *s = suite_create("my_split");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_split_should_success_easily);
    tcase_add_test(tc_core, test_my_split_should_success_mediumly);
    tcase_add_test(tc_core, test_my_split_should_success_hardly);
    suite_add_tcase(s, tc_core);

    return s;
}