/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-11 12:27:25
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/unsigned char/test_non_arr_unsignedchar.h
 */

#ifndef __TEST_NON_ARR_UNSIGNED_CHAR_H_
#define __TEST_NON_ARR_UNSIGNED_CHAR_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleUnsignedCharStr {
    unsigned char str[100];
};
INIT(TestNonArrSingleUnsignedCharStr,
     struct TestNonArrSingleUnsignedCharStr,
     MEM(struct TestNonArrSingleUnsignedCharStr, Str, unsigned char, str, NULL));

struct TestNonArrSingleUnsignedCharNum {
    unsigned char num[5];
};
INIT(TestNonArrSingleUnsignedCharNum,
     struct TestNonArrSingleUnsignedCharNum,
     MEM(struct TestNonArrSingleUnsignedCharNum, Num, unsigned char, num, NULL));

struct TestNonArrSingleUnsignedCharBool {
    unsigned char b[5];
};
INIT(TestNonArrSingleUnsignedCharBool,
     struct TestNonArrSingleUnsignedCharBool,
     MEM(struct TestNonArrSingleUnsignedCharBool, Bool, unsigned char, b, NULL));

struct TestNonArrMultUnsignedCharStr {
    unsigned char str1[100];
    unsigned char str2[100];
    unsigned char str3[100];
};
INIT(TestNonArrMultUnsignedCharStr,
     struct TestNonArrMultUnsignedCharStr,
     MEM(struct TestNonArrMultUnsignedCharStr, Str, unsigned char, str1, NULL),
     MEM(struct TestNonArrMultUnsignedCharStr, Str, unsigned char, str2, NULL),
     MEM(struct TestNonArrMultUnsignedCharStr, Str, unsigned char, str3, NULL));

struct TestNonArrMultUnsignedCharNum {
    unsigned char num1[5];
    unsigned char num2[5];
    unsigned char num3[5];
    unsigned char num4[5];
    unsigned char num5[5];
};
INIT(TestNonArrMultUnsignedCharNum,
     struct TestNonArrMultUnsignedCharNum,
     MEM(struct TestNonArrMultUnsignedCharNum, Num, unsigned char, num1, NULL),
     MEM(struct TestNonArrMultUnsignedCharNum, Num, unsigned char, num2, NULL),
     MEM(struct TestNonArrMultUnsignedCharNum, Num, unsigned char, num3, NULL),
     MEM(struct TestNonArrMultUnsignedCharNum, Num, unsigned char, num4, NULL),
     MEM(struct TestNonArrMultUnsignedCharNum, Num, unsigned char, num5, NULL));

struct TestNonArrMultUnsignedCharBool {
    unsigned char bool1[5];
    unsigned char bool2[5];
    unsigned char bool3[5];
    unsigned char bool4[5];
    unsigned char bool5[5];
};
INIT(TestNonArrMultUnsignedCharBool,
     struct TestNonArrMultUnsignedCharBool,
     MEM(struct TestNonArrMultUnsignedCharBool, Bool, unsigned char, bool1, NULL),
     MEM(struct TestNonArrMultUnsignedCharBool, Bool, unsigned char, bool2, NULL),
     MEM(struct TestNonArrMultUnsignedCharBool, Bool, unsigned char, bool3, NULL),
     MEM(struct TestNonArrMultUnsignedCharBool, Bool, unsigned char, bool4, NULL),
     MEM(struct TestNonArrMultUnsignedCharBool, Bool, unsigned char, bool5, NULL));

// mult to json
char* test_change_non_arr_single_unsignedchar_str_to_json(char* exp, char* real);
char* test_change_non_arr_single_unsignedchar_num_to_json(char* exp, char* real);
char* test_change_non_arr_single_unsignedchar_bool_to_json(char* exp, char* real);
char* test_change_non_arr_mult_unsignedchar_str_to_json(char* exp, char* real);
char* test_change_non_arr_mult_unsignedchar_num_to_json(char* exp, char* real);
char* test_change_non_arr_mult_unsignedchar_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_mult_str_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_single_num_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_mult_num_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_single_bool_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_mult_bool_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_single_null_json_to_non_arr_single_unsignedchar_str(char* json);
int test_change_mult_null_json_to_non_arr_single_unsignedchar_str(char* json);

int test_change_single_str_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_mult_str_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_single_num_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_mult_num_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_single_bool_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_single_null_json_to_non_arr_single_unsignedchar_num(char* json);
int test_change_mult_null_json_to_non_arr_single_unsignedchar_num(char* json);

int test_change_single_str_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_single_num_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_single_null_json_to_non_arr_single_unsignedchar_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_unsignedchar_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json);

#endif
