/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 10:30:52
 * @LastEditTime : 2023-01-05 08:53:09
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
    char a;
    char *b;
    char *c[2];
    struct A mfa;
    struct A mfaa[2];
    struct A *pmfa;
    struct A *pmfaa[2];
};
INIT(SA,
     struct SA,
     MEM(struct SA, Num, char, a, NULL, "dgade,omitempty"),
     MEM(struct SA, Num, char *, b, NULL, "asdf,omitempty"),
     MEM(struct SA, Str, char *, c, NULL, "_,omitempty"),
     MEM(struct SA, Str, struct A, mfa, A, "dfrgrss,omitempty"),
     MEM(struct SA, Str, struct A, mfaa, A, "rt,omitempty"),
     MEM(struct SA, Str, struct A *, pmfa, A, "_,omitempty"),
     MEM(struct SA, Str, struct A *, pmfaa, A, "_,omitempty"));

#endif
