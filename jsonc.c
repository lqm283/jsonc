/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:29
 * @LastEditTime : 2023-01-05 06:10:46
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/jsonc.c
 */

#include "jsonc.h"

#include <stdio.h>
#include <string.h>

static inline int is_this_char(int dest, int src) {
    return (dest == src);
}

static inline int is_pointor(const char* src) {
    while (*src != 0) {
        if (is_this_char('*', *src)) {
            return 1;
        }
        src++;
    }
    return 0;
}

static int jsonc_change_string_to_json(void* buf_start,
                                       void** buf_end,
                                       const char* str) {
    int ret = 0;
    char* buf = buf_start;

    *buf++ = '"';
    while (*str != 0) {
        *buf++ = *str++;
    }
    *buf++ = '"';
    *buf_end = buf;
    return ret;
}

static int is_struct(const struct type* type) {
    const struct struct_mem* mem = type->mem;
    int length = 0;
    while (mem->mem_type != NULL) {
        length += mem->mem_length;
        mem++;
    }
    if (type->length < length) {
        return 0;
    } else {
        return 1;
    }
}

static enum c_type jsonc_get_ctype(const struct struct_mem* mem) {
    enum c_type c_type = cBase;

    if (mem->mem_length / mem->type_length > 1) {
        c_type |= cBaseArr;
    }
    if (is_pointor(mem->mem_type)) {
        c_type |= cPtrBase;
    }

    if (mem->type_info != NULL) {
        if (is_struct(mem->type_info)) {
            c_type |= cStruct;
        } else {
            c_type |= cUnion;
        }
    }

    return c_type;
}

static void* jsonc_obj_to_json(char* buf, void* st, const struct type* type) {
    const struct struct_mem* mem = type->mem;
    (void)st;
    *buf++ = '{';
    while (mem->mem_type != NULL) {
        enum c_type c_type = jsonc_get_ctype(mem);

        // 不支持联合体进行转换，跳过联合体
        if (c_type & cUnion) {
            mem++;
            continue;
        }

        jsonc_change_string_to_json(buf, (void*)&buf, mem->mem_name);
        *buf++ = ':';
        switch (c_type) {
            case cBase:
                printf("It is cBase\n");
                break;
            case cStruct:
                printf("It is cStruct\n");
                break;
            case cUnion:
                printf("It is cUnion\n");
                break;
            case cBaseArr:
                printf("It is cBaseArr\n");
                break;
            case cStructArr:
                printf("It is cStructArr\n");
                break;
            case cUnionArr:
                printf("It is cUnionArr\n");
                break;
            case cPtrBase:
                printf("It is cPtrBase\n");
                break;
            case cPtrStruct:
                printf("It is cPtrStruct\n");
                break;
            case cPtrUnion:
                printf("It is cPtrUnion\n");
                break;
            case cPtrBaseArr:
                printf("It is cPtrBaseArr\n");
                break;
            case cPtrStructArr:
                printf("It is cPtrStructArr\n");
                break;
            case cPtrUnionArr:
                printf("It is cPtrUnionArr\n");
                break;
            default:
                break;
        }
        mem++;
        if (mem->mem_type != NULL) {
            *buf++ = ',';
        }
    }
    *buf++ = '}';
    return buf;
}

void* jsonc_serialize(char* buf, void* st, const struct type* type) {
    void* ret = NULL;

    if (st == NULL) {
        return ret;
    }
    ret = jsonc_obj_to_json(buf, st, type);
    if (ret) {
        *(char*)ret++ = '\0';
        return buf;
    }
    return ret;
}
