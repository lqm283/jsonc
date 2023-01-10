/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 14:01:35
 * @LastEditTime : 2023-01-10 15:33:16
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/char/test_char_json_to_mult.h
 */
#ifndef __TEST_CHAR_JSON_TO_MULT_H_
#define __TEST_CHAR_JSON_TO_MULT_H_

#include "../obj.h"
#include "test_non_arr_char.h"
#include "test_non_non_char.h"
#include "test_ptr_arr_char.h"
#include "test_ptr_non_char.h"

static const struct TestChangeToMult NonNonCharChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_non_single_char_str),
    FUNC(test_change_mult_str_json_to_non_non_single_char_str),
    FUNC(test_change_single_num_json_to_non_non_single_char_str),
    FUNC(test_change_mult_num_json_to_non_non_single_char_str),
    FUNC(test_change_single_bool_json_to_non_non_single_char_str),
    FUNC(test_change_mult_bool_json_to_non_non_single_char_str),
    FUNC(test_change_single_null_json_to_non_non_single_char_str),
    FUNC(test_change_mult_null_json_to_non_non_single_char_str),
    FUNC(test_change_single_str_json_to_non_non_single_char_num),
    FUNC(test_change_mult_str_json_to_non_non_single_char_num),
    FUNC(test_change_single_num_json_to_non_non_single_char_num),
    FUNC(test_change_mult_num_json_to_non_non_single_char_num),
    FUNC(test_change_single_bool_json_to_non_non_single_char_num),
    FUNC(test_change_mult_bool_json_to_non_non_single_char_num),
    FUNC(test_change_single_null_json_to_non_non_single_char_num),
    FUNC(test_change_mult_null_json_to_non_non_single_char_num),
    FUNC(test_change_single_str_json_to_non_non_single_char_bool),
    FUNC(test_change_mult_str_json_to_non_non_single_char_bool),
    FUNC(test_change_single_num_json_to_non_non_single_char_bool),
    FUNC(test_change_mult_num_json_to_non_non_single_char_bool),
    FUNC(test_change_single_bool_json_to_non_non_single_char_bool),
    FUNC(test_change_mult_bool_json_to_non_non_single_char_bool),
    FUNC(test_change_single_null_json_to_non_non_single_char_bool),
    FUNC(test_change_mult_null_json_to_non_non_single_char_bool),
    FUNC(test_change_equal_mult_str_json_to_non_non_mult_char_str),
    FUNC(test_change_more_mult_str_json_to_non_non_mult_char_str),
    FUNC(test_change_less_mult_str_json_to_non_non_mult_char_str),
    FUNC(test_change_diff_mult_str_json_to_non_non_mult_char_str),
    FUNC(test_change_equal_mult_num_json_to_non_non_mult_char_str),
    FUNC(test_change_more_mult_num_json_to_non_non_mult_char_str),
    FUNC(test_change_less_mult_num_json_to_non_non_mult_char_str),
    FUNC(test_change_diff_mult_num_json_to_non_non_mult_char_str),
    FUNC(test_change_equal_mult_bool_json_to_non_non_mult_char_str),
    FUNC(test_change_more_mult_bool_json_to_non_non_mult_char_str),
    FUNC(test_change_less_mult_bool_json_to_non_non_mult_char_str),
    FUNC(test_change_diff_mult_bool_json_to_non_non_mult_char_str),
    FUNC(test_change_equal_mult_null_json_to_non_non_mult_char_str),
    FUNC(test_change_more_mult_null_json_to_non_non_mult_char_str),
    FUNC(test_change_less_mult_null_json_to_non_non_mult_char_str),
    FUNC(test_change_diff_mult_null_json_to_non_non_mult_char_str),
    FUNC(test_change_equal_mult_str_json_to_non_non_mult_char_num),
    FUNC(test_change_more_mult_str_json_to_non_non_mult_char_num),
    FUNC(test_change_less_mult_str_json_to_non_non_mult_char_num),
    FUNC(test_change_diff_mult_str_json_to_non_non_mult_char_num),
    FUNC(test_change_equal_mult_num_json_to_non_non_mult_char_num),
    FUNC(test_change_more_mult_num_json_to_non_non_mult_char_num),
    FUNC(test_change_less_mult_num_json_to_non_non_mult_char_num),
    FUNC(test_change_diff_mult_num_json_to_non_non_mult_char_num),
    FUNC(test_change_equal_mult_bool_json_to_non_non_mult_char_num),
    FUNC(test_change_more_mult_bool_json_to_non_non_mult_char_num),
    FUNC(test_change_less_mult_bool_json_to_non_non_mult_char_num),
    FUNC(test_change_diff_mult_bool_json_to_non_non_mult_char_num),
    FUNC(test_change_equal_mult_null_json_to_non_non_mult_char_num),
    FUNC(test_change_more_mult_null_json_to_non_non_mult_char_num),
    FUNC(test_change_less_mult_null_json_to_non_non_mult_char_num),
    FUNC(test_change_diff_mult_null_json_to_non_non_mult_char_num),
    FUNC(test_change_equal_mult_str_json_to_non_non_mult_char_bool),
    FUNC(test_change_more_mult_str_json_to_non_non_mult_char_bool),
    FUNC(test_change_less_mult_str_json_to_non_non_mult_char_bool),
    FUNC(test_change_diff_mult_str_json_to_non_non_mult_char_bool),
    FUNC(test_change_equal_mult_num_json_to_non_non_mult_char_bool),
    FUNC(test_change_more_mult_num_json_to_non_non_mult_char_bool),
    FUNC(test_change_less_mult_num_json_to_non_non_mult_char_bool),
    FUNC(test_change_diff_mult_num_json_to_non_non_mult_char_bool),
    FUNC(test_change_equal_mult_bool_json_to_non_non_mult_char_bool),
    FUNC(test_change_more_mult_bool_json_to_non_non_mult_char_bool),
    FUNC(test_change_less_mult_bool_json_to_non_non_mult_char_bool),
    FUNC(test_change_diff_mult_bool_json_to_non_non_mult_char_bool),
    FUNC(test_change_equal_mult_null_json_to_non_non_mult_char_bool),
    FUNC(test_change_more_mult_null_json_to_non_non_mult_char_bool),
    FUNC(test_change_less_mult_null_json_to_non_non_mult_char_bool),
    FUNC(test_change_diff_mult_null_json_to_non_non_mult_char_bool),
    {NULL, NULL}};

static const struct TestChangeToMult PtrNonCharChangeToMult[] = {
    FUNC(test_change_single_str_json_to_ptr_non_single_char_str),
    FUNC(test_change_mult_str_json_to_ptr_non_single_char_str),
    FUNC(test_change_single_num_json_to_ptr_non_single_char_str),
    FUNC(test_change_mult_num_json_to_ptr_non_single_char_str),
    FUNC(test_change_single_bool_json_to_ptr_non_single_char_str),
    FUNC(test_change_mult_bool_json_to_ptr_non_single_char_str),
    FUNC(test_change_single_null_json_to_ptr_non_single_char_str),
    FUNC(test_change_mult_null_json_to_ptr_non_single_char_str),
    FUNC(test_change_single_str_json_to_ptr_non_single_char_num),
    FUNC(test_change_mult_str_json_to_ptr_non_single_char_num),
    FUNC(test_change_single_num_json_to_ptr_non_single_char_num),
    FUNC(test_change_mult_num_json_to_ptr_non_single_char_num),
    FUNC(test_change_single_bool_json_to_ptr_non_single_char_num),
    FUNC(test_change_mult_bool_json_to_ptr_non_single_char_num),
    FUNC(test_change_single_null_json_to_ptr_non_single_char_num),
    FUNC(test_change_mult_null_json_to_ptr_non_single_char_num),
    FUNC(test_change_single_str_json_to_ptr_non_single_char_bool),
    FUNC(test_change_mult_str_json_to_ptr_non_single_char_bool),
    FUNC(test_change_single_num_json_to_ptr_non_single_char_bool),
    FUNC(test_change_mult_num_json_to_ptr_non_single_char_bool),
    FUNC(test_change_single_bool_json_to_ptr_non_single_char_bool),
    FUNC(test_change_mult_bool_json_to_ptr_non_single_char_bool),
    FUNC(test_change_single_null_json_to_ptr_non_single_char_bool),
    FUNC(test_change_mult_null_json_to_ptr_non_single_char_bool),
    FUNC(test_change_equal_mult_str_json_to_ptr_non_mult_char_str),
    FUNC(test_change_more_mult_str_json_to_ptr_non_mult_char_str),
    FUNC(test_change_less_mult_str_json_to_ptr_non_mult_char_str),
    FUNC(test_change_diff_mult_str_json_to_ptr_non_mult_char_str),
    FUNC(test_change_equal_mult_num_json_to_ptr_non_mult_char_str),
    FUNC(test_change_more_mult_num_json_to_ptr_non_mult_char_str),
    FUNC(test_change_less_mult_num_json_to_ptr_non_mult_char_str),
    FUNC(test_change_diff_mult_num_json_to_ptr_non_mult_char_str),
    FUNC(test_change_equal_mult_bool_json_to_ptr_non_mult_char_str),
    FUNC(test_change_more_mult_bool_json_to_ptr_non_mult_char_str),
    FUNC(test_change_less_mult_bool_json_to_ptr_non_mult_char_str),
    FUNC(test_change_diff_mult_bool_json_to_ptr_non_mult_char_str),
    FUNC(test_change_equal_mult_null_json_to_ptr_non_mult_char_str),
    FUNC(test_change_more_mult_null_json_to_ptr_non_mult_char_str),
    FUNC(test_change_less_mult_null_json_to_ptr_non_mult_char_str),
    FUNC(test_change_diff_mult_null_json_to_ptr_non_mult_char_str),
    FUNC(test_change_equal_mult_str_json_to_ptr_non_mult_char_num),
    FUNC(test_change_more_mult_str_json_to_ptr_non_mult_char_num),
    FUNC(test_change_less_mult_str_json_to_ptr_non_mult_char_num),
    FUNC(test_change_diff_mult_str_json_to_ptr_non_mult_char_num),
    FUNC(test_change_equal_mult_num_json_to_ptr_non_mult_char_num),
    FUNC(test_change_more_mult_num_json_to_ptr_non_mult_char_num),
    FUNC(test_change_less_mult_num_json_to_ptr_non_mult_char_num),
    FUNC(test_change_diff_mult_num_json_to_ptr_non_mult_char_num),
    FUNC(test_change_equal_mult_bool_json_to_ptr_non_mult_char_num),
    FUNC(test_change_more_mult_bool_json_to_ptr_non_mult_char_num),
    FUNC(test_change_less_mult_bool_json_to_ptr_non_mult_char_num),
    FUNC(test_change_diff_mult_bool_json_to_ptr_non_mult_char_num),
    FUNC(test_change_equal_mult_null_json_to_ptr_non_mult_char_num),
    FUNC(test_change_more_mult_null_json_to_ptr_non_mult_char_num),
    FUNC(test_change_less_mult_null_json_to_ptr_non_mult_char_num),
    FUNC(test_change_diff_mult_null_json_to_ptr_non_mult_char_num),
    FUNC(test_change_equal_mult_str_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_more_mult_str_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_less_mult_str_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_diff_mult_str_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_equal_mult_num_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_more_mult_num_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_less_mult_num_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_diff_mult_num_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_equal_mult_bool_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_more_mult_bool_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_less_mult_bool_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_diff_mult_bool_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_equal_mult_null_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_more_mult_null_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_less_mult_null_json_to_ptr_non_mult_char_bool),
    FUNC(test_change_diff_mult_null_json_to_ptr_non_mult_char_bool),
    {NULL, NULL}};

static const struct TestChangeToMult NonArrCharChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_arr_single_char_str),
    FUNC(test_change_mult_str_json_to_non_arr_single_char_str),
    FUNC(test_change_single_num_json_to_non_arr_single_char_str),
    FUNC(test_change_mult_num_json_to_non_arr_single_char_str),
    FUNC(test_change_single_bool_json_to_non_arr_single_char_str),
    FUNC(test_change_mult_bool_json_to_non_arr_single_char_str),
    FUNC(test_change_single_null_json_to_non_arr_single_char_str),
    FUNC(test_change_mult_null_json_to_non_arr_single_char_str),
    FUNC(test_change_single_str_json_to_non_arr_single_char_num),
    FUNC(test_change_mult_str_json_to_non_arr_single_char_num),
    FUNC(test_change_single_num_json_to_non_arr_single_char_num),
    FUNC(test_change_mult_num_json_to_non_arr_single_char_num),
    FUNC(test_change_single_bool_json_to_non_arr_single_char_num),
    FUNC(test_change_mult_bool_json_to_non_arr_single_char_num),
    FUNC(test_change_single_null_json_to_non_arr_single_char_num),
    FUNC(test_change_mult_null_json_to_non_arr_single_char_num),
    FUNC(test_change_single_str_json_to_non_arr_single_char_bool),
    FUNC(test_change_mult_str_json_to_non_arr_single_char_bool),
    FUNC(test_change_single_num_json_to_non_arr_single_char_bool),
    FUNC(test_change_mult_num_json_to_non_arr_single_char_bool),
    FUNC(test_change_single_bool_json_to_non_arr_single_char_bool),
    FUNC(test_change_mult_bool_json_to_non_arr_single_char_bool),
    FUNC(test_change_single_null_json_to_non_arr_single_char_bool),
    FUNC(test_change_mult_null_json_to_non_arr_single_char_bool),
    FUNC(test_change_equal_mult_str_json_to_non_arr_mult_char_str),
    FUNC(test_change_more_mult_str_json_to_non_arr_mult_char_str),
    FUNC(test_change_less_mult_str_json_to_non_arr_mult_char_str),
    FUNC(test_change_diff_mult_str_json_to_non_arr_mult_char_str),
    FUNC(test_change_equal_mult_num_json_to_non_arr_mult_char_str),
    FUNC(test_change_more_mult_num_json_to_non_arr_mult_char_str),
    FUNC(test_change_less_mult_num_json_to_non_arr_mult_char_str),
    FUNC(test_change_diff_mult_num_json_to_non_arr_mult_char_str),
    FUNC(test_change_equal_mult_bool_json_to_non_arr_mult_char_str),
    FUNC(test_change_more_mult_bool_json_to_non_arr_mult_char_str),
    FUNC(test_change_less_mult_bool_json_to_non_arr_mult_char_str),
    FUNC(test_change_diff_mult_bool_json_to_non_arr_mult_char_str),
    FUNC(test_change_equal_mult_null_json_to_non_arr_mult_char_str),
    FUNC(test_change_more_mult_null_json_to_non_arr_mult_char_str),
    FUNC(test_change_less_mult_null_json_to_non_arr_mult_char_str),
    FUNC(test_change_diff_mult_null_json_to_non_arr_mult_char_str),
    FUNC(test_change_equal_mult_str_json_to_non_arr_mult_char_num),
    FUNC(test_change_more_mult_str_json_to_non_arr_mult_char_num),
    FUNC(test_change_less_mult_str_json_to_non_arr_mult_char_num),
    FUNC(test_change_diff_mult_str_json_to_non_arr_mult_char_num),
    FUNC(test_change_equal_mult_num_json_to_non_arr_mult_char_num),
    FUNC(test_change_more_mult_num_json_to_non_arr_mult_char_num),
    FUNC(test_change_less_mult_num_json_to_non_arr_mult_char_num),
    FUNC(test_change_diff_mult_num_json_to_non_arr_mult_char_num),
    FUNC(test_change_equal_mult_bool_json_to_non_arr_mult_char_num),
    FUNC(test_change_more_mult_bool_json_to_non_arr_mult_char_num),
    FUNC(test_change_less_mult_bool_json_to_non_arr_mult_char_num),
    FUNC(test_change_diff_mult_bool_json_to_non_arr_mult_char_num),
    FUNC(test_change_equal_mult_null_json_to_non_arr_mult_char_num),
    FUNC(test_change_more_mult_null_json_to_non_arr_mult_char_num),
    FUNC(test_change_less_mult_null_json_to_non_arr_mult_char_num),
    FUNC(test_change_diff_mult_null_json_to_non_arr_mult_char_num),
    FUNC(test_change_equal_mult_str_json_to_non_arr_mult_char_bool),
    FUNC(test_change_more_mult_str_json_to_non_arr_mult_char_bool),
    FUNC(test_change_less_mult_str_json_to_non_arr_mult_char_bool),
    FUNC(test_change_diff_mult_str_json_to_non_arr_mult_char_bool),
    FUNC(test_change_equal_mult_num_json_to_non_arr_mult_char_bool),
    FUNC(test_change_more_mult_num_json_to_non_arr_mult_char_bool),
    FUNC(test_change_less_mult_num_json_to_non_arr_mult_char_bool),
    FUNC(test_change_diff_mult_num_json_to_non_arr_mult_char_bool),
    FUNC(test_change_equal_mult_bool_json_to_non_arr_mult_char_bool),
    FUNC(test_change_more_mult_bool_json_to_non_arr_mult_char_bool),
    FUNC(test_change_less_mult_bool_json_to_non_arr_mult_char_bool),
    FUNC(test_change_diff_mult_bool_json_to_non_arr_mult_char_bool),
    FUNC(test_change_equal_mult_null_json_to_non_arr_mult_char_bool),
    FUNC(test_change_more_mult_null_json_to_non_arr_mult_char_bool),
    FUNC(test_change_less_mult_null_json_to_non_arr_mult_char_bool),
    FUNC(test_change_diff_mult_null_json_to_non_arr_mult_char_bool),
    {NULL, NULL}};

static const struct TestChangeToMult PtrArrCharChangeToMult[] = {
    FUNC(test_change_single_str_json_to_ptr_arr_single_char_str),
    FUNC(test_change_mult_str_json_to_ptr_arr_single_char_str),
    FUNC(test_change_single_num_json_to_ptr_arr_single_char_str),
    FUNC(test_change_mult_num_json_to_ptr_arr_single_char_str),
    FUNC(test_change_single_bool_json_to_ptr_arr_single_char_str),
    FUNC(test_change_mult_bool_json_to_ptr_arr_single_char_str),
    FUNC(test_change_single_null_json_to_ptr_arr_single_char_str),
    FUNC(test_change_mult_null_json_to_ptr_arr_single_char_str),
    FUNC(test_change_single_str_json_to_ptr_arr_single_char_num),
    FUNC(test_change_mult_str_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_single_num_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_mult_num_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_single_bool_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_mult_bool_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_single_null_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_mult_null_json_to_ptr_arr_single_char_num),
    // FUNC(test_change_single_str_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_mult_str_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_single_num_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_mult_num_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_single_bool_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_mult_bool_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_single_null_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_mult_null_json_to_ptr_arr_single_char_bool),
    // FUNC(test_change_equal_mult_str_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_more_mult_str_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_less_mult_str_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_diff_mult_str_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_equal_mult_num_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_more_mult_num_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_less_mult_num_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_diff_mult_num_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_equal_mult_bool_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_more_mult_bool_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_less_mult_bool_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_diff_mult_bool_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_equal_mult_null_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_more_mult_null_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_less_mult_null_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_diff_mult_null_json_to_ptr_arr_mult_char_str),
    // FUNC(test_change_equal_mult_str_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_more_mult_str_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_less_mult_str_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_diff_mult_str_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_equal_mult_num_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_more_mult_num_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_less_mult_num_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_diff_mult_num_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_equal_mult_bool_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_more_mult_bool_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_less_mult_bool_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_diff_mult_bool_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_equal_mult_null_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_more_mult_null_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_less_mult_null_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_diff_mult_null_json_to_ptr_arr_mult_char_num),
    // FUNC(test_change_equal_mult_str_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_more_mult_str_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_less_mult_str_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_diff_mult_str_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_equal_mult_num_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_more_mult_num_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_less_mult_num_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_diff_mult_num_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_equal_mult_bool_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_more_mult_bool_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_less_mult_bool_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_diff_mult_bool_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_equal_mult_null_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_more_mult_null_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_less_mult_null_json_to_ptr_arr_mult_char_bool),
    // FUNC(test_change_diff_mult_null_json_to_ptr_arr_mult_char_bool),
    {NULL, NULL}};

#endif
