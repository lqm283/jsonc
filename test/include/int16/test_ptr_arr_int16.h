/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 08:27:28
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int16/test_ptr_arr_int16.h
 */

#ifndef __TEST_PTR_ARR_INT16_H_
#define __TEST_PTR_ARR_INT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleInt16Str {
    int16_t* str[2];
};
INIT(TestPtrArrSingleInt16Str,
     struct TestPtrArrSingleInt16Str,
     MEM(struct TestPtrArrSingleInt16Str, Str, int16_t*, str, NULL));

struct TestPtrArrSingleInt16Num {
    int16_t* num[2];
};
INIT(TestPtrArrSingleInt16Num,
     struct TestPtrArrSingleInt16Num,
     MEM(struct TestPtrArrSingleInt16Num, Num, int16_t*, num, NULL));

struct TestPtrArrSingleInt16Bool {
    int16_t* b[2];
};
INIT(TestPtrArrSingleInt16Bool,
     struct TestPtrArrSingleInt16Bool,
     MEM(struct TestPtrArrSingleInt16Bool, Bool, int16_t*, b, NULL));

struct TestPtrArrMultInt16Str {
    int16_t* str1[2];
    int16_t* str2[2];
    int16_t* str3[2];
};
INIT(TestPtrArrMultInt16Str,
     struct TestPtrArrMultInt16Str,
     MEM(struct TestPtrArrMultInt16Str, Str, int16_t*, str1, NULL),
     MEM(struct TestPtrArrMultInt16Str, Str, int16_t*, str2, NULL),
     MEM(struct TestPtrArrMultInt16Str, Str, int16_t*, str3, NULL));

struct TestPtrArrMultInt16Num {
    int16_t* num1[2];
    int16_t* num2[2];
    int16_t* num3[2];
};
INIT(TestPtrArrMultInt16Num,
     struct TestPtrArrMultInt16Num,
     MEM(struct TestPtrArrMultInt16Num, Num, int16_t*, num1, NULL),
     MEM(struct TestPtrArrMultInt16Num, Num, int16_t*, num2, NULL),
     MEM(struct TestPtrArrMultInt16Num, Num, int16_t*, num3, NULL));

struct TestPtrArrMultInt16Bool {
    int16_t* bool1[2];
    int16_t* bool2[2];
    int16_t* bool3[2];
};
INIT(TestPtrArrMultInt16Bool,
     struct TestPtrArrMultInt16Bool,
     MEM(struct TestPtrArrMultInt16Bool, Bool, int16_t*, bool1, NULL),
     MEM(struct TestPtrArrMultInt16Bool, Bool, int16_t*, bool2, NULL),
     MEM(struct TestPtrArrMultInt16Bool, Bool, int16_t*, bool3, NULL));

// mult to json
char* test_change_ptr_arr_single_int16_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_int16_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_int16_bool_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_int16_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_int16_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_int16_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_int16_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_int16_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_int16_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_int16_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_int16_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_int16_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_int16_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_int16_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_int16_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_int16_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_int16_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_int16_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_int16_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_int16_bool(char* json);

#endif
