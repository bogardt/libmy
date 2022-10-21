#include "bsd/string.h"
#include "mytest.h"

#define FULL_PATH_MAX_LEN 15
#define FULL_PATH_RES     "hello world"

/* START_TEST(test_my_strlcat_should_copy) { */
/*     char full_path[FULL_PATH_MAX_LEN] = "hello"; */

/*     ck_assert_int_eq(my_strlcpy(full_path, " wolrd", FULL_PATH_MAX_LEN), */
/*                      strlen(FULL_PATH_RES)); */
/*     ck_assert_str_eq(full_path, FULL_PATH_RES); */
/* } */
/* END_TEST */

START_TEST(test_my_strlcat_should_trunkat) {
    char full_path[FULL_PATH_MAX_LEN], BSD_full_path[FULL_PATH_MAX_LEN];
    char *src = "hello world long string";

    unsigned int ret = my_strlcpy(full_path, src, FULL_PATH_MAX_LEN);
    unsigned int BSD_ret = strlcpy(BSD_full_path, src, FULL_PATH_MAX_LEN);

    ck_assert_int_eq(ret, BSD_ret);
    ck_assert_str_eq(full_path, BSD_full_path);

    ck_assert_int_eq(ret, strlen(src));
    ck_assert_str_eq(full_path, FULL_PATH_RES " lo");
}
END_TEST

Suite *my_strlcat_suite(void) {
    Suite *s = suite_create("my_strlcat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    // tcase_add_test(tc_core, test_my_strlcat_should_copy);
    tcase_add_test(tc_core, test_my_strlcat_should_trunkat);
    suite_add_tcase(s, tc_core);

    return s;
}
