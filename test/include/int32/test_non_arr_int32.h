/*Int32
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-10 20:46:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int32/test_non_arr_int32.h
 */

#ifndef __TEST_NON_ARR_INT32_H_
#define __TEST_NON_ARR_INT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonArrSingleInt32Str {
    int32_t str[100];
};
INIT(TestNonArrSingleInt32Str,
     struct TestNonArrSingleInt32Str,
     MEM(struct TestNonArrSingleInt32Str, Str, int32_t, str, NULL));

struct TestNonArrSingleInt32Num {
    int32_t num[5];
};
INIT(TestNonArrSingleInt32Num,
     struct TestNonArrSingleInt32Num,
     MEM(struct TestNonArrSingleInt32Num, Num, int32_t, num, NULL));

struct TestNonArrSingleInt32Bool {
    int32_t b[5];
};
INIT(TestNonArrSingleInt32Bool,
     struct TestNonArrSingleInt32Bool,
     MEM(struct TestNonArrSingleInt32Bool, Bool, int32_t, b, NULL));

struct TestNonArrMultInt32Str {
    int32_t str1[100];
    int32_t str2[100];
    int32_t str3[100];
};
INIT(TestNonArrMultInt32Str,
     struct TestNonArrMultInt32Str,
     MEM(struct TestNonArrMultInt32Str, Str, int32_t, str1, NULL),
     MEM(struct TestNonArrMultInt32Str, Str, int32_t, str2, NULL),
     MEM(struct TestNonArrMultInt32Str, Str, int32_t, str3, NULL));

struct TestNonArrMultInt32Num {
    int32_t num1[5];
    int32_t num2[5];
    int32_t num3[5];
    int32_t num4[5];
    int32_t num5[5];
};
INIT(TestNonArrMultInt32Num,
     struct TestNonArrMultInt32Num,
     MEM(struct TestNonArrMultInt32Num, Num, int32_t, num1, NULL),
     MEM(struct TestNonArrMultInt32Num, Num, int32_t, num2, NULL),
     MEM(struct TestNonArrMultInt32Num, Num, int32_t, num3, NULL),
     MEM(struct TestNonArrMultInt32Num, Num, int32_t, num4, NULL),
     MEM(struct TestNonArrMultInt32Num, Num, int32_t, num5, NULL));

struct TestNonArrMultInt32Bool {
    int32_t bool1[5];
    int32_t bool2[5];
    int32_t bool3[5];
    int32_t bool4[5];
    int32_t bool5[5];
};
INIT(TestNonArrMultInt32Bool,
     struct TestNonArrMultInt32Bool,
     MEM(struct TestNonArrMultInt32Bool, Bool, int32_t, bool1, NULL),
     MEM(struct TestNonArrMultInt32Bool, Bool, int32_t, bool2, NULL),
     MEM(struct TestNonArrMultInt32Bool, Bool, int32_t, bool3, NULL),
     MEM(struct TestNonArrMultInt32Bool, Bool, int32_t, bool4, NULL),
     MEM(struct TestNonArrMultInt32Bool, Bool, int32_t, bool5, NULL));

// mult to json
char* test_change_non_arr_single_int32_num_to_json(char* exp, char* real);
char* test_change_non_arr_single_int32_bool_to_json(char* exp, char* real);
char* test_change_non_arr_mult_int32_num_to_json(char* exp, char* real);
char* test_change_non_arr_mult_int32_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_arr_single_int32_num(char* json);
int test_change_mult_str_json_to_non_arr_single_int32_num(char* json);
int test_change_single_num_json_to_non_arr_single_int32_num(char* json);
int test_change_mult_num_json_to_non_arr_single_int32_num(char* json);
int test_change_single_bool_json_to_non_arr_single_int32_num(char* json);
int test_change_mult_bool_json_to_non_arr_single_int32_num(char* json);
int test_change_single_null_json_to_non_arr_single_int32_num(char* json);
int test_change_mult_null_json_to_non_arr_single_int32_num(char* json);

int test_change_single_str_json_to_non_arr_single_int32_bool(char* json);
int test_change_mult_str_json_to_non_arr_single_int32_bool(char* json);
int test_change_single_num_json_to_non_arr_single_int32_bool(char* json);
int test_change_mult_num_json_to_non_arr_single_int32_bool(char* json);
int test_change_single_bool_json_to_non_arr_single_int32_bool(char* json);
int test_change_mult_bool_json_to_non_arr_single_int32_bool(char* json);
int test_change_single_null_json_to_non_arr_single_int32_bool(char* json);
int test_change_mult_null_json_to_non_arr_single_int32_bool(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_int32_num(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_int32_num(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_int32_num(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_int32_num(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_int32_num(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_int32_num(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_int32_num(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_int32_num(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_int32_num(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_int32_num(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_int32_num(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_int32_num(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_int32_num(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_int32_num(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_int32_num(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_int32_num(char* json);

int test_change_equal_mult_str_json_to_non_arr_mult_int32_bool(char* json);
int test_change_more_mult_str_json_to_non_arr_mult_int32_bool(char* json);
int test_change_less_mult_str_json_to_non_arr_mult_int32_bool(char* json);
int test_change_diff_mult_str_json_to_non_arr_mult_int32_bool(char* json);
int test_change_equal_mult_num_json_to_non_arr_mult_int32_bool(char* json);
int test_change_more_mult_num_json_to_non_arr_mult_int32_bool(char* json);
int test_change_less_mult_num_json_to_non_arr_mult_int32_bool(char* json);
int test_change_diff_mult_num_json_to_non_arr_mult_int32_bool(char* json);
int test_change_equal_mult_bool_json_to_non_arr_mult_int32_bool(char* json);
int test_change_more_mult_bool_json_to_non_arr_mult_int32_bool(char* json);
int test_change_less_mult_bool_json_to_non_arr_mult_int32_bool(char* json);
int test_change_diff_mult_bool_json_to_non_arr_mult_int32_bool(char* json);
int test_change_equal_mult_null_json_to_non_arr_mult_int32_bool(char* json);
int test_change_more_mult_null_json_to_non_arr_mult_int32_bool(char* json);
int test_change_less_mult_null_json_to_non_arr_mult_int32_bool(char* json);
int test_change_diff_mult_null_json_to_non_arr_mult_int32_bool(char* json);

#endif
