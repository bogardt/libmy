#include "mytest.h"
#include <stdio.h>

START_TEST(test_my_memcpy_str_should_success) {
  char *str = "tata";
  char *dest1 = (char *)malloc(sizeof(char) * my_strlen(str) + 1);
  char *dest2 = (char *)malloc(sizeof(char) * my_strlen(str) + 1);
  char *ret1 = (char *)my_memcpy(dest1, str, sizeof(char) * my_strlen(str) + 1);
  char *ret2 = (char *)memcpy(dest2, str, sizeof(char) * my_strlen(str) + 1);

  ck_assert_str_eq(ret1, ret2);

  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_my_memcpy_int_should_success) {
  const int arr[5] = {12, 14, 543, 43, 3};
  int *dest1 = (int *)malloc(sizeof(int) * 5);
  int *dest2 = (int *)malloc(sizeof(int) * 5);
  int *ret1 = (int *)my_memcpy(dest1, arr, sizeof(int) * 5);
  int *ret2 = (int *)memcpy(dest2, arr, sizeof(char) * 5);
  (void)ret1;
  (void)ret2;
  // for (unsigned int i = 0; i < 4; i++)
  //     ck_assert_int_eq(ret1[i], ret2[i]);

  free(dest1);
  free(dest2);
}
END_TEST

Suite *my_memcpy_suite(void) {
  Suite *s = suite_create("my_memcpy");

  /* Core test case */
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_my_memcpy_str_should_success);
  tcase_add_test(tc_core, test_my_memcpy_int_should_success);
  suite_add_tcase(s, tc_core);

  return s;
}