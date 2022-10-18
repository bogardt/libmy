#include "mytest.h"
#include <string.h>

START_TEST(test_my_strncat_should_success_level_1)
{
    char *s1 = "tata";
    char *s2 = "toto";

    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strncat(res, s2, 1), "tatat");
}
END_TEST

START_TEST(test_my_strncat_should_success_level_2)
{
    char *s1 = "tata";
    char *s2 = "totosad12313";

    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strncat(res, s2, 3), "tatatot");
}
END_TEST

START_TEST(test_my_strncat_should_success_level_3)
{
    char *s1 = "toto teuf";
    char *s2 = " encore un weekend";

    int length = strlen(s1) + strlen(s2);
    char *res = (char *)malloc(sizeof(char) * length);
    
    strcpy(res, s1);

    ck_assert_str_eq(my_strncat(res, s2, 5), "toto teuf enco");
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
    suite_add_tcase(s, tc_core);

    return s;
}