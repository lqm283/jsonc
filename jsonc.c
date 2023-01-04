/*
 * @Author       : lqm283
 * @Date         : 2022-04-13 13:47:29
 * @LastEditTime : 2023-01-04 13:52:44
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/jsonc.c
 */

#include "jsonc.h"

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
static const char* jsonc_type_uint8[] = {"uint8_t",
                                         "u8",
                                         "unsigned char",
                                         "uint8",
                                         NULL};
static const char* jsonc_type_int16[] =
    {"short", "int16_t", "short int", "int16", "i16", NULL};
static const char* jsonc_type_uint16[] = {"uint16_t",
                                          "u16",
                                          "unsigned short",
                                          "unsigned short int",
                                          NULL};
static const char* jsonc_type_int32[] = {"int",
                                         "int32_t",
                                         "int32",
                                         "i32",
                                         NULL};
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
#define JSON_NULL 1 /* 给 json 字符串是一个空字符串 */
#define JSON_ROOT 2 /* 根节点错误，该 json 字符串不是一个有效的 json */
#define JSON_OBJ 3 /* 对象错误，可能是由于括号或者引号不匹配引起 */
#define JSON_TRCOM 4        /*  对象出现尾随逗号 */
#define JSON_EOFE 5         /* json 文件结尾存在多余的字符 */
#define JSON_ELE 6          /* json 元素存在错误 */
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
static void* jsonc_change_cmultarr_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem);
static void* jsonc_change_cptrbase_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem);
static void* jsonc_change_cptrmult_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem);
static void* jsonc_change_cptrbasearr_to_json(char* buf,
                                              void* st,
                                              const struct struct_mem* mem);
static void* jsonc_change_cptrmultarr_to_json(char* buf,
                                              void* st,
                                              const struct struct_mem* mem);

static int jsonc_check_obj(char* start_obj, char** end_obj);
static int jsonc_check_null(char* start_obj, char** end_obj);
static jsonc_obj* jsonc_get_obj(char* start_str, char** end_str);
static jsonc_arr* jsonc_get_arr(char* start_str, char** end_str);
static int jsonc_destroy_obj(jsonc_obj* obj);
static int jsonc_obj_to_struct(const jsonc_obj* obj);
static int jsonc_match_mult(void* st,
                            const struct type* type,
                            const jsonc_obj* obj);

static inline int is_this_char(int dest, int src) {
    return (dest == src);
}

static inline int is_pointor(char* src) {
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

static enum c_base_type is_base_type(char* src) {
    const char*** base_type = jsonc_c_base_type;
    int i = 0;
    enum c_base_type type = cInt8;
    const char* str;
    char* s;

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

static int jsonc_change_null_to_json(void* buf_start, void** buf_end) {
    strcpy(buf_start, "null");

    buf_start += 4;

    *buf_end = buf_start;

    return 0;
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
        c_type |= cMult;
    }
    return c_type;
}

void* jsonc_change_cbase_to_json(char* buf,
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

static void* jsonc_obj_to_json(char* buf, void* st, const struct type* type) {
    const struct struct_mem* mem = type->mem;

    *buf++ = '{';
    while (mem->mem_type != NULL) {
        jsonc_change_string_to_json(buf, (void*)&buf, mem->mem_name);
        *buf++ = ':';
        switch (jsonc_get_ctype(mem)) {
            case cBase:
                buf =
                    jsonc_change_cbase_to_json(buf, st + mem->mem_offset, mem);
                break;
            case cMult:
                buf = jsonc_obj_to_json(buf,
                                        st + mem->mem_offset,
                                        mem->type_info);
                break;
            case cBaseArr:
                buf = jsonc_change_cbasearr_to_json(buf,
                                                    st + mem->mem_offset,
                                                    mem);
                break;
            case cMultArr:
                buf = jsonc_change_cmultarr_to_json(buf,
                                                    st + mem->mem_offset,
                                                    mem);
                break;
            case cPtrBase:
                buf = jsonc_change_cptrbase_to_json(buf,
                                                    st + mem->mem_offset,
                                                    mem);
                break;
            case cPtrMult:
                buf = jsonc_change_cptrmult_to_json(buf,
                                                    st + mem->mem_offset,
                                                    mem);
                break;
            case cPtrBaseArr:
                buf = jsonc_change_cptrbasearr_to_json(buf,
                                                       st + mem->mem_offset,
                                                       mem);
                break;
            case cPtrMultArr:
                buf = jsonc_change_cptrmultarr_to_json(buf,
                                                       st + mem->mem_offset,
                                                       mem);
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
            buf = jsonc_change_cbase_to_json(buf,
                                             st + (i * mem->type_length),
                                             mem);
            if ((i + 1) != length) {
                *buf++ = ',';
            }
        }

        *buf++ = ']';
        return buf;
    }
    return ret;
}

static void* jsonc_change_cmultarr_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem) {
    int length = mem->mem_length / mem->type_length;
    *buf++ = '[';
    for (int i = 0; i < length; i++) {
        buf = jsonc_obj_to_json(buf,
                                st + (i * mem->type_info->length),
                                mem->type_info);
        if ((i + 1) != length) {
            *buf++ = ',';
        }
    }

    *buf++ = ']';
    return buf;
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

static void* jsonc_change_cptrmult_to_json(char* buf,
                                           void* st,
                                           const struct struct_mem* mem) {
    void* ret = NULL;
    st = (void*)(*(long*)st);
    if (st == NULL) {
        jsonc_change_null_to_json(buf, &ret);
    } else {
        ret = jsonc_obj_to_json(buf, st, mem->type_info);
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

static void* jsonc_change_cptrmultarr_to_json(char* buf,
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
            buf = jsonc_obj_to_json(buf, addr, mem->type_info);
        }
        if ((i + 1) != length) {
            *buf++ = ',';
        }
    }
    *buf++ = ']';
    return buf;
}

/* 反序列化相关函数 */

#define JSONCALLOC(size) calloc(1, size)
#define JSONFREE(json) free(json)

static inline void INIT_LIST_HEAD(struct list_head* list) {
    list->next = list;
    list->prev = list;
}

static inline void l__list_add(struct list_head* _new,
                               struct list_head* prev,
                               struct list_head* next) {
    next->prev = _new;
    _new->next = next;
    _new->prev = prev;
    prev->next = _new;
}

static inline void list_add_tail(struct list_head* _new,
                                 struct list_head* head) {
    l__list_add(_new, head->prev, head);
}

static inline void l__list_del(struct list_head* prev, struct list_head* next) {
    next->prev = prev;
    prev->next = next;
}

#define LIST_POISON1 ((void*)0x00100100)
#define LIST_POISON2 ((void*)0x00200200)

static inline void list_del(struct list_head* entry) {
    l__list_del(entry->prev, entry->next);
    entry->next = (struct list_head*)LIST_POISON1;
    entry->prev = (struct list_head*)LIST_POISON2;
}

static inline int isspace(int x) {
    if (x == ' ' || x == '\t' || x == '\n' || x == '\f' || x == '\b' ||
        x == '\r') {
        return 1;
    } else {
        return 0;
    }
}

static inline void skipspace(char** s) {
    while (isspace(**s)) {
        (*s)++;
    }
}

static inline int isdigit(int x) {
    if ('0' <= x && x <= '9') {
        return 1;
    } else {
        return 0;
    }
}

static int jsonc_check_string(char* start_str, char** end_str) {
    if (*start_str != '"') {
        return -JSON_ELE;
    } else {
        start_str++;
    }
    while (*start_str != '"') {
        start_str++;
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
    if (*start_element != ':') {
        return -JSON_ELE;
    } else {
        start_element++;
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
            break;
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

    if (*str != '{') {
        return -JSON_ROOT;
    } else {
        brackets++;
        str++;
    }

    while (*str != 0) {
        if (brackets == 0) {
            skipspace(&str);
            if (*str != 0) {
                return -JSON_EOFE;
            }
        }
        if (*str == '{' || *str == '[') {
            brackets++;
        } else if (*str == '}' || *str == ']') {
            brackets--;
        } else if (*str == '\"') {
            quotes++;
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

static inline char* get_double_quotes(char* src) {
    while (*src++ != 0) {
        if (*src == '"') {
            return src;
        }
    }
    return NULL;
}

static char* get_string(char** src) {
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

static enum json_bool jsonc_get_bool(char* start_str, char** end_str) {
    enum json_bool bool;
    if (*start_str == 't') {
        bool = True;
        start_str += 4;
    } else {
        bool = False;
        start_str += 5;
    }
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return bool;
}

static char* jsonc_get_num(char* start_str, char** end_str) {
    char *num, *temp, count;
    unsigned char i;

    temp = start_str;
    count = 0;
    while (isdigit(*temp) || is_this_char('-', *temp) ||
           is_this_char('e', *temp) || is_this_char('E', *temp) ||
           is_this_char('.', *temp)) {
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

static int jsonc_get_null(char* start_str, char** end_str) {
    start_str += 4;
    *end_str = start_str;
    return True;
}

static int json_get_ele(char* start_str, char** end_str, jsonc_obj* obj) {
    int ret = 0;
    struct jsonc_ele* ele;

    ele = JSONCALLOC(sizeof(struct jsonc_ele));
    if (!ele) {
        ret = -JSON_UNELE;
    }

    // 初始化元素链表
    INIT_LIST_HEAD(&ele->sibling);
    list_add_tail(&ele->sibling, obj);

    // 获取元素名称
    skipspace(&start_str);
    ele->name = get_string(&start_str);

    if (!ele->name) {
        return -JSON_ALLOC;
    }

    // 获取元素类型和值
    skipspace(&start_str);
    start_str++;
    skipspace(&start_str);

    switch (*start_str) {
        case '"':  // 字符串类型
            ele->type = Str;
            ele->value.Str = get_string(&start_str);
            if (!ele->value.Str) {
                return -JSON_GET_STRING;
            }
            break;
        case '{':  // 对象类型
            ele->type = Obj;
            ele->value.Obj = jsonc_get_obj(start_str, &start_str);
            if (!ele->value.Obj) {
                return -JSON_GET_OBJ;
            }
            break;
        case '[':  // 数组类型
            ele->value.Arr = jsonc_get_arr(start_str, &start_str);
            if (!ele->value.Arr) {
                return -JSON_GET_ARR;
            }
            // 数组需要判断其是单一类型的数组还是复合类型的数组
            ele->type = Arr;
            struct list_head* list = ele->value.Arr->next;
            jsonc_arr_mem* arr_mem = (jsonc_arr_mem*)list;
            enum json_type arr_mem_type = arr_mem->type;
            while (list != ele->value.Arr) {
                arr_mem = (jsonc_arr_mem*)list;
                if (arr_mem->type != arr_mem_type) {
                    ele->type = MultArr;
                    break;
                }
                list = list->next;
            }
            break;
        case 't':  // bool类型
        case 'f':
            ele->type = Bool;
            ele->value.Bool = jsonc_get_bool(start_str, &start_str);
            break;
        case '0' ... '9':  // 数字类型
        case '-':
            ele->type = Num;
            ele->value.Num = jsonc_get_num(start_str, &start_str);
            if (!ele->value.Num) {
                return -JSON_GET_NUM;
            }
            break;
        case 'n':
            ele->type = Null;
            ele->value.Null = jsonc_get_null(start_str, &start_str);
            if (!ele->value.Null) {
                return -JSON_GET_NULL;
            }
            break;
    }
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return ret;
}

static int jsonc_destroy_arr(jsonc_arr* arr) {
    jsonc_arr_mem* mem;
    jsonc_arr* list;
    int ret = 0;
    list = arr;
    while (list->next != arr) {
        mem = (jsonc_arr_mem*)list->next;
        list_del(&mem->sibling);

        switch (mem->type) {
            case Obj:
                ret = jsonc_destroy_obj(mem->value.Obj);
                break;
            case Arr:
                ret = jsonc_destroy_arr(mem->value.Arr);
                break;
            case Str:
                JSONFREE(mem->value.Str);
                break;
            case Num:
                JSONFREE(mem->value.Num);
                break;
            case Bool:
                break;
            default:
                JSONFREE(mem->value.Str);
        }
        JSONFREE(mem);
    }
    JSONFREE(arr);

    return ret;
}

static int jsonc_destroy_ele(struct jsonc_ele* ele) {
    int ret = 0;

    list_del(&ele->sibling);
    // 复合类型的值需要深入销毁
    switch (ele->type) {
        case Obj:
            ret = jsonc_destroy_obj(ele->value.Obj);
            break;
        case Arr:
            ret = jsonc_destroy_arr(ele->value.Arr);
            break;
        case Str:
            JSONFREE(ele->value.Str);

            break;
        case Num:
            JSONFREE(ele->value.Num);
            break;
        default:
            break;
    }
    JSONFREE(ele->name);
    JSONFREE(ele);

    return ret;
}

static int jsonc_destroy_obj(jsonc_obj* obj) {
    int ret = 0;
    jsonc_obj* list;
    struct jsonc_ele* ele;

    list = obj;

    // 依次删除对象中的元素
    while (list->next != obj) {
        ele = (struct jsonc_ele*)list->next;
        ret = jsonc_destroy_ele(ele);
    }
    JSONFREE(obj);
    obj = NULL;
    return ret;
}

static int jsonc_destroy(jsonc_obj* tree) {
    int ret = 0;
    // 销毁对象
    jsonc_destroy_obj(tree);
    return ret;
}

static jsonc_obj* jsonc_get_obj(char* start_str, char** end_str) {
    jsonc_obj* obj;
    int ret = 0;

    obj = JSONCALLOC(sizeof(jsonc_obj));
    if (!obj) {
        return NULL;
    }

    INIT_LIST_HEAD(obj);

    skipspace(&start_str);
    start_str++;
    skipspace(&start_str);

    // 开始获取元素
    while (*start_str != '}') {
        ret = json_get_ele(start_str, &start_str, obj);
        if (ret) {
            jsonc_destroy(obj);
            return NULL;
        }
        skipspace(&start_str);
        if (*start_str == ',') {
            start_str++;
        }
    }
    skipspace(&start_str);
    start_str++;
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return obj;
}

static jsonc_arr* jsonc_get_arr(char* start_str, char** end_str) {
    jsonc_arr* arr;
    jsonc_arr_mem* mem;

    arr = JSONCALLOC(sizeof(jsonc_arr));
    if (!arr) {
        return NULL;
    }

    INIT_LIST_HEAD(arr);

    skipspace(&start_str);
    start_str++;
    skipspace(&start_str);

    while (*start_str != ']') {
        skipspace(&start_str);
        mem = JSONCALLOC(sizeof(jsonc_arr_mem));
        if (!mem) {
            return NULL;
        }

        switch (*start_str) {
            case '"':
                mem->type = Str;
                mem->value.Str = get_string(&start_str);
                break;
            case '{':
                mem->type = Obj;
                mem->value.Obj = jsonc_get_obj(start_str, &start_str);
                break;
            case '[':
                mem->type = Arr;
                mem->value.Arr = jsonc_get_arr(start_str, &start_str);
                break;
            case 't':  // bool类型
            case 'f':
                mem->type = Bool;
                mem->value.Bool = jsonc_get_bool(start_str, &start_str);
                break;
            case '0' ... '9':  // 数字类型
            case '-':
                mem->type = Num;
                mem->value.Num = jsonc_get_num(start_str, &start_str);
                break;
            case 'n':
                mem->type = Null;
                mem->value.Null = jsonc_get_null(start_str, &start_str);
                break;
            default:
                break;
        }
        list_add_tail(&mem->sibling, arr);
        skipspace(&start_str);
        if (*start_str == ',') {
            start_str++;
        }
    }

    start_str++;
    if (end_str != NULL) {
        *end_str = start_str;
    }
    return arr;
}

static const struct struct_mem* jsonc_probe_mem_and_ele(
    const struct struct_mem* mem,
    struct jsonc_ele* ele) {
    while (mem->mem_type != NULL) {
        if (!strcmp(mem->mem_name, ele->name)) {
            return mem;
        }
        mem++;
    }
    return NULL;
}

static int jonc_match_union_self(void* st,
                                 const struct struct_mem* mem,
                                 struct jsonc_ele* ele) {
    int ret = 0;
    ele->mem_addr = NULL;
    // 与 union 的成员进行名称匹配
    mem = jsonc_probe_mem_and_ele(mem, ele);
    if (mem != NULL) {
        ele->mem = *mem;
        // 如果元素是对象，按对象进行处理
        if (ele->type == Obj) {
            if (mem->type_info != NULL) {
                // union 成员也是对象，按照复合对象进行处理
                ret = jsonc_match_mult(st, ele->mem.type_info, ele->value.Obj);
                if (!ret) {
                    ele->c_type = cMult;
                    return ret;
                }
            } else {
                return -JSON_MATCH;
            }
        } else {
            if (mem->type_info == NULL) {
            }
            printf("ele is not a obj");
        }
    }
    return ret;
}

static int jsonc_match_union(void* st,
                             const struct type* type,
                             const jsonc_obj* obj) {
    int ret = 0;
    struct list_head* list = obj->next;

    // 判断 json 对象中的元素属于 union 本身还是 union 的成员
    // 只有一个元素则先假设其属于 union 本身
    if (list->next == obj) {
        // 尝试匹配 union 自身的成员
        ret = jonc_match_union_self(st, type->mem, (struct jsonc_ele*)list);
        if (ret) {
            // 匹配 union 成员的成员
        }

    } else {  // 如果 json 树对象中存在多个元素，则属于 union 的成员
    }

    return ret;
}

static int jsonc_bind_arr_union(struct jsonc_ele* ele) {
    int ret = 0;

    return ret;
}
static int jsonc_bind_arr(struct jsonc_ele* ele) {
    int ret = 0;

    if (ele->mem.mem_length / ele->mem.type_length > 1) {
        ele->c_type |= cBaseArr;
    }

    jsonc_arr* arr = ele->value.Arr->next;
    int i = 0;
    do {
        jsonc_arr_mem* arr_mem = (jsonc_arr_mem*)arr;
        arr_mem->mem_addr = ele->mem_addr + ele->mem.type_length * i;
        if (ele->c_type & cPtrBase) {
            arr_mem->mem_addr = (void*)(*(long*)arr_mem->mem_addr);
            arr_mem->c_type = cPtrBase;
        }
        arr_mem->mem = ele->mem;
        if (arr_mem->type == Obj) {
            if (!(ele->c_type & cMult)) {
            } else {
                ret = jsonc_match_mult(arr_mem->mem_addr,
                                       arr_mem->mem.type_info,
                                       arr_mem->value.Obj);
                if (ret) {
                    return ret;
                }
            }
        } else if (arr_mem->type == Arr) {
            // 二维数组，暂时不考虑支持
        } else {
            if (ele->c_type & cPtrBase) {
                arr_mem->c_type = cPtrBase;
            }
        }
        i++;
        arr = arr->next;
    } while (arr != ele->value.Arr);

    return ret;
}

// 将 json 元素和对象成员绑定
static int jsonc_bind_mem_and_ele(void* st, struct jsonc_ele* ele) {
    int ret = 0;
    ele->mem_addr = st;
    switch (ele->type) {
        case MultArr:
            ret = jsonc_bind_arr_union(ele);
        case Arr:
            ret = jsonc_bind_arr(ele);
            break;
        case Obj:
            break;
        case Null:
        default:
            break;
    };

    return ret;
}

static int jsonc_match_struct(void* st,
                              const struct type* type,
                              const jsonc_obj* obj) {
    int ret = 0;
    struct list_head* list = obj->next;
    const struct struct_mem* mem;

    // 将 json 元素和 struct 成员逐一绑定
    do {
        struct jsonc_ele* ele = (struct jsonc_ele*)list;
        ele->mem_addr = NULL;
        mem = jsonc_probe_mem_and_ele(type->mem, ele);
        if (mem == NULL) {
            list = list->next;
            continue;
        }

        ele->mem = *mem;

        ele->mem_addr = st + mem->mem_offset;

        if (is_pointor(ele->mem.mem_type)) {
            ele->c_type |= cPtrBase;
            if (ele->type != Arr && ele->type != MultArr) {
                ele->mem_addr = (void*)(*(long*)ele->mem_addr);
            }
        }

        if (mem->type_info != NULL) {
            ele->c_type |= cMult;
        }

        ret = jsonc_bind_mem_and_ele(st + mem->mem_offset, ele);
        if (ret) {
            return ret;
        }

        list = list->next;
    } while (list != obj);

    return ret;
}
static int jsonc_match_mult(void* st,
                            const struct type* type,
                            const jsonc_obj* obj) {
    int ret = 0;
    const struct struct_mem* mem;
    int length = 0;
    mem = type->mem;
    while (mem->mem_type != NULL) {
        length += mem->mem_length;
        mem++;
    }

    // 根据复合类型是 union 还是 struct 选择不同的匹配方式
    if (type->length < length) {
        return jsonc_match_union(st, type, obj);
    } else {
        return jsonc_match_struct(st, type, obj);
    }

    return ret;
}

static int jsonc_jsonstr_to_multstr(const struct jsonc_ele* ele) {
    int ret = 0;
    if (ele->c_type == cPtrBase) {
        // 使用指针保存字符串的时候要自己注意指针的越界问题，越界就是自己活该了
        strcpy(ele->mem_addr, ele->value.Str);
    } else {
        unsigned long length = strlen(ele->value.Str);
        unsigned long capacity = ele->mem.mem_length / ele->mem.type_length;
        if (length > capacity) {
            length = capacity;
        }
        memcpy(ele->mem_addr, ele->value.Str, length);
    }
    return ret;
}

static int jsonc_jsonstr_to_multnum(const struct jsonc_ele* ele) {
    int ret = 0;

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
            *(char*)ele->mem_addr = (char)strtoll(ele->value.Str, NULL, 0);
            break;
        case cInt16:
        case cUInt16:
            *(short*)ele->mem_addr = (short)strtoll(ele->value.Str, NULL, 0);
            break;
        case cInt32:
        case cUInt32:
            *(int*)ele->mem_addr = (int)strtoll(ele->value.Str, NULL, 0);
            break;
        case cInt64:
        case cUInt64:
            *(long*)ele->mem_addr = strtoll(ele->value.Str, NULL, 0);
            break;
        case cFloat:
            *(float*)ele->mem_addr = strtof(ele->value.Str, NULL);
            break;
        case cDouble:
            *(double*)ele->mem_addr = strtod(ele->value.Str, NULL);
            break;
        default:
            break;
    }

    return ret;
}

static int jsonc_jsonstr_to_multbool(const struct jsonc_ele* ele) {
    int ret = 0;
    char bool;

    if (*ele->value.Str == '0' && strtod(ele->value.Str, NULL) == 0) {
        bool = False;
    } else {
        if (strcmp(ele->value.Str, BOOL[False]) == 0) {
            bool = False;
        } else {
            bool = True;
        }
    }

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
        case cInt16:
        case cUInt16:
        case cInt32:
        case cUInt32:
        case cInt64:
        case cUInt64:
            *(char*)ele->mem_addr = bool;
            break;
        case cFloat:
            *(float*)ele->mem_addr = (float)bool;
            break;
        case cDouble:
            *(double*)ele->mem_addr = (double)bool;
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

static int jsonc_jsonnum_to_multbool(const struct jsonc_ele* ele) {
    int ret = 0;
    int bool;
    if (strtod(ele->value.Num, NULL) != 0) {
        bool = True;
    } else {
        bool = False;
    }

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
        case cInt16:
        case cUInt16:
        case cInt32:
        case cUInt32:
        case cInt64:
        case cUInt64:
            *(char*)ele->mem_addr = (char)bool;
            break;
        case cFloat:
            *(float*)ele->mem_addr = (float)bool;
            break;
        case cDouble:
            *(double*)ele->mem_addr = (double)bool;
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }
    return ret;
}

static int jsonc_jsonbool_to_multstr(const struct jsonc_ele* ele) {
    char* addr;
    if (ele->c_type == cPtrBase) {
        addr = strcpy(ele->mem_addr, BOOL[ele->value.Bool]);
    } else {
        unsigned long capacity = ele->mem.mem_length / ele->mem.type_length;
        addr = memcpy(ele->mem_addr, BOOL[ele->value.Bool], capacity);
    }

    if (!addr) {
        return -JSON_CPY;
    } else {
        return 0;
    }
}

static int jsonc_jsonbool_to_multnum(const struct jsonc_ele* ele) {
    int ret = 0;

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
        case cInt16:
        case cUInt16:
        case cInt32:
        case cUInt32:
        case cInt64:
        case cUInt64:
            *(char*)ele->mem_addr = ele->value.Bool;
            break;
        case cFloat:
            *(float*)ele->mem_addr = ele->value.Bool;
            break;
        case cDouble:
            *(double*)ele->mem_addr = ele->value.Bool;
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }

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

    switch (is_base_type(ele->mem.mem_type)) {
        case cInt8:
        case cUInt8:
        case cInt16:
        case cUInt16:
        case cInt32:
        case cUInt32:
        case cInt64:
        case cUInt64:
            *(char*)ele->mem_addr = 0;
            break;
        case cFloat:
            *(float*)ele->mem_addr = 0;
            break;
        case cDouble:
            *(double*)ele->mem_addr = 0;
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }

    return ret;
}

static int jsonc_jsonnull_to_multbool(const struct jsonc_ele* ele) {
    return jsonc_jsonnull_to_multnum(ele);
}

static int jsonc_get_cbase(const struct jsonc_ele* ele) {
    int ret = 0;

    switch (ele->type) {
        case Str:
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
            break;
        case Num:
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
            break;
        case Bool:
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
            break;
        case Null:
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
            break;
        default:
            ret = -JSON_TYPE;
            break;
    }
    return ret;
}

static int jsonc_get_cmult(const struct jsonc_ele* ele) {
    return jsonc_obj_to_struct(ele->value.Obj);
}

static int jsonc_get_cbasearr(const struct jsonc_ele* ele) {
    if (ele->type == Arr) {
        return jsonc_obj_to_struct(ele->value.Arr);
    } else {
        return jsonc_get_cbase(ele);
    }
    return 0;
}

static int jsonc_get_cmultarr(const struct jsonc_ele* ele) {
    int ret = 0;
    jsonc_arr* list = ele->value.Arr->next;
    while (list != ele->value.Arr) {
        jsonc_arr_mem* arr = (jsonc_arr_mem*)list;
        ret = jsonc_obj_to_struct(arr->value.Arr);
        if (ret) {
            return ret;
        }
        list = list->next;
    }

    return ret;
}

static int jsonc_get_cptrbase(struct jsonc_ele* ele) {
    return jsonc_get_cbase(ele);
}

static int jsonc_get_cptrmult(struct jsonc_ele* ele) {
    return jsonc_get_cmult(ele);
}

static int jsonc_get_cptrbasearr(const struct jsonc_ele* ele) {
    int ret = 0;
    jsonc_arr* list = ele->value.Arr->next;
    while (list != ele->value.Arr) {
        jsonc_arr_mem* mem = (jsonc_arr_mem*)list;
        ret = jsonc_get_cptrbase(mem);
        if (ret) {
            return ret;
        }
        list = list->next;
    }
    return ret;
}

static int jsonc_get_cptrmultarr(const struct jsonc_ele* ele) {
    int ret = 0;
    ret = jsonc_get_cmultarr(ele);
    return ret;
}

static int jsonc_obj_to_struct(const jsonc_obj* obj) {
    int ret = 0;
    jsonc_obj* list = obj->next;

    while (list != obj) {
        struct jsonc_ele* ele = (struct jsonc_ele*)list;
        switch (ele->c_type) {
            case cBase:
                ret = jsonc_get_cbase(ele);
                break;
            case cMult:
                ret = jsonc_get_cmult(ele);
                break;
            case cBaseArr:
                ret = jsonc_get_cbasearr(ele);
                break;
            case cMultArr:
                ret = jsonc_get_cmultarr(ele);
                break;
            case cPtrBase:
                ret = jsonc_get_cptrbase(ele);
                break;
            case cPtrMult:
                ret = jsonc_get_cptrmult(ele);
                break;
            case cPtrBaseArr:
                ret = jsonc_get_cptrbasearr(ele);
                break;
            case cPtrMultArr:
                ret = jsonc_get_cptrmultarr(ele);
                break;
            default:
                ret = -JSON_UNKOEN_TYPE;
                break;
        }
        if (ret) {
            return ret;
        }
        list = list->next;
    }

    return ret;
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

int jsonc_deserialize(char* buf, void* st, const struct type* type) {
    int ret = 0;
    jsonc_obj* tree;

    ret = jsonc_check_json(buf);
    if (ret) {
        return ret;
    }

    // 先将json字符串转换为json树
    tree = jsonc_get_obj(buf, NULL);
    if (!tree) {
        return -JSON_TREE;
    }

    // 匹配结构体或联合体和json树
    ret = jsonc_match_mult(st, type, tree);
    if (ret) {
        return ret;
    }

    // 将json树转换为复合类型
    ret = jsonc_obj_to_struct(tree);

    jsonc_destroy(tree);

    return ret;
}
