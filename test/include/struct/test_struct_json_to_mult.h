/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 14:01:35
 * @LastEditTime : 2023-01-11 20:04:34
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/struct/test_struct_json_to_mult.h
 */
#ifndef __TEST_STRUCT_JSON_TO_MULT_H_
#define __TEST_STRUCT_JSON_TO_MULT_H_

#include "../obj.h"
#include "test_non_arr_struct.h"
#include "test_non_non_struct.h"
#include "test_ptr_arr_struct.h"
#include "test_ptr_non_struct.h"

static const struct TestChangeToMult NonNonStructChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_non_single_struct_one),
    FUNC(test_change_single_str_json_to_non_non_mult_struct_two),
    FUNC(test_change_single_str_json_to_non_non_mult_struct_max),
    {NULL, NULL}};

static const struct TestChangeToMult PtrNonStructChangeToMult[] = {
    FUNC(test_change_single_str_json_to_ptr_non_single_struct_one),
    FUNC(test_change_single_str_json_to_ptr_non_mult_struct_two),
    FUNC(test_change_single_str_json_to_ptr_non_mult_struct_max),
    {NULL, NULL}};

static const struct TestChangeToMult NonArrStructChangeToMult[] = {
    FUNC(test_change_single_str_json_to_non_arr_single_struct_one),
    FUNC(test_change_single_str_json_to_non_arr_mult_struct_two),
    FUNC(test_change_single_str_json_to_non_arr_mult_struct_max),
    {NULL, NULL}};

static const struct TestChangeToMult PtrArrStructChangeToMult[] = {
    FUNC(test_change_single_str_json_to_ptr_arr_single_struct_one),
    FUNC(test_change_single_str_json_to_ptr_arr_mult_struct_two),
    FUNC(test_change_single_str_json_to_ptr_arr_mult_struct_max),
    {NULL, NULL}};

#endif
