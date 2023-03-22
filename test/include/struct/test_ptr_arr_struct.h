/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:11:24
 * @LastEditTime : 2023-01-11 20:01:57
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_ptr_arr_struct.h
 */

#ifndef __TEST_PTR_ARR_STRUCT_H_
#define __TEST_PTR_ARR_STRUCT_H_

#include <stdint.h>

#include "../../../jsonc.h"
#include "test_base_struct.h"

// 单元素 struct
struct TestPtrArrSingleStruct {
    struct BaseStruct* s[2];
};
INIT(TestPtrArrSingleStruct,
     struct TestPtrArrSingleStruct,
     MEM(struct TestPtrArrSingleStruct, Obj, struct BaseStruct*, s, BaseStruct));

// 多元素纯 struct
struct TestPtrArrMult1Struct {
    struct BaseStruct* s1[2];
    struct BaseStruct* s2[2];
};
INIT(TestPtrArrMult1Struct,
     struct TestPtrArrMult1Struct,
     MEM(struct TestPtrArrMult1Struct, Obj, struct BaseStruct*, s1, BaseStruct),
     MEM(struct TestPtrArrMult1Struct, Obj, struct BaseStruct*, s2, BaseStruct));

// 多元素混合基本类型 struct
struct TestPtrArrMultMaxStruct {
    struct BaseStruct* s1[2];
    struct BaseStruct* s2[2];
    int* a[2];
    int* b[2];
    float* c[2];
};
INIT(TestPtrArrMultMaxStruct,
     struct TestPtrArrMultMaxStruct,
     MEM(struct TestPtrArrMultMaxStruct, Obj, struct BaseStruct*, s1, BaseStruct),
     MEM(struct TestPtrArrMultMaxStruct, Obj, struct BaseStruct*, s2, BaseStruct),
     MEM(struct TestPtrArrMultMaxStruct, Num, int*, a, NULL),
     MEM(struct TestPtrArrMultMaxStruct, Num, int*, b, NULL),
     MEM(struct TestPtrArrMultMaxStruct, Num, float*, c, NULL));

// struct 类型转换为 json
int test_change_ptr_arr_single_struct_to_json(char* exp, char* real);
int test_change_ptr_arr_mult1_struct_to_json(char* exp, char* real);
int test_change_ptr_arr_multmax_struct_to_json(char* exp, char* real);

// json 转换为 json 类型
int test_change_single_str_json_to_ptr_arr_single_struct_one(char* json);
int test_change_single_str_json_to_ptr_arr_mult_struct_two(char* json);
int test_change_single_str_json_to_ptr_arr_mult_struct_max(char* json);
#endif
