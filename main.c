/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-06 08:14:51
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

    struct USA usa;

    usa.ua = malloc(sizeof(union UA));

    // printf("addr ua.t \t= 0x%lx\n", (long)&ua.t);
    // printf("addr value ua.t = 0x%lx\n", (long)ua.t);

    int ret = 0;

    ret = JsoncDeserialize(buf, &usa, USA);

    if (ret != 0) {
        printf("JsoncDeserialize error\n");
        return ret;
    }

    printf("usa.a = %d\n", usa.a);
    printf("usa.ua.b = %c\n", usa.ua->t[0].a);
    printf("usa.ua.b = %d\n", usa.ua->t[0].b);
    printf("usa.ua.b = %c\n", usa.ua->t[1].a);
    printf("usa.ua.b = %d\n", usa.ua->t[1].b);

    return 0;
}
