/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:01
 * @LastEditTime : 2023-01-09 16:05:25
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/char/test_ptr_non_char.c
 */

#include "../../include/char/test_ptr_non_char.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 char 类型转换为 str 类型的 json
char* test_change_ptr_non_single_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str\":\"test change char * str to json\"}";
    char* s = "test change char * str to json";
    struct TestPtrNonSingleCharStr str;
    str.str = s;
    ret = JsoncSerialize(real, &str, TestPtrNonSingleCharStr);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 类型的 char 类型转换为 json
char* test_change_ptr_non_single_char_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"num\":10}";
    struct TestPtrNonSingleCharNum num;
    num.num = malloc(sizeof(num.num));
    *num.num = 10;
    ret = JsoncSerialize(real, &num, TestPtrNonSingleCharNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
char* test_change_ptr_non_single_char_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"b\":true}";
    struct TestPtrNonSingleCharBool b;
    b.b = malloc(sizeof(b.b));
    *b.b = 1;
    ret = JsoncSerialize(real, &b, TestPtrNonSingleCharBool);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Str 转换为 json
char* test_change_ptr_non_mult_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str1\":\"I am str1\",\"str2\":\"I am str2\",\"str3\":\"c\"}";
    struct TestPtrNonMultCharStr str;
    str.str3 = malloc(sizeof(str.str3));
    str.str1 = "I am str1";
    str.str2 = "I am str2";
    *str.str3 = 'c';
    ret = JsoncSerialize(real, &str, TestPtrNonMultCharStr);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Num 转换为 json
char* test_change_ptr_non_mult_char_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"num1\":-128,\"num2\":-1,\"num3\":0,\"num4\":1,\"num5\":127}";
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    *num.num1 = -128;
    *num.num2 = -1;
    *num.num3 = 0;
    *num.num4 = 1;
    *num.num5 = 127;
    ret = JsoncSerialize(real, &num, TestPtrNonMultCharNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// char 多成员 Bool 转换为 json
char* test_change_ptr_non_mult_char_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"bool1\":true,\"bool2\":true,\"bool3\":false,\"bool4\":true,\"bool5\":true}";
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    *bool.bool1 = -128;
    *bool.bool2 = -1;
    *bool.bool3 = 0;
    *bool.bool4 = 1;
    *bool.bool5 = 127;
    ret = JsoncSerialize(real, &bool, TestPtrNonMultCharBool);
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
int test_change_single_str_json_to_ptr_non_single_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharStr str;
    str.str = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonSingleCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp(str.str, "single str json change to ptr non single char str")) {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_mult_str_json_to_ptr_non_single_char_str(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_num_json_to_ptr_non_single_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharStr str;
    str.str = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonSingleCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp(str.str, "116")) {
        return 1;
    }
    return ret;
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_num_json_to_ptr_non_single_char_str(char* json) {
    return test_change_single_num_json_to_ptr_non_single_char_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_bool_json_to_ptr_non_single_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharStr str;
    str.str = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonSingleCharStr);
    if (ret) {
        return ret;
    }

    if (strcmp(str.str, "true")) {
        return 1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_bool_json_to_ptr_non_single_char_str(char* json) {
    return test_change_single_bool_json_to_ptr_non_single_char_str(json);
}

// 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_null_json_to_ptr_non_single_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharStr str;
    str.str = malloc(sizeof(str.str));
    ret = JsoncDeserialize(json, &str, TestPtrNonSingleCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str != '\0') {
        return 1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_null_json_to_ptr_non_single_char_str(char* json) {
    return test_change_single_null_json_to_ptr_non_single_char_str(json);
}

// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_ptr_non_single_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharNum num;
    num.num = malloc(sizeof(num.num));
    ret = JsoncDeserialize(json, &num, TestPtrNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_ptr_non_single_char_num(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_ptr_non_single_char_num(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_ptr_non_single_char_num(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_ptr_non_single_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharNum num;
    num.num = malloc(sizeof(num.num));
    ret = JsoncDeserialize(json, &num, TestPtrNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_ptr_non_single_char_num(char* json) {
    return test_change_single_bool_json_to_ptr_non_single_char_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_ptr_non_single_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharNum num;
    num.num = malloc(sizeof(num.num));
    ret = JsoncDeserialize(json, &num, TestPtrNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_ptr_non_single_char_num(char* json) {
    return test_change_single_null_json_to_ptr_non_single_char_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_ptr_non_single_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharBool b;
    b.b = malloc(sizeof(b.b));
    ret = JsoncDeserialize(json, &b, TestPtrNonSingleCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_ptr_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_ptr_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_ptr_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_ptr_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_ptr_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_ptr_non_single_char_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_ptr_non_single_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonSingleCharBool b;
    b.b = malloc(sizeof(b.b));
    ret = JsoncDeserialize(json, &b, TestPtrNonSingleCharBool);
    if (ret) {
        return ret;
    }
    if (*b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_ptr_non_single_char_bool(char* json) {
    return test_change_single_null_json_to_ptr_non_single_char_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(100);
    str.str2 = malloc(100);
    str.str3 = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
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
int test_change_more_mult_str_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_str(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(100);
    str.str2 = malloc(100);
    str.str3 = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "true") || strcmp(str.str2, "false")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_str_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_str(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(100);
    str.str2 = malloc(100);
    str.str3 = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
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
int test_change_more_mult_num_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_equal_mult_num_json_to_ptr_non_mult_char_str(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(100);
    str.str2 = malloc(100);
    str.str3 = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "0") || strcmp(str.str2, "1234567")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_less_mult_num_json_to_ptr_non_mult_char_str(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(100);
    str.str2 = malloc(100);
    str.str3 = malloc(100);
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
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
int test_change_more_mult_bool_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_non_mult_char_str(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(sizeof(str.str1));
    str.str2 = malloc(sizeof(str.str2));
    str.str3 = malloc(sizeof(str.str3));
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (strcmp(str.str1, "true") || strcmp(str.str2, "false")) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_less_mult_bool_json_to_ptr_non_mult_char_str(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(sizeof(str.str1));
    str.str2 = malloc(sizeof(str.str2));
    str.str3 = malloc(sizeof(str.str3));
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1 != '\0' || *str.str2 != '\0' || *str.str3 != '\0') {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_null_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_equal_mult_null_json_to_ptr_non_mult_char_str(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharStr str;
    str.str1 = malloc(sizeof(str.str1));
    str.str2 = malloc(sizeof(str.str2));
    str.str3 = malloc(sizeof(str.str3));
    ret = JsoncDeserialize(json, &str, TestPtrNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (*str.str1 != '\0' || *str.str2 != '\0') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_null_json_to_ptr_non_mult_char_str(char* json) {
    return test_change_less_mult_null_json_to_ptr_non_mult_char_str(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_non_mult_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultCharNum);
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
int test_change_more_mult_str_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_num(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_non_mult_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num2 != -1 || *num.num4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_num(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_num(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_num(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_num(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_num(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_non_mult_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultCharNum);
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
int test_change_more_mult_bool_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_non_mult_char_num(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_non_mult_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 1 || *num.num3 != 0 || *num.num5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_less_mult_bool_json_to_ptr_non_mult_char_num(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_non_mult_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultCharNum);
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
int test_change_more_mult_null_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_equal_mult_null_json_to_ptr_non_mult_char_num(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_non_mult_char_num(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharNum num;
    num.num1 = malloc(sizeof(num.num1));
    num.num2 = malloc(sizeof(num.num2));
    num.num3 = malloc(sizeof(num.num3));
    num.num4 = malloc(sizeof(num.num4));
    num.num5 = malloc(sizeof(num.num5));
    ret = JsoncDeserialize(json, &num, TestPtrNonMultCharNum);
    if (ret) {
        return ret;
    }
    if (*num.num1 != 0 || *num.num3 != 0 || *num.num5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_ptr_non_mult_char_num(char* json) {
    return test_change_less_mult_null_json_to_ptr_non_mult_char_num(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_str_json_to_ptr_non_mult_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultCharBool);
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
int test_change_more_mult_str_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_bool(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_str_json_to_ptr_non_mult_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool2 != 0 || *bool.bool4 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_str_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_bool(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_num_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_bool(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_more_mult_num_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_equal_mult_str_json_to_ptr_non_mult_char_bool(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_num_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_bool(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_num_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_less_mult_str_json_to_ptr_non_mult_char_bool(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_bool_json_to_ptr_non_mult_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultCharBool);
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
int test_change_more_mult_bool_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_equal_mult_bool_json_to_ptr_non_mult_char_bool(json);
}

// 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_bool_json_to_ptr_non_mult_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 1 || *bool.bool3 != 0 || *bool.bool5 != 1) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_bool_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_less_mult_bool_json_to_ptr_non_mult_char_bool(json);
}

// 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_equal_mult_null_json_to_ptr_non_mult_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultCharBool);
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
int test_change_more_mult_null_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_equal_mult_null_json_to_ptr_non_mult_char_bool(json);
}

// 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_less_mult_null_json_to_ptr_non_mult_char_bool(char* json) {
    int ret = 0;
    struct TestPtrNonMultCharBool bool;
    bool.bool1 = malloc(sizeof(bool.bool1));
    bool.bool2 = malloc(sizeof(bool.bool2));
    bool.bool3 = malloc(sizeof(bool.bool3));
    bool.bool4 = malloc(sizeof(bool.bool4));
    bool.bool5 = malloc(sizeof(bool.bool5));
    ret = JsoncDeserialize(json, &bool, TestPtrNonMultCharBool);
    if (ret) {
        return ret;
    }
    if (*bool.bool1 != 0 || *bool.bool3 != 0 || *bool.bool5 != 0) {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
int test_change_diff_mult_null_json_to_ptr_non_mult_char_bool(char* json) {
    return test_change_less_mult_null_json_to_ptr_non_mult_char_bool(json);
}
