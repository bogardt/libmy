#include "mytest.h"

START_TEST(test_my_strchr_should_success_level_1) {
    const char *str = "hello";
    char c = 'e';

    ck_assert_str_eq(my_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_my_strchr_should_success_level_2) {
    const char *str = "hello";
    char c = 0;

    ck_assert_str_eq(my_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *my_strchr_suite(void) {
    Suite *s = suite_create("my_strchr");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strchr_should_success_level_1);
    tcase_add_test(tc_core, test_my_strchr_should_success_level_2);
    suite_add_tcase(s, tc_core);

    return s;
}