/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-03-27 19:49:36
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

struct a{
    void *data;
};
INIT(a, struct a,
    MEM(struct a, Any, void *, data, NULL)
);


char *obj = "{\"data\":{\"a\":3}}";
char *arr = "{\"data\":[1,2,3,4,5]}";
char *str = "{\"data\":\"hello world\"}";
char *num = "{\"data\":10}";
char *bool = "{\"data\":false}";

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    // test();
    struct a a = {
        .data = NULL,
    };
    JsoncDeserialize(obj, &a,a);
    printf("%s\r\n", (char *)a.data);
    JsoncDeserialize(arr, &a,a);
    printf("%s\r\n", (char *)a.data);
    JsoncDeserialize(str, &a,a);
    printf("%s\r\n", (char *)a.data);
    JsoncDeserialize(num, &a,a);
    printf("%d\r\n", (uint8_t)*(double *)a.data);
    JsoncDeserialize(bool, &a,a);
    printf("%d\r\n", (uint8_t)*(double *)a.data);

    return 0;
}
