/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-03-22 14:05:13
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/uint8/test_non_non_uint8.c
 */

#include "../../include/uint8/test_non_non_uint8.h"

#include <stdint.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 char 类型转换为 str 类型的 json
int test_change_non_non_single_uint8_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"str\":\"a\"}";
    struct TestNonNonSingleUint8Str str;
    str.str = 'a';
    ret = JsoncSerialize(real, &str, TestNonNonSingleUint8Str);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 类型的 char 类型转换为 json
int test_change_non_non_single_uint8_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":10}";
    struct TestNonNonSingleUint8Num num;
    num.num = 10;
    ret = JsoncSerialize(real, &num, TestNonNonSingleUint8Num);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
int test_change_non_non_single_uint8_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":true}";
    struct TestNonNonSingleUint8Bool b;
    b.b = 1;
    ret = JsoncSerialize(real, &b, TestNonNonSingleUint8Bool);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Str 转换为 json
int test_change_non_non_mult_uint8_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"str1\":\"a\",\"str2\":\"b\",\"str3\":\"c\"}";
    struct TestNonNonMultUint8Str str;
    str.str1 = 'a';
    str.str2 = 'b';
    str.str3 = 'c';
    ret = JsoncSerialize(real, &str, TestNonNonMultUint8Str);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
int test_change_non_non_mult_uint8_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num1\":128,\"num2\":255,\"num3\":0,\"num4\":1,\"num5\":127}";
    struct TestNonNonMultUint8Num num;
    num.num1 = -128;
    num.num2 = -1;
    num.num3 = 0;
    num.num4 = 1;
    num.num5 = 127;
    ret = JsoncSerialize(real, &num, TestNonNonMultUint8Num);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
int test_change_non_non_mult_uint8_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"bool1\":true,\"bool2\":true,\"bool3\":false,\"bool4\":true,\"bool5\":true}";
    struct TestNonNonMultUint8Bool bool;
    bool.bool1 = -128;
    bool.bool2 = -1;
    bool.bool3 = 0;
    bool.bool4 = 1;
    bool.bool5 = 127;
    ret = JsoncSerialize(real, &bool, TestNonNonMultUint8Bool);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

/*
----------------------------------------------
json 转换为复合类型
----------------------------------------------
*/

// 单元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_single_str_json_to_non_non_single_uint8_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Str str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleUint8Str);
    if (ret) {
        return ret;
    }
    if (str.str != 't') {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_mult_str_json_to_non_non_single_uint8_str(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_num_json_to_non_non_single_uint8_str(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_str(json);
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_uint8_str(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_uint8_str(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_str(json);
}

// 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_uint8_str(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_str(json);
}

// 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_null_json_to_non_non_single_uint8_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Str str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleUint8Str);
    if (ret) {
        return ret;
    }
    if (str.str != '\0') {
        return 1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_uint8_str(char* json) {
    return test_change_single_null_json_to_non_non_single_uint8_str(json);
}

// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_non_non_single_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_non_single_uint8_num(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_non_single_uint8_num(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_uint8_num(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_uint8_num(char* json) {
    return test_change_single_bool_json_to_non_non_single_uint8_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_non_single_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_uint8_num(char* json) {
    return test_change_single_null_json_to_non_non_single_uint8_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_non_single_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Bool b;
    ret = JsoncDeserialize(json, &b, TestNonNonSingleUint8Bool);
    if (ret) {
        return ret;
    }
    if (b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_non_single_uint8_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_non_single_uint8_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_uint8_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_uint8_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_uint8_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_uint8_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_non_single_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonSingleUint8Bool b;
    ret = JsoncDeserialize(json, &b, TestNonNonSingleUint8Bool);
    if (ret) {
        return ret;
    }
    if (b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_uint8_bool(char* json) {
    return test_change_single_null_json_to_non_non_single_uint8_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_str_json_to_non_non_mult_uint8_str(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Str str;
    ret = JsoncDeserialize(json, &str, TestNonNonMultUint8Str);
    if (ret) {
        return ret;
    }
    if (str.str1 != 't' || str.str2 != 'f' || str.str3 != 't') {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_str_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_str_json_to_non_non_mult_uint8_str(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Str str;
    ret = JsoncDeserialize(json, &str, TestNonNonMultUint8Str);
    if (ret) {
        return ret;
    }
    if (str.str1 != 't' || str.str2 != 'f') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_str_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_num_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_num_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_num_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_num_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_str(json);
}

//  元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_bool_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_bool_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_str(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_null_json_to_non_non_mult_uint8_str(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Str str;
    ret = JsoncDeserialize(json, &str, TestNonNonMultUint8Str);
    if (ret) {
        return ret;
    }
    if (str.str1 != '\0' || str.str2 != '\0' || str.str3 != '\0') {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_null_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_equal_mult_null_json_to_non_non_mult_uint8_str(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_null_json_to_non_non_mult_uint8_str(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Str str;
    ret = JsoncDeserialize(json, &str, TestNonNonMultUint8Str);
    if (ret) {
        return ret;
    }
    if (str.str1 != '\0' || str.str2 != '\0') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_null_json_to_non_non_mult_uint8_str(char* json) {
    return test_change_less_mult_null_json_to_non_non_mult_uint8_str(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_non_mult_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num1 != 128 || num.num2 != 255 || num.num3 != 0 || num.num4 != 1 ||
        num.num5 != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_non_mult_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num2 != 255 || num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_non_mult_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num1 != 1 || num.num2 != 1 || num.num3 != 0 || num.num4 != 1 ||
        num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_equal_mult_bool_json_to_non_non_mult_uint8_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_non_mult_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num1 != 1 || num.num3 != 0 || num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_less_mult_bool_json_to_non_non_mult_uint8_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_non_mult_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num1 != 0 || num.num2 != 0 || num.num3 != 0 || num.num4 != 0 ||
        num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_null_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_equal_mult_null_json_to_non_non_mult_uint8_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_non_mult_uint8_num(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Num num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultUint8Num);
    if (ret) {
        return ret;
    }
    if (num.num1 != 0 || num.num3 != 0 || num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_non_mult_uint8_num(char* json) {
    return test_change_less_mult_null_json_to_non_non_mult_uint8_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_non_mult_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultUint8Bool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 0 || bool.bool2 != 1 || bool.bool3 != 0 || bool.bool4 != 1 ||
        bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_non_mult_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultUint8Bool);
    if (ret) {
        return ret;
    }
    if (bool.bool2 != 0 || bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_uint8_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_uint8_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_non_mult_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultUint8Bool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 1 || bool.bool2 != 1 || bool.bool3 != 0 || bool.bool4 != 1 ||
        bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_equal_mult_bool_json_to_non_non_mult_uint8_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_non_mult_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultUint8Bool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 1 || bool.bool3 != 0 || bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_less_mult_bool_json_to_non_non_mult_uint8_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_non_mult_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultUint8Bool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 0 || bool.bool2 != 0 || bool.bool3 != 0 || bool.bool4 != 0 ||
        bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_null_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_equal_mult_null_json_to_non_non_mult_uint8_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_non_mult_uint8_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultUint8Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultUint8Bool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 0 || bool.bool3 != 0 || bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_non_mult_uint8_bool(char* json) {
    return test_change_less_mult_null_json_to_non_non_mult_uint8_bool(json);
}
