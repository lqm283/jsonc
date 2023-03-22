/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-11 13:40:20
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/double/test_non_arr_double.h
 */

#ifndef __TEST_NON_ARR_DOUBLE_H_
#define __TEST_NON_ARR_DOUBLE_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleDoubleStr {
    double str[100];
};
INIT(TestNonArrSingleDoubleStr,
     struct TestNonArrSingleDoubleStr,
     MEM(struct TestNonArrSingleDoubleStr, Str, double, str, NULL));

struct TestNonArrSingleDoubleNum {
    double num[5];
};
INIT(TestNonArrSingleDoubleNum,
     struct TestNonArrSingleDoubleNum,
     MEM(struct TestNonArrSingleDoubleNum, Num, double, num, NULL));

struct TestNonArrSingleDoubleBool {
    double b[5];
};
INIT(TestNonArrSingleDoubleBool,
     struct TestNonArrSingleDoubleBool,
     MEM(struct TestNonArrSingleDoubleBool, Bool, double, b, NULL));

struct TestNonArrMultDoubleStr {
    double str1[100];
    double str2[100];
    double str3[100];
};
INIT(TestNonArrMultDoubleStr,
     struct TestNonArrMultDoubleStr,
     MEM(struct TestNonArrMultDoubleStr, Str, double, str1, NULL),
     MEM(struct TestNonArrMultDoubleStr, Str, double, str2, NULL),
     MEM(struct TestNonArrMultDoubleStr, Str, double, str3, NULL));

struct TestNonArrMultDoubleNum {
    double num1[5];
    double num2[5];
    double num3[5];
    double num4[5];
    double num5[5];
};
INIT(TestNonArrMultDoubleNum,
     struct TestNonArrMultDoubleNum,
     MEM(struct TestNonArrMultDoubleNum, Num, double, num1, NULL),
     MEM(struct TestNonArrMultDoubleNum, Num, double, num2, NULL),
     MEM(struct TestNonArrMultDoubleNum, Num, double, num3, NULL),
     MEM(struct TestNonArrMultDoubleNum, Num, double, num4, NULL),
     MEM(struct TestNonArrMultDoubleNum, Num, double, num5, NULL));

struct TestNonArrMultDoubleBool {
    double bool1[5];
    double bool2[5];
    double bool3[5];
    double bool4[5];
    double bool5[5];
};
INIT(TestNonArrMultDoubleBool,
     struct TestNonArrMultDoubleBool,
     MEM(struct TestNonArrMultDoubleBool, Bool, double, bool1, NULL),
     MEM(struct TestNonArrMultDoubleBool, Bool, double, bool2, NULL),
     MEM(struct TestNonArrMultDoubleBool, Bool, double, bool3, NULL),
     MEM(struct TestNonArrMultDoubleBool, Bool, double, bool4, NULL),
     MEM(struct TestNonArrMultDoubleBool, Bool, double, bool5, NULL));

// mult to json
int test_change_non_arr_single_double_num_to_json(char* exp, char* real);
int test_change_non_arr_single_double_bool_to_json(char* exp, char* real);
int test_change_non_arr_mult_double_num_to_json(char* exp, char* real);
int test_change_non_arr_mult_double_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_double_num(char* json);
int test_change_mult_str_json_to_non_arr_single_double_num(char* json);
int test_change_single_num_json_to_non_arr_single_double_num(char* json);
int test_change_mult_num_json_to_non_arr_single_double_num(char* json);
int test_change_single_bool_json_to_non_arr_single_double_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_double_num(char* json);
int test_change_single_null_json_to_non_arr_single_double_num(char* json);
int test_change_mult_null_json_to_non_arr_single_double_num(char* json);

int test_change_single_str_json_to_non_arr_single_double_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_double_bool(char* json);
int test_change_single_num_json_to_non_arr_single_double_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_double_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_double_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_double_bool(char* json);
int test_change_single_null_json_to_non_arr_single_double_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_double_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_double_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_double_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_double_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_double_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_double_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_double_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_double_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_double_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_double_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_double_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_double_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_double_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_double_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_double_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_double_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_double_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_double_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_double_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_double_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_double_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_double_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_double_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_double_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_double_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_double_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_double_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_double_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_double_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_double_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_double_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_double_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_double_bool(char* json);

#endif
