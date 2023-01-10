/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-10 15:31:37
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/char/test_ptr_arr_char.h
 */

#ifndef __TEST_PTR_ARR_CHAR_H_
#define __TEST_PTR_ARR_CHAR_H_

#include "../../../jsonc.h"

// char 单成员字符串
struct TestPtrArrSingleCharStr {
    char* str[2];
};
INIT(TestPtrArrSingleCharStr,
     struct TestPtrArrSingleCharStr,
     MEM(struct TestPtrArrSingleCharStr, Str, char*, str, NULL));

struct TestPtrArrSingleCharNum {
    char* num[2];
};
INIT(TestPtrArrSingleCharNum,
     struct TestPtrArrSingleCharNum,
     MEM(struct TestPtrArrSingleCharNum, Num, char*, num, NULL));

struct TestPtrArrSingleCharBool {
    char* b[2];
};
INIT(TestPtrArrSingleCharBool,
     struct TestPtrArrSingleCharBool,
     MEM(struct TestPtrArrSingleCharBool, Bool, char*, b, NULL));

struct TestPtrArrMultCharStr {
    char* str1[2];
    char* str2[2];
    char* str3[2];
};
INIT(TestPtrArrMultCharStr,
     struct TestPtrArrMultCharStr,
     MEM(struct TestPtrArrMultCharStr, Str, char*, str1, NULL),
     MEM(struct TestPtrArrMultCharStr, Str, char*, str2, NULL),
     MEM(struct TestPtrArrMultCharStr, Str, char*, str3, NULL));

struct TestPtrArrMultCharNum {
    char* num1[2];
    char* num2[2];
    char* num3[2];
};
INIT(TestPtrArrMultCharNum,
     struct TestPtrArrMultCharNum,
     MEM(struct TestPtrArrMultCharNum, Num, char*, num1, NULL),
     MEM(struct TestPtrArrMultCharNum, Num, char*, num2, NULL),
     MEM(struct TestPtrArrMultCharNum, Num, char*, num3, NULL));

struct TestPtrArrMultCharBool {
    char* bool1[2];
    char* bool2[2];
    char* bool3[2];
};
INIT(TestPtrArrMultCharBool,
     struct TestPtrArrMultCharBool,
     MEM(struct TestPtrArrMultCharBool, Bool, char*, bool1, NULL),
     MEM(struct TestPtrArrMultCharBool, Bool, char*, bool2, NULL),
     MEM(struct TestPtrArrMultCharBool, Bool, char*, bool3, NULL));

// mult to json
char* test_change_ptr_arr_single_char_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_char_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_single_char_bool_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_char_str_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_char_num_to_json(char* exp, char* real);
char* test_change_ptr_arr_mult_char_bool_to_json(char* exp, char* real);

// json to mult
int test_change_single_str_json_to_ptr_arr_single_char_str(char* json);
int test_change_mult_str_json_to_ptr_arr_single_char_str(char* json);
int test_change_single_num_json_to_ptr_arr_single_char_str(char* json);
int test_change_mult_num_json_to_ptr_arr_single_char_str(char* json);
int test_change_single_bool_json_to_ptr_arr_single_char_str(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_char_str(char* json);
int test_change_single_null_json_to_ptr_arr_single_char_str(char* json);
int test_change_mult_null_json_to_ptr_arr_single_char_str(char* json);

int test_change_single_str_json_to_ptr_arr_single_char_num(char* json);
int test_change_mult_str_json_to_ptr_arr_single_char_num(char* json);
int test_change_single_num_json_to_ptr_arr_single_char_num(char* json);
int test_change_mult_num_json_to_ptr_arr_single_char_num(char* json);
int test_change_single_bool_json_to_ptr_arr_single_char_num(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_char_num(char* json);
int test_change_single_null_json_to_ptr_arr_single_char_num(char* json);
int test_change_mult_null_json_to_ptr_arr_single_char_num(char* json);

int test_change_single_str_json_to_ptr_arr_single_char_bool(char* json);
int test_change_mult_str_json_to_ptr_arr_single_char_bool(char* json);
int test_change_single_num_json_to_ptr_arr_single_char_bool(char* json);
int test_change_mult_num_json_to_ptr_arr_single_char_bool(char* json);
int test_change_single_bool_json_to_ptr_arr_single_char_bool(char* json);
int test_change_mult_bool_json_to_ptr_arr_single_char_bool(char* json);
int test_change_single_null_json_to_ptr_arr_single_char_bool(char* json);
int test_change_mult_null_json_to_ptr_arr_single_char_bool(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_char_str(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_char_str(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_char_str(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_char_str(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_char_str(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_char_str(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_char_str(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_char_str(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_char_str(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_char_str(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_char_str(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_char_str(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_char_str(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_char_str(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_char_str(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_char_str(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_char_num(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_char_num(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_char_num(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_char_num(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_char_num(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_char_num(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_char_num(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_char_num(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_char_num(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_char_num(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_char_num(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_char_num(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_char_num(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_char_num(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_char_num(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_char_num(char* json);

int test_change_equal_mult_str_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_more_mult_str_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_less_mult_str_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_diff_mult_str_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_equal_mult_num_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_more_mult_num_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_less_mult_num_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_diff_mult_num_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_equal_mult_bool_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_more_mult_bool_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_less_mult_bool_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_diff_mult_bool_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_equal_mult_null_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_more_mult_null_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_less_mult_null_json_to_ptr_arr_mult_char_bool(char* json);
int test_change_diff_mult_null_json_to_ptr_arr_mult_char_bool(char* json);

#endif
