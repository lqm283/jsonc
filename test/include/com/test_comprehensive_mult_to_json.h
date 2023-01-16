/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-14 16:44:31
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/com/test_comprehensive_mult_to_json.h
 */

#ifndef __TEST_COMPREHENSIVE_MULT_TO_JSON_H_
#define __TEST_COMPREHENSIVE_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_comprehensive.h"

static const struct TestChangeToJson NonNonComChangeToJson[] = {
    FUNC(test_change_non_non_single_com_uninfo_to_json),
    FUNC(test_change_non_non_single_com_ack_to_json),
    FUNC(test_change_non_non_single_com_stream_to_json),
    {NULL, NULL}};

#endif
