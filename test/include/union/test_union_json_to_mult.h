/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 14:01:35
 * @LastEditTime : 2023-01-11 20:59:14
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/union/test_union_json_to_mult.h
 */
#ifndef __TEST_UNION_JSON_TO_MULT_H_
#define __TEST_UNION_JSON_TO_MULT_H_

#include "../obj.h"
#include "test_non_arr_union.h"
#include "test_non_non_union.h"
#include "test_ptr_arr_union.h"
#include "test_ptr_non_union.h"

static const struct TestChangeToMult NonNonUnionChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_non_single_union_lone),
    FUNC(test_change_single_str_json_to_non_non_mult_union_base),
    {NULL, NULL}};

static const struct TestChangeToMult PtrNonUnionChangeToMult[] = {{NULL, NULL}};

static const struct TestChangeToMult NonArrUnionChangeToMult[] = {{NULL, NULL}};

static const struct TestChangeToMult PtrArrUnionChangeToMult[] = {{NULL, NULL}};

#endif