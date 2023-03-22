/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-03-22 12:29:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/main.c
 */

#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "jsonc.h"
#include "test/include/test.h"

struct A {
    int a;
    int b;
};
INIT(A, struct A,
MEM(struct A, Num, int, a, NULL),
MEM(struct A, Num, int, b, NULL));


struct B{
    int aa;
    int bb;
    void *data;
};
INIT(B, struct B,
MEM(struct B, Num, int, aa, NULL),
MEM(struct B, Num, int, bb, NULL),
MEM(struct B, Obj, int *, data, NULL));

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    char buf[1024];
    char temp[1024];

    struct A a;
    a.a = 20;
    a.b = 30;

    JsoncSerialize(temp,&a,A);

    printf("temp = %s\n",temp);

    struct B b;
    b.aa = 23;
    b.bb = 34;
    b.data = temp;
    JsoncSerialize(buf,&b,B);

    printf("buf = %s\n",buf);

    sprintf(temp,"%d",500);
    b.data = NULL;
    JsoncSerialize(buf,&b,B);

    printf("buf = %s\n",buf);

    return 0;
}
