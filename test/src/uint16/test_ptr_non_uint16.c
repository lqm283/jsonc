/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:01
 * @LastEditTime : 2023-03-22 14:03:50
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/uint16/test_ptr_non_uint16.c
 */

#include "../../include/uint16/test_ptr_non_uint16.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 char 类型转换为 str 类型的 json
int test_change_ptr_non_single_uint16_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"str\":\"test change char * str to json\"}";
    uint16_t* s = (uint16_t*)"test change char * str to json";
    struct TestPtrNonSingleUint16Str str;
    str.str = s;
    ret = JsoncSerialize(real, &str, TestPtrNonSingleUint16Str);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 类型的 char 类型转换为 json
int test_change_ptr_non_single_uint16_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":10}";
    struct TestPtrNonSingleUint16Num num;
    num.num = malloc(sizeof(uint16_t));
    *num.num = 10;
    ret = JsoncSerialize(real, &num, TestPtrNonSingleUint16Num);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
int test_change_ptr_non_single_uint16_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":true}";
    struct TestPtrNonSingleUint16Bool b;
    b.b = malloc(sizeof(uint16_t));
    *b.b = 1;
    ret = JsoncSerialize(real, &b, TestPtrNonSingleUint16Bool);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Str 转换为 json
int test_change_ptr_non_mult_uint16_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"str1\":\"I am str1\",\"str2\":\"I am str2\",\"str3\":\"c\"}";
    struct TestPtrNonMultUint16Str str;
    str.str3 = malloc(sizeof(uint16_t));
    str.str1 = (uint16_t*)"I am str1";
    str.str2 = (uint16_t*)"I am str2";
    *str.str3 = 'c';
    ret = JsoncSerialize(real, &str, TestPtrNonMultUint16Str);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
int test_change_ptr_non_mult_uint16_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num1\":65408,\"num2\":65535,\"num3\":0,\"num4\":1,\"num5\":127}";
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    *num.num1 = -128;
    *num.num2 = -1;
    *num.num3 = 0;
    *num.num4 = 1;
    *num.num5 = 127;
    ret = JsoncSerialize(real, &num, TestPtrNonMultUint16Num);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
int test_change_ptr_non_mult_uint16_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"bool1\":true,\"bool2\":true,\"bool3\":false,\"bool4\":true,\"bool5\":true}";
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    *bool.bool1 = -128;
    *bool.bool2 = -1;
    *bool.bool3 = 0;
    *bool.bool4 = 1;
    *bool.bool5 = 127;
    ret = JsoncSerialize(real, &bool, TestPtrNonMultUint16Bool);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

/*
----------------------------------------------
json 转换为复合类型
----------------------------------------------
*/
// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_ptr_non_single_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonSingleUint16Num num;
    num.num = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonSingleUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_ptr_non_single_uint16_num(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_ptr_non_single_uint16_num(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_ptr_non_single_uint16_num(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_ptr_non_single_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonSingleUint16Num num;
    num.num = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonSingleUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_ptr_non_single_uint16_num(char* json) {
    return test_change_single_bool_json_to_ptr_non_single_uint16_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_ptr_non_single_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonSingleUint16Num num;
    num.num = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonSingleUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_ptr_non_single_uint16_num(char* json) {
    return test_change_single_null_json_to_ptr_non_single_uint16_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_ptr_non_single_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonSingleUint16Bool b;
    b.b = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &b, TestPtrNonSingleUint16Bool);
    if (ret) {
        return ret;
    }
    if (*b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_ptr_non_single_uint16_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_ptr_non_single_uint16_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_ptr_non_single_uint16_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_ptr_non_single_uint16_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_ptr_non_single_uint16_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_uint16_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_ptr_non_single_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonSingleUint16Bool b;
    b.b = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &b, TestPtrNonSingleUint16Bool);
    if (ret) {
        return ret;
    }
    if (*b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_ptr_non_single_uint16_bool(char* json) {
    return test_change_single_null_json_to_ptr_non_single_uint16_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_non_mult_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 32768 || *num.num2 != 12345 || *num.num3 != 0 || *num.num4 != 1 ||
        *num.num5 != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_uint16_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_non_mult_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num2 != 12345 || *num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_uint16_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_uint16_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_uint16_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_uint16_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_uint16_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num2 != 1 || *num.num3 != 0 || *num.num4 != 1 ||
        *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_non_mult_uint16_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_non_mult_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num3 != 0 || *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_less_mult_bool_json_to_ptr_non_mult_uint16_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_non_mult_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num2 != 0 || *num.num3 != 0 || *num.num4 != 0 ||
        *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_null_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_equal_mult_null_json_to_ptr_non_mult_uint16_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_non_mult_uint16_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Num num;
    num.num1 = malloc(sizeof(uint16_t));
    num.num2 = malloc(sizeof(uint16_t));
    num.num3 = malloc(sizeof(uint16_t));
    num.num4 = malloc(sizeof(uint16_t));
    num.num5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultUint16Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num3 != 0 || *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_ptr_non_mult_uint16_num(char* json) {
    return test_change_less_mult_null_json_to_ptr_non_mult_uint16_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_non_mult_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultUint16Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool2 != 1 || *bool.bool3 != 0 || *bool.bool4 != 1 ||
        *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_uint16_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_non_mult_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultUint16Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool2 != 0 || *bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_uint16_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_uint16_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_uint16_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_uint16_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_uint16_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultUint16Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool2 != 1 || *bool.bool3 != 0 || *bool.bool4 != 1 ||
        *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_non_mult_uint16_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultUint16Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool3 != 0 || *bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_less_mult_bool_json_to_ptr_non_mult_uint16_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_non_mult_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultUint16Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool2 != 0 || *bool.bool3 != 0 || *bool.bool4 != 0 ||
        *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_null_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_equal_mult_null_json_to_ptr_non_mult_uint16_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_non_mult_uint16_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultUint16Bool bool;
    bool.bool1 = malloc(sizeof(uint16_t));
    bool.bool2 = malloc(sizeof(uint16_t));
    bool.bool3 = malloc(sizeof(uint16_t));
    bool.bool4 = malloc(sizeof(uint16_t));
    bool.bool5 = malloc(sizeof(uint16_t));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultUint16Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool3 != 0 || *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_ptr_non_mult_uint16_bool(char* json) {
    return test_change_less_mult_null_json_to_ptr_non_mult_uint16_bool(json);
}
