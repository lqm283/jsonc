/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-13 16:54:57
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
    int b[2];
};
INIT(TestNonArrMultBaseUnion,
     union TestNonArrMultBaseUnion,
     MEM(union TestNonArrMultBaseUnion, Num, struct BaseUnionStruct, a, BaseUnionStruct),
     MEM(union TestNonArrMultBaseUnion, Num, int, b, NULL));

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

//  json 转换为只有一个基本类型成员的union，
int test_change_single_arr_json_to_non_arr_single_union_lonemem(char* json);
int test_change_mult_arr_json_to_non_arr_single_union_lonemem(char* json);

// json 转换为有多个成员的 union
int test_change_single_s_json_to_non_arr_mult_union_selfmem(char* json);
int test_change_single_arr_json_to_non_arr_mult_union_selfmem(char* json);
int test_change_single_arr_json_to_non_arr_mult_union_submem(char* json);
int test_change_mult_s_json_to_non_arr_mult_union_submem(char* json);
int test_change_mult_arr_json_to_non_arr_mult_union_submem(char* json);

#endif
