/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-01-08 23:14:42
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/test_non_non_char.c
 */

#include "../include/test_non_non_char.h"

#include <string.h>
/*
----------------------------------------------
复合类型转换为 json
----------------------------------------------
*/

// 单成员的 char 类型转换为 str 类型的 json
char* test_change_non_non_single_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str\":\"a\"}";
    struct TestNonNonSingleCharStr str;
    str.str = 'a';
    ret = JsoncSerialize(real, &str, TestNonNonSingleCharStr);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Num 类型的 char 类型转换为 json
char* test_change_non_non_single_char_num_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"num\":10}";
    struct TestNonNonSingleCharNum num;
    num.num = 10;
    ret = JsoncSerialize(real, &num, TestNonNonSingleCharNum);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 单成员的 Bool 类型的 char 类型转换为 json
char* test_change_non_non_single_char_bool_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"b\":true}";
    struct TestNonNonSingleCharBool b;
    b.b = 1;
    ret = JsoncSerialize(real, &b, TestNonNonSingleCharBool);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

char* test_change_non_non_mult_char_str_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"str1\":\"a\",\"str2\":\"b\",\"str3\":\"c\"}";
    struct TestNonNonMultCharStr str;
    str.str1 = 'a';
    str.str2 = 'b';
    str.str3 = 'c';
    ret = JsoncSerialize(real, &str, TestNonNonMultCharStr);
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
int test_change_single_str_json_to_non_non_single_char_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleCharStr);
    if (ret) {
        return ret;
    }
    if (str.str != 't') {
        return 1;
    }
    return ret;
}

// 多元素的 str 类型的 json 转换为单成员的 char 类型
int test_change_mult_str_json_to_non_non_single_char_str(char* json) {
    return test_change_single_str_json_to_non_non_single_char_str(json);
}

// 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_num_json_to_non_non_single_char_str(char* json) {
    return test_change_single_str_json_to_non_non_single_char_str(json);
}

// 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_char_str(char* json) {
    return test_change_single_str_json_to_non_non_single_char_str(json);
}

// 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_char_str(char* json) {
    return test_change_single_str_json_to_non_non_single_char_str(json);
}

// 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_char_str(char* json) {
    return test_change_single_str_json_to_non_non_single_char_str(json);
}

// 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_single_null_json_to_non_non_single_char_str(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonSingleCharStr);
    if (ret) {
        return ret;
    }
    if (str.str != '\0') {
        return 1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_char_str(char* json) {
    return test_change_single_null_json_to_non_non_single_char_str(json);
}

// 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_str_json_to_non_non_single_char_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (num.num != 10) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_str_json_to_non_non_single_char_num(char* json) {
    return test_change_single_str_json_to_non_non_single_char_num(json);
}

// 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_num_json_to_non_non_single_char_num(char* json) {
    return test_change_single_str_json_to_non_non_single_char_num(json);
}

// 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_char_num(char* json) {
    return test_change_single_str_json_to_non_non_single_char_num(json);
}

// 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_char_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (num.num != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_char_num(char* json) {
    return test_change_single_bool_json_to_non_non_single_char_num(json);
}

// 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_single_null_json_to_non_non_single_char_num(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharNum num;
    ret = JsoncDeserialize(json, &num, TestNonNonSingleCharNum);
    if (ret) {
        return ret;
    }
    if (num.num != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_char_num(char* json) {
    return test_change_single_null_json_to_non_non_single_char_num(json);
}

// 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_str_json_to_non_non_single_char_bool(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharBool b;
    ret = JsoncDeserialize(json, &b, TestNonNonSingleCharBool);
    if (ret) {
        return ret;
    }
    if (b.b != 1) {
        return -1;
    }
    return ret;
}

// 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_str_json_to_non_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_char_bool(json);
}

// 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_num_json_to_non_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_char_bool(json);
}

// 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_num_json_to_non_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_char_bool(json);
}

// 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_bool_json_to_non_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_char_bool(json);
}

// 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_bool_json_to_non_non_single_char_bool(char* json) {
    return test_change_single_str_json_to_non_non_single_char_bool(json);
}

// 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_single_null_json_to_non_non_single_char_bool(char* json) {
    int ret = 0;
    struct TestNonNonSingleCharBool b;
    ret = JsoncDeserialize(json, &b, TestNonNonSingleCharBool);
    if (ret) {
        return ret;
    }
    if (b.b != 0) {
        return -1;
    }
    return ret;
}

// 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char
int test_change_mult_null_json_to_non_non_single_char_bool(char* json) {
    return test_change_single_null_json_to_non_non_single_char_bool(json);
}

// 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_str_json_to_non_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonNonMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (str.str1 != 't' || str.str2 != 'f' || str.str3 != 't') {
        return 1;
    }
    return ret;
}

// 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_str_json_to_non_non_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_char_str(json);
}

// 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_str_json_to_non_non_mult_char_str(char* json) {
    int ret = 0;
    struct TestNonNonMultCharStr str;
    ret = JsoncDeserialize(json, &str, TestNonNonMultCharStr);
    if (ret) {
        return ret;
    }
    if (str.str1 != 't' || str.str2 != 'f') {
        return 1;
    }
    return ret;
}

// 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_str_json_to_non_non_mult_char_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_char_str(json);
}

// 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_num_json_to_non_non_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_char_str(json);
}

// 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_more_mult_num_json_to_non_non_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_char_str(json);
}

// 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_less_mult_num_json_to_non_non_mult_char_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_char_str(json);
}

// 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_diff_mult_num_json_to_non_non_mult_char_str(char* json) {
    return test_change_less_mult_str_json_to_non_non_mult_char_str(json);
}

// 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char
int test_change_equal_mult_bool_json_to_non_non_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_char_str(json);
}

//
int test_change_more_mult_bool_json_to_non_non_mult_char_str(char* json) {
    return test_change_equal_mult_str_json_to_non_non_mult_char_str(json);
}
