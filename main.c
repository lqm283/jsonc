/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-04 13:42:17
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

struct SB {
    int a;
    int b;
};
INIT(SB,
     struct SB,
     MEM(struct SB, Num, int, a, NULL, "a"),
     MEM(struct SB, Num, int, b, NULL, "a"));

struct SC {
    int* a;
};
static const struct struct_mem struct_mem_SC[] = {
    {"int*",
     "a",
     Num,
     sizeof(int*),
     sizeof(((struct SC*)0)->a),
     __builtin_offsetof(struct SC, a),
     ((void*)0)},
    {((void*)0), ((void*)0), 0, 0, 0, 0, ((void*)0)}};

static const struct type struct_type_SC[] = {
    {"struct SC",
     sizeof(struct SC),
     struct_mem_SC,
     (sizeof(struct_mem_SC) / sizeof(struct struct_mem) - 1)}};

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
    struct SC sc;

    sc.a = malloc(sizeof(int));

    // ret = struct_to_json_test();

    // ret = json_to_struct_test();

    ret = JsoncDeserialize(buf, &sc, SC);

    printf("sc.a = %d\r\n", *sc.a);

    return ret;
}
