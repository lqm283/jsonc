/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:46:01
 * @LastEditTime : 2023-01-13 11:56:19
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/union/test_ptr_non_union.c
 */

#include "../../include/union/test_ptr_non_union.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// json 转换为单个成员的 union， 这种情况 union 会被当做 struct 来处理
int test_change_single_s_json_to_ptr_non_single_union_lone(char* json) {
    int ret = 0;
    union TestPtrNonSingleUnion u;
    u.a = malloc(sizeof(int));
    ret = JsoncDeserialize(json, &u, TestPtrNonSingleUnion);
    if (ret) {
        free(u.a);
        return ret;
    }

    if (*u.a != 10) {
        free(u.a);
        return -1;
    }
    free(u.a);
    return ret;
}

int test_change_single_s_json_to_ptr_non_mult_union_base(char* json) {
    int ret = 0;
    union TestPtrNonMultBaseUnion u;
    u.b = malloc(sizeof(float));
    ret = JsoncDeserialize(json, &u, TestPtrNonMultBaseUnion);
    if (ret) {
        free(u.b);
        return ret;
    }

    if (*u.a != 10) {
        free(u.b);
        return -1;
    }
    free(u.b);
    return ret;
}

// 转换为自身的对象类型成员
int test_change_single_s_json_to_ptr_non_mult_union_obj(char* json) {
    int ret = 0;
    union TestPtrNonMultObjUnion u;
    u.b = malloc(sizeof(struct BaseUnionStruct));
    ret = JsoncDeserialize(json, &u, TestPtrNonMultObjUnion);
    if (ret) {
        free(u.b);
        return ret;
    }

    if (u.b->a != 10) {
        free(u.b);
        return -1;
    }
    free(u.b);
    return ret;
}

// 转换到自身成员的子成员
int test_change_single_s_json_to_ptr_non_mult_union_nson(char* json) {
    int ret = 0;
    union TestPtrNonMultObjUnion u;

    ret = JsoncDeserialize(json, &u, TestPtrNonMultObjUnion);
    if (ret) {
        return ret;
    }

    if (strcmp(u.abc.c, "3.14159") || u.abc.a != 20 || u.abc.b != 50) {
        return -1;
    }
    return ret;
}

int test_change_single_s_json_to_ptr_non_mult_union_pson(char* json) {
    int ret = 0;
    union TestPtrNonMultObjUnion u;
    u.b = malloc(sizeof(struct BaseUnionStruct));

    ret = JsoncDeserialize(json, &u, TestPtrNonMultObjUnion);
    if (ret) {
        free(u.b);
        return ret;
    }

    if (u.ab->a != 10 || u.ab->b != 30) {
        free(u.b);
        return -1;
    }
    free(u.b);
    return ret;
}
