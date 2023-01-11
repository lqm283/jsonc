/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 13:53:50
 * @LastEditTime : 2023-01-11 20:40:20
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/union/test_union_mult_to_json.h
 */

#ifndef __TEST_UNION_MULT_TO_JSON_H_
#define __TEST_UNION_MULT_TO_JSON_H_

#include "../../include/obj.h"
#include "test_non_arr_union.h"
#include "test_non_non_union.h"
#include "test_ptr_arr_union.h"
#include "test_ptr_non_union.h"

static const struct TestChangeToJson NonNonStructChangeToJson[] = {{NULL, NULL}};

static const struct TestChangeToJson PtrNonStructChangeToJson[] = {{NULL, NULL}};

static const struct TestChangeToJson NonArrStructChangeToJson[] = {{NULL, NULL}};

static const struct TestChangeToJson PtrArrStructChangeToJson[] = {{NULL, NULL}};

#endif
