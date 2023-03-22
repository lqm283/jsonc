/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:10:48
 * @LastEditTime : 2023-03-22 13:58:01
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/int64/test_ptr_arr_int64.c
 */

#include "../../include/int64/test_ptr_arr_int64.h"

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

// 单成员的 char 指针数组类型转换为 str 类型的 json
int test_change_ptr_arr_single_int64_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"str\":[\"test change char * [0] str to json\",\"test change char * [1] str "
        "to json\"]}";
    struct TestPtrArrSingleInt64Str str = {
        {(int64_t*)"test change char * [0] str to json",
         (int64_t*)"test change char * [1] str to json"}};
    ret = JsoncSerialize(real, &str, TestPtrArrSingleInt64Str);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 指针数组类型的 char 类型转换为 json
int test_change_ptr_arr_single_int64_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":[10,20]}";
    struct TestPtrArrSingleInt64Num num;
    int64_t num1 = 10;
    num.num[0] = &num1;
    num.num[1] = malloc(1);
    *num.num[1] = 20;
    ret = JsoncSerialize(real, &num, TestPtrArrSingleInt64Num);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 指针数组类型的 char 类型转换为 json
int test_change_ptr_arr_single_int64_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":[true,false]}";
    int64_t bool1 = 1;
    int64_t bool2 = 0;
    struct TestPtrArrSingleInt64Bool b = {{&bool1, &bool2}};
    ret = JsoncSerialize(real, &b, TestPtrArrSingleInt64Bool);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Str 转换为 json
int test_change_ptr_arr_mult_int64_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"str1\":[\"str1_0\",\"str1_1\"],\"str2\":[\"str2_0\",\"str2_1\"],\"str3\":["
        "\"str3_0\",\"str3_1\"]}";
    struct TestPtrArrMultInt64Str str = {{(int64_t*)"str1_0", (int64_t*)"str1_1"},
                                         {(int64_t*)"str2_0", (int64_t*)"str2_1"},
                                         {(int64_t*)"str3_0", (int64_t*)"str3_1"}};
    ret = JsoncSerialize(real, &str, TestPtrArrMultInt64Str);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Num 转换为 json
int test_change_ptr_arr_mult_int64_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num1\":[1,2],\"num2\":[3,4],\"num3\":[5,6]}";
    int64_t num1 = 1;
    int64_t num2 = 2;
    int64_t num3 = 3;
    int64_t num4 = 4;
    int64_t num5 = 5;
    int64_t num6 = 6;

    struct TestPtrArrMultInt64Num num = {{&num1, &num2}, {&num3, &num4}, {&num5, &num6}};
    ret = JsoncSerialize(real, &num, TestPtrArrMultInt64Num);
    if (ret > 0) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Bool 转换为 json
int test_change_ptr_arr_mult_int64_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"bool1\":[false,true],\"bool2\":[true,false],\"bool3\":[false,true]}";
    int64_t bool1 = 0;
    int64_t bool2 = 1;
    int64_t bool3 = 1;
    int64_t bool4 = 0;
    int64_t bool5 = 0;
    int64_t bool6 = 1;
    struct TestPtrArrMultInt64Bool bool = {{&bool1, &bool2},
                                           {&bool3, &bool4},
                                           {&bool5, &bool6}};
    ret = JsoncSerialize(real, &bool, TestPtrArrMultInt64Bool);
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

// 单元素 Str 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_str_json_to_ptr_arr_single_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleInt64Num num;
    num.num[0] = malloc(sizeof(int64_t));
    num.num[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 10 || *num.num[1] != 127) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_str_json_to_ptr_arr_single_int64_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_int64_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_int64_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleInt64Num num;
    num.num[0] = malloc(sizeof(int64_t));
    num.num[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 1 || *num.num[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_int64_num(char* json) {
    return test_change_single_bool_json_to_ptr_arr_single_int64_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleInt64Num num;
    num.num[0] = malloc(sizeof(int64_t));
    num.num[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 0 || *num.num[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_int64_num(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_int64_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_str_json_to_ptr_arr_single_int64_bool(char* json) {
    int ret = 0;
    struct TestPtrArrSingleInt64Bool b;
    b.b[0] = malloc(sizeof(int64_t));
    b.b[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &b, TestPtrArrSingleInt64Bool);
    if (ret) {
        return ret;
    }
    if (*b.b[0] != 1 || *b.b[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_str_json_to_ptr_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_int64_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_int64_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_int64_bool(char* json) {
    int ret = 0;
    struct TestPtrArrSingleInt64Bool b;
    b.b[0] = malloc(sizeof(int64_t));
    b.b[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &b, TestPtrArrSingleInt64Bool);
    if (ret) {
        return ret;
    }
    if (*b.b[0] != 0 || *b.b[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_int64_bool(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_int64_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Num num;
    num.num1[0] = malloc(sizeof(int64_t));
    num.num1[1] = malloc(sizeof(int64_t));
    num.num2[0] = malloc(sizeof(int64_t));
    num.num2[1] = malloc(sizeof(int64_t));
    num.num3[0] = malloc(sizeof(int64_t));
    num.num3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != -32767 || *num.num1[1] != -1 || *num.num2[0] != 0 ||
        *num.num2[1] != 0 || *num.num3[0] != 1 || *num.num3[1] != 32767) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_str_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Num num;
    num.num1[0] = malloc(sizeof(int64_t));
    num.num1[1] = malloc(sizeof(int64_t));
    num.num2[0] = malloc(sizeof(int64_t));
    num.num2[1] = malloc(sizeof(int64_t));
    num.num3[0] = malloc(sizeof(int64_t));
    num.num3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultInt64Num);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != -32767 || *num.num1[1] != -1 || *num.num3[0] != 1 ||
        *num.num3[1] != 32767) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_str_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Num num;
    num.num1[0] = malloc(sizeof(int64_t));
    num.num1[1] = malloc(sizeof(int64_t));
    num.num2[0] = malloc(sizeof(int64_t));
    num.num2[1] = malloc(sizeof(int64_t));
    num.num3[0] = malloc(sizeof(int64_t));
    num.num3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultInt64Num);
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
int test_change_more_mult_bool_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Num num;
    num.num1[0] = malloc(sizeof(int64_t));
    num.num1[1] = malloc(sizeof(int64_t));
    num.num2[0] = malloc(sizeof(int64_t));
    num.num2[1] = malloc(sizeof(int64_t));
    num.num3[0] = malloc(sizeof(int64_t));
    num.num3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultInt64Num);
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
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Num num;
    num.num1[0] = malloc(sizeof(int64_t));
    num.num1[1] = malloc(sizeof(int64_t));
    num.num2[0] = malloc(sizeof(int64_t));
    num.num2[1] = malloc(sizeof(int64_t));
    num.num3[0] = malloc(sizeof(int64_t));
    num.num3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultInt64Num);
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
int test_change_more_mult_null_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_int64_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型指针数组的多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_int64_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Num num;
    num.num1[0] = malloc(sizeof(int64_t));
    num.num1[1] = malloc(sizeof(int64_t));
    num.num2[0] = malloc(sizeof(int64_t));
    num.num2[1] = malloc(sizeof(int64_t));
    num.num3[0] = malloc(sizeof(int64_t));
    num.num3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultInt64Num);
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
int test_change_diff_mult_null_json_to_ptr_arr_mult_int64_num(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_int64_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Bool bool;
    bool.bool1[0] = malloc(sizeof(int64_t));
    bool.bool1[1] = malloc(sizeof(int64_t));
    bool.bool2[0] = malloc(sizeof(int64_t));
    bool.bool2[1] = malloc(sizeof(int64_t));
    bool.bool3[0] = malloc(sizeof(int64_t));
    bool.bool3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultInt64Bool);
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
int test_change_more_mult_str_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Bool bool;
    bool.bool1[0] = malloc(sizeof(int64_t));
    bool.bool1[1] = malloc(sizeof(int64_t));
    bool.bool2[0] = malloc(sizeof(int64_t));
    bool.bool2[1] = malloc(sizeof(int64_t));
    bool.bool3[0] = malloc(sizeof(int64_t));
    bool.bool3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultInt64Bool);
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
int test_change_diff_mult_str_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_int64_bool(json);
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_int64_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Bool bool;
    bool.bool1[0] = malloc(sizeof(int64_t));
    bool.bool1[1] = malloc(sizeof(int64_t));
    bool.bool2[0] = malloc(sizeof(int64_t));
    bool.bool2[1] = malloc(sizeof(int64_t));
    bool.bool3[0] = malloc(sizeof(int64_t));
    bool.bool3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultInt64Bool);
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
int test_change_more_mult_null_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_int64_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_int64_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultInt64Bool bool;
    bool.bool1[0] = malloc(sizeof(int64_t));
    bool.bool1[1] = malloc(sizeof(int64_t));
    bool.bool2[0] = malloc(sizeof(int64_t));
    bool.bool2[1] = malloc(sizeof(int64_t));
    bool.bool3[0] = malloc(sizeof(int64_t));
    bool.bool3[1] = malloc(sizeof(int64_t));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultInt64Bool);
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
int test_change_diff_mult_null_json_to_ptr_arr_mult_int64_bool(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_int64_bool(json);
}
