/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-11 15:25:42
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

#endif

// 单个 struct 类型转换为 json
char* test_change_non_non_single_struct_to_json(char* exp, char* real);
