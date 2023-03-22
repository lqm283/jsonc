/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 08:27:28
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint32/test_ptr_arr_uint32.h
 */

#ifndef __TEST_PTR_ARR_UINT32_H_
#define __TEST_PTR_ARR_UINT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleUint32Str {
    uint32_t* str[2];
};
INIT(TestPtrArrSingleUint32Str,
     struct TestPtrArrSingleUint32Str,
     MEM(struct TestPtrArrSingleUint32Str, Str, uint32_t*, str, NULL));

struct TestPtrArrSingleUint32Num {
    uint32_t* num[2];
};
INIT(TestPtrArrSingleUint32Num,
     struct TestPtrArrSingleUint32Num,
     MEM(struct TestPtrArrSingleUint32Num, Num, uint32_t*, num, NULL));

struct TestPtrArrSingleUint32Bool {
    uint32_t* b[2];
};
INIT(TestPtrArrSingleUint32Bool,
     struct TestPtrArrSingleUint32Bool,
     MEM(struct TestPtrArrSingleUint32Bool, Bool, uint32_t*, b, NULL));

struct TestPtrArrMultUint32Str {
    uint32_t* str1[2];
    uint32_t* str2[2];
    uint32_t* str3[2];
};
INIT(TestPtrArrMultUint32Str,
     struct TestPtrArrMultUint32Str,
     MEM(struct TestPtrArrMultUint32Str, Str, uint32_t*, str1, NULL),
     MEM(struct TestPtrArrMultUint32Str, Str, uint32_t*, str2, NULL),
     MEM(struct TestPtrArrMultUint32Str, Str, uint32_t*, str3, NULL));

struct TestPtrArrMultUint32Num {
    uint32_t* num1[2];
    uint32_t* num2[2];
    uint32_t* num3[2];
};
INIT(TestPtrArrMultUint32Num,
     struct TestPtrArrMultUint32Num,
     MEM(struct TestPtrArrMultUint32Num, Num, uint32_t*, num1, NULL),
     MEM(struct TestPtrArrMultUint32Num, Num, uint32_t*, num2, NULL),
     MEM(struct TestPtrArrMultUint32Num, Num, uint32_t*, num3, NULL));

struct TestPtrArrMultUint32Bool {
    uint32_t* bool1[2];
    uint32_t* bool2[2];
    uint32_t* bool3[2];
};
INIT(TestPtrArrMultUint32Bool,
     struct TestPtrArrMultUint32Bool,
     MEM(struct TestPtrArrMultUint32Bool, Bool, uint32_t*, bool1, NULL),
     MEM(struct TestPtrArrMultUint32Bool, Bool, uint32_t*, bool2, NULL),
     MEM(struct TestPtrArrMultUint32Bool, Bool, uint32_t*, bool3, NULL));

// mult to json
int test_change_ptr_arr_single_uint32_str_to_json(char* exp, char* real);
int test_change_ptr_arr_single_uint32_num_to_json(char* exp, char* real);
int test_change_ptr_arr_single_uint32_bool_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint32_str_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint32_num_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_uint32_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint32_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint32_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_uint32_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_uint32_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint32_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint32_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_uint32_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_uint32_bool(char* json);

#endif
