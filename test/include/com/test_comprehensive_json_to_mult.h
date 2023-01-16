/*
 * @Author       : lqm283
 * @Date         : 2023-01-14 14:27:53
 * @LastEditTime : 2023-01-14 21:04:37
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/com/test_comprehensive_json_to_mult.h
 */
/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 14:01:35
 * @LastEditTime : 2023-01-10 16:59:47
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/char/test_char_json_to_mult.h
 */
#ifndef __TEST_COMPREHENSIVE_JSON_TO_MULT_H_
#define __TEST_COMPREHENSIVE_JSON_TO_MULT_H_

#include "../obj.h"
#include "test_comprehensive.h"

static const struct TestChangeToMult NonNonComChangeToMult[] = {
    FUNC(test_change_single_uninfo_json_to_non_non_mult_com_data),
    FUNC(test_change_single_ack_json_to_non_non_mult_com_data),
    FUNC(test_change_single_cmd_json_to_non_non_mult_com_data),
    {NULL, NULL}};

#endif
