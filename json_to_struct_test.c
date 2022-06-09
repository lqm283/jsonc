/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:45
 * @LastEditTime : 2022-06-09 15:51:26
 * @LastEditors  : lqm283 lanqianming@hotmail.com
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/json_to_struct_test.c
 */

#include <stdio.h>
#include <sys/types.h>

#include "jsonc.h"
#include "main.h"

static const char *BOOL[] = {"false", "true"};

int json_to_struct_test(void) {
    int ret = 0;
    char buf[81920];
    struct test test;

    // 基本类型
    // char 类型
    char char_str[100];
    char char_num;
    char char_bool;
    // unsigned char 类型
    uint8_t uchar_str[100];
    uint8_t uchar_num;
    uint8_t uchar_bool;
    // short int 类型
    short short_str[100];
    short short_num;
    short short_bool;
    // unsigned short int 类型
    unsigned short ushort_str[100];
    unsigned short ushort_num;
    unsigned short ushort_bool;
    // int 类型
    int int_str[100];
    int int_num;
    int int_bool;
    // unsigned int 类型
    unsigned int uint_str[100];
    unsigned int uint_num;
    unsigned int uint_bool;
    // long long 类型
    long long ll_str[100];
    long long ll_num;
    long long ll_bool;
    // unsigned long long 类型
    unsigned long long ull_str[100];
    unsigned long long ull_num;
    unsigned long long ull_bool;
    // float 类型
    float float_str[100];
    float float_num;
    float float_bool;
    // double 类型
    double double_str[100];
    double double_num;
    double double_bool;

    // 指针数组
    // char 类型
    char p_arr_char_str[100];
    char p_arr_char_num[100];
    char p_arr_char_bool[100];
    // unsigned char 类型
    uint8_t p_arr_uchar_str[100];
    uint8_t p_arr_uchar_num[100];
    uint8_t p_arr_uchar_bool[100];
    // short int 类型
    short p_arr_short_str[100];
    short p_arr_short_num[100];
    short p_arr_short_bool[100];
    // unsigned short int 类型
    unsigned short p_arr_ushort_str[100];
    unsigned short p_arr_ushort_num[100];
    unsigned short p_arr_ushort_bool[100];
    // int 类型
    int p_arr_int_str[100];
    int p_arr_int_num[100];
    int p_arr_int_bool[100];
    // unsigned int 类型
    unsigned int p_arr_uint_str[100];
    unsigned int p_arr_uint_num[100];
    unsigned int p_arr_uint_bool[100];
    // long long 类型
    long long p_arr_ll_str[100];
    long long p_arr_ll_num[100];
    long long p_arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long p_arr_ull_str[100];
    unsigned long long p_arr_ull_num[100];
    unsigned long long p_arr_ull_bool[100];
    // float 类型
    float p_arr_float_str[100];
    float p_arr_float_num[100];
    float p_arr_float_bool[100];
    // double 类型
    double p_arr_double_str[100];
    double p_arr_double_num[100];
    double p_arr_double_bool[100];

    struct st p_test_st;
    struct st p_arr_test_st[2];

    test.p_char_str = char_str;
    test.p_char_num = &char_num;
    test.p_char_bool = &char_bool;
    test.p_uchar_str = uchar_str;
    test.p_uchar_num = &uchar_num;
    test.p_uchar_bool = &uchar_bool;
    test.p_short_str = short_str;
    printf("&short_str = 0x%lx\n", (long)short_str);
    test.p_short_num = &short_num;
    test.p_short_bool = &short_bool;
    printf("&short_bool = 0x%lx\n", (long)&short_bool);
    test.p_ushort_str = ushort_str;
    test.p_ushort_num = &ushort_num;
    test.p_ushort_bool = &ushort_bool;
    test.p_int_str = int_str;
    test.p_int_num = &int_num;
    test.p_int_bool = &int_bool;
    test.p_uint_str = uint_str;
    test.p_uint_num = &uint_num;
    test.p_uint_bool = &uint_bool;
    test.p_ll_str = ll_str;
    test.p_ll_num = &ll_num;
    test.p_ll_bool = &ll_bool;
    test.p_ull_str = ull_str;
    test.p_ull_num = &ull_num;
    test.p_ull_bool = &ull_bool;
    test.p_float_str = float_str;
    test.p_float_num = &float_num;
    test.p_float_bool = &float_bool;
    test.p_double_str = double_str;
    test.p_double_num = &double_num;
    test.p_double_bool = &double_bool;

    // char 类型
    for (int i = 0; i < 100; i++) {
        test.p_arr_char_str[i] = &p_arr_char_str[i];
        test.p_arr_char_num[i] = &p_arr_char_num[i];
        test.p_arr_char_bool[i] = &p_arr_char_bool[i];
        // unsigned char 类型
        test.p_arr_uchar_str[i] = &p_arr_uchar_str[i];
        test.p_arr_uchar_num[i] = &p_arr_uchar_num[i];
        test.p_arr_uchar_bool[i] = &p_arr_uchar_bool[i];
        // short int 类型
        test.p_arr_short_str[i] = &p_arr_short_str[i];
        test.p_arr_short_num[i] = &p_arr_short_num[i];
        test.p_arr_short_bool[i] = &p_arr_short_bool[i];
        // unsigned short int 类型
        test.p_arr_ushort_str[i] = &p_arr_ushort_str[i];
        test.p_arr_ushort_num[i] = &p_arr_ushort_num[i];
        test.p_arr_ushort_bool[i] = &p_arr_ushort_bool[i];
        // int 类型
        test.p_arr_int_str[i] = &p_arr_int_str[i];
        test.p_arr_int_num[i] = &p_arr_int_num[i];
        test.p_arr_int_bool[i] = &p_arr_int_bool[i];
        // unsigned int 类型
        test.p_arr_uint_str[i] = &p_arr_uint_str[i];
        test.p_arr_uint_num[i] = &p_arr_uint_num[i];
        test.p_arr_uint_bool[i] = &p_arr_uint_bool[i];
        // long long 类型
        test.p_arr_ll_str[i] = &p_arr_ll_str[i];
        test.p_arr_ll_num[i] = &p_arr_ll_num[i];
        test.p_arr_ll_bool[i] = &p_arr_ll_bool[i];
        // unsigned long long 类型
        test.p_arr_ull_str[i] = &p_arr_ull_str[i];
        test.p_arr_ull_num[i] = &p_arr_ull_num[i];
        test.p_arr_ull_bool[i] = &p_arr_ull_bool[i];
        // float 类型
        test.p_arr_float_str[i] = &p_arr_float_str[i];
        test.p_arr_float_num[i] = &p_arr_float_num[i];
        test.p_arr_float_bool[i] = &p_arr_float_bool[i];
        // double 类型
        test.p_arr_double_str[i] = &p_arr_double_str[i];
        test.p_arr_double_num[i] = &p_arr_double_num[i];
        test.p_arr_double_bool[i] = &p_arr_double_bool[i];
    }

    test.p_test_st = &p_test_st;
    test.p_arr_test_st[0] = &p_arr_test_st[0];
    test.p_arr_test_st[1] = &p_arr_test_st[1];

    FILE *file = fopen("json/test.json", "r");
    if (!file) {
        return -1;
    }
    unsigned long n = fread(buf, 1, sizeof(buf), file);
    buf[n] = 0;

    ret = jsonc_deserialize(buf, &test, STRUCT(test));

    printf("test.char_str = %c\n", test.char_str);
    printf("test.char_num = %d\n", test.char_num);
    printf("test.char_bool = %s\n", BOOL[(uint8_t)test.char_bool]);

    printf("test.uchar_str = %c\n", test.uchar_str);
    printf("test.uchar_num = %d\n", test.uchar_num);
    printf("test.uchar_bool = %s\n", BOOL[test.uchar_bool]);

    printf("test.short_str = %s\n", (char *)&test.short_str);
    printf("test.short_num = %d\n", test.short_num);
    printf("test.short_bool = %s\n", BOOL[test.short_bool]);

    printf("test.ushort_str = %s\n", (char *)&test.ushort_str);
    printf("test.ushort_num = %d\n", test.ushort_num);
    printf("test.ushort_bool = %s\n", BOOL[test.ushort_bool]);

    printf("test.int_str = %s\n", (char *)&test.int_str);
    printf("test.int_num = %d\n", test.int_num);
    printf("test.int_bool = %s\n", BOOL[test.int_bool]);

    printf("test.uint_str = %s\n", (char *)&test.uint_str);
    printf("test.uint_num = %d\n", test.uint_num);
    printf("test.uint_bool = %s\n", BOOL[test.uint_bool]);

    printf("test.ll_str = %s\n", (char *)&test.ll_str);
    printf("test.ll_num = %lld\n", test.ll_num);
    printf("test.ll_bool = %s\n", BOOL[test.ll_bool]);

    printf("test.ull_str = %s\n", (char *)&test.ull_str);
    printf("test.ull_num = %lld\n", test.ull_num);
    printf("test.ull_bool = %s\n", BOOL[test.ull_bool]);

    printf("test.float_str = %s\n", (char *)&test.float_str);
    printf("test.float_num = %f\n", test.float_num);
    printf("test.float_bool = %f\n", test.float_bool);

    printf("test.double_str = %s\n", (char *)&test.double_str);
    printf("test.double_num = %f\n", test.double_num);
    printf("test.double_bool = %f\n", test.double_bool);

    printf("test.p_char_str = %s\n", test.p_char_str);
    printf("test.p_char_num = %d\n", *test.p_char_num);
    printf("test.p_char_bool = %s\n", BOOL[(uint8_t)*test.p_char_bool]);

    printf("test.p_uchar_str = %s\n", test.p_uchar_str);
    printf("test.p_uchar_num = %d\n", *test.p_uchar_num);
    printf("test.p_uchar_bool = %s\n", BOOL[*test.p_uchar_bool]);

    printf("test.p_short_str = %s\n", (char *)test.p_short_str);
    printf("test.p_short_num = %d\n", *test.p_short_num);
    printf("test.p_short_bool = %s\n", BOOL[*test.p_short_bool]);

    printf("test.p_ushort_str = %s\n", (char *)test.p_ushort_str);
    printf("test.p_ushort_num = %d\n", *test.p_ushort_num);
    printf("test.p_ushort_bool = %s\n", BOOL[*test.p_ushort_bool]);

    printf("test.p_int_str = %s\n", (char *)test.p_int_str);
    printf("test.p_int_num = %d\n", *test.p_int_num);
    printf("test.p_int_bool = %s\n", BOOL[*test.p_int_bool]);

    printf("test.p_uint_str = %s\n", (char *)test.p_uint_str);
    printf("test.p_uint_num = %d\n", *test.p_uint_num);
    printf("test.p_uint_bool = %s\n", BOOL[*test.p_uint_bool]);

    printf("test.p_ll_str = %s\n", (char *)test.p_ll_str);
    printf("test.p_ll_num = %lld\n", *test.p_ll_num);
    printf("test.p_ll_bool = %s\n", BOOL[*test.p_ll_bool]);

    printf("test.p_ull_str = %s\n", (char *)test.p_ull_str);
    printf("test.p_ull_num = %lld\n", *test.p_ull_num);
    printf("test.p_ull_bool = %s\n", BOOL[*test.p_ull_bool]);

    printf("test.p_float_str = %s\n", (char *)test.p_float_str);
    printf("test.p_float_num = %f\n", *test.p_float_num);
    printf("test.p_float_bool = %f\n", *test.p_float_bool);

    printf("test.p_double_str = %s\n", (char *)test.p_double_str);
    printf("test.p_double_num = %f\n", *test.p_double_num);
    printf("test.p_double_bool = %f\n", *test.p_double_bool);

    printf("test.arr_char_str = %s\n", (char *)test.arr_char_str);
    printf("test.arr_char_num[0] = %d\n", test.arr_char_num[0]);
    printf("test.arr_char_bool[0] = %s\n", BOOL[(uint8_t)test.arr_char_bool[0]]);

    printf("test.arr_uchar_str = %s\n", (char *)test.arr_uchar_str);
    printf("test.arr_uchar_num[0] = %d\n", test.arr_uchar_num[0]);
    printf("test.arr_uchar_bool[0] = %s\n", BOOL[test.arr_uchar_bool[0]]);

    printf("test.arr_short_str = %s\n", (char *)test.arr_short_str);
    printf("test.arr_short_num[0] = %d\n", test.arr_short_num[0]);
    printf("test.arr_short_bool[0] = %s\n", BOOL[test.arr_short_bool[0]]);

    printf("test.arr_ushort_str = %s\n", (char *)test.arr_ushort_str);
    printf("test.arr_ushort_num[0] = %d\n", test.arr_ushort_num[0]);
    printf("test.arr_ushort_bool[0] = %s\n", BOOL[test.arr_ushort_bool[0]]);

    printf("test.arr_int_str = %s\n", (char *)test.arr_int_str);
    printf("test.arr_int_num[0] = %d\n", test.arr_int_num[0]);
    printf("test.arr_int_bool[0] = %s\n", BOOL[test.arr_int_bool[0]]);

    printf("test.arr_uint_str = %s\n", (char *)test.arr_uint_str);
    printf("test.arr_uint_num[0] = %d\n", test.arr_uint_num[0]);
    printf("test.arr_uint_num[1] = %d\n", test.arr_uint_num[1]);
    printf("test.arr_uint_bool[0] = %s\n", BOOL[test.arr_uint_bool[0]]);

    printf("test.arr_ll_str = %s\n", (char *)test.arr_ll_str);
    printf("test.arr_ll_num[0] = %lld\n", test.arr_ll_num[0]);
    printf("test.arr_ll_bool[0] = %s\n", BOOL[test.arr_ll_bool[0]]);

    printf("test.arr_ull_str = %s\n", (char *)test.arr_ull_str);
    printf("test.arr_ull_num[0] = %lld\n", test.arr_ull_num[0]);
    printf("test.arr_ull_bool[0] = %s\n", BOOL[test.arr_ull_bool[0]]);

    printf("test.arr_float_str = %s\n", (char *)test.arr_float_str);
    printf("test.arr_float_num[0] = %f\n", test.arr_float_num[0]);
    printf("test.arr_float_num[1] = %f\n", test.arr_float_num[1]);
    printf("test.arr_float_bool[0] = %f\n", test.arr_float_bool[0]);

    printf("test.arr_double_str = %s\n", (char *)test.arr_double_str);
    printf("test.arr_double_num[0] = %f\n", test.arr_double_num[0]);
    printf("test.arr_double_bool[0] = %f\n", test.arr_double_bool[0]);

    printf("test.p_arr_char_str[0] = %c\n", *test.p_arr_char_str[0]);
    printf("test.p_arr_char_num[0] = %d\n", *test.p_arr_char_num[0]);
    printf("test.p_arr_char_bool[0] = %s\n", BOOL[(u_int8_t)*test.p_arr_char_bool[0]]);

    printf("test.p_arr_uchar_str[0] = %c\n", *test.p_arr_uchar_str[0]);
    printf("test.p_arr_uchar_num[0] = %d\n", *test.p_arr_uchar_num[0]);
    printf("test.p_arr_uchar_bool[0] = %s\n", BOOL[*test.p_arr_uchar_bool[0]]);

    printf("test.p_arr_short_str[0] = %c\n", *test.p_arr_short_str[0]);
    printf("test.p_arr_short_num[0] = %d\n", *test.p_arr_short_num[0]);
    printf("test.p_arr_short_bool[0] = %s\n", BOOL[*test.p_arr_short_bool[0]]);

    printf("test.p_arr_ushort_str[0] = %c\n", *test.p_arr_ushort_str[0]);
    printf("test.p_arr_ushort_num[0] = %d\n", *test.p_arr_ushort_num[0]);
    printf("test.p_arr_ushort_bool[0] = %s\n", BOOL[*test.p_arr_ushort_bool[0]]);

    printf("test.p_arr_int_str[0] = %c\n", *test.p_arr_int_str[0]);
    printf("test.p_arr_int_num[0] = %d\n", *test.p_arr_int_num[0]);
    printf("test.p_arr_int_bool[0] = %s\n", BOOL[*test.p_arr_int_bool[0]]);

    printf("test.p_arr_uint_str[0] = %c\n", *test.p_arr_uint_str[0]);
    printf("test.p_arr_uint_num[0] = %u\n", *test.p_arr_uint_num[0]);
    printf("test.p_arr_uint_bool[0] = %s\n", BOOL[*test.p_arr_uint_bool[0]]);

    printf("test.p_arr_ll_str[0] = %c\n", (int)*test.p_arr_ll_str[0]);
    printf("test.p_arr_ll_num[0] = %lld\n", *test.p_arr_ll_num[0]);
    printf("test.p_arr_ll_bool[0] = %s\n", BOOL[*test.p_arr_ll_bool[0]]);

    printf("test.p_arr_ull_str[0] = %c\n", (int)*test.p_arr_ull_str[0]);
    printf("test.p_arr_ull_num[0] = %llu\n", *test.p_arr_ull_num[0]);
    printf("test.p_arr_ull_bool[0] = %s\n", BOOL[*test.p_arr_ull_bool[0]]);

    printf("test.p_arr_float_str[0] = %c\n", (char)*test.p_arr_float_str[0]);
    printf("test.p_arr_float_num[0] = %f\n", *test.p_arr_float_num[0]);
    printf("test.p_arr_float_bool[0] = %f\n", *test.p_arr_float_bool[0]);

    printf("test.p_arr_double_str[0] = %c\n", (char)*test.p_arr_double_str[0]);
    printf("test.p_arr_double_num[0] = %f\n", *test.p_arr_double_num[0]);
    printf("test.p_arr_double_bool[0] = %f\n", *test.p_arr_double_bool[0]);

    printf("test.test_st.char_str = %c\n", test.test_st.char_str);
    printf("test.test_st.char_num = %d\n", test.test_st.char_num);
    printf("test.test_st.char_bool = %s\n", BOOL[(uint8_t)test.test_st.char_bool]);

    printf("test.test_st.uchar_str = %c\n", test.test_st.uchar_str);
    printf("test.test_st.uchar_num = %d\n", test.test_st.uchar_num);
    printf("test.test_st.uchar_bool = %s\n", BOOL[test.test_st.uchar_bool]);

    printf("test.test_st.short_str = %s\n", (char *)&test.test_st.short_str);
    printf("test.test_st.short_num = %d\n", test.test_st.short_num);
    printf("test.test_st.short_bool = %s\n", BOOL[test.test_st.short_bool]);

    printf("test.test_st.ushort_str = %s\n", (char *)&test.test_st.ushort_str);
    printf("test.test_st.ushort_num = %d\n", test.test_st.ushort_num);
    printf("test.test_st.ushort_bool = %s\n", BOOL[test.test_st.ushort_bool]);

    printf("test.test_st.int_str = %s\n", (char *)&test.test_st.int_str);
    printf("test.test_st.int_num = %d\n", test.test_st.int_num);
    printf("test.test_st.int_bool = %s\n", BOOL[test.test_st.int_bool]);

    printf("test.test_st.uint_str = %s\n", (char *)&test.test_st.uint_str);
    printf("test.test_st.uint_num = %d\n", test.test_st.uint_num);
    printf("test.test_st.uint_bool = %s\n", BOOL[test.test_st.uint_bool]);

    printf("test.test_st.ll_str = %s\n", (char *)&test.test_st.ll_str);
    printf("test.test_st.ll_num = %lld\n", test.test_st.ll_num);
    printf("test.test_st.ll_bool = %s\n", BOOL[test.test_st.ll_bool]);

    printf("test.test_st.ull_str = %s\n", (char *)&test.test_st.ull_str);
    printf("test.test_st.ull_num = %lld\n", test.test_st.ull_num);
    printf("test.test_st.ull_bool = %s\n", BOOL[test.test_st.ull_bool]);

    printf("test.test_st.float_str = %s\n", (char *)&test.test_st.float_str);
    printf("test.test_st.float_num = %f\n", test.test_st.float_num);
    printf("test.test_st.float_bool = %f\n", test.test_st.float_bool);

    printf("test.test_st.double_str = %s\n", (char *)&test.test_st.double_str);
    printf("test.test_st.double_num = %f\n", test.test_st.double_num);
    printf("test.test_st.double_bool = %f\n", test.test_st.double_bool);

    printf("test.p_test_st->char_str = %c\n", test.p_test_st->char_str);
    printf("test.p_test_st->char_num = %d\n", test.p_test_st->char_num);
    printf("test.p_test_st->char_bool = %s\n", BOOL[(uint8_t)test.p_test_st->char_bool]);

    printf("test.p_test_st->uchar_str = %c\n", test.p_test_st->uchar_str);
    printf("test.p_test_st->uchar_num = %d\n", test.p_test_st->uchar_num);
    printf("test.p_test_st->uchar_bool = %s\n", BOOL[test.p_test_st->uchar_bool]);

    printf("test.p_test_st->short_str = %s\n", (char *)&test.p_test_st->short_str);
    printf("test.p_test_st->short_num = %d\n", test.p_test_st->short_num);
    printf("test.p_test_st->short_bool = %s\n", BOOL[test.p_test_st->short_bool]);

    printf("test.p_test_st->ushort_str = %s\n", (char *)&test.p_test_st->ushort_str);
    printf("test.p_test_st->ushort_num = %d\n", test.p_test_st->ushort_num);
    printf("test.p_test_st->ushort_bool = %s\n", BOOL[test.p_test_st->ushort_bool]);

    printf("test.p_test_st->int_str = %s\n", (char *)&test.p_test_st->int_str);
    printf("test.p_test_st->int_num = %d\n", test.p_test_st->int_num);
    printf("test.p_test_st->int_bool = %s\n", BOOL[test.p_test_st->int_bool]);

    printf("test.p_test_st->uint_str = %s\n", (char *)&test.p_test_st->uint_str);
    printf("test.p_test_st->uint_num = %d\n", test.p_test_st->uint_num);
    printf("test.p_test_st->uint_bool = %s\n", BOOL[test.p_test_st->uint_bool]);

    printf("test.p_test_st->ll_str = %s\n", (char *)&test.p_test_st->ll_str);
    printf("test.p_test_st->ll_num = %lld\n", test.p_test_st->ll_num);
    printf("test.p_test_st->ll_bool = %s\n", BOOL[test.p_test_st->ll_bool]);

    printf("test.p_test_st->ull_str = %s\n", (char *)&test.p_test_st->ull_str);
    printf("test.p_test_st->ull_num = %lld\n", test.p_test_st->ull_num);
    printf("test.p_test_st->ull_bool = %s\n", BOOL[test.p_test_st->ull_bool]);

    printf("test.p_test_st->float_str = %s\n", (char *)&test.p_test_st->float_str);
    printf("test.p_test_st->float_num = %f\n", test.p_test_st->float_num);
    printf("test.p_test_st->float_bool = %f\n", test.p_test_st->float_bool);

    printf("test.p_test_st->double_str = %s\n", (char *)&test.p_test_st->double_str);
    printf("test.p_test_st->double_num = %f\n", test.p_test_st->double_num);
    printf("test.p_test_st->double_bool = %f\n", test.p_test_st->double_bool);

    // struct st arr_test_st[2];
    printf("test.arr_test_st[0].char_str = %c\n", test.arr_test_st[0].uchar_str);
    printf("test.arr_test_st[0].char_num = %d\n", test.arr_test_st[0].char_num);
    printf("test.arr_test_st[0].char_bool = %s\n", BOOL[(uint8_t)test.arr_test_st[0].char_bool]);

    printf("test.arr_test_st[0].uchar_str = %c\n", test.arr_test_st[0].uchar_str);
    printf("test.arr_test_st[0].uchar_num = %d\n", test.arr_test_st[0].uchar_num);
    printf("test.arr_test_st[0].uchar_bool = %s\n", BOOL[test.arr_test_st[0].uchar_bool]);

    printf("test.arr_test_st[0].short_str = %s\n", (char *)&test.arr_test_st[0].short_str);
    printf("test.arr_test_st[0].short_num = %d\n", test.arr_test_st[0].short_num);
    printf("test.arr_test_st[0].short_bool = %s\n", BOOL[test.arr_test_st[0].short_bool]);

    printf("test.arr_test_st[0].ushort_str = %s\n", (char *)&test.arr_test_st[0].ushort_str);
    printf("test.arr_test_st[0].ushort_num = %d\n", test.arr_test_st[0].ushort_num);
    printf("test.arr_test_st[0].ushort_bool = %s\n", BOOL[test.arr_test_st[0].ushort_bool]);

    printf("test.arr_test_st[0].int_str = %s\n", (char *)&test.arr_test_st[0].int_str);
    printf("test.arr_test_st[0].int_num = %d\n", test.arr_test_st[0].int_num);
    printf("test.arr_test_st[0].int_bool = %s\n", BOOL[test.arr_test_st[0].int_bool]);

    printf("test.arr_test_st[0].uint_str = %s\n", (char *)&test.arr_test_st[0].uint_str);
    printf("test.arr_test_st[0].uint_num = %d\n", test.arr_test_st[0].uint_num);
    printf("test.arr_test_st[0].uint_bool = %s\n", BOOL[test.arr_test_st[0].uint_bool]);

    printf("test.arr_test_st[0].ll_str = %s\n", (char *)&test.arr_test_st[0].ll_str);
    printf("test.arr_test_st[0].ll_num = %lld\n", test.arr_test_st[0].ll_num);
    printf("test.arr_test_st[0].ll_bool = %s\n", BOOL[test.arr_test_st[0].ll_bool]);

    printf("test.arr_test_st[0].ull_str = %s\n", (char *)&test.arr_test_st[0].ull_str);
    printf("test.arr_test_st[0].ull_num = %lld\n", test.arr_test_st[0].ull_num);
    printf("test.arr_test_st[0].ull_bool = %s\n", BOOL[test.arr_test_st[0].ull_bool]);

    printf("test.arr_test_st[0].float_str = %s\n", (char *)&test.arr_test_st[0].float_str);
    printf("test.arr_test_st[0].float_num = %f\n", test.arr_test_st[0].float_num);
    printf("test.arr_test_st[0].float_bool = %f\n", test.arr_test_st[0].float_bool);

    printf("test.arr_test_st[0].double_str = %s\n", (char *)&test.arr_test_st[0].double_str);
    printf("test.arr_test_st[0].double_num = %f\n", test.arr_test_st[0].double_num);
    printf("test.arr_test_st[0].double_bool = %f\n", test.arr_test_st[0].double_bool);

    printf("test.arr_test_st[1].char_str = %c\n", test.arr_test_st[1].uchar_str);
    printf("test.arr_test_st[1].char_num = %d\n", test.arr_test_st[1].char_num);
    printf("test.arr_test_st[1].char_bool = %s\n", BOOL[(uint8_t)test.arr_test_st[1].char_bool]);

    printf("test.arr_test_st[1].uchar_str = %c\n", test.arr_test_st[1].uchar_str);
    printf("test.arr_test_st[1].uchar_num = %d\n", test.arr_test_st[1].uchar_num);
    printf("test.arr_test_st[1].uchar_bool = %s\n", BOOL[test.arr_test_st[1].uchar_bool]);

    printf("test.arr_test_st[1].short_str = %s\n", (char *)&test.arr_test_st[1].short_str);
    printf("test.arr_test_st[1].short_num = %d\n", test.arr_test_st[1].short_num);
    printf("test.arr_test_st[1].short_bool = %s\n", BOOL[test.arr_test_st[1].short_bool]);

    printf("test.arr_test_st[1].ushort_str = %s\n", (char *)&test.arr_test_st[1].ushort_str);
    printf("test.arr_test_st[1].ushort_num = %d\n", test.arr_test_st[1].ushort_num);
    printf("test.arr_test_st[1].ushort_bool = %s\n", BOOL[test.arr_test_st[1].ushort_bool]);

    printf("test.arr_test_st[1].int_str = %s\n", (char *)&test.arr_test_st[1].int_str);
    printf("test.arr_test_st[1].int_num = %d\n", test.arr_test_st[1].int_num);
    printf("test.arr_test_st[1].int_bool = %s\n", BOOL[test.arr_test_st[1].int_bool]);

    printf("test.arr_test_st[1].uint_str = %s\n", (char *)&test.arr_test_st[1].uint_str);
    printf("test.arr_test_st[1].uint_num = %d\n", test.arr_test_st[1].uint_num);
    printf("test.arr_test_st[1].uint_bool = %s\n", BOOL[test.arr_test_st[1].uint_bool]);

    printf("test.arr_test_st[1].ll_str = %s\n", (char *)&test.arr_test_st[1].ll_str);
    printf("test.arr_test_st[1].ll_num = %lld\n", test.arr_test_st[1].ll_num);
    printf("test.arr_test_st[1].ll_bool = %s\n", BOOL[test.arr_test_st[1].ll_bool]);

    printf("test.arr_test_st[1].ull_str = %s\n", (char *)&test.arr_test_st[1].ull_str);
    printf("test.arr_test_st[1].ull_num = %lld\n", test.arr_test_st[1].ull_num);
    printf("test.arr_test_st[1].ull_bool = %s\n", BOOL[test.arr_test_st[1].ull_bool]);

    printf("test.arr_test_st[1].float_str = %s\n", (char *)&test.arr_test_st[1].float_str);
    printf("test.arr_test_st[1].float_num = %f\n", test.arr_test_st[1].float_num);
    printf("test.arr_test_st[1].float_bool = %f\n", test.arr_test_st[1].float_bool);

    printf("test.arr_test_st[1].double_str = %s\n", (char *)&test.arr_test_st[1].double_str);
    printf("test.arr_test_st[1].double_num = %f\n", test.arr_test_st[1].double_num);
    printf("test.arr_test_st[1].double_bool = %f\n", test.arr_test_st[1].double_bool);

    // p_arr_test_st
    printf("test.p_arr_test_st[0].char_str = %c\n", test.p_arr_test_st[0]->uchar_str);
    printf("test.p_arr_test_st[0].char_num = %d\n", test.p_arr_test_st[0]->char_num);
    printf("test.p_arr_test_st[0].char_bool = %s\n", BOOL[(uint8_t)test.p_arr_test_st[0]->char_bool]);

    printf("test.p_arr_test_st[0].uchar_str = %c\n", test.p_arr_test_st[0]->uchar_str);
    printf("test.p_arr_test_st[0].uchar_num = %d\n", test.p_arr_test_st[0]->uchar_num);
    printf("test.p_arr_test_st[0].uchar_bool = %s\n", BOOL[test.p_arr_test_st[0]->uchar_bool]);

    printf("test.p_arr_test_st[0].short_str = %s\n", (char *)&test.p_arr_test_st[0]->short_str);
    printf("test.p_arr_test_st[0].short_num = %d\n", test.p_arr_test_st[0]->short_num);
    printf("test.p_arr_test_st[0].short_bool = %s\n", BOOL[test.p_arr_test_st[0]->short_bool]);

    printf("test.p_arr_test_st[0].ushort_str = %s\n", (char *)&test.p_arr_test_st[0]->ushort_str);
    printf("test.p_arr_test_st[0].ushort_num = %d\n", test.p_arr_test_st[0]->ushort_num);
    printf("test.p_arr_test_st[0].ushort_bool = %s\n", BOOL[test.p_arr_test_st[0]->ushort_bool]);

    printf("test.p_arr_test_st[0].int_str = %s\n", (char *)&test.p_arr_test_st[0]->int_str);
    printf("test.p_arr_test_st[0].int_num = %d\n", test.p_arr_test_st[0]->int_num);
    printf("test.p_arr_test_st[0].int_bool = %s\n", BOOL[test.p_arr_test_st[0]->int_bool]);

    printf("test.p_arr_test_st[0].uint_str = %s\n", (char *)&test.p_arr_test_st[0]->uint_str);
    printf("test.p_arr_test_st[0].uint_num = %d\n", test.p_arr_test_st[0]->uint_num);
    printf("test.p_arr_test_st[0].uint_bool = %s\n", BOOL[test.p_arr_test_st[0]->uint_bool]);

    printf("test.p_arr_test_st[0].ll_str = %s\n", (char *)&test.p_arr_test_st[0]->ll_str);
    printf("test.p_arr_test_st[0].ll_num = %lld\n", test.p_arr_test_st[0]->ll_num);
    printf("test.p_arr_test_st[0].ll_bool = %s\n", BOOL[test.p_arr_test_st[0]->ll_bool]);

    printf("test.p_arr_test_st[0].ull_str = %s\n", (char *)&test.p_arr_test_st[0]->ull_str);
    printf("test.p_arr_test_st[0].ull_num = %lld\n", test.p_arr_test_st[0]->ull_num);
    printf("test.p_arr_test_st[0].ull_bool = %s\n", BOOL[test.p_arr_test_st[0]->ull_bool]);

    printf("test.p_arr_test_st[0].float_str = %s\n", (char *)&test.p_arr_test_st[0]->float_str);
    printf("test.p_arr_test_st[0].float_num = %f\n", test.p_arr_test_st[0]->float_num);
    printf("test.p_arr_test_st[0].float_bool = %f\n", test.p_arr_test_st[0]->float_bool);

    printf("test.p_arr_test_st[0].double_str = %s\n", (char *)&test.p_arr_test_st[0]->double_str);
    printf("test.p_arr_test_st[0].double_num = %f\n", test.p_arr_test_st[0]->double_num);
    printf("test.p_arr_test_st[0].double_bool = %f\n", test.p_arr_test_st[0]->double_bool);

    printf("test.p_arr_test_st[1].char_str = %c\n", test.p_arr_test_st[1]->uchar_str);
    printf("test.p_arr_test_st[1].char_num = %d\n", test.p_arr_test_st[1]->char_num);
    printf("test.p_arr_test_st[1].char_bool = %s\n", BOOL[(uint8_t)test.p_arr_test_st[1]->char_bool]);

    printf("test.p_arr_test_st[1].uchar_str = %c\n", test.p_arr_test_st[1]->uchar_str);
    printf("test.p_arr_test_st[1].uchar_num = %d\n", test.p_arr_test_st[1]->uchar_num);
    printf("test.p_arr_test_st[1].uchar_bool = %s\n", BOOL[test.p_arr_test_st[1]->uchar_bool]);

    printf("test.p_arr_test_st[1].short_str = %s\n", (char *)&test.p_arr_test_st[1]->short_str);
    printf("test.p_arr_test_st[1].short_num = %d\n", test.p_arr_test_st[1]->short_num);
    printf("test.p_arr_test_st[1].short_bool = %s\n", BOOL[test.p_arr_test_st[1]->short_bool]);

    printf("test.p_arr_test_st[1].ushort_str = %s\n", (char *)&test.p_arr_test_st[1]->ushort_str);
    printf("test.p_arr_test_st[1].ushort_num = %d\n", test.p_arr_test_st[1]->ushort_num);
    printf("test.p_arr_test_st[1].ushort_bool = %s\n", BOOL[test.p_arr_test_st[1]->ushort_bool]);

    printf("test.p_arr_test_st[1].int_str = %s\n", (char *)&test.p_arr_test_st[1]->int_str);
    printf("test.p_arr_test_st[1].int_num = %d\n", test.p_arr_test_st[1]->int_num);
    printf("test.p_arr_test_st[1].int_bool = %s\n", BOOL[test.p_arr_test_st[1]->int_bool]);

    printf("test.p_arr_test_st[1].uint_str = %s\n", (char *)&test.p_arr_test_st[1]->uint_str);
    printf("test.p_arr_test_st[1].uint_num = %d\n", test.p_arr_test_st[1]->uint_num);
    printf("test.p_arr_test_st[1].uint_bool = %s\n", BOOL[test.p_arr_test_st[1]->uint_bool]);

    printf("test.p_arr_test_st[1].ll_str = %s\n", (char *)&test.p_arr_test_st[1]->ll_str);
    printf("test.p_arr_test_st[1].ll_num = %lld\n", test.p_arr_test_st[1]->ll_num);
    printf("test.p_arr_test_st[1].ll_bool = %s\n", BOOL[test.p_arr_test_st[1]->ll_bool]);

    printf("test.p_arr_test_st[1].ull_str = %s\n", (char *)&test.p_arr_test_st[1]->ull_str);
    printf("test.p_arr_test_st[1].ull_num = %lld\n", test.p_arr_test_st[1]->ull_num);
    printf("test.p_arr_test_st[1].ull_bool = %s\n", BOOL[test.p_arr_test_st[1]->ull_bool]);

    printf("test.p_arr_test_st[1].float_str = %s\n", (char *)&test.p_arr_test_st[1]->float_str);
    printf("test.p_arr_test_st[1].float_num = %f\n", test.p_arr_test_st[1]->float_num);
    printf("test.p_arr_test_st[1].float_bool = %f\n", test.p_arr_test_st[1]->float_bool);

    printf("test.p_arr_test_st[1].double_str = %s\n", (char *)&test.p_arr_test_st[1]->double_str);
    printf("test.p_arr_test_st[1].double_num = %f\n", test.p_arr_test_st[1]->double_num);
    printf("test.p_arr_test_st[1].double_bool = %f\n", test.p_arr_test_st[1]->double_bool);

    printf("test.test_un.arr_char_str = %s\n", test.test_un.arr_char_str);

    if (ret) {
        printf("change have some errors\n");
    } else {
        printf("change ok \n");
    }

    return ret;
}
