/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 08:26:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int16/test_non_non_int16.h
 */
#ifndef __TEST_NON_NON_INT16_H_
#define __TEST_NON_NON_INT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleInt16Str {
    int16_t str;
};
INIT(TestNonNonSingleInt16Str,
     struct TestNonNonSingleInt16Str,
     MEM(struct TestNonNonSingleInt16Str, Str, int16_t, str, NULL));

struct TestNonNonSingleInt16Num {
    int16_t num;
};
INIT(TestNonNonSingleInt16Num,
     struct TestNonNonSingleInt16Num,
     MEM(struct TestNonNonSingleInt16Num, Num, int16_t, num, NULL));

struct TestNonNonSingleInt16Bool {
    int16_t b;
};
INIT(TestNonNonSingleInt16Bool,
     struct TestNonNonSingleInt16Bool,
     MEM(struct TestNonNonSingleInt16Bool, Bool, int16_t, b, NULL));

struct TestNonNonMultInt16Str {
    int16_t str1;
    int16_t str2;
    int16_t str3;
};
INIT(TestNonNonMultInt16Str,
     struct TestNonNonMultInt16Str,
     MEM(struct TestNonNonMultInt16Str, Str, int16_t, str1, NULL),
     MEM(struct TestNonNonMultInt16Str, Str, int16_t, str2, NULL),
     MEM(struct TestNonNonMultInt16Str, Str, int16_t, str3, NULL));

struct TestNonNonMultInt16Num {
    int16_t num1;
    int16_t num2;
    int16_t num3;
    int16_t num4;
    int16_t num5;
};
INIT(TestNonNonMultInt16Num,
     struct TestNonNonMultInt16Num,
     MEM(struct TestNonNonMultInt16Num, Num, int16_t, num1, NULL),
     MEM(struct TestNonNonMultInt16Num, Num, int16_t, num2, NULL),
     MEM(struct TestNonNonMultInt16Num, Num, int16_t, num3, NULL),
     MEM(struct TestNonNonMultInt16Num, Num, int16_t, num4, NULL),
     MEM(struct TestNonNonMultInt16Num, Num, int16_t, num5, NULL));

struct TestNonNonMultInt16Bool {
    int16_t bool1;
    int16_t bool2;
    int16_t bool3;
    int16_t bool4;
    int16_t bool5;
};
INIT(TestNonNonMultInt16Bool,
     struct TestNonNonMultInt16Bool,
     MEM(struct TestNonNonMultInt16Bool, Bool, int16_t, bool1, NULL),
     MEM(struct TestNonNonMultInt16Bool, Bool, int16_t, bool2, NULL),
     MEM(struct TestNonNonMultInt16Bool, Bool, int16_t, bool3, NULL),
     MEM(struct TestNonNonMultInt16Bool, Bool, int16_t, bool4, NULL),
     MEM(struct TestNonNonMultInt16Bool, Bool, int16_t, bool5, NULL));

// mult to json
char* test_change_non_non_single_int16_str_to_json(char* exp, char* real);
char* test_change_non_non_single_int16_num_to_json(char* exp, char* real);
char* test_change_non_non_single_int16_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_int16_str_to_json(char* exp, char* real);
char* test_change_non_non_mult_int16_num_to_json(char* exp, char* real);
char* test_change_non_non_mult_int16_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_int16_num(char* json);
int test_change_mult_str_json_to_non_non_single_int16_num(char* json);
int test_change_single_num_json_to_non_non_single_int16_num(char* json);
int test_change_mult_num_json_to_non_non_single_int16_num(char* json);
int test_change_single_bool_json_to_non_non_single_int16_num(char* json);
int test_change_mult_bool_json_to_non_non_single_int16_num(char* json);
int test_change_single_null_json_to_non_non_single_int16_num(char* json);
int test_change_mult_null_json_to_non_non_single_int16_num(char* json);

int test_change_single_str_json_to_non_non_single_int16_bool(char* json);
int test_change_mult_str_json_to_non_non_single_int16_bool(char* json);
int test_change_single_num_json_to_non_non_single_int16_bool(char* json);
int test_change_mult_num_json_to_non_non_single_int16_bool(char* json);
int test_change_single_bool_json_to_non_non_single_int16_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_int16_bool(char* json);
int test_change_single_null_json_to_non_non_single_int16_bool(char* json);
int test_change_mult_null_json_to_non_non_single_int16_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_int16_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_int16_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_int16_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_int16_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_int16_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_int16_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_int16_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_int16_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_int16_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_int16_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_int16_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_int16_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_int16_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_int16_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_int16_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_int16_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_int16_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_int16_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_int16_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_int16_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_int16_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_int16_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_int16_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_int16_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_int16_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_int16_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_int16_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_int16_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_int16_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_int16_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_int16_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_int16_bool(char* json);

#endif
