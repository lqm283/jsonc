/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 10:30:52
 * @LastEditTime : 2023-01-06 03:54:57
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
    char a;
    int b;
};
INIT(A,
     struct A,
     MEM(struct A, Str, char, a, NULL, "start"),
     MEM(struct A, Num, int, b, NULL));

union B {
    int a;
    int b;
};
INIT(B,
     union B,
     MEM(union B, Num, int, a, NULL),
     MEM(union B, Num, int, b, NULL));

struct SA {
    struct A *mfa;
};
INIT(SA, struct SA, MEM(struct SA, Num, struct A *, mfa, A, "dgade,omitempty"));

#endif
