/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 14:01:35
 * @LastEditTime : 2023-01-11 13:52:20
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/float/test_float_json_to_mult.h
 */
#ifndef __TEST_FLOAT_JSON_TO_MULT_H_
#define __TEST_FLOAT_JSON_TO_MULT_H_

#include "../obj.h"
#include "test_non_arr_float.h"
#include "test_non_non_float.h"
#include "test_ptr_arr_float.h"
#include "test_ptr_non_float.h"

static const struct TestChangeToMult NonNonFloatChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_non_single_float_num),
    FUNC(test_change_mult_str_json_to_non_non_single_float_num),
    FUNC(test_change_single_num_json_to_non_non_single_float_num),
    FUNC(test_change_mult_num_json_to_non_non_single_float_num),
    FUNC(test_change_single_bool_json_to_non_non_single_float_num),
    FUNC(test_change_mult_bool_json_to_non_non_single_float_num),
    FUNC(test_change_single_null_json_to_non_non_single_float_num),
    FUNC(test_change_mult_null_json_to_non_non_single_float_num),
    FUNC(test_change_single_str_json_to_non_non_single_float_bool),
    FUNC(test_change_mult_str_json_to_non_non_single_float_bool),
    FUNC(test_change_single_num_json_to_non_non_single_float_bool),
    FUNC(test_change_mult_num_json_to_non_non_single_float_bool),
    FUNC(test_change_single_bool_json_to_non_non_single_float_bool),
    FUNC(test_change_mult_bool_json_to_non_non_single_float_bool),
    FUNC(test_change_single_null_json_to_non_non_single_float_bool),
    FUNC(test_change_mult_null_json_to_non_non_single_float_bool),
    FUNC(test_change_equal_mult_str_json_to_non_non_mult_float_num),
    FUNC(test_change_more_mult_str_json_to_non_non_mult_float_num),
    FUNC(test_change_less_mult_str_json_to_non_non_mult_float_num),
    FUNC(test_change_diff_mult_str_json_to_non_non_mult_float_num),
    FUNC(test_change_equal_mult_num_json_to_non_non_mult_float_num),
    FUNC(test_change_more_mult_num_json_to_non_non_mult_float_num),
    FUNC(test_change_less_mult_num_json_to_non_non_mult_float_num),
    FUNC(test_change_diff_mult_num_json_to_non_non_mult_float_num),
    FUNC(test_change_equal_mult_bool_json_to_non_non_mult_float_num),
    FUNC(test_change_more_mult_bool_json_to_non_non_mult_float_num),
    FUNC(test_change_less_mult_bool_json_to_non_non_mult_float_num),
    FUNC(test_change_diff_mult_bool_json_to_non_non_mult_float_num),
    FUNC(test_change_equal_mult_null_json_to_non_non_mult_float_num),
    FUNC(test_change_more_mult_null_json_to_non_non_mult_float_num),
    FUNC(test_change_less_mult_null_json_to_non_non_mult_float_num),
    FUNC(test_change_diff_mult_null_json_to_non_non_mult_float_num),
    FUNC(test_change_equal_mult_str_json_to_non_non_mult_float_bool),
    FUNC(test_change_more_mult_str_json_to_non_non_mult_float_bool),
    FUNC(test_change_less_mult_str_json_to_non_non_mult_float_bool),
    FUNC(test_change_diff_mult_str_json_to_non_non_mult_float_bool),
    FUNC(test_change_equal_mult_num_json_to_non_non_mult_float_bool),
    FUNC(test_change_more_mult_num_json_to_non_non_mult_float_bool),
    FUNC(test_change_less_mult_num_json_to_non_non_mult_float_bool),
    FUNC(test_change_diff_mult_num_json_to_non_non_mult_float_bool),
    FUNC(test_change_equal_mult_bool_json_to_non_non_mult_float_bool),
    FUNC(test_change_more_mult_bool_json_to_non_non_mult_float_bool),
    FUNC(test_change_less_mult_bool_json_to_non_non_mult_float_bool),
    FUNC(test_change_diff_mult_bool_json_to_non_non_mult_float_bool),
    FUNC(test_change_equal_mult_null_json_to_non_non_mult_float_bool),
    FUNC(test_change_more_mult_null_json_to_non_non_mult_float_bool),
    FUNC(test_change_less_mult_null_json_to_non_non_mult_float_bool),
    FUNC(test_change_diff_mult_null_json_to_non_non_mult_float_bool),
    {NULL, NULL}};

static const struct TestChangeToMult PtrNonFloatChangeToMult[] = {
    FUNC(test_change_single_str_json_to_ptr_non_single_float_num),
    FUNC(test_change_mult_str_json_to_ptr_non_single_float_num),
    FUNC(test_change_single_num_json_to_ptr_non_single_float_num),
    FUNC(test_change_mult_num_json_to_ptr_non_single_float_num),
    FUNC(test_change_single_bool_json_to_ptr_non_single_float_num),
    FUNC(test_change_mult_bool_json_to_ptr_non_single_float_num),
    FUNC(test_change_single_null_json_to_ptr_non_single_float_num),
    FUNC(test_change_mult_null_json_to_ptr_non_single_float_num),
    FUNC(test_change_single_str_json_to_ptr_non_single_float_bool),
    FUNC(test_change_mult_str_json_to_ptr_non_single_float_bool),
    FUNC(test_change_single_num_json_to_ptr_non_single_float_bool),
    FUNC(test_change_mult_num_json_to_ptr_non_single_float_bool),
    FUNC(test_change_single_bool_json_to_ptr_non_single_float_bool),
    FUNC(test_change_mult_bool_json_to_ptr_non_single_float_bool),
    FUNC(test_change_single_null_json_to_ptr_non_single_float_bool),
    FUNC(test_change_mult_null_json_to_ptr_non_single_float_bool),
    FUNC(test_change_equal_mult_str_json_to_ptr_non_mult_float_num),
    FUNC(test_change_more_mult_str_json_to_ptr_non_mult_float_num),
    FUNC(test_change_less_mult_str_json_to_ptr_non_mult_float_num),
    FUNC(test_change_diff_mult_str_json_to_ptr_non_mult_float_num),
    FUNC(test_change_equal_mult_num_json_to_ptr_non_mult_float_num),
    FUNC(test_change_more_mult_num_json_to_ptr_non_mult_float_num),
    FUNC(test_change_less_mult_num_json_to_ptr_non_mult_float_num),
    FUNC(test_change_diff_mult_num_json_to_ptr_non_mult_float_num),
    FUNC(test_change_equal_mult_bool_json_to_ptr_non_mult_float_num),
    FUNC(test_change_more_mult_bool_json_to_ptr_non_mult_float_num),
    FUNC(test_change_less_mult_bool_json_to_ptr_non_mult_float_num),
    FUNC(test_change_diff_mult_bool_json_to_ptr_non_mult_float_num),
    FUNC(test_change_equal_mult_null_json_to_ptr_non_mult_float_num),
    FUNC(test_change_more_mult_null_json_to_ptr_non_mult_float_num),
    FUNC(test_change_less_mult_null_json_to_ptr_non_mult_float_num),
    FUNC(test_change_diff_mult_null_json_to_ptr_non_mult_float_num),
    FUNC(test_change_equal_mult_str_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_more_mult_str_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_less_mult_str_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_diff_mult_str_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_equal_mult_num_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_more_mult_num_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_less_mult_num_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_diff_mult_num_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_equal_mult_bool_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_more_mult_bool_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_less_mult_bool_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_diff_mult_bool_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_equal_mult_null_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_more_mult_null_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_less_mult_null_json_to_ptr_non_mult_float_bool),
    FUNC(test_change_diff_mult_null_json_to_ptr_non_mult_float_bool),
    {NULL, NULL}};

static const struct TestChangeToMult NonArrFloatChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_arr_single_float_num),
    FUNC(test_change_mult_str_json_to_non_arr_single_float_num),
    FUNC(test_change_single_num_json_to_non_arr_single_float_num),
    FUNC(test_change_mult_num_json_to_non_arr_single_float_num),
    FUNC(test_change_single_bool_json_to_non_arr_single_float_num),
    FUNC(test_change_mult_bool_json_to_non_arr_single_float_num),
    FUNC(test_change_single_null_json_to_non_arr_single_float_num),
    FUNC(test_change_mult_null_json_to_non_arr_single_float_num),
    FUNC(test_change_single_str_json_to_non_arr_single_float_bool),
    FUNC(test_change_mult_str_json_to_non_arr_single_float_bool),
    FUNC(test_change_single_num_json_to_non_arr_single_float_bool),
    FUNC(test_change_mult_num_json_to_non_arr_single_float_bool),
    FUNC(test_change_single_bool_json_to_non_arr_single_float_bool),
    FUNC(test_change_mult_bool_json_to_non_arr_single_float_bool),
    FUNC(test_change_single_null_json_to_non_arr_single_float_bool),
    FUNC(test_change_mult_null_json_to_non_arr_single_float_bool),
    FUNC(test_change_equal_mult_str_json_to_non_arr_mult_float_num),
    FUNC(test_change_more_mult_str_json_to_non_arr_mult_float_num),
    FUNC(test_change_less_mult_str_json_to_non_arr_mult_float_num),
    FUNC(test_change_diff_mult_str_json_to_non_arr_mult_float_num),
    FUNC(test_change_equal_mult_num_json_to_non_arr_mult_float_num),
    FUNC(test_change_more_mult_num_json_to_non_arr_mult_float_num),
    FUNC(test_change_less_mult_num_json_to_non_arr_mult_float_num),
    FUNC(test_change_diff_mult_num_json_to_non_arr_mult_float_num),
    FUNC(test_change_equal_mult_bool_json_to_non_arr_mult_float_num),
    FUNC(test_change_more_mult_bool_json_to_non_arr_mult_float_num),
    FUNC(test_change_less_mult_bool_json_to_non_arr_mult_float_num),
    FUNC(test_change_diff_mult_bool_json_to_non_arr_mult_float_num),
    FUNC(test_change_equal_mult_null_json_to_non_arr_mult_float_num),
    FUNC(test_change_more_mult_null_json_to_non_arr_mult_float_num),
    FUNC(test_change_less_mult_null_json_to_non_arr_mult_float_num),
    FUNC(test_change_diff_mult_null_json_to_non_arr_mult_float_num),
    FUNC(test_change_equal_mult_str_json_to_non_arr_mult_float_bool),
    FUNC(test_change_more_mult_str_json_to_non_arr_mult_float_bool),
    FUNC(test_change_less_mult_str_json_to_non_arr_mult_float_bool),
    FUNC(test_change_diff_mult_str_json_to_non_arr_mult_float_bool),
    FUNC(test_change_equal_mult_num_json_to_non_arr_mult_float_bool),
    FUNC(test_change_more_mult_num_json_to_non_arr_mult_float_bool),
    FUNC(test_change_less_mult_num_json_to_non_arr_mult_float_bool),
    FUNC(test_change_diff_mult_num_json_to_non_arr_mult_float_bool),
    FUNC(test_change_equal_mult_bool_json_to_non_arr_mult_float_bool),
    FUNC(test_change_more_mult_bool_json_to_non_arr_mult_float_bool),
    FUNC(test_change_less_mult_bool_json_to_non_arr_mult_float_bool),
    FUNC(test_change_diff_mult_bool_json_to_non_arr_mult_float_bool),
    FUNC(test_change_equal_mult_null_json_to_non_arr_mult_float_bool),
    FUNC(test_change_more_mult_null_json_to_non_arr_mult_float_bool),
    FUNC(test_change_less_mult_null_json_to_non_arr_mult_float_bool),
    FUNC(test_change_diff_mult_null_json_to_non_arr_mult_float_bool),
    {NULL, NULL}};

static const struct TestChangeToMult PtrArrFloatChangeToMult[] = {
    FUNC(test_change_single_str_json_to_ptr_arr_single_float_num),
    FUNC(test_change_mult_str_json_to_ptr_arr_single_float_num),
    FUNC(test_change_single_num_json_to_ptr_arr_single_float_num),
    FUNC(test_change_mult_num_json_to_ptr_arr_single_float_num),
    FUNC(test_change_single_bool_json_to_ptr_arr_single_float_num),
    FUNC(test_change_mult_bool_json_to_ptr_arr_single_float_num),
    FUNC(test_change_single_null_json_to_ptr_arr_single_float_num),
    FUNC(test_change_mult_null_json_to_ptr_arr_single_float_num),
    FUNC(test_change_single_str_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_mult_str_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_single_num_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_mult_num_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_single_bool_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_mult_bool_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_single_null_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_mult_null_json_to_ptr_arr_single_float_bool),
    FUNC(test_change_equal_mult_str_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_more_mult_str_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_less_mult_str_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_diff_mult_str_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_equal_mult_num_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_more_mult_num_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_less_mult_num_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_diff_mult_num_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_equal_mult_bool_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_more_mult_bool_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_less_mult_bool_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_diff_mult_bool_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_equal_mult_null_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_more_mult_null_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_less_mult_null_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_diff_mult_null_json_to_ptr_arr_mult_float_num),
    FUNC(test_change_equal_mult_str_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_more_mult_str_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_less_mult_str_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_diff_mult_str_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_equal_mult_num_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_more_mult_num_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_less_mult_num_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_diff_mult_num_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_equal_mult_bool_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_more_mult_bool_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_less_mult_bool_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_diff_mult_bool_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_equal_mult_null_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_more_mult_null_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_less_mult_null_json_to_ptr_arr_mult_float_bool),
    FUNC(test_change_diff_mult_null_json_to_ptr_arr_mult_float_bool),
    {NULL, NULL}};

#endif
