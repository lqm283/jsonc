/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:20:56
 * @LastEditTime : 2023-01-11 17:00:19
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_non_arr_struct.h
 */

#ifndef __TEST_NON_ARR_STRUCT_H_
#define __TEST_NON_ARR_STRUCT_H_

#include <stdint.h>

#include "../../../jsonc.h"
#include "test_base_struct.h"

// 单元素 struct
struct TestNonArrSingleStruct {
    struct BaseStruct s[2];
};
INIT(TestNonArrSingleStruct,
     struct TestNonArrSingleStruct,
     MEM(struct TestNonArrSingleStruct, Obj, struct BaseStruct, s, BaseStruct));

// 多元素纯 struct
struct TestNonArrMult1Struct {
    struct BaseStruct s1[2];
    struct BaseStruct s2[2];
};
INIT(TestNonArrMult1Struct,
     struct TestNonArrMult1Struct,
     MEM(struct TestNonArrMult1Struct, Obj, struct BaseStruct, s1, BaseStruct),
     MEM(struct TestNonArrMult1Struct, Obj, struct BaseStruct, s2, BaseStruct));

// 多元素混合基本类型 struct
struct TestNonArrMultMaxStruct {
    struct BaseStruct s1[2];
    struct BaseStruct s2[2];
    int a[2];
    int b[2];
    float c[2];
};
INIT(TestNonArrMultMaxStruct,
     struct TestNonArrMultMaxStruct,
     MEM(struct TestNonArrMultMaxStruct, Obj, struct BaseStruct, s1, BaseStruct),
     MEM(struct TestNonArrMultMaxStruct, Obj, struct BaseStruct, s2, BaseStruct),
     MEM(struct TestNonArrMultMaxStruct, Num, int, a, NULL),
     MEM(struct TestNonArrMultMaxStruct, Num, int, b, NULL),
     MEM(struct TestNonArrMultMaxStruct, Num, float, c, NULL));

// struct 类型转换为 json
char* test_change_non_arr_single_struct_to_json(char* exp, char* real);
char* test_change_non_arr_mult1_struct_to_json(char* exp, char* real);
char* test_change_non_arr_multmax_struct_to_json(char* exp, char* real);

// json 转换为 json 类型
int test_change_single_str_json_to_non_arr_single_struct_one(char* json);
int test_change_single_str_json_to_non_arr_mult_struct_two(char* json);
int test_change_single_str_json_to_non_arr_mult_struct_max(char* json);

#endif
