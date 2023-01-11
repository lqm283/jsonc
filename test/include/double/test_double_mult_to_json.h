/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 14:15:56
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/double/test_double_mult_to_json.h
 */

#ifndef __TEST_DOUBLE_MULT_TO_JSON_H_
#define __TEST_DOUBLE_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_double.h"
#include "test_non_non_double.h"
#include "test_ptr_arr_double.h"
#include "test_ptr_non_double.h"

static const struct TestChangeToJson NonNonDoubleChangeToJson[] = {
    FUNC(test_change_non_non_single_double_num_to_json),
    FUNC(test_change_non_non_single_double_bool_to_json),
    FUNC(test_change_non_non_mult_double_num_to_json),
    FUNC(test_change_non_non_mult_double_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonDoubleChangeToJson[] = {
    FUNC(test_change_ptr_non_single_double_num_to_json),
    FUNC(test_change_ptr_non_single_double_bool_to_json),
    FUNC(test_change_ptr_non_mult_double_num_to_json),
    FUNC(test_change_ptr_non_mult_double_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrDoubleChangeToJson[] = {
    FUNC(test_change_non_arr_single_double_num_to_json),
    FUNC(test_change_non_arr_single_double_bool_to_json),
    FUNC(test_change_non_arr_mult_double_num_to_json),
    FUNC(test_change_non_arr_mult_double_bool_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrDoubleChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_double_num_to_json),
    FUNC(test_change_ptr_arr_single_double_bool_to_json),
    FUNC(test_change_ptr_arr_mult_double_num_to_json),
    FUNC(test_change_ptr_arr_mult_double_bool_to_json),
    {NULL, NULL}};

#endif
