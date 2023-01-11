/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:34
 * @LastEditTime : 2023-01-11 21:49:25
 * @LastEditors  : lqm283
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

enum json_type { Str, Num, Bool, Obj, Arr, MultArr, Null };

enum json_bool { False, True };
enum c_type {
    cBase = 0,
    cStruct,
    cUnion,
    cBaseArr = 4,
    cStructArr,
    cUnionArr,
    cPtrBase = 8,
    cPtrStruct,
    cPtrUnion,
    cPtrBaseArr = 12,
    cPtrStructArr,
    cPtrUnionArr
};

struct list_head {
    struct list_head *next, *prev;
};

typedef struct list_head jsonc_obj;
typedef struct list_head jsonc_arr;

/**
 * @description: 复合对象成员的相关参数和信息
 */
typedef struct struct_mem {
    const char* mem_type;        // 成员的类型
    const char* mem_name;        // 成员的名称
    enum json_type struct_type;  // 成员的 json 数据类型
    int type_length;             // 成员类型的长度
    int mem_length;              // 成员的长度
    int mem_offset;              // 成员在对象中的偏移量
    const struct type* type_info;  // 如果成员是对象，则该对象的信息
    const char* tag;
} struct_mem;

/**
 * @description: 复合对象的相关参数和信息
 */
typedef struct type {
    const char* struct_type;       // 复合对象的类型
    int length;                    // 复合对象的长度
    const struct struct_mem* mem;  // 复合对象的成员信息
    int mem_num;                   // 复合对象的成员数量
} type;

/**
 * @description: json 元素的相关参数
 */
typedef struct jsonc_ele {
    char* name;                // json 元素的名称
    enum json_type type;       // json 元素的类型
    char* value;               // json 元素的值
    int num;                   // 数组和对象的元素个数
    struct struct_mem mem;     // 与 json 元素对应的复合对象的成员
    void* mem_addr;            // 复合对象成员的地址
    enum c_type c_type;        // 复合对象成员的 C 数据类型
} jsonc_ele;

typedef struct jsonc_ele jsonc_arr_mem;

#define STRUCT_NAME(name) struct_type_##name
#define struct_type_NULL NULL

#define __COUNT_ARGS(_0,   \
                     _1,   \
                     _2,   \
                     _3,   \
                     _4,   \
                     _5,   \
                     _6,   \
                     _7,   \
                     _8,   \
                     _9,   \
                     _10,  \
                     _11,  \
                     _12,  \
                     _n,   \
                     X...) \
    _n
#define COUNT_ARGS(X...) \
    __COUNT_ARGS(, ##X, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define STR_CONNECT(str) ("" str)

#define SIZEOF(type, name) sizeof(((type*)0)->name)
#define L_MEM(s_type, json_type, mem_type, mem_name, type_info, tag...) \
    {                                                                   \
#mem_type, #mem_name, json_type, sizeof(mem_type),              \
            SIZEOF(s_type, mem_name), offsetof(s_type, mem_name),       \
            struct_type##type_info, STR_CONNECT(tag)                    \
    }
#define L_INIT(s_name, s_type, s_mem...)                     \
    static const struct struct_mem struct_mem_##s_name[] = { \
        s_mem,                                               \
        {NULL, NULL, Null, 0, 0, 0, NULL, NULL}};            \
    static const struct type struct_type_##s_name[] = {      \
        {#s_type,                                            \
         sizeof(s_type),                                     \
         struct_mem_##s_name,                                \
         (sizeof(struct_mem_##s_name) / sizeof(struct struct_mem) - 1)}}
#define L_STRUCT(name) struct_type_##name
#define STRUCT(name) L_STRUCT(name)
void* jsonc_serialize(char* buf, void* st, const struct type* type);
int jsonc_deserialize(char* buf, void* st, const struct type* type);

/**
 * @description: 初始化复合类型的信息块
 * @param {} s_name 复合类型的类型名称
 * @param {} s_type 复合类型的数据类型
 * @param {} s_mem 复合类型的成员，使用MEM宏进行成员描述
 */
#define INIT(s_name, s_type, s_mem...) L_INIT(s_name, s_type, s_mem)

/**
 * @description: 描述复合类型的成员
 * @param {} s_type 复合类型的数据类型
 * @param {} json_type
 * 该成员将要保存的数据类型，可以是：字符串、数字、布尔类型三种
 * @param {} mem_type 成员的数据结构类型
 * @param {} mem_name 成员的名称
 * @param {} type_info 复合类型成员的信息块，基本数据类型此项填 NULL
 */
#define MEM(s_type, json_type, mem_type, mem_name, type_info, tag...) \
    L_MEM(s_type, json_type, mem_type, mem_name, _##type_info, tag)

/**
 * @description: 将C语言的结构体序列化为json
 * @param {char*} buf 保存序列化后的json的缓存
 * @param {void*} st 需要序列化的结构体变量的地址
 * @param {type*} type 结构体变量的类型描述
 * @return {*} 指向json起始位置的指针
 */
#define JsoncSerialize(buf, st, type) jsonc_serialize(buf, st, STRUCT(type))

/**
 * @description: 将json进行反序列化为C语言的复合类型（结构体和联合体）
 * @param {char*} buf 保存json的缓存
 * @param {void*} st  复合类型的地址
 * @param {type*} type 复合类型的类型描述
 * @return {*} 0 成功反序列化  其他 失败
 */
#define JsoncDeserialize(buf, st, type) jsonc_deserialize(buf, st, STRUCT(type))

#endif
