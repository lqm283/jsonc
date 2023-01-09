/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-01-09 16:48:11
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/char/test_non_arr_char.c
 */

#include "../../include/char/test_non_arr_char.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 char 类型转换为 str 类型的 json
char* test_change_non_arr_single_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str\":\"test change char * str to json\"}";
    struct TestNonArrSingleCharStr str = {"test change char * str to json"};
    ret = JsoncSerialize(real, &str, TestNonArrSingleCharStr);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 类型的 char 类型转换为 json
char* test_change_non_arr_single_char_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"num\":[1,2,3,4,5]}";
    struct TestNonArrSingleCharNum num = {{1, 2, 3, 4, 5}};
    ret = JsoncSerialize(real, &num, TestNonArrSingleCharNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
char* test_change_non_arr_single_char_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"b\":[true,false,true,true,false]}";
    struct TestNonArrSingleCharBool b = {{1, 0, 1, 1, 0}};
    ret = JsoncSerialize(real, &b, TestNonArrSingleCharBool);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Str 转换为 json
char* test_change_non_arr_mult_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str1\":\"I am str1\",\"str2\":\"I am str2\",\"str3\":\"c\"}";
    struct TestNonArrMultCharStr str = {"I am str1", "I am str2", "c"};
    ret = JsoncSerialize(real, &str, TestNonArrMultCharStr);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
char* test_change_non_arr_mult_char_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"num1\":[-128,-1,0,1,127],\"num2\":[-128,-1,0,1,127],\"num3\":[-128,-1,0,1,"
        "127],\"num4\":[-128,-1,0,1,127],\"num5\":[-128,-1,0,1,127]}";
    struct TestNonArrMultCharNum num = {{-128, -1, 0, 1, 127},
                                        {-128, -1, 0, 1, 127},
                                        {-128, -1, 0, 1, 127},
                                        {-128, -1, 0, 1, 127},
                                        {-128, -1, 0, 1, 127}};
    ret = JsoncSerialize(real, &num, TestNonArrMultCharNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
char* test_change_non_arr_mult_char_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"bool1\":[true,true,false,true,true],\"bool2\":[true,true,false,true,true],"
        "\"bool3\":[true,true,false,true,true],\"bool4\":[true,true,false,true,true],"
        "\"bool5\":[true,true,false,true,true]}";
    struct TestNonArrMultCharBool bool = {{-128, -1, 0, 1, 127},
                                          {-128, -1, 0, 1, 127},
                                          {-128, -1, 0, 1, 127},
                                          {-128, -1, 0, 1, 127},
                                          {-128, -1, 0, 1, 127}};
    ret = JsoncSerialize(real, &bool, TestNonArrMultCharBool);
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

// 单元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_single_str_json_to_non_arr_single_char_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp(str.str, "single str json change to ptr non single char str")) {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_mult_str_json_to_non_arr_single_char_str(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_char_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp(str.str, "116")) {
        return 1;
    }
    return ret;
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_char_str(char* json) {
    return test_change_single_num_json_to_non_arr_single_char_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_char_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp(str.str, "true")) {
        return 1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_char_str(char* json) {
    return test_change_single_bool_json_to_non_arr_single_char_str(json);
}

// 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_char_str(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrSingleCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str != '\0') {
        return 1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_char_str(char* json) {
    return test_change_single_null_json_to_non_arr_single_char_str(json);
}

// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_char_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_char_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_char_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_char_num(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_char_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_char_num(char* json) {
    return test_change_single_bool_json_to_non_arr_single_char_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_char_num(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrSingleCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_char_num(char* json) {
    return test_change_single_null_json_to_non_arr_single_char_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_arr_single_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharBool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_arr_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_arr_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_arr_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_arr_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_arr_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_arr_single_char_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_arr_single_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrSingleCharBool b;
    ret = JsoncDeserialize(json, &b, TestNonArrSingleCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_arr_single_char_bool(char* json) {
    return test_change_single_null_json_to_non_arr_single_char_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "true") || strcmp(str.str2, "false") ||
        strcmp(str.str3, "true")) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_str_json_to_non_arr_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_str(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "true") || strcmp(str.str2, "false")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_char_str(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_str(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "0") || strcmp(str.str2, "1234567") ||
        strcmp(str.str3, "147258369")) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_char_str(char* json) {
    return test_change_equal_mult_num_json_to_non_arr_mult_char_str(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "0") || strcmp(str.str2, "1234567")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_char_str(char* json) {
    return test_change_less_mult_num_json_to_non_arr_mult_char_str(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "true") || strcmp(str.str2, "false") ||
        strcmp(str.str3, "true")) {
        return 1;
    }
    return ret;
}

//  元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_bool_json_to_non_arr_mult_char_str(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_char_str(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "true") || strcmp(str.str2, "false")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_char_str(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_char_str(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1 != '\0' || *str.str2 != '\0' || *str.str3 != '\0') {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_null_json_to_non_arr_mult_char_str(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_char_str(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonArrMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonArrMultCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1 != '\0' || *str.str2 != '\0') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_char_str(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_char_str(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_char_num(char* json) {
    int ret = 0;
    struct TestNonArrMultCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != -128 || *num.num2 != -1 || *num.num3 != 0 || *num.num4 != 1 ||
        *num.num5 != 127) {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_str_json_to_non_arr_mult_char_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_char_num(char* json) {
    int ret = 0;
    struct TestNonArrMultCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num2 != -1 || *num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_char_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_char_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_char_num(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_char_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_char_num(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_char_num(char* json) {
    int ret = 0;
    struct TestNonArrMultCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultCharNum);
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
int test_change_more_mult_bool_json_to_non_arr_mult_char_num(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_char_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_char_num(char* json) {
    int ret = 0;
    struct TestNonArrMultCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num3 != 0 || *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_char_num(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_char_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_char_num(char* json) {
    int ret = 0;
    struct TestNonArrMultCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultCharNum);
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
int test_change_more_mult_null_json_to_non_arr_mult_char_num(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_char_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_char_num(char* json) {
    int ret = 0;
    struct TestNonArrMultCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonArrMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num3 != 0 || *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_char_num(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_char_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_non_arr_mult_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultCharBool);
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
int test_change_more_mult_str_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_non_arr_mult_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool2 != 0 || *bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_equal_mult_str_json_to_non_arr_mult_char_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_less_mult_str_json_to_non_arr_mult_char_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_arr_mult_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultCharBool);
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
int test_change_more_mult_bool_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_equal_mult_bool_json_to_non_arr_mult_char_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_non_arr_mult_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool3 != 0 || *bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_less_mult_bool_json_to_non_arr_mult_char_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_non_arr_mult_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultCharBool);
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
int test_change_more_mult_null_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_equal_mult_null_json_to_non_arr_mult_char_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_non_arr_mult_char_bool(char* json) {
    int ret = 0;
    struct TestNonArrMultCharBool bool;
    ret = JsoncDeserialize(json, &bool, TestNonArrMultCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool3 != 0 || *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_non_arr_mult_char_bool(char* json) {
    return test_change_less_mult_null_json_to_non_arr_mult_char_bool(json);
}
