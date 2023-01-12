/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-01-12 22:04:37
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

// json 转换为单个成员的 union， 这种情况 union 会被当做 struct 来处理
int test_change_single_s_json_to_non_arr_single_union_lone(char* json) {
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

// 匹配 union 成员的子成员失败后再次尝试匹配 union 自身的成员
int test_change_single_s_json_to_non_arr_mult_union_base(char* json) {
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
