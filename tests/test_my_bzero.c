#include "mytest.h"

START_TEST(test_my_bzero) {
    char smth[10] = "aaaaaaaaaa";

    my_bzero(smth, 5);
    ck_assert_int_eq(smth[6], 'a');
}
END_TEST

Suite *my_bzero_suite(void) {
    Suite *s = suite_create("my_bzero");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_bzero);
    suite_add_tcase(s, tc_core);

    return s;
}
