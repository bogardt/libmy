#include "mytest.h"
#include <stdio.h>

START_TEST(test_my_memset_str_should_success) {
    char dest1[34] = "This is string.h library function";
    my_memset(dest1, 'c', 4);
    ck_assert_str_eq(dest1, "cccc is string.h library function");

    char dest2[34] = "This is string.h library function";
    memset(dest2, 'c', 4);
    ck_assert_str_eq(dest2, "cccc is string.h library function");
}
END_TEST

START_TEST(test_my_memset_int_should_success) {
    int dest1[5] = { 1, 2, 3, 4, 5};
    int dest2[5] = { 1, 2, 3, 4, 5};

    my_memset(dest1, 12, sizeof(int) * 5);
    memset(dest2, 12, sizeof(int) * 5);
}
END_TEST

Suite *my_memset_suite(void) {
    Suite *s = suite_create("my_memset");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_memset_str_should_success);
    tcase_add_test(tc_core, test_my_memset_int_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}