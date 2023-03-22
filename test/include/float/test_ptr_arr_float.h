/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-03-22 13:46:10
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/float/test_ptr_arr_float.h
 */

#ifndef __TEST_PTR_ARR_FLOAT_H_
#define __TEST_PTR_ARR_FLOAT_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleFloatStr {
    float* str[2];
};
INIT(TestPtrArrSingleFloatStr,
     struct TestPtrArrSingleFloatStr,
     MEM(struct TestPtrArrSingleFloatStr, Str, float*, str, NULL));

struct TestPtrArrSingleFloatNum {
    float* num[2];
};
INIT(TestPtrArrSingleFloatNum,
     struct TestPtrArrSingleFloatNum,
     MEM(struct TestPtrArrSingleFloatNum, Num, float*, num, NULL));

struct TestPtrArrSingleFloatBool {
    float* b[2];
};
INIT(TestPtrArrSingleFloatBool,
     struct TestPtrArrSingleFloatBool,
     MEM(struct TestPtrArrSingleFloatBool, Bool, float*, b, NULL));

struct TestPtrArrMultFloatStr {
    float* str1[2];
    float* str2[2];
    float* str3[2];
};
INIT(TestPtrArrMultFloatStr,
     struct TestPtrArrMultFloatStr,
     MEM(struct TestPtrArrMultFloatStr, Str, float*, str1, NULL),
     MEM(struct TestPtrArrMultFloatStr, Str, float*, str2, NULL),
     MEM(struct TestPtrArrMultFloatStr, Str, float*, str3, NULL));

struct TestPtrArrMultFloatNum {
    float* num1[2];
    float* num2[2];
    float* num3[2];
};
INIT(TestPtrArrMultFloatNum,
     struct TestPtrArrMultFloatNum,
     MEM(struct TestPtrArrMultFloatNum, Num, float*, num1, NULL),
     MEM(struct TestPtrArrMultFloatNum, Num, float*, num2, NULL),
     MEM(struct TestPtrArrMultFloatNum, Num, float*, num3, NULL));

struct TestPtrArrMultFloatBool {
    float* bool1[2];
    float* bool2[2];
    float* bool3[2];
};
INIT(TestPtrArrMultFloatBool,
     struct TestPtrArrMultFloatBool,
     MEM(struct TestPtrArrMultFloatBool, Bool, float*, bool1, NULL),
     MEM(struct TestPtrArrMultFloatBool, Bool, float*, bool2, NULL),
     MEM(struct TestPtrArrMultFloatBool, Bool, float*, bool3, NULL));

// mult to json
int test_change_ptr_arr_single_float_num_to_json(char* exp, char* real);
int test_change_ptr_arr_single_float_bool_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_float_num_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_float_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_float_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_float_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_float_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_float_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_float_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_float_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_float_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_float_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_float_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_float_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_float_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_float_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_float_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_float_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_float_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_float_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_float_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_float_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_float_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_float_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_float_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_float_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_float_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_float_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_float_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_float_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_float_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_float_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_float_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_float_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_float_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_float_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_float_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_float_bool(char* json);

#endif
