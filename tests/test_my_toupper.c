#include "mytest.h"

START_TEST(test_my_toupper_should_success) {
    for (int c = 'a'; c <= 'z'; c++)
        ck_assert_int_eq(my_toupper(c), c - 32);
}
END_TEST

START_TEST(test_my_toupper_should_fail) {
    ck_assert_int_eq(my_toupper(' '), ' ');
    ck_assert_int_eq(my_toupper('\n'), '\n');
    ck_assert_int_eq(my_toupper('\t'), '\t');
    ck_assert_int_eq(my_toupper('\r'), '\r');
}
END_TEST

Suite *my_toupper_suite(void) {
    Suite *s = suite_create("my_toupper");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_toupper_should_success);
    tcase_add_test(tc_core, test_my_toupper_should_fail);
    suite_add_tcase(s, tc_core);

    return s;
}