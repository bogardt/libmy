#include "bsd/string.h"

#include "mytest.h"
#include "stdio.h"

#define FULL_PATH_MAX_LEN 15

START_TEST(test_my_strlcpy_should_copy) {
    char full_path[FULL_PATH_MAX_LEN], BSD_full_path[FULL_PATH_MAX_LEN];
    char *src = "hello world";

    unsigned int ret = my_strlcpy(full_path, src, FULL_PATH_MAX_LEN);
    unsigned int BSD_ret = strlcpy(BSD_full_path, src, FULL_PATH_MAX_LEN);

    ck_assert_int_eq(ret, BSD_ret);
    ck_assert_str_eq(full_path, BSD_full_path);

    ck_assert_int_eq(ret, 11);
    ck_assert_str_eq(full_path, src);
}
END_TEST

START_TEST(test_my_strlcpy_should_trunkat) {
    char full_path[FULL_PATH_MAX_LEN], BSD_full_path[FULL_PATH_MAX_LEN];
    char *src = "hello world long string";

    unsigned int ret = my_strlcpy(full_path, src, FULL_PATH_MAX_LEN);
    unsigned int BSD_ret = strlcpy(BSD_full_path, src, FULL_PATH_MAX_LEN);

    ck_assert_int_eq(ret, BSD_ret);
    ck_assert_str_eq(full_path, BSD_full_path);

    ck_assert_int_ne(ret, FULL_PATH_MAX_LEN);
    ck_assert_str_eq(full_path, "hello world lo");
}
END_TEST

Suite *my_strlcpy_suite(void) {
    Suite *s = suite_create("my_strlcpy");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strlcpy_should_copy);
    tcase_add_test(tc_core, test_my_strlcpy_should_trunkat);
    suite_add_tcase(s, tc_core);

    return s;
}
