/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-09 23:05:45
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/char/test_char_mult_to_json.h
 */

#ifndef __TEST_CHAR_MULT_TO_JSON_H_
#define __TEST_CHAR_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_char.h"
#include "test_non_non_char.h"
#include "test_ptr_arr_char.h"
#include "test_ptr_non_char.h"

static const struct TestChangeToJson NonNonCharChangeToJson[] = {
    FUNC(test_change_non_non_single_char_str_to_json),
    FUNC(test_change_non_non_single_char_num_to_json),
    FUNC(test_change_non_non_single_char_bool_to_json),
    FUNC(test_change_non_non_mult_char_str_to_json),
    FUNC(test_change_non_non_mult_char_num_to_json),
    FUNC(test_change_non_non_mult_char_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonCharChangeToJson[] = {
    FUNC(test_change_ptr_non_single_char_str_to_json),
    FUNC(test_change_ptr_non_single_char_num_to_json),
    FUNC(test_change_ptr_non_single_char_bool_to_json),
    FUNC(test_change_ptr_non_mult_char_str_to_json),
    FUNC(test_change_ptr_non_mult_char_num_to_json),
    FUNC(test_change_ptr_non_mult_char_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrCharChangeToJson[] = {
    FUNC(test_change_non_arr_single_char_str_to_json),
    FUNC(test_change_non_arr_single_char_num_to_json),
    FUNC(test_change_non_arr_single_char_bool_to_json),
    FUNC(test_change_non_arr_mult_char_str_to_json),
    FUNC(test_change_non_arr_mult_char_num_to_json),
    FUNC(test_change_non_arr_mult_char_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrCharChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_char_str_to_json),
    FUNC(test_change_ptr_arr_single_char_num_to_json),
    FUNC(test_change_ptr_arr_single_char_bool_to_json),
    FUNC(test_change_ptr_arr_mult_char_str_to_json),
    FUNC(test_change_ptr_arr_mult_char_num_to_json),
    FUNC(test_change_ptr_arr_mult_char_bool_to_json),
    {NULL, NULL}};

#endif
