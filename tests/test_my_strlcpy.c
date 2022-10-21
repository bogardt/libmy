#include "mytest.h"

START_TEST(test_my_strlcpy_should_success) {
    const char *src = "hello";
    char *dest = (char *) malloc(sizeof(char) * strlen(src) + 1);
    int ret = my_strlcpy(dest, src, 5);

    ck_assert_int_eq(ret, 5);
    // ck_assert_str_eq(dest, ret);
    // ck_assert_str_eq(dest, src);

    free(dest);
}
END_TEST

Suite *my_strlcpy_suite(void) {
    Suite *s = suite_create("my_strlcpy");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strlcpy_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}