/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2022-06-16 15:00:57
 * @LastEditors  : lqm283 lanqianming@hotmail.com
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/main.c
 */

#include "main.h"

#include <stdio.h>

#include "jsonc.h"

extern int json_to_struct_test(void);
extern int struct_to_json_test(void);

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    int ret = 0;

    ret = struct_to_json_test();

    ret = json_to_struct_test();
    return ret;
}
