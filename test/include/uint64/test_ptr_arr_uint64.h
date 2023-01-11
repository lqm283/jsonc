/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 08:27:28
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint64/test_ptr_arr_uint64.h
 */

#ifndef __TEST_PTR_ARR_UINT64_H_
#define __TEST_PTR_ARR_UINT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleUint64Str {
    uint64_t* str[2];
};
INIT(TestPtrArrSingleUint64Str,
     struct TestPtrArrSingleUint64Str,
     MEM(struct TestPtrArrSingleUint64Str, Str, uint64_t*, str, NULL));

struct TestPtrArrSingleUint64Num {
    uint64_t* num[2];
};
INIT(TestPtrArrSingleUint64Num,
     struct TestPtrArrSingleUint64Num,
     MEM(struct TestPtrArrSingleUint64Num, Num, uint64_t*, num, NULL));

struct TestPtrArrSingleUint64Bool {
    uint64_t* b[2];
};
INIT(TestPtrArrSingleUint64Bool,
     struct TestPtrArrSingleUint64Bool,
     MEM(struct TestPtrArrSingleUint64Bool, Bool, uint64_t*, b, NULL));

struct TestPtrArrMultUint64Str {
    uint64_t* str1[2];
    uint64_t* str2[2];
    uint64_t* str3[2];
};
INIT(TestPtrArrMultUint64Str,
     struct TestPtrArrMultUint64Str,
     MEM(struct TestPtrArrMultUint64Str, Str, uint64_t*, str1, NULL),
     MEM(struct TestPtrArrMultUint64Str, Str, uint64_t*, str2, NULL),
     MEM(struct TestPtrArrMultUint64Str, Str, uint64_t*, str3, NULL));

struct TestPtrArrMultUint64Num {
    uint64_t* num1[2];
    uint64_t* num2[2];
    uint64_t* num3[2];
};
INIT(TestPtrArrMultUint64Num,
     struct TestPtrArrMultUint64Num,
     MEM(struct TestPtrArrMultUint64Num, Num, uint64_t*, num1, NULL),
     MEM(struct TestPtrArrMultUint64Num, Num, uint64_t*, num2, NULL),
     MEM(struct TestPtrArrMultUint64Num, Num, uint64_t*, num3, NULL));

struct TestPtrArrMultUint64Bool {
    uint64_t* bool1[2];
    uint64_t* bool2[2];
    uint64_t* bool3[2];
};
INIT(TestPtrArrMultUint64Bool,
     struct TestPtrArrMultUint64Bool,
     MEM(struct TestPtrArrMultUint64Bool, Bool, uint64_t*, bool1, NULL),
     MEM(struct TestPtrArrMultUint64Bool, Bool, uint64_t*, bool2, NULL),
     MEM(struct TestPtrArrMultUint64Bool, Bool, uint64_t*, bool3, NULL));

// mult to json
char* test_change_ptr_arr_single_uint64_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_uint64_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_uint64_bool_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_uint64_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_uint64_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_uint64_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint64_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint64_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint64_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint64_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint64_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint64_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint64_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint64_bool(char* json);

#endif
