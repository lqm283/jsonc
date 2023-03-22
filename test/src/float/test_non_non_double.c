/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-03-22 14:24:11
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/float/test_non_non_double.c
 */

#include "../../include/float/test_non_non_float.h"

#include <stdint.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 Num 类型的 char 类型转换为 json
int test_change_non_non_single_float_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":10.147000}";
    struct TestNonNonSingleFloatNum num;
    num.num = 10.147;
    ret = JsoncSerialize(real, &num, TestNonNonSingleFloatNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
int test_change_non_non_single_float_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":true}";
    struct TestNonNonSingleFloatBool b;
    b.b = 1;
    ret = JsoncSerialize(real, &b, TestNonNonSingleFloatBool);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
int test_change_non_non_mult_float_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"num1\":-128.362000,\"num2\":-1.147000,\"num3\":0.000000,\"num4\":1.654000,"
        "\"num5\":127.125000}";
    struct TestNonNonMultFloatNum num;
    num.num1 = -128.362;
    num.num2 = -1.147;
    num.num3 = 0;
    num.num4 = 1.654;
    num.num5 = 127.125;
    ret = JsoncSerialize(real, &num, TestNonNonMultFloatNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
int test_change_non_non_mult_float_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"bool1\":true,\"bool2\":true,\"bool3\":false,\"bool4\":true,\"bool5\":true}";
    struct TestNonNonMultFloatBool bool;
    bool.bool1 = -128;
    bool.bool2 = -1;
    bool.bool3 = 0;
    bool.bool4 = 1;
    bool.bool5 = 127;
    ret = JsoncSerialize(real, &bool, TestNonNonMultFloatBool);
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
int test_change_single_str_json_to_non_non_single_float_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_non_single_float_num(char* json) {
    return test_change_single_str_json_to_non_non_single_float_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_non_single_float_num(char* json) {
    return test_change_single_str_json_to_non_non_single_float_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_float_num(char* json) {
    return test_change_single_str_json_to_non_non_single_float_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_float_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_float_num(char* json) {
    return test_change_single_bool_json_to_non_non_single_float_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_non_single_float_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_float_num(char* json) {
    return test_change_single_null_json_to_non_non_single_float_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_non_single_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonSingleFloatBool b;
    ret = JsoncDeserialize(json, &b, TestNonNonSingleFloatBool);
    if (ret) {
        return ret;
    }
    if (b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_non_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_float_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_non_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_float_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_float_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_float_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_float_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_non_single_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonSingleFloatBool b;
    ret = JsoncDeserialize(json, &b, TestNonNonSingleFloatBool);
    if (ret) {
        return ret;
    }
    if (b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_float_bool(char* json) {
    return test_change_single_null_json_to_non_non_single_float_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_non_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num1 != 32768 || num.num2 != 12345 || num.num3 != 0 || num.num4 != 1 ||
        num.num5 != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_non_non_mult_float_num(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_float_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_non_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num2 != 12345 || num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_non_mult_float_num(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_float_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_non_mult_float_num(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_float_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_non_mult_float_num(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_float_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_non_mult_float_num(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_float_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_non_mult_float_num(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_float_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_non_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultFloatNum);
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
int test_change_more_mult_bool_json_to_non_non_mult_float_num(char* json) {
    return test_change_equal_mult_bool_json_to_non_non_mult_float_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_non_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num1 != 1 || num.num3 != 0 || num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_non_mult_float_num(char* json) {
    return test_change_less_mult_bool_json_to_non_non_mult_float_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_non_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultFloatNum);
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
int test_change_more_mult_null_json_to_non_non_mult_float_num(char* json) {
    return test_change_equal_mult_null_json_to_non_non_mult_float_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_non_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonMultFloatNum);
    if (ret) {
        return ret;
    }
    if (num.num1 != 0 || num.num3 != 0 || num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_non_mult_float_num(char* json) {
    return test_change_less_mult_null_json_to_non_non_mult_float_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_non_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultFloatBool);
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
int test_change_more_mult_str_json_to_non_non_mult_float_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_float_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_non_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultFloatBool);
    if (ret) {
        return ret;
    }
    if (bool.bool2 != 0 || bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_non_mult_float_bool(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_float_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_non_mult_float_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_float_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_non_mult_float_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_float_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_non_mult_float_bool(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_float_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_non_mult_float_bool(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_float_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_non_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultFloatBool);
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
int test_change_more_mult_bool_json_to_non_non_mult_float_bool(char* json) {
    return test_change_equal_mult_bool_json_to_non_non_mult_float_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_non_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultFloatBool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 1 || bool.bool3 != 0 || bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_non_mult_float_bool(char* json) {
    return test_change_less_mult_bool_json_to_non_non_mult_float_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_non_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultFloatBool);
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
int test_change_more_mult_null_json_to_non_non_mult_float_bool(char* json) {
    return test_change_equal_mult_null_json_to_non_non_mult_float_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_non_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonNonMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonNonMultFloatBool);
    if (ret) {
        return ret;
    }
    if (bool.bool1 != 0 || bool.bool3 != 0 || bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_non_mult_float_bool(char* json) {
    return test_change_less_mult_null_json_to_non_non_mult_float_bool(json);
}
