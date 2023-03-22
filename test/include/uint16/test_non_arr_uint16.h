/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-10 20:46:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint16/test_non_arr_uint16.h
 */

#ifndef __TEST_NON_ARR_UINT16_H_
#define __TEST_NON_ARR_UINT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleUint16Str {
    uint16_t str[100];
};
INIT(TestNonArrSingleUint16Str,
     struct TestNonArrSingleUint16Str,
     MEM(struct TestNonArrSingleUint16Str, Str, uint16_t, str, NULL));

struct TestNonArrSingleUint16Num {
    uint16_t num[5];
};
INIT(TestNonArrSingleUint16Num,
     struct TestNonArrSingleUint16Num,
     MEM(struct TestNonArrSingleUint16Num, Num, uint16_t, num, NULL));

struct TestNonArrSingleUint16Bool {
    uint16_t b[5];
};
INIT(TestNonArrSingleUint16Bool,
     struct TestNonArrSingleUint16Bool,
     MEM(struct TestNonArrSingleUint16Bool, Bool, uint16_t, b, NULL));

struct TestNonArrMultUint16Str {
    uint16_t str1[100];
    uint16_t str2[100];
    uint16_t str3[100];
};
INIT(TestNonArrMultUint16Str,
     struct TestNonArrMultUint16Str,
     MEM(struct TestNonArrMultUint16Str, Str, uint16_t, str1, NULL),
     MEM(struct TestNonArrMultUint16Str, Str, uint16_t, str2, NULL),
     MEM(struct TestNonArrMultUint16Str, Str, uint16_t, str3, NULL));

struct TestNonArrMultUint16Num {
    uint16_t num1[5];
    uint16_t num2[5];
    uint16_t num3[5];
    uint16_t num4[5];
    uint16_t num5[5];
};
INIT(TestNonArrMultUint16Num,
     struct TestNonArrMultUint16Num,
     MEM(struct TestNonArrMultUint16Num, Num, uint16_t, num1, NULL),
     MEM(struct TestNonArrMultUint16Num, Num, uint16_t, num2, NULL),
     MEM(struct TestNonArrMultUint16Num, Num, uint16_t, num3, NULL),
     MEM(struct TestNonArrMultUint16Num, Num, uint16_t, num4, NULL),
     MEM(struct TestNonArrMultUint16Num, Num, uint16_t, num5, NULL));

struct TestNonArrMultUint16Bool {
    uint16_t bool1[5];
    uint16_t bool2[5];
    uint16_t bool3[5];
    uint16_t bool4[5];
    uint16_t bool5[5];
};
INIT(TestNonArrMultUint16Bool,
     struct TestNonArrMultUint16Bool,
     MEM(struct TestNonArrMultUint16Bool, Bool, uint16_t, bool1, NULL),
     MEM(struct TestNonArrMultUint16Bool, Bool, uint16_t, bool2, NULL),
     MEM(struct TestNonArrMultUint16Bool, Bool, uint16_t, bool3, NULL),
     MEM(struct TestNonArrMultUint16Bool, Bool, uint16_t, bool4, NULL),
     MEM(struct TestNonArrMultUint16Bool, Bool, uint16_t, bool5, NULL));

// mult to json
int test_change_non_arr_single_uint16_num_to_json(char* exp, char* real);
int test_change_non_arr_single_uint16_bool_to_json(char* exp, char* real);
int test_change_non_arr_mult_uint16_num_to_json(char* exp, char* real);
int test_change_non_arr_mult_uint16_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_uint16_num(char* json);
int test_change_mult_str_json_to_non_arr_single_uint16_num(char* json);
int test_change_single_num_json_to_non_arr_single_uint16_num(char* json);
int test_change_mult_num_json_to_non_arr_single_uint16_num(char* json);
int test_change_single_bool_json_to_non_arr_single_uint16_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint16_num(char* json);
int test_change_single_null_json_to_non_arr_single_uint16_num(char* json);
int test_change_mult_null_json_to_non_arr_single_uint16_num(char* json);

int test_change_single_str_json_to_non_arr_single_uint16_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_uint16_bool(char* json);
int test_change_single_num_json_to_non_arr_single_uint16_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_uint16_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_uint16_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint16_bool(char* json);
int test_change_single_null_json_to_non_arr_single_uint16_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_uint16_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint16_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint16_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint16_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint16_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint16_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint16_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint16_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint16_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint16_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint16_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint16_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint16_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint16_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint16_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint16_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint16_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint16_bool(char* json);

#endif
