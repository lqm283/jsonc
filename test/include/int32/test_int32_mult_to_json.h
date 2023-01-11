/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 09:37:00
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/int32/test_int32_mult_to_json.h
 */

#ifndef __TEST_INT32_MULT_TO_JSON_H_
#define __TEST_INT32_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_int32.h"
#include "test_non_non_int32.h"
#include "test_ptr_arr_int32.h"
#include "test_ptr_non_int32.h"

static const struct TestChangeToJson NonNonInt32ChangeToJson[] = {
    FUNC(test_change_non_non_single_int32_str_to_json),
    FUNC(test_change_non_non_single_int32_num_to_json),
    FUNC(test_change_non_non_single_int32_bool_to_json),
    FUNC(test_change_non_non_mult_int32_str_to_json),
    FUNC(test_change_non_non_mult_int32_num_to_json),
    FUNC(test_change_non_non_mult_int32_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonInt32ChangeToJson[] = {
    FUNC(test_change_ptr_non_single_int32_str_to_json),
    FUNC(test_change_ptr_non_single_int32_num_to_json),
    FUNC(test_change_ptr_non_single_int32_bool_to_json),
    FUNC(test_change_ptr_non_mult_int32_str_to_json),
    FUNC(test_change_ptr_non_mult_int32_num_to_json),
    FUNC(test_change_ptr_non_mult_int32_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrInt32ChangeToJson[] = {
    FUNC(test_change_non_arr_single_int32_num_to_json),
    FUNC(test_change_non_arr_single_int32_bool_to_json),
    FUNC(test_change_non_arr_mult_int32_num_to_json),
    FUNC(test_change_non_arr_mult_int32_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrInt32ChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_int32_str_to_json),
    FUNC(test_change_ptr_arr_single_int32_num_to_json),
    FUNC(test_change_ptr_arr_single_int32_bool_to_json),
    FUNC(test_change_ptr_arr_mult_int32_str_to_json),
    FUNC(test_change_ptr_arr_mult_int32_num_to_json),
    FUNC(test_change_ptr_arr_mult_int32_bool_to_json),
    {NULL, NULL}};

#endif
