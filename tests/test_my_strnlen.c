#include "mytest.h"

START_TEST(test_my_strnlen_should_success) {
    const char *str = "test";

    ck_assert_int_eq(my_strnlen(str, 3), strnlen(str, 3));
    ck_assert_int_eq(my_strnlen(str, 7), strnlen(str, 7));
}
END_TEST

Suite *my_strnlen_suite(void) {
    Suite *s = suite_create("my_strnlen");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strnlen_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}