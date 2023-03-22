/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:01
 * @LastEditTime : 2023-03-22 14:01:10
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/struct/test_ptr_non_struct.c
 */

#include "../../include/struct/test_ptr_non_struct.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
------------------
复合类型转换为 json
------------------
*/

// 单个 struct 类型转换为 json
int test_change_ptr_non_single_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"s\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello world\",\"d\":true}}";
    struct TestPtrNonSingleStruct s;

    s.s = malloc(sizeof(struct BaseStruct));
    s.s->a = 10;
    s.s->b = 3.14159;
    strcpy(s.s->c, "Hello world");
    s.s->d = 1;
    ret = JsoncSerialize(real, &s, TestPtrNonSingleStruct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 纯 struct 类型转换为 json
int test_change_ptr_non_mult1_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s1\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},\"s2\":{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}}";
    struct TestPtrNonMult1Struct s;

    s.s1 = malloc(sizeof(struct BaseStruct));
    s.s2 = malloc(sizeof(struct BaseStruct));
    s.s1->a = 10;
    s.s1->b = 3.14159;
    strcpy(s.s1->c, "Hello world");
    s.s1->d = 1;
    s.s2->a = 33;
    s.s2->b = 2.7173;
    strcpy(s.s2->c, "Good morning");
    s.s2->d = 0;
    ret = JsoncSerialize(real, &s, TestPtrNonMult1Struct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 混合的 struct 类型转换为 json
int test_change_ptr_non_multmax_struct_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"s1\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},\"s2\":{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},\"a\":10,\"b\":20,\"c\":30.000000}";
    struct TestPtrNonMultMaxStruct s;

    s.s1 = malloc(sizeof(struct BaseStruct));
    s.s2 = malloc(sizeof(struct BaseStruct));
    s.a = malloc(sizeof(int));
    s.b = malloc(sizeof(int));
    s.c = malloc(sizeof(float));
    s.s1->a = 10;
    s.s1->b = 3.14159;
    strcpy(s.s1->c, "Hello world");
    s.s1->d = 1;
    s.s2->a = 33;
    s.s2->b = 2.7173;
    strcpy(s.s2->c, "Good morning");
    s.s2->d = 0;
    *s.a = 10;
    *s.b = 20;
    *s.c = 30;

    ret = JsoncSerialize(real, &s, TestPtrNonMultMaxStruct);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// json 转换为单个 struct 成员的 struct
int test_change_single_str_json_to_ptr_non_single_struct_one(char* json) {
    int ret = 0;
    struct TestPtrNonSingleStruct s;
    s.s = malloc(sizeof(struct BaseStruct));
    ret = JsoncDeserialize(json, &s, TestPtrNonSingleStruct);

    if (s.s->a != 10 || s.s->b != 50 || s.s->d != 1) {
        return -1;
    }

    if (strcmp("Hello world", s.s->c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个纯 struct 成员的 struct
int test_change_single_str_json_to_ptr_non_mult_struct_two(char* json) {
    int ret = 0;
    struct TestPtrNonMult1Struct s;
    s.s1 = malloc(sizeof(struct BaseStruct));
    s.s2 = malloc(sizeof(struct BaseStruct));
    ret = JsoncDeserialize(json, &s, TestPtrNonMult1Struct);

    if (s.s1->a != 10 || s.s1->b != -20 || s.s1->d != 1 || s.s2->a != 33 ||
        s.s2->b != 100 || s.s2->d != 0) {
        return -1;
    }

    if (strcmp("Hello world", s.s1->c) || strcmp("Good morning", s.s2->c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个混合类型成员的 struct
int test_change_single_str_json_to_ptr_non_mult_struct_max(char* json) {
    int ret = 0;
    struct TestPtrNonMultMaxStruct s;
    s.s1 = malloc(sizeof(struct BaseStruct));
    s.s2 = malloc(sizeof(struct BaseStruct));
    s.a = malloc(sizeof(int));
    s.b = malloc(sizeof(int));
    s.c = malloc(sizeof(float));
    ret = JsoncDeserialize(json, &s, TestPtrNonMultMaxStruct);

    if (s.s1->a != 10 || s.s1->b != -20 || s.s1->d != 1 || s.s2->a != 33 ||
        s.s2->b != 100 || s.s2->d != 0 || *s.a != 10 || *s.b != 20 || *s.c != 30) {
        return -1;
    }

    if (strcmp("Hello world", s.s1->c) || strcmp("Good morning", s.s2->c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}
