/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:29
 * @LastEditTime : 2023-01-05 09:01:50
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/jsonc.c
 */

#include "jsonc.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum mult_type { Struct, Union };
enum c_base_type {
    cInt8,
    cUInt8,
    cInt16,
    cUInt16,
    cInt32,
    cUInt32,
    cInt64,
    cUInt64,
    cFloat,
    cDouble
};

static const char* BOOL[] = {"false", "true"};
static const char* jsonc_type_int8[] = {"char", "int8_t", "int8", "i8", NULL};
static const char* jsonc_type_uint8[] = {"uint8_t", "u8", "unsigned char", "uint8", NULL};
static const char* jsonc_type_int16[] =
    {"short", "int16_t", "short int", "int16", "i16", NULL};
static const char* jsonc_type_uint16[] = {"uint16_t",
                                          "u16",
                                          "unsigned short",
                                          "unsigned short int",
                                          NULL};
static const char* jsonc_type_int32[] = {"int", "int32_t", "int32", "i32", NULL};
static const char* jsonc_type_uint32[] =
    {"int", "uint32_t", "u32", "unsigned int", "uint32", NULL};
static const char* jsonc_type_int64[] =
    {"int64_t", "long long", "long long int", "int64", "i64", NULL};
static const char* jsonc_type_uint64[] = {"uint64_t",
                                          "u64",
                                          "unsigned long long",
                                          "long long unsigned int",
                                          "unsigned long long int",
                                          "uint64",
                                          NULL};
static const char* jsonc_type_float[] = {"float", NULL};
static const char* jsonc_type_double[] = {"double", NULL};

static const char** jsonc_c_base_type[] = {jsonc_type_int8,
                                           jsonc_type_uint8,
                                           jsonc_type_int16,
                                           jsonc_type_uint16,
                                           jsonc_type_int32,
                                           jsonc_type_uint32,
                                           jsonc_type_int64,
                                           jsonc_type_uint64,
                                           jsonc_type_float,
                                           jsonc_type_double,
                                           NULL};

/**
 * @description: jsonc 的错误定义
 */
#define JSON_NULL 1  /* 给 json 字符串是一个空字符串 */
#define JSON_ROOT 2  /* 根节点错误，该 json 字符串不是一个有效的 json */
#define JSON_OBJ 3   /* 对象错误，可能是由于括号或者引号不匹配引起 */
#define JSON_TRCOM 4 /*  对象出现尾随逗号 */
#define JSON_EOFE 5  /* json 文件结尾存在多余的字符 */
#define JSON_ELE 6   /* json 元素存在错误 */
#define JSON_STRNOEND 7     /* 字符串没有结尾双引号 */
#define JSON_NUM 8          /* 数字错误 */
#define JSON_BOOL 9         /* 布尔类型错误 */
#define JSON_ARRAY 10       /* 数组错误 */
#define JSON_UNELE 11       /* 创建元素失败 */
#define JSON_ALLOC 12       /* 分配内存失败 */
#define JSON_TREE 13        /* json 树转换失败 */
#define JSON_MATCH 14       /* json元素和复合类型成员匹配失败 */
#define JSON_UNKOEN_TYPE 15 /* 在转换的过程中出现未知的类型 */
#define JSON_STR 16         /* 非字符串类型 */
#define JSON_TYPE 17        /* 类型不匹配 */
#define JSON_CPY 18         /* 值复制发生错误 */
#define JSON_GET_STRING 19  /* 获取string发生错误 */
#define JSON_GET_OBJ 20     /* 获取obj发生错误 */
#define JSON_GET_ARR 21     /* 获取arr发生错误 */
#define JSON_GET_NUM 22     /* 获取num发生错误 */
#define JSON_NULL_VAL 23    /* null值错误 */
#define JSON_GET_NULL 24    /* 获取null发生错误 */

static void* jsonc_change_cbasearr_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem);
static void* jsonc_change_cptrbase_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem);
static void* jsonc_change_cptrbasearr_to_json(char* buf,
                                              void* st,
                                              const struct struct_mem* mem);
static void* jsonc_change_cstructarr_to_json(char* buf,
                                             void* st,
                                             const struct struct_mem* mem);
static void* jsonc_change_cptrstruct_to_json(char* buf,
                                             void* st,
                                             const struct struct_mem* mem);
static void* jsonc_change_cptrstructarr_to_json(char* buf,
                                                void* st,
                                                const struct struct_mem* mem);

// 辅助函数

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

static void get_tag_name(char* buf, const char* str) {
    while (*str != ',' && *str != 0) {
        if (isalpha(*str)) {
            *buf++ = *str++;
        } else {
            break;
        }
    }
    *buf = '\0';
}

static int is_omitempty(const char* str) {
    char* cmp = "omitempty";

    int ret = 1;

    while (*str != '\0') {
        if (*str++ == ',') {
            break;
        }
    }

    while (!isalpha(*str)) {
        str++;
    };

    while (*cmp != '\0') {
        if ((*cmp != *str && *cmp != (*str + 0x20)) || !isalpha(*str)) {
            return 0;
        }
        cmp++;
        str++;
    }

    if (isalpha(*str)) {
        return 0;
    }

    return ret;
}

static enum c_base_type is_base_type(const char* src) {
    const char*** base_type = jsonc_c_base_type;
    int i = 0;
    enum c_base_type type = cInt8;
    const char* str;
    const char* s;

    while (*base_type != NULL) {
        while ((*base_type)[i] != NULL) {
            str = (*base_type)[i];
            s = src;
            while (*s != 0 && *str != 0) {
                if (*s != *str) {
                    break;
                }
                s++;
                (str)++;
            }
            if (*str == 0) {
                return type;
            }
            i++;
        }
        i = 0;
        base_type++;
        type++;
    }
    return -1;
}

// 序列话函数

static int jsonc_change_null_to_json(void* buf_start, void** buf_end) {
    strcpy(buf_start, "null");

    buf_start += 4;

    *buf_end = buf_start;

    return 0;
}

static int jsonc_change_string_to_json(void* buf_start, void** buf_end, const char* str) {
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

static int jsonc_change_num_to_json(void* buf_start,
                                    void** buf_end,
                                    void* st,
                                    const struct struct_mem* mem) {
    char num[64] = {0};
    char* str = num;

    switch (is_base_type(mem->mem_type)) {
        case cInt8:
            sprintf(num, "%d", *(char*)st);
            break;
        case cUInt8:
            sprintf(num, "%u", *(unsigned char*)st);
            break;
        case cInt16:
            sprintf(num, "%d", *(short*)st);
            break;
        case cUInt16:
            sprintf(num, "%u", *(unsigned short*)st);
            break;
        case cInt32:
            sprintf(num, "%d", *(int*)st);
            break;
        case cUInt32:
            sprintf(num, "%u", *(unsigned int*)st);
            break;
        case cInt64:
            sprintf(num, "%lld", *(long long*)st);
            break;
        case cUInt64:
            sprintf(num, "%llu", *(unsigned long long*)st);
            break;
        case cFloat:
            sprintf(num, "%f", *(float*)st);
            break;
        case cDouble:
            sprintf(num, "%lf", *(double*)st);
            break;
        default:
            *buf_end = NULL;
            return -JSON_TYPE;
            break;
    }
    while (*str != '\0') {
        *(char*)buf_start++ = *str++;
    }
    *buf_end = buf_start;
    return 0;
}

static int jsonc_change_bool_to_json(void* buf_start,
                                     void** buf_end,
                                     void* st,
                                     const struct struct_mem* mem) {
    char buf[8] = {0};
    char* str = buf;
    const char* bool;

    switch (is_base_type(mem->mem_type)) {
        case cInt8:
        case cUInt8:
            bool = BOOL[*(char*)st ? True : False];
            break;
        case cInt16:
        case cUInt16:
            bool = BOOL[*(short*)st ? True : False];
            break;
        case cInt32:
        case cUInt32:
            bool = BOOL[*(int*)st ? True : False];
            break;
        case cInt64:
        case cUInt64:
            bool = BOOL[*(long long*)st ? True : False];
            break;
        case cFloat:
            bool = BOOL[*(float*)st ? True : False];
            break;
        case cDouble:
            bool = BOOL[*(double*)st ? True : False];
            break;
        default:
            break;
    }
    sprintf(buf, "%s", bool);
    while (*str != '\0') {
        *(char*)buf_start++ = *str++;
    }
    *buf_end = buf_start;
    return 0;
}

static void* jsonc_change_cbase_to_json(char* buf,
                                        void* st,
                                        const struct struct_mem* mem) {
    void* ret = NULL;
    switch (mem->struct_type) {
        case Str:
            jsonc_change_string_to_json(buf, &ret, st);
            break;
        case Num:
            jsonc_change_num_to_json(buf, &ret, st, mem);
            break;
        case Bool:
            jsonc_change_bool_to_json(buf, &ret, st, mem);
            break;
        default:
            break;
    }
    return ret;
}

static void* jsonc_change_cbasearr_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem) {
    void* ret = NULL;
    if (mem->struct_type == Str) {
        jsonc_change_string_to_json(buf, &ret, st);
    } else {
        int length = mem->mem_length / mem->type_length;
        *buf++ = '[';

        for (int i = 0; i < length; i++) {
            buf = jsonc_change_cbase_to_json(buf, st + (i * mem->type_length), mem);
            if ((i + 1) != length) {
                *buf++ = ',';
            }
        }

        *buf++ = ']';
        return buf;
    }
    return ret;
}

static void* jsonc_change_cptrbase_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem) {
    void* ret = NULL;
    st = (void*)(*(long*)st);
    if (st == NULL) {
        jsonc_change_null_to_json(buf, &ret);
    } else {
        ret = jsonc_change_cbase_to_json(buf, st, mem);
    }
    return ret;
}

static void* jsonc_change_cptrbasearr_to_json(char* buf,
                                              void* st,
                                              const struct struct_mem* mem) {
    void* addr;
    int length = mem->mem_length / mem->type_length;
    *buf++ = '[';
    for (int i = 0; i < length; i++) {
        addr = st + (i * mem->type_length);
        addr = (void*)(*(long*)addr);

        if (addr == NULL) {
            jsonc_change_null_to_json(buf, (void*)&buf);
        } else {
            buf = jsonc_change_cbase_to_json(buf, addr, mem);
        }
        if ((i + 1) != length) {
            *buf++ = ',';
        }
    }
    *buf++ = ']';
    return buf;
}

static void* jsonc_change_cstruct_to_json(char* buf, void* st, const struct type* type) {
    char tag_name[100];
    const struct struct_mem* mem = type->mem;
    (void)st;
    *buf++ = '{';
    while (mem->mem_type != NULL) {
        enum c_type c_type = jsonc_get_ctype(mem);

        // 不支持联合体进行转换，跳过联合体，但是只有一个成员的的联合体会被当做结构体处理
        if (c_type & cUnion) {
            mem++;
            continue;
        }
        get_tag_name(tag_name, mem->tag);

        // 判断使用有 omitempty ，有则跳过空值
        if (is_omitempty(mem->tag)) {
            // @todo 这个功能比较复杂，留待后续实现
        }

        jsonc_change_string_to_json(buf,
                                    (void*)&buf,
                                    strcmp(tag_name, "") ? tag_name : mem->mem_name);
        *buf++ = ':';
        switch (c_type) {
            case cBase:
                buf = jsonc_change_cbase_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cStruct:
                buf = jsonc_change_cstruct_to_json(buf,
                                                   st + mem->mem_offset,
                                                   mem->type_info);
                break;
            case cBaseArr:
                buf = jsonc_change_cbasearr_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cStructArr:
                buf = jsonc_change_cstructarr_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cPtrBase:
                buf = jsonc_change_cptrbase_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cPtrStruct:
                buf = jsonc_change_cptrstruct_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cPtrBaseArr:
                buf = jsonc_change_cptrbasearr_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cPtrStructArr:
                buf = jsonc_change_cptrstructarr_to_json(buf, st + mem->mem_offset, mem);
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

static void* jsonc_change_cstructarr_to_json(char* buf,
                                             void* st,
                                             const struct struct_mem* mem) {
    int length = mem->mem_length / mem->type_length;
    *buf++ = '[';
    for (int i = 0; i < length; i++) {
        buf = jsonc_change_cstruct_to_json(buf,
                                           st + (i * mem->type_info->length),
                                           mem->type_info);
        if ((i + 1) != length) {
            *buf++ = ',';
        }
    }

    *buf++ = ']';
    return buf;
}

static void* jsonc_change_cptrstruct_to_json(char* buf,
                                             void* st,
                                             const struct struct_mem* mem) {
    void* ret = NULL;
    st = (void*)(*(long*)st);
    if (st == NULL) {
        jsonc_change_null_to_json(buf, &ret);
    } else {
        ret = jsonc_change_cstruct_to_json(buf, st, mem->type_info);
    }
    return ret;
}

static void* jsonc_change_cptrstructarr_to_json(char* buf,
                                                void* st,
                                                const struct struct_mem* mem) {
    void* addr;
    int length = mem->mem_length / mem->type_length;
    *buf++ = '[';
    for (int i = 0; i < length; i++) {
        addr = st + (i * mem->type_length);
        addr = (void*)(*(long*)addr);
        if (addr == NULL) {
            jsonc_change_null_to_json(buf, (void*)&buf);
        } else {
            buf = jsonc_change_cstruct_to_json(buf, addr, mem->type_info);
        }
        if ((i + 1) != length) {
            *buf++ = ',';
        }
    }
    *buf++ = ']';
    return buf;
}

// 反序列化函数

void* jsonc_serialize(char* buf, void* st, const struct type* type) {
    void* ret = NULL;

    if (st == NULL) {
        return ret;
    }
    ret = jsonc_change_cstruct_to_json(buf, st, type);
    if (ret) {
        *(char*)ret++ = '\0';
        return buf;
    }
    return ret;
}
