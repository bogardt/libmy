#ifndef __MY_TEST_H__
#define __MY_TEST_H__

#include <stdlib.h>
#include <check.h>
#include "../includes/libmy.h"

Suite *my_is_digit_suite(void);
Suite *my_is_alpha_suite(void);
Suite *my_putstr_suite(void);
Suite *my_strlen_suite(void);
Suite *my_split_suite(void);
Suite *my_count_words_suite(void);
Suite *my_strcat_suite(void);
Suite *my_strncat_suite(void);
Suite *my_strlcat_suite(void);
Suite *my_tolower_suite(void);
Suite *my_toupper_suite(void);
Suite *my_strcmp_suite(void);
Suite *my_strncmp_suite(void);
Suite *my_strcpy_suite(void);
Suite *my_strncpy_suite(void);
Suite *my_strlcpy_suite(void);
Suite *my_memcpy_suite(void);

#endif /* !__MY_TEST_H__ */