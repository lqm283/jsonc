/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 12:58:17
 * @LastEditTime : 2023-01-11 08:19:57
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/json_to_mult.h
 */

#ifndef __JSON_TO_MULT_H_
#define __JSON_TO_MULT_H_

#include "char/test_char_json_to_mult.h"
#include "uint16/test_uint16_json_to_mult.h"
#include "uint8/test_uint8_json_to_mult.h"

static const struct TestChangeToMult *ChangeToMult[] = {
    //
    NonNonCharChangeToMult,
    PtrNonCharChangeToMult,
    NonArrCharChangeToMult,
    PtrArrCharChangeToMult,
    NonNonUint8ChangeToMult,
    PtrNonUint8ChangeToMult,
    NonArrUint8ChangeToMult,
    PtrArrUint8ChangeToMult,
    NonNonUint16ChangeToMult,
    PtrNonUint16ChangeToMult,
    NonArrUint16ChangeToMult,
    PtrArrUint16ChangeToMult,
    NULL};

#endif
