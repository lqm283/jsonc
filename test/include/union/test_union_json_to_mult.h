/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 14:01:35
 * @LastEditTime : 2023-01-13 17:11:30
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
    FUNC(test_change_single_s_json_to_non_non_single_union_lone),
    FUNC(test_change_single_s_json_to_non_non_mult_union_base),
    FUNC(test_change_single_s_json_to_non_non_mult_union_obj),
    FUNC(test_change_single_m_json_to_non_non_mult_union_obj),
    FUNC(test_change_single_s_json_to_non_non_mult_union_son),
    FUNC(test_change_single_s_json_to_non_non_mult_union_sonarr),

    {NULL, NULL}};

static const struct TestChangeToMult PtrNonUnionChangeToMult[] = {
    FUNC(test_change_single_s_json_to_ptr_non_single_union_lone),
    FUNC(test_change_single_s_json_to_ptr_non_mult_union_base),
    FUNC(test_change_single_s_json_to_ptr_non_mult_union_obj),
    FUNC(test_change_single_s_json_to_ptr_non_mult_union_nson),
    FUNC(test_change_single_s_json_to_ptr_non_mult_union_pson),

    {NULL, NULL}};

static const struct TestChangeToMult NonArrUnionChangeToMult[] = {
    FUNC(test_change_single_arr_json_to_non_arr_single_union_lonemem),
    FUNC(test_change_mult_arr_json_to_non_arr_single_union_lonemem),
    FUNC(test_change_single_s_json_to_non_arr_mult_union_selfmem),
    FUNC(test_change_single_arr_json_to_non_arr_mult_union_selfmem),
    FUNC(test_change_single_arr_json_to_non_arr_mult_union_submem),
    FUNC(test_change_mult_s_json_to_non_arr_mult_union_submem),
    FUNC(test_change_mult_arr_json_to_non_arr_mult_union_submem),
    {NULL, NULL}};

static const struct TestChangeToMult PtrArrUnionChangeToMult[] = {{NULL, NULL}};

#endif
