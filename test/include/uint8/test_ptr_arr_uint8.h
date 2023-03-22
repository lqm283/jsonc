/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-10 20:49:05
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint8/test_ptr_arr_uint8.h
 */

#ifndef __TEST_PTR_ARR_UINT8_H_
#define __TEST_PTR_ARR_UINT8_H_

#include "../../../jsonc.h"
#include <stdint.h>

// char 单成员字符串
struct TestPtrArrSingleUint8Str {
    uint8_t* str[2];
};
INIT(TestPtrArrSingleUint8Str,
     struct TestPtrArrSingleUint8Str,
     MEM(struct TestPtrArrSingleUint8Str, Str, uint8_t*, str, NULL));

struct TestPtrArrSingleUint8Num {
    uint8_t* num[2];
};
INIT(TestPtrArrSingleUint8Num,
     struct TestPtrArrSingleUint8Num,
     MEM(struct TestPtrArrSingleUint8Num, Num, uint8_t*, num, NULL));

struct TestPtrArrSingleUint8Bool {
    uint8_t* b[2];
};
INIT(TestPtrArrSingleUint8Bool,
     struct TestPtrArrSingleUint8Bool,
     MEM(struct TestPtrArrSingleUint8Bool, Bool, uint8_t*, b, NULL));

struct TestPtrArrMultUint8Str {
    uint8_t* str1[2];
    uint8_t* str2[2];
    uint8_t* str3[2];
};
INIT(TestPtrArrMultUint8Str,
     struct TestPtrArrMultUint8Str,
     MEM(struct TestPtrArrMultUint8Str, Str, uint8_t*, str1, NULL),
     MEM(struct TestPtrArrMultUint8Str, Str, uint8_t*, str2, NULL),
     MEM(struct TestPtrArrMultUint8Str, Str, uint8_t*, str3, NULL));

struct TestPtrArrMultUint8Num {
    uint8_t* num1[2];
    uint8_t* num2[2];
    uint8_t* num3[2];
};
INIT(TestPtrArrMultUint8Num,
     struct TestPtrArrMultUint8Num,
     MEM(struct TestPtrArrMultUint8Num, Num, uint8_t*, num1, NULL),
     MEM(struct TestPtrArrMultUint8Num, Num, uint8_t*, num2, NULL),
     MEM(struct TestPtrArrMultUint8Num, Num, uint8_t*, num3, NULL));

struct TestPtrArrMultUint8Bool {
    uint8_t* bool1[2];
    uint8_t* bool2[2];
    uint8_t* bool3[2];
};
INIT(TestPtrArrMultUint8Bool,
     struct TestPtrArrMultUint8Bool,
     MEM(struct TestPtrArrMultUint8Bool, Bool, uint8_t*, bool1, NULL),
     MEM(struct TestPtrArrMultUint8Bool, Bool, uint8_t*, bool2, NULL),
     MEM(struct TestPtrArrMultUint8Bool, Bool, uint8_t*, bool3, NULL));

// mult to json
int test_change_ptr_arr_single_uint8_str_to_json(char* exp, char* real);
int test_change_ptr_arr_single_uint8_num_to_json(char* exp, char* real);
int test_change_ptr_arr_single_uint8_bool_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint8_str_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint8_num_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint8_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint8_str(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint8_str(char* json);

int test_change_single_str_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint8_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint8_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint8_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint8_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint8_str(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint8_str(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint8_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint8_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint8_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint8_bool(char* json);

#endif
