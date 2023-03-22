/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 13:43:17
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/float/test_non_non_float.h
 */
#ifndef __TEST_NON_NON_FLOAT_H_
#define __TEST_NON_NON_FLOAT_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleFloatStr {
    float str;
};
INIT(TestNonNonSingleFloatStr,
     struct TestNonNonSingleFloatStr,
     MEM(struct TestNonNonSingleFloatStr, Str, float, str, NULL));

struct TestNonNonSingleFloatNum {
    float num;
};
INIT(TestNonNonSingleFloatNum,
     struct TestNonNonSingleFloatNum,
     MEM(struct TestNonNonSingleFloatNum, Num, float, num, NULL));

struct TestNonNonSingleFloatBool {
    float b;
};
INIT(TestNonNonSingleFloatBool,
     struct TestNonNonSingleFloatBool,
     MEM(struct TestNonNonSingleFloatBool, Bool, float, b, NULL));

struct TestNonNonMultFloatStr {
    float str1;
    float str2;
    float str3;
};
INIT(TestNonNonMultFloatStr,
     struct TestNonNonMultFloatStr,
     MEM(struct TestNonNonMultFloatStr, Str, float, str1, NULL),
     MEM(struct TestNonNonMultFloatStr, Str, float, str2, NULL),
     MEM(struct TestNonNonMultFloatStr, Str, float, str3, NULL));

struct TestNonNonMultFloatNum {
    float num1;
    float num2;
    float num3;
    float num4;
    float num5;
};
INIT(TestNonNonMultFloatNum,
     struct TestNonNonMultFloatNum,
     MEM(struct TestNonNonMultFloatNum, Num, float, num1, NULL),
     MEM(struct TestNonNonMultFloatNum, Num, float, num2, NULL),
     MEM(struct TestNonNonMultFloatNum, Num, float, num3, NULL),
     MEM(struct TestNonNonMultFloatNum, Num, float, num4, NULL),
     MEM(struct TestNonNonMultFloatNum, Num, float, num5, NULL));

struct TestNonNonMultFloatBool {
    float bool1;
    float bool2;
    float bool3;
    float bool4;
    float bool5;
};
INIT(TestNonNonMultFloatBool,
     struct TestNonNonMultFloatBool,
     MEM(struct TestNonNonMultFloatBool, Bool, float, bool1, NULL),
     MEM(struct TestNonNonMultFloatBool, Bool, float, bool2, NULL),
     MEM(struct TestNonNonMultFloatBool, Bool, float, bool3, NULL),
     MEM(struct TestNonNonMultFloatBool, Bool, float, bool4, NULL),
     MEM(struct TestNonNonMultFloatBool, Bool, float, bool5, NULL));

// mult to json
int test_change_non_non_single_float_num_to_json(char* exp, char* real);
int test_change_non_non_single_float_bool_to_json(char* exp, char* real);
int test_change_non_non_mult_float_num_to_json(char* exp, char* real);
int test_change_non_non_mult_float_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_float_num(char* json);
int test_change_mult_str_json_to_non_non_single_float_num(char* json);
int test_change_single_num_json_to_non_non_single_float_num(char* json);
int test_change_mult_num_json_to_non_non_single_float_num(char* json);
int test_change_single_bool_json_to_non_non_single_float_num(char* json);
int test_change_mult_bool_json_to_non_non_single_float_num(char* json);
int test_change_single_null_json_to_non_non_single_float_num(char* json);
int test_change_mult_null_json_to_non_non_single_float_num(char* json);

int test_change_single_str_json_to_non_non_single_float_bool(char* json);
int test_change_mult_str_json_to_non_non_single_float_bool(char* json);
int test_change_single_num_json_to_non_non_single_float_bool(char* json);
int test_change_mult_num_json_to_non_non_single_float_bool(char* json);
int test_change_single_bool_json_to_non_non_single_float_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_float_bool(char* json);
int test_change_single_null_json_to_non_non_single_float_bool(char* json);
int test_change_mult_null_json_to_non_non_single_float_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_float_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_float_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_float_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_float_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_float_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_float_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_float_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_float_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_float_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_float_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_float_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_float_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_float_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_float_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_float_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_float_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_float_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_float_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_float_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_float_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_float_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_float_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_float_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_float_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_float_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_float_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_float_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_float_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_float_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_float_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_float_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_float_bool(char* json);

#endif
