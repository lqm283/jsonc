/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 12:16:33
 * @LastEditTime : 2023-01-06 13:02:50
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/obj.h
 */
#ifndef __OBJ_H_
#define __OBJ_H_

struct TestChangeToJson {
    const char* name;
    char* (*test_change_to_json)(char* exp, char* real);
};

struct TestChangeToMult {
    const char* name;
    int (*test_change_to_mult)(char* json);
};

#define FUNC(func)  \
    {               \
#func, func \
    }

#endif
