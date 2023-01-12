/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-12 20:32:14
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/union/test_non_arr_union.h
 */

#ifndef __TEST_NON_ARR_UNION_H_
#define __TEST_NON_ARR_UNION_H_

#include <stdint.h>

#include "../../../jsonc.h"
#include "test_base_union.h"

union TestNonArrSingleUnion {
    int a[2];
};
INIT(TestNonArrSingleUnion,
     union TestNonArrSingleUnion,
     MEM(union TestNonArrSingleUnion, Num, int, a, NULL));

union TestNonArrMultBaseUnion {
    struct BaseUnionStruct a[2];
    float b[2];
};
INIT(TestNonArrMultBaseUnion,
     union TestNonArrMultBaseUnion,
     MEM(union TestNonArrMultBaseUnion, Num, struct BaseUnionStruct, a, BaseUnionStruct),
     MEM(union TestNonArrMultBaseUnion, Num, float, b, NULL));

union TestNonArrMultObjUnion {
    int n[2];
    struct BaseUnionStruct b[2];
    struct BaseTestStructABC abc[2];
    struct BaseTestStructAB ab[2];
    struct BaseTestStructA a[2];
};
INIT(
    TestNonArrMultObjUnion,
    union TestNonArrMultObjUnion,
    MEM(union TestNonArrMultObjUnion, Num, int, n, NULL),
    MEM(union TestNonArrMultObjUnion, Obj, struct BaseUnionStruct, b, BaseUnionStruct),
    MEM(union TestNonArrMultObjUnion,
        Obj,
        struct BaseTestStructABC,
        abc,
        BaseTestStructABC),
    MEM(union TestNonArrMultObjUnion, Obj, struct BaseTestStructAB, ab, BaseTestStructAB),
    MEM(union TestNonArrMultObjUnion, Obj, struct BaseTestStructA, a, BaseTestStructA));

//  只有一个成员的 union 进行 json 转换
int test_change_single_s_json_to_non_arr_single_union_lone(char* json);

// 有多个成员的 union 进行转换
int test_change_single_s_json_to_non_arr_mult_union_base(char* json);
int test_change_single_s_json_to_non_arr_mult_union_obj(char* json);
int test_change_single_s_json_to_non_arr_mult_union_son(char* json);
int test_change_single_s_json_to_non_arr_mult_union_sonarr(char* json);

#endif
