/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-03-22 14:10:47
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint64/test_non_arr_uint64.h
 */

#ifndef __TEST_NON_ARR_UINT64_H_
#define __TEST_NON_ARR_UINT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleUint64Str {
    uint64_t str[100];
};
INIT(TestNonArrSingleUint64Str,
     struct TestNonArrSingleUint64Str,
     MEM(struct TestNonArrSingleUint64Str, Str, uint64_t, str, NULL));

struct TestNonArrSingleUint64Num {
    uint64_t num[5];
};
INIT(TestNonArrSingleUint64Num,
     struct TestNonArrSingleUint64Num,
     MEM(struct TestNonArrSingleUint64Num, Num, uint64_t, num, NULL));

struct TestNonArrSingleUint64Bool {
    uint64_t b[5];
};
INIT(TestNonArrSingleUint64Bool,
     struct TestNonArrSingleUint64Bool,
     MEM(struct TestNonArrSingleUint64Bool, Bool, uint64_t, b, NULL));

struct TestNonArrMultUint64Str {
    uint64_t str1[100];
    uint64_t str2[100];
    uint64_t str3[100];
};
INIT(TestNonArrMultUint64Str,
     struct TestNonArrMultUint64Str,
     MEM(struct TestNonArrMultUint64Str, Str, uint64_t, str1, NULL),
     MEM(struct TestNonArrMultUint64Str, Str, uint64_t, str2, NULL),
     MEM(struct TestNonArrMultUint64Str, Str, uint64_t, str3, NULL));

struct TestNonArrMultUint64Num {
    uint64_t num1[5];
    uint64_t num2[5];
    uint64_t num3[5];
    uint64_t num4[5];
    uint64_t num5[5];
};
INIT(TestNonArrMultUint64Num,
     struct TestNonArrMultUint64Num,
     MEM(struct TestNonArrMultUint64Num, Num, uint64_t, num1, NULL),
     MEM(struct TestNonArrMultUint64Num, Num, uint64_t, num2, NULL),
     MEM(struct TestNonArrMultUint64Num, Num, uint64_t, num3, NULL),
     MEM(struct TestNonArrMultUint64Num, Num, uint64_t, num4, NULL),
     MEM(struct TestNonArrMultUint64Num, Num, uint64_t, num5, NULL));

struct TestNonArrMultUint64Bool {
    uint64_t bool1[5];
    uint64_t bool2[5];
    uint64_t bool3[5];
    uint64_t bool4[5];
    uint64_t bool5[5];
};
INIT(TestNonArrMultUint64Bool,
     struct TestNonArrMultUint64Bool,
     MEM(struct TestNonArrMultUint64Bool, Bool, uint64_t, bool1, NULL),
     MEM(struct TestNonArrMultUint64Bool, Bool, uint64_t, bool2, NULL),
     MEM(struct TestNonArrMultUint64Bool, Bool, uint64_t, bool3, NULL),
     MEM(struct TestNonArrMultUint64Bool, Bool, uint64_t, bool4, NULL),
     MEM(struct TestNonArrMultUint64Bool, Bool, uint64_t, bool5, NULL));

// mult to json
int test_change_non_arr_single_uint64_num_to_json(char* exp, char* real);
int test_change_non_arr_single_uint64_bool_to_json(char* exp, char* real);
int test_change_non_arr_mult_uint64_num_to_json(char* exp, char* real);
int test_change_non_arr_mult_uint64_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_uint64_num(char* json);
int test_change_mult_str_json_to_non_arr_single_uint64_num(char* json);
int test_change_single_num_json_to_non_arr_single_uint64_num(char* json);
int test_change_mult_num_json_to_non_arr_single_uint64_num(char* json);
int test_change_single_bool_json_to_non_arr_single_uint64_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint64_num(char* json);
int test_change_single_null_json_to_non_arr_single_uint64_num(char* json);
int test_change_mult_null_json_to_non_arr_single_uint64_num(char* json);

int test_change_single_str_json_to_non_arr_single_uint64_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_uint64_bool(char* json);
int test_change_single_num_json_to_non_arr_single_uint64_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_uint64_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_uint64_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint64_bool(char* json);
int test_change_single_null_json_to_non_arr_single_uint64_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_uint64_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint64_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint64_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint64_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint64_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint64_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint64_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint64_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint64_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint64_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint64_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint64_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint64_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint64_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint64_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint64_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint64_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint64_bool(char* json);

#endif
