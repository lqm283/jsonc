/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:39
 * @LastEditTime : 2023-01-11 16:46:02
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_ptr_non_struct.h
 */

#ifndef __TEST_PTR_NON_STRUCT_H_
#define __TEST_PTR_NON_STRUCT_H_

#include <stdint.h>

#include "../../../jsonc.h"
#include "test_base_struct.h"

// 单元素 struct
struct TestPtrNonSingleStruct {
    struct BaseStruct* s;
};
INIT(TestPtrNonSingleStruct,
     struct TestPtrNonSingleStruct,
     MEM(struct TestPtrNonSingleStruct, Obj, struct BaseStruct*, s, BaseStruct));

// 多元素纯 struct
struct TestPtrNonMult1Struct {
    struct BaseStruct* s1;
    struct BaseStruct* s2;
};
INIT(TestPtrNonMult1Struct,
     struct TestPtrNonMult1Struct,
     MEM(struct TestPtrNonMult1Struct, Obj, struct BaseStruct*, s1, BaseStruct),
     MEM(struct TestPtrNonMult1Struct, Obj, struct BaseStruct*, s2, BaseStruct));

// 多元素混合基本类型 struct
struct TestPtrNonMultMaxStruct {
    struct BaseStruct* s1;
    struct BaseStruct* s2;
    int* a;
    int* b;
    float* c;
};
INIT(TestPtrNonMultMaxStruct,
     struct TestPtrNonMultMaxStruct,
     MEM(struct TestPtrNonMultMaxStruct, Obj, struct BaseStruct*, s1, BaseStruct),
     MEM(struct TestPtrNonMultMaxStruct, Obj, struct BaseStruct*, s2, BaseStruct),
     MEM(struct TestPtrNonMultMaxStruct, Num, int*, a, NULL),
     MEM(struct TestPtrNonMultMaxStruct, Num, int*, b, NULL),
     MEM(struct TestPtrNonMultMaxStruct, Num, float*, c, NULL));

// struct 类型转换为 json
char* test_change_ptr_non_single_struct_to_json(char* exp, char* real);
char* test_change_ptr_non_mult1_struct_to_json(char* exp, char* real);
char* test_change_ptr_non_multmax_struct_to_json(char* exp, char* real);

// json 转换为 json 类型
int test_change_single_str_json_to_ptr_non_single_struct_one(char* json);
int test_change_single_str_json_to_ptr_non_mult_struct_two(char* json);
int test_change_single_str_json_to_ptr_non_mult_struct_max(char* json);

#endif
