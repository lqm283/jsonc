/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-09 16:53:37
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/char/test_non_arr_char.h
 */

#ifndef __TEST_NON_ARR_CHAR_H_
#define __TEST_NON_ARR_CHAR_H_

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleCharStr {
    char str[100];
};
INIT(TestNonArrSingleCharStr,
     struct TestNonArrSingleCharStr,
     MEM(struct TestNonArrSingleCharStr, Str, char, str, NULL));

struct TestNonArrSingleCharNum {
    char num[5];
};
INIT(TestNonArrSingleCharNum,
     struct TestNonArrSingleCharNum,
     MEM(struct TestNonArrSingleCharNum, Num, char, num, NULL));

struct TestNonArrSingleCharBool {
    char b[5];
};
INIT(TestNonArrSingleCharBool,
     struct TestNonArrSingleCharBool,
     MEM(struct TestNonArrSingleCharBool, Bool, char, b, NULL));

struct TestNonArrMultCharStr {
    char str1[100];
    char str2[100];
    char str3[100];
};
INIT(TestNonArrMultCharStr,
     struct TestNonArrMultCharStr,
     MEM(struct TestNonArrMultCharStr, Str, char, str1, NULL),
     MEM(struct TestNonArrMultCharStr, Str, char, str2, NULL),
     MEM(struct TestNonArrMultCharStr, Str, char, str3, NULL));

struct TestNonArrMultCharNum {
    char num1[5];
    char num2[5];
    char num3[5];
    char num4[5];
    char num5[5];
};
INIT(TestNonArrMultCharNum,
     struct TestNonArrMultCharNum,
     MEM(struct TestNonArrMultCharNum, Num, char, num1, NULL),
     MEM(struct TestNonArrMultCharNum, Num, char, num2, NULL),
     MEM(struct TestNonArrMultCharNum, Num, char, num3, NULL),
     MEM(struct TestNonArrMultCharNum, Num, char, num4, NULL),
     MEM(struct TestNonArrMultCharNum, Num, char, num5, NULL));

struct TestNonArrMultCharBool {
    char bool1[5];
    char bool2[5];
    char bool3[5];
    char bool4[5];
    char bool5[5];
};
INIT(TestNonArrMultCharBool,
     struct TestNonArrMultCharBool,
     MEM(struct TestNonArrMultCharBool, Bool, char, bool1, NULL),
     MEM(struct TestNonArrMultCharBool, Bool, char, bool2, NULL),
     MEM(struct TestNonArrMultCharBool, Bool, char, bool3, NULL),
     MEM(struct TestNonArrMultCharBool, Bool, char, bool4, NULL),
     MEM(struct TestNonArrMultCharBool, Bool, char, bool5, NULL));

// mult to json
char* test_change_non_arr_single_char_str_to_json(char* exp, char* real);
char* test_change_non_arr_single_char_num_to_json(char* exp, char* real);
char* test_change_non_arr_single_char_bool_to_json(char* exp, char* real);
char* test_change_non_arr_mult_char_str_to_json(char* exp, char* real);
char* test_change_non_arr_mult_char_num_to_json(char* exp, char* real);
char* test_change_non_arr_mult_char_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_char_str(char* json);
int test_change_mult_str_json_to_non_arr_single_char_str(char* json);
int test_change_single_num_json_to_non_arr_single_char_str(char* json);
int test_change_mult_num_json_to_non_arr_single_char_str(char* json);
int test_change_single_bool_json_to_non_arr_single_char_str(char* json);
int test_change_mult_bool_json_to_non_arr_single_char_str(char* json);
int test_change_single_null_json_to_non_arr_single_char_str(char* json);
int test_change_mult_null_json_to_non_arr_single_char_str(char* json);

int test_change_single_str_json_to_non_arr_single_char_num(char* json);
int test_change_mult_str_json_to_non_arr_single_char_num(char* json);
int test_change_single_num_json_to_non_arr_single_char_num(char* json);
int test_change_mult_num_json_to_non_arr_single_char_num(char* json);
int test_change_single_bool_json_to_non_arr_single_char_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_char_num(char* json);
int test_change_single_null_json_to_non_arr_single_char_num(char* json);
int test_change_mult_null_json_to_non_arr_single_char_num(char* json);

int test_change_single_str_json_to_non_arr_single_char_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_char_bool(char* json);
int test_change_single_num_json_to_non_arr_single_char_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_char_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_char_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_char_bool(char* json);
int test_change_single_null_json_to_non_arr_single_char_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_char_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_char_str(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_char_str(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_char_str(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_char_str(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_char_str(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_char_str(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_char_str(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_char_str(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_char_str(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_char_str(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_char_str(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_char_str(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_char_str(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_char_str(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_char_str(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_char_str(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_char_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_char_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_char_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_char_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_char_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_char_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_char_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_char_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_char_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_char_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_char_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_char_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_char_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_char_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_char_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_char_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_char_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_char_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_char_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_char_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_char_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_char_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_char_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_char_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_char_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_char_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_char_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_char_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_char_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_char_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_char_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_char_bool(char* json);

#endif
