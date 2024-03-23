/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:29
 * @LastEditTime : 2024-03-23 19:16:31
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/jsonc.c
 */

#include "jsonc.h"

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum c_base_type {
    cNone,
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
static const char* jsonc_type_float[] = {"float", "float32_t", "float32", NULL};
static const char* jsonc_type_double[] = {"double", "float64_t", "float64", NULL};

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
#define JSON_NORMAL 0 /* 正常 */
#define JSON_NULL 1   /* 给定的 json 字符串是一个空字符串 */
#define JSON_ROOT 2   /* 根节点错误，该 json 字符串不是一个有效的 json */
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
#define JSON_OBJ_EMPTY 25   /* 预期序列化的对象是一个空对象 */

static int jsonc_check_number(char* start_num, char** end_num);
static int jsonc_check_string(char* start_str, char** end_str);
static int jsonc_check_array(char* start_array, char** end_array);
static int jsonc_check_obj(char* start_obj, char** end_obj);

static int jsonc_change_cbasearr_to_json(char* buf_start,
                                         char** buf_end,
                                         void* st,
                                         const struct struct_mem* mem);
static int jsonc_change_cptrbase_to_json(char* buf_start,
                                         char** buf_end,
                                         void* st,
                                         const struct struct_mem* mem);
static int jsonc_change_cptrbasearr_to_json(char* buf_start,
                                            char** buf_end,
                                            void* st,
                                            const struct struct_mem* mem);
static int jsonc_change_cstructarr_to_json(char* buf_start,
                                           char** buf_end,
                                           void* st,
                                           const struct struct_mem* mem);
static int jsonc_change_cptrstruct_to_json(char* buf_start,
                                           char** buf_end,
                                           void* st,
                                           const struct struct_mem* mem);
static int jsonc_change_cptrstructarr_to_json(char* buf_start,
                                              char** buf_end,
                                              void* st,
                                              const struct struct_mem* mem);

static int jsonc_check_obj(char* start_obj, char** end_obj);

static int jsonc_change_alone(struct jsonc_ele* ele);
int jsonc_change_to_arr(struct jsonc_ele* ele);
int jsonc_change_to_base(struct jsonc_ele* ele);
int jsonc_change_to_union(char* buf, void* st, const struct type* type);
int jsonc_change_to_struct(char* buf, void* st, const struct type* type);
int jsonc_change_to_obj(char* buf, void* st, const struct type* type);
static int jsonc_check_json(char* src);

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
        if (isalpha((int)*str)) {
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

    while (!isalpha((int)*str)) {
        str++;
    };

    while (*cmp != '\0') {
        if ((*cmp != *str && *cmp != (*str + 0x20)) || !isalpha((int)*str)) {
            return 0;
        }
        cmp++;
        str++;
    }

    if (isalpha((int)*str)) {
        return 0;
    }

    return ret;
}

static enum c_base_type is_base_type(const char* src) {
    const char*** base_type = jsonc_c_base_type;
    int i = 0, count = 0;
    enum c_base_type type = cInt8;
    char s[100];
    const char* str;

    while (src[count] != '*' && src[count] != '\0') {
        s[count] = src[count];
        count++;
    }
    s[count] = '\0';
    while (count--) {
        if (src[count] == '*' || isspace((int)src[count])) {
            s[count] = '\0';
        } else {
            break;
        }
    }

    while (*base_type != NULL) {
        while ((*base_type)[i] != NULL) {
            str = (*base_type)[i];

            if (!strcmp(s, str)) {
                return type;
            }
            i++;
        }
        i = 0;
        base_type++;
        type++;
    }
    return cNone;
}

// 序列话函数

static int jsonc_change_null_to_json(char* buf_start, char** buf_end) {
    strcpy(buf_start, "null");

    buf_start += 4;

    *buf_end = buf_start;

    return 0;
}

static int jsonc_change_char_to_json(char* buf_start, char** buf_end, const char* str) {
    int ret = 0;
    char* buf = buf_start;
    *buf++ = '"';
    *buf++ = *str;
    *buf++ = '"';
    *buf_end = buf;
    return ret;
}

static int jsonc_change_str_to_json(char* buf_start, char** buf_end, const char* str) {
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

static int jsonc_change_num_to_json(char* buf_start,
                                    char** buf_end,
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

static int jsonc_change_bool_to_json(char* buf_start,
                                     char** buf_end,
                                     void* st,
                                     const struct struct_mem* mem) {
    char buf[8] = {0};
    char* str = buf;
    const char* bool = BOOL[False];

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
            bool = BOOL[False];
            break;
    }
    sprintf(buf, "%s", bool);
    while (*str != '\0') {
        *(char*)buf_start++ = *str++;
    }
    *buf_end = buf_start;
    return 0;
}

static int jsonc_change_obj_to_json(char* buf_start, char** buf_end, void* st) {
    // 处理空对象
    if (st == NULL) {
        jsonc_change_null_to_json(buf_start, &buf_start);
        *buf_end = buf_start;
        return 0;
    }

    // 检查任意对象的合法性
    if (jsonc_check_json((char*)st) && jsonc_check_string(st, NULL) &&
        jsonc_check_number(st, NULL) && jsonc_check_array(st, NULL)) {
        return -0xff;
    }

    char* str = st;
    while (*str != '\0') {
        *buf_start++ = *str++;
    }
    *buf_end = buf_start;
    return 0;
}

static int jsonc_change_cbase_to_json(char* buf_start,
                                      char** buf_end,
                                      void* st,
                                      const struct struct_mem* mem) {
    int ret = 0;
    switch (mem->struct_type) {
        case Str:
            if (jsonc_get_ctype(mem) == cPtrBase) {
                ret = jsonc_change_str_to_json(buf_start, &buf_start, st);
            } else {
                if (mem->mem_length / mem->type_length == 1) {
                    ret = jsonc_change_char_to_json(buf_start, &buf_start, st);
                } else {
                    ret = jsonc_change_str_to_json(buf_start, &buf_start, st);
                }
            }
            break;
        case Num:
            ret = jsonc_change_num_to_json(buf_start, &buf_start, st, mem);
            break;
        case Bool:
            ret = jsonc_change_bool_to_json(buf_start, &buf_start, st, mem);
            break;
        case Obj:
        case Any:
            ret = jsonc_change_obj_to_json(buf_start, &buf_start, st);
            break;
        default:
            break;
    }
    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cbasearr_to_json(char* buf_start,
                                         char** buf_end,
                                         void* st,
                                         const struct struct_mem* mem) {
    int ret = 0;
    if (mem->struct_type == Str) {
        ret = jsonc_change_str_to_json(buf_start, &buf_start, st);
    } else {
        int length = mem->mem_length / mem->type_length;
        *buf_start++ = '[';

        for (int i = 0; i < length; i++) {
            ret = jsonc_change_cbase_to_json(buf_start,
                                             &buf_start,
                                             (void*)((long)st + (i * mem->type_length)),
                                             mem);
            if ((i + 1) != length) {
                *buf_start++ = ',';
            }
        }

        *buf_start++ = ']';
    }
    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cptrbase_to_json(char* buf_start,
                                         char** buf_end,
                                         void* st,
                                         const struct struct_mem* mem) {
    int ret = 0;
    st = (void*)(*(long*)st);
    if (st == NULL) {
        ret = jsonc_change_null_to_json(buf_start, &buf_start);
    } else {
        ret = jsonc_change_cbase_to_json(buf_start, &buf_start, st, mem);
    }
    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cptrbasearr_to_json(char* buf_start,
                                            char** buf_end,
                                            void* st,
                                            const struct struct_mem* mem) {
    void* addr;
    int ret = 0;
    int length = mem->mem_length / mem->type_length;
    *buf_start++ = '[';
    for (int i = 0; i < length; i++) {
        addr = (void*)((long)st + (i * mem->type_length));
        addr = (void*)(*(long*)addr);

        if (addr == NULL) {
            ret = jsonc_change_null_to_json(buf_start, &buf_start);
        } else {
            ret = jsonc_change_cbase_to_json(buf_start, &buf_start, addr, mem);
        }
        if (ret) {
            return ret;
        }
        if ((i + 1) != length) {
            *buf_start++ = ',';
        }
    }
    *buf_start++ = ']';

    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cstruct_to_json(char* buf_start,
                                        char** buf_end,
                                        void* st,
                                        const struct type* type) {
    char tag_name[100];
    const struct struct_mem* mem = type->mem;
    int ret = 0;
    *buf_start++ = '{';
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

        ret = jsonc_change_str_to_json(buf_start,
                                       &buf_start,
                                       strcmp(tag_name, "") ? tag_name : mem->mem_name);
        *buf_start++ = ':';
        switch (c_type) {
            case cBase:
                ret = jsonc_change_cbase_to_json(buf_start,
                                                 &buf_start,
                                                 (void*)((long)st + mem->mem_offset),
                                                 mem);
                break;
            case cStruct:
                ret = jsonc_change_cstruct_to_json(buf_start,
                                                   &buf_start,
                                                   (void*)((long)st + mem->mem_offset),
                                                   mem->type_info);
                break;
            case cBaseArr:
                ret = jsonc_change_cbasearr_to_json(buf_start,
                                                    &buf_start,
                                                    (void*)((long)st + mem->mem_offset),
                                                    mem);
                break;
            case cStructArr:
                ret = jsonc_change_cstructarr_to_json(buf_start,
                                                      &buf_start,
                                                      (void*)((long)st + mem->mem_offset),
                                                      mem);
                break;
            case cPtrBase:
                ret = jsonc_change_cptrbase_to_json(buf_start,
                                                    &buf_start,
                                                    (void*)((long)st + mem->mem_offset),
                                                    mem);
                break;
            case cPtrStruct:
                ret = jsonc_change_cptrstruct_to_json(buf_start,
                                                      &buf_start,
                                                      (void*)((long)st + mem->mem_offset),
                                                      mem);
                break;
            case cPtrBaseArr:
                ret =
                    jsonc_change_cptrbasearr_to_json(buf_start,
                                                     &buf_start,
                                                     (void*)((long)st + mem->mem_offset),
                                                     mem);
                break;
            case cPtrStructArr:
                ret = jsonc_change_cptrstructarr_to_json(
                    buf_start,
                    &buf_start,
                    (void*)((long)st + mem->mem_offset),
                    mem);
                break;
            default:
                break;
        }
        if (ret) {
            return ret;
        }
        mem++;
        if (mem->mem_type != NULL) {
            *buf_start++ = ',';
        }
    }
    *buf_start++ = '}';
    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cstructarr_to_json(char* buf_start,
                                           char** buf_end,
                                           void* st,
                                           const struct struct_mem* mem) {
    int length = mem->mem_length / mem->type_length;
    int ret = 0;

    *buf_start++ = '[';
    for (int i = 0; i < length; i++) {
        ret =
            jsonc_change_cstruct_to_json(buf_start,
                                         &buf_start,
                                         (void*)((long)st + (i * mem->type_info->length)),
                                         mem->type_info);
        if (ret) {
            return ret;
        }
        if ((i + 1) != length) {
            *buf_start++ = ',';
        }
    }

    *buf_start++ = ']';
    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cptrstruct_to_json(char* buf_start,
                                           char** buf_end,
                                           void* st,
                                           const struct struct_mem* mem) {
    int ret = 0;
    st = (void*)(*(long*)st);
    if (st == NULL) {
        ret = jsonc_change_null_to_json(buf_start, &buf_start);
    } else {
        ret = jsonc_change_cstruct_to_json(buf_start, &buf_start, st, mem->type_info);
    }
    *buf_end = buf_start;
    return ret;
}

static int jsonc_change_cptrstructarr_to_json(char* buf_start,
                                              char** buf_end,
                                              void* st,
                                              const struct struct_mem* mem) {
    void* addr;
    int ret = 0;
    int length = mem->mem_length / mem->type_length;
    *buf_start++ = '[';
    for (int i = 0; i < length; i++) {
        addr = (void*)((long)st + (i * mem->type_length));
        addr = (void*)(*(long*)addr);
        if (addr == NULL) {
            ret = jsonc_change_null_to_json(buf_start, (void*)&buf_start);
        } else {
            ret =
                jsonc_change_cstruct_to_json(buf_start, &buf_start, addr, mem->type_info);
        }
        if (ret) {
            return ret;
        }
        if ((i + 1) != length) {
            *buf_start++ = ',';
        }
    }
    *buf_start++ = ']';
    *buf_end = buf_start;
    return ret;
}

// 反序列化函数

static inline void skipspace(char** s) {
    while (isspace((int)**s)) {
        (*s)++;
    }
}

static inline int skipescape(char** s) {
    if (**s == '\\') {
        (*s) += 2;
        return 1;
    }
    return 0;
}

static inline void skipstr(char** s) {
    if (**s != '"') {
        return;
    }
    (*s)++;
    while (**s != '"' && **s != '\0') {
        skipescape(s);
        (*s)++;
    }
    if (**s == '"') {
        (*s)++;
    }
}

static int jsonc_check_number(char* start_num, char** end_num) {
    int sign, decimal, index;
    sign = 0;
    index = 0;
    decimal = 0;
    if (*start_num == '-') {
        start_num++;
    }

    while (*start_num != 0 && !isspace((int)*start_num)) {
        switch (*start_num) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
            case '+':
            case '-':
                if (sign != 0 || index == 0) {
                    *end_num = start_num;
                    return -JSON_NUM;
                } else {
                    sign = 1;
                }
                break;
            case 'e':
            case 'E':
                if (index != 0) {
                    *end_num = start_num;
                    return -JSON_NUM;
                } else {
                    index = 1;
                }
                break;
            case '.':
                if (index != 0 || decimal != 0) {
                    *end_num = start_num;
                    return -JSON_NUM;
                } else {
                    decimal = 1;
                }
                break;
            case ',':
            case '}':
            case ']':
                goto num_end;
            default:
                return -JSON_NUM;
        }
        start_num++;
    }

num_end:
    if (end_num != NULL) {
        *end_num = start_num;
    }
    return 0;
}

static int jsonc_check_string(char* start_str, char** end_str) {
    if (*start_str != '"') {
        return -JSON_ELE;
    } else {
        start_str++;
    }
    while (*start_str != '"' && *start_str != 0) {
        if (!skipescape(&start_str)) {
            start_str++;
        }
    }
    if (*start_str == 0) {
        return -JSON_STRNOEND;
    }
    start_str++;
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return 0;
};

static int jsonc_check_null(char* start_obj, char** end_obj) {
    int ret = 0;
    if (memcmp(start_obj, "null", 4) != 0) {
        return -JSON_NULL_VAL;
    }
    *end_obj = start_obj + 4;
    return ret;
}

static int jsonc_check_bool(char* start_bool, char** end_bool) {
    int ret = 0;

    if (*start_bool == 'f') {
        if (memcmp(start_bool, BOOL[False], 5)) {
            return -JSON_BOOL;
        }
        start_bool += 5;
    } else if (*start_bool == 't') {
        if (memcmp(start_bool, BOOL[True], 4)) {
            return -JSON_BOOL;
        }
        start_bool += 4;
    } else {
        return -JSON_BOOL;
    }
    if (!isspace((int)*(start_bool)) && *start_bool != ',' && *start_bool != ']' &&
        *start_bool != '}') {
        ret = -JSON_BOOL;
    }
    if (end_bool != NULL) {
        *end_bool = start_bool;
    }
    return ret;
}

static int jsonc_check_array(char* start_array, char** end_array) {
    int ret = 0;

    skipspace(&start_array);
    if (*start_array != '[') {
        return -JSON_ARRAY;
    }
    start_array++;

    while (*start_array != ']' && *start_array != 0) {
        skipspace(&start_array);
        switch (*start_array) {
            case '"':
                ret = jsonc_check_string(start_array, &start_array);
                if (ret) {
                    goto array_end;
                }
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '-':
                ret = jsonc_check_number(start_array, &start_array);
                if (ret) {
                    goto array_end;
                }
                break;
            case 't':  // bool
            case 'f':
                ret = jsonc_check_bool(start_array, &start_array);
                if (ret) {
                    goto array_end;
                }
                break;
            case '[':  // 数组
                ret = jsonc_check_array(start_array, &start_array);
                if (ret) {
                    goto array_end;
                }
                break;
            case '{':  // 对象
                ret = jsonc_check_obj(start_array, &start_array);
                if (ret) {
                    goto array_end;
                }
                break;
            case 'n':
                ret = jsonc_check_null(start_array, &start_array);
                break;
            case ']':
                break;
            default:
                ret = -JSON_ARRAY;
                goto array_end;
        }

        skipspace(&start_array);

        if (*start_array == ',') {
            start_array++;
        } else if (*start_array == ']') {
        } else {
            ret = -JSON_ARRAY;
            break;
        }
    }

array_end:
    start_array++;
    if (end_array != NULL) {
        *end_array = start_array;
    }
    return ret;
}

static int jsonc_check_element(char* start_element, char** end_element) {
    int ret = 0;
    skipspace(&start_element);
    if (*start_element == '}') {
        return ret;
    }

    ret = jsonc_check_string(start_element, &start_element);
    if (ret) {
        return -JSON_ELE;
    }

    skipspace(&start_element);
    if (*start_element++ != ':') {
        return -JSON_ELE;
    }
    skipspace(&start_element);
    switch (*start_element) {
        case '"':
            ret = jsonc_check_string(start_element, &start_element);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '-':
            ret = jsonc_check_number(start_element, &start_element);
            break;
        case 't':
        case 'f':
            ret = jsonc_check_bool(start_element, &start_element);
            break;
        case '[':
            ret = jsonc_check_array(start_element, &start_element);
            break;
        case '{':
            ret = jsonc_check_obj(start_element, &start_element);
            break;
        case 'n':
            ret = jsonc_check_null(start_element, &start_element);
            break;
        default:
            ret = -JSON_ELE;
            break;
    }
    if (end_element != NULL) {
        *end_element = start_element;
    }
    return ret;
}

static int jsonc_check_obj(char* start_obj, char** end_obj) {
    int ret = 0;
    char* str;

    str = start_obj;
    skipspace(&str);
    if (*str == '{') {
        str++;
    } else {
        return -JSON_OBJ;
    }
    do {
        ret = jsonc_check_element(str, &str);
        if (ret) {
            return ret;
        }
        skipspace(&str);
        if (*str == '}') {
            str++;
            break;
        } else if (*str == ',') {
            str++;
            skipspace(&str);
            if (*str != '"') {
                return -JSON_TRCOM;
            }
        } else {
            return -JSON_ELE;
        }
    } while (*str != 0);
    if (end_obj != NULL) {
        *end_obj = str;
    }
    return ret;
}

static int jsonc_check_json(char* src) {
    int brackets, quotes;
    int ret = 0;
    char* str = src;

    brackets = 0;
    quotes = 0;
    skipspace(&str);
    if (*str == 0) {
        return -JSON_NULL;
    }

    if (*str++ != '{') {
        return -JSON_ROOT;
    }
    brackets++;

    while (*str != 0) {
        if (brackets == 0) {
            skipspace(&str);
            if (*str != 0) {
                return -JSON_EOFE;
            }else{
                break;
            }
        }
        // 跳过字符串
        if (*str == '"') {
            skipstr(&str);
            continue;
        }

        if (*str == '{' || *str == '[') {
            brackets++;
        } else if (*str == '}' || *str == ']') {
            brackets--;
        }
        str++;
    }

    if ((brackets != 0) || (quotes % 2)) {
        return -JSON_OBJ;
    }

    str = src;
    skipspace(&str);
    if (*str == '{') {
        str++;
        skipspace(&str);
        if (*str == '}') {
            return -JSON_NULL;
        }
    }

    ret = jsonc_check_obj(src, &str);
    return ret;
}

#define JSONCALLOC(size) malloc(size)
#define JSONFREE(json) free(json)

static const struct struct_mem* jsonc_probe_mem_and_ele(const struct struct_mem* mem,
                                                        const struct jsonc_ele* ele) {
    char tag_name[100];
    while (mem->mem_type != NULL) {
        // 匹配成员名称和tag名称
        get_tag_name(tag_name, mem->tag);
        if (!strcmp(mem->mem_name, ele->name) || !strcmp(tag_name, ele->name)) {
            return mem;
        }
        mem++;
    }
    return NULL;
}

static inline void jsonc_destroy_ele(struct jsonc_ele* ele) {
    if (ele->name != NULL) {
        JSONFREE(ele->name);
    }
    ele->name = NULL;
    if (ele->value != NULL) {
        JSONFREE(ele->value);
    }
    ele->name = NULL;
}

static inline void jsonc_destroy_ele_list(struct jsonc_ele** list) {
    int count = 0;
    if (list != NULL) {
        while (list[count] != NULL) {
            jsonc_destroy_ele(list[count]);
            JSONFREE(list[count]);
            list[count] = NULL;
            count++;
        }
        JSONFREE(list);
    }
}
static inline char* get_double_quotes(char* src) {
    while (*src != 0) {
        skipescape(&src);
        if (*src == '"') {
            return src;
        }
        src++;
    }
    return NULL;
}

static inline char* get_string(char** src) {
    char *from, *to, *string, *temp;
    if (**src != '"') {
        return NULL;
    }
    from = (*src)++;
    to = get_double_quotes(*src);
    int size = to - from;
    string = (char*)JSONCALLOC(size);
    if (!string) {
        return NULL;
    }
    temp = string;
    for (; *src < to; (*src)++) {
        *temp++ = **src;
    }
    (*src)++;
    string[size - 1] = '\0';
    return string;
}

static inline char* get_obj(char** src) {
    int count = 0;
    char* str = *src;
    if (*str++ != '{') {
        return NULL;
    }
    // 获取对象的结尾
    count++;
    while (count != 0 && *str != '\0') {
        if (*str == '{') {
            count++;
        } else if (*str == '}') {
            count--;
        } else if (*str == '"') {
            skipstr(&str);
            continue;
        }
        str++;
    }
    if (count != 0) {
        return NULL;
    }
    char* obj;

    count = (long)str - (long)*src;
    obj = JSONCALLOC(count + 1);
    if (obj == NULL) {
        return NULL;
    }
    memcpy(obj, *src, count);
    obj[count] = '\0';

    *src = str;

    return obj;
}

static inline char* get_arr(int* num, char** src) {
    int count = 0;
    char* str = *src;
    if (*str++ != '[') {
        return NULL;
    }
    *num = 0;
    // 获取数组的结尾
    count++;
    while (count != 0 && *str != '\0') {
        if (*str != ']' && !isspace((int)*str) && *num == 0) {
            *num = 1;
        }
        if (*str == '[') {
            count++;
        } else if (*str == ']') {
            count--;
        } else if (*str == '"') {
            skipstr(&str);
            continue;
        } else if (*str == ',') {
            (*num)++;
        }
        str++;
    }
    if (count != 0) {
        return NULL;
    }
    char* arr;
    if (!(*num)) {
        arr = JSONCALLOC(3);
        if (arr == NULL) {
            return NULL;
        }
        strcpy(arr, "[]");
    } else {
        count = (long)str - (long)*src;
        arr = JSONCALLOC(count + 1);
        if (arr == NULL) {
            return NULL;
        }
        memcpy(arr, *src, count);
        arr[count] = '\0';
    }
    *src = str;

    return arr;
}

static char* get_bool(char* start_str, char** end_str) {
    char* bool = JSONCALLOC(6);
    if (!bool) {
        return NULL;
    }
    if (*start_str == 't') {
        memcpy(bool, start_str, 4);
        bool[4] = '\0';
        start_str += 4;
    } else {
        memcpy(bool, start_str, 5);
        bool[5] = '\0';
        start_str += 5;
    }
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return bool;
}

static inline char* get_num(char* start_str, char** end_str) {
    char *num, *temp;
    int count;
    unsigned char i;

    temp = start_str;
    count = 0;
    while (isdigit((int)*temp) || is_this_char('-', *temp) || is_this_char('e', *temp) ||
           is_this_char('E', *temp) || is_this_char('.', *temp)) {
        temp++;
        count++;
    }

    num = JSONCALLOC(count + 1);
    if (!num) {
        return NULL;
    }
    for (i = 0; i < count; i++) {
        num[i] = (char)*start_str++;
    }
    num[count] = '\0';
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return num;
}

static char* get_null(char* start_str, char** end_str) {
    char* null = JSONCALLOC(5);
    if (!null) {
        return NULL;
    }
    for (int i = 0; i < 4; i++) {
        null[i] = *start_str++;
    }
    null[4] = '\0';
    *end_str = start_str;
    return null;
}

static int jsonc_get_value_and_type(struct jsonc_ele* ele,
                                    char* start_str,
                                    char** end_str) {
    int ret = 0;
    // 获取值和类型
    skipspace(&start_str);

    switch (*start_str) {
        case '"':  // Str
            ele->value = get_string(&start_str);
            ele->type = Str;
            break;
        case '{':  // Obj
            ele->value = get_obj(&start_str);
            ele->type = Obj;
            break;
        case '[':  // Arr
            ele->value = get_arr(&ele->num, &start_str);
            ele->type = Arr;
            break;
        case 't':
        case 'f':  // Bool
            ele->type = Bool;
            ele->value = get_bool(start_str, &start_str);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '-':  // Num
            ele->value = get_num(start_str, &start_str);
            ele->type = Num;
            break;
        case 'n':  // Null
            ele->value = get_null(start_str, &start_str);
            ele->type = Null;
            break;
        default:
            ret = -JSON_TYPE;
    }
    if (end_str != NULL) {
        *end_str = start_str;
    }
    if (ele->value == NULL) {
        ret = -JSON_CPY;
    }
    return ret;
}

static int jsonc_get_arr_ele(jsonc_arr_mem* mem, char* start_str, char** end_str) {
    int ret = 0;
    ret = jsonc_get_value_and_type(mem, start_str, end_str);
    return ret;
}

static struct jsonc_ele jsonc_get_ele(char* start_str, char** end_str) {
    struct jsonc_ele ele;
    ele.name = NULL;
    ele.value = NULL;

    // 获取元素的名称
    skipspace(&start_str);
    ele.name = get_string(&start_str);
    if (ele.name == NULL) {
        return ele;
    }

    // 获取值
    skipspace(&start_str);
    start_str++;
    skipspace(&start_str);
    jsonc_get_value_and_type(&ele, start_str, end_str);
    return ele;
}

static int jsonc_jsonstr_to_multstr(const struct jsonc_ele* ele) {
    int ret = 0;
    if (ele->c_type & cPtrBase) {
        // 使用指针保存字符串的时候要自己注意指针的越界问题，越界就是自己活该了
        strcpy(ele->mem_addr, ele->value);
    } else if (ele->c_type == cBase) {  // 尝试将数字转换为一个字符
        if (ele->type == Str) {
            memcpy(ele->mem_addr, ele->value, 1);
        } else if (ele->type == Num) {
            *(char*)ele->mem_addr = (char)strtoll(ele->value, NULL, 0);
            ((char*)ele->mem_addr)[1] = '\0';
        } else if (ele->type == Bool) {
            // memcpy(ele->mem_addr, ele->value.Bool, 1);
        }

    } else {  // 保存到数组中，可以知道数组的长度
        if (ele->type == Num) {
            *(char*)ele->mem_addr = (char)strtoll(ele->value, NULL, 0);
            ((char*)ele->mem_addr)[1] = '\0';
        } else {
            unsigned long length = strlen(ele->value);
            unsigned long capacity = ele->mem.mem_length / ele->mem.type_length;
            if (length > capacity) {
                length = capacity;
            }
            memcpy(ele->mem_addr, ele->value, length);
            if (length == capacity) {
                ((char*)ele->mem_addr)[length - 1] = '\0';
            } else {
                ((char*)ele->mem_addr)[length] = '\0';
            }
        }
    }
    return ret;
}

static int jsonc_jsonstr_to_multnum(const struct jsonc_ele* ele) {
    int ret = 0;

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
            *(char*)ele->mem_addr = (char)strtoll(ele->value, NULL, 0);
            break;
        case cInt16:
        case cUInt16:
            *(short*)ele->mem_addr = (short)strtoll(ele->value, NULL, 0);
            break;
        case cInt32:
        case cUInt32:
            *(int*)ele->mem_addr = (int)strtoll(ele->value, NULL, 0);
            break;
        case cInt64:
        case cUInt64:
            *(long long*)ele->mem_addr = strtoll(ele->value, NULL, 0);
            break;
        case cFloat:
            *(float*)ele->mem_addr = strtof(ele->value, NULL);
            break;
        case cDouble:
            *(double*)ele->mem_addr = strtod(ele->value, NULL);
            break;
        default:
            break;
    }

    return ret;
}

static inline int jsonc_assign_to_num(const struct jsonc_ele* ele, uint64_t num) {
    int ret = 0;

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
            *(char*)ele->mem_addr = num;
            break;
        case cInt16:
        case cUInt16:
            *(uint16_t*)ele->mem_addr = num;
            break;
        case cInt32:
        case cUInt32:
            *(uint32_t*)ele->mem_addr = num;
            break;
        case cInt64:
        case cUInt64:
            *(uint64_t*)ele->mem_addr = num;
            break;
        case cFloat:
            *(float*)ele->mem_addr = num;
            break;
        case cDouble:
            *(double*)ele->mem_addr = num;
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }

    return ret;
}

static int jsonc_jsonstr_to_multbool(const struct jsonc_ele* ele) {
    int ret = 0;
    char bool = False;

    if (*ele->value == '\0') {
        bool = False;
    } else if (*ele->value == '0' && strtod(ele->value, NULL) == 0) {
        bool = False;
    } else {
        if (strcmp(ele->value, BOOL[False]) == 0) {
            bool = False;
        } else {
            bool = True;
        }
    }

    ret = jsonc_assign_to_num(ele, bool);

    return ret;
}

static int jsonc_jsonnum_to_multstr(const struct jsonc_ele* ele) {
    return jsonc_jsonstr_to_multstr(ele);
}

static int jsonc_jsonnum_to_multnum(const struct jsonc_ele* ele) {
    return jsonc_jsonstr_to_multnum(ele);
}

static int jsonc_jsonnum_to_multbool(const struct jsonc_ele* ele) {
    int ret = 0;
    int bool = False;
    if (strtod(ele->value, NULL) != 0) {
        bool = True;
    }

    ret = jsonc_assign_to_num(ele, bool);

    return ret;
}

static int jsonc_jsonbool_to_multstr(const struct jsonc_ele* ele) {
    char* addr;
    if (ele->c_type == cPtrBase) {
        addr = strcpy(ele->mem_addr, ele->value);
    } else {
        unsigned long capacity = ele->mem.mem_length / ele->mem.type_length;
        addr = memcpy(ele->mem_addr, ele->value, capacity);
    }

    if (!addr) {
        return -JSON_CPY;
    } else {
        return 0;
    }
}

static int jsonc_jsonbool_to_multnum(const struct jsonc_ele* ele) {
    int ret = 0;
    char bool = False;
    if (!strcmp(ele->value, BOOL[True])) {
        bool = True;
    }

    ret = jsonc_assign_to_num(ele, bool);

    return ret;
}

static int jsonc_jsonbool_to_multbool(const struct jsonc_ele* ele) {
    return jsonc_jsonbool_to_multnum(ele);
}

static int jsonc_jsonnull_to_multstr(const struct jsonc_ele* ele) {
    *(char*)ele->mem_addr = 0;
    return 0;
}

static int jsonc_jsonnull_to_multnum(const struct jsonc_ele* ele) {
    int ret = 0;

    ret = jsonc_assign_to_num(ele, 0);

    return ret;
}

static int jsonc_jsonnull_to_multbool(const struct jsonc_ele* ele) {
    return jsonc_jsonnull_to_multnum(ele);
}

int jsonc_change_str_to_base(struct jsonc_ele* ele) {
    int ret = 0;
    switch (ele->mem.struct_type) {
        case Str:
            ret = jsonc_jsonstr_to_multstr(ele);
            break;
        case Num:
            ret = jsonc_jsonstr_to_multnum(ele);
            break;
        case Bool:
            ret = jsonc_jsonstr_to_multbool(ele);
            break;
        default:
            break;
    }
    return ret;
}

static int jsonc_change_num_to_base(const struct jsonc_ele* ele) {
    int ret = 0;
    switch (ele->mem.struct_type) {
        case Str:
            ret = jsonc_jsonnum_to_multstr(ele);
            break;
        case Num:
            ret = jsonc_jsonnum_to_multnum(ele);
            break;
        case Bool:
            ret = jsonc_jsonnum_to_multbool(ele);
            break;
        default:
            break;
    }
    return ret;
}

static int jsonc_change_bool_to_base(const struct jsonc_ele* ele) {
    int ret = 0;
    switch (ele->mem.struct_type) {
        case Str:
            ret = jsonc_jsonbool_to_multstr(ele);
            break;
        case Num:
            ret = jsonc_jsonbool_to_multnum(ele);
            break;
        case Bool:
            ret = jsonc_jsonbool_to_multbool(ele);
            break;
        default:
            break;
    }
    return ret;
}

static int jsonc_change_null_to_base(const struct jsonc_ele* ele) {
    int ret = 0;
    switch (ele->mem.struct_type) {
        case Str:
            ret = jsonc_jsonnull_to_multstr(ele);
            break;
        case Num:
            ret = jsonc_jsonnull_to_multnum(ele);
            break;
        case Bool:
            ret = jsonc_jsonnull_to_multbool(ele);
            break;
        default:
            break;
    }
    return ret;
}

int jsonc_change_to_base(struct jsonc_ele* ele) {
    int ret = 0;

    switch (ele->type) {
        case Str:
            ret = jsonc_change_str_to_base(ele);
            break;
        case Num:
            ret = jsonc_change_num_to_base(ele);
            break;
        case Bool:
            ret = jsonc_change_bool_to_base(ele);
            break;
        case Null:
            ret = jsonc_change_null_to_base(ele);
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }

    return ret;
}

int jsonc_change_obj_to_any(struct jsonc_ele** ele) {
    int len = strlen((*ele)->value);
    char* obj = malloc(len + 1);
    strcpy(obj, (*ele)->value);
    obj[len] = '\0';
    void** temp = (*ele)->mem_addr;
    *temp = (void*)obj;
    return 0;
}

int jsonc_change_num_to_any(struct jsonc_ele** ele) {
    double* num = malloc(sizeof(double));
    *num = strtod((*ele)->value, NULL);
    void** temp = (*ele)->mem_addr;
    *temp = (void*)num;
    return 0;
}

int jsonc_change_bool_to_any(struct jsonc_ele** ele) {
    double* bool = malloc(sizeof(double));
    *bool = False;
    if (!strcmp((*ele)->value, BOOL[True])) {
        *bool = True;
    }
    void** temp = (*ele)->mem_addr;
    *temp = (void*)bool;
    return 0;
}

int jsonc_change_null_to_any(struct jsonc_ele** ele) {
    void** temp = (*ele)->mem_addr;
    *temp = NULL;
    return 0;
}

int jsonc_change_any(struct jsonc_ele** ele) {
    int ret = 0;
    switch ((*ele)->type) {
        case Obj:
            ret = jsonc_change_obj_to_any(ele);
            break;
        case Arr:
            ret = jsonc_change_obj_to_any(ele);
            break;
        case Str:
            ret = jsonc_change_obj_to_any(ele);
            break;
        case Num:
            ret = jsonc_change_num_to_any(ele);
            break;
        case Bool:
            ret = jsonc_change_bool_to_any(ele);
            break;
        case Null:
            ret = jsonc_change_null_to_any(ele);
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }

    return ret;
}

static int jsonc_change_arr(struct jsonc_ele* ele) {
    int ret = 0;
    char* value = ele->value;
    jsonc_arr_mem mem;

    // 只支持一维数组，在这个函数中，数组会被降级为独自变量
    int mem_num = ele->mem.mem_length / ele->mem.type_length;

    if (*value != '[') {
        ret = -JSON_ARRAY;
    }
    skipspace(&value);
    value++;
    while (*value != ']' && mem_num--) {
        mem = *ele;
        mem.name = NULL;
        mem.value = NULL;
        mem.c_type &= ~cBaseArr;  // 降级数组

        ret = jsonc_get_arr_ele(&mem, value, &value);  // 获取一个数组元素
        if (ret) {
            jsonc_destroy_ele(&mem);
            return ret;
        }
        // @question 如果取出的依然是一个数组，该什么办？
        if (mem.type == Arr) {
        } else {
            ret = jsonc_change_alone(&mem);
        }
        jsonc_destroy_ele(&mem);
        if (ret != 0 && ret != -JSON_MATCH) {
            return ret;
        }
        ele->mem_addr = (void*)((long)ele->mem_addr + mem.mem.type_length);
        skipspace(&value);
        if (*value == ',') {
            value++;
        }
    }

    return ret;
}

static int jsonc_change_alone(struct jsonc_ele* ele) {
    int ret = 0;

    if (ele->c_type & cPtrBase) {
        ele->mem_addr = (void*)(*(long*)ele->mem_addr);
    }

    // 根据是否是复合类型执行不同的操作
    if (ele->c_type & cStruct || ele->c_type & cUnion) {
        ret = jsonc_change_to_obj(ele->value, ele->mem_addr, ele->mem.type_info);
    } else {
        ret = jsonc_change_to_base(ele);
    }
    return ret;
}

static int jsonc_change_ele_to_mem(void* st,
                                   const struct type* type,
                                   struct jsonc_ele* ele) {
    int ret = 0;
    const struct struct_mem* mem;

    mem = jsonc_probe_mem_and_ele(type->mem, ele);
    if (mem == NULL) {
        return -JSON_MATCH;
    }
    ele->mem = *mem;
    ele->mem_addr = (void*)((long)st + mem->mem_offset);
    ele->c_type = jsonc_get_ctype(mem);

    // @todo 跳过显然无法完成转换的匹配
    if ((ele->c_type & cStruct) &&
        (ele->type == Str || ele->type == Num || ele->type == Bool)) {
        return -JSON_MATCH;
        ;
    }

    if (mem->struct_type == Any) {
        // ele->mem_addr = (void*)(*(long*)ele->mem_addr);
        return jsonc_change_any(&ele);
    }

    // 根据对象成员是否是数组来执行操作
    if (ele->c_type & cBaseArr && (ele->type == Arr)) {
        ret = jsonc_change_arr(ele);
    } else {
        ret = jsonc_change_alone(ele);
    }

    return ret;
}

static const struct struct_mem* jsonc_find_best_mem(const struct type* type,
                                                    struct jsonc_ele** list) {
    int ele_num = 0;
    int max_level = -100000;
    int level = 0;
    char tag_name[100];
    const struct struct_mem* max_mem = NULL;
    const struct struct_mem* mem = type->mem;

    // 获取 json 元素的个数
    while (list[ele_num] != NULL) {
        ele_num++;
    }

    // 开始进行匹配
    while (mem->mem_type != NULL) {
        // 排除非复合类型对象和union对象
        if (mem->type_info != NULL) {
            level = 0;
            int mem_num = 0;
            int temp_ele_num = ele_num;
            const struct struct_mem* SubMem = mem->type_info->mem;
            // 获取 nion 成员的子成员个数
            while (SubMem[mem_num].mem_type != NULL) {
                mem_num++;
            }
            // 开始子成员的匹配
            while (SubMem->mem_type != NULL) {
                get_tag_name(tag_name, SubMem->tag);
                for (struct jsonc_ele** ele = list; *ele != NULL; ele++) {
                    // 匹配成员名称和tag名称
                    if (!strcmp(SubMem->mem_name, (*ele)->name) ||
                        !strcmp(tag_name, (*ele)->name)) {
                        int probe = 0;
                        mem_num--;
                        temp_ele_num--;
                        // 名称匹配上，加 10分
                        level += 10;
                        enum c_type c_type = jsonc_get_ctype(SubMem);
                        // 匹配类型
                        switch ((*ele)->type) {
                            case Num:
                            case Str:
                            case Bool:
                            case Null:
                                if (!(c_type & (cStruct & cUnion))) {
                                    level += 10;
                                    probe = 1;
                                    if (c_type & cBaseArr) {
                                        level -= 5;
                                    }
                                }
                                break;
                            case Arr:
                                if (c_type & cBaseArr) {
                                    level += 10;
                                    probe = 1;
                                } else if (c_type & (cStruct & cUnion)) {
                                    level += 5;
                                    probe = 1;
                                }
                                break;
                            case Obj:
                                if (c_type & cStruct || c_type & cUnion) {
                                    level += 10;
                                    probe = 1;
                                }
                            default:
                                break;
                        }
                        if (probe) {
                            break;
                        }
                    }
                }
                if (!temp_ele_num) {
                    break;
                }
                SubMem++;
            }
            level -= mem_num * 5;
            level -= temp_ele_num * 3;
            if (max_level < level) {
                max_mem = mem;
                max_level = level;
            }
        }
        mem++;
    }
    return max_mem;
}

static int jsonc_change_to_mem_son(void* st,
                                   const struct type* type,
                                   struct jsonc_ele** list) {
    int ret = 0;
    const struct struct_mem* mem = jsonc_find_best_mem(type, list);
    if (mem == NULL) {
        return -JSON_MATCH;
    }

    // 如果 union 的成员是指针，先进行指针的转换
    enum c_type c_type = jsonc_get_ctype(mem);
    if (c_type & cPtrBase) {
        st = (void*)(*(long*)st);
    }

    // 将json元素转换为mem的成员
    while (*list != NULL) {
        ret = jsonc_change_ele_to_mem(st, mem->type_info, *list);
        if (ret) {
            return ret;
        }
        list++;
    }
    return ret;
}

static int jsonc_change_to_self_mem(void* st,
                                    const struct type* type,
                                    struct jsonc_ele** list) {
    int ret = -JSON_MATCH;
    char tag_name[100];
    while (*list != NULL) {
        if ((*list)->type == Obj) {
            list++;
            continue;
        }

        const struct struct_mem* mem = type->mem;
        while (mem->mem_type != NULL) {
            get_tag_name(tag_name, mem->tag);
            if (!strcmp(mem->mem_name, (*list)->name) ||
                !strcmp(tag_name, (*list)->name)) {
                // 根据该元素是不是数组来执行不同的操作
                (*list)->mem = *mem;
                (*list)->mem_addr = (void*)((long)st + mem->mem_offset);
                (*list)->c_type = jsonc_get_ctype(mem);

                // @todo 跳过显然无法完成转换的匹配
                if (((*list)->c_type & cStruct) &&
                    ((*list)->type == Str || (*list)->type == Num ||
                     (*list)->type == Bool)) {
                    return -JSON_MATCH;
                    ;
                }

                // 根据对象成员是否是数组来执行操作
                if ((*list)->c_type & cBaseArr && ((*list)->type == Arr)) {
                    ret = jsonc_change_arr((*list));
                } else {
                    ret = jsonc_change_alone((*list));
                }
                if (ret) {
                    return ret;
                }
            }
            mem++;
        }
        list++;
    }

    return ret;
}

int jsonc_get_json_ele_num(char* str) {
    int count = 1;
    int end = 1;
    skipspace(&str);
    str++;
    skipspace(&str);
    while (end != 0) {
        if (*str == '"') {
            skipstr(&str);
            continue;
        } else if (*str == '[' || *str == '{') {
            end++;
        } else if (*str == ']' || *str == '}') {
            end--;
        }

        if (*str == ',') {
            if (end == 1) {
                count++;
            }
        }
        str++;
    }
    return count;
}

int jsonc_change_to_union(char* buf, void* st, const struct type* type) {
    int ret = 0;
    int ele_num = 1;
    int count = 0;
    struct jsonc_ele** list;
    struct jsonc_ele* ele;

    // 检查 json 的元素个数，只有一个元素时尝试与 union 自身的成员进行匹配
    // 有多个元素时则需要先尝试与 union 成员的成员进行匹配
    ele_num = jsonc_get_json_ele_num(buf);

    skipspace(&buf);
    buf++;
    skipspace(&buf);
    list = JSONCALLOC(sizeof(struct jsonc_ele*) * ele_num + 1);
    if (!list) {
        ret = -JSON_ALLOC;
        goto end;
    }

    // 获取所有的 json 元素
    while (*buf != '}') {
        // 获取元素
        ele = JSONCALLOC(sizeof(struct jsonc_ele));
        if (!ele) {
            ret = -JSON_ALLOC;
            goto end;
        }
        list[count] = ele;

        *ele = jsonc_get_ele(buf, &buf);
        if (ele->name == NULL || ele->value == NULL) {
            ret = -JSON_ELE;
            goto end;
        }
        count++;
        list[count] = NULL;
        skipspace(&buf);
        if (*buf == ',') {
            buf++;
        }
    }

    if (ele_num == 1) {
        // 先尝试与nion自身的成员进行匹配，不行才与其子成员进行匹配（该子成员必须是
        // union）
        ret = jsonc_change_ele_to_mem(st, type, *list);
        if (ret) {
            // 与子成员进行匹配
            ret = jsonc_change_to_mem_son(st, type, list);
        }
    } else {
        // 尝试与 nion
        // 成员的子成员进行匹配（该成员必须是结构体才行）,否则再尝试与自身的成员匹配
        ret = jsonc_change_to_mem_son(st, type, list);
        if (ret) {
            // 与自身成员匹配,以 json 为基础，成功匹配到一个就退出。
            ret = jsonc_change_to_self_mem(st, type, list);
        }
    }

end:
    jsonc_destroy_ele_list(list);

    return ret;
}

int jsonc_change_to_struct(char* buf, void* st, const struct type* type) {
    int ret = 0;
    skipspace(&buf);
    buf++;
    skipspace(&buf);

    // 开始将元素转换到复合类型成员
    while (*buf != '}') {
        // 获取元素
        struct jsonc_ele ele = jsonc_get_ele(buf, &buf);
        if (ele.name == NULL || ele.value == NULL) {
            jsonc_destroy_ele(&ele);
            return -JSON_ELE;
        }

        // 开始尝试将 json 转换为 mult 类型成员
        ret = jsonc_change_ele_to_mem(st, type, &ele);
        jsonc_destroy_ele(&ele);
        if (ret != 0 && ret != -JSON_MATCH) {
            return ret;
        }

        skipspace(&buf);
        if (*buf == ',') {
            buf++;
        }
    }
    return 0;
}

int jsonc_change_to_obj(char* buf, void* st, const struct type* type) {
    int ret = 0;

    const struct struct_mem* mem;
    int length = 0;

    // 根据复合对象是 struct 还是 union 执行不同的匹配操作
    mem = type->mem;
    while (mem->mem_type != NULL) {
        length += mem->mem_length;
        mem++;
    }
    if (type->length < length) {
        // 匹配 union 只有一个成员的 union 会被当做 struct 处理
        ret = jsonc_change_to_union(buf, st, type);
    } else {
        // 匹配 struct
        ret = jsonc_change_to_struct(buf, st, type);
    }

    return ret;
}

// 外部调用的函数

int jsonc_serialize(char* buf, void* st, const struct type* type) {
    int ret = 0;
    char* buf_start = buf;

    if (st == NULL) {
        return -JSON_OBJ_EMPTY;
    }
    ret = jsonc_change_cstruct_to_json(buf_start, &buf_start, st, type);
    if (ret) {
        return ret;
    } else {
        ret = buf_start - buf;
        *buf_start++ = '\0';
    }

    return ret;
}

int jsonc_deserialize(char* buf, void* st, const struct type* type) {
    int ret = 0;

    ret = jsonc_check_json(buf);
    if (ret) {
        return ret;
    }

    // 将json转换为复合对象
    ret = jsonc_change_to_obj(buf, st, type);
    return ret;
}
