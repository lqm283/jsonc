/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 08:26:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int32/test_non_non_int32.h
 */
#ifndef __TEST_NON_NON_INT32_H_
#define __TEST_NON_NON_INT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleInt32Str {
    int32_t str;
};
INIT(TestNonNonSingleInt32Str,
     struct TestNonNonSingleInt32Str,
     MEM(struct TestNonNonSingleInt32Str, Str, int32_t, str, NULL));

struct TestNonNonSingleInt32Num {
    int32_t num;
};
INIT(TestNonNonSingleInt32Num,
     struct TestNonNonSingleInt32Num,
     MEM(struct TestNonNonSingleInt32Num, Num, int32_t, num, NULL));

struct TestNonNonSingleInt32Bool {
    int32_t b;
};
INIT(TestNonNonSingleInt32Bool,
     struct TestNonNonSingleInt32Bool,
     MEM(struct TestNonNonSingleInt32Bool, Bool, int32_t, b, NULL));

struct TestNonNonMultInt32Str {
    int32_t str1;
    int32_t str2;
    int32_t str3;
};
INIT(TestNonNonMultInt32Str,
     struct TestNonNonMultInt32Str,
     MEM(struct TestNonNonMultInt32Str, Str, int32_t, str1, NULL),
     MEM(struct TestNonNonMultInt32Str, Str, int32_t, str2, NULL),
     MEM(struct TestNonNonMultInt32Str, Str, int32_t, str3, NULL));

struct TestNonNonMultInt32Num {
    int32_t num1;
    int32_t num2;
    int32_t num3;
    int32_t num4;
    int32_t num5;
};
INIT(TestNonNonMultInt32Num,
     struct TestNonNonMultInt32Num,
     MEM(struct TestNonNonMultInt32Num, Num, int32_t, num1, NULL),
     MEM(struct TestNonNonMultInt32Num, Num, int32_t, num2, NULL),
     MEM(struct TestNonNonMultInt32Num, Num, int32_t, num3, NULL),
     MEM(struct TestNonNonMultInt32Num, Num, int32_t, num4, NULL),
     MEM(struct TestNonNonMultInt32Num, Num, int32_t, num5, NULL));

struct TestNonNonMultInt32Bool {
    int32_t bool1;
    int32_t bool2;
    int32_t bool3;
    int32_t bool4;
    int32_t bool5;
};
INIT(TestNonNonMultInt32Bool,
     struct TestNonNonMultInt32Bool,
     MEM(struct TestNonNonMultInt32Bool, Bool, int32_t, bool1, NULL),
     MEM(struct TestNonNonMultInt32Bool, Bool, int32_t, bool2, NULL),
     MEM(struct TestNonNonMultInt32Bool, Bool, int32_t, bool3, NULL),
     MEM(struct TestNonNonMultInt32Bool, Bool, int32_t, bool4, NULL),
     MEM(struct TestNonNonMultInt32Bool, Bool, int32_t, bool5, NULL));

// mult to json
char* test_change_non_non_single_int32_str_to_json(char* exp, char* real);
char* test_change_non_non_single_int32_num_to_json(char* exp, char* real);
char* test_change_non_non_single_int32_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_int32_str_to_json(char* exp, char* real);
char* test_change_non_non_mult_int32_num_to_json(char* exp, char* real);
char* test_change_non_non_mult_int32_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_int32_num(char* json);
int test_change_mult_str_json_to_non_non_single_int32_num(char* json);
int test_change_single_num_json_to_non_non_single_int32_num(char* json);
int test_change_mult_num_json_to_non_non_single_int32_num(char* json);
int test_change_single_bool_json_to_non_non_single_int32_num(char* json);
int test_change_mult_bool_json_to_non_non_single_int32_num(char* json);
int test_change_single_null_json_to_non_non_single_int32_num(char* json);
int test_change_mult_null_json_to_non_non_single_int32_num(char* json);

int test_change_single_str_json_to_non_non_single_int32_bool(char* json);
int test_change_mult_str_json_to_non_non_single_int32_bool(char* json);
int test_change_single_num_json_to_non_non_single_int32_bool(char* json);
int test_change_mult_num_json_to_non_non_single_int32_bool(char* json);
int test_change_single_bool_json_to_non_non_single_int32_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_int32_bool(char* json);
int test_change_single_null_json_to_non_non_single_int32_bool(char* json);
int test_change_mult_null_json_to_non_non_single_int32_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_int32_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_int32_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_int32_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_int32_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_int32_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_int32_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_int32_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_int32_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_int32_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_int32_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_int32_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_int32_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_int32_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_int32_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_int32_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_int32_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_int32_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_int32_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_int32_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_int32_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_int32_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_int32_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_int32_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_int32_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_int32_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_int32_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_int32_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_int32_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_int32_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_int32_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_int32_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_int32_bool(char* json);

#endif
