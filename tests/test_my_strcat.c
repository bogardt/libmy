#include "mytest.h"
#include <string.h>

START_TEST(test_my_strcat_should_success_level_1)
{
    char s1[8] = "tata";
    char *s2 = "toto";
    char *res = my_strcat(s1, s2);

    ck_assert_str_eq(res, "tatatoto");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_2)
{
    char s1[11] = "tata";
    char *s2 = "toto123";
    char *res = my_strcat(s1, s2);

    ck_assert_str_eq(res, "tatatoto123");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_3)
{
    char s1[27] = "toto teuf";
    char *s2 = " encore un weekend";
    char *res = my_strcat(s1, s2);

    ck_assert_str_eq(res, "toto teuf encore un weekend");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_4)
{
    char s1[8] = "tata";
    char *s2 = "toto";
    int length = strlen(s1) + strlen(s2);
    char *cpy = (char *)malloc(sizeof(char) * length + 1);

    my_strcpy(cpy, s1);

    char *res = my_strcat(cpy, s2);

    ck_assert_str_eq(res, "tatatoto");

    free(res);
}
END_TEST

Suite *my_strcat_suite(void)
{
    Suite *s = suite_create("my_strcat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strcat_should_success_level_1);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_2);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_3);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_4);
    suite_add_tcase(s, tc_core);

    return s;
}