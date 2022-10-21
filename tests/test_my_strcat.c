#include "mytest.h"
#include <string.h>

START_TEST(test_my_strcat_should_success_level_1) {
    const char *src = "toto";

    char dest[8] = "tata";
    char *res = my_strcat(dest, src);

    ck_assert_str_eq(res, "tatatoto");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_2) {
    const char *src = "toto123";

    char dest[11] = "tata";
    char *res = my_strcat(dest, src);

    ck_assert_str_eq(res, "tatatoto123");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_3) {
    const char *src = " encore un weekend";

    char dest[27] = "toto teuf";
    char *res = my_strcat(dest, src);

    ck_assert_str_eq(res, "toto teuf encore un weekend");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_4) {
    const char *src = "toto";

    char dest[8] = "tata";
    int length = strlen(dest) + strlen(src);
    char *cpy = (char *) malloc(sizeof(char) * length + 1);

    my_strcpy(cpy, dest);

    char *res = my_strcat(cpy, src);

    ck_assert_str_eq(res, "tatatoto");

    free(res);
}
END_TEST

START_TEST(test_my_strcat_should_success_level_5) {
    const char *src = "toto";

    char *dest1 = strdup("tata");
    char *dest2 = strdup("tata");

    char *res1 = my_strcat(dest1, src);

    char *res2 = strcat(dest2, src);

    ck_assert_str_eq(res1, "tatatoto");
    ck_assert_str_eq(res2, "tatatoto");
    ck_assert_str_eq(res1, res2);

    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(test_my_strcat_should_success_level_6) {
    const char *src = "toto123";

    char *dest1 = strdup("tata");
    char *dest2 = strdup("tata");

    char *res1 = my_strcat(dest1, src);
    char *res2 = strcat(dest2, src);

    ck_assert_str_eq(res1, "tatatoto123");
    ck_assert_str_eq(res2, "tatatoto123");
    ck_assert_str_eq(res1, res2);

    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(test_my_strcat_should_success_level_7) {
    const char *src = " encore un weekend";

    char *dest1 = strndup("toto teuf", 27);
    char *dest2 = strndup("toto teuf", 27);

    char *res1 = my_strcat(dest1, src);
    char *res2 = strcat(dest2, src);

    ck_assert_str_eq(res1, "toto teuf encore un weekend");
    ck_assert_str_eq(res2, "toto teuf encore un weekend");
    ck_assert_str_eq(res1, res2);

    free(dest1);
    free(dest2);
}
END_TEST

Suite *my_strcat_suite(void) {
    Suite *s = suite_create("my_strcat");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_my_strcat_should_success_level_1);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_2);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_3);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_4);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_5);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_6);
    tcase_add_test(tc_core, test_my_strcat_should_success_level_7);
    suite_add_tcase(s, tc_core);

    return s;
}