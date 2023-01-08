/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 12:58:17
 * @LastEditTime : 2023-01-08 20:48:33
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/json_to_mult.h
 */

#ifndef __JSON_TO_MULT_H_
#define __JSON_TO_MULT_H_

#include "../include/obj.h"
#include "../include/test.h"

static const struct TestChangeToMult ChangeToMult[] = {
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
    {NULL, NULL}};

#endif
