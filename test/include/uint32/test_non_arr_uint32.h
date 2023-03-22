/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-11 10:23:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint32/test_non_arr_uint32.h
 */

#ifndef __TEST_NON_ARR_UINT32_H_
#define __TEST_NON_ARR_UINT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleUint32Str {
    uint32_t str[100];
};
INIT(TestNonArrSingleUint32Str,
     struct TestNonArrSingleUint32Str,
     MEM(struct TestNonArrSingleUint32Str, Str, uint32_t, str, NULL));

struct TestNonArrSingleUint32Num {
    uint32_t num[5];
};
INIT(TestNonArrSingleUint32Num,
     struct TestNonArrSingleUint32Num,
     MEM(struct TestNonArrSingleUint32Num, Num, uint32_t, num, NULL));

struct TestNonArrSingleUint32Bool {
    uint32_t b[5];
};
INIT(TestNonArrSingleUint32Bool,
     struct TestNonArrSingleUint32Bool,
     MEM(struct TestNonArrSingleUint32Bool, Bool, uint32_t, b, NULL));

struct TestNonArrMultUint32Str {
    uint32_t str1[100];
    uint32_t str2[100];
    uint32_t str3[100];
};
INIT(TestNonArrMultUint32Str,
     struct TestNonArrMultUint32Str,
     MEM(struct TestNonArrMultUint32Str, Str, uint32_t, str1, NULL),
     MEM(struct TestNonArrMultUint32Str, Str, uint32_t, str2, NULL),
     MEM(struct TestNonArrMultUint32Str, Str, uint32_t, str3, NULL));

struct TestNonArrMultUint32Num {
    uint32_t num1[5];
    uint32_t num2[5];
    uint32_t num3[5];
    uint32_t num4[5];
    uint32_t num5[5];
};
INIT(TestNonArrMultUint32Num,
     struct TestNonArrMultUint32Num,
     MEM(struct TestNonArrMultUint32Num, Num, uint32_t, num1, NULL),
     MEM(struct TestNonArrMultUint32Num, Num, uint32_t, num2, NULL),
     MEM(struct TestNonArrMultUint32Num, Num, uint32_t, num3, NULL),
     MEM(struct TestNonArrMultUint32Num, Num, uint32_t, num4, NULL),
     MEM(struct TestNonArrMultUint32Num, Num, uint32_t, num5, NULL));

struct TestNonArrMultUint32Bool {
    uint32_t bool1[5];
    uint32_t bool2[5];
    uint32_t bool3[5];
    uint32_t bool4[5];
    uint32_t bool5[5];
};
INIT(TestNonArrMultUint32Bool,
     struct TestNonArrMultUint32Bool,
     MEM(struct TestNonArrMultUint32Bool, Bool, uint32_t, bool1, NULL),
     MEM(struct TestNonArrMultUint32Bool, Bool, uint32_t, bool2, NULL),
     MEM(struct TestNonArrMultUint32Bool, Bool, uint32_t, bool3, NULL),
     MEM(struct TestNonArrMultUint32Bool, Bool, uint32_t, bool4, NULL),
     MEM(struct TestNonArrMultUint32Bool, Bool, uint32_t, bool5, NULL));

// mult to json
int test_change_non_arr_single_uint32_num_to_json(char* exp, char* real);
int test_change_non_arr_single_uint32_bool_to_json(char* exp, char* real);
int test_change_non_arr_mult_uint32_num_to_json(char* exp, char* real);
int test_change_non_arr_mult_uint32_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_uint32_num(char* json);
int test_change_mult_str_json_to_non_arr_single_uint32_num(char* json);
int test_change_single_num_json_to_non_arr_single_uint32_num(char* json);
int test_change_mult_num_json_to_non_arr_single_uint32_num(char* json);
int test_change_single_bool_json_to_non_arr_single_uint32_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint32_num(char* json);
int test_change_single_null_json_to_non_arr_single_uint32_num(char* json);
int test_change_mult_null_json_to_non_arr_single_uint32_num(char* json);

int test_change_single_str_json_to_non_arr_single_uint32_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_uint32_bool(char* json);
int test_change_single_num_json_to_non_arr_single_uint32_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_uint32_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_uint32_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint32_bool(char* json);
int test_change_single_null_json_to_non_arr_single_uint32_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_uint32_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint32_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint32_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint32_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint32_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint32_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint32_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint32_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint32_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint32_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint32_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint32_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint32_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint32_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint32_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint32_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint32_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint32_bool(char* json);

#endif
