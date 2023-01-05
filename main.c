/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-05 14:08:13
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/main.c
 */

#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#include "jsonc.h"

// extern int json_to_struct_test(void);
// extern int struct_to_json_test(void);

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    char buf[81920];

    FILE* file = fopen("json/test.json", "r");
    if (!file) {
        return -1;
    }
    unsigned long n = fread(buf, 1, sizeof(buf), file);
    buf[n] = 0;

    struct A a;

    // a.a = malloc(sizeof(float));

    // for (int i = 0; i < 5; i++) {
    //     a.a[i] = malloc(100);
    //     printf("addr &a.a[%d] = 0x%lx\n", i, (long)&a.a[i]);
    //     printf("addr a.a[%d] = 0x%lx\n", i, (long)a.a[i]);
    // }

    int ret = 0;

    ret = JsoncDeserialize(buf, &a, A);

    if (ret != 0) {
        printf("JsoncDeserialize error\n");
        return ret;
    }

    printf("a.a[0] = %f\n", a.a[0]);
    printf("a.a[1] = %f\n", a.a[1]);
    printf("a.a[2] = %f\n", a.a[2]);
    printf("a.a[3] = %f\n", a.a[3]);
    printf("a.a[4] = %f\n", a.a[4]);

    return 0;
}
