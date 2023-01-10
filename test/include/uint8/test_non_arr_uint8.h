/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-10 20:46:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint8/test_non_arr_uint8.h
 */

#ifndef __TEST_NON_ARR_UINT8_H_
#define __TEST_NON_ARR_UINT8_H_

#include <stdint.h>
#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleUint8Str {
    uint8_t str[100];
};
INIT(TestNonArrSingleUint8Str,
     struct TestNonArrSingleUint8Str,
     MEM(struct TestNonArrSingleUint8Str, Str, uint8_t, str, NULL));

struct TestNonArrSingleUint8Num {
    uint8_t num[5];
};
INIT(TestNonArrSingleUint8Num,
     struct TestNonArrSingleUint8Num,
     MEM(struct TestNonArrSingleUint8Num, Num, uint8_t, num, NULL));

struct TestNonArrSingleUint8Bool {
    uint8_t b[5];
};
INIT(TestNonArrSingleUint8Bool,
     struct TestNonArrSingleUint8Bool,
     MEM(struct TestNonArrSingleUint8Bool, Bool, uint8_t, b, NULL));

struct TestNonArrMultUint8Str {
    uint8_t str1[100];
    uint8_t str2[100];
    uint8_t str3[100];
};
INIT(TestNonArrMultUint8Str,
     struct TestNonArrMultUint8Str,
     MEM(struct TestNonArrMultUint8Str, Str, uint8_t, str1, NULL),
     MEM(struct TestNonArrMultUint8Str, Str, uint8_t, str2, NULL),
     MEM(struct TestNonArrMultUint8Str, Str, uint8_t, str3, NULL));

struct TestNonArrMultUint8Num {
    uint8_t num1[5];
    uint8_t num2[5];
    uint8_t num3[5];
    uint8_t num4[5];
    uint8_t num5[5];
};
INIT(TestNonArrMultUint8Num,
     struct TestNonArrMultUint8Num,
     MEM(struct TestNonArrMultUint8Num, Num, uint8_t, num1, NULL),
     MEM(struct TestNonArrMultUint8Num, Num, uint8_t, num2, NULL),
     MEM(struct TestNonArrMultUint8Num, Num, uint8_t, num3, NULL),
     MEM(struct TestNonArrMultUint8Num, Num, uint8_t, num4, NULL),
     MEM(struct TestNonArrMultUint8Num, Num, uint8_t, num5, NULL));

struct TestNonArrMultUint8Bool {
    uint8_t bool1[5];
    uint8_t bool2[5];
    uint8_t bool3[5];
    uint8_t bool4[5];
    uint8_t bool5[5];
};
INIT(TestNonArrMultUint8Bool,
     struct TestNonArrMultUint8Bool,
     MEM(struct TestNonArrMultUint8Bool, Bool, uint8_t, bool1, NULL),
     MEM(struct TestNonArrMultUint8Bool, Bool, uint8_t, bool2, NULL),
     MEM(struct TestNonArrMultUint8Bool, Bool, uint8_t, bool3, NULL),
     MEM(struct TestNonArrMultUint8Bool, Bool, uint8_t, bool4, NULL),
     MEM(struct TestNonArrMultUint8Bool, Bool, uint8_t, bool5, NULL));

// mult to json
char* test_change_non_arr_single_uint8_str_to_json(char* exp, char* real);
char* test_change_non_arr_single_uint8_num_to_json(char* exp, char* real);
char* test_change_non_arr_single_uint8_bool_to_json(char* exp, char* real);
char* test_change_non_arr_mult_uint8_str_to_json(char* exp, char* real);
char* test_change_non_arr_mult_uint8_num_to_json(char* exp, char* real);
char* test_change_non_arr_mult_uint8_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_uint8_str(char* json);
int test_change_mult_str_json_to_non_arr_single_uint8_str(char* json);
int test_change_single_num_json_to_non_arr_single_uint8_str(char* json);
int test_change_mult_num_json_to_non_arr_single_uint8_str(char* json);
int test_change_single_bool_json_to_non_arr_single_uint8_str(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint8_str(char* json);
int test_change_single_null_json_to_non_arr_single_uint8_str(char* json);
int test_change_mult_null_json_to_non_arr_single_uint8_str(char* json);

int test_change_single_str_json_to_non_arr_single_uint8_num(char* json);
int test_change_mult_str_json_to_non_arr_single_uint8_num(char* json);
int test_change_single_num_json_to_non_arr_single_uint8_num(char* json);
int test_change_mult_num_json_to_non_arr_single_uint8_num(char* json);
int test_change_single_bool_json_to_non_arr_single_uint8_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint8_num(char* json);
int test_change_single_null_json_to_non_arr_single_uint8_num(char* json);
int test_change_mult_null_json_to_non_arr_single_uint8_num(char* json);

int test_change_single_str_json_to_non_arr_single_uint8_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_uint8_bool(char* json);
int test_change_single_num_json_to_non_arr_single_uint8_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_uint8_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_uint8_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_uint8_bool(char* json);
int test_change_single_null_json_to_non_arr_single_uint8_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_uint8_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint8_str(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint8_str(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint8_str(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint8_str(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint8_str(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint8_str(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint8_str(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint8_str(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint8_str(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint8_str(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint8_str(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint8_str(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint8_str(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint8_str(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint8_str(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint8_str(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint8_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint8_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint8_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint8_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint8_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint8_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint8_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint8_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint8_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint8_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint8_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint8_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint8_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint8_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint8_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint8_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_uint8_bool(char* json);

#endif
