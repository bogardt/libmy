#include "mytest.h"

START_TEST(test_my_tolower_should_success)
{
    for (int c = 'A'; c <= 'Z'; c++)
        ck_assert_int_eq(my_tolower(c), c + 32);
}
END_TEST

START_TEST(test_my_tolower_should_fail)
{
    ck_assert_int_eq(my_tolower(' '), ' ');
    ck_assert_int_eq(my_tolower('\n'), '\n');
    ck_assert_int_eq(my_tolower('\t'), '\t');
    ck_assert_int_eq(my_tolower('\r'), '\r');
}
END_TEST

Suite*  my_tolower_suite(void) 
{
    Suite *s = suite_create("my_tolower");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_tolower_should_success);
    tcase_add_test(tc_core, test_my_tolower_should_fail);
    suite_add_tcase(s, tc_core);

    return s;
}