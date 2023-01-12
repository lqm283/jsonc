/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-12 08:19:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : 测试常规的非数组非指针 char 类型
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/union/test_non_non_union.h
 */
#ifndef __TEST_NON_NON_UNION_H_
#define __TEST_NON_NON_UNION_H_

#include <stdint.h>

#include "../../../jsonc.h"
#include "test_base_struct.h"

union TestNonNonSingleUnion {
    int a;
};
INIT(TestNonNonSingleUnion,
     union TestNonNonSingleUnion,
     MEM(union TestNonNonSingleUnion, Num, int, a, NULL));

union TestNonNonMultBaseUnion {
    int a;
    float b;
};
INIT(TestNonNonMultBaseUnion,
     union TestNonNonMultBaseUnion,
     MEM(union TestNonNonMultBaseUnion, Num, int, a, NULL),
     MEM(union TestNonNonMultBaseUnion, Num, float, b, NULL));

union TestNonNonMultObjUnion {
    int n;
    struct BaseStruct b;
};
INIT(TestNonNonMultObjUnion,
     union TestNonNonMultObjUnion,
     MEM(union TestNonNonMultObjUnion, Num, int, n, NULL),
     MEM(union TestNonNonMultObjUnion, Num, struct BaseStruct, b, BaseStruct));

//  只有一个成员的 union 进行 json 转换
int test_change_single_s_json_to_non_non_single_union_lone(char* json);

// 有多个成员的 union 进行转换
int test_change_single_s_json_to_non_non_mult_union_base(char* json);
int test_change_single_s_json_to_non_non_mult_union_obj(char* json);
int test_change_single_s_json_to_non_non_mult_union_son(char* json);

#endif
