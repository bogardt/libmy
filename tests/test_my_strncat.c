#include "mytest.h"
#include <string.h>

START_TEST(test_my_strncat_should_success_level_1)
{
    char s1[8] = "tata";
    char *s2 = "toto";
    char *res = my_strcat(s1, s2);

    ck_assert_str_eq(res, "tatatoto");
}
END_TEST

START_TEST(test_my_strncat_should_success_level_2)
{
    char s1[11] = "tata";
    char *s2 = "toto123";
    char *res = my_strcat(s1, s2);

    ck_assert_str_eq(res, "tatatoto123");
}
END_TEST

START_TEST(test_my_strncat_should_success_level_3)
{
    char s1[27] = "toto teuf";
    char *s2 = " encore un weekend";
    char *res = my_strcat(s1, s2);

    ck_assert_str_eq(res, "toto teuf encore un weekend");
}
END_TEST

START_TEST(test_my_strncat_should_success_level_4)
{
    char *s1 = "tata";
    char *s2 = "toto";
    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length + 1);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strncat(res, s2, 1), "tatat");

    free(res);
}
END_TEST

START_TEST(test_my_strncat_should_success_level_5)
{
    char *s1 = "tata";
    char *s2 = "totosad12313";
    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length + 1);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strncat(res, s2, 3), "tatatot");

    free(res);
}
END_TEST

START_TEST(test_my_strncat_should_success_level_6)
{
    char *s1 = "toto teuf";
    char *s2 = " encore un weekend";
    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length + 1);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strncat(res, s2, 5), "toto teuf enco");

    free(res);
}
END_TEST

START_TEST(test_my_strncat_should_success_level_7)
{
    char *s1 = "toto teuf";
    char *s2 = " encore un weekend";
    int length = strlen(s1) + strlen(s2);

    char *res1 = (char *)malloc(sizeof(char) * length + 1);
    strcpy(res1, s1);
    char *ret1 = my_strncat(res1, s2, 5);

    char *res2 = (char *)malloc(sizeof(char) * length + 1);
    strcpy(res2, s1);
    char *ret2 = my_strncat(res2, s2, 5);

    ck_assert_str_eq(ret1, "toto teuf enco");
    ck_assert_str_eq(ret2, "toto teuf enco");
    ck_assert_str_eq(ret1, ret2);

    free(res1);
    free(res2);
}
END_TEST

Suite *my_strncat_suite(void)
{
    Suite *s = suite_create("my_strncat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strncat_should_success_level_1);
    tcase_add_test(tc_core, test_my_strncat_should_success_level_2);
    tcase_add_test(tc_core, test_my_strncat_should_success_level_3);
    tcase_add_test(tc_core, test_my_strncat_should_success_level_4);
    tcase_add_test(tc_core, test_my_strncat_should_success_level_5);
    tcase_add_test(tc_core, test_my_strncat_should_success_level_6);
    tcase_add_test(tc_core, test_my_strncat_should_success_level_7);
    suite_add_tcase(s, tc_core);

    return s;
}