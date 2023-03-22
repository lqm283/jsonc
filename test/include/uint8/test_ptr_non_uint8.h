/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-10 20:20:09
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint8/test_ptr_non_uint8.h
 */

#ifndef __TEST_PTR_NON_UINT8_H_
#define __TEST_PTR_NON_UINT8_H_

#include "../../../jsonc.h"
#include <stdint.h>

// char 单成员字符串
struct TestPtrNonSingleUint8Str {
    uint8_t* str;
};
INIT(TestPtrNonSingleUint8Str,
     struct TestPtrNonSingleUint8Str,
     MEM(struct TestPtrNonSingleUint8Str, Str, uint8_t*, str, NULL));

struct TestPtrNonSingleUint8Num {
    uint8_t* num;
};
INIT(TestPtrNonSingleUint8Num,
     struct TestPtrNonSingleUint8Num,
     MEM(struct TestPtrNonSingleUint8Num, Num, uint8_t*, num, NULL));

struct TestPtrNonSingleUint8Bool {
    uint8_t* b;
};
INIT(TestPtrNonSingleUint8Bool,
     struct TestPtrNonSingleUint8Bool,
     MEM(struct TestPtrNonSingleUint8Bool, Bool, uint8_t*, b, NULL));

struct TestPtrNonMultUint8Str {
    uint8_t* str1;
    uint8_t* str2;
    uint8_t* str3;
};
INIT(TestPtrNonMultUint8Str,
     struct TestPtrNonMultUint8Str,
     MEM(struct TestPtrNonMultUint8Str, Str, uint8_t*, str1, NULL),
     MEM(struct TestPtrNonMultUint8Str, Str, uint8_t*, str2, NULL),
     MEM(struct TestPtrNonMultUint8Str, Str, uint8_t*, str3, NULL));

struct TestPtrNonMultUint8Num {
    uint8_t* num1;
    uint8_t* num2;
    uint8_t* num3;
    uint8_t* num4;
    uint8_t* num5;
};
INIT(TestPtrNonMultUint8Num,
     struct TestPtrNonMultUint8Num,
     MEM(struct TestPtrNonMultUint8Num, Num, uint8_t*, num1, NULL),
     MEM(struct TestPtrNonMultUint8Num, Num, uint8_t*, num2, NULL),
     MEM(struct TestPtrNonMultUint8Num, Num, uint8_t*, num3, NULL),
     MEM(struct TestPtrNonMultUint8Num, Num, uint8_t*, num4, NULL),
     MEM(struct TestPtrNonMultUint8Num, Num, uint8_t*, num5, NULL));

struct TestPtrNonMultUint8Bool {
    uint8_t* bool1;
    uint8_t* bool2;
    uint8_t* bool3;
    uint8_t* bool4;
    uint8_t* bool5;
};
INIT(TestPtrNonMultUint8Bool,
     struct TestPtrNonMultUint8Bool,
     MEM(struct TestPtrNonMultUint8Bool, Bool, uint8_t*, bool1, NULL),
     MEM(struct TestPtrNonMultUint8Bool, Bool, uint8_t*, bool2, NULL),
     MEM(struct TestPtrNonMultUint8Bool, Bool, uint8_t*, bool3, NULL),
     MEM(struct TestPtrNonMultUint8Bool, Bool, uint8_t*, bool4, NULL),
     MEM(struct TestPtrNonMultUint8Bool, Bool, uint8_t*, bool5, NULL));

// mult to json
int test_change_ptr_non_single_uint8_str_to_json(char* exp, char* real);
int test_change_ptr_non_single_uint8_num_to_json(char* exp, char* real);
int test_change_ptr_non_single_uint8_bool_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint8_str_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint8_num_to_json(char* exp, char* real);
int test_change_ptr_non_mult_uint8_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_non_single_uint8_str(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint8_str(char* json);
int test_change_single_num_json_to_ptr_non_single_uint8_str(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint8_str(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint8_str(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint8_str(char* json);
int test_change_single_null_json_to_ptr_non_single_uint8_str(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint8_str(char* json);

int test_change_single_str_json_to_ptr_non_single_uint8_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint8_num(char* json);
int test_change_single_num_json_to_ptr_non_single_uint8_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint8_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint8_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint8_num(char* json);
int test_change_single_null_json_to_ptr_non_single_uint8_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint8_num(char* json);

int test_change_single_str_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_uint8_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_uint8_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint8_str(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint8_str(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint8_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint8_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_uint8_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_uint8_bool(char* json);

#endif
