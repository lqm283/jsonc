/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-01-11 13:58:16
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/float/test_non_arr_float.c
 */

#include "../../include/float/test_non_arr_float.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/
// 单成员的 Num 类型的 char 类型转换为 json
char* test_change_non_arr_single_float_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"num\":[0.000000,2.147000,3.362000,4.654000,5.125000]}";
    struct TestNonArrSingleFloatNum num = {{0, 2.147, 3.362, 4.654, 5.125}};
    ret = JsoncSerialize(real, &num, TestNonArrSingleFloatNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
char* test_change_non_arr_single_float_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"b\":[true,false,true,true,false]}";
    struct TestNonArrSingleFloatBool b = {{1, 0, 1, 1, 0}};
    ret = JsoncSerialize(real, &b, TestNonArrSingleFloatBool);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
char* test_change_non_arr_mult_float_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"num1\":[128.362000,255.147003,0.000000,1.654000,127.125000],\"num2\":[128."
        "362000,255.147003,0.000000,1.654000,127.125000],\"num3\":[128.362000,255.147003,"
        "0.000000,1.654000,127.125000],\"num4\":[128.362000,255.147003,0.000000,1.654000,"
        "127.125000],\"num5\":[128.362000,255.147003,0.000000,1.654000,127.125000]}";
    struct TestNonArrMultFloatNum num = {{128.362, 255.147, 0, 1.654, 127.125},
                                         {128.362, 255.147, 0, 1.654, 127.125},
                                         {128.362, 255.147, 0, 1.654, 127.125},
                                         {128.362, 255.147, 0, 1.654, 127.125},
                                         {128.362, 255.147, 0, 1.654, 127.125}};
    ret = JsoncSerialize(real, &num, TestNonArrMultFloatNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
char* test_change_non_arr_mult_float_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"bool1\":[true,true,false,true,true],\"bool2\":[true,true,false,true,true],"
        "\"bool3\":[true,true,false,true,true],\"bool4\":[true,true,false,true,true],"
        "\"bool5\":[true,true,false,true,true]}";
    struct TestNonArrMultFloatBool bool = {{128.362, 255.147, 0, 1.654, 127.125},
                                           {128.362, 255.147, 0, 1.654, 127.125},
                                           {128.362, 255.147, 0, 1.654, 127.125},
                                           {128.362, 255.147, 0, 1.654, 127.125},
                                           {128.362, 255.147, 0, 1.654, 127.125}};
    ret = JsoncSerialize(real, &bool, TestNonArrMultFloatBool);
    if (ret) {
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
int test_change_single_str_json_to_non_arr_single_float_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleFloatNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_float_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_float_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_float_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_float_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleFloatNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_float_num(char* json) {
    return test_change_single_bool_json_to_non_arr_single_float_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_float_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleFloatNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_float_num(char* json) {
    return test_change_single_null_json_to_non_arr_single_float_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleFloatBool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleFloatBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_float_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_float_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleFloatBool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleFloatBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_float_bool(char* json) {
    return test_change_single_null_json_to_non_arr_single_float_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultFloatNum);
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
int test_change_more_mult_str_json_to_non_arr_mult_float_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_float_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultFloatNum);
    if (ret) {
        return ret;
    }
    if (*num.num2 != 12345 || *num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_float_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_float_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_float_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_float_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_float_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_float_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_float_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_float_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_float_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_float_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultFloatNum);
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
int test_change_more_mult_bool_json_to_non_arr_mult_float_num(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_float_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultFloatNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num3 != 0 || *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_float_num(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_float_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultFloatNum);
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
int test_change_more_mult_null_json_to_non_arr_mult_float_num(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_float_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_float_num(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultFloatNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num3 != 0 || *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_float_num(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_float_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultFloatBool);
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
int test_change_more_mult_str_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_float_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultFloatBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool2 != 0 || *bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_float_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_float_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_float_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_float_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_float_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultFloatBool);
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
int test_change_more_mult_bool_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_float_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultFloatBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool3 != 0 || *bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_float_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultFloatBool);
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
int test_change_more_mult_null_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_float_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_float_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultFloatBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultFloatBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool3 != 0 || *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_float_bool(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_float_bool(json);
}
