/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 13:51:51
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/double/test_ptr_arr_double.h
 */

#ifndef __TEST_PTR_ARR_DOUBLE_H_
#define __TEST_PTR_ARR_DOUBLE_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleDoubleStr {
    double* str[2];
};
INIT(TestPtrArrSingleDoubleStr,
     struct TestPtrArrSingleDoubleStr,
     MEM(struct TestPtrArrSingleDoubleStr, Str, double*, str, NULL));

struct TestPtrArrSingleDoubleNum {
    double* num[2];
};
INIT(TestPtrArrSingleDoubleNum,
     struct TestPtrArrSingleDoubleNum,
     MEM(struct TestPtrArrSingleDoubleNum, Num, double*, num, NULL));

struct TestPtrArrSingleDoubleBool {
    double* b[2];
};
INIT(TestPtrArrSingleDoubleBool,
     struct TestPtrArrSingleDoubleBool,
     MEM(struct TestPtrArrSingleDoubleBool, Bool, double*, b, NULL));

struct TestPtrArrMultDoubleStr {
    double* str1[2];
    double* str2[2];
    double* str3[2];
};
INIT(TestPtrArrMultDoubleStr,
     struct TestPtrArrMultDoubleStr,
     MEM(struct TestPtrArrMultDoubleStr, Str, double*, str1, NULL),
     MEM(struct TestPtrArrMultDoubleStr, Str, double*, str2, NULL),
     MEM(struct TestPtrArrMultDoubleStr, Str, double*, str3, NULL));

struct TestPtrArrMultDoubleNum {
    double* num1[2];
    double* num2[2];
    double* num3[2];
};
INIT(TestPtrArrMultDoubleNum,
     struct TestPtrArrMultDoubleNum,
     MEM(struct TestPtrArrMultDoubleNum, Num, double*, num1, NULL),
     MEM(struct TestPtrArrMultDoubleNum, Num, double*, num2, NULL),
     MEM(struct TestPtrArrMultDoubleNum, Num, double*, num3, NULL));

struct TestPtrArrMultDoubleBool {
    double* bool1[2];
    double* bool2[2];
    double* bool3[2];
};
INIT(TestPtrArrMultDoubleBool,
     struct TestPtrArrMultDoubleBool,
     MEM(struct TestPtrArrMultDoubleBool, Bool, double*, bool1, NULL),
     MEM(struct TestPtrArrMultDoubleBool, Bool, double*, bool2, NULL),
     MEM(struct TestPtrArrMultDoubleBool, Bool, double*, bool3, NULL));

// mult to json
char* test_change_ptr_arr_single_double_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_double_bool_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_double_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_double_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_double_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_double_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_double_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_double_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_double_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_double_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_double_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_double_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_double_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_double_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_double_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_double_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_double_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_double_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_double_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_double_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_double_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_double_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_double_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_double_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_double_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_double_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_double_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_double_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_double_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_double_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_double_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_double_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_double_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_double_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_double_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_double_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_double_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_double_bool(char* json);

#endif
