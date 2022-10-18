#include "mytest.h"
#include <string.h>
#include <stdio.h>

START_TEST(test_my_strcat_should_success_level_1)
{
    char *s1 = "tata";
    char *s2 = "toto";

    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strcat(res, s2), "tatatoto");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_2)
{
    char *s1 = "tata";
    char *s2 = "totosad12313";

    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strcat(res, s2), "tatatotosad12313");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_3)
{
    char *s1 = "toto teuf";
    char *s2 = " encore un weekend";

    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strcat(res, s2), "toto teuf encore un weekend");
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
    suite_add_tcase(s, tc_core);

    return s;
}