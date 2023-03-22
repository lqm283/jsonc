/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 08:26:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint32/test_non_non_uint32.h
 */
#ifndef __TEST_NON_NON_UINT32_H_
#define __TEST_NON_NON_UINT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleUint32Str {
    uint32_t str;
};
INIT(TestNonNonSingleUint32Str,
     struct TestNonNonSingleUint32Str,
     MEM(struct TestNonNonSingleUint32Str, Str, uint32_t, str, NULL));

struct TestNonNonSingleUint32Num {
    uint32_t num;
};
INIT(TestNonNonSingleUint32Num,
     struct TestNonNonSingleUint32Num,
     MEM(struct TestNonNonSingleUint32Num, Num, uint32_t, num, NULL));

struct TestNonNonSingleUint32Bool {
    uint32_t b;
};
INIT(TestNonNonSingleUint32Bool,
     struct TestNonNonSingleUint32Bool,
     MEM(struct TestNonNonSingleUint32Bool, Bool, uint32_t, b, NULL));

struct TestNonNonMultUint32Str {
    uint32_t str1;
    uint32_t str2;
    uint32_t str3;
};
INIT(TestNonNonMultUint32Str,
     struct TestNonNonMultUint32Str,
     MEM(struct TestNonNonMultUint32Str, Str, uint32_t, str1, NULL),
     MEM(struct TestNonNonMultUint32Str, Str, uint32_t, str2, NULL),
     MEM(struct TestNonNonMultUint32Str, Str, uint32_t, str3, NULL));

struct TestNonNonMultUint32Num {
    uint32_t num1;
    uint32_t num2;
    uint32_t num3;
    uint32_t num4;
    uint32_t num5;
};
INIT(TestNonNonMultUint32Num,
     struct TestNonNonMultUint32Num,
     MEM(struct TestNonNonMultUint32Num, Num, uint32_t, num1, NULL),
     MEM(struct TestNonNonMultUint32Num, Num, uint32_t, num2, NULL),
     MEM(struct TestNonNonMultUint32Num, Num, uint32_t, num3, NULL),
     MEM(struct TestNonNonMultUint32Num, Num, uint32_t, num4, NULL),
     MEM(struct TestNonNonMultUint32Num, Num, uint32_t, num5, NULL));

struct TestNonNonMultUint32Bool {
    uint32_t bool1;
    uint32_t bool2;
    uint32_t bool3;
    uint32_t bool4;
    uint32_t bool5;
};
INIT(TestNonNonMultUint32Bool,
     struct TestNonNonMultUint32Bool,
     MEM(struct TestNonNonMultUint32Bool, Bool, uint32_t, bool1, NULL),
     MEM(struct TestNonNonMultUint32Bool, Bool, uint32_t, bool2, NULL),
     MEM(struct TestNonNonMultUint32Bool, Bool, uint32_t, bool3, NULL),
     MEM(struct TestNonNonMultUint32Bool, Bool, uint32_t, bool4, NULL),
     MEM(struct TestNonNonMultUint32Bool, Bool, uint32_t, bool5, NULL));

// mult to json
int test_change_non_non_single_uint32_str_to_json(char* exp, char* real);
int test_change_non_non_single_uint32_num_to_json(char* exp, char* real);
int test_change_non_non_single_uint32_bool_to_json(char* exp, char* real);
int test_change_non_non_mult_uint32_str_to_json(char* exp, char* real);
int test_change_non_non_mult_uint32_num_to_json(char* exp, char* real);
int test_change_non_non_mult_uint32_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_uint32_num(char* json);
int test_change_mult_str_json_to_non_non_single_uint32_num(char* json);
int test_change_single_num_json_to_non_non_single_uint32_num(char* json);
int test_change_mult_num_json_to_non_non_single_uint32_num(char* json);
int test_change_single_bool_json_to_non_non_single_uint32_num(char* json);
int test_change_mult_bool_json_to_non_non_single_uint32_num(char* json);
int test_change_single_null_json_to_non_non_single_uint32_num(char* json);
int test_change_mult_null_json_to_non_non_single_uint32_num(char* json);

int test_change_single_str_json_to_non_non_single_uint32_bool(char* json);
int test_change_mult_str_json_to_non_non_single_uint32_bool(char* json);
int test_change_single_num_json_to_non_non_single_uint32_bool(char* json);
int test_change_mult_num_json_to_non_non_single_uint32_bool(char* json);
int test_change_single_bool_json_to_non_non_single_uint32_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_uint32_bool(char* json);
int test_change_single_null_json_to_non_non_single_uint32_bool(char* json);
int test_change_mult_null_json_to_non_non_single_uint32_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint32_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint32_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint32_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint32_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint32_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint32_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint32_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint32_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint32_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint32_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint32_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint32_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint32_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint32_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint32_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint32_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_uint32_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_uint32_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_uint32_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_uint32_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_uint32_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_uint32_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_uint32_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_uint32_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_uint32_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_uint32_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_uint32_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_uint32_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_uint32_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_uint32_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_uint32_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_uint32_bool(char* json);

#endif
