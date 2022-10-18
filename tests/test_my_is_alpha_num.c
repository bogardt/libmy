#include "mytest.h"

START_TEST(test_my_is_alpha_num_should_success)
{
    for (char c = 'a'; c <= 'z'; c++)
        ck_assert_int_eq(my_is_alpha_num(c), 1);
    for (char c = 'A'; c <= 'Z'; c++)
        ck_assert_int_eq(my_is_alpha_num(c), 1);
    for (char c = '0'; c <= '9'; c++)
        ck_assert_int_eq(my_is_alpha_num(c), 1);
}
END_TEST

START_TEST(test_my_is_alpha_num_should_fail)
{
    ck_assert_int_eq(my_is_alpha_num(' '), 0);
    ck_assert_int_eq(my_is_alpha_num('\t'), 0);
    ck_assert_int_eq(my_is_alpha_num('\n'), 0);
}
END_TEST

Suite *my_is_alpha_num_suite(void)
{
    Suite *s = suite_create("my_is_alpha_num");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_is_alpha_num_should_success);
    tcase_add_test(tc_core, test_my_is_alpha_num_should_fail);
    suite_add_tcase(s, tc_core);

    return s;
}