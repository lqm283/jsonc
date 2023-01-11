/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 08:17:08
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint16/test_ptr_non_uint16.h
 */

#ifndef __TEST_PTR_NON_UINT16_H_
#define __TEST_PTR_NON_UINT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleUint16Str {
    uint16_t* str;
};
INIT(TestPtrNonSingleUint16Str,
     struct TestPtrNonSingleUint16Str,
     MEM(struct TestPtrNonSingleUint16Str, Str, uint16_t*, str, NULL));

struct TestPtrNonSingleUint16Num {
    uint16_t* num;
};
INIT(TestPtrNonSingleUint16Num,
     struct TestPtrNonSingleUint16Num,
     MEM(struct TestPtrNonSingleUint16Num, Num, uint16_t*, num, NULL));

struct TestPtrNonSingleUint16Bool {
    uint16_t* b;
};
INIT(TestPtrNonSingleUint16Bool,
     struct TestPtrNonSingleUint16Bool,
     MEM(struct TestPtrNonSingleUint16Bool, Bool, uint16_t*, b, NULL));

struct TestPtrNonMultUint16Str {
    uint16_t* str1;
    uint16_t* str2;
    uint16_t* str3;
};
INIT(TestPtrNonMultUint16Str,
     struct TestPtrNonMultUint16Str,
     MEM(struct TestPtrNonMultUint16Str, Str, uint16_t*, str1, NULL),
     MEM(struct TestPtrNonMultUint16Str, Str, uint16_t*, str2, NULL),
     MEM(struct TestPtrNonMultUint16Str, Str, uint16_t*, str3, NULL));

struct TestPtrNonMultUint16Num {
    uint16_t* num1;
    uint16_t* num2;
    uint16_t* num3;
    uint16_t* num4;
    uint16_t* num5;
};
INIT(TestPtrNonMultUint16Num,
     struct TestPtrNonMultUint16Num,
     MEM(struct TestPtrNonMultUint16Num, Num, uint16_t*, num1, NULL),
     MEM(struct TestPtrNonMultUint16Num, Num, uint16_t*, num2, NULL),
     MEM(struct TestPtrNonMultUint16Num, Num, uint16_t*, num3, NULL),
     MEM(struct TestPtrNonMultUint16Num, Num, uint16_t*, num4, NULL),
     MEM(struct TestPtrNonMultUint16Num, Num, uint16_t*, num5, NULL));

struct TestPtrNonMultUint16Bool {
    uint16_t* bool1;
    uint16_t* bool2;
    uint16_t* bool3;
    uint16_t* bool4;
    uint16_t* bool5;
};
INIT(TestPtrNonMultUint16Bool,
     struct TestPtrNonMultUint16Bool,
     MEM(struct TestPtrNonMultUint16Bool, Bool, uint16_t*, bool1, NULL),
     MEM(struct TestPtrNonMultUint16Bool, Bool, uint16_t*, bool2, NULL),
     MEM(struct TestPtrNonMultUint16Bool, Bool, uint16_t*, bool3, NULL),
     MEM(struct TestPtrNonMultUint16Bool, Bool, uint16_t*, bool4, NULL),
     MEM(struct TestPtrNonMultUint16Bool, Bool, uint16_t*, bool5, NULL));

// mult to json
char* test_change_ptr_non_single_uint16_str_to_json(char* exp, char* real);
char* test_change_ptr_non_single_uint16_num_to_json(char* exp, char* real);
char* test_change_ptr_non_single_uint16_bool_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_uint16_str_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_uint16_num_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_uint16_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_uint16_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint16_num(char* json);
int test_change_single_num_json_to_ptr_non_single_uint16_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint16_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint16_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint16_num(char* json);
int test_change_single_null_json_to_ptr_non_single_uint16_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint16_num(char* json);

int test_change_single_str_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_uint16_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint16_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint16_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint16_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint16_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint16_bool(char* json);

#endif
