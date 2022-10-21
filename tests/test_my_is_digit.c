#include "./mytest.h"

START_TEST(test_my_is_digit_should_success) {
  for (char c = '0'; c <= '9'; c++)
    ck_assert_int_eq(my_is_digit(c), 1);
}
END_TEST

START_TEST(test_my_is_digit_should_fail) {
  ck_assert_int_eq(my_is_digit('a'), 0);
  ck_assert_int_eq(my_is_digit(' '), 0);
  ck_assert_int_eq(my_is_digit('\t'), 0);
  ck_assert_int_eq(my_is_digit('\n'), 0);
}
END_TEST

Suite *my_is_digit_suite(void) {
  Suite *s = suite_create("my_is_digit");

  /* Core test case */
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_my_is_digit_should_success);
  tcase_add_test(tc_core, test_my_is_digit_should_fail);
  suite_add_tcase(s, tc_core);

  return s;
}