/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 11:52:15
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint64/test_ptr_non_uint64.h
 */

#ifndef __TEST_PTR_NON_UINT64_H_
#define __TEST_PTR_NON_UINT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleUint64Str {
    uint64_t* str;
};
INIT(TestPtrNonSingleUint64Str,
     struct TestPtrNonSingleUint64Str,
     MEM(struct TestPtrNonSingleUint64Str, Str, uint64_t*, str, NULL));

struct TestPtrNonSingleUint64Num {
    uint64_t* num;
};
INIT(TestPtrNonSingleUint64Num,
     struct TestPtrNonSingleUint64Num,
     MEM(struct TestPtrNonSingleUint64Num, Num, uint64_t*, num, NULL));

struct TestPtrNonSingleUint64Bool {
    uint64_t* b;
};
INIT(TestPtrNonSingleUint64Bool,
     struct TestPtrNonSingleUint64Bool,
     MEM(struct TestPtrNonSingleUint64Bool, Bool, uint64_t*, b, NULL));

struct TestPtrNonMultUint64Str {
    uint64_t* str1;
    uint64_t* str2;
    uint64_t* str3;
};
INIT(TestPtrNonMultUint64Str,
     struct TestPtrNonMultUint64Str,
     MEM(struct TestPtrNonMultUint64Str, Str, uint64_t*, str1, NULL),
     MEM(struct TestPtrNonMultUint64Str, Str, uint64_t*, str2, NULL),
     MEM(struct TestPtrNonMultUint64Str, Str, uint64_t*, str3, NULL));

struct TestPtrNonMultUint64Num {
    uint64_t* num1;
    uint64_t* num2;
    uint64_t* num3;
    uint64_t* num4;
    uint64_t* num5;
};
INIT(TestPtrNonMultUint64Num,
     struct TestPtrNonMultUint64Num,
     MEM(struct TestPtrNonMultUint64Num, Num, uint64_t*, num1, NULL),
     MEM(struct TestPtrNonMultUint64Num, Num, uint64_t*, num2, NULL),
     MEM(struct TestPtrNonMultUint64Num, Num, uint64_t*, num3, NULL),
     MEM(struct TestPtrNonMultUint64Num, Num, uint64_t*, num4, NULL),
     MEM(struct TestPtrNonMultUint64Num, Num, uint64_t*, num5, NULL));

struct TestPtrNonMultUint64Bool {
    uint64_t* bool1;
    uint64_t* bool2;
    uint64_t* bool3;
    uint64_t* bool4;
    uint64_t* bool5;
};
INIT(TestPtrNonMultUint64Bool,
     struct TestPtrNonMultUint64Bool,
     MEM(struct TestPtrNonMultUint64Bool, Bool, uint64_t*, bool1, NULL),
     MEM(struct TestPtrNonMultUint64Bool, Bool, uint64_t*, bool2, NULL),
     MEM(struct TestPtrNonMultUint64Bool, Bool, uint64_t*, bool3, NULL),
     MEM(struct TestPtrNonMultUint64Bool, Bool, uint64_t*, bool4, NULL),
     MEM(struct TestPtrNonMultUint64Bool, Bool, uint64_t*, bool5, NULL));

// mult to json
int test_change_ptr_non_single_uint64_str_to_json(char* exp, char* real);
int test_change_ptr_non_single_uint64_num_to_json(char* exp, char* real);
int test_change_ptr_non_single_uint64_bool_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint64_str_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint64_num_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint64_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_uint64_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint64_num(char* json);
int test_change_single_num_json_to_ptr_non_single_uint64_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint64_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint64_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint64_num(char* json);
int test_change_single_null_json_to_ptr_non_single_uint64_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint64_num(char* json);

int test_change_single_str_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_uint64_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint64_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint64_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint64_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint64_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint64_bool(char* json);

#endif
