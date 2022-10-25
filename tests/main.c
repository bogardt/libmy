#include "mytest.h"

SRunner *only_one_test(void) { return srunner_create(my_strcat_suite()); }

SRunner *run_all(void) {
    SRunner *sr = srunner_create(my_is_digit_suite());

    srunner_add_suite(sr, my_is_alpha_suite());
    srunner_add_suite(sr, my_putstr_suite());
    srunner_add_suite(sr, my_strlen_suite());
    srunner_add_suite(sr, my_strnlen_suite());

    srunner_add_suite(sr, my_count_words_suite());
    srunner_add_suite(sr, my_split_suite());

    srunner_add_suite(sr, my_tolower_suite());
    srunner_add_suite(sr, my_toupper_suite());

    srunner_add_suite(sr, my_strcmp_suite());
    srunner_add_suite(sr, my_strncmp_suite());

    srunner_add_suite(sr, my_strcpy_suite());
    srunner_add_suite(sr, my_strncpy_suite());
    srunner_add_suite(sr, my_strlcpy_suite());

    srunner_add_suite(sr, my_strcat_suite());
    srunner_add_suite(sr, my_strncat_suite());
    srunner_add_suite(sr, my_strlcat_suite());

    srunner_add_suite(sr, my_memcpy_suite());
    srunner_add_suite(sr, my_memset_suite());
    srunner_add_suite(sr, my_bzero_suite());

    srunner_add_suite(sr, my_strchr_suite());

    return sr;
}

int main(void) {
    SRunner *sr = run_all();
    //  SRunner *sr = only_one_test();

    // run & print output with higher level of verbosity
    srunner_run_all(sr, CK_VERBOSE);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
