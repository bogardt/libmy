#include "mytest.h"

START_TEST(test_my_strcpy_should_success)
{
    const char *src = "hello";
    const unsigned int len = strlen(src);

    char *dest1 = (char *)malloc(sizeof(char) * len + 1);
    char *ret1 = my_strcpy(dest1, src);

    char *dest2 = (char *)malloc(sizeof(char) * len + 1);
    char *ret2 = strcpy(dest2, src);

    ck_assert_str_eq(ret1, ret2);
    ck_assert_str_eq(dest1, dest2);

    free(dest1);
    free(dest2);
}
END_TEST

Suite *my_strcpy_suite(void)
{
    Suite *s = suite_create("my_strcpy");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strcpy_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}