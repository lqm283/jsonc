/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-03-22 13:56:41
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/int64/test_non_arr_int64.c
 */

#include "../../include/int64/test_non_arr_int64.h"

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
int test_change_non_arr_single_int64_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":[1,2,3,4,5]}";
    struct TestNonArrSingleInt64Num num = {{1, 2, 3, 4, 5}};
    ret = JsoncSerialize(real, &num, TestNonArrSingleInt64Num);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
int test_change_non_arr_single_int64_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":[true,false,true,true,false]}";
    struct TestNonArrSingleInt64Bool b = {{1, 0, 1, 1, 0}};
    ret = JsoncSerialize(real, &b, TestNonArrSingleInt64Bool);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
int test_change_non_arr_mult_int64_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"num1\":[128,255,0,1,127],\"num2\":[128,255,0,1,127],\"num3\":[128,255,0,1,"
        "127],\"num4\":[128,255,0,1,127],\"num5\":[128,255,0,1,127]}";
    struct TestNonArrMultInt64Num num = {{128, 255, 0, 1, 127},
                                         {128, 255, 0, 1, 127},
                                         {128, 255, 0, 1, 127},
                                         {128, 255, 0, 1, 127},
                                         {128, 255, 0, 1, 127}};
    ret = JsoncSerialize(real, &num, TestNonArrMultInt64Num);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
int test_change_non_arr_mult_int64_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"bool1\":[true,true,false,true,true],\"bool2\":[true,true,false,true,true],"
        "\"bool3\":[true,true,false,true,true],\"bool4\":[true,true,false,true,true],"
        "\"bool5\":[true,true,false,true,true]}";
    struct TestNonArrMultInt64Bool bool = {{128, 255, 0, 1, 127},
                                           {128, 255, 0, 1, 127},
                                           {128, 255, 0, 1, 127},
                                           {128, 255, 0, 1, 127},
                                           {128, 255, 0, 1, 127}};
    ret = JsoncSerialize(real, &bool, TestNonArrMultInt64Bool);
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
// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_int64_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_int64_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_int64_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_int64_num(char* json) {
    return test_change_single_bool_json_to_non_arr_single_int64_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_int64_num(char* json) {
    return test_change_single_null_json_to_non_arr_single_int64_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleInt64Bool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleInt64Bool);
    if (ret) {
        return ret;
    }
    if (*b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_int64_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleInt64Bool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleInt64Bool);
    if (ret) {
        return ret;
    }
    if (*b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_int64_bool(char* json) {
    return test_change_single_null_json_to_non_arr_single_int64_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != -32767 || *num.num2 != 12345 || *num.num3 != 0 || *num.num4 != -1 ||
        *num.num5 != 32767) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num2 != 12345 || *num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_int64_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_int64_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultInt64Num);
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
int test_change_more_mult_bool_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num3 != 0 || *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultInt64Num);
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
int test_change_more_mult_null_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Num num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num3 != 0 || *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_int64_num(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultInt64Bool);
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
int test_change_more_mult_str_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultInt64Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool2 != 0 || *bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_int64_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_int64_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_int64_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_int64_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultInt64Bool);
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
int test_change_more_mult_bool_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultInt64Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool3 != 0 || *bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_int64_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultInt64Bool);
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
int test_change_more_mult_null_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultInt64Bool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultInt64Bool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool3 != 0 || *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_int64_bool(json);
}
