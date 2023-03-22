/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-03-22 13:59:47
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/struct/test_non_arr_struct.c
 */

#include "../../include/struct/test_non_arr_struct.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
------------------
复合类型转换为 json
------------------
*/

// 单个 struct 类型转换为 json
int test_change_non_arr_single_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s\":[{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true}]}";
    struct TestNonArrSingleStruct s = {
        {{10, 3.14159, "Hello world", 1}, {10, 3.14159, "Hello world", 1}}};
    ret = JsoncSerialize(real, &s, TestNonArrSingleStruct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 纯 struct 类型转换为 json
int test_change_non_arr_mult1_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s1\":[{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true}],\"s2\":[{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}]}";
    struct TestNonArrMult1Struct s = {
        {{10, 3.14159, "Hello world", 1}, {10, 3.14159, "Hello world", 1}},
        {{33, 2.7173, "Good morning", 0}, {33, 2.7173, "Good morning", 0}}};
    ret = JsoncSerialize(real, &s, TestNonArrMult1Struct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 混合的 struct 类型转换为 json
int test_change_non_arr_multmax_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s1\":[{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true}],\"s2\":[{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}],\"a\":[10,10],\"b\":[20,20],\"c\":[30.000000,30.000000]"
        "}";
    struct TestNonArrMultMaxStruct s = {
        {{10, 3.14159, "Hello world", 1}, {10, 3.14159, "Hello world", 1}},
        {{33, 2.7173, "Good morning", 0}, {33, 2.7173, "Good morning", 0}},
        {10, 10},
        {20, 20},
        {30, 30}};
    ret = JsoncSerialize(real, &s, TestNonArrMultMaxStruct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// json 转换为单个 struct 成员的 struct
int test_change_single_str_json_to_non_arr_single_struct_one(char* json) {
    int ret = 0;
    struct TestNonArrSingleStruct s;
    ret = JsoncDeserialize(json, &s, TestNonArrSingleStruct);

    if (s.s[0].a != 10 || s.s[0].b != 50 || s.s[0].d != 1 || s.s[1].a != 10 ||
        s.s[1].b != 50 || s.s[1].d != 1) {
        return -1;
    }

    if (strcmp("Hello world", s.s[0].c) || strcmp("Hello world", s.s[1].c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个纯 struct 成员的 struct
int test_change_single_str_json_to_non_arr_mult_struct_two(char* json) {
    int ret = 0;
    struct TestNonArrMult1Struct s;
    ret = JsoncDeserialize(json, &s, TestNonArrMult1Struct);

    if (s.s1[0].a != 10 || s.s1[0].b != -20 || s.s1[0].d != 1 || s.s2[0].a != 33 ||
        s.s2[0].b != 100 || s.s2[0].d != 0 || s.s1[1].a != 10 || s.s1[1].b != -20 ||
        s.s1[1].d != 1 || s.s2[1].a != 33 || s.s2[1].b != 100 || s.s2[1].d != 0) {
        return -1;
    }

    if (strcmp("Hello world", s.s1[0].c) || strcmp("Good morning", s.s2[1].c) ||
        strcmp("Hello world", s.s1[1].c) || strcmp("Good morning", s.s2[0].c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个混合类型成员的 struct
int test_change_single_str_json_to_non_arr_mult_struct_max(char* json) {
    int ret = 0;
    struct TestNonArrMultMaxStruct s;
    ret = JsoncDeserialize(json, &s, TestNonArrMultMaxStruct);

    if (s.s1[0].a != 10 || s.s1[0].b != -20 || s.s1[0].d != 1 || s.s2[0].a != 33 ||
        s.s2[0].b != 100 || s.s2[0].d != 0 || s.a[0] != 10 || s.b[0] != 20 ||
        s.c[0] != 30 || s.s1[1].a != 10 || s.s1[1].b != -20 || s.s1[1].d != 1 ||
        s.s2[1].a != 33 || s.s2[1].b != 100 || s.s2[1].d != 0 || s.a[1] != 10 ||
        s.b[1] != 20 || s.c[1] != 30) {
        return -1;
    }

    if (strcmp("Hello world", s.s1[0].c) || strcmp("Good morning", s.s2[1].c) ||
        strcmp("Hello world", s.s1[1].c) || strcmp("Good morning", s.s2[0].c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}