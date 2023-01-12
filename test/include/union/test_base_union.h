/*
 * @Author       : lqm283
 * @Date         : 2023-01-11 16:38:58
 * @LastEditTime : 2023-01-12 11:15:07
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/union/test_base_union.h
 */
#ifndef __TEST_BASE_UNION_H_
#define __TEST_BASE_UNION_H_

#include "../../../jsonc.h"

struct BaseUnionStruct {
    float b;
    char c[100];
    int a;
    char d;
};
INIT(BaseUnionStruct,
     struct BaseUnionStruct,
     MEM(struct BaseUnionStruct, Num, int, a, NULL),
     MEM(struct BaseUnionStruct, Num, float, b, NULL),
     MEM(struct BaseUnionStruct, Str, char, c, NULL),
     MEM(struct BaseUnionStruct, Bool, char, d, NULL));

struct BaseTestStructA {
    int a;
};
INIT(BaseTestStructA,
     struct BaseTestStructA,
     MEM(struct BaseTestStructA, Num, int, a, NULL));

struct BaseTestStructAB {
    float b;
    int a;
};
INIT(BaseTestStructAB,
     struct BaseTestStructAB,
     MEM(struct BaseTestStructAB, Num, int, a, NULL),
     MEM(struct BaseTestStructAB, Num, float, b, NULL));

struct BaseTestStructABC {
    char c[100];
    int a;
    float b;
};
INIT(BaseTestStructABC,
     struct BaseTestStructABC,
     MEM(struct BaseTestStructABC, Num, int, a, NULL),
     MEM(struct BaseTestStructABC, Num, float, b, NULL),
     MEM(struct BaseTestStructABC, Str, char, c, NULL));

#endif
