/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-09 16:20:40
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/char/test_ptr_non_char.h
 */

#ifndef __TEST_PTR_NON_CHAR_H_
#define __TEST_PTR_NON_CHAR_H_

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleCharStr {
    char* str;
};
INIT(TestPtrNonSingleCharStr,
     struct TestPtrNonSingleCharStr,
     MEM(struct TestPtrNonSingleCharStr, Str, char*, str, NULL));

struct TestPtrNonSingleCharNum {
    char *num;
};
INIT(TestPtrNonSingleCharNum,
     struct TestPtrNonSingleCharNum,
     MEM(struct TestPtrNonSingleCharNum, Num, char*, num, NULL));

struct TestPtrNonSingleCharBool {
    char *b;
};
INIT(TestPtrNonSingleCharBool,
     struct TestPtrNonSingleCharBool,
     MEM(struct TestPtrNonSingleCharBool, Bool, char*, b, NULL));

struct TestPtrNonMultCharStr {
    char *str1;
    char *str2;
    char *str3;
};
INIT(TestPtrNonMultCharStr,
     struct TestPtrNonMultCharStr,
     MEM(struct TestPtrNonMultCharStr, Str, char*, str1, NULL),
     MEM(struct TestPtrNonMultCharStr, Str, char*, str2, NULL),
     MEM(struct TestPtrNonMultCharStr, Str, char*, str3, NULL));

struct TestPtrNonMultCharNum {
    char *num1;
    char *num2;
    char *num3;
    char *num4;
    char *num5;
};
INIT(TestPtrNonMultCharNum,
     struct TestPtrNonMultCharNum,
     MEM(struct TestPtrNonMultCharNum, Num, char*, num1, NULL),
     MEM(struct TestPtrNonMultCharNum, Num, char*, num2, NULL),
     MEM(struct TestPtrNonMultCharNum, Num, char*, num3, NULL),
     MEM(struct TestPtrNonMultCharNum, Num, char*, num4, NULL),
     MEM(struct TestPtrNonMultCharNum, Num, char*, num5, NULL));

struct TestPtrNonMultCharBool {
    char *bool1;
    char *bool2;
    char *bool3;
    char *bool4;
    char *bool5;
};
INIT(TestPtrNonMultCharBool,
     struct TestPtrNonMultCharBool,
     MEM(struct TestPtrNonMultCharBool, Bool, char*, bool1, NULL),
     MEM(struct TestPtrNonMultCharBool, Bool, char*, bool2, NULL),
     MEM(struct TestPtrNonMultCharBool, Bool, char*, bool3, NULL),
     MEM(struct TestPtrNonMultCharBool, Bool, char*, bool4, NULL),
     MEM(struct TestPtrNonMultCharBool, Bool, char*, bool5, NULL));

// mult to json
char* test_change_ptr_non_single_char_str_to_json(char* exp, char* real);
char* test_change_ptr_non_single_char_num_to_json(char* exp, char* real);
char* test_change_ptr_non_single_char_bool_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_char_str_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_char_num_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_char_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_non_single_char_str(char* json);
int test_change_mult_str_json_to_ptr_non_single_char_str(char* json);
int test_change_single_num_json_to_ptr_non_single_char_str(char* json);
int test_change_mult_num_json_to_ptr_non_single_char_str(char* json);
int test_change_single_bool_json_to_ptr_non_single_char_str(char* json);
int test_change_mult_bool_json_to_ptr_non_single_char_str(char* json);
int test_change_single_null_json_to_ptr_non_single_char_str(char* json);
int test_change_mult_null_json_to_ptr_non_single_char_str(char* json);

int test_change_single_str_json_to_ptr_non_single_char_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_char_num(char* json);
int test_change_single_num_json_to_ptr_non_single_char_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_char_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_char_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_char_num(char* json);
int test_change_single_null_json_to_ptr_non_single_char_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_char_num(char* json);

int test_change_single_str_json_to_ptr_non_single_char_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_char_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_char_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_char_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_char_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_char_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_char_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_char_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_char_str(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_char_str(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_char_str(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_char_str(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_char_str(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_char_str(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_char_str(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_char_str(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_char_str(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_char_str(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_char_str(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_char_str(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_char_str(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_char_str(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_char_str(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_char_str(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_char_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_char_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_char_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_char_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_char_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_char_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_char_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_char_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_char_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_char_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_char_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_char_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_char_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_char_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_char_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_char_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_char_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_char_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_char_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_char_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_char_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_char_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_char_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_char_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_char_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_char_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_char_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_char_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_char_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_char_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_char_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_char_bool(char* json);

#endif
