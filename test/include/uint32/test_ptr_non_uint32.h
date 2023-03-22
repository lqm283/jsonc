/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 10:23:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint32/test_ptr_non_uint32.h
 */

#ifndef __TEST_PTR_NON_UINT32_H_
#define __TEST_PTR_NON_UINT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleUint32Str {
    uint32_t* str;
};
INIT(TestPtrNonSingleUint32Str,
     struct TestPtrNonSingleUint32Str,
     MEM(struct TestPtrNonSingleUint32Str, Str, uint32_t*, str, NULL));

struct TestPtrNonSingleUint32Num {
    uint32_t* num;
};
INIT(TestPtrNonSingleUint32Num,
     struct TestPtrNonSingleUint32Num,
     MEM(struct TestPtrNonSingleUint32Num, Num, uint32_t*, num, NULL));

struct TestPtrNonSingleUint32Bool {
    uint32_t* b;
};
INIT(TestPtrNonSingleUint32Bool,
     struct TestPtrNonSingleUint32Bool,
     MEM(struct TestPtrNonSingleUint32Bool, Bool, uint32_t*, b, NULL));

struct TestPtrNonMultUint32Str {
    uint32_t* str1;
    uint32_t* str2;
    uint32_t* str3;
};
INIT(TestPtrNonMultUint32Str,
     struct TestPtrNonMultUint32Str,
     MEM(struct TestPtrNonMultUint32Str, Str, uint32_t*, str1, NULL),
     MEM(struct TestPtrNonMultUint32Str, Str, uint32_t*, str2, NULL),
     MEM(struct TestPtrNonMultUint32Str, Str, uint32_t*, str3, NULL));

struct TestPtrNonMultUint32Num {
    uint32_t* num1;
    uint32_t* num2;
    uint32_t* num3;
    uint32_t* num4;
    uint32_t* num5;
};
INIT(TestPtrNonMultUint32Num,
     struct TestPtrNonMultUint32Num,
     MEM(struct TestPtrNonMultUint32Num, Num, uint32_t*, num1, NULL),
     MEM(struct TestPtrNonMultUint32Num, Num, uint32_t*, num2, NULL),
     MEM(struct TestPtrNonMultUint32Num, Num, uint32_t*, num3, NULL),
     MEM(struct TestPtrNonMultUint32Num, Num, uint32_t*, num4, NULL),
     MEM(struct TestPtrNonMultUint32Num, Num, uint32_t*, num5, NULL));

struct TestPtrNonMultUint32Bool {
    uint32_t* bool1;
    uint32_t* bool2;
    uint32_t* bool3;
    uint32_t* bool4;
    uint32_t* bool5;
};
INIT(TestPtrNonMultUint32Bool,
     struct TestPtrNonMultUint32Bool,
     MEM(struct TestPtrNonMultUint32Bool, Bool, uint32_t*, bool1, NULL),
     MEM(struct TestPtrNonMultUint32Bool, Bool, uint32_t*, bool2, NULL),
     MEM(struct TestPtrNonMultUint32Bool, Bool, uint32_t*, bool3, NULL),
     MEM(struct TestPtrNonMultUint32Bool, Bool, uint32_t*, bool4, NULL),
     MEM(struct TestPtrNonMultUint32Bool, Bool, uint32_t*, bool5, NULL));

// mult to json
int test_change_ptr_non_single_uint32_str_to_json(char* exp, char* real);
int test_change_ptr_non_single_uint32_num_to_json(char* exp, char* real);
int test_change_ptr_non_single_uint32_bool_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint32_str_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint32_num_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint32_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_uint32_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint32_num(char* json);
int test_change_single_num_json_to_ptr_non_single_uint32_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint32_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint32_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint32_num(char* json);
int test_change_single_null_json_to_ptr_non_single_uint32_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint32_num(char* json);

int test_change_single_str_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_uint32_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint32_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint32_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint32_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint32_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint32_bool(char* json);

#endif
