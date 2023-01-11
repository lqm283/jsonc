/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 08:27:28
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int32/test_ptr_arr_int32.h
 */

#ifndef __TEST_PTR_ARR_INT32_H_
#define __TEST_PTR_ARR_INT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleInt32Str {
    int32_t* str[2];
};
INIT(TestPtrArrSingleInt32Str,
     struct TestPtrArrSingleInt32Str,
     MEM(struct TestPtrArrSingleInt32Str, Str, int32_t*, str, NULL));

struct TestPtrArrSingleInt32Num {
    int32_t* num[2];
};
INIT(TestPtrArrSingleInt32Num,
     struct TestPtrArrSingleInt32Num,
     MEM(struct TestPtrArrSingleInt32Num, Num, int32_t*, num, NULL));

struct TestPtrArrSingleInt32Bool {
    int32_t* b[2];
};
INIT(TestPtrArrSingleInt32Bool,
     struct TestPtrArrSingleInt32Bool,
     MEM(struct TestPtrArrSingleInt32Bool, Bool, int32_t*, b, NULL));

struct TestPtrArrMultInt32Str {
    int32_t* str1[2];
    int32_t* str2[2];
    int32_t* str3[2];
};
INIT(TestPtrArrMultInt32Str,
     struct TestPtrArrMultInt32Str,
     MEM(struct TestPtrArrMultInt32Str, Str, int32_t*, str1, NULL),
     MEM(struct TestPtrArrMultInt32Str, Str, int32_t*, str2, NULL),
     MEM(struct TestPtrArrMultInt32Str, Str, int32_t*, str3, NULL));

struct TestPtrArrMultInt32Num {
    int32_t* num1[2];
    int32_t* num2[2];
    int32_t* num3[2];
};
INIT(TestPtrArrMultInt32Num,
     struct TestPtrArrMultInt32Num,
     MEM(struct TestPtrArrMultInt32Num, Num, int32_t*, num1, NULL),
     MEM(struct TestPtrArrMultInt32Num, Num, int32_t*, num2, NULL),
     MEM(struct TestPtrArrMultInt32Num, Num, int32_t*, num3, NULL));

struct TestPtrArrMultInt32Bool {
    int32_t* bool1[2];
    int32_t* bool2[2];
    int32_t* bool3[2];
};
INIT(TestPtrArrMultInt32Bool,
     struct TestPtrArrMultInt32Bool,
     MEM(struct TestPtrArrMultInt32Bool, Bool, int32_t*, bool1, NULL),
     MEM(struct TestPtrArrMultInt32Bool, Bool, int32_t*, bool2, NULL),
     MEM(struct TestPtrArrMultInt32Bool, Bool, int32_t*, bool3, NULL));

// mult to json
char* test_change_ptr_arr_single_int32_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_int32_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_int32_bool_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_int32_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_int32_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_int32_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_int32_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_int32_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_int32_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_int32_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_int32_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_int32_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_int32_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_int32_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_int32_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_int32_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_int32_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_int32_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_int32_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_int32_bool(char* json);

#endif
