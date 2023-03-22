/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 08:26:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint64/test_non_non_uint64.h
 */
#ifndef __TEST_NON_NON_UINT64_H_
#define __TEST_NON_NON_UINT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleUint64Str {
    uint64_t str;
};
INIT(TestNonNonSingleUint64Str,
     struct TestNonNonSingleUint64Str,
     MEM(struct TestNonNonSingleUint64Str, Str, uint64_t, str, NULL));

struct TestNonNonSingleUint64Num {
    uint64_t num;
};
INIT(TestNonNonSingleUint64Num,
     struct TestNonNonSingleUint64Num,
     MEM(struct TestNonNonSingleUint64Num, Num, uint64_t, num, NULL));

struct TestNonNonSingleUint64Bool {
    uint64_t b;
};
INIT(TestNonNonSingleUint64Bool,
     struct TestNonNonSingleUint64Bool,
     MEM(struct TestNonNonSingleUint64Bool, Bool, uint64_t, b, NULL));

struct TestNonNonMultUint64Str {
    uint64_t str1;
    uint64_t str2;
    uint64_t str3;
};
INIT(TestNonNonMultUint64Str,
     struct TestNonNonMultUint64Str,
     MEM(struct TestNonNonMultUint64Str, Str, uint64_t, str1, NULL),
     MEM(struct TestNonNonMultUint64Str, Str, uint64_t, str2, NULL),
     MEM(struct TestNonNonMultUint64Str, Str, uint64_t, str3, NULL));

struct TestNonNonMultUint64Num {
    uint64_t num1;
    uint64_t num2;
    uint64_t num3;
    uint64_t num4;
    uint64_t num5;
};
INIT(TestNonNonMultUint64Num,
     struct TestNonNonMultUint64Num,
     MEM(struct TestNonNonMultUint64Num, Num, uint64_t, num1, NULL),
     MEM(struct TestNonNonMultUint64Num, Num, uint64_t, num2, NULL),
     MEM(struct TestNonNonMultUint64Num, Num, uint64_t, num3, NULL),
     MEM(struct TestNonNonMultUint64Num, Num, uint64_t, num4, NULL),
     MEM(struct TestNonNonMultUint64Num, Num, uint64_t, num5, NULL));

struct TestNonNonMultUint64Bool {
    uint64_t bool1;
    uint64_t bool2;
    uint64_t bool3;
    uint64_t bool4;
    uint64_t bool5;
};
INIT(TestNonNonMultUint64Bool,
     struct TestNonNonMultUint64Bool,
     MEM(struct TestNonNonMultUint64Bool, Bool, uint64_t, bool1, NULL),
     MEM(struct TestNonNonMultUint64Bool, Bool, uint64_t, bool2, NULL),
     MEM(struct TestNonNonMultUint64Bool, Bool, uint64_t, bool3, NULL),
     MEM(struct TestNonNonMultUint64Bool, Bool, uint64_t, bool4, NULL),
     MEM(struct TestNonNonMultUint64Bool, Bool, uint64_t, bool5, NULL));

// mult to json
int test_change_non_non_single_uint64_str_to_json(char* exp, char* real);
int test_change_non_non_single_uint64_num_to_json(char* exp, char* real);
int test_change_non_non_single_uint64_bool_to_json(char* exp, char* real);
int test_change_non_non_mult_uint64_str_to_json(char* exp, char* real);
int test_change_non_non_mult_uint64_num_to_json(char* exp, char* real);
int test_change_non_non_mult_uint64_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_uint64_num(char* json);
int test_change_mult_str_json_to_non_non_single_uint64_num(char* json);
int test_change_single_num_json_to_non_non_single_uint64_num(char* json);
int test_change_mult_num_json_to_non_non_single_uint64_num(char* json);
int test_change_single_bool_json_to_non_non_single_uint64_num(char* json);
int test_change_mult_bool_json_to_non_non_single_uint64_num(char* json);
int test_change_single_null_json_to_non_non_single_uint64_num(char* json);
int test_change_mult_null_json_to_non_non_single_uint64_num(char* json);

int test_change_single_str_json_to_non_non_single_uint64_bool(char* json);
int test_change_mult_str_json_to_non_non_single_uint64_bool(char* json);
int test_change_single_num_json_to_non_non_single_uint64_bool(char* json);
int test_change_mult_num_json_to_non_non_single_uint64_bool(char* json);
int test_change_single_bool_json_to_non_non_single_uint64_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_uint64_bool(char* json);
int test_change_single_null_json_to_non_non_single_uint64_bool(char* json);
int test_change_mult_null_json_to_non_non_single_uint64_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint64_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint64_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint64_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint64_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint64_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint64_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint64_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint64_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint64_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint64_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint64_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint64_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint64_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint64_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint64_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint64_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint64_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint64_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint64_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint64_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint64_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint64_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint64_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint64_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint64_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint64_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint64_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint64_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint64_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint64_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint64_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint64_bool(char* json);

#endif
