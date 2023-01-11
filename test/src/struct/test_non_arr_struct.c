/*
 * @Author       : lqm283
 * @Date         : 2023-01-09 16:19:33
 * @LastEditTime : 2023-01-11 15:19:05
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/struct/test_non_arr_struct.c
 */

#include "../../include/struct/test_non_arr_struct.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
------------------
复合类型转换为 json
------------------
*/

// 单个 struct 类型转换为 json
// char* test_change_non_arr_single_struct_to_json(char* exp, char* real) {
//     char* ret = 0;
//     // char* e = "{\"num\":[1,2,3,4,5]}";
//     // struct TestNonNonSingleStruct s = {{1, 2, 3, 4, 5}};
//     // ret = JsoncSerialize(real, &s, TestNonNonSingleStruct);
//     // if (ret) {
//     //     strcpy(exp, e);
//     // }
//     return ret;
// }