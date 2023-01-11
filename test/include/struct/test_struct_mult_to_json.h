/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 19:52:08
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_struct_mult_to_json.h
 */

#ifndef __TEST_STRUCT_MULT_TO_JSON_H_
#define __TEST_STRUCT_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_struct.h"
#include "test_non_non_struct.h"
#include "test_ptr_arr_struct.h"
#include "test_ptr_non_struct.h"

static const struct TestChangeToJson NonNonStructChangeToJson[] = {
    FUNC(test_change_non_non_single_struct_to_json),
    FUNC(test_change_non_non_mult1_struct_to_json),
    FUNC(test_change_non_non_multmax_struct_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrNonStructChangeToJson[] = {
    FUNC(test_change_ptr_non_single_struct_to_json),
    FUNC(test_change_ptr_non_mult1_struct_to_json),
    FUNC(test_change_ptr_non_multmax_struct_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson NonArrStructChangeToJson[] = {
    FUNC(test_change_non_arr_single_struct_to_json),
    FUNC(test_change_non_arr_mult1_struct_to_json),
    FUNC(test_change_non_arr_multmax_struct_to_json),
    {NULL, NULL}};

static const struct TestChangeToJson PtrArrStructChangeToJson[] = {
    FUNC(test_change_ptr_arr_single_struct_to_json),
    FUNC(test_change_ptr_arr_mult1_struct_to_json),
    FUNC(test_change_ptr_arr_multmax_struct_to_json),
    {NULL, NULL}};

#endif
