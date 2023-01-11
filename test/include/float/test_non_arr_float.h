/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-11 13:40:20
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/float/test_non_arr_float.h
 */

#ifndef __TEST_NON_ARR_FLOAT_H_
#define __TEST_NON_ARR_FLOAT_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleFloatStr {
    float str[100];
};
INIT(TestNonArrSingleFloatStr,
     struct TestNonArrSingleFloatStr,
     MEM(struct TestNonArrSingleFloatStr, Str, float, str, NULL));

struct TestNonArrSingleFloatNum {
    float num[5];
};
INIT(TestNonArrSingleFloatNum,
     struct TestNonArrSingleFloatNum,
     MEM(struct TestNonArrSingleFloatNum, Num, float, num, NULL));

struct TestNonArrSingleFloatBool {
    float b[5];
};
INIT(TestNonArrSingleFloatBool,
     struct TestNonArrSingleFloatBool,
     MEM(struct TestNonArrSingleFloatBool, Bool, float, b, NULL));

struct TestNonArrMultFloatStr {
    float str1[100];
    float str2[100];
    float str3[100];
};
INIT(TestNonArrMultFloatStr,
     struct TestNonArrMultFloatStr,
     MEM(struct TestNonArrMultFloatStr, Str, float, str1, NULL),
     MEM(struct TestNonArrMultFloatStr, Str, float, str2, NULL),
     MEM(struct TestNonArrMultFloatStr, Str, float, str3, NULL));

struct TestNonArrMultFloatNum {
    float num1[5];
    float num2[5];
    float num3[5];
    float num4[5];
    float num5[5];
};
INIT(TestNonArrMultFloatNum,
     struct TestNonArrMultFloatNum,
     MEM(struct TestNonArrMultFloatNum, Num, float, num1, NULL),
     MEM(struct TestNonArrMultFloatNum, Num, float, num2, NULL),
     MEM(struct TestNonArrMultFloatNum, Num, float, num3, NULL),
     MEM(struct TestNonArrMultFloatNum, Num, float, num4, NULL),
     MEM(struct TestNonArrMultFloatNum, Num, float, num5, NULL));

struct TestNonArrMultFloatBool {
    float bool1[5];
    float bool2[5];
    float bool3[5];
    float bool4[5];
    float bool5[5];
};
INIT(TestNonArrMultFloatBool,
     struct TestNonArrMultFloatBool,
     MEM(struct TestNonArrMultFloatBool, Bool, float, bool1, NULL),
     MEM(struct TestNonArrMultFloatBool, Bool, float, bool2, NULL),
     MEM(struct TestNonArrMultFloatBool, Bool, float, bool3, NULL),
     MEM(struct TestNonArrMultFloatBool, Bool, float, bool4, NULL),
     MEM(struct TestNonArrMultFloatBool, Bool, float, bool5, NULL));

// mult to json
char* test_change_non_arr_single_float_num_to_json(char* exp, char* real);
char* test_change_non_arr_single_float_bool_to_json(char* exp, char* real);
char* test_change_non_arr_mult_float_num_to_json(char* exp, char* real);
char* test_change_non_arr_mult_float_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_float_num(char* json);
int test_change_mult_str_json_to_non_arr_single_float_num(char* json);
int test_change_single_num_json_to_non_arr_single_float_num(char* json);
int test_change_mult_num_json_to_non_arr_single_float_num(char* json);
int test_change_single_bool_json_to_non_arr_single_float_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_float_num(char* json);
int test_change_single_null_json_to_non_arr_single_float_num(char* json);
int test_change_mult_null_json_to_non_arr_single_float_num(char* json);

int test_change_single_str_json_to_non_arr_single_float_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_float_bool(char* json);
int test_change_single_num_json_to_non_arr_single_float_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_float_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_float_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_float_bool(char* json);
int test_change_single_null_json_to_non_arr_single_float_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_float_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_float_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_float_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_float_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_float_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_float_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_float_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_float_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_float_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_float_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_float_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_float_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_float_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_float_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_float_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_float_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_float_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_float_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_float_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_float_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_float_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_float_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_float_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_float_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_float_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_float_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_float_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_float_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_float_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_float_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_float_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_float_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_float_bool(char* json);

#endif
