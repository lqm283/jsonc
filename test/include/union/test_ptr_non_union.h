/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-12 17:10:51
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/union/test_ptr_non_union.h
 */

#ifndef __TEST_PTR_NON_UNION_H_
#define __TEST_PTR_NON_UNION_H_

#include <stdint.h>

#include "../../../jsonc.h"
#include "test_base_union.h"

union TestPtrNonSingleUnion {
    int *a;
};
INIT(TestPtrNonSingleUnion,
     union TestPtrNonSingleUnion,
     MEM(union TestPtrNonSingleUnion, Num, int *, a, NULL));

union TestPtrNonMultBaseUnion {
    int *a;
    float *b;
};
INIT(TestPtrNonMultBaseUnion,
     union TestPtrNonMultBaseUnion,
     MEM(union TestPtrNonMultBaseUnion, Num, int *, a, NULL),
     MEM(union TestPtrNonMultBaseUnion, Num, float *, b, NULL));

union TestPtrNonMultObjUnion {
    int *n;
    struct BaseUnionStruct *b;
    struct BaseTestStructABC abc;
    struct BaseTestStructAB *ab;
    struct BaseTestStructA *a;
};
INIT(
    TestPtrNonMultObjUnion,
    union TestPtrNonMultObjUnion,
    MEM(union TestPtrNonMultObjUnion, Num, int *, n, NULL),
    MEM(union TestPtrNonMultObjUnion, Obj, struct BaseUnionStruct *, b, BaseUnionStruct),
    MEM(union TestPtrNonMultObjUnion,
        Obj,
        struct BaseTestStructABC,
        abc,
        BaseTestStructABC),
    MEM(union TestPtrNonMultObjUnion,
        Obj,
        struct BaseTestStructAB *,
        ab,
        BaseTestStructAB),
    MEM(union TestPtrNonMultObjUnion, Obj, struct BaseTestStructA *, a, BaseTestStructA));

//  只有一个成员的 union 进行 json 转换
int test_change_single_s_json_to_ptr_non_single_union_lone(char *json);

// 有多个成员的 union 进行转换
int test_change_single_s_json_to_ptr_non_mult_union_base(char *json);
int test_change_single_s_json_to_ptr_non_mult_union_obj(char *json);
int test_change_single_s_json_to_ptr_non_mult_union_nson(char *json);
int test_change_single_s_json_to_ptr_non_mult_union_pson(char *json);

#endif
