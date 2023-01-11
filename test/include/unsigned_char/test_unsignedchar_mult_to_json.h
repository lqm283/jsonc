/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 12:31:49
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/unsigned char/test_unsignedchar_mult_to_json.h
 */

#ifndef __TEST_UNSIGNED_CHAR_MULT_TO_JSON_H_
#define __TEST_UNSIGNED_CHAR_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_unsignedchar.h"
#include "test_non_non_unsignedchar.h"
#include "test_ptr_arr_unsignedchar.h"
#include "test_ptr_non_unsignedchar.h"

static const struct TestChangeToJson NonNonUnsignedCharChangeToJson[] = {
    FUNC(test_change_non_non_single_unsignedchar_str_to_json),
    FUNC(test_change_non_non_single_unsignedchar_num_to_json),
    FUNC(test_change_non_non_single_unsignedchar_bool_to_json),
    FUNC(test_change_non_non_mult_unsignedchar_str_to_json),
    FUNC(test_change_non_non_mult_unsignedchar_num_to_json),
    FUNC(test_change_non_non_mult_unsignedchar_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonUnsignedCharChangeToJson[] = {
    FUNC(test_change_ptr_non_single_unsignedchar_str_to_json),
    FUNC(test_change_ptr_non_single_unsignedchar_num_to_json),
    FUNC(test_change_ptr_non_single_unsignedchar_bool_to_json),
    FUNC(test_change_ptr_non_mult_unsignedchar_str_to_json),
    FUNC(test_change_ptr_non_mult_unsignedchar_num_to_json),
    FUNC(test_change_ptr_non_mult_unsignedchar_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrUnsignedCharChangeToJson[] = {
    FUNC(test_change_non_arr_single_unsignedchar_str_to_json),
    FUNC(test_change_non_arr_single_unsignedchar_num_to_json),
    FUNC(test_change_non_arr_single_unsignedchar_bool_to_json),
    FUNC(test_change_non_arr_mult_unsignedchar_str_to_json),
    FUNC(test_change_non_arr_mult_unsignedchar_num_to_json),
    FUNC(test_change_non_arr_mult_unsignedchar_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrUnsignedCharChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_unsignedchar_str_to_json),
    FUNC(test_change_ptr_arr_single_unsignedchar_num_to_json),
    FUNC(test_change_ptr_arr_single_unsignedchar_bool_to_json),
    FUNC(test_change_ptr_arr_mult_unsignedchar_str_to_json),
    FUNC(test_change_ptr_arr_mult_unsignedchar_num_to_json),
    FUNC(test_change_ptr_arr_mult_unsignedchar_bool_to_json),
    {NULL, NULL}};

#endif
