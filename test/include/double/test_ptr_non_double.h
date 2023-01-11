/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 14:16:13
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/double/test_ptr_non_double.h
 */

#ifndef __TEST_PTR_NON_DOUBLE_H_
#define __TEST_PTR_NON_DOUBLE_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleDoubleStr {
    double* str;
};
INIT(TestPtrNonSingleDoubleStr,
     struct TestPtrNonSingleDoubleStr,
     MEM(struct TestPtrNonSingleDoubleStr, Str, double*, str, NULL));

struct TestPtrNonSingleDoubleNum {
    double* num;
};
INIT(TestPtrNonSingleDoubleNum,
     struct TestPtrNonSingleDoubleNum,
     MEM(struct TestPtrNonSingleDoubleNum, Num, double*, num, NULL));

struct TestPtrNonSingleDoubleBool {
    double* b;
};
INIT(TestPtrNonSingleDoubleBool,
     struct TestPtrNonSingleDoubleBool,
     MEM(struct TestPtrNonSingleDoubleBool, Bool, double*, b, NULL));

struct TestPtrNonMultDoubleStr {
    double* str1;
    double* str2;
    double* str3;
};
INIT(TestPtrNonMultDoubleStr,
     struct TestPtrNonMultDoubleStr,
     MEM(struct TestPtrNonMultDoubleStr, Str, double*, str1, NULL),
     MEM(struct TestPtrNonMultDoubleStr, Str, double*, str2, NULL),
     MEM(struct TestPtrNonMultDoubleStr, Str, double*, str3, NULL));

struct TestPtrNonMultDoubleNum {
    double* num1;
    double* num2;
    double* num3;
    double* num4;
    double* num5;
};
INIT(TestPtrNonMultDoubleNum,
     struct TestPtrNonMultDoubleNum,
     MEM(struct TestPtrNonMultDoubleNum, Num, double*, num1, NULL),
     MEM(struct TestPtrNonMultDoubleNum, Num, double*, num2, NULL),
     MEM(struct TestPtrNonMultDoubleNum, Num, double*, num3, NULL),
     MEM(struct TestPtrNonMultDoubleNum, Num, double*, num4, NULL),
     MEM(struct TestPtrNonMultDoubleNum, Num, double*, num5, NULL));

struct TestPtrNonMultDoubleBool {
    double* bool1;
    double* bool2;
    double* bool3;
    double* bool4;
    double* bool5;
};
INIT(TestPtrNonMultDoubleBool,
     struct TestPtrNonMultDoubleBool,
     MEM(struct TestPtrNonMultDoubleBool, Bool, double*, bool1, NULL),
     MEM(struct TestPtrNonMultDoubleBool, Bool, double*, bool2, NULL),
     MEM(struct TestPtrNonMultDoubleBool, Bool, double*, bool3, NULL),
     MEM(struct TestPtrNonMultDoubleBool, Bool, double*, bool4, NULL),
     MEM(struct TestPtrNonMultDoubleBool, Bool, double*, bool5, NULL));

// mult to json
char* test_change_ptr_non_single_double_num_to_json(char* exp, char* real);
char* test_change_ptr_non_single_double_bool_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_double_num_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_double_bool_to_json(char* exp, char* real);

// json to mult

int test_change_single_str_json_to_ptr_non_single_double_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_double_num(char* json);
int test_change_single_num_json_to_ptr_non_single_double_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_double_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_double_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_double_num(char* json);
int test_change_single_null_json_to_ptr_non_single_double_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_double_num(char* json);

int test_change_single_str_json_to_ptr_non_single_double_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_double_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_double_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_double_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_double_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_double_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_double_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_double_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_double_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_double_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_double_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_double_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_double_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_double_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_double_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_double_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_double_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_double_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_double_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_double_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_double_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_double_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_double_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_double_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_double_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_double_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_double_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_double_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_double_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_double_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_double_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_double_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_double_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_double_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_double_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_double_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_double_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_double_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_double_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_double_bool(char* json);

#endif
