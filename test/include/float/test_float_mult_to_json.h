/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 13:44:58
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/float/test_float_mult_to_json.h
 */

#ifndef __TEST_FLOAT_MULT_TO_JSON_H_
#define __TEST_FLOAT_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_float.h"
#include "test_non_non_float.h"
#include "test_ptr_arr_float.h"
#include "test_ptr_non_float.h"

static const struct TestChangeToJson NonNonFloatChangeToJson[] = {
    FUNC(test_change_non_non_single_float_num_to_json),
    FUNC(test_change_non_non_single_float_bool_to_json),
    FUNC(test_change_non_non_mult_float_num_to_json),
    FUNC(test_change_non_non_mult_float_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonFloatChangeToJson[] = {
    FUNC(test_change_ptr_non_single_float_num_to_json),
    FUNC(test_change_ptr_non_single_float_bool_to_json),
    FUNC(test_change_ptr_non_mult_float_num_to_json),
    FUNC(test_change_ptr_non_mult_float_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrFloatChangeToJson[] = {
    FUNC(test_change_non_arr_single_float_num_to_json),
    FUNC(test_change_non_arr_single_float_bool_to_json),
    FUNC(test_change_non_arr_mult_float_num_to_json),
    FUNC(test_change_non_arr_mult_float_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrFloatChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_float_num_to_json),
    FUNC(test_change_ptr_arr_single_float_bool_to_json),
    FUNC(test_change_ptr_arr_mult_float_num_to_json),
    FUNC(test_change_ptr_arr_mult_float_bool_to_json),
    {NULL, NULL}};

#endif
