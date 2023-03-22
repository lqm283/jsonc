/*Int64
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-10 20:46:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int64/test_non_arr_int64.h
 */

#ifndef __TEST_NON_ARR_INT64_H_
#define __TEST_NON_ARR_INT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleInt64Str {
    int64_t str[100];
};
INIT(TestNonArrSingleInt64Str,
     struct TestNonArrSingleInt64Str,
     MEM(struct TestNonArrSingleInt64Str, Str, int64_t, str, NULL));

struct TestNonArrSingleInt64Num {
    int64_t num[5];
};
INIT(TestNonArrSingleInt64Num,
     struct TestNonArrSingleInt64Num,
     MEM(struct TestNonArrSingleInt64Num, Num, int64_t, num, NULL));

struct TestNonArrSingleInt64Bool {
    int64_t b[5];
};
INIT(TestNonArrSingleInt64Bool,
     struct TestNonArrSingleInt64Bool,
     MEM(struct TestNonArrSingleInt64Bool, Bool, int64_t, b, NULL));

struct TestNonArrMultInt64Str {
    int64_t str1[100];
    int64_t str2[100];
    int64_t str3[100];
};
INIT(TestNonArrMultInt64Str,
     struct TestNonArrMultInt64Str,
     MEM(struct TestNonArrMultInt64Str, Str, int64_t, str1, NULL),
     MEM(struct TestNonArrMultInt64Str, Str, int64_t, str2, NULL),
     MEM(struct TestNonArrMultInt64Str, Str, int64_t, str3, NULL));

struct TestNonArrMultInt64Num {
    int64_t num1[5];
    int64_t num2[5];
    int64_t num3[5];
    int64_t num4[5];
    int64_t num5[5];
};
INIT(TestNonArrMultInt64Num,
     struct TestNonArrMultInt64Num,
     MEM(struct TestNonArrMultInt64Num, Num, int64_t, num1, NULL),
     MEM(struct TestNonArrMultInt64Num, Num, int64_t, num2, NULL),
     MEM(struct TestNonArrMultInt64Num, Num, int64_t, num3, NULL),
     MEM(struct TestNonArrMultInt64Num, Num, int64_t, num4, NULL),
     MEM(struct TestNonArrMultInt64Num, Num, int64_t, num5, NULL));

struct TestNonArrMultInt64Bool {
    int64_t bool1[5];
    int64_t bool2[5];
    int64_t bool3[5];
    int64_t bool4[5];
    int64_t bool5[5];
};
INIT(TestNonArrMultInt64Bool,
     struct TestNonArrMultInt64Bool,
     MEM(struct TestNonArrMultInt64Bool, Bool, int64_t, bool1, NULL),
     MEM(struct TestNonArrMultInt64Bool, Bool, int64_t, bool2, NULL),
     MEM(struct TestNonArrMultInt64Bool, Bool, int64_t, bool3, NULL),
     MEM(struct TestNonArrMultInt64Bool, Bool, int64_t, bool4, NULL),
     MEM(struct TestNonArrMultInt64Bool, Bool, int64_t, bool5, NULL));

// mult to json
int test_change_non_arr_single_int64_num_to_json(char* exp, char* real);
int test_change_non_arr_single_int64_bool_to_json(char* exp, char* real);
int test_change_non_arr_mult_int64_num_to_json(char* exp, char* real);
int test_change_non_arr_mult_int64_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_int64_num(char* json);
int test_change_mult_str_json_to_non_arr_single_int64_num(char* json);
int test_change_single_num_json_to_non_arr_single_int64_num(char* json);
int test_change_mult_num_json_to_non_arr_single_int64_num(char* json);
int test_change_single_bool_json_to_non_arr_single_int64_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_int64_num(char* json);
int test_change_single_null_json_to_non_arr_single_int64_num(char* json);
int test_change_mult_null_json_to_non_arr_single_int64_num(char* json);

int test_change_single_str_json_to_non_arr_single_int64_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_int64_bool(char* json);
int test_change_single_num_json_to_non_arr_single_int64_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_int64_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_int64_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_int64_bool(char* json);
int test_change_single_null_json_to_non_arr_single_int64_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_int64_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_int64_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_int64_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_int64_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_int64_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_int64_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_int64_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_int64_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_int64_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_int64_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_int64_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_int64_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_int64_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_int64_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_int64_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_int64_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_int64_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_int64_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_int64_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_int64_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_int64_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_int64_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_int64_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_int64_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_int64_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_int64_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_int64_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_int64_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_int64_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_int64_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_int64_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_int64_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_int64_bool(char* json);

#endif
