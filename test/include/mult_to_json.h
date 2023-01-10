/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 12:54:14
 * @LastEditTime : 2023-01-10 20:52:28
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/mult_to_json.h
 */
#ifndef __MULT_TO_JSON_H_
#define __MULT_TO_JSON_H_

#include "../include/obj.h"
#include "char/test_char_mult_to_json.h"
#include "uint8/test_uint8_mult_to_json.h"

static const struct TestChangeToJson *ChangeToJson[] = {
    //
    NonNonCharChangeToJson,
    PtrNonCharChangeToJson,
    NonArrCharChangeToJson,
    PtrArrCharChangeToJson,
    NonNonUint8ChangeToJson,
    PtrNonUint8ChangeToJson,
    NonArrUint8ChangeToJson,
    PtrArrUint8ChangeToJson,
    NULL};

#endif
