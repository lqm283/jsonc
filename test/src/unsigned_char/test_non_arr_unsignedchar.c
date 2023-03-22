/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-03-22 14:14:25
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/unsigned_char/test_non_arr_unsignedchar.c
 */

#include "../../include/unsigned_char/test_non_arr_unsignedchar.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 char 类型转换为 str 类型的 json
int test_change_non_arr_single_unsignedchar_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"str\":\"test change char * str to json\"}";
    struct TestNonArrSingleUnsignedCharStr str = {"test change char * str to json"};
    ret = JsoncSerialize(real, &str, TestNonArrSingleUnsignedCharStr);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 类型的 char 类型转换为 json
int test_change_non_arr_single_unsignedchar_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"num\":[1,2,3,4,5]}";
    struct TestNonArrSingleUnsignedCharNum num = {{1, 2, 3, 4, 5}};
    ret = JsoncSerialize(real, &num, TestNonArrSingleUnsignedCharNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
int test_change_non_arr_single_unsignedchar_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"b\":[true,false,true,true,false]}";
    struct TestNonArrSingleUnsignedCharBool b = {{1, 0, 1, 1, 0}};
    ret = JsoncSerialize(real, &b, TestNonArrSingleUnsignedCharBool);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Str 转换为 json
int test_change_non_arr_mult_unsignedchar_str_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"str1\":\"I am str1\",\"str2\":\"I am str2\",\"str3\":\"c\"}";
    struct TestNonArrMultUnsignedCharStr str = {"I am str1", "I am str2", "c"};
    ret = JsoncSerialize(real, &str, TestNonArrMultUnsignedCharStr);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
int test_change_non_arr_mult_unsignedchar_num_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"num1\":[128,255,0,1,127],\"num2\":[128,255,0,1,127],\"num3\":[128,255,0,1,"
        "127],\"num4\":[128,255,0,1,127],\"num5\":[128,255,0,1,127]}";
    struct TestNonArrMultUnsignedCharNum num = {{128, 255, 0, 1, 127},
                                                {128, 255, 0, 1, 127},
                                                {128, 255, 0, 1, 127},
                                                {128, 255, 0, 1, 127},
                                                {128, 255, 0, 1, 127}};
    ret = JsoncSerialize(real, &num, TestNonArrMultUnsignedCharNum);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
int test_change_non_arr_mult_unsignedchar_bool_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"bool1\":[true,true,false,true,true],\"bool2\":[true,true,false,true,true],"
        "\"bool3\":[true,true,false,true,true],\"bool4\":[true,true,false,true,true],"
        "\"bool5\":[true,true,false,true,true]}";
    struct TestNonArrMultUnsignedCharBool bool = {{128, 255, 0, 1, 127},
                                                  {128, 255, 0, 1, 127},
                                                  {128, 255, 0, 1, 127},
                                                  {128, 255, 0, 1, 127},
                                                  {128, 255, 0, 1, 127}};
    ret = JsoncSerialize(real, &bool, TestNonArrMultUnsignedCharBool);
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

// 单元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_single_str_json_to_non_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp((char*)str.str, "single str json change to ptr non single char str")) {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_mult_str_json_to_non_arr_single_unsignedchar_str(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp((char*)str.str, "t")) {
        return 1;
    }
    return ret;
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_unsignedchar_str(char* json) {
    return test_change_single_num_json_to_non_arr_single_unsignedchar_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp((char*)str.str, "true")) {
        return 1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_unsignedchar_str(char* json) {
    return test_change_single_bool_json_to_non_arr_single_unsignedchar_str(json);
}

// 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str != '\0') {
        return 1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_unsignedchar_str(char* json) {
    return test_change_single_null_json_to_non_arr_single_unsignedchar_str(json);
}

// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_unsignedchar_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_unsignedchar_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_unsignedchar_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_unsignedchar_num(char* json) {
    return test_change_single_bool_json_to_non_arr_single_unsignedchar_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_unsignedchar_num(char* json) {
    return test_change_single_null_json_to_non_arr_single_unsignedchar_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharBool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_unsignedchar_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleUnsignedCharBool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_unsignedchar_bool(char* json) {
    return test_change_single_null_json_to_non_arr_single_unsignedchar_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1, "true") || strcmp((char*)str.str2, "false") ||
        strcmp((char*)str.str3, "true")) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1, "true") || strcmp((char*)str.str2, "false")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1, "0") || strcmp((char*)str.str2, "1234567") ||
        strcmp((char*)str.str3, "147258369")) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1, "0") || strcmp((char*)str.str2, "1234567")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1, "true") || strcmp((char*)str.str2, "false") ||
        strcmp((char*)str.str3, "true")) {
        return 1;
    }
    return ret;
}

//  元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp((char*)str.str1, "true") || strcmp((char*)str.str2, "false")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1 != '\0' || *str.str2 != '\0' || *str.str3 != '\0') {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_str(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultUnsignedCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1 != '\0' || *str.str2 != '\0') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_unsignedchar_str(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_str(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 128 || *num.num2 != 255 || *num.num3 != 0 || *num.num4 != 1 ||
        *num.num5 != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num2 != 255 || *num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultUnsignedCharNum);
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
int test_change_more_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num3 != 0 || *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultUnsignedCharNum);
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
int test_change_more_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultUnsignedCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num3 != 0 || *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_unsignedchar_num(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultUnsignedCharBool);
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
int test_change_more_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool2 != 0 || *bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultUnsignedCharBool);
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
int test_change_more_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool3 != 0 || *bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultUnsignedCharBool);
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
int test_change_more_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_unsignedchar_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultUnsignedCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultUnsignedCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool3 != 0 || *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_unsignedchar_bool(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_unsignedchar_bool(json);
}
