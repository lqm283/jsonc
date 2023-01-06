/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-01-06 13:42:47
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
int test_chang_single_json_to_non_non_single_char_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleCharStr);
    if (ret) {
        return ret;
    }
    if (str.str != 's') {
        return -1;
    }
    return ret;
}
