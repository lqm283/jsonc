/*Int16
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-10 20:46:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int16/test_non_arr_int16.h
 */

#ifndef __TEST_NON_ARR_INT16_H_
#define __TEST_NON_ARR_INT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleInt16Str {
    int16_t str[100];
};
INIT(TestNonArrSingleInt16Str,
     struct TestNonArrSingleInt16Str,
     MEM(struct TestNonArrSingleInt16Str, Str, int16_t, str, NULL));

struct TestNonArrSingleInt16Num {
    int16_t num[5];
};
INIT(TestNonArrSingleInt16Num,
     struct TestNonArrSingleInt16Num,
     MEM(struct TestNonArrSingleInt16Num, Num, int16_t, num, NULL));

struct TestNonArrSingleInt16Bool {
    int16_t b[5];
};
INIT(TestNonArrSingleInt16Bool,
     struct TestNonArrSingleInt16Bool,
     MEM(struct TestNonArrSingleInt16Bool, Bool, int16_t, b, NULL));

struct TestNonArrMultInt16Str {
    int16_t str1[100];
    int16_t str2[100];
    int16_t str3[100];
};
INIT(TestNonArrMultInt16Str,
     struct TestNonArrMultInt16Str,
     MEM(struct TestNonArrMultInt16Str, Str, int16_t, str1, NULL),
     MEM(struct TestNonArrMultInt16Str, Str, int16_t, str2, NULL),
     MEM(struct TestNonArrMultInt16Str, Str, int16_t, str3, NULL));

struct TestNonArrMultInt16Num {
    int16_t num1[5];
    int16_t num2[5];
    int16_t num3[5];
    int16_t num4[5];
    int16_t num5[5];
};
INIT(TestNonArrMultInt16Num,
     struct TestNonArrMultInt16Num,
     MEM(struct TestNonArrMultInt16Num, Num, int16_t, num1, NULL),
     MEM(struct TestNonArrMultInt16Num, Num, int16_t, num2, NULL),
     MEM(struct TestNonArrMultInt16Num, Num, int16_t, num3, NULL),
     MEM(struct TestNonArrMultInt16Num, Num, int16_t, num4, NULL),
     MEM(struct TestNonArrMultInt16Num, Num, int16_t, num5, NULL));

struct TestNonArrMultInt16Bool {
    int16_t bool1[5];
    int16_t bool2[5];
    int16_t bool3[5];
    int16_t bool4[5];
    int16_t bool5[5];
};
INIT(TestNonArrMultInt16Bool,
     struct TestNonArrMultInt16Bool,
     MEM(struct TestNonArrMultInt16Bool, Bool, int16_t, bool1, NULL),
     MEM(struct TestNonArrMultInt16Bool, Bool, int16_t, bool2, NULL),
     MEM(struct TestNonArrMultInt16Bool, Bool, int16_t, bool3, NULL),
     MEM(struct TestNonArrMultInt16Bool, Bool, int16_t, bool4, NULL),
     MEM(struct TestNonArrMultInt16Bool, Bool, int16_t, bool5, NULL));

// mult to json
char* test_change_non_arr_single_int16_num_to_json(char* exp, char* real);
char* test_change_non_arr_single_int16_bool_to_json(char* exp, char* real);
char* test_change_non_arr_mult_int16_num_to_json(char* exp, char* real);
char* test_change_non_arr_mult_int16_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_int16_num(char* json);
int test_change_mult_str_json_to_non_arr_single_int16_num(char* json);
int test_change_single_num_json_to_non_arr_single_int16_num(char* json);
int test_change_mult_num_json_to_non_arr_single_int16_num(char* json);
int test_change_single_bool_json_to_non_arr_single_int16_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_int16_num(char* json);
int test_change_single_null_json_to_non_arr_single_int16_num(char* json);
int test_change_mult_null_json_to_non_arr_single_int16_num(char* json);

int test_change_single_str_json_to_non_arr_single_int16_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_int16_bool(char* json);
int test_change_single_num_json_to_non_arr_single_int16_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_int16_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_int16_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_int16_bool(char* json);
int test_change_single_null_json_to_non_arr_single_int16_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_int16_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_int16_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_int16_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_int16_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_int16_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_int16_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_int16_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_int16_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_int16_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_int16_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_int16_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_int16_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_int16_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_int16_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_int16_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_int16_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_int16_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_int16_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_int16_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_int16_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_int16_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_int16_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_int16_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_int16_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_int16_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_int16_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_int16_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_int16_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_int16_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_int16_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_int16_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_int16_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_int16_bool(char* json);

#endif
