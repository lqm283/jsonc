/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-10 20:50:50
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/uint8/test_uint8_mult_to_json.h
 */

#ifndef __TEST_UINT8_MULT_TO_JSON_H_
#define __TEST_UINT8_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_uint8.h"
#include "test_non_non_uint8.h"
#include "test_ptr_arr_uint8.h"
#include "test_ptr_non_uint8.h"

static const struct TestChangeToJson NonNonUint8ChangeToJson[] = {
    FUNC(test_change_non_non_single_uint8_str_to_json),
    FUNC(test_change_non_non_single_uint8_num_to_json),
    FUNC(test_change_non_non_single_uint8_bool_to_json),
    FUNC(test_change_non_non_mult_uint8_str_to_json),
    FUNC(test_change_non_non_mult_uint8_num_to_json),
    FUNC(test_change_non_non_mult_uint8_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonUint8ChangeToJson[] = {
    FUNC(test_change_ptr_non_single_uint8_str_to_json),
    FUNC(test_change_ptr_non_single_uint8_num_to_json),
    FUNC(test_change_ptr_non_single_uint8_bool_to_json),
    FUNC(test_change_ptr_non_mult_uint8_str_to_json),
    FUNC(test_change_ptr_non_mult_uint8_num_to_json),
    FUNC(test_change_ptr_non_mult_uint8_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrUint8ChangeToJson[] = {
    FUNC(test_change_non_arr_single_uint8_str_to_json),
    FUNC(test_change_non_arr_single_uint8_num_to_json),
    FUNC(test_change_non_arr_single_uint8_bool_to_json),
    FUNC(test_change_non_arr_mult_uint8_str_to_json),
    FUNC(test_change_non_arr_mult_uint8_num_to_json),
    FUNC(test_change_non_arr_mult_uint8_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrUint8ChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_uint8_str_to_json),
    FUNC(test_change_ptr_arr_single_uint8_num_to_json),
    FUNC(test_change_ptr_arr_single_uint8_bool_to_json),
    FUNC(test_change_ptr_arr_mult_uint8_str_to_json),
    FUNC(test_change_ptr_arr_mult_uint8_num_to_json),
    FUNC(test_change_ptr_arr_mult_uint8_bool_to_json),
    {NULL, NULL}};

#endif
