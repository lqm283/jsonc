/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 09:37:00
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int64/test_int64_mult_to_json.h
 */

#ifndef __TEST_INT64_MULT_TO_JSON_H_
#define __TEST_INT64_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_int64.h"
#include "test_non_non_int64.h"
#include "test_ptr_arr_int64.h"
#include "test_ptr_non_int64.h"

static const struct TestChangeToJson NonNonInt64ChangeToJson[] = {
    FUNC(test_change_non_non_single_int64_str_to_json),
    FUNC(test_change_non_non_single_int64_num_to_json),
    FUNC(test_change_non_non_single_int64_bool_to_json),
    FUNC(test_change_non_non_mult_int64_str_to_json),
    FUNC(test_change_non_non_mult_int64_num_to_json),
    FUNC(test_change_non_non_mult_int64_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonInt64ChangeToJson[] = {
    FUNC(test_change_ptr_non_single_int64_str_to_json),
    FUNC(test_change_ptr_non_single_int64_num_to_json),
    FUNC(test_change_ptr_non_single_int64_bool_to_json),
    FUNC(test_change_ptr_non_mult_int64_str_to_json),
    FUNC(test_change_ptr_non_mult_int64_num_to_json),
    FUNC(test_change_ptr_non_mult_int64_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrInt64ChangeToJson[] = {
    FUNC(test_change_non_arr_single_int64_num_to_json),
    FUNC(test_change_non_arr_single_int64_bool_to_json),
    FUNC(test_change_non_arr_mult_int64_num_to_json),
    FUNC(test_change_non_arr_mult_int64_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrInt64ChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_int64_str_to_json),
    FUNC(test_change_ptr_arr_single_int64_num_to_json),
    FUNC(test_change_ptr_arr_single_int64_bool_to_json),
    FUNC(test_change_ptr_arr_mult_int64_str_to_json),
    FUNC(test_change_ptr_arr_mult_int64_num_to_json),
    FUNC(test_change_ptr_arr_mult_int64_bool_to_json),
    {NULL, NULL}};

#endif
