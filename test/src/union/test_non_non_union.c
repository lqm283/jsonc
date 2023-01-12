/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:06:59
 * @LastEditTime : 2023-01-12 21:55:47
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

// 转换为自身的对象类型成员
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

// 转换为自身的对象类型的子成员
int test_change_single_m_json_to_non_non_mult_union_obj(char* json) {
    int ret = 0;
    union TestNonNonMultObj1Union u;
    ret = JsoncDeserialize(json, &u, TestNonNonMultObj1Union);
    if (ret) {
        return ret;
    }

    if (u.b.a != 20 || u.b.b != 50 || strcmp("3.14159", u.b.c)) {
        return -1;
    }

    return ret;
}

// 转换到自身成员的子成员
int test_change_single_s_json_to_non_non_mult_union_son(char* json) {
    int ret = 0;
    union TestNonNonMultObjUnion u;
    ret = JsoncDeserialize(json, &u, TestNonNonMultObjUnion);
    if (ret) {
        return ret;
    }

    if (strcmp(u.abc.c, "3.14159") || u.abc.a != 20 || u.abc.b != 50) {
        return -1;
    }

    return ret;
}

// 转换到自身成员的子成员
int test_change_single_s_json_to_non_non_mult_union_sonarr(char* json) {
    int ret = 0;
    union TestNonNonMultObjUnion u;
    ret = JsoncDeserialize(json, &u, TestNonNonMultObjUnion);
    if (ret) {
        return ret;
    }

    if (u.abc.c[0] != 1 || u.abc.c[1] != 2 || u.abc.c[2] != 3 || u.abc.c[3] != 4 ||
        u.abc.c[4] != 5 || u.abc.a != 10 || u.abc.b != 20) {
        return -1;
    }

    return ret;
}
