/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-01-11 15:44:21
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/struct/test_non_non_struct.c
 */

#include "../../include/struct/test_non_non_struct.h"

#include <stdint.h>
#include <string.h>

/*
------------------
复合类型转换为 json
------------------
*/

// 单个 struct 类型转换为 json
char* test_change_non_non_single_struct_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e = "{\"s\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello world\",\"d\":true}}";
    struct TestNonNonSingleStruct s = {{10, 3.14159, "Hello world", 1}};
    ret = JsoncSerialize(real, &s, TestNonNonSingleStruct);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 纯 struct 类型转换为 json
char* test_change_non_non_mult1_struct_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"s1\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},\"s2\":{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false}}";
    struct TestNonNonMult1Struct s = {{10, 3.14159, "Hello world", 1},
                                      {33, 2.7173, "Good morning", 0}};
    ret = JsoncSerialize(real, &s, TestNonNonMult1Struct);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}

// 多个 混合的 struct 类型转换为 json
char* test_change_non_non_multmax_struct_to_json(char* exp, char* real) {
    char* ret = 0;
    char* e =
        "{\"s1\":{\"a\":10,\"b\":3.141590,\"c\":\"Hello "
        "world\",\"d\":true},\"s2\":{\"a\":33,\"b\":2.717300,\"c\":\"Good "
        "morning\",\"d\":false},\"a\":10,\"b\":20,\"c\":30.000000}";
    struct TestNonNonMultMaxStruct s = {{10, 3.14159, "Hello world", 1},
                                        {33, 2.7173, "Good morning", 0},
                                        10,
                                        20,
                                        30};
    ret = JsoncSerialize(real, &s, TestNonNonMultMaxStruct);
    if (ret) {
        strcpy(exp, e);
    }
    return ret;
}
