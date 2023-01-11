/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:10:48
 * @LastEditTime : 2023-01-11 20:22:27
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/struct/test_ptr_arr_struct.c
 */

#include "../../include/struct/test_ptr_arr_struct.h"

#include <bits/stdint-uintn.h>
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
char* test_change_ptr_arr_single_struct_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"s\":[{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true}]}";
    struct TestPtrArrSingleStruct s;

    s.s[0] = malloc(sizeof(struct BaseStruct));
    s.s[1] = malloc(sizeof(struct BaseStruct));
    s.s[0]->a = 10;
    s.s[0]->b = 3.14159;
    strcpy(s.s[0]->c, "Hello world");
    s.s[0]->d = 1;
    s.s[1]->a = 10;
    s.s[1]->b = 3.14159;
    strcpy(s.s[1]->c, "Hello world");
    s.s[1]->d = 1;
    ret = JsoncSerialize(real, &s, TestPtrArrSingleStruct);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 纯 struct 类型转换为 json
char* test_change_ptr_arr_mult1_struct_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"s1\":[{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true}],\"s2\":[{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}]}";
    struct TestPtrArrMult1Struct s;

    s.s1[0] = malloc(sizeof(struct BaseStruct));
    s.s2[0] = malloc(sizeof(struct BaseStruct));
    s.s1[1] = malloc(sizeof(struct BaseStruct));
    s.s2[1] = malloc(sizeof(struct BaseStruct));

    s.s1[0]->a = 10;
    s.s1[0]->b = 3.14159;
    strcpy(s.s1[0]->c, "Hello world");
    s.s1[0]->d = 1;
    s.s2[0]->a = 33;
    s.s2[0]->b = 2.7173;
    strcpy(s.s2[0]->c, "Good morning");
    s.s2[0]->d = 0;

    s.s1[1]->a = 10;
    s.s1[1]->b = 3.14159;
    strcpy(s.s1[1]->c, "Hello world");
    s.s1[1]->d = 1;
    s.s2[1]->a = 33;
    s.s2[1]->b = 2.7173;
    strcpy(s.s2[1]->c, "Good morning");
    s.s2[1]->d = 0;
    ret = JsoncSerialize(real, &s, TestPtrArrMult1Struct);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 混合的 struct 类型转换为 json
char* test_change_ptr_arr_multmax_struct_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"s1\":[{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true}],\"s2\":[{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}],\"a\":[10,10],\"b\":[20,20],\"c\":[30.000000,30.000000]"
        "}";
    struct TestPtrArrMultMaxStruct s;

    s.s1[0] = malloc(sizeof(struct BaseStruct));
    s.s2[0] = malloc(sizeof(struct BaseStruct));
    s.a[0] = malloc(sizeof(int));
    s.b[0] = malloc(sizeof(int));
    s.c[0] = malloc(sizeof(float));

    s.s1[1] = malloc(sizeof(struct BaseStruct));
    s.s2[1] = malloc(sizeof(struct BaseStruct));
    s.a[1] = malloc(sizeof(int));
    s.b[1] = malloc(sizeof(int));
    s.c[1] = malloc(sizeof(float));

    s.s1[0]->a = 10;
    s.s1[0]->b = 3.14159;
    strcpy(s.s1[0]->c, "Hello world");
    s.s1[0]->d = 1;
    s.s2[0]->a = 33;
    s.s2[0]->b = 2.7173;
    strcpy(s.s2[0]->c, "Good morning");
    s.s2[0]->d = 0;
    *s.a[0] = 10;
    *s.b[0] = 20;
    *s.c[0] = 30;

    s.s1[1]->a = 10;
    s.s1[1]->b = 3.14159;
    strcpy(s.s1[1]->c, "Hello world");
    s.s1[1]->d = 1;
    s.s2[1]->a = 33;
    s.s2[1]->b = 2.7173;
    strcpy(s.s2[1]->c, "Good morning");
    s.s2[1]->d = 0;
    *s.a[1] = 10;
    *s.b[1] = 20;
    *s.c[1] = 30;

    ret = JsoncSerialize(real, &s, TestPtrArrMultMaxStruct);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// json 转换为单个 struct 成员的 struct
int test_change_single_str_json_to_ptr_arr_single_struct_one(char* json) {
    int ret = 0;
    struct TestPtrArrSingleStruct s;
    s.s[0] = malloc(sizeof(struct BaseStruct));
    s.s[1] = malloc(sizeof(struct BaseStruct));
    ret = JsoncDeserialize(json, &s, TestPtrArrSingleStruct);

    if (s.s[0]->a != 10 || s.s[0]->b != 50 || s.s[0]->d != 1 || s.s[1]->a != 10 ||
        s.s[1]->b != 50 || s.s[1]->d != 1) {
        return -1;
    }

    if (strcmp("Hello world", s.s[0]->c) || strcmp("Hello world", s.s[1]->c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个纯 struct 成员的 struct
int test_change_single_str_json_to_ptr_arr_mult_struct_two(char* json) {
    int ret = 0;
    struct TestPtrArrMult1Struct s;
    s.s1[0] = malloc(sizeof(struct BaseStruct));
    s.s2[0] = malloc(sizeof(struct BaseStruct));
    s.s1[1] = malloc(sizeof(struct BaseStruct));
    s.s2[1] = malloc(sizeof(struct BaseStruct));
    ret = JsoncDeserialize(json, &s, TestPtrArrMult1Struct);

    if (s.s1[0]->a != 10 || s.s1[0]->b != -20 || s.s1[0]->d != 1 || s.s2[0]->a != 33 ||
        s.s2[0]->b != 100 || s.s2[0]->d != 0 || s.s1[1]->a != 10 || s.s1[1]->b != -20 ||
        s.s1[1]->d != 1 || s.s2[1]->a != 33 || s.s2[1]->b != 100 || s.s2[1]->d != 0) {
        return -1;
    }

    if (strcmp("Hello world", s.s1[0]->c) || strcmp("Good morning", s.s2[0]->c) ||
        strcmp("Hello world", s.s1[1]->c) || strcmp("Good morning", s.s2[1]->c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}

// json 转换为多个混合类型成员的 struct
int test_change_single_str_json_to_ptr_arr_mult_struct_max(char* json) {
    int ret = 0;
    struct TestPtrArrMultMaxStruct s;
    s.s1[0] = malloc(sizeof(struct BaseStruct));
    s.s2[0] = malloc(sizeof(struct BaseStruct));
    s.a[0] = malloc(sizeof(int));
    s.b[0] = malloc(sizeof(int));
    s.c[0] = malloc(sizeof(float));
    s.s1[1] = malloc(sizeof(struct BaseStruct));
    s.s2[1] = malloc(sizeof(struct BaseStruct));
    s.a[1] = malloc(sizeof(int));
    s.b[1] = malloc(sizeof(int));
    s.c[1] = malloc(sizeof(float));
    ret = JsoncDeserialize(json, &s, TestPtrArrMultMaxStruct);

    if (s.s1[0]->a != 10 || s.s1[0]->b != -20 || s.s1[0]->d != 1 || s.s2[0]->a != 33 ||
        s.s2[0]->b != 100 || s.s2[0]->d != 0 || *s.a[0] != 10 || *s.b[0] != 20 ||
        *s.c[0] != 30 || s.s1[1]->a != 10 || s.s1[1]->b != -20 || s.s1[1]->d != 1 ||
        s.s2[1]->a != 33 || s.s2[1]->b != 100 || s.s2[1]->d != 0 || *s.a[1] != 10 ||
        *s.b[1] != 20 || *s.c[1] != 30) {
        return -1;
    }

    if (strcmp("Hello world", s.s1[0]->c) || strcmp("Good morning", s.s2[0]->c) ||
        strcmp("Hello world", s.s1[1]->c) || strcmp("Good morning", s.s2[1]->c)) {
        return -1;
    }

    if (ret) {
        return ret;
    }
    return ret;
}
