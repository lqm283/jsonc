/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 12:31:35
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/unsigned char/test_non_non_unsignedchar.h
 */
#ifndef __TEST_NON_NON_UNSIGNED_CHAR_H_
#define __TEST_NON_NON_UNSIGNED_CHAR_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestNonNonSingleUnsignedCharStr {
    unsigned char str;
};
INIT(TestNonNonSingleUnsignedCharStr,
     struct TestNonNonSingleUnsignedCharStr,
     MEM(struct TestNonNonSingleUnsignedCharStr, Str, unsigned char, str, NULL));

struct TestNonNonSingleUnsignedCharNum {
    unsigned char num;
};
INIT(TestNonNonSingleUnsignedCharNum,
     struct TestNonNonSingleUnsignedCharNum,
     MEM(struct TestNonNonSingleUnsignedCharNum, Num, unsigned char, num, NULL));

struct TestNonNonSingleUnsignedCharBool {
    unsigned char b;
};
INIT(TestNonNonSingleUnsignedCharBool,
     struct TestNonNonSingleUnsignedCharBool,
     MEM(struct TestNonNonSingleUnsignedCharBool, Bool, unsigned char, b, NULL));

struct TestNonNonMultUnsignedCharStr {
    unsigned char str1;
    unsigned char str2;
    unsigned char str3;
};
INIT(TestNonNonMultUnsignedCharStr,
     struct TestNonNonMultUnsignedCharStr,
     MEM(struct TestNonNonMultUnsignedCharStr, Str, unsigned char, str1, NULL),
     MEM(struct TestNonNonMultUnsignedCharStr, Str, unsigned char, str2, NULL),
     MEM(struct TestNonNonMultUnsignedCharStr, Str, unsigned char, str3, NULL));

struct TestNonNonMultUnsignedCharNum {
    unsigned char num1;
    unsigned char num2;
    unsigned char num3;
    unsigned char num4;
    unsigned char num5;
};
INIT(TestNonNonMultUnsignedCharNum,
     struct TestNonNonMultUnsignedCharNum,
     MEM(struct TestNonNonMultUnsignedCharNum, Num, unsigned char, num1, NULL),
     MEM(struct TestNonNonMultUnsignedCharNum, Num, unsigned char, num2, NULL),
     MEM(struct TestNonNonMultUnsignedCharNum, Num, unsigned char, num3, NULL),
     MEM(struct TestNonNonMultUnsignedCharNum, Num, unsigned char, num4, NULL),
     MEM(struct TestNonNonMultUnsignedCharNum, Num, unsigned char, num5, NULL));

struct TestNonNonMultUnsignedCharBool {
    unsigned char bool1;
    unsigned char bool2;
    unsigned char bool3;
    unsigned char bool4;
    unsigned char bool5;
};
INIT(TestNonNonMultUnsignedCharBool,
     struct TestNonNonMultUnsignedCharBool,
     MEM(struct TestNonNonMultUnsignedCharBool, Bool, unsigned char, bool1, NULL),
     MEM(struct TestNonNonMultUnsignedCharBool, Bool, unsigned char, bool2, NULL),
     MEM(struct TestNonNonMultUnsignedCharBool, Bool, unsigned char, bool3, NULL),
     MEM(struct TestNonNonMultUnsignedCharBool, Bool, unsigned char, bool4, NULL),
     MEM(struct TestNonNonMultUnsignedCharBool, Bool, unsigned char, bool5, NULL));

// mult to json
char* test_change_non_non_single_unsignedchar_str_to_json(char* exp, char* real);
char* test_change_non_non_single_unsignedchar_num_to_json(char* exp, char* real);
char* test_change_non_non_single_unsignedchar_bool_to_json(char* exp, char* real);
char* test_change_non_non_mult_unsignedchar_str_to_json(char* exp, char* real);
char* test_change_non_non_mult_unsignedchar_num_to_json(char* exp, char* real);
char* test_change_non_non_mult_unsignedchar_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_mult_str_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_single_num_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_mult_num_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_single_bool_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_mult_bool_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_single_null_json_to_non_non_single_unsignedchar_str(char* json);
int test_change_mult_null_json_to_non_non_single_unsignedchar_str(char* json);

int test_change_single_str_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_mult_str_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_single_num_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_mult_num_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_single_bool_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_mult_bool_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_single_null_json_to_non_non_single_unsignedchar_num(char* json);
int test_change_mult_null_json_to_non_non_single_unsignedchar_num(char* json);

int test_change_single_str_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_mult_str_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_single_num_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_mult_num_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_single_bool_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_mult_bool_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_single_null_json_to_non_non_single_unsignedchar_bool(char* json);
int test_change_mult_null_json_to_non_non_single_unsignedchar_bool(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_str_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_str_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_num_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_num_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_null_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_null_json_to_non_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_unsignedchar_str(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_str_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_str_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_num_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_num_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_null_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_null_json_to_non_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_unsignedchar_num(char* json);

int test_change_equal_mult_str_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_str_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_str_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_str_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_num_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_num_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_num_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_num_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_bool_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_bool_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_bool_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_bool_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_null_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_null_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_null_json_to_non_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_null_json_to_non_non_mult_unsignedchar_bool(char* json);

#endif
