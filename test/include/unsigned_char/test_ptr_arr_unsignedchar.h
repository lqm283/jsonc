/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-03-22 13:49:57
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/unsigned_char/test_ptr_arr_unsignedchar.h
 */

#ifndef __TEST_PTR_ARR_UNSIGNED_CHAR_H_
#define __TEST_PTR_ARR_UNSIGNED_CHAR_H_

#include <stdint.h>

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleUnsignedCharStr {
    unsigned char* str[2];
};
INIT(TestPtrArrSingleUnsignedCharStr,
     struct TestPtrArrSingleUnsignedCharStr,
     MEM(struct TestPtrArrSingleUnsignedCharStr, Str, unsigned char*, str, NULL));

struct TestPtrArrSingleUnsignedCharNum {
    unsigned char* num[2];
};
INIT(TestPtrArrSingleUnsignedCharNum,
     struct TestPtrArrSingleUnsignedCharNum,
     MEM(struct TestPtrArrSingleUnsignedCharNum, Num, unsigned char*, num, NULL));

struct TestPtrArrSingleUnsignedCharBool {
    unsigned char* b[2];
};
INIT(TestPtrArrSingleUnsignedCharBool,
     struct TestPtrArrSingleUnsignedCharBool,
     MEM(struct TestPtrArrSingleUnsignedCharBool, Bool, unsigned char*, b, NULL));

struct TestPtrArrMultUnsignedCharStr {
    unsigned char* str1[2];
    unsigned char* str2[2];
    unsigned char* str3[2];
};
INIT(TestPtrArrMultUnsignedCharStr,
     struct TestPtrArrMultUnsignedCharStr,
     MEM(struct TestPtrArrMultUnsignedCharStr, Str, unsigned char*, str1, NULL),
     MEM(struct TestPtrArrMultUnsignedCharStr, Str, unsigned char*, str2, NULL),
     MEM(struct TestPtrArrMultUnsignedCharStr, Str, unsigned char*, str3, NULL));

struct TestPtrArrMultUnsignedCharNum {
    unsigned char* num1[2];
    unsigned char* num2[2];
    unsigned char* num3[2];
};
INIT(TestPtrArrMultUnsignedCharNum,
     struct TestPtrArrMultUnsignedCharNum,
     MEM(struct TestPtrArrMultUnsignedCharNum, Num, unsigned char*, num1, NULL),
     MEM(struct TestPtrArrMultUnsignedCharNum, Num, unsigned char*, num2, NULL),
     MEM(struct TestPtrArrMultUnsignedCharNum, Num, unsigned char*, num3, NULL));

struct TestPtrArrMultUnsignedCharBool {
    unsigned char* bool1[2];
    unsigned char* bool2[2];
    unsigned char* bool3[2];
};
INIT(TestPtrArrMultUnsignedCharBool,
     struct TestPtrArrMultUnsignedCharBool,
     MEM(struct TestPtrArrMultUnsignedCharBool, Bool, unsigned char*, bool1, NULL),
     MEM(struct TestPtrArrMultUnsignedCharBool, Bool, unsigned char*, bool2, NULL),
     MEM(struct TestPtrArrMultUnsignedCharBool, Bool, unsigned char*, bool3, NULL));

// mult to json
int test_change_ptr_arr_single_unsignedchar_str_to_json(char* exp, char* real);
int test_change_ptr_arr_single_unsignedchar_num_to_json(char* exp, char* real);
int test_change_ptr_arr_single_unsignedchar_bool_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_unsignedchar_str_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_unsignedchar_num_to_json(char* exp, char* real);
int test_change_ptr_arr_mult_unsignedchar_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_mult_str_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_single_num_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_mult_num_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_single_bool_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_single_null_json_to_ptr_arr_single_unsignedchar_str(char* json);
int test_change_mult_null_json_to_ptr_arr_single_unsignedchar_str(char* json);

int test_change_single_str_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_unsignedchar_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_unsignedchar_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_unsignedchar_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_unsignedchar_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json);

#endif
