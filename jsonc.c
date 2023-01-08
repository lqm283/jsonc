/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:29
 * @LastEditTime : 2023-01-08 18:26:45
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
#define JSON_NULL 1 /* 给定的 json 字符串是一个空字符串 */
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

static int jsonc_check_obj(char* start_obj, char** end_obj);

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

static inline void skipspace(char** s) {
    while (isspace(**s)) {
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

static int jsonc_check_number(char* start_num, char** end_num) {
    int sign, decimal, index;
    sign = 0;
    index = 0;
    decimal = 0;
    if (*start_num == '-') {
        start_num++;
    }

    while (*start_num != 0 && !isspace(*start_num)) {
        switch (*start_num) {
            case '0' ... '9':
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
    char temp[5];

    memcpy(temp, start_obj, 4);
    start_obj += 4;
    if (strcmp(temp, "null") != 0) {
        return -JSON_NULL_VAL;
    }
    *end_obj = start_obj;
    return ret;
}

static int jsonc_check_bool(char* start_bool, char** end_bool) {
    int i, length;
    int ret = 0;
    const char* bool;

    if (*start_bool == 'f') {
        bool = BOOL[0];
        length = 5;
    } else if (*start_bool == 't') {
        bool = BOOL[1];
        length = 4;
    } else {
        return -JSON_BOOL;
    }
    for (i = 0; i < length; i++) {
        if (*start_bool != bool[i]) {
            ret = -JSON_BOOL;
            return ret;
        }
        start_bool++;
    }
    if (!isspace(*(start_bool)) && *start_bool != ',' && *start_bool != ']' &&
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
            case '0' ... '9':
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
        case '0' ... '9':
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
            }
        }
        // 跳过字符串
        if (*str == '"') {
            str++;
            quotes++;
            while (*str != '"' && *str++ != 0) {
                // 忽略掉\后面的字符
                skipescape(&str);
            }
            if (*str == '"') {
                quotes++;
            }
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

#define JSONCALLOC(size) calloc(1, size)
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

static void jsonc_destroy_ele(const struct jsonc_ele* ele) {
    JSONFREE(ele->name);
    JSONFREE(ele->value);
}

static inline char* get_double_quotes(char* src) {
    while (*src++ != 0) {
        skipescape(&src);
        if (*src == '"') {
            return src;
        }
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
    string = (char*)JSONCALLOC(to - from);
    if (string != NULL) {
        temp = string;
    } else {
        return NULL;
    }
    for (; *src < to; (*src)++) {
        *temp++ = **src;
    }
    (*src)++;
    return string;
}

static inline char* get_obj(char** src) {
    int count = 0;
    char* str = *src;

    if (**src != '{') {
        return NULL;
    } else {
        count++;
    }

    while (*str++ != '}') {
        if (!isspace(*str)) {
            count++;
        }
    }
    count++;

    char* obj = (char*)JSONCALLOC(count + 1);
    if (!obj) {
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        skipspace(src);
        obj[i] = **src++;
    }
    obj[count] = '\0';
    return obj;
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
        memcpy(bool, start_str, 4);
        bool[5] = '\0';
        start_str += 5;
    }
    bool[1] = '\0';
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return bool;
}

static inline char* get_num(char* start_str, char** end_str) {
    char *num, *temp, count;
    unsigned char i;

    temp = start_str;
    count = 0;
    while (isdigit(*temp) || is_this_char('-', *temp) || is_this_char('e', *temp) ||
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

static struct jsonc_ele jsonc_get_ele(char* start_str, char** end_str) {
    struct jsonc_ele ele;

    // 获取元素的名称
    skipspace(&start_str);
    ele.name = get_string(&start_str);

    // 获取值和类型
    skipspace(&start_str);
    start_str++;
    skipspace(&start_str);

    switch (*start_str) {
        case '"':  // Str
            ele.value = get_string(&start_str);
            ele.type = Str;
            break;
        case '{':  // Obj
            ele.value = get_obj(&start_str);
            ele.type = Obj;
            break;
        case '[':  // Arr
            ele.type = Arr;
            break;
        case 't':
        case 'f':  // Bool
            ele.type = Bool;
            ele.value = get_bool(start_str, &start_str);
            break;
        case '0' ... '9':
        case '-':  // Num
            ele.value = get_num(start_str, &start_str);
            ele.type = Num;
            break;
        case 'n':  // Null
            ele.value = get_null(start_str, &start_str);
            ele.type = Null;
            break;
    }
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return ele;
}

static int jsonc_jsonstr_to_multstr(const struct jsonc_ele* ele) {
    int ret = 0;
    if (ele->c_type == cPtrBase) {
        // 使用指针保存字符串的时候要自己注意指针的越界问题，越界就是自己活该了
        strcpy(ele->mem_addr, ele->value);
    } else if (ele->c_type == cBase) {  // 尝试将数字转换为一个字符
        if (ele->type == Str) {
            memcpy(ele->mem_addr, ele->value, 1);
        } else if (ele->type == Num) {
            *(char*)ele->mem_addr = (char)strtoll(ele->value, NULL, 0);
        } else if (ele->type == Bool) {
            // memcpy(ele->mem_addr, ele->value.Bool, 1);
        }

    } else {  // 保存到数组中，可以知道数组的长度
        unsigned long length = strlen(ele->value);
        unsigned long capacity = ele->mem.mem_length / ele->mem.type_length;
        if (length > capacity) {
            length = capacity;
        }

        if (length > 1) {
            memcpy(ele->mem_addr, ele->value, length - 1);
            char* end = (char*)ele->mem_addr;
            end[length - 1] = '\0';
        } else {
            memcpy(ele->mem_addr, ele->value, length);
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
            *(long*)ele->mem_addr = strtoll(ele->value, NULL, 0);
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

static int jsonc_jsonnum_to_multstr(const struct jsonc_ele* ele) {
    return jsonc_jsonstr_to_multstr(ele);
}

static int jsonc_jsonnum_to_multnum(const struct jsonc_ele* ele) {
    return jsonc_jsonstr_to_multnum(ele);
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
            break;
        case Bool:
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
            break;
        default:
            ret = -JSON_TYPE;
            break;
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
    ele->mem_addr = st + mem->mem_offset;
    ele->c_type = jsonc_get_ctype(mem);

    if (ele->c_type & cPtrBase && !(ele->c_type & cBaseArr)) {
        ele->mem_addr = (void*)(*(long*)ele->mem_addr);
        printf("ele->mem_addr = 0x%lx\n", (long)ele->mem_addr);
    }

    if (ele->type == Obj && ele->c_type & cStruct) {
    } else if (ele->type == Obj && ele->c_type & cUnion) {
    } else if (ele->type == Arr && ele->c_type & cBaseArr) {
    } else {
        jsonc_change_to_base(ele);
    }

    return ret;
}

int jsonc_change_to_union(char* buf, void* st, const struct type* type) {
    int ret = 0;
    (void)buf;
    (void)st;
    (void)type;
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
        if (!(ele.name && ele.value)) {
            jsonc_destroy_ele(&ele);
            return -JSON_ELE;
        }

        // 开始尝试将 json 转换为 mult 类型成员
        jsonc_change_ele_to_mem(st, type, &ele);
        jsonc_destroy_ele(&ele);
        skipspace(&buf);
        if (*buf == ',') {
            buf++;
        }
    }
    return ret;
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
        // 匹配 union
        ret = jsonc_change_to_union(buf, st, type);
    } else {
        // 匹配 struct
        ret = jsonc_change_to_struct(buf, st, type);
    }

    return ret;
}

// 外部调用的函数

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
