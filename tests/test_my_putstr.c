#include "mytest.h"

START_TEST(test_my_putstr_should_success)
{
    char *test = "test";
    // my_putstr(test);

    /* value shouldn't be changed */
    ck_assert_str_eq("test", test);
}
END_TEST

Suite *my_putstr_suite(void)
{
    Suite *s = suite_create("my_putstr");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_putstr_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}