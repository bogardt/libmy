#include "mytest.h"

START_TEST(test_my_strcat_should_success_level_1) {
    const char *src = "toto";

    char dest[9] = "tata";
    char *res = my_strcat(dest, src);

    (void)res;

    ck_assert_str_eq(dest, "tatatoto");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_2) {
    const char *src = "toto123";

    char dest[12] = "tata";
    char *res = my_strcat(dest, src);
    (void)res;

    ck_assert_str_eq(dest, "tatatoto123");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_3) {
    const char *src = " encore un weekend";

    char dest[28] = "toto teuf";
    char *res = my_strcat(dest, src);
    (void)res;

    ck_assert_str_eq(dest, "toto teuf encore un weekend");
}
END_TEST

START_TEST(test_my_strcat_should_success_level_4) {
    const char *str = "tata";
    const char *src = "toto";

    char *dest1 = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)) + 1);
    char *dest2 = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)) + 1);

    strcpy(dest1, str);
    strcpy(dest2, str);

    my_strcat(dest1, src);
    strcat(dest2, src);

    ck_assert_str_eq(dest1, "tatatoto");
    ck_assert_str_eq(dest2, "tatatoto");
    ck_assert_str_eq(dest1, dest2);

    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(test_my_strcat_should_success_level_5) {
    const char *str = "tata";
    const char *src = "toto123";

    char *dest1 = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)) + 1);
    char *dest2 = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)) + 1);

    strcpy(dest1, str);
    strcpy(dest2, str);

    my_strcat(dest1, src);
    strcat(dest2, src);

    ck_assert_str_eq(dest1, "tatatoto123");
    ck_assert_str_eq(dest2, "tatatoto123");
    ck_assert_str_eq(dest1, dest2);

    free(dest1);
    free(dest2);
}
END_TEST

START_TEST(test_my_strcat_should_success_level_6) {
    const char *str = "toto teuf";
    const char *src = " encore un weekend";

    char *dest1 = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)) + 1);
    char *dest2 = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)) + 1);

    strcpy(dest1, str);
    strcpy(dest2, str);

    my_strcat(dest1, src);
    strcat(dest2, src);

    ck_assert_str_eq(dest1, "toto teuf encore un weekend");
    ck_assert_str_eq(dest2, "toto teuf encore un weekend");
    ck_assert_str_eq(dest1, dest2);

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
    suite_add_tcase(s, tc_core);

    return s;
}