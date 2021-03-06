/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:34
 * @LastEditTime : 2022-06-16 14:18:38
 * @LastEditors  : lqm283 lanqianming@hotmail.com
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/jsonc.h
 */
#ifndef __JSONC_H_
#define __JSONC_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum json_type { Str, Num, Bool, MultArr, Obj, Arr, Null };
enum json_bool { False, True };
enum c_type {
    cBase,
    cMult,
    cBaseArr,
    cMultArr,
    cPtrBase,
    cPtrMult,
    cPtrBaseArr,
    cPtrMultArr,
};

struct list_head {
    struct list_head *next, *prev;
};

typedef struct list_head jsonc_obj;
typedef struct list_head jsonc_arr;

union jsonc_type {
    jsonc_obj* obj;
    jsonc_arr* arr;
    char* str;
    char* num;
    enum json_bool bool;
    int null;
} jsonc_type;

struct struct_mem {
    char* mem_type;
    char* mem_name;
    enum json_type struct_type;
    int type_length;
    int mem_length;
    int mem_offset;
    const struct type* type_info;
} struct_mem;

struct jsonc_ele {
    struct list_head sibling;
    char* name;
    enum json_type type;
    union jsonc_type value;
    struct struct_mem mem;
    void* mem_addr;
    enum c_type c_type;
} jsonc_ele;

typedef struct jsonc_ele jsonc_arr_mem;

struct type {
    char* struct_type;
    int length;
    const struct struct_mem* mem;
    int mem_num;
} type;

#define STRUCT_NAME(name) struct_type_##name
#define struct_type_NULL NULL

#define SIZEOF(type, name) sizeof(((type*)0)->name)
#define L_MEM(s_type, json_type, mem_type, mem_name, type_info)                                                  \
    {                                                                                                            \
#mem_type, #mem_name, json_type, sizeof(mem_type), SIZEOF(s_type, mem_name), offsetof(s_type, mem_name), \
            struct_type##type_info                                                                               \
    }
#define L_INIT(s_name, s_type, s_mem...)                                                            \
    static const struct struct_mem struct_mem_##s_name[] = {s_mem, {NULL, NULL, 0, 0, 0, 0, NULL}}; \
    static const struct type struct_type_##s_name[] = {                                             \
        {#s_type, sizeof(s_type), struct_mem_##s_name, (sizeof(struct_mem_##s_name) / sizeof(struct struct_mem) - 1)}}
#define L_STRUCT(name) struct_type_##name
#define STRUCT(name) L_STRUCT(name)
void* jsonc_serialize(char* buf, void* st, const struct type* type);
int jsonc_deserialize(char* buf, void* st, const struct type* type);

/**
 * @description: ?????????????????????????????????
 * @param {} s_name ???????????????????????????
 * @param {} s_type ???????????????????????????
 * @param {} s_mem ??????????????????????????????MEM?????????????????????
 */
#define INIT(s_name, s_type, s_mem...) L_INIT(s_name, s_type, s_mem)

/**
 * @description: ???????????????????????????
 * @param {} s_type ???????????????????????????
 * @param {} json_type
 * ??????????????????????????????????????????????????????????????????????????????????????????
 * @param {} mem_type ???????????????????????????
 * @param {} mem_name ???????????????
 * @param {} type_info ???????????????????????????????????????????????????????????? NULL
 */
#define MEM(s_type, json_type, mem_type, mem_name, type_info) L_MEM(s_type, json_type, mem_type, mem_name, _##type_info)

/**
 * @description: ???C??????????????????????????????json
 * @param {char*} buf ?????????????????????json?????????
 * @param {void*} st ??????????????????????????????????????????
 * @param {type*} type ??????????????????????????????
 * @return {*} ??????json?????????????????????
 */
#define JsoncSerialize(buf, st, type) jsonc_serialize(buf, st, STRUCT(type))

/**
 * @description: ???json?????????????????????C????????????????????????????????????????????????
 * @param {char*} buf ??????json?????????
 * @param {void*} st  ?????????????????????
 * @param {type*} type ???????????????????????????
 * @return {*} 0 ??????????????????  ?????? ??????
 */
#define JsoncDeserialize(buf, st, type) jsonc_deserialize(buf, st, STRUCT(type))

#endif
