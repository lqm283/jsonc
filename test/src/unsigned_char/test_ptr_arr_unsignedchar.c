/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 22:10:48
 * @LastEditTime : 2023-03-22 14:16:44
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/unsigned_char/test_ptr_arr_unsignedchar.c
 */

#include "../../include/unsigned_char/test_ptr_arr_unsignedchar.h"

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
int test_change_ptr_arr_single_unsignedchar_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"str\":[\"test change char * [0] str to json\",\"test change char * [1] str "
        "to json\"]}";
    struct TestPtrArrSingleUnsignedCharStr str = {
        {(unsigned char*)"test change char * [0] str to json",
         (unsigned char*)"test change char * [1] str to json"}};
    ret = JsoncSerialize(real, &str, TestPtrArrSingleUnsignedCharStr);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 指针数组类型的 char 类型转换为 json
int test_change_ptr_arr_single_unsignedchar_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":[10,20]}";
    struct TestPtrArrSingleUnsignedCharNum num;
    unsigned char num1 = 10;
    num.num[0] = &num1;
    num.num[1] = malloc(1);
    *num.num[1] = 20;
    ret = JsoncSerialize(real, &num, TestPtrArrSingleUnsignedCharNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 指针数组类型的 char 类型转换为 json
int test_change_ptr_arr_single_unsignedchar_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":[true,false]}";
    unsigned char bool1 = 1;
    unsigned char bool2 = 0;
    struct TestPtrArrSingleUnsignedCharBool b = {{&bool1, &bool2}};
    ret = JsoncSerialize(real, &b, TestPtrArrSingleUnsignedCharBool);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Str 转换为 json
int test_change_ptr_arr_mult_unsignedchar_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"str1\":[\"str1_0\",\"str1_1\"],\"str2\":[\"str2_0\",\"str2_1\"],\"str3\":["
        "\"str3_0\",\"str3_1\"]}";
    struct TestPtrArrMultUnsignedCharStr str = {
        {(unsigned char*)"str1_0", (unsigned char*)"str1_1"},
        {(unsigned char*)"str2_0", (unsigned char*)"str2_1"},
        {(unsigned char*)"str3_0", (unsigned char*)"str3_1"}};
    ret = JsoncSerialize(real, &str, TestPtrArrMultUnsignedCharStr);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Num 转换为 json
int test_change_ptr_arr_mult_unsignedchar_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num1\":[1,2],\"num2\":[3,4],\"num3\":[5,6]}";
    unsigned char num1 = 1;
    unsigned char num2 = 2;
    unsigned char num3 = 3;
    unsigned char num4 = 4;
    unsigned char num5 = 5;
    unsigned char num6 = 6;

    struct TestPtrArrMultUnsignedCharNum num = {{&num1, &num2},
                                                {&num3, &num4},
                                                {&num5, &num6}};
    ret = JsoncSerialize(real, &num, TestPtrArrMultUnsignedCharNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 指针数组类型多成员 Bool 转换为 json
int test_change_ptr_arr_mult_unsignedchar_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"bool1\":[false,true],\"bool2\":[true,false],\"bool3\":[false,true]}";
    unsigned char bool1 = 0;
    unsigned char bool2 = 1;
    unsigned char bool3 = 1;
    unsigned char bool4 = 0;
    unsigned char bool5 = 0;
    unsigned char bool6 = 1;
    struct TestPtrArrMultUnsignedCharBool bool = {{&bool1, &bool2},
                                                  {&bool3, &bool4},
                                                  {&bool5, &bool6}};
    ret = JsoncSerialize(real, &bool, TestPtrArrMultUnsignedCharBool);
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

// 单元素的 str 类型的 json 转换为指针数组类型的单成员的 char 类型
int test_change_single_str_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharStr str;
    str.str[0] = malloc(100 * sizeof(unsigned char));
    str.str[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str[0], "test str1") ||
        strcmp((char*)str.str[1], "test str2")) {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为指针数组类型的单成员的 char 类型
int test_change_mult_str_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharStr str;
    str.str[0] = malloc(sizeof(unsigned char) * 20);
    str.str[1] = malloc(sizeof(unsigned char) * 20);
    ret = JsoncDeserialize(json, &str, TestPtrArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp((char*)str.str[0], "12359518") || strcmp((char*)str.str[1], "12365871")) {
        return 1;
    }
    return ret;
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    return test_change_single_num_json_to_ptr_arr_single_unsignedchar_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharStr str;
    str.str[0] = malloc(sizeof(unsigned char) * 20);
    str.str[1] = malloc(sizeof(unsigned char) * 20);
    ret = JsoncDeserialize(json, &str, TestPtrArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp((char*)str.str[0], "true") || strcmp((char*)str.str[1], "false")) {
        return 1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Str 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    return test_change_single_bool_json_to_ptr_arr_single_unsignedchar_str(json);
}

// 单元素 Null 类型的 json 转换为保存 Str 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharStr str;
    str.str[0] = malloc(sizeof(unsigned char) * 20);
    str.str[1] = malloc(sizeof(unsigned char) * 20);
    ret = JsoncDeserialize(json, &str, TestPtrArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str[0] != '\0' || *str.str[1] != '\0') {
        return 1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Str 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_unsignedchar_str(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_unsignedchar_str(json);
}

// 单元素 Str 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_str_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharNum num;
    num.num[0] = malloc(sizeof(unsigned char));
    num.num[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 10 || *num.num[1] != 127) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_str_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharNum num;
    num.num[0] = malloc(sizeof(unsigned char));
    num.num[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 1 || *num.num[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    return test_change_single_bool_json_to_ptr_arr_single_unsignedchar_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharNum num;
    num.num[0] = malloc(sizeof(unsigned char));
    num.num[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrSingleUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num[0] != 0 || *num.num[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_unsignedchar_num(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_unsignedchar_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharBool b;
    b.b[0] = malloc(sizeof(unsigned char));
    b.b[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &b, TestPtrArrSingleUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b[0] != 1 || *b.b[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_str_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_num_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_num_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_bool_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_bool_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_ptr_arr_single_unsignedchar_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_single_null_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestPtrArrSingleUnsignedCharBool b;
    b.b[0] = malloc(sizeof(unsigned char));
    b.b[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &b, TestPtrArrSingleUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b[0] != 0 || *b.b[1] != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的指针数组单成员 char
int test_change_mult_null_json_to_ptr_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_null_json_to_ptr_arr_single_unsignedchar_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharStr str;
    str.str1[0] = malloc(100 * sizeof(unsigned char));
    str.str1[1] = malloc(100 * sizeof(unsigned char));
    str.str2[0] = malloc(100 * sizeof(unsigned char));
    str.str2[1] = malloc(100 * sizeof(unsigned char));
    str.str3[0] = malloc(100 * sizeof(unsigned char));
    str.str3[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1[0], "true") || strcmp((char*)str.str1[1], "false") ||
        strcmp((char*)str.str2[0], "false") || strcmp((char*)str.str2[1], "true") ||
        strcmp((char*)str.str3[0], "true") || strcmp((char*)str.str3[1], "false")) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_more_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharStr str;
    str.str1[0] = malloc(100 * sizeof(unsigned char));
    str.str1[1] = malloc(100 * sizeof(unsigned char));
    str.str2[0] = malloc(100 * sizeof(unsigned char));
    str.str2[1] = malloc(100 * sizeof(unsigned char));
    str.str3[0] = malloc(100 * sizeof(unsigned char));
    str.str3[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1[0], "true") || strcmp((char*)str.str1[1], "false") ||
        strcmp((char*)str.str2[0], "false") ||
        strcmp((char*)(char*)(char*)(char*)str.str2[1], "true")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_diff_mult_str_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharStr str;
    str.str1[0] = malloc(100 * sizeof(unsigned char));
    str.str1[1] = malloc(100 * sizeof(unsigned char));
    str.str2[0] = malloc(100 * sizeof(unsigned char));
    str.str2[1] = malloc(100 * sizeof(unsigned char));
    str.str3[0] = malloc(100 * sizeof(unsigned char));
    str.str3[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1[0], "12345") || strcmp((char*)str.str1[1], "54321") ||
        strcmp((char*)str.str2[0], "23456") || strcmp((char*)str.str2[1], "65432") ||
        strcmp((char*)str.str3[0], "34567") || strcmp((char*)str.str3[1], "76543")) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharStr str;
    str.str1[0] = malloc(100 * sizeof(unsigned char));
    str.str1[1] = malloc(100 * sizeof(unsigned char));
    str.str2[0] = malloc(100 * sizeof(unsigned char));
    str.str2[1] = malloc(100 * sizeof(unsigned char));
    str.str3[0] = malloc(100 * sizeof(unsigned char));
    str.str3[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1[0], "12345") || strcmp((char*)str.str1[1], "54321") ||
        strcmp((char*)str.str2[0], "23456") || strcmp((char*)str.str2[1], "65432")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_str(json);
}

//  元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_more_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_diff_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharStr str;
    str.str1[0] = malloc(100 * sizeof(unsigned char));
    str.str1[1] = malloc(100 * sizeof(unsigned char));
    str.str2[0] = malloc(100 * sizeof(unsigned char));
    str.str2[1] = malloc(100 * sizeof(unsigned char));
    str.str3[0] = malloc(100 * sizeof(unsigned char));
    str.str3[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1[0] != 0 || *str.str1[1] != 0 || *str.str2[0] != 0 ||
        *str.str2[1] != 0 || *str.str3[0] != 0 || *str.str3[1] != 0) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_more_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharStr str;
    str.str1[0] = malloc(100 * sizeof(unsigned char));
    str.str1[1] = malloc(100 * sizeof(unsigned char));
    str.str2[0] = malloc(100 * sizeof(unsigned char));
    str.str2[1] = malloc(100 * sizeof(unsigned char));
    str.str3[0] = malloc(100 * sizeof(unsigned char));
    str.str3[1] = malloc(100 * sizeof(unsigned char));
    ret = JsoncDeserialize(json, &str, TestPtrArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1[0] != '\0' || *str.str2[0] != '\0') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的指针数组多成员 char
int test_change_diff_mult_null_json_to_ptr_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharNum num;
    num.num1[0] = malloc(sizeof(unsigned char));
    num.num1[1] = malloc(sizeof(unsigned char));
    num.num2[0] = malloc(sizeof(unsigned char));
    num.num2[1] = malloc(sizeof(unsigned char));
    num.num3[0] = malloc(sizeof(unsigned char));
    num.num3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 128 || *num.num1[1] != 1 || *num.num2[0] != 0 ||
        *num.num2[1] != 0 || *num.num3[0] != 255 || *num.num3[1] != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharNum num;
    num.num1[0] = malloc(sizeof(unsigned char));
    num.num1[1] = malloc(sizeof(unsigned char));
    num.num2[0] = malloc(sizeof(unsigned char));
    num.num2[1] = malloc(sizeof(unsigned char));
    num.num3[0] = malloc(sizeof(unsigned char));
    num.num3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1[0] != 128 || *num.num1[1] != 1 || *num.num3[0] != 255 ||
        *num.num3[1] != 127) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_str_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharNum num;
    num.num1[0] = malloc(sizeof(unsigned char));
    num.num1[1] = malloc(sizeof(unsigned char));
    num.num2[0] = malloc(sizeof(unsigned char));
    num.num2[1] = malloc(sizeof(unsigned char));
    num.num3[0] = malloc(sizeof(unsigned char));
    num.num3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultUnsignedCharNum);
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
int test_change_more_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharNum num;
    num.num1[0] = malloc(sizeof(unsigned char));
    num.num1[1] = malloc(sizeof(unsigned char));
    num.num2[0] = malloc(sizeof(unsigned char));
    num.num2[1] = malloc(sizeof(unsigned char));
    num.num3[0] = malloc(sizeof(unsigned char));
    num.num3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultUnsignedCharNum);
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
int test_change_diff_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的指针数组多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharNum num;
    num.num1[0] = malloc(sizeof(unsigned char));
    num.num1[1] = malloc(sizeof(unsigned char));
    num.num2[0] = malloc(sizeof(unsigned char));
    num.num2[1] = malloc(sizeof(unsigned char));
    num.num3[0] = malloc(sizeof(unsigned char));
    num.num3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultUnsignedCharNum);
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
int test_change_more_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型指针数组的多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharNum num;
    num.num1[0] = malloc(sizeof(unsigned char));
    num.num1[1] = malloc(sizeof(unsigned char));
    num.num2[0] = malloc(sizeof(unsigned char));
    num.num2[1] = malloc(sizeof(unsigned char));
    num.num3[0] = malloc(sizeof(unsigned char));
    num.num3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &num, TestPtrArrMultUnsignedCharNum);
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
int test_change_diff_mult_null_json_to_ptr_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharBool bool;
    bool.bool1[0] = malloc(sizeof(unsigned char));
    bool.bool1[1] = malloc(sizeof(unsigned char));
    bool.bool2[0] = malloc(sizeof(unsigned char));
    bool.bool2[1] = malloc(sizeof(unsigned char));
    bool.bool3[0] = malloc(sizeof(unsigned char));
    bool.bool3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultUnsignedCharBool);
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
int test_change_more_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharBool bool;
    bool.bool1[0] = malloc(sizeof(unsigned char));
    bool.bool1[1] = malloc(sizeof(unsigned char));
    bool.bool2[0] = malloc(sizeof(unsigned char));
    bool.bool2[1] = malloc(sizeof(unsigned char));
    bool.bool3[0] = malloc(sizeof(unsigned char));
    bool.bool3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultUnsignedCharBool);
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
int test_change_diff_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_bool_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharBool bool;
    bool.bool1[0] = malloc(sizeof(unsigned char));
    bool.bool1[1] = malloc(sizeof(unsigned char));
    bool.bool2[0] = malloc(sizeof(unsigned char));
    bool.bool2[1] = malloc(sizeof(unsigned char));
    bool.bool3[0] = malloc(sizeof(unsigned char));
    bool.bool3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultUnsignedCharBool);
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
int test_change_more_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestPtrArrMultUnsignedCharBool bool;
    bool.bool1[0] = malloc(sizeof(unsigned char));
    bool.bool1[1] = malloc(sizeof(unsigned char));
    bool.bool2[0] = malloc(sizeof(unsigned char));
    bool.bool2[1] = malloc(sizeof(unsigned char));
    bool.bool3[0] = malloc(sizeof(unsigned char));
    bool.bool3[1] = malloc(sizeof(unsigned char));
    ret = JsoncDeserialize(json, &bool, TestPtrArrMultUnsignedCharBool);
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
int test_change_diff_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_null_json_to_ptr_arr_mult_unsignedchar_bool(json);
}
