/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:34
 * @LastEditTime : 2022-06-09 15:30:40
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

enum json_type { Str, Num, Bool, MultArr, Obj, Arr };
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
#define L_MEM(s_type, json_type, mem_type, mem_name, type_info) \
  {                                                             \
#mem_type, #mem_name, json_type, sizeof(mem_type),          \
        SIZEOF(s_type, mem_name), offsetof(s_type, mem_name),   \
        struct_type##type_info                                  \
  }
#define L_INIT(s_name, s_type, s_mem...)                   \
  static const struct struct_mem struct_mem_##s_name[] = { \
      s_mem, {NULL, NULL, 0, 0, 0, 0, NULL}};              \
  static const struct type struct_type_##s_name[] = {      \
      {#s_type, sizeof(s_type), struct_mem_##s_name,       \
       (sizeof(struct_mem_##s_name) / sizeof(struct struct_mem) - 1)}}
#define L_STRUCT(name) struct_type_##name

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
#define MEM(s_type, json_type, mem_type, mem_name, type_info) \
  L_MEM(s_type, json_type, mem_type, mem_name, _##type_info)

/**
 * @description: 为函数传入结构体的信息块
 * @param {} name 结构体的名称
 */
#define STRUCT(name) L_STRUCT(name)

/**
 * @description: 将C语言的结构体序列化为json
 * @param {char*} buf 保存序列化后的json的缓存
 * @param {void*} st 需要序列化的结构体变量的地址
 * @param {type*} type 结构体变量的类型描述
 * @return {*} 指向json起始位置的指针
 */
void* jsonc_serialize(char* buf, void* st, const struct type* type);

/**
 * @description: 将json进行反序列化为C语言的复合类型（结构体和联合体）
 * @param {char*} buf 保存json的缓存
 * @param {void*} st  复合类型的地址
 * @param {type*} type 复合类型的类型描述
 * @return {*} 0 成功反序列化  其他 失败
 */
int jsonc_deserialize(char* buf, void* st, const struct type* type);

#endif
