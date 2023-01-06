/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 10:30:52
 * @LastEditTime : 2023-01-06 12:22:32
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
INIT(B, union B, MEM(union B, Num, int, a, NULL), MEM(union B, Num, int, b, NULL));

struct SA {
    struct A *mfa[2];
};
INIT(SA, struct SA, MEM(struct SA, Num, struct A *, mfa, A, "dgade,omitempty"));

union UA {
    char a;
    int b;
    struct A t[2];
};
INIT(UA,
     union UA,
     MEM(union UA, Str, char, a, NULL, "start"),
     MEM(union UA, Num, int, b, NULL),
     MEM(union UA, Num, struct A, t, A, "dgade,omitempty"));

struct USA {
    int a;
    union UA *ua;
};
INIT(USA,
     struct USA,
     MEM(struct USA, Num, int, a, NULL),
     MEM(struct USA, Num, union UA *, ua, UA));

#endif
