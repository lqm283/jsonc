/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-08 23:33:54
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/test_non_non_char.h
 */
#ifndef __TEST_NON_NON_CHAR_H_
#define __TEST_NON_NON_CHAR_H_

#include "../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleCharStr {
    char str;
};
INIT(TestNonNonSingleCharStr,
     struct TestNonNonSingleCharStr,
     MEM(struct TestNonNonSingleCharStr, Str, char, str, NULL));

struct TestNonNonSingleCharNum {
    char num;
};
INIT(TestNonNonSingleCharNum,
     struct TestNonNonSingleCharNum,
     MEM(struct TestNonNonSingleCharNum, Num, char, num, NULL));

struct TestNonNonSingleCharBool {
    char b;
};
INIT(TestNonNonSingleCharBool,
     struct TestNonNonSingleCharBool,
     MEM(struct TestNonNonSingleCharBool, Bool, char, b, NULL));

struct TestNonNonMultCharStr {
    char str1;
    char str2;
    char str3;
};
INIT(TestNonNonMultCharStr,
     struct TestNonNonMultCharStr,
     MEM(struct TestNonNonMultCharStr, Str, char, str1, NULL),
     MEM(struct TestNonNonMultCharStr, Str, char, str2, NULL),
     MEM(struct TestNonNonMultCharStr, Str, char, str3, NULL));

struct TestNonNonMultCharNum {
    char num1;
    char num2;
    char num3;
    char num4;
    char num5;
};
INIT(TestNonNonMultCharNum,
     struct TestNonNonMultCharNum,
     MEM(struct TestNonNonMultCharNum, Num, char, num1, NULL),
     MEM(struct TestNonNonMultCharNum, Num, char, num2, NULL),
     MEM(struct TestNonNonMultCharNum, Num, char, num3, NULL),
     MEM(struct TestNonNonMultCharNum, Num, char, num4, NULL),
     MEM(struct TestNonNonMultCharNum, Num, char, num5, NULL));

// mult to json
char* test_change_non_non_single_char_str_to_json(char* exp, char* real);
char* test_change_non_non_single_char_num_to_json(char* exp, char* real);
char* test_change_non_non_single_char_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_char_str_to_json(char* exp, char* real);
char* test_change_non_non_mult_char_num_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_char_str(char* json);
int test_change_mult_str_json_to_non_non_single_char_str(char* json);
int test_change_single_num_json_to_non_non_single_char_str(char* json);
int test_change_mult_num_json_to_non_non_single_char_str(char* json);
int test_change_single_bool_json_to_non_non_single_char_str(char* json);
int test_change_mult_bool_json_to_non_non_single_char_str(char* json);
int test_change_single_null_json_to_non_non_single_char_str(char* json);
int test_change_mult_null_json_to_non_non_single_char_str(char* json);

int test_change_single_str_json_to_non_non_single_char_num(char* json);
int test_change_mult_str_json_to_non_non_single_char_num(char* json);
int test_change_single_num_json_to_non_non_single_char_num(char* json);
int test_change_mult_num_json_to_non_non_single_char_num(char* json);
int test_change_single_bool_json_to_non_non_single_char_num(char* json);
int test_change_mult_bool_json_to_non_non_single_char_num(char* json);
int test_change_single_null_json_to_non_non_single_char_num(char* json);
int test_change_mult_null_json_to_non_non_single_char_num(char* json);
int test_change_single_str_json_to_non_non_single_char_bool(char* json);
int test_change_mult_str_json_to_non_non_single_char_bool(char* json);
int test_change_single_num_json_to_non_non_single_char_bool(char* json);
int test_change_mult_num_json_to_non_non_single_char_bool(char* json);
int test_change_single_bool_json_to_non_non_single_char_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_char_bool(char* json);
int test_change_single_null_json_to_non_non_single_char_bool(char* json);
int test_change_mult_null_json_to_non_non_single_char_bool(char* json);
int test_change_equal_mult_str_json_to_non_non_mult_char_str(char* json);
int test_change_more_mult_str_json_to_non_non_mult_char_str(char* json);
int test_change_less_mult_str_json_to_non_non_mult_char_str(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_char_str(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_char_str(char* json);
int test_change_more_mult_num_json_to_non_non_mult_char_str(char* json);
int test_change_less_mult_num_json_to_non_non_mult_char_str(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_char_str(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_char_str(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_char_str(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_char_str(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_char_str(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_char_str(char* json);
int test_change_more_mult_null_json_to_non_non_mult_char_str(char* json);
int test_change_less_mult_null_json_to_non_non_mult_char_str(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_char_str(char* json);
int test_change_equal_mult_str_json_to_non_non_mult_char_num(char* json);

#endif
