/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:10:48
 * @LastEditTime : 2023-03-22 14:22:53
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/double/test_ptr_arr_double.c
 */

#include "../../include/double/test_ptr_arr_double.h"

#include <bits/stdint-uintn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 Num 指针数组类型的 char 类型转换为 json
int test_change_ptr_arr_single_double_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":[10.147000,20.362000]}";
    struct TestPtrArrSingleDoubleNum num;
    double num1 = 10.147;
    num.num[0] = &num1;
    num.num[1] = malloc(1);
    *num.num[1] = 20.362;
    ret = JsoncSerialize(real, &num, TestPtrArrSingleDoubleNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 指针数组类型的 char 类型转换为 json
int test_change_ptr_arr_single_double_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":[true,false]}";
    double bool1 = 1;
    double bool2 = 0;
    struct TestPtrArrSingleDoubleBool b = {{&bool1, &bool2}};
    ret = JsoncSerialize(real, &b, TestPtrArrSingleDoubleBool);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Num 转换为 json
int test_change_ptr_arr_mult_double_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"num1\":[1.147000,2.147000],\"num2\":[3.654000,4.654000],\"num3\":[5.125000,6."
        "125000]}";
    double num1 = 1.147;
    double num2 = 2.147;
    double num3 = 3.654;
    double num4 = 4.654;
    double num5 = 5.125;
    double num6 = 6.125;

    struct TestPtrArrMultDoubleNum num = {{&num1, &num2}, {&num3, &num4}, {&num5, &num6}};
    ret = JsoncSerialize(real, &num, TestPtrArrMultDoubleNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Bool 转换为 json
int test_change_ptr_arr_mult_double_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"bool1\":[false,true],\"bool2\":[true,false],\"bool3\":[false,true]}";
    double bool1 = 0;
    double bool2 = 1;
    double bool3 = 1;
    double bool4 = 0;
    double bool5 = 0;
    double bool6 = 1;
    struct TestPtrArrMultDoubleBool bool = {{&bool1, &bool2},
                                           {&bool3, &bool4},
                                           {&bool5, &bool6}};
    ret = JsoncSerialize(real, &bool, TestPtrArrMultDoubleBool);
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

// 单元素 Str 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_str_json_to_ptr_arr_single_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleDoubleNum num;
    num.num[0] = malloc(sizeof(double));
    num.num[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 10 || *num.num[1] != 127) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_str_json_to_ptr_arr_single_double_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_double_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_double_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleDoubleNum num;
    num.num[0] = malloc(sizeof(double));
    num.num[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 1 || *num.num[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_double_num(char* json) {
    return test_change_single_bool_json_to_ptr_arr_single_double_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleDoubleNum num;
    num.num[0] = malloc(sizeof(double));
    num.num[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 0 || *num.num[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_double_num(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_double_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_str_json_to_ptr_arr_single_double_bool(char* json) {
    int ret = 0;
    struct TestPtrArrSingleDoubleBool b;
    b.b[0] = malloc(sizeof(double));
    b.b[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &b, TestPtrArrSingleDoubleBool);
    if (ret) {
        return ret;
    }
    if (*b.b[0] != 1 || *b.b[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_str_json_to_ptr_arr_single_double_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_double_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_double_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_double_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_double_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_double_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_double_bool(char* json) {
    int ret = 0;
    struct TestPtrArrSingleDoubleBool b;
    b.b[0] = malloc(sizeof(double));
    b.b[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &b, TestPtrArrSingleDoubleBool);
    if (ret) {
        return ret;
    }
    if (*b.b[0] != 0 || *b.b[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_double_bool(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_double_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleNum num;
    num.num1[0] = malloc(sizeof(double));
    num.num1[1] = malloc(sizeof(double));
    num.num2[0] = malloc(sizeof(double));
    num.num2[1] = malloc(sizeof(double));
    num.num3[0] = malloc(sizeof(double));
    num.num3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 32768 || *num.num1[1] != 1 || *num.num2[0] != 0 ||
        *num.num2[1] != 0 || *num.num3[0] != 12345 || *num.num3[1] != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_str_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleNum num;
    num.num1[0] = malloc(sizeof(double));
    num.num1[1] = malloc(sizeof(double));
    num.num2[0] = malloc(sizeof(double));
    num.num2[1] = malloc(sizeof(double));
    num.num3[0] = malloc(sizeof(double));
    num.num3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 32768 || *num.num1[1] != 1 || *num.num3[0] != 12345 ||
        *num.num3[1] != 127) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_str_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleNum num;
    num.num1[0] = malloc(sizeof(double));
    num.num1[1] = malloc(sizeof(double));
    num.num2[0] = malloc(sizeof(double));
    num.num2[1] = malloc(sizeof(double));
    num.num3[0] = malloc(sizeof(double));
    num.num3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 1 || *num.num1[1] != 0 || *num.num2[0] != 0 ||
        *num.num2[1] != 1 || *num.num3[0] != 1 || *num.num3[1] != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_bool_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_double_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleNum num;
    num.num1[0] = malloc(sizeof(double));
    num.num1[1] = malloc(sizeof(double));
    num.num2[0] = malloc(sizeof(double));
    num.num2[1] = malloc(sizeof(double));
    num.num3[0] = malloc(sizeof(double));
    num.num3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 1 || *num.num1[1] != 0 || *num.num3[0] != 1 ||
        *num.num3[1] != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_bool_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_double_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleNum num;
    num.num1[0] = malloc(sizeof(double));
    num.num1[1] = malloc(sizeof(double));
    num.num2[0] = malloc(sizeof(double));
    num.num2[1] = malloc(sizeof(double));
    num.num3[0] = malloc(sizeof(double));
    num.num3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 0 || *num.num1[1] != 0 || *num.num2[0] != 0 ||
        *num.num2[1] != 0 || *num.num3[0] != 0 || *num.num3[1] != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型指针数组的多成员 char
int test_change_more_mult_null_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_double_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型指针数组的多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_double_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleNum num;
    num.num1[0] = malloc(sizeof(double));
    num.num1[1] = malloc(sizeof(double));
    num.num2[0] = malloc(sizeof(double));
    num.num2[1] = malloc(sizeof(double));
    num.num3[0] = malloc(sizeof(double));
    num.num3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultDoubleNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 0 || *num.num1[1] != 0 || *num.num3[0] != 0 ||
        *num.num3[1] != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_null_json_to_ptr_arr_mult_double_num(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_double_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_double_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleBool bool;
    bool.bool1[0] = malloc(sizeof(double));
    bool.bool1[1] = malloc(sizeof(double));
    bool.bool2[0] = malloc(sizeof(double));
    bool.bool2[1] = malloc(sizeof(double));
    bool.bool3[0] = malloc(sizeof(double));
    bool.bool3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultDoubleBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1[0] != 1 || *bool.bool1[1] != 0 || *bool.bool2[0] != 0 ||
        *bool.bool2[1] != 1 || *bool.bool3[0] != 1 || *bool.bool3[1] != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_double_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleBool bool;
    bool.bool1[0] = malloc(sizeof(double));
    bool.bool1[1] = malloc(sizeof(double));
    bool.bool2[0] = malloc(sizeof(double));
    bool.bool2[1] = malloc(sizeof(double));
    bool.bool3[0] = malloc(sizeof(double));
    bool.bool3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultDoubleBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1[0] != 1 || *bool.bool1[1] != 0 || *bool.bool3[0] != 1 ||
        *bool.bool3[1] != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_double_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_double_bool(json);
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_double_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_double_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleBool bool;
    bool.bool1[0] = malloc(sizeof(double));
    bool.bool1[1] = malloc(sizeof(double));
    bool.bool2[0] = malloc(sizeof(double));
    bool.bool2[1] = malloc(sizeof(double));
    bool.bool3[0] = malloc(sizeof(double));
    bool.bool3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultDoubleBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1[0] != 0 || *bool.bool1[1] != 0 || *bool.bool2[0] != 0 ||
        *bool.bool2[1] != 0 || *bool.bool3[0] != 0 || *bool.bool3[1] != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_null_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_double_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_double_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultDoubleBool bool;
    bool.bool1[0] = malloc(sizeof(double));
    bool.bool1[1] = malloc(sizeof(double));
    bool.bool2[0] = malloc(sizeof(double));
    bool.bool2[1] = malloc(sizeof(double));
    bool.bool3[0] = malloc(sizeof(double));
    bool.bool3[1] = malloc(sizeof(double));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultDoubleBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1[0] != 0 || *bool.bool1[1] != 0 || *bool.bool3[0] != 0 ||
        *bool.bool3[1] != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_ptr_arr_mult_double_bool(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_double_bool(json);
}
