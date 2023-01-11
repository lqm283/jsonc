/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 14:16:06
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/double/test_non_non_double.h
 */
#ifndef __TEST_NON_NON_DOUBLE_H_
#define __TEST_NON_NON_DOUBLE_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleDoubleStr {
    double str;
};
INIT(TestNonNonSingleDoubleStr,
     struct TestNonNonSingleDoubleStr,
     MEM(struct TestNonNonSingleDoubleStr, Str, double, str, NULL));

struct TestNonNonSingleDoubleNum {
    double num;
};
INIT(TestNonNonSingleDoubleNum,
     struct TestNonNonSingleDoubleNum,
     MEM(struct TestNonNonSingleDoubleNum, Num, double, num, NULL));

struct TestNonNonSingleDoubleBool {
    double b;
};
INIT(TestNonNonSingleDoubleBool,
     struct TestNonNonSingleDoubleBool,
     MEM(struct TestNonNonSingleDoubleBool, Bool, double, b, NULL));

struct TestNonNonMultDoubleStr {
    double str1;
    double str2;
    double str3;
};
INIT(TestNonNonMultDoubleStr,
     struct TestNonNonMultDoubleStr,
     MEM(struct TestNonNonMultDoubleStr, Str, double, str1, NULL),
     MEM(struct TestNonNonMultDoubleStr, Str, double, str2, NULL),
     MEM(struct TestNonNonMultDoubleStr, Str, double, str3, NULL));

struct TestNonNonMultDoubleNum {
    double num1;
    double num2;
    double num3;
    double num4;
    double num5;
};
INIT(TestNonNonMultDoubleNum,
     struct TestNonNonMultDoubleNum,
     MEM(struct TestNonNonMultDoubleNum, Num, double, num1, NULL),
     MEM(struct TestNonNonMultDoubleNum, Num, double, num2, NULL),
     MEM(struct TestNonNonMultDoubleNum, Num, double, num3, NULL),
     MEM(struct TestNonNonMultDoubleNum, Num, double, num4, NULL),
     MEM(struct TestNonNonMultDoubleNum, Num, double, num5, NULL));

struct TestNonNonMultDoubleBool {
    double bool1;
    double bool2;
    double bool3;
    double bool4;
    double bool5;
};
INIT(TestNonNonMultDoubleBool,
     struct TestNonNonMultDoubleBool,
     MEM(struct TestNonNonMultDoubleBool, Bool, double, bool1, NULL),
     MEM(struct TestNonNonMultDoubleBool, Bool, double, bool2, NULL),
     MEM(struct TestNonNonMultDoubleBool, Bool, double, bool3, NULL),
     MEM(struct TestNonNonMultDoubleBool, Bool, double, bool4, NULL),
     MEM(struct TestNonNonMultDoubleBool, Bool, double, bool5, NULL));

// mult to json
char* test_change_non_non_single_double_num_to_json(char* exp, char* real);
char* test_change_non_non_single_double_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_double_num_to_json(char* exp, char* real);
char* test_change_non_non_mult_double_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_double_num(char* json);
int test_change_mult_str_json_to_non_non_single_double_num(char* json);
int test_change_single_num_json_to_non_non_single_double_num(char* json);
int test_change_mult_num_json_to_non_non_single_double_num(char* json);
int test_change_single_bool_json_to_non_non_single_double_num(char* json);
int test_change_mult_bool_json_to_non_non_single_double_num(char* json);
int test_change_single_null_json_to_non_non_single_double_num(char* json);
int test_change_mult_null_json_to_non_non_single_double_num(char* json);

int test_change_single_str_json_to_non_non_single_double_bool(char* json);
int test_change_mult_str_json_to_non_non_single_double_bool(char* json);
int test_change_single_num_json_to_non_non_single_double_bool(char* json);
int test_change_mult_num_json_to_non_non_single_double_bool(char* json);
int test_change_single_bool_json_to_non_non_single_double_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_double_bool(char* json);
int test_change_single_null_json_to_non_non_single_double_bool(char* json);
int test_change_mult_null_json_to_non_non_single_double_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_double_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_double_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_double_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_double_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_double_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_double_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_double_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_double_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_double_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_double_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_double_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_double_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_double_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_double_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_double_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_double_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_double_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_double_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_double_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_double_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_double_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_double_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_double_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_double_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_double_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_double_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_double_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_double_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_double_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_double_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_double_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_double_bool(char* json);

#endif
