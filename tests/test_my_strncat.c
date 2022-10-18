#include "mytest.h"

START_TEST(test_my_strncat_should_success)
{
    ck_assert_str_eq(my_strncat("tata", "toto", 2), "tatato");
}
END_TEST

Suite*  my_strncat_suite(void) 
{
    Suite *s = suite_create("my_strncat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strncat_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}