#include "mytest.h"
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>

START_TEST(test_my_strlcat_should_success_level_1)
{
    // char *src = "toto";

    // char s1[7] = "tata";
    // int res = my_strlcat(s1, src, 5);

// todo: chantier
    // char s2[4] = "tata";
    // int res_strlcat = strlcat(s2, src, 2);

    // printf("res: [%d] & s2: [%s]\n", res_strlcat, s2);

    // ck_assert_int_eq(res, res_strlcat);
    // ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_my_strlcat_should_success_level_2)
{
    // char *src = "toto123";

    // char s1[7] = "tata";
    // int res = my_strlcat(s1, src, 5);

    // char s2[7] = "tata";
    // int res_strlcat = strlcat(s2, src, 5);

    // ck_assert_int_eq(res, res_strlcat);
    // ck_assert_str_eq(s1, s2);
    
}
END_TEST

START_TEST(test_my_strlcat_should_success_level_3)
{
    // char *src = NULL;

    // char s1[7] = "tata";
    // int res = my_strlcat(s1, src, 5);
    // (void) res;
    // char s2[7] = "tata";
    // int res_strlcat = strlcat(s2, src, 5);
    // (void)res_strlcat;
    // ck_assert_int_eq(res, res_strlcat);
}
END_TEST

// START_TEST(test_my_strlcat_should_success_level_4)
// {
//     char s1[8] = "tata";
//     char *s2 = "toto";
//     int length = strlen(s1) + strlen(s2);
//     char *cpy = (char *)malloc(sizeof(char) * length + 1);

//     my_strcpy(cpy, s1);

//     char *res = my_strlcat(cpy, s2, 8);

//     ck_assert_str_eq(res, "tatatoto");

//     free(res);
// }
// END_TEST

Suite *my_strlcat_suite(void)
{
    Suite *s = suite_create("my_strlcat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strlcat_should_success_level_1);
    tcase_add_test(tc_core, test_my_strlcat_should_success_level_2);
    tcase_add_test(tc_core, test_my_strlcat_should_success_level_3);
    // tcase_add_test(tc_core, test_my_strlcat_should_success_level_4);
    suite_add_tcase(s, tc_core);

    return s;
}