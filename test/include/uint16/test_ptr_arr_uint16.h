/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 08:27:28
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint16/test_ptr_arr_uint16.h
 */

#ifndef __TEST_PTR_ARR_UINT16_H_
#define __TEST_PTR_ARR_UINT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleUint16Str {
    uint16_t* str[2];
};
INIT(TestPtrArrSingleUint16Str,
     struct TestPtrArrSingleUint16Str,
     MEM(struct TestPtrArrSingleUint16Str, Str, uint16_t*, str, NULL));

struct TestPtrArrSingleUint16Num {
    uint16_t* num[2];
};
INIT(TestPtrArrSingleUint16Num,
     struct TestPtrArrSingleUint16Num,
     MEM(struct TestPtrArrSingleUint16Num, Num, uint16_t*, num, NULL));

struct TestPtrArrSingleUint16Bool {
    uint16_t* b[2];
};
INIT(TestPtrArrSingleUint16Bool,
     struct TestPtrArrSingleUint16Bool,
     MEM(struct TestPtrArrSingleUint16Bool, Bool, uint16_t*, b, NULL));

struct TestPtrArrMultUint16Str {
    uint16_t* str1[2];
    uint16_t* str2[2];
    uint16_t* str3[2];
};
INIT(TestPtrArrMultUint16Str,
     struct TestPtrArrMultUint16Str,
     MEM(struct TestPtrArrMultUint16Str, Str, uint16_t*, str1, NULL),
     MEM(struct TestPtrArrMultUint16Str, Str, uint16_t*, str2, NULL),
     MEM(struct TestPtrArrMultUint16Str, Str, uint16_t*, str3, NULL));

struct TestPtrArrMultUint16Num {
    uint16_t* num1[2];
    uint16_t* num2[2];
    uint16_t* num3[2];
};
INIT(TestPtrArrMultUint16Num,
     struct TestPtrArrMultUint16Num,
     MEM(struct TestPtrArrMultUint16Num, Num, uint16_t*, num1, NULL),
     MEM(struct TestPtrArrMultUint16Num, Num, uint16_t*, num2, NULL),
     MEM(struct TestPtrArrMultUint16Num, Num, uint16_t*, num3, NULL));

struct TestPtrArrMultUint16Bool {
    uint16_t* bool1[2];
    uint16_t* bool2[2];
    uint16_t* bool3[2];
};
INIT(TestPtrArrMultUint16Bool,
     struct TestPtrArrMultUint16Bool,
     MEM(struct TestPtrArrMultUint16Bool, Bool, uint16_t*, bool1, NULL),
     MEM(struct TestPtrArrMultUint16Bool, Bool, uint16_t*, bool2, NULL),
     MEM(struct TestPtrArrMultUint16Bool, Bool, uint16_t*, bool3, NULL));

// mult to json
int test_change_ptr_arr_single_uint16_str_to_json(char* exp, char* real);
int test_change_ptr_arr_single_uint16_num_to_json(char* exp, char* real);
int test_change_ptr_arr_single_uint16_bool_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint16_str_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint16_num_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint16_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint16_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint16_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint16_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint16_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint16_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint16_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint16_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint16_bool(char* json);

#endif
