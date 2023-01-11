/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 12:31:41
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/unsigned char/test_ptr_non_unsignedchar.h
 */

#ifndef __TEST_PTR_NON_UNSIGNED_CHAR_H_
#define __TEST_PTR_NON_UNSIGNED_CHAR_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrNonSingleUnsignedCharStr {
    unsigned char* str;
};
INIT(TestPtrNonSingleUnsignedCharStr,
     struct TestPtrNonSingleUnsignedCharStr,
     MEM(struct TestPtrNonSingleUnsignedCharStr, Str, unsigned char*, str, NULL));

struct TestPtrNonSingleUnsignedCharNum {
    unsigned char* num;
};
INIT(TestPtrNonSingleUnsignedCharNum,
     struct TestPtrNonSingleUnsignedCharNum,
     MEM(struct TestPtrNonSingleUnsignedCharNum, Num, unsigned char*, num, NULL));

struct TestPtrNonSingleUnsignedCharBool {
    unsigned char* b;
};
INIT(TestPtrNonSingleUnsignedCharBool,
     struct TestPtrNonSingleUnsignedCharBool,
     MEM(struct TestPtrNonSingleUnsignedCharBool, Bool, unsigned char*, b, NULL));

struct TestPtrNonMultUnsignedCharStr {
    unsigned char* str1;
    unsigned char* str2;
    unsigned char* str3;
};
INIT(TestPtrNonMultUnsignedCharStr,
     struct TestPtrNonMultUnsignedCharStr,
     MEM(struct TestPtrNonMultUnsignedCharStr, Str, unsigned char*, str1, NULL),
     MEM(struct TestPtrNonMultUnsignedCharStr, Str, unsigned char*, str2, NULL),
     MEM(struct TestPtrNonMultUnsignedCharStr, Str, unsigned char*, str3, NULL));

struct TestPtrNonMultUnsignedCharNum {
    unsigned char* num1;
    unsigned char* num2;
    unsigned char* num3;
    unsigned char* num4;
    unsigned char* num5;
};
INIT(TestPtrNonMultUnsignedCharNum,
     struct TestPtrNonMultUnsignedCharNum,
     MEM(struct TestPtrNonMultUnsignedCharNum, Num, unsigned char*, num1, NULL),
     MEM(struct TestPtrNonMultUnsignedCharNum, Num, unsigned char*, num2, NULL),
     MEM(struct TestPtrNonMultUnsignedCharNum, Num, unsigned char*, num3, NULL),
     MEM(struct TestPtrNonMultUnsignedCharNum, Num, unsigned char*, num4, NULL),
     MEM(struct TestPtrNonMultUnsignedCharNum, Num, unsigned char*, num5, NULL));

struct TestPtrNonMultUnsignedCharBool {
    unsigned char* bool1;
    unsigned char* bool2;
    unsigned char* bool3;
    unsigned char* bool4;
    unsigned char* bool5;
};
INIT(TestPtrNonMultUnsignedCharBool,
     struct TestPtrNonMultUnsignedCharBool,
     MEM(struct TestPtrNonMultUnsignedCharBool, Bool, unsigned char*, bool1, NULL),
     MEM(struct TestPtrNonMultUnsignedCharBool, Bool, unsigned char*, bool2, NULL),
     MEM(struct TestPtrNonMultUnsignedCharBool, Bool, unsigned char*, bool3, NULL),
     MEM(struct TestPtrNonMultUnsignedCharBool, Bool, unsigned char*, bool4, NULL),
     MEM(struct TestPtrNonMultUnsignedCharBool, Bool, unsigned char*, bool5, NULL));

// mult to json
char* test_change_ptr_non_single_unsignedchar_str_to_json(char* exp, char* real);
char* test_change_ptr_non_single_unsignedchar_num_to_json(char* exp, char* real);
char* test_change_ptr_non_single_unsignedchar_bool_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_unsignedchar_str_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_unsignedchar_num_to_json(char* exp, char* real);
char* test_change_ptr_non_mult_unsignedchar_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_mult_str_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_single_num_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_mult_num_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_single_bool_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_mult_bool_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_single_null_json_to_ptr_non_single_unsignedchar_str(char* json);
int test_change_mult_null_json_to_ptr_non_single_unsignedchar_str(char* json);

int test_change_single_str_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_mult_str_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_single_num_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_mult_num_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_single_bool_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_mult_bool_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_single_null_json_to_ptr_non_single_unsignedchar_num(char* json);
int test_change_mult_null_json_to_ptr_non_single_unsignedchar_num(char* json);

int test_change_single_str_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_mult_str_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_single_num_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_mult_num_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_single_bool_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_mult_bool_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_single_null_json_to_ptr_non_single_unsignedchar_bool(char* json);
int test_change_mult_null_json_to_ptr_non_single_unsignedchar_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_unsignedchar_str(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_unsignedchar_str(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_unsignedchar_num(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_unsignedchar_num(char* json);

int test_change_equal_mult_str_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_str_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_str_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_num_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_num_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_more_mult_null_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_less_mult_null_json_to_ptr_non_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_non_mult_unsignedchar_bool(char* json);

#endif
