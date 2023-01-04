/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-04 19:28:00
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

extern int json_to_struct_test(void);
extern int struct_to_json_test(void);

struct SA {
    int a;
};
INIT(SA, struct SA, MEM(struct SA, Num, int, a, NULL));

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

    int ret = 0;

    // struct D d;
    struct SA sa;

    // ret = struct_to_json_test();

    // ret = json_to_struct_test();

    ret = JsoncDeserialize(buf, &sa, SA);

    printf("sa.a = %d\r\n", sa.a);

    return ret;
}
