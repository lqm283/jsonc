/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 10:30:52
 * @LastEditTime : 2023-01-05 06:02:24
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/main.h
 */
#ifndef __MAIN_H_
#define __MAIN_H_
#include <bits/stdint-uintn.h>

#include "jsonc.h"
#include "stdint.h"

struct A {
    int a;
};
INIT(A, struct A, MEM(struct A, Num, int, a, NULL));

union B {
    int a;
    int b;
};
INIT(B,
     union B,
     MEM(union B, Num, int, a, NULL),
     MEM(union B, Num, int, b, NULL));

struct SA {
    int a;
    int b[10];
    int *c;
    int *d[10];
    struct A aa;
    struct A aaa[10];
    struct A *pa;
    struct A *paa[10];
    union B ub;
    union B uba[10];
    union B *pub;
    union B *puba[10];
};
INIT(SA,
     struct SA,
     MEM(struct SA, Num, int, a, NULL),
     MEM(struct SA, Num, int, b, NULL, "b"),
     MEM(struct SA, Num, int *, c, NULL),
     MEM(struct SA, Num, int *, d, NULL),
     MEM(struct SA, Num, struct A, aa, A),
     MEM(struct SA, Num, struct A, aaa, A),
     MEM(struct SA, Num, struct A *, pa, A),
     MEM(struct SA, Num, struct A *, paa, A),
     MEM(struct SA, Num, union B, ub, B),
     MEM(struct SA, Num, union B, uba, B),
     MEM(struct SA, Num, union B *, pub, B),
     MEM(struct SA, Num, union B *, puba, B));

#endif
