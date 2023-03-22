/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-03-22 13:47:29
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int64/test_ptr_arr_int64.h
 */

#ifndef __TEST_PTR_ARR_INT64_H_
#define __TEST_PTR_ARR_INT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleInt64Str {
    int64_t* str[2];
};
INIT(TestPtrArrSingleInt64Str,
     struct TestPtrArrSingleInt64Str,
     MEM(struct TestPtrArrSingleInt64Str, Str, int64_t*, str, NULL));

struct TestPtrArrSingleInt64Num {
    int64_t* num[2];
};
INIT(TestPtrArrSingleInt64Num,
     struct TestPtrArrSingleInt64Num,
     MEM(struct TestPtrArrSingleInt64Num, Num, int64_t*, num, NULL));

struct TestPtrArrSingleInt64Bool {
    int64_t* b[2];
};
INIT(TestPtrArrSingleInt64Bool,
     struct TestPtrArrSingleInt64Bool,
     MEM(struct TestPtrArrSingleInt64Bool, Bool, int64_t*, b, NULL));

struct TestPtrArrMultInt64Str {
    int64_t* str1[2];
    int64_t* str2[2];
    int64_t* str3[2];
};
INIT(TestPtrArrMultInt64Str,
     struct TestPtrArrMultInt64Str,
     MEM(struct TestPtrArrMultInt64Str, Str, int64_t*, str1, NULL),
     MEM(struct TestPtrArrMultInt64Str, Str, int64_t*, str2, NULL),
     MEM(struct TestPtrArrMultInt64Str, Str, int64_t*, str3, NULL));

struct TestPtrArrMultInt64Num {
    int64_t* num1[2];
    int64_t* num2[2];
    int64_t* num3[2];
};
INIT(TestPtrArrMultInt64Num,
     struct TestPtrArrMultInt64Num,
     MEM(struct TestPtrArrMultInt64Num, Num, int64_t*, num1, NULL),
     MEM(struct TestPtrArrMultInt64Num, Num, int64_t*, num2, NULL),
     MEM(struct TestPtrArrMultInt64Num, Num, int64_t*, num3, NULL));

struct TestPtrArrMultInt64Bool {
    int64_t* bool1[2];
    int64_t* bool2[2];
    int64_t* bool3[2];
};
INIT(TestPtrArrMultInt64Bool,
     struct TestPtrArrMultInt64Bool,
     MEM(struct TestPtrArrMultInt64Bool, Bool, int64_t*, bool1, NULL),
     MEM(struct TestPtrArrMultInt64Bool, Bool, int64_t*, bool2, NULL),
     MEM(struct TestPtrArrMultInt64Bool, Bool, int64_t*, bool3, NULL));

// mult to json
int test_change_ptr_arr_single_int64_str_to_json(char* exp, char* real);
int test_change_ptr_arr_single_int64_num_to_json(char* exp, char* real);
int test_change_ptr_arr_single_int64_bool_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_int64_str_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_int64_num_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_int64_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_int64_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_int64_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_int64_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_int64_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_int64_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_int64_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_int64_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_int64_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_int64_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_int64_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_int64_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_int64_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_int64_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_int64_bool(char* json);

#endif
