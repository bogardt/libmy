#include "mytest.h"

START_TEST(test_my_strncpy_should_success_level_1)
{
    const char *src = "hello";
    const unsigned int len = strlen(src);

    char *dest1 = (char *)malloc(sizeof(char) * len + 1);
    char *ret1 = my_strncpy(dest1, src, len - 1);

    char *dest2 = (char *)malloc(sizeof(char) * len + 1);
    char *ret2 = strncpy(dest2, src, len - 1);

    (void)ret1;
    (void)ret2;
    ck_assert_str_eq(ret1, ret2);
    ck_assert_str_eq(dest1, dest2);

    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(test_my_strncpy_should_success_level_2)
{
    const char *src = "hello";
    const unsigned int len = strlen(src) - 2;

    char *dest1 = (char *)malloc(sizeof(char) * len + 1);
    char *ret1 = my_strncpy(dest1, src, len);

    char *dest2 = (char *)malloc(sizeof(char) * len + 1);
    char *ret2 = strncpy(dest2, src, len);

    ck_assert_str_eq(ret1, ret2);
    ck_assert_str_eq(dest1, dest2);

    free(dest1);
    free(dest2);
}
END_TEST

Suite *my_strncpy_suite(void)
{
    Suite *s = suite_create("my_strncpy");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strncpy_should_success_level_1);
    tcase_add_test(tc_core, test_my_strncpy_should_success_level_2);
    suite_add_tcase(s, tc_core);

    return s;
}