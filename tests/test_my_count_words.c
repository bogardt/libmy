#include "mytest.h"
#include <string.h>

START_TEST(test_my_count_words_should_success) {
    /* value shouldn't be changed */
    ck_assert_int_eq(my_count_words("test", ' '), 1);
    ck_assert_int_eq(my_count_words("test toto", ' '), 2);
    ck_assert_int_eq(my_count_words("test  toto", ' '), 2);
    ck_assert_int_eq(my_count_words("test      toto", ' '), 2);
    ck_assert_int_eq(my_count_words("test      toto ", ' '), 2);
    ck_assert_int_eq(my_count_words(" test      toto", ' '), 2);
    ck_assert_int_eq(my_count_words("  test      toto  ", ' '), 2);
    ck_assert_int_eq(my_count_words("  test      toto", ' '), 2);
    ck_assert_int_eq(my_count_words("test      toto  ", ' '), 2);
    ck_assert_int_eq(
        my_count_words(
            "                          test      toto                        ",
            ' '),
        2);
}
END_TEST

Suite *my_count_words_suite(void) {
    Suite *s = suite_create("my_count_words");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_count_words_should_success);
    suite_add_tcase(s, tc_core);

    return s;
}