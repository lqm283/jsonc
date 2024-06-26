/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:07:42
 * @LastEditTime : 2023-01-12 21:12:44
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
#include "test_base_union.h"

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

union TestNonNonMultObj1Union {
    int n;
    struct BaseUnionStruct b;
};
INIT(TestNonNonMultObj1Union,
     union TestNonNonMultObj1Union,
     MEM(union TestNonNonMultObj1Union, Num, int, n, NULL),
     MEM(union TestNonNonMultObj1Union, Obj, struct BaseUnionStruct, b, BaseUnionStruct));

union TestNonNonMultObjUnion {
    int n;
    struct BaseUnionStruct b;
    struct BaseTestStructABC abc;
    struct BaseTestStructAB ab;
    struct BaseTestStructA a;
};
INIT(
    TestNonNonMultObjUnion,
    union TestNonNonMultObjUnion,
    MEM(union TestNonNonMultObjUnion, Num, int, n, NULL),
    MEM(union TestNonNonMultObjUnion, Obj, struct BaseUnionStruct, b, BaseUnionStruct),
    MEM(union TestNonNonMultObjUnion,
        Obj,
        struct BaseTestStructABC,
        abc,
        BaseTestStructABC),
    MEM(union TestNonNonMultObjUnion, Obj, struct BaseTestStructAB, ab, BaseTestStructAB),
    MEM(union TestNonNonMultObjUnion, Obj, struct BaseTestStructA, a, BaseTestStructA));

//  只有一个成员的 union 进行 json 转换
int test_change_single_s_json_to_non_non_single_union_lone(char* json);

// 有多个成员的 union 进行转换
int test_change_single_s_json_to_non_non_mult_union_base(char* json);
int test_change_single_s_json_to_non_non_mult_union_obj(char* json);
int test_change_single_m_json_to_non_non_mult_union_obj(char* json);
int test_change_single_s_json_to_non_non_mult_union_son(char* json);
int test_change_single_s_json_to_non_non_mult_union_sonarr(char* json);

#endif
