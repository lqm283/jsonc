/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-03-22 13:46:27
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int16/test_ptr_non_int16.h
 */

#ifndef __TEST_PTR_NON_INT16_H_
#define __TEST_PTR_NON_INT16_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleInt16Str {
    int16_t* str;
};
INIT(TestPtrNonSingleInt16Str,
     struct TestPtrNonSingleInt16Str,
     MEM(struct TestPtrNonSingleInt16Str, Str, int16_t*, str, NULL));

struct TestPtrNonSingleInt16Num {
    int16_t* num;
};
INIT(TestPtrNonSingleInt16Num,
     struct TestPtrNonSingleInt16Num,
     MEM(struct TestPtrNonSingleInt16Num, Num, int16_t*, num, NULL));

struct TestPtrNonSingleInt16Bool {
    int16_t* b;
};
INIT(TestPtrNonSingleInt16Bool,
     struct TestPtrNonSingleInt16Bool,
     MEM(struct TestPtrNonSingleInt16Bool, Bool, int16_t*, b, NULL));

struct TestPtrNonMultInt16Str {
    int16_t* str1;
    int16_t* str2;
    int16_t* str3;
};
INIT(TestPtrNonMultInt16Str,
     struct TestPtrNonMultInt16Str,
     MEM(struct TestPtrNonMultInt16Str, Str, int16_t*, str1, NULL),
     MEM(struct TestPtrNonMultInt16Str, Str, int16_t*, str2, NULL),
     MEM(struct TestPtrNonMultInt16Str, Str, int16_t*, str3, NULL));

struct TestPtrNonMultInt16Num {
    int16_t* num1;
    int16_t* num2;
    int16_t* num3;
    int16_t* num4;
    int16_t* num5;
};
INIT(TestPtrNonMultInt16Num,
     struct TestPtrNonMultInt16Num,
     MEM(struct TestPtrNonMultInt16Num, Num, int16_t*, num1, NULL),
     MEM(struct TestPtrNonMultInt16Num, Num, int16_t*, num2, NULL),
     MEM(struct TestPtrNonMultInt16Num, Num, int16_t*, num3, NULL),
     MEM(struct TestPtrNonMultInt16Num, Num, int16_t*, num4, NULL),
     MEM(struct TestPtrNonMultInt16Num, Num, int16_t*, num5, NULL));

struct TestPtrNonMultInt16Bool {
    int16_t* bool1;
    int16_t* bool2;
    int16_t* bool3;
    int16_t* bool4;
    int16_t* bool5;
};
INIT(TestPtrNonMultInt16Bool,
     struct TestPtrNonMultInt16Bool,
     MEM(struct TestPtrNonMultInt16Bool, Bool, int16_t*, bool1, NULL),
     MEM(struct TestPtrNonMultInt16Bool, Bool, int16_t*, bool2, NULL),
     MEM(struct TestPtrNonMultInt16Bool, Bool, int16_t*, bool3, NULL),
     MEM(struct TestPtrNonMultInt16Bool, Bool, int16_t*, bool4, NULL),
     MEM(struct TestPtrNonMultInt16Bool, Bool, int16_t*, bool5, NULL));

// mult to json
int test_change_ptr_non_single_int16_str_to_json(char* exp, char* real);
int test_change_ptr_non_single_int16_num_to_json(char* exp, char* real);
int test_change_ptr_non_single_int16_bool_to_json(char* exp, char* real);
int test_change_ptr_non_mult_int16_str_to_json(char* exp, char* real);
int test_change_ptr_non_mult_int16_num_to_json(char* exp, char* real);
int test_change_ptr_non_mult_int16_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_int16_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_int16_num(char* json);
int test_change_single_num_json_to_ptr_non_single_int16_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_int16_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_int16_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_int16_num(char* json);
int test_change_single_null_json_to_ptr_non_single_int16_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_int16_num(char* json);

int test_change_single_str_json_to_ptr_non_single_int16_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_int16_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_int16_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_int16_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_int16_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_int16_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_int16_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_int16_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_int16_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_int16_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_int16_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_int16_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_int16_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_int16_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_int16_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_int16_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_int16_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_int16_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_int16_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_int16_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_int16_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_int16_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_int16_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_int16_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_int16_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_int16_bool(char* json);

#endif
