/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-01-07 17:40:44
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/test_non_non_char.c
 */

#include "../include/test_non_non_char.h"

#include <string.h>

// 单成员的 char 类型转换为 str 类型的 json
char* test_change_non_non_single_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str\":\"a\"}";
    struct TestNonNonSingleCharStr str;
    str.str = 'a';
    ret = JsoncSerialize(real, &str, TestNonNonSingleCharStr);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单元素的 str 类型的 json 转换为单成员的 char 类型
int test_chang_single_str_json_to_non_non_single_char_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleCharStr);
    if (ret) {
        return ret;
    }
    if (str.str != 's') {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为单成员的 char 类型
int test_chang_mult_str_json_to_non_non_single_char_str(char* json) {
    return test_chang_single_str_json_to_non_non_single_char_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_chang_single_num_json_to_non_non_single_char_str(char* json) {
    return test_chang_single_str_json_to_non_non_single_char_str(json);
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_chang_mult_num_json_to_non_non_single_char_str(char* json) {
    return test_chang_single_str_json_to_non_non_single_char_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_chang_single_bool_json_to_non_non_single_char_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleCharStr);
    if (ret) {
        return ret;
    }
    if (str.str != 't') {
        return 1;
    }
    return ret;
}

// 单成员的 Num类型的 char 类型转换为 json
char* test_change_non_non_single_char_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"num\":10}";
    struct TestNonNonSingleCharNum num;
    num.num = 10;
    ret = JsoncSerialize(real, &num, TestNonNonSingleCharNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单元素的 Num 类型的 json 转换为单成员的 char 类型
int test_chang_single_json_to_non_non_single_char_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素的 json 转换为保存 Num 类型的单成员 char
int test_chang_mult_json_to_non_non_single_char_num(char* json) {
    return test_chang_single_json_to_non_non_single_char_num(json);
}
