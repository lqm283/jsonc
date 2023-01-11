/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 08:26:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int64/test_non_non_int64.h
 */
#ifndef __TEST_NON_NON_INT64_H_
#define __TEST_NON_NON_INT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleInt64Str {
    int64_t str;
};
INIT(TestNonNonSingleInt64Str,
     struct TestNonNonSingleInt64Str,
     MEM(struct TestNonNonSingleInt64Str, Str, int64_t, str, NULL));

struct TestNonNonSingleInt64Num {
    int64_t num;
};
INIT(TestNonNonSingleInt64Num,
     struct TestNonNonSingleInt64Num,
     MEM(struct TestNonNonSingleInt64Num, Num, int64_t, num, NULL));

struct TestNonNonSingleInt64Bool {
    int64_t b;
};
INIT(TestNonNonSingleInt64Bool,
     struct TestNonNonSingleInt64Bool,
     MEM(struct TestNonNonSingleInt64Bool, Bool, int64_t, b, NULL));

struct TestNonNonMultInt64Str {
    int64_t str1;
    int64_t str2;
    int64_t str3;
};
INIT(TestNonNonMultInt64Str,
     struct TestNonNonMultInt64Str,
     MEM(struct TestNonNonMultInt64Str, Str, int64_t, str1, NULL),
     MEM(struct TestNonNonMultInt64Str, Str, int64_t, str2, NULL),
     MEM(struct TestNonNonMultInt64Str, Str, int64_t, str3, NULL));

struct TestNonNonMultInt64Num {
    int64_t num1;
    int64_t num2;
    int64_t num3;
    int64_t num4;
    int64_t num5;
};
INIT(TestNonNonMultInt64Num,
     struct TestNonNonMultInt64Num,
     MEM(struct TestNonNonMultInt64Num, Num, int64_t, num1, NULL),
     MEM(struct TestNonNonMultInt64Num, Num, int64_t, num2, NULL),
     MEM(struct TestNonNonMultInt64Num, Num, int64_t, num3, NULL),
     MEM(struct TestNonNonMultInt64Num, Num, int64_t, num4, NULL),
     MEM(struct TestNonNonMultInt64Num, Num, int64_t, num5, NULL));

struct TestNonNonMultInt64Bool {
    int64_t bool1;
    int64_t bool2;
    int64_t bool3;
    int64_t bool4;
    int64_t bool5;
};
INIT(TestNonNonMultInt64Bool,
     struct TestNonNonMultInt64Bool,
     MEM(struct TestNonNonMultInt64Bool, Bool, int64_t, bool1, NULL),
     MEM(struct TestNonNonMultInt64Bool, Bool, int64_t, bool2, NULL),
     MEM(struct TestNonNonMultInt64Bool, Bool, int64_t, bool3, NULL),
     MEM(struct TestNonNonMultInt64Bool, Bool, int64_t, bool4, NULL),
     MEM(struct TestNonNonMultInt64Bool, Bool, int64_t, bool5, NULL));

// mult to json
char* test_change_non_non_single_int64_str_to_json(char* exp, char* real);
char* test_change_non_non_single_int64_num_to_json(char* exp, char* real);
char* test_change_non_non_single_int64_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_int64_str_to_json(char* exp, char* real);
char* test_change_non_non_mult_int64_num_to_json(char* exp, char* real);
char* test_change_non_non_mult_int64_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_int64_num(char* json);
int test_change_mult_str_json_to_non_non_single_int64_num(char* json);
int test_change_single_num_json_to_non_non_single_int64_num(char* json);
int test_change_mult_num_json_to_non_non_single_int64_num(char* json);
int test_change_single_bool_json_to_non_non_single_int64_num(char* json);
int test_change_mult_bool_json_to_non_non_single_int64_num(char* json);
int test_change_single_null_json_to_non_non_single_int64_num(char* json);
int test_change_mult_null_json_to_non_non_single_int64_num(char* json);

int test_change_single_str_json_to_non_non_single_int64_bool(char* json);
int test_change_mult_str_json_to_non_non_single_int64_bool(char* json);
int test_change_single_num_json_to_non_non_single_int64_bool(char* json);
int test_change_mult_num_json_to_non_non_single_int64_bool(char* json);
int test_change_single_bool_json_to_non_non_single_int64_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_int64_bool(char* json);
int test_change_single_null_json_to_non_non_single_int64_bool(char* json);
int test_change_mult_null_json_to_non_non_single_int64_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_int64_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_int64_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_int64_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_int64_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_int64_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_int64_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_int64_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_int64_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_int64_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_int64_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_int64_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_int64_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_int64_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_int64_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_int64_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_int64_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_int64_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_int64_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_int64_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_int64_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_int64_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_int64_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_int64_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_int64_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_int64_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_int64_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_int64_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_int64_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_int64_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_int64_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_int64_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_int64_bool(char* json);

#endif
