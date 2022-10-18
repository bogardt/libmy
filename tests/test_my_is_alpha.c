#include "mytest.h"

START_TEST(test_my_is_alpha_should_success)
{
    for (char c = 'a'; c <= 'z'; c++)
        ck_assert_int_eq(my_is_alpha_num(c), 1);
    for (char c = 'A'; c <= 'Z'; c++)
        ck_assert_int_eq(my_is_alpha_num(c), 1);
}
END_TEST

START_TEST(test_my_is_alpha_should_fail)
{
    ck_assert_int_eq(my_is_alpha('9'), 0);
    ck_assert_int_eq(my_is_alpha(' '), 0);
    ck_assert_int_eq(my_is_alpha('\t'), 0);
    ck_assert_int_eq(my_is_alpha('\n'), 0);
}
END_TEST

Suite *my_is_alpha_suite(void)
{
    Suite *s = suite_create("my_is_alpha");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_is_alpha_should_success);
    tcase_add_test(tc_core, test_my_is_alpha_should_fail);
    suite_add_tcase(s, tc_core);

    return s;
}