/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-08 20:29:13
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

// mult to json
char* test_change_non_non_single_char_str_to_json(char* exp, char* real);
char* test_change_non_non_single_char_num_to_json(char* exp, char* real);
char* test_change_non_non_single_char_bool_to_json(char* exp, char* real);

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

#endif
