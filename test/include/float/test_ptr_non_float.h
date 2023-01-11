/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 10:23:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/float/test_ptr_non_float.h
 */

#ifndef __TEST_PTR_NON_FLOAT_H_
#define __TEST_PTR_NON_FLOAT_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleFloatStr {
    float* str;
};
INIT(TestPtrNonSingleFloatStr,
     struct TestPtrNonSingleFloatStr,
     MEM(struct TestPtrNonSingleFloatStr, Str, float*, str, NULL));

struct TestPtrNonSingleFloatNum {
    float* num;
};
INIT(TestPtrNonSingleFloatNum,
     struct TestPtrNonSingleFloatNum,
     MEM(struct TestPtrNonSingleFloatNum, Num, float*, num, NULL));

struct TestPtrNonSingleFloatBool {
    float* b;
};
INIT(TestPtrNonSingleFloatBool,
     struct TestPtrNonSingleFloatBool,
     MEM(struct TestPtrNonSingleFloatBool, Bool, float*, b, NULL));

struct TestPtrNonMultFloatStr {
    float* str1;
    float* str2;
    float* str3;
};
INIT(TestPtrNonMultFloatStr,
     struct TestPtrNonMultFloatStr,
     MEM(struct TestPtrNonMultFloatStr, Str, float*, str1, NULL),
     MEM(struct TestPtrNonMultFloatStr, Str, float*, str2, NULL),
     MEM(struct TestPtrNonMultFloatStr, Str, float*, str3, NULL));

struct TestPtrNonMultFloatNum {
    float* num1;
    float* num2;
    float* num3;
    float* num4;
    float* num5;
};
INIT(TestPtrNonMultFloatNum,
     struct TestPtrNonMultFloatNum,
     MEM(struct TestPtrNonMultFloatNum, Num, float*, num1, NULL),
     MEM(struct TestPtrNonMultFloatNum, Num, float*, num2, NULL),
     MEM(struct TestPtrNonMultFloatNum, Num, float*, num3, NULL),
     MEM(struct TestPtrNonMultFloatNum, Num, float*, num4, NULL),
     MEM(struct TestPtrNonMultFloatNum, Num, float*, num5, NULL));

struct TestPtrNonMultFloatBool {
    float* bool1;
    float* bool2;
    float* bool3;
    float* bool4;
    float* bool5;
};
INIT(TestPtrNonMultFloatBool,
     struct TestPtrNonMultFloatBool,
     MEM(struct TestPtrNonMultFloatBool, Bool, float*, bool1, NULL),
     MEM(struct TestPtrNonMultFloatBool, Bool, float*, bool2, NULL),
     MEM(struct TestPtrNonMultFloatBool, Bool, float*, bool3, NULL),
     MEM(struct TestPtrNonMultFloatBool, Bool, float*, bool4, NULL),
     MEM(struct TestPtrNonMultFloatBool, Bool, float*, bool5, NULL));

// mult to json
char* test_change_ptr_non_single_float_num_to_json(char* exp, char* real);
char* test_change_ptr_non_single_float_bool_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_float_num_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_float_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_float_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_float_num(char* json);
int test_change_single_num_json_to_ptr_non_single_float_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_float_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_float_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_float_num(char* json);
int test_change_single_null_json_to_ptr_non_single_float_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_float_num(char* json);

int test_change_single_str_json_to_ptr_non_single_float_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_float_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_float_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_float_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_float_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_float_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_float_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_float_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_float_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_float_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_float_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_float_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_float_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_float_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_float_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_float_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_float_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_float_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_float_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_float_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_float_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_float_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_float_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_float_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_float_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_float_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_float_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_float_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_float_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_float_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_float_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_float_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_float_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_float_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_float_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_float_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_float_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_float_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_float_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_float_bool(char* json);

#endif
