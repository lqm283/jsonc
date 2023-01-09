/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 12:54:14
 * @LastEditTime : 2023-01-09 11:21:51
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/mult_to_json.h
 */
#ifndef __MULT_TO_JSON_H_
#define __MULT_TO_JSON_H_

#include "../include/obj.h"
#include "../include/test.h"

static const struct TestChangeToJson ChangeToJson[] = {
    FUNC(test_change_non_non_single_char_str_to_json),
    FUNC(test_change_non_non_single_char_num_to_json),
    FUNC(test_change_non_non_single_char_bool_to_json),
    FUNC(test_change_non_non_mult_char_str_to_json),
    FUNC(test_change_non_non_mult_char_num_to_json),
    FUNC(test_change_non_non_mult_char_bool_to_json),
    {NULL, NULL}};

#endif
