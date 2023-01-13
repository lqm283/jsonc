/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-01-13 17:11:11
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/union/test_non_arr_union.c
 */

#include "../../include/union/test_non_arr_union.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  json
//  转换为只有一个基本类型成员的union，当 union 只有一个成员是，它会被当做 struct 来处理

// 只有一个元素的 json 数组转换为单个成员的 union， 这种情况 union 会被当做 struct 来处理
int test_change_single_arr_json_to_non_arr_single_union_lonemem(char* json) {
    int ret = 0;
    union TestNonArrSingleUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrSingleUnion);
    if (ret) {
        return ret;
    }

    if (u.a[0] != 10 || u.a[1] != 20) {
        return -1;
    }

    return ret;
}

// 多个元素的 json 数组转换为单个成员的 union, 这种情况 union 也会被当做 struct 来处理
int test_change_mult_arr_json_to_non_arr_single_union_lonemem(char* json) {
    int ret = 0;
    union TestNonArrSingleUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrSingleUnion);
    if (ret) {
        return ret;
    }

    if (u.a[0] != 50 || u.a[1] != 2) {
        return -1;
    }

    return ret;
}

// json 转换为有多个成员的 union， 这种情况的转换方式会比较复杂。

// json
// 只有一个元素，会首先尝试转换为自身成员，失败再尝试转换为自身成员的子成员,这里转为自身成员
int test_change_single_s_json_to_non_arr_mult_union_selfmem(char* json) {
    int ret = 0;
    union TestNonArrMultBaseUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrMultBaseUnion);
    if (ret) {
        return ret;
    }

    if (u.b[0] != 50) {
        return -1;
    }
    return ret;
}

int test_change_single_arr_json_to_non_arr_mult_union_selfmem(char* json) {
    int ret = 0;
    union TestNonArrMultBaseUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrMultBaseUnion);
    if (ret) {
        return ret;
    }

    if (u.b[0] != 88 || u.b[1] != 89) {
        return -1;
    }
    return ret;
}

// json  只有一个元素，会首先尝试转换为自身成员，
// 失败再尝试转换为自身成员的子成员,这里转为复合类型的子成员
int test_change_single_arr_json_to_non_arr_mult_union_submem(char* json) {
    int ret = 0;
    union TestNonArrMultBaseUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrMultBaseUnion);
    if (ret) {
        return ret;
    }

    if (u.a[0].a != 10 || u.a[0].b != 20 || u.a[0].d != 1 || u.a[1].a != 34 ||
        u.a[1].b != 54 || u.a[1].d != 0) {
        return -1;
    }

    if (strcmp(u.a[0].c, "135498") || strcmp(u.a[1].c, "dfgsfdgsf")) {
        return -1;
    }
    return ret;
}

// json 有多个元素，会首先尝试转换到自身成员的子成员，
// 失败再尝试转换为自身成员，这里转换为子成员
int test_change_mult_s_json_to_non_arr_mult_union_submem(char* json) {
    int ret = 0;
    union TestNonArrMultBaseUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrMultBaseUnion);
    if (ret) {
        return ret;
    }

    if (u.a[0].a != 111 || u.a[0].b != 222 || u.a[0].d != 1) {
        return -1;
    }

    if (strcmp(u.a[0].c, "3.14159")) {
        return -1;
    }

    return ret;
}

// json 有多个元素，会首先尝试转换到自身成员的子成员，
// 失败再尝试转换为自身成员，这里转换为自身成员
int test_change_mult_arr_json_to_non_arr_mult_union_submem(char* json) {
    int ret = 0;
    union TestNonArrMultBaseUnion u;
    ret = JsoncDeserialize(json, &u, TestNonArrMultBaseUnion);
    if (ret) {
        return ret;
    }

    if (u.a[0].a != 10 || u.a[0].b != 20 || u.a[0].d != 1 || u.a[1].a != 34 ||
        u.a[1].b != 54 || u.a[1].d != 0) {
        return -1;
    }

    if (strcmp(u.a[0].c, "135498") || strcmp(u.a[1].c, "dfgsfdgsf")) {
        return -1;
    }
    return ret;
}
