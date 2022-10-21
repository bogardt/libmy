#include "mytest.h"

START_TEST(test_my_strncpy_should_success_level_1) {
    const char *src = "hello";
    // const unsigned int len = strlen(src);

    char dest1[10];   //  = (char *) malloc(sizeof(char) * len + 1);
    char *ret1 = my_strncpy(dest1, src, 9);

    char dest2[10];   // = (char *) malloc(sizeof(char) * len + 1);
    char *ret2 = strncpy(dest2, src, 9);

    /* (void) ret1; */
    /* (void) ret2; */
    ck_assert_str_eq(ret1, ret2);
    ck_assert_str_eq(dest1, dest2);

    ck_assert_str_eq(dest1, "hello");
    /* free(dest1); */
    /* free(dest2); */
}
END_TEST

START_TEST(test_my_strncpy_should_success_level_2) {
    const char *src = "hello";
    //    const unsigned int len = strlen(src) - 2;

    char dest1[10];   // = (char *) malloc(sizeof(char) * len + 1);
    bzero(dest1, 10);
    char *ret1 = my_strncpy(dest1, src, 3);

    char dest2[10];   // = (char *) malloc(sizeof(char) * len + 1);
    bzero(dest2, 10);
    char *ret2 = strncpy(dest2, src, 3);

    ck_assert_str_eq(ret1, ret2);
    ck_assert_str_eq(dest1, dest2);

    ck_assert_str_eq(dest1, "hel");

    /* free(dest1); */
    /* free(dest2); */
}
END_TEST

Suite *my_strncpy_suite(void) {
    Suite *s = suite_create("my_strncpy");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strncpy_should_success_level_1);
    tcase_add_test(tc_core, test_my_strncpy_should_success_level_2);
    suite_add_tcase(s, tc_core);

    return s;
}
