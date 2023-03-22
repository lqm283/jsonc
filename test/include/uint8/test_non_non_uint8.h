/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-10 20:47:54
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint8/test_non_non_uint8.h
 */
#ifndef __TEST_NON_NON_UINT8_H_
#define __TEST_NON_NON_UINT8_H_

#include "../../../jsonc.h"
#include <stdint.h>

// char 单成员字符串
struct TestNonNonSingleUint8Str {
    uint8_t str;
};
INIT(TestNonNonSingleUint8Str,
     struct TestNonNonSingleUint8Str,
     MEM(struct TestNonNonSingleUint8Str, Str, uint8_t, str, NULL));

struct TestNonNonSingleUint8Num {
    uint8_t num;
};
INIT(TestNonNonSingleUint8Num,
     struct TestNonNonSingleUint8Num,
     MEM(struct TestNonNonSingleUint8Num, Num, uint8_t, num, NULL));

struct TestNonNonSingleUint8Bool {
    uint8_t b;
};
INIT(TestNonNonSingleUint8Bool,
     struct TestNonNonSingleUint8Bool,
     MEM(struct TestNonNonSingleUint8Bool, Bool, uint8_t, b, NULL));

struct TestNonNonMultUint8Str {
    uint8_t str1;
    uint8_t str2;
    uint8_t str3;
};
INIT(TestNonNonMultUint8Str,
     struct TestNonNonMultUint8Str,
     MEM(struct TestNonNonMultUint8Str, Str, uint8_t, str1, NULL),
     MEM(struct TestNonNonMultUint8Str, Str, uint8_t, str2, NULL),
     MEM(struct TestNonNonMultUint8Str, Str, uint8_t, str3, NULL));

struct TestNonNonMultUint8Num {
    uint8_t num1;
    uint8_t num2;
    uint8_t num3;
    uint8_t num4;
    uint8_t num5;
};
INIT(TestNonNonMultUint8Num,
     struct TestNonNonMultUint8Num,
     MEM(struct TestNonNonMultUint8Num, Num, uint8_t, num1, NULL),
     MEM(struct TestNonNonMultUint8Num, Num, uint8_t, num2, NULL),
     MEM(struct TestNonNonMultUint8Num, Num, uint8_t, num3, NULL),
     MEM(struct TestNonNonMultUint8Num, Num, uint8_t, num4, NULL),
     MEM(struct TestNonNonMultUint8Num, Num, uint8_t, num5, NULL));

struct TestNonNonMultUint8Bool {
    uint8_t bool1;
    uint8_t bool2;
    uint8_t bool3;
    uint8_t bool4;
    uint8_t bool5;
};
INIT(TestNonNonMultUint8Bool,
     struct TestNonNonMultUint8Bool,
     MEM(struct TestNonNonMultUint8Bool, Bool, uint8_t, bool1, NULL),
     MEM(struct TestNonNonMultUint8Bool, Bool, uint8_t, bool2, NULL),
     MEM(struct TestNonNonMultUint8Bool, Bool, uint8_t, bool3, NULL),
     MEM(struct TestNonNonMultUint8Bool, Bool, uint8_t, bool4, NULL),
     MEM(struct TestNonNonMultUint8Bool, Bool, uint8_t, bool5, NULL));

// mult to json
int test_change_non_non_single_uint8_str_to_json(char* exp, char* real);
int test_change_non_non_single_uint8_num_to_json(char* exp, char* real);
int test_change_non_non_single_uint8_bool_to_json(char* exp, char* real);
int test_change_non_non_mult_uint8_str_to_json(char* exp, char* real);
int test_change_non_non_mult_uint8_num_to_json(char* exp, char* real);
int test_change_non_non_mult_uint8_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_uint8_str(char* json);
int test_change_mult_str_json_to_non_non_single_uint8_str(char* json);
int test_change_single_num_json_to_non_non_single_uint8_str(char* json);
int test_change_mult_num_json_to_non_non_single_uint8_str(char* json);
int test_change_single_bool_json_to_non_non_single_uint8_str(char* json);
int test_change_mult_bool_json_to_non_non_single_uint8_str(char* json);
int test_change_single_null_json_to_non_non_single_uint8_str(char* json);
int test_change_mult_null_json_to_non_non_single_uint8_str(char* json);

int test_change_single_str_json_to_non_non_single_uint8_num(char* json);
int test_change_mult_str_json_to_non_non_single_uint8_num(char* json);
int test_change_single_num_json_to_non_non_single_uint8_num(char* json);
int test_change_mult_num_json_to_non_non_single_uint8_num(char* json);
int test_change_single_bool_json_to_non_non_single_uint8_num(char* json);
int test_change_mult_bool_json_to_non_non_single_uint8_num(char* json);
int test_change_single_null_json_to_non_non_single_uint8_num(char* json);
int test_change_mult_null_json_to_non_non_single_uint8_num(char* json);

int test_change_single_str_json_to_non_non_single_uint8_bool(char* json);
int test_change_mult_str_json_to_non_non_single_uint8_bool(char* json);
int test_change_single_num_json_to_non_non_single_uint8_bool(char* json);
int test_change_mult_num_json_to_non_non_single_uint8_bool(char* json);
int test_change_single_bool_json_to_non_non_single_uint8_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_uint8_bool(char* json);
int test_change_single_null_json_to_non_non_single_uint8_bool(char* json);
int test_change_mult_null_json_to_non_non_single_uint8_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint8_str(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint8_str(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint8_str(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint8_str(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint8_str(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint8_str(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint8_str(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint8_str(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint8_str(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint8_str(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint8_str(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint8_str(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint8_str(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint8_str(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint8_str(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint8_str(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint8_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint8_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint8_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint8_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint8_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint8_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint8_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint8_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint8_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint8_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint8_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint8_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint8_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint8_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint8_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint8_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint8_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint8_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint8_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint8_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint8_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint8_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint8_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint8_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint8_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint8_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint8_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint8_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint8_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint8_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint8_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint8_bool(char* json);

#endif
