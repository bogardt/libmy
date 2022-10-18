#include <string.h>
#include "mytest.h"

START_TEST(test_my_strncmp_should_success_level_1)
{
    const char *s1 = "test";
    const char *s2 = "test";

    ck_assert_int_eq(my_strncmp(s1, s2, strlen(s1)), strncmp(s1, s2, strlen(s1)));
}
END_TEST

START_TEST(test_my_strncmp_should_success_level_2)
{
    const char *s1 = "Thomas is in the kitchen !";
    const char *s2 = "Thomas is in the kitchen !";

    ck_assert_int_eq(my_strncmp(s1, s2, strlen(s1)), strncmp(s1, s2, strlen(s1)));
}
END_TEST

START_TEST(test_my_strncmp_should_success_level_3)
{
    const char *s1 = "Thomas is in the kitchen !";
    const char *s2 = "Thomas is in the kitchen !";

    ck_assert_int_eq(my_strncmp(s1, s2, strlen(s1) - 5), strncmp(s1, s2, strlen(s1) - 5));
}
END_TEST

START_TEST(test_my_strncmp_should_failed_level_1)
{
    const char *s1 = "test";
    const char *s2 = "test_tata";

    ck_assert_int_eq(my_strncmp(s1, s2, strlen(s1)), strncmp(s1, s2, strlen(s1)));
}
END_TEST

START_TEST(test_my_strncmp_should_failed_level_2)
{
    const char *s1 = "test";
    const char *s2 = "0329432094";

    ck_assert_int_eq(my_strncmp(s1, s2, strlen(s1)), strncmp(s1, s2, strlen(s1)));
}
END_TEST

START_TEST(test_my_strncmp_should_failed_level_3)
{
    const char *s1 = "test";
    const char *s2 = "test\t\n\r\0";

    ck_assert_int_eq(my_strncmp(s1, s2, strlen(s1)), strncmp(s1, s2, strlen(s1)));
}
END_TEST

START_TEST(test_my_strncmp_should_failed_level_4)
{
    const char *s1 = NULL;
    const char *s2 = "test";

    ck_assert_int_eq(my_strncmp(s1, s2, 0), strncmp(s1, s2, 0));
}
END_TEST

START_TEST(test_my_strncmp_should_failed_level_5)
{
    const char *s1 = NULL;
    const char *s2 = NULL;

    ck_assert_int_eq(my_strncmp(s1, s2, 0), strncmp(s1, s2, 0));
}
END_TEST

Suite *my_strncmp_suite(void)
{
    Suite *s = suite_create("my_strncmp");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strncmp_should_success_level_1);
    tcase_add_test(tc_core, test_my_strncmp_should_success_level_2);
    tcase_add_test(tc_core, test_my_strncmp_should_success_level_3);
    tcase_add_test(tc_core, test_my_strncmp_should_failed_level_1);
    tcase_add_test(tc_core, test_my_strncmp_should_failed_level_2);
    tcase_add_test(tc_core, test_my_strncmp_should_failed_level_3);
    tcase_add_test(tc_core, test_my_strncmp_should_failed_level_4);
    tcase_add_test(tc_core, test_my_strncmp_should_failed_level_5);
    suite_add_tcase(s, tc_core);

    return s;
}