/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2024-03-25 08:22:39
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
#include <stdint.h>

#include "jsonc.h"
#include "test/include/test.h"

struct num{
    int a;
    int b;
};
INIT(num,struct num,MEM(struct num,Num,int,a,NULL),MEM(struct num,Num,int,b,NULL));

struct arr{
    struct num a[1];
};
INIT(arr,struct arr,MEM(struct arr,Arr,struct num,a,num));



int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    // test();

    struct arr arr[1];
    arr[0].a->a = 10;
    arr[0].a->b = 20;


    char buf[200];

    JsoncSerialize(buf,&arr,arr);

    printf("%s\n",buf);


    return 0;
}
