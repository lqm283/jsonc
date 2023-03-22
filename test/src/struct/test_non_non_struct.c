/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-03-22 14:00:12
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/struct/test_non_non_struct.c
 */

#include "../../include/struct/test_non_non_struct.h"

#include <stdint.h>
#include <string.h>

/*
------------------
复合类型转换为 json
------------------
*/

// 单个 struct 类型转换为 json
int test_change_non_non_single_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"s\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello world\",\"d\":true}}";
    struct TestNonNonSingleStruct s = {{10, 3.14159, "Hello world", 1}};
    ret = JsoncSerialize(real, &s, TestNonNonSingleStruct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 纯 struct 类型转换为 json
int test_change_non_non_mult1_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s1\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},\"s2\":{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}}";
    struct TestNonNonMult1Struct s = {{10, 3.14159, "Hello world", 1},
                                      {33, 2.7173, "Good morning", 0}};
    ret = JsoncSerialize(real, &s, TestNonNonMult1Struct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 混合的 struct 类型转换为 json
int test_change_non_non_multmax_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s1\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},\"s2\":{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},\"a\":10,\"b\":20,\"c\":30.000000}";
    struct TestNonNonMultMaxStruct s = {{10, 3.14159, "Hello world", 1},
                                        {33, 2.7173, "Good morning", 0},
                                        10,
                                        20,
                                        30};
    ret = JsoncSerialize(real, &s, TestNonNonMultMaxStruct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// json 转换为单个 struct 成员的 struct
int test_change_single_str_json_to_non_non_single_struct_one(char* json) {
    int ret = 0;
    struct TestNonNonSingleStruct s;
    ret = JsoncDeserialize(json, &s, TestNonNonSingleStruct);

    if (s.s.a != 10 || s.s.b != 50 || s.s.d != 1) {
        return -1;
    }

    if (strcmp("Hello world", s.s.c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个纯 struct 成员的 struct
int test_change_single_str_json_to_non_non_mult_struct_two(char* json) {
    int ret = 0;
    struct TestNonNonMult1Struct s;
    ret = JsoncDeserialize(json, &s, TestNonNonMult1Struct);

    if (s.s1.a != 10 || s.s1.b != -20 || s.s1.d != 1 || s.s2.a != 33 || s.s2.b != 100 ||
        s.s2.d != 0) {
        return -1;
    }

    if (strcmp("Hello world", s.s1.c) || strcmp("Good morning", s.s2.c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个混合类型成员的 struct
int test_change_single_str_json_to_non_non_mult_struct_max(char* json) {
    int ret = 0;
    struct TestNonNonMultMaxStruct s;
    ret = JsoncDeserialize(json, &s, TestNonNonMultMaxStruct);

    if (s.s1.a != 10 || s.s1.b != -20 || s.s1.d != 1 || s.s2.a != 33 || s.s2.b != 100 ||
        s.s2.d != 0 || s.a != 10 || s.b != 20 || s.c != 30) {
        return -1;
    }

    if (strcmp("Hello world", s.s1.c) || strcmp("Good morning", s.s2.c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}