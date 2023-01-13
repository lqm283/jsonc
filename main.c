/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-01-13 13:38:48
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
#include "test/include/union/test_ptr_non_union.h"

int mem_test_change_single_s_json_to_ptr_non_mult_union_pson(char* json) {
    int ret = 0;
    union TestPtrNonMultObjUnion u;
    u.b = malloc(sizeof(struct BaseUnionStruct));

    ret = JsoncDeserialize(json, &u, TestPtrNonMultObjUnion);
    if (ret) {
        free(u.b);
        return ret;
    }

    if (u.ab->a != 10 || u.ab->b != 30) {
        free(u.b);
        return -1;
    }
    free(u.b);
    return ret;
}

char* json = "{\"a\":10,\"b\":30}";

int mem_test() {
    return mem_test_change_single_s_json_to_ptr_non_mult_union_pson(json);
}

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    while (1) {
        // test();
        int ret = mem_test();
        usleep(1000 * 1);
        printf("test ok  ret = %d\n", ret);
    }

    return 0;
}
