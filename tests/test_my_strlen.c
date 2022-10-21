#include "mytest.h"

START_TEST(test_my_strlen_should_success) {
    const char *str = "test";

    ck_assert_int_eq(my_strlen(str), strlen(str));
}
END_TEST

Suite *my_strlen_suite(void) {
    Suite *s = suite_create("my_strlen");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strlen_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}