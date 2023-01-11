/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 08:17:08
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int64/test_ptr_non_int64.h
 */

#ifndef __TEST_PTR_NON_INT64_H_
#define __TEST_PTR_NON_INT64_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleInt64Str {
    int64_t* str;
};
INIT(TestPtrNonSingleInt64Str,
     struct TestPtrNonSingleInt64Str,
     MEM(struct TestPtrNonSingleInt64Str, Str, int64_t*, str, NULL));

struct TestPtrNonSingleInt64Num {
    int64_t* num;
};
INIT(TestPtrNonSingleInt64Num,
     struct TestPtrNonSingleInt64Num,
     MEM(struct TestPtrNonSingleInt64Num, Num, int64_t*, num, NULL));

struct TestPtrNonSingleInt64Bool {
    int64_t* b;
};
INIT(TestPtrNonSingleInt64Bool,
     struct TestPtrNonSingleInt64Bool,
     MEM(struct TestPtrNonSingleInt64Bool, Bool, int64_t*, b, NULL));

struct TestPtrNonMultInt64Str {
    int64_t* str1;
    int64_t* str2;
    int64_t* str3;
};
INIT(TestPtrNonMultInt64Str,
     struct TestPtrNonMultInt64Str,
     MEM(struct TestPtrNonMultInt64Str, Str, int64_t*, str1, NULL),
     MEM(struct TestPtrNonMultInt64Str, Str, int64_t*, str2, NULL),
     MEM(struct TestPtrNonMultInt64Str, Str, int64_t*, str3, NULL));

struct TestPtrNonMultInt64Num {
    int64_t* num1;
    int64_t* num2;
    int64_t* num3;
    int64_t* num4;
    int64_t* num5;
};
INIT(TestPtrNonMultInt64Num,
     struct TestPtrNonMultInt64Num,
     MEM(struct TestPtrNonMultInt64Num, Num, int64_t*, num1, NULL),
     MEM(struct TestPtrNonMultInt64Num, Num, int64_t*, num2, NULL),
     MEM(struct TestPtrNonMultInt64Num, Num, int64_t*, num3, NULL),
     MEM(struct TestPtrNonMultInt64Num, Num, int64_t*, num4, NULL),
     MEM(struct TestPtrNonMultInt64Num, Num, int64_t*, num5, NULL));

struct TestPtrNonMultInt64Bool {
    int64_t* bool1;
    int64_t* bool2;
    int64_t* bool3;
    int64_t* bool4;
    int64_t* bool5;
};
INIT(TestPtrNonMultInt64Bool,
     struct TestPtrNonMultInt64Bool,
     MEM(struct TestPtrNonMultInt64Bool, Bool, int64_t*, bool1, NULL),
     MEM(struct TestPtrNonMultInt64Bool, Bool, int64_t*, bool2, NULL),
     MEM(struct TestPtrNonMultInt64Bool, Bool, int64_t*, bool3, NULL),
     MEM(struct TestPtrNonMultInt64Bool, Bool, int64_t*, bool4, NULL),
     MEM(struct TestPtrNonMultInt64Bool, Bool, int64_t*, bool5, NULL));

// mult to json
char* test_change_ptr_non_single_int64_str_to_json(char* exp, char* real);
char* test_change_ptr_non_single_int64_num_to_json(char* exp, char* real);
char* test_change_ptr_non_single_int64_bool_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_int64_str_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_int64_num_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_int64_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_int64_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_int64_num(char* json);
int test_change_single_num_json_to_ptr_non_single_int64_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_int64_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_int64_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_int64_num(char* json);
int test_change_single_null_json_to_ptr_non_single_int64_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_int64_num(char* json);

int test_change_single_str_json_to_ptr_non_single_int64_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_int64_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_int64_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_int64_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_int64_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_int64_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_int64_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_int64_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_int64_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_int64_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_int64_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_int64_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_int64_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_int64_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_int64_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_int64_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_int64_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_int64_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_int64_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_int64_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_int64_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_int64_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_int64_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_int64_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_int64_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_int64_bool(char* json);

#endif
