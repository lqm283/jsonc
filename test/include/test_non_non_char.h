/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-06 14:43:00
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

char* test_change_non_non_single_char_str_to_json(char* exp, char* real);
char* test_change_non_non_single_char_num_to_json(char* exp, char* real);

int test_chang_single_json_to_non_non_single_char_str(char* json);
int test_chang_mult_json_to_non_non_single_char_str(char* json);
int test_chang_single_json_to_non_non_single_char_num(char* json);

#endif
