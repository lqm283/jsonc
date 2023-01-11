/*
 * @Author       : lqm283
 * @Date         : 2023-01-11 16:38:58
 * @LastEditTime : 2023-01-11 16:38:59
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_base_struct.h
 */
#ifndef __TEST_BASE_STRUCT_H_
#define __TEST_BASE_STRUCT_H_

#include "../../../jsonc.h"

struct BaseStruct {
    int a;
    float b;
    char c[100];
    char d;
};
INIT(BaseStruct,
     struct BaseStruct,
     MEM(struct BaseStruct, Num, int, a, NULL),
     MEM(struct BaseStruct, Num, float, b, NULL),
     MEM(struct BaseStruct, Str, char, c, NULL),
     MEM(struct BaseStruct, Bool, char, d, NULL));

#endif
