/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-05 09:04:41
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

    struct SA sa =
        {20, NULL, {"adsf", "asdgeee"}, {30}, {{455}, {34654}}, NULL, {NULL, NULL}};

    sa.b = malloc(sizeof(char));
    sa.pmfa = malloc(sizeof(struct A));
    *sa.b = 80;
    sa.pmfa->a = 30;
    sa.pmfaa[0] = malloc(sizeof(struct A));
    sa.pmfaa[1] = malloc(sizeof(struct A));
    sa.pmfaa[0]->a = 124;
    sa.pmfaa[1]->a = 654;

    printf("addr sa.b = 0x%lx\n", (long)sa.b);

    JsoncSerialize(buf, &sa, SA);

    printf("%s\n", buf);

    // struct D d;
    // struct SC sc;

    // sc.a = malloc(sizeof(int));

    // ret = struct_to_json_test();

    // ret = json_to_struct_test();

    // ret = JsoncDeserialize(buf, &sc, SC);

    // printf("sc.a = %d\r\n", *sc.a);

    return ret;
}
