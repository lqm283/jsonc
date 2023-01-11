/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 08:26:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint16/test_non_non_uint16.h
 */
#ifndef __TEST_NON_NON_UINT16_H_
#define __TEST_NON_NON_UINT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleUint16Str {
    uint16_t str;
};
INIT(TestNonNonSingleUint16Str,
     struct TestNonNonSingleUint16Str,
     MEM(struct TestNonNonSingleUint16Str, Str, uint16_t, str, NULL));

struct TestNonNonSingleUint16Num {
    uint16_t num;
};
INIT(TestNonNonSingleUint16Num,
     struct TestNonNonSingleUint16Num,
     MEM(struct TestNonNonSingleUint16Num, Num, uint16_t, num, NULL));

struct TestNonNonSingleUint16Bool {
    uint16_t b;
};
INIT(TestNonNonSingleUint16Bool,
     struct TestNonNonSingleUint16Bool,
     MEM(struct TestNonNonSingleUint16Bool, Bool, uint16_t, b, NULL));

struct TestNonNonMultUint16Str {
    uint16_t str1;
    uint16_t str2;
    uint16_t str3;
};
INIT(TestNonNonMultUint16Str,
     struct TestNonNonMultUint16Str,
     MEM(struct TestNonNonMultUint16Str, Str, uint16_t, str1, NULL),
     MEM(struct TestNonNonMultUint16Str, Str, uint16_t, str2, NULL),
     MEM(struct TestNonNonMultUint16Str, Str, uint16_t, str3, NULL));

struct TestNonNonMultUint16Num {
    uint16_t num1;
    uint16_t num2;
    uint16_t num3;
    uint16_t num4;
    uint16_t num5;
};
INIT(TestNonNonMultUint16Num,
     struct TestNonNonMultUint16Num,
     MEM(struct TestNonNonMultUint16Num, Num, uint16_t, num1, NULL),
     MEM(struct TestNonNonMultUint16Num, Num, uint16_t, num2, NULL),
     MEM(struct TestNonNonMultUint16Num, Num, uint16_t, num3, NULL),
     MEM(struct TestNonNonMultUint16Num, Num, uint16_t, num4, NULL),
     MEM(struct TestNonNonMultUint16Num, Num, uint16_t, num5, NULL));

struct TestNonNonMultUint16Bool {
    uint16_t bool1;
    uint16_t bool2;
    uint16_t bool3;
    uint16_t bool4;
    uint16_t bool5;
};
INIT(TestNonNonMultUint16Bool,
     struct TestNonNonMultUint16Bool,
     MEM(struct TestNonNonMultUint16Bool, Bool, uint16_t, bool1, NULL),
     MEM(struct TestNonNonMultUint16Bool, Bool, uint16_t, bool2, NULL),
     MEM(struct TestNonNonMultUint16Bool, Bool, uint16_t, bool3, NULL),
     MEM(struct TestNonNonMultUint16Bool, Bool, uint16_t, bool4, NULL),
     MEM(struct TestNonNonMultUint16Bool, Bool, uint16_t, bool5, NULL));

// mult to json
char* test_change_non_non_single_uint16_str_to_json(char* exp, char* real);
char* test_change_non_non_single_uint16_num_to_json(char* exp, char* real);
char* test_change_non_non_single_uint16_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_uint16_str_to_json(char* exp, char* real);
char* test_change_non_non_mult_uint16_num_to_json(char* exp, char* real);
char* test_change_non_non_mult_uint16_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_uint16_num(char* json);
int test_change_mult_str_json_to_non_non_single_uint16_num(char* json);
int test_change_single_num_json_to_non_non_single_uint16_num(char* json);
int test_change_mult_num_json_to_non_non_single_uint16_num(char* json);
int test_change_single_bool_json_to_non_non_single_uint16_num(char* json);
int test_change_mult_bool_json_to_non_non_single_uint16_num(char* json);
int test_change_single_null_json_to_non_non_single_uint16_num(char* json);
int test_change_mult_null_json_to_non_non_single_uint16_num(char* json);

int test_change_single_str_json_to_non_non_single_uint16_bool(char* json);
int test_change_mult_str_json_to_non_non_single_uint16_bool(char* json);
int test_change_single_num_json_to_non_non_single_uint16_bool(char* json);
int test_change_mult_num_json_to_non_non_single_uint16_bool(char* json);
int test_change_single_bool_json_to_non_non_single_uint16_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_uint16_bool(char* json);
int test_change_single_null_json_to_non_non_single_uint16_bool(char* json);
int test_change_mult_null_json_to_non_non_single_uint16_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint16_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint16_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint16_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint16_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint16_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint16_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint16_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint16_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint16_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint16_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint16_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint16_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint16_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint16_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint16_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint16_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint16_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint16_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint16_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint16_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint16_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint16_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint16_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint16_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint16_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint16_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint16_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint16_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint16_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint16_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint16_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint16_bool(char* json);

#endif
