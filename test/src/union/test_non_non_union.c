/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-01-12 08:18:14
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/union/test_non_non_union.c
 */

#include "../../include/union/test_non_non_union.h"

#include <stdint.h>
#include <string.h>

// json 转换为单个成员的 union， 这种情况 union 会被当做 struct 来处理
int test_change_single_s_json_to_non_non_single_union_lone(char* json) {
    int ret = 0;
    union TestNonNonSingleUnion u;
    ret = JsoncDeserialize(json, &u, TestNonNonSingleUnion);
    if (ret) {
        return ret;
    }

    if (u.a != 10) {
        return -1;
    }

    return ret;
}

int test_change_single_s_json_to_non_non_mult_union_base(char* json) {
    int ret = 0;
    union TestNonNonMultBaseUnion u;
    ret = JsoncDeserialize(json, &u, TestNonNonMultBaseUnion);
    if (ret) {
        return ret;
    }

    if (u.a != 10) {
        return -1;
    }

    return ret;
}

int test_change_single_s_json_to_non_non_mult_union_obj(char* json) {
    int ret = 0;
    union TestNonNonMultObjUnion u;
    ret = JsoncDeserialize(json, &u, TestNonNonMultObjUnion);
    if (ret) {
        return ret;
    }

    if (u.b.a != 10) {
        return -1;
    }

    return ret;
}
