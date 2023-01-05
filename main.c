/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-05 05:44:12
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

    int ret = 0;

    struct SA sa = {10, 20};

    JsoncSerialize(buf, &sa, SA);

    // struct D d;
    // struct SC sc;

    // sc.a = malloc(sizeof(int));

    // ret = struct_to_json_test();

    // ret = json_to_struct_test();

    // ret = JsoncDeserialize(buf, &sc, SC);

    // printf("sc.a = %d\r\n", *sc.a);

    return ret;
}
