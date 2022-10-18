#include "mytest.h"

START_TEST(test_my_strcat_should_success)
{
    ck_assert_str_eq(my_strcat("tata", "toto"), "tatatoto");
    ck_assert_str_eq(my_strcat("tata", "totosad12313"), "tatatotosad12313");
    ck_assert_str_eq(my_strcat("toto teuf", " encore un weekend"), "toto teuf encore un weekend");
}
END_TEST

Suite*  my_strcat_suite(void) 
{
    Suite *s = suite_create("my_strcat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strcat_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}