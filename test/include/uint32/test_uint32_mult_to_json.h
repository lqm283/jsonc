/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 10:21:54
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint32/test_uint32_mult_to_json.h
 */

#ifndef __TEST_UINT32_MULT_TO_JSON_H_
#define __TEST_UINT32_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_uint32.h"
#include "test_non_non_uint32.h"
#include "test_ptr_arr_uint32.h"
#include "test_ptr_non_uint32.h"

static const struct TestChangeToJson NonNonUint32ChangeToJson[] = {
    FUNC(test_change_non_non_single_uint32_str_to_json),
    FUNC(test_change_non_non_single_uint32_num_to_json),
    FUNC(test_change_non_non_single_uint32_bool_to_json),
    FUNC(test_change_non_non_mult_uint32_str_to_json),
    FUNC(test_change_non_non_mult_uint32_num_to_json),
    FUNC(test_change_non_non_mult_uint32_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonUint32ChangeToJson[] = {
    FUNC(test_change_ptr_non_single_uint32_str_to_json),
    FUNC(test_change_ptr_non_single_uint32_num_to_json),
    FUNC(test_change_ptr_non_single_uint32_bool_to_json),
    FUNC(test_change_ptr_non_mult_uint32_str_to_json),
    FUNC(test_change_ptr_non_mult_uint32_num_to_json),
    FUNC(test_change_ptr_non_mult_uint32_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrUint32ChangeToJson[] = {
    FUNC(test_change_non_arr_single_uint32_num_to_json),
    FUNC(test_change_non_arr_single_uint32_bool_to_json),
    FUNC(test_change_non_arr_mult_uint32_num_to_json),
    FUNC(test_change_non_arr_mult_uint32_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrUint32ChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_uint32_str_to_json),
    FUNC(test_change_ptr_arr_single_uint32_num_to_json),
    FUNC(test_change_ptr_arr_single_uint32_bool_to_json),
    FUNC(test_change_ptr_arr_mult_uint32_str_to_json),
    FUNC(test_change_ptr_arr_mult_uint32_num_to_json),
    FUNC(test_change_ptr_arr_mult_uint32_bool_to_json),
    {NULL, NULL}};

#endif
