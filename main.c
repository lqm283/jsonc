/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-06 03:56:12
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

    struct SA sa;

    sa.mfa = malloc(sizeof(struct A));

    // for (int i = 0; i < 5; i++) {
    //     a.a[i] = malloc(100);
    //     printf("addr &a.a[%d] = 0x%lx\n", i, (long)&a.a[i]);
    //     printf("addr a.a[%d] = 0x%lx\n", i, (long)a.a[i]);
    // }

    int ret = 0;

    ret = JsoncDeserialize(buf, &sa, SA);

    if (ret != 0) {
        printf("JsoncDeserialize error\n");
        return ret;
    }

    printf("sa.mfa.a = %c\n", sa.mfa[0].a);
    printf("sa.mfa.a = %d\n", sa.mfa[0].b);
    // printf("sa.mfa.a = %c\n", sa.mfa[1].a);
    // printf("sa.mfa.a = %d\n", sa.mfa[1].b);

    return 0;
}
