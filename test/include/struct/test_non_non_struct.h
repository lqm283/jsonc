/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 15:59:56
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_non_non_struct.h
 */
#ifndef __TEST_NON_NON_STRUCT_H_
#define __TEST_NON_NON_STRUCT_H_

#include <stdint.h>

#include "../../../jsonc.h"

struct BaseStruct {
    int a;
    float b;
    char c[100];
    char d;
};
INIT(BaseStruct,
     struct BaseStruct,
     MEM(struct BaseStruct, Num, int, a, NULL),
     MEM(struct BaseStruct, Num, float, b, NULL),
     MEM(struct BaseStruct, Str, char, c, NULL),
     MEM(struct BaseStruct, Bool, char, d, NULL));

// 单元素 struct
struct TestNonNonSingleStruct {
    struct BaseStruct s;
};
INIT(TestNonNonSingleStruct,
     struct TestNonNonSingleStruct,
     MEM(struct TestNonNonSingleStruct, Obj, struct BaseStruct, s, BaseStruct));

// 多元素纯 struct
struct TestNonNonMult1Struct {
    struct BaseStruct s1;
    struct BaseStruct s2;
};
INIT(TestNonNonMult1Struct,
     struct TestNonNonMult1Struct,
     MEM(struct TestNonNonMult1Struct, Obj, struct BaseStruct, s1, BaseStruct),
     MEM(struct TestNonNonMult1Struct, Obj, struct BaseStruct, s2, BaseStruct));

// 多元素混合基本类型 struct
struct TestNonNonMultMaxStruct {
    struct BaseStruct s1;
    struct BaseStruct s2;
    int a;
    int b;
    float c;
};
INIT(TestNonNonMultMaxStruct,
     struct TestNonNonMultMaxStruct,
     MEM(struct TestNonNonMultMaxStruct, Obj, struct BaseStruct, s1, BaseStruct),
     MEM(struct TestNonNonMultMaxStruct, Obj, struct BaseStruct, s2, BaseStruct),
     MEM(struct TestNonNonMultMaxStruct, Num, int, a, NULL),
     MEM(struct TestNonNonMultMaxStruct, Num, int, b, NULL),
     MEM(struct TestNonNonMultMaxStruct, Num, float, c, NULL));

#endif

// struct 类型转换为 json
char* test_change_non_non_single_struct_to_json(char* exp, char* real);
char* test_change_non_non_mult1_struct_to_json(char* exp, char* real);
char* test_change_non_non_multmax_struct_to_json(char* exp, char* real);

// json 转换为 json 类型
int test_change_single_str_json_to_non_non_single_struct_one(char* json);