/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 08:17:08
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int32/test_ptr_non_int32.h
 */

#ifndef __TEST_PTR_NON_INT32_H_
#define __TEST_PTR_NON_INT32_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleInt32Str {
    int32_t* str;
};
INIT(TestPtrNonSingleInt32Str,
     struct TestPtrNonSingleInt32Str,
     MEM(struct TestPtrNonSingleInt32Str, Str, int32_t*, str, NULL));

struct TestPtrNonSingleInt32Num {
    int32_t* num;
};
INIT(TestPtrNonSingleInt32Num,
     struct TestPtrNonSingleInt32Num,
     MEM(struct TestPtrNonSingleInt32Num, Num, int32_t*, num, NULL));

struct TestPtrNonSingleInt32Bool {
    int32_t* b;
};
INIT(TestPtrNonSingleInt32Bool,
     struct TestPtrNonSingleInt32Bool,
     MEM(struct TestPtrNonSingleInt32Bool, Bool, int32_t*, b, NULL));

struct TestPtrNonMultInt32Str {
    int32_t* str1;
    int32_t* str2;
    int32_t* str3;
};
INIT(TestPtrNonMultInt32Str,
     struct TestPtrNonMultInt32Str,
     MEM(struct TestPtrNonMultInt32Str, Str, int32_t*, str1, NULL),
     MEM(struct TestPtrNonMultInt32Str, Str, int32_t*, str2, NULL),
     MEM(struct TestPtrNonMultInt32Str, Str, int32_t*, str3, NULL));

struct TestPtrNonMultInt32Num {
    int32_t* num1;
    int32_t* num2;
    int32_t* num3;
    int32_t* num4;
    int32_t* num5;
};
INIT(TestPtrNonMultInt32Num,
     struct TestPtrNonMultInt32Num,
     MEM(struct TestPtrNonMultInt32Num, Num, int32_t*, num1, NULL),
     MEM(struct TestPtrNonMultInt32Num, Num, int32_t*, num2, NULL),
     MEM(struct TestPtrNonMultInt32Num, Num, int32_t*, num3, NULL),
     MEM(struct TestPtrNonMultInt32Num, Num, int32_t*, num4, NULL),
     MEM(struct TestPtrNonMultInt32Num, Num, int32_t*, num5, NULL));

struct TestPtrNonMultInt32Bool {
    int32_t* bool1;
    int32_t* bool2;
    int32_t* bool3;
    int32_t* bool4;
    int32_t* bool5;
};
INIT(TestPtrNonMultInt32Bool,
     struct TestPtrNonMultInt32Bool,
     MEM(struct TestPtrNonMultInt32Bool, Bool, int32_t*, bool1, NULL),
     MEM(struct TestPtrNonMultInt32Bool, Bool, int32_t*, bool2, NULL),
     MEM(struct TestPtrNonMultInt32Bool, Bool, int32_t*, bool3, NULL),
     MEM(struct TestPtrNonMultInt32Bool, Bool, int32_t*, bool4, NULL),
     MEM(struct TestPtrNonMultInt32Bool, Bool, int32_t*, bool5, NULL));

// mult to json
int test_change_ptr_non_single_int32_str_to_json(char* exp, char* real);
int test_change_ptr_non_single_int32_num_to_json(char* exp, char* real);
int test_change_ptr_non_single_int32_bool_to_json(char* exp, char* real);
int test_change_ptr_non_mult_int32_str_to_json(char* exp, char* real);
int test_change_ptr_non_mult_int32_num_to_json(char* exp, char* real);
int test_change_ptr_non_mult_int32_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_int32_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_int32_num(char* json);
int test_change_single_num_json_to_ptr_non_single_int32_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_int32_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_int32_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_int32_num(char* json);
int test_change_single_null_json_to_ptr_non_single_int32_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_int32_num(char* json);

int test_change_single_str_json_to_ptr_non_single_int32_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_int32_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_int32_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_int32_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_int32_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_int32_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_int32_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_int32_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_int32_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_int32_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_int32_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_int32_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_int32_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_int32_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_int32_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_int32_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_int32_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_int32_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_int32_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_int32_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_int32_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_int32_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_int32_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_int32_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_int32_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_int32_bool(char* json);

#endif
