/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 10:30:52
 * @LastEditTime : 2022-06-09 15:51:48
 * @LastEditors  : lqm283 lanqianming@hotmail.com
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/main.h
 */
#ifndef __MAIN_H_
#define __MAIN_H_
#include <bits/stdint-uintn.h>

#include "jsonc.h"
#include "stdint.h"

struct st {
    // 基本类型
    // char 类型
    char char_str;
    char char_num;
    char char_bool;
    // unsigned char 类型
    uint8_t uchar_str;
    uint8_t uchar_num;
    uint8_t uchar_bool;
    // short int 类型
    short short_str;
    short short_num;
    short short_bool;
    // unsigned short int 类型
    unsigned short ushort_str;
    unsigned short ushort_num;
    unsigned short ushort_bool;
    // int 类型
    int int_str;
    int int_num;
    int int_bool;
    // unsigned int 类型
    unsigned int uint_str;
    unsigned int uint_num;
    unsigned int uint_bool;
    // long long 类型
    long long ll_str;
    long long ll_num;
    long long ll_bool;
    // unsigned long long 类型
    unsigned long long ull_str;
    unsigned long long ull_num;
    unsigned long long ull_bool;
    // float 类型
    float float_str;
    float float_num;
    float float_bool;
    // double 类型
    double double_str;
    double double_num;
    double double_bool;
    // 指针类型
    // char * 类型
    char *p_char_str;
    char *p_char_num;
    char *p_char_bool;
    // unsigned char * 类型
    uint8_t *p_uchar_str;
    uint8_t *p_uchar_num;
    uint8_t *p_uchar_bool;
    // short int * 类型
    short *p_short_str;
    short *p_short_num;
    short *p_short_bool;
    // unsigned short int * 类型
    unsigned short *p_ushort_str;
    unsigned short *p_ushort_num;
    unsigned short *p_ushort_bool;
    // int * 类型
    int *p_int_str;
    int *p_int_num;
    int *p_int_bool;
    // unsigned int * 类型
    unsigned int *p_uint_str;
    unsigned int *p_uint_num;
    unsigned int *p_uint_bool;
    // long long * 类型
    long long *p_ll_str;
    long long *p_ll_num;
    long long *p_ll_bool;
    // unsigned long long * 类型
    unsigned long long *p_ull_str;
    unsigned long long *p_ull_num;
    unsigned long long *p_ull_bool;
    // float * 类型
    float *p_float_str;
    float *p_float_num;
    float *p_float_bool;
    // double * 类型
    double *p_double_str;
    double *p_double_num;
    double *p_double_bool;
    // 数组
    // char 类型
    char arr_char_str[100];
    char arr_char_num[100];
    char arr_char_bool[100];
    // unsigned char 类型
    uint8_t arr_uchar_str[100];
    uint8_t arr_uchar_num[100];
    uint8_t arr_uchar_bool[100];
    // short int 类型
    short arr_short_str[100];
    short arr_short_num[100];
    short arr_short_bool[100];
    // unsigned short int 类型
    unsigned short arr_ushort_str[100];
    unsigned short arr_ushort_num[100];
    unsigned short arr_ushort_bool[100];
    // int 类型
    int arr_int_str[100];
    int arr_int_num[100];
    int arr_int_bool[100];
    // unsigned int 类型
    unsigned int arr_uint_str[100];
    unsigned int arr_uint_num[100];
    unsigned int arr_uint_bool[100];
    // long long 类型
    long long arr_ll_str[100];
    long long arr_ll_num[100];
    long long arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long arr_ull_str[100];
    unsigned long long arr_ull_num[100];
    unsigned long long arr_ull_bool[100];
    // float 类型
    float arr_float_str[100];
    float arr_float_num[100];
    float arr_float_bool[100];
    // double 类型
    double arr_double_str[100];
    double arr_double_num[100];
    double arr_double_bool[100];
    // 指针数组
    // char 类型
    char *p_arr_char_str[100];
    char *p_arr_char_num[100];
    char *p_arr_char_bool[100];
    // unsigned char 类型
    uint8_t *p_arr_uchar_str[100];
    uint8_t *p_arr_uchar_num[100];
    uint8_t *p_arr_uchar_bool[100];
    // short int 类型
    short *p_arr_short_str[100];
    short *p_arr_short_num[100];
    short *p_arr_short_bool[100];
    // unsigned short int 类型
    unsigned short *p_arr_ushort_str[100];
    unsigned short *p_arr_ushort_num[100];
    unsigned short *p_arr_ushort_bool[100];
    // int 类型
    int *p_arr_int_str[100];
    int *p_arr_int_num[100];
    int *p_arr_int_bool[100];
    // unsigned int 类型
    unsigned int *p_arr_uint_str[100];
    unsigned int *p_arr_uint_num[100];
    unsigned int *p_arr_uint_bool[100];
    // long long 类型
    long long *p_arr_ll_str[100];
    long long *p_arr_ll_num[100];
    long long *p_arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long *p_arr_ull_str[100];
    unsigned long long *p_arr_ull_num[100];
    unsigned long long *p_arr_ull_bool[100];
    // float 类型
    float *p_arr_float_str[100];
    float *p_arr_float_num[100];
    float *p_arr_float_bool[100];
    // double 类型
    double *p_arr_double_str[100];
    double *p_arr_double_num[100];
    double *p_arr_double_bool[100];
};
INIT(st,
     struct st,
     MEM(struct st, Str, char, char_str, NULL),
     MEM(struct st, Num, char, char_num, NULL),
     MEM(struct st, Bool, char, char_bool, NULL),
     MEM(struct st, Str, uint8_t, uchar_str, NULL),
     MEM(struct st, Num, uint8_t, uchar_num, NULL),
     MEM(struct st, Bool, uint8_t, uchar_bool, NULL),
     MEM(struct st, Str, short, short_str, NULL),
     MEM(struct st, Num, short, short_num, NULL),
     MEM(struct st, Bool, short, short_bool, NULL),
     MEM(struct st, Str, unsigned short, ushort_str, NULL),
     MEM(struct st, Num, unsigned short, ushort_num, NULL),
     MEM(struct st, Bool, unsigned short, ushort_bool, NULL),
     MEM(struct st, Str, int, int_str, NULL),
     MEM(struct st, Num, int, int_num, NULL),
     MEM(struct st, Bool, int, int_bool, NULL),
     MEM(struct st, Str, unsigned int, uint_str, NULL),
     MEM(struct st, Num, unsigned int, uint_num, NULL),
     MEM(struct st, Bool, unsigned int, uint_bool, NULL),
     MEM(struct st, Str, long long, ll_str, NULL),
     MEM(struct st, Num, long long, ll_num, NULL),
     MEM(struct st, Bool, long long, ll_bool, NULL),
     MEM(struct st, Str, unsigned long long, ull_str, NULL),
     MEM(struct st, Num, unsigned long long, ull_num, NULL),
     MEM(struct st, Bool, unsigned long long, ull_bool, NULL),
     MEM(struct st, Str, float, float_str, NULL),
     MEM(struct st, Num, float, float_num, NULL),
     MEM(struct st, Bool, float, float_bool, NULL),
     MEM(struct st, Str, double, double_str, NULL),
     MEM(struct st, Num, double, double_num, NULL),
     MEM(struct st, Bool, double, double_bool, NULL),
     // 指针类型
     MEM(struct st, Str, char *, p_char_str, NULL),
     MEM(struct st, Num, char *, p_char_num, NULL),
     MEM(struct st, Bool, char *, p_char_bool, NULL),
     MEM(struct st, Str, uint8_t *, p_uchar_str, NULL),
     MEM(struct st, Num, uint8_t *, p_uchar_num, NULL),
     MEM(struct st, Bool, uint8_t *, p_uchar_bool, NULL),
     MEM(struct st, Str, short *, p_short_str, NULL),
     MEM(struct st, Num, short *, p_short_num, NULL),
     MEM(struct st, Bool, short *, p_short_bool, NULL),
     MEM(struct st, Str, unsigned short *, p_ushort_str, NULL),
     MEM(struct st, Num, unsigned short *, p_ushort_num, NULL),
     MEM(struct st, Bool, unsigned short *, p_ushort_bool, NULL),
     MEM(struct st, Str, int *, p_int_str, NULL),
     MEM(struct st, Num, int *, p_int_num, NULL),
     MEM(struct st, Bool, int *, p_int_bool, NULL),
     MEM(struct st, Str, unsigned int *, p_uint_str, NULL),
     MEM(struct st, Num, unsigned int *, p_uint_num, NULL),
     MEM(struct st, Bool, unsigned int *, p_uint_bool, NULL),
     MEM(struct st, Str, long long *, p_ll_str, NULL),
     MEM(struct st, Num, long long *, p_ll_num, NULL),
     MEM(struct st, Bool, long long *, p_ll_bool, NULL),
     MEM(struct st, Str, unsigned long long *, p_ull_str, NULL),
     MEM(struct st, Num, unsigned long long *, p_ull_num, NULL),
     MEM(struct st, Bool, unsigned long long *, p_ull_bool, NULL),
     MEM(struct st, Str, float *, p_float_str, NULL),
     MEM(struct st, Num, float *, p_float_num, NULL),
     MEM(struct st, Bool, float *, p_float_bool, NULL),
     MEM(struct st, Str, double *, p_double_str, NULL),
     MEM(struct st, Num, double *, p_double_num, NULL),
     MEM(struct st, Bool, double *, p_double_bool, NULL),
     // 数组
     MEM(struct st, Str, char, arr_char_str, NULL),
     MEM(struct st, Num, char, arr_char_num, NULL),
     MEM(struct st, Bool, char, arr_char_bool, NULL),
     MEM(struct st, Str, uint8_t, arr_uchar_str, NULL),
     MEM(struct st, Num, uint8_t, arr_uchar_num, NULL),
     MEM(struct st, Bool, uint8_t, arr_uchar_bool, NULL),
     MEM(struct st, Str, short, arr_short_str, NULL),
     MEM(struct st, Num, short, arr_short_num, NULL),
     MEM(struct st, Bool, short, arr_short_bool, NULL),
     MEM(struct st, Str, unsigned short, arr_ushort_str, NULL),
     MEM(struct st, Num, unsigned short, arr_ushort_num, NULL),
     MEM(struct st, Bool, unsigned short, arr_ushort_bool, NULL),
     MEM(struct st, Str, int, arr_int_str, NULL),
     MEM(struct st, Num, int, arr_int_num, NULL),
     MEM(struct st, Bool, int, arr_int_bool, NULL),
     MEM(struct st, Str, unsigned int, arr_uint_str, NULL),
     MEM(struct st, Num, unsigned int, arr_uint_num, NULL),
     MEM(struct st, Bool, unsigned int, arr_uint_bool, NULL),
     MEM(struct st, Str, long long, arr_ll_str, NULL),
     MEM(struct st, Num, long long, arr_ll_num, NULL),
     MEM(struct st, Bool, long long, arr_ll_bool, NULL),
     MEM(struct st, Str, unsigned long long, arr_ull_str, NULL),
     MEM(struct st, Num, unsigned long long, arr_ull_num, NULL),
     MEM(struct st, Bool, unsigned long long, arr_ull_bool, NULL),
     MEM(struct st, Str, float, arr_float_str, NULL),
     MEM(struct st, Num, float, arr_float_num, NULL),
     MEM(struct st, Bool, float, arr_float_bool, NULL),
     MEM(struct st, Str, double, arr_double_str, NULL),
     MEM(struct st, Num, double, arr_double_num, NULL),
     MEM(struct st, Bool, double, arr_double_bool, NULL),
     // 指针数组
     MEM(struct st, Str, char *, p_arr_char_str, NULL),
     MEM(struct st, Num, char *, p_arr_char_num, NULL),
     MEM(struct st, Bool, char *, p_arr_char_bool, NULL),
     MEM(struct st, Str, uint8_t *, p_arr_uchar_str, NULL),
     MEM(struct st, Num, uint8_t *, p_arr_uchar_num, NULL),
     MEM(struct st, Bool, uint8_t *, p_arr_uchar_bool, NULL),
     MEM(struct st, Str, short *, p_arr_short_str, NULL),
     MEM(struct st, Num, short *, p_arr_short_num, NULL),
     MEM(struct st, Bool, short *, p_arr_short_bool, NULL),
     MEM(struct st, Str, unsigned short *, p_arr_ushort_str, NULL),
     MEM(struct st, Num, unsigned short *, p_arr_ushort_num, NULL),
     MEM(struct st, Bool, unsigned short *, p_arr_ushort_bool, NULL),
     MEM(struct st, Str, int *, p_arr_int_str, NULL),
     MEM(struct st, Num, int *, p_arr_int_num, NULL),
     MEM(struct st, Bool, int *, p_arr_int_bool, NULL),
     MEM(struct st, Str, unsigned int *, p_arr_uint_str, NULL),
     MEM(struct st, Num, unsigned int *, p_arr_uint_num, NULL),
     MEM(struct st, Bool, unsigned int *, p_arr_uint_bool, NULL),
     MEM(struct st, Str, long long *, p_arr_ll_str, NULL),
     MEM(struct st, Num, long long *, p_arr_ll_num, NULL),
     MEM(struct st, Bool, long long *, p_arr_ll_bool, NULL),
     MEM(struct st, Str, unsigned long long *, p_arr_ull_str, NULL),
     MEM(struct st, Num, unsigned long long *, p_arr_ull_num, NULL),
     MEM(struct st, Bool, unsigned long long *, p_arr_ull_bool, NULL),
     MEM(struct st, Str, float *, p_arr_float_str, NULL),
     MEM(struct st, Num, float *, p_arr_float_num, NULL),
     MEM(struct st, Bool, float *, p_arr_float_bool, NULL),
     MEM(struct st, Str, double *, p_arr_double_str, NULL),
     MEM(struct st, Num, double *, p_arr_double_num, NULL),
     MEM(struct st, Bool, double *, p_arr_double_bool, NULL));

struct un {
    // 基本类型
    // char 类型
    char char_str;
    char char_num;
    char char_bool;
    // unsigned char 类型
    uint8_t uchar_str;
    uint8_t uchar_num;
    uint8_t uchar_bool;
    // short int 类型
    short short_str;
    short short_num;
    short short_bool;
    // unsigned short int 类型
    unsigned short ushort_str;
    unsigned short ushort_num;
    unsigned short ushort_bool;
    // int 类型
    int int_str;
    int int_num;
    int int_bool;
    // unsigned int 类型
    unsigned int uint_str;
    unsigned int uint_num;
    unsigned int uint_bool;
    // long long 类型
    long long ll_str;
    long long ll_num;
    long long ll_bool;
    // unsigned long long 类型
    unsigned long long ull_str;
    unsigned long long ull_num;
    unsigned long long ull_bool;
    // float 类型
    float float_str;
    float float_num;
    float float_bool;
    // double 类型
    double double_str;
    double double_num;
    double double_bool;
    // 指针类型
    // char * 类型
    char *p_char_str;
    char *p_char_num;
    char *p_char_bool;
    // unsigned char * 类型
    uint8_t *p_uchar_str;
    uint8_t *p_uchar_num;
    uint8_t *p_uchar_bool;
    // short int * 类型
    short *p_short_str;
    short *p_short_num;
    short *p_short_bool;
    // unsigned short int * 类型
    unsigned short *p_ushort_str;
    unsigned short *p_ushort_num;
    unsigned short *p_ushort_bool;
    // int * 类型
    int *p_int_str;
    int *p_int_num;
    int *p_int_bool;
    // unsigned int * 类型
    unsigned int *p_uint_str;
    unsigned int *p_uint_num;
    unsigned int *p_uint_bool;
    // long long * 类型
    long long *p_ll_str;
    long long *p_ll_num;
    long long *p_ll_bool;
    // unsigned long long * 类型
    unsigned long long *p_ull_str;
    unsigned long long *p_ull_num;
    unsigned long long *p_ull_bool;
    // float * 类型
    float *p_float_str;
    float *p_float_num;
    float *p_float_bool;
    // double * 类型
    double *p_double_str;
    double *p_double_num;
    double *p_double_bool;
    // 数组
    // char 类型
    char arr_char_str[100];
    char arr_char_num[100];
    char arr_char_bool[100];
    // unsigned char 类型
    uint8_t arr_uchar_str[100];
    uint8_t arr_uchar_num[100];
    uint8_t arr_uchar_bool[100];
    // short int 类型
    short arr_short_str[100];
    short arr_short_num[100];
    short arr_short_bool[100];
    // unsigned short int 类型
    unsigned short arr_ushort_str[100];
    unsigned short arr_ushort_num[100];
    unsigned short arr_ushort_bool[100];
    // int 类型
    int arr_int_str[100];
    int arr_int_num[100];
    int arr_int_bool[100];
    // unsigned int 类型
    unsigned int arr_uint_str[100];
    unsigned int arr_uint_num[100];
    unsigned int arr_uint_bool[100];
    // long long 类型
    long long arr_ll_str[100];
    long long arr_ll_num[100];
    long long arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long arr_ull_str[100];
    unsigned long long arr_ull_num[100];
    unsigned long long arr_ull_bool[100];
    // float 类型
    float arr_float_str[100];
    float arr_float_num[100];
    float arr_float_bool[100];
    // double 类型
    double arr_double_str[100];
    double arr_double_num[100];
    double arr_double_bool[100];
    // 指针数组
    // char 类型
    char *p_arr_char_str[100];
    char *p_arr_char_num[100];
    char *p_arr_char_bool[100];
    // unsigned char 类型
    uint8_t *p_arr_uchar_str[100];
    uint8_t *p_arr_uchar_num[100];
    uint8_t *p_arr_uchar_bool[100];
    // short int 类型
    short *p_arr_short_str[100];
    short *p_arr_short_num[100];
    short *p_arr_short_bool[100];
    // unsigned short int 类型
    unsigned short *p_arr_ushort_str[100];
    unsigned short *p_arr_ushort_num[100];
    unsigned short *p_arr_ushort_bool[100];
    // int 类型
    int *p_arr_int_str[100];
    int *p_arr_int_num[100];
    int *p_arr_int_bool[100];
    // unsigned int 类型
    unsigned int *p_arr_uint_str[100];
    unsigned int *p_arr_uint_num[100];
    unsigned int *p_arr_uint_bool[100];
    // long long 类型
    long long *p_arr_ll_str[100];
    long long *p_arr_ll_num[100];
    long long *p_arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long *p_arr_ull_str[100];
    unsigned long long *p_arr_ull_num[100];
    unsigned long long *p_arr_ull_bool[100];
    // float 类型
    float *p_arr_float_str[100];
    float *p_arr_float_num[100];
    float *p_arr_float_bool[100];
    // double 类型
    double *p_arr_double_str[100];
    double *p_arr_double_num[100];
    double *p_arr_double_bool[100];
};
INIT(un,
     struct un,
     MEM(struct un, Str, char, char_str, NULL),
     MEM(struct un, Num, char, char_num, NULL),
     MEM(struct un, Bool, char, char_bool, NULL),
     MEM(struct un, Str, uint8_t, uchar_str, NULL),
     MEM(struct un, Num, uint8_t, uchar_num, NULL),
     MEM(struct un, Bool, uint8_t, uchar_bool, NULL),
     MEM(struct un, Str, short, short_str, NULL),
     MEM(struct un, Num, short, short_num, NULL),
     MEM(struct un, Bool, short, short_bool, NULL),
     MEM(struct un, Str, unsigned short, ushort_str, NULL),
     MEM(struct un, Num, unsigned short, ushort_num, NULL),
     MEM(struct un, Bool, unsigned short, ushort_bool, NULL),
     MEM(struct un, Str, int, int_str, NULL),
     MEM(struct un, Num, int, int_num, NULL),
     MEM(struct un, Bool, int, int_bool, NULL),
     MEM(struct un, Str, unsigned int, uint_str, NULL),
     MEM(struct un, Num, unsigned int, uint_num, NULL),
     MEM(struct un, Bool, unsigned int, uint_bool, NULL),
     MEM(struct un, Str, long long, ll_str, NULL),
     MEM(struct un, Num, long long, ll_num, NULL),
     MEM(struct un, Bool, long long, ll_bool, NULL),
     MEM(struct un, Str, unsigned long long, ull_str, NULL),
     MEM(struct un, Num, unsigned long long, ull_num, NULL),
     MEM(struct un, Bool, unsigned long long, ull_bool, NULL),
     MEM(struct un, Str, float, float_str, NULL),
     MEM(struct un, Num, float, float_num, NULL),
     MEM(struct un, Bool, float, float_bool, NULL),
     MEM(struct un, Str, double, double_str, NULL),
     MEM(struct un, Num, double, double_num, NULL),
     MEM(struct un, Bool, double, double_bool, NULL),
     // 指针类型
     MEM(struct un, Str, char *, p_char_str, NULL),
     MEM(struct un, Num, char *, p_char_num, NULL),
     MEM(struct un, Bool, char *, p_char_bool, NULL),
     MEM(struct un, Str, uint8_t *, p_uchar_str, NULL),
     MEM(struct un, Num, uint8_t *, p_uchar_num, NULL),
     MEM(struct un, Bool, uint8_t *, p_uchar_bool, NULL),
     MEM(struct un, Str, short *, p_short_str, NULL),
     MEM(struct un, Num, short *, p_short_num, NULL),
     MEM(struct un, Bool, short *, p_short_bool, NULL),
     MEM(struct un, Str, unsigned short *, p_ushort_str, NULL),
     MEM(struct un, Num, unsigned short *, p_ushort_num, NULL),
     MEM(struct un, Bool, unsigned short *, p_ushort_bool, NULL),
     MEM(struct un, Str, int *, p_int_str, NULL),
     MEM(struct un, Num, int *, p_int_num, NULL),
     MEM(struct un, Bool, int *, p_int_bool, NULL),
     MEM(struct un, Str, unsigned int *, p_uint_str, NULL),
     MEM(struct un, Num, unsigned int *, p_uint_num, NULL),
     MEM(struct un, Bool, unsigned int *, p_uint_bool, NULL),
     MEM(struct un, Str, long long *, p_ll_str, NULL),
     MEM(struct un, Num, long long *, p_ll_num, NULL),
     MEM(struct un, Bool, long long *, p_ll_bool, NULL),
     MEM(struct un, Str, unsigned long long *, p_ull_str, NULL),
     MEM(struct un, Num, unsigned long long *, p_ull_num, NULL),
     MEM(struct un, Bool, unsigned long long *, p_ull_bool, NULL),
     MEM(struct un, Str, float *, p_float_str, NULL),
     MEM(struct un, Num, float *, p_float_num, NULL),
     MEM(struct un, Bool, float *, p_float_bool, NULL),
     MEM(struct un, Str, double *, p_double_str, NULL),
     MEM(struct un, Num, double *, p_double_num, NULL),
     MEM(struct un, Bool, double *, p_double_bool, NULL),
     // 数组
     MEM(struct un, Str, char, arr_char_str, NULL),
     MEM(struct un, Num, char, arr_char_num, NULL),
     MEM(struct un, Bool, char, arr_char_bool, NULL),
     MEM(struct un, Str, uint8_t, arr_uchar_str, NULL),
     MEM(struct un, Num, uint8_t, arr_uchar_num, NULL),
     MEM(struct un, Bool, uint8_t, arr_uchar_bool, NULL),
     MEM(struct un, Str, short, arr_short_str, NULL),
     MEM(struct un, Num, short, arr_short_num, NULL),
     MEM(struct un, Bool, short, arr_short_bool, NULL),
     MEM(struct un, Str, unsigned short, arr_ushort_str, NULL),
     MEM(struct un, Num, unsigned short, arr_ushort_num, NULL),
     MEM(struct un, Bool, unsigned short, arr_ushort_bool, NULL),
     MEM(struct un, Str, int, arr_int_str, NULL),
     MEM(struct un, Num, int, arr_int_num, NULL),
     MEM(struct un, Bool, int, arr_int_bool, NULL),
     MEM(struct un, Str, unsigned int, arr_uint_str, NULL),
     MEM(struct un, Num, unsigned int, arr_uint_num, NULL),
     MEM(struct un, Bool, unsigned int, arr_uint_bool, NULL),
     MEM(struct un, Str, long long, arr_ll_str, NULL),
     MEM(struct un, Num, long long, arr_ll_num, NULL),
     MEM(struct un, Bool, long long, arr_ll_bool, NULL),
     MEM(struct un, Str, unsigned long long, arr_ull_str, NULL),
     MEM(struct un, Num, unsigned long long, arr_ull_num, NULL),
     MEM(struct un, Bool, unsigned long long, arr_ull_bool, NULL),
     MEM(struct un, Str, float, arr_float_str, NULL),
     MEM(struct un, Num, float, arr_float_num, NULL),
     MEM(struct un, Bool, float, arr_float_bool, NULL),
     MEM(struct un, Str, double, arr_double_str, NULL),
     MEM(struct un, Num, double, arr_double_num, NULL),
     MEM(struct un, Bool, double, arr_double_bool, NULL),
     // 指针数组
     MEM(struct un, Str, char *, p_arr_char_str, NULL),
     MEM(struct un, Num, char *, p_arr_char_num, NULL),
     MEM(struct un, Bool, char *, p_arr_char_bool, NULL),
     MEM(struct un, Str, uint8_t *, p_arr_uchar_str, NULL),
     MEM(struct un, Num, uint8_t *, p_arr_uchar_num, NULL),
     MEM(struct un, Bool, uint8_t *, p_arr_uchar_bool, NULL),
     MEM(struct un, Str, short *, p_arr_short_str, NULL),
     MEM(struct un, Num, short *, p_arr_short_num, NULL),
     MEM(struct un, Bool, short *, p_arr_short_bool, NULL),
     MEM(struct un, Str, unsigned short *, p_arr_ushort_str, NULL),
     MEM(struct un, Num, unsigned short *, p_arr_ushort_num, NULL),
     MEM(struct un, Bool, unsigned short *, p_arr_ushort_bool, NULL),
     MEM(struct un, Str, int *, p_arr_int_str, NULL),
     MEM(struct un, Num, int *, p_arr_int_num, NULL),
     MEM(struct un, Bool, int *, p_arr_int_bool, NULL),
     MEM(struct un, Str, unsigned int *, p_arr_uint_str, NULL),
     MEM(struct un, Num, unsigned int *, p_arr_uint_num, NULL),
     MEM(struct un, Bool, unsigned int *, p_arr_uint_bool, NULL),
     MEM(struct un, Str, long long *, p_arr_ll_str, NULL),
     MEM(struct un, Num, long long *, p_arr_ll_num, NULL),
     MEM(struct un, Bool, long long *, p_arr_ll_bool, NULL),
     MEM(struct un, Str, unsigned long long *, p_arr_ull_str, NULL),
     MEM(struct un, Num, unsigned long long *, p_arr_ull_num, NULL),
     MEM(struct un, Bool, unsigned long long *, p_arr_ull_bool, NULL),
     MEM(struct un, Str, float *, p_arr_float_str, NULL),
     MEM(struct un, Num, float *, p_arr_float_num, NULL),
     MEM(struct un, Bool, float *, p_arr_float_bool, NULL),
     MEM(struct un, Str, double *, p_arr_double_str, NULL),
     MEM(struct un, Num, double *, p_arr_double_num, NULL),
     MEM(struct un, Bool, double *, p_arr_double_bool, NULL));

struct test {
    // 基本类型
    // char 类型
    char char_str;
    char char_num;
    char char_bool;
    // unsigned char 类型
    uint8_t uchar_str;
    uint8_t uchar_num;
    uint8_t uchar_bool;
    // short int 类型
    short short_str;
    short short_num;
    short short_bool;
    // unsigned short int 类型
    unsigned short ushort_str;
    unsigned short ushort_num;
    unsigned short ushort_bool;
    // int 类型
    int int_str;
    int int_num;
    int int_bool;
    // unsigned int 类型
    unsigned int uint_str;
    unsigned int uint_num;
    unsigned int uint_bool;
    // long long 类型
    long long ll_str;
    long long ll_num;
    long long ll_bool;
    // unsigned long long 类型
    unsigned long long ull_str;
    unsigned long long ull_num;
    unsigned long long ull_bool;
    // float 类型
    float float_str;
    float float_num;
    float float_bool;
    // double 类型
    double double_str;
    double double_num;
    double double_bool;
    // 指针类型
    // char * 类型
    char *p_char_str;
    char *p_char_num;
    char *p_char_bool;
    // unsigned char * 类型
    uint8_t *p_uchar_str;
    uint8_t *p_uchar_num;
    uint8_t *p_uchar_bool;
    // short int * 类型
    short *p_short_str;
    short *p_short_num;
    short *p_short_bool;
    // unsigned short int * 类型
    unsigned short *p_ushort_str;
    unsigned short *p_ushort_num;
    unsigned short *p_ushort_bool;
    // int * 类型
    int *p_int_str;
    int *p_int_num;
    int *p_int_bool;
    // unsigned int * 类型
    unsigned int *p_uint_str;
    unsigned int *p_uint_num;
    unsigned int *p_uint_bool;
    // long long * 类型
    long long *p_ll_str;
    long long *p_ll_num;
    long long *p_ll_bool;
    // unsigned long long * 类型
    unsigned long long *p_ull_str;
    unsigned long long *p_ull_num;
    unsigned long long *p_ull_bool;
    // float * 类型
    float *p_float_str;
    float *p_float_num;
    float *p_float_bool;
    // double * 类型
    double *p_double_str;
    double *p_double_num;
    double *p_double_bool;
    // 数组
    // char 类型
    char arr_char_str[100];
    char arr_char_num[100];
    char arr_char_bool[100];
    // unsigned char 类型
    uint8_t arr_uchar_str[100];
    uint8_t arr_uchar_num[100];
    uint8_t arr_uchar_bool[100];
    // short int 类型
    short arr_short_str[100];
    short arr_short_num[100];
    short arr_short_bool[100];
    // unsigned short int 类型
    unsigned short arr_ushort_str[100];
    unsigned short arr_ushort_num[100];
    unsigned short arr_ushort_bool[100];
    // int 类型
    int arr_int_str[100];
    int arr_int_num[100];
    int arr_int_bool[100];
    // unsigned int 类型
    unsigned int arr_uint_str[100];
    unsigned int arr_uint_num[100];
    unsigned int arr_uint_bool[100];
    // long long 类型
    long long arr_ll_str[100];
    long long arr_ll_num[100];
    long long arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long arr_ull_str[100];
    unsigned long long arr_ull_num[100];
    unsigned long long arr_ull_bool[100];
    // float 类型
    float arr_float_str[100];
    float arr_float_num[100];
    float arr_float_bool[100];
    // double 类型
    double arr_double_str[100];
    double arr_double_num[100];
    double arr_double_bool[100];
    // 指针数组
    // char 类型
    char *p_arr_char_str[100];
    char *p_arr_char_num[100];
    char *p_arr_char_bool[100];
    // unsigned char 类型
    uint8_t *p_arr_uchar_str[100];
    uint8_t *p_arr_uchar_num[100];
    uint8_t *p_arr_uchar_bool[100];
    // short int 类型
    short *p_arr_short_str[100];
    short *p_arr_short_num[100];
    short *p_arr_short_bool[100];
    // unsigned short int 类型
    unsigned short *p_arr_ushort_str[100];
    unsigned short *p_arr_ushort_num[100];
    unsigned short *p_arr_ushort_bool[100];
    // int 类型
    int *p_arr_int_str[100];
    int *p_arr_int_num[100];
    int *p_arr_int_bool[100];
    // unsigned int 类型
    unsigned int *p_arr_uint_str[100];
    unsigned int *p_arr_uint_num[100];
    unsigned int *p_arr_uint_bool[100];
    // long long 类型
    long long *p_arr_ll_str[100];
    long long *p_arr_ll_num[100];
    long long *p_arr_ll_bool[100];
    // unsigned long long 类型
    unsigned long long *p_arr_ull_str[100];
    unsigned long long *p_arr_ull_num[100];
    unsigned long long *p_arr_ull_bool[100];
    // float 类型
    float *p_arr_float_str[100];
    float *p_arr_float_num[100];
    float *p_arr_float_bool[100];
    // double 类型
    double *p_arr_double_str[100];
    double *p_arr_double_num[100];
    double *p_arr_double_bool[100];

    // 结构体类型
    struct st test_st;

    // 结构体指针类型
    struct st *p_test_st;

    // 结构体数组类型
    struct st arr_test_st[2];

    // 结构体指针数组类型
    struct st *p_arr_test_st[2];

    // 联合体类型
    struct un test_un;

    // 联合体指针类型
    struct un *p_test_un;

    // 联合体数组类型
    struct un arr_test_un[2];

    // 联合体指针数组类型
    struct un *p_arr_test_un[2];
};
INIT(test,
     struct test,
     MEM(struct test, Str, char, char_str, NULL),
     MEM(struct test, Num, char, char_num, NULL),
     MEM(struct test, Bool, char, char_bool, NULL),
     MEM(struct test, Str, uint8_t, uchar_str, NULL),
     MEM(struct test, Num, uint8_t, uchar_num, NULL),
     MEM(struct test, Bool, uint8_t, uchar_bool, NULL),
     MEM(struct test, Str, short, short_str, NULL),
     MEM(struct test, Num, short, short_num, NULL),
     MEM(struct test, Bool, short, short_bool, NULL),
     MEM(struct test, Str, unsigned short, ushort_str, NULL),
     MEM(struct test, Num, unsigned short, ushort_num, NULL),
     MEM(struct test, Bool, unsigned short, ushort_bool, NULL),
     MEM(struct test, Str, int, int_str, NULL),
     MEM(struct test, Num, int, int_num, NULL),
     MEM(struct test, Bool, int, int_bool, NULL),
     MEM(struct test, Str, unsigned int, uint_str, NULL),
     MEM(struct test, Num, unsigned int, uint_num, NULL),
     MEM(struct test, Bool, unsigned int, uint_bool, NULL),
     MEM(struct test, Str, long long, ll_str, NULL),
     MEM(struct test, Num, long long, ll_num, NULL),
     MEM(struct test, Bool, long long, ll_bool, NULL),
     MEM(struct test, Str, unsigned long long, ull_str, NULL),
     MEM(struct test, Num, unsigned long long, ull_num, NULL),
     MEM(struct test, Bool, unsigned long long, ull_bool, NULL),
     MEM(struct test, Str, float, float_str, NULL),
     MEM(struct test, Num, float, float_num, NULL),
     MEM(struct test, Bool, float, float_bool, NULL),
     MEM(struct test, Str, double, double_str, NULL),
     MEM(struct test, Num, double, double_num, NULL),
     MEM(struct test, Bool, double, double_bool, NULL),
     // 指针类型
     MEM(struct test, Str, char *, p_char_str, NULL),
     MEM(struct test, Num, char *, p_char_num, NULL),
     MEM(struct test, Bool, char *, p_char_bool, NULL),
     MEM(struct test, Str, uint8_t *, p_uchar_str, NULL),
     MEM(struct test, Num, uint8_t *, p_uchar_num, NULL),
     MEM(struct test, Bool, uint8_t *, p_uchar_bool, NULL),
     MEM(struct test, Str, short *, p_short_str, NULL),
     MEM(struct test, Num, short *, p_short_num, NULL),
     MEM(struct test, Bool, short *, p_short_bool, NULL),
     MEM(struct test, Str, unsigned short *, p_ushort_str, NULL),
     MEM(struct test, Num, unsigned short *, p_ushort_num, NULL),
     MEM(struct test, Bool, unsigned short *, p_ushort_bool, NULL),
     MEM(struct test, Str, int *, p_int_str, NULL),
     MEM(struct test, Num, int *, p_int_num, NULL),
     MEM(struct test, Bool, int *, p_int_bool, NULL),
     MEM(struct test, Str, unsigned int *, p_uint_str, NULL),
     MEM(struct test, Num, unsigned int *, p_uint_num, NULL),
     MEM(struct test, Bool, unsigned int *, p_uint_bool, NULL),
     MEM(struct test, Str, long long *, p_ll_str, NULL),
     MEM(struct test, Num, long long *, p_ll_num, NULL),
     MEM(struct test, Bool, long long *, p_ll_bool, NULL),
     MEM(struct test, Str, unsigned long long *, p_ull_str, NULL),
     MEM(struct test, Num, unsigned long long *, p_ull_num, NULL),
     MEM(struct test, Bool, unsigned long long *, p_ull_bool, NULL),
     MEM(struct test, Str, float *, p_float_str, NULL),
     MEM(struct test, Num, float *, p_float_num, NULL),
     MEM(struct test, Bool, float *, p_float_bool, NULL),
     MEM(struct test, Str, double *, p_double_str, NULL),
     MEM(struct test, Num, double *, p_double_num, NULL),
     MEM(struct test, Bool, double *, p_double_bool, NULL),
     // 数组
     MEM(struct test, Str, char, arr_char_str, NULL),
     MEM(struct test, Num, char, arr_char_num, NULL),
     MEM(struct test, Bool, char, arr_char_bool, NULL),
     MEM(struct test, Str, uint8_t, arr_uchar_str, NULL),
     MEM(struct test, Num, uint8_t, arr_uchar_num, NULL),
     MEM(struct test, Bool, uint8_t, arr_uchar_bool, NULL),
     MEM(struct test, Str, short, arr_short_str, NULL),
     MEM(struct test, Num, short, arr_short_num, NULL),
     MEM(struct test, Bool, short, arr_short_bool, NULL),
     MEM(struct test, Str, unsigned short, arr_ushort_str, NULL),
     MEM(struct test, Num, unsigned short, arr_ushort_num, NULL),
     MEM(struct test, Bool, unsigned short, arr_ushort_bool, NULL),
     MEM(struct test, Str, int, arr_int_str, NULL),
     MEM(struct test, Num, int, arr_int_num, NULL),
     MEM(struct test, Bool, int, arr_int_bool, NULL),
     MEM(struct test, Str, unsigned int, arr_uint_str, NULL),
     MEM(struct test, Num, unsigned int, arr_uint_num, NULL),
     MEM(struct test, Bool, unsigned int, arr_uint_bool, NULL),
     MEM(struct test, Str, long long, arr_ll_str, NULL),
     MEM(struct test, Num, long long, arr_ll_num, NULL),
     MEM(struct test, Bool, long long, arr_ll_bool, NULL),
     MEM(struct test, Str, unsigned long long, arr_ull_str, NULL),
     MEM(struct test, Num, unsigned long long, arr_ull_num, NULL),
     MEM(struct test, Bool, unsigned long long, arr_ull_bool, NULL),
     MEM(struct test, Str, float, arr_float_str, NULL),
     MEM(struct test, Num, float, arr_float_num, NULL),
     MEM(struct test, Bool, float, arr_float_bool, NULL),
     MEM(struct test, Str, double, arr_double_str, NULL),
     MEM(struct test, Num, double, arr_double_num, NULL),
     MEM(struct test, Bool, double, arr_double_bool, NULL),
     // 指针数组
     MEM(struct test, Str, char *, p_arr_char_str, NULL),
     MEM(struct test, Num, char *, p_arr_char_num, NULL),
     MEM(struct test, Bool, char *, p_arr_char_bool, NULL),
     MEM(struct test, Str, uint8_t *, p_arr_uchar_str, NULL),
     MEM(struct test, Num, uint8_t *, p_arr_uchar_num, NULL),
     MEM(struct test, Bool, uint8_t *, p_arr_uchar_bool, NULL),
     MEM(struct test, Str, short *, p_arr_short_str, NULL),
     MEM(struct test, Num, short *, p_arr_short_num, NULL),
     MEM(struct test, Bool, short *, p_arr_short_bool, NULL),
     MEM(struct test, Str, unsigned short *, p_arr_ushort_str, NULL),
     MEM(struct test, Num, unsigned short *, p_arr_ushort_num, NULL),
     MEM(struct test, Bool, unsigned short *, p_arr_ushort_bool, NULL),
     MEM(struct test, Str, int *, p_arr_int_str, NULL),
     MEM(struct test, Num, int *, p_arr_int_num, NULL),
     MEM(struct test, Bool, int *, p_arr_int_bool, NULL),
     MEM(struct test, Str, unsigned int *, p_arr_uint_str, NULL),
     MEM(struct test, Num, unsigned int *, p_arr_uint_num, NULL),
     MEM(struct test, Bool, unsigned int *, p_arr_uint_bool, NULL),
     MEM(struct test, Str, long long *, p_arr_ll_str, NULL),
     MEM(struct test, Num, long long *, p_arr_ll_num, NULL),
     MEM(struct test, Bool, long long *, p_arr_ll_bool, NULL),
     MEM(struct test, Str, unsigned long long *, p_arr_ull_str, NULL),
     MEM(struct test, Num, unsigned long long *, p_arr_ull_num, NULL),
     MEM(struct test, Bool, unsigned long long *, p_arr_ull_bool, NULL),
     MEM(struct test, Str, float *, p_arr_float_str, NULL),
     MEM(struct test, Num, float *, p_arr_float_num, NULL),
     MEM(struct test, Bool, float *, p_arr_float_bool, NULL),
     MEM(struct test, Str, double *, p_arr_double_str, NULL),
     MEM(struct test, Num, double *, p_arr_double_num, NULL),
     MEM(struct test, Bool, double *, p_arr_double_bool, NULL),
     MEM(struct test, Bool, struct st, test_st, st),
     MEM(struct test, Str, struct st *, p_test_st, st),
     MEM(struct test, Num, struct st, arr_test_st, st),
     MEM(struct test, Bool, struct st *, p_arr_test_st, st),
     MEM(struct test, Bool, struct un, test_un, un),
     MEM(struct test, Str, struct un *, p_test_un, un),
     MEM(struct test, Num, struct un, arr_test_un, un),
     MEM(struct test, Bool, struct un *, p_arr_test_un, un));

struct test1 {
    char char_num_base;
    char char_bool_base;
    uint8_t uchar_num_base;
    uint8_t uchar_bool_base;
    short short_num_base;
    short short_bool_base;
    uint16_t ushort_num_base;
    uint16_t ushort_bool_base;
    int int_num_base;
    int int_bool_base;
    uint32_t uint_num_base;
    uint32_t uint_bool_base;
    long long ll_num_base;
    long long ll_bool_base;
    uint64_t ull_num_base;
    uint64_t ull_bool_base;
    float float_num_base;
    float float_bool_base;
    double double_num_base;
    double double_bool_base;
    //  数组
    char char_str_base_arr[20];
    char char_num_base_arr[2];
    char char_bool_base_arr[2];
    uint8_t uchar_str_base_arr[20];
    uint8_t uchar_num_base_arr[2];
    uint8_t uchar_bool_base_arr[2];
    short short_num_base_arr[2];
    short short_bool_base_arr[2];
    uint16_t ushort_num_base_arr[2];
    uint16_t ushort_bool_base_arr[2];
    int int_num_base_arr[2];
    int int_bool_base_arr[2];
    uint32_t uint_num_base_arr[2];
    uint32_t uint_bool_base_arr[2];
    long long ll_num_base_arr[2];
    long long ll_bool_base_arr[2];
    uint64_t ull_num_base_arr[2];
    uint64_t ull_bool_base_arr[2];
    float float_num_base_arr[2];
    float float_bool_base_arr[2];
    double double_num_base_arr[2];
    double double_bool_base_arr[2];
    //指针
    char *p_char_str_base;
    char *p_char_num_base;
    char *p_char_bool_base;
    uint8_t *p_uchar_str_base;
    uint8_t *p_uchar_num_base;
    uint8_t *p_uchar_bool_base;
    short *p_short_num_base;
    short *p_short_bool_base;
    uint16_t *p_ushort_num_base;
    uint16_t *p_ushort_bool_base;
    int *p_int_num_base;
    int *p_int_bool_base;
    uint32_t *p_uint_num_base;
    uint32_t *p_uint_bool_base;
    long long *p_ll_num_base;
    long long *p_ll_bool_base;
    uint64_t *p_ull_num_base;
    uint64_t *p_ull_bool_base;
    float *p_float_num_base;
    float *p_float_bool_base;
    double *p_double_num_base;
    double *p_double_bool_base;
    // 指针数组
    char *p_char_str_base_arr[2];
    char *p_char_num_base_arr[2];
    char *p_char_bool_base_arr[2];
    uint8_t *p_uchar_str_base_arr[2];
    uint8_t *p_uchar_num_base_arr[2];
    uint8_t *p_uchar_bool_base_arr[2];
    short *p_short_num_base_arr[2];
    short *p_short_bool_base_arr[2];
    uint16_t *p_ushort_num_base_arr[2];
    uint16_t *p_ushort_bool_base_arr[2];
    int *p_int_num_base_arr[2];
    int *p_int_bool_base_arr[2];
    uint32_t *p_uint_num_base_arr[2];
    uint32_t *p_uint_bool_base_arr[2];
    long long *p_ll_num_base_arr[2];
    long long *p_ll_bool_base_arr[2];
    uint64_t *p_ull_num_base_arr[2];
    uint64_t *p_ull_bool_base_arr[2];
    float *p_float_num_base_arr[2];
    float *p_float_bool_base_arr[2];
    double *p_double_num_base_arr[2];
    double *p_double_bool_base_arr[2];
};
INIT(test1,
     struct test1,
     MEM(struct test1, Num, char, char_num_base, NULL),
     MEM(struct test1, Bool, char, char_bool_base, NULL),
     MEM(struct test1, Num, uint8_t, uchar_num_base, NULL),
     MEM(struct test1, Bool, uint8_t, uchar_bool_base, NULL),
     MEM(struct test1, Num, short, short_num_base, NULL),
     MEM(struct test1, Bool, short, short_bool_base, NULL),
     MEM(struct test1, Num, uint16_t, ushort_num_base, NULL),
     MEM(struct test1, Bool, uint16_t, ushort_bool_base, NULL),
     MEM(struct test1, Num, int, int_num_base, NULL),
     MEM(struct test1, Bool, int, int_bool_base, NULL),
     MEM(struct test1, Num, uint32_t, uint_num_base, NULL),
     MEM(struct test1, Bool, uint32_t, uint_bool_base, NULL),
     MEM(struct test1, Num, long long, ll_num_base, NULL),
     MEM(struct test1, Bool, long long, ll_bool_base, NULL),
     MEM(struct test1, Num, uint64_t, ull_num_base, NULL),
     MEM(struct test1, Bool, uint64_t, ull_bool_base, NULL),
     MEM(struct test1, Num, float, float_num_base, NULL),
     MEM(struct test1, Bool, float, float_bool_base, NULL),
     MEM(struct test1, Num, double, double_num_base, NULL),
     MEM(struct test1, Bool, double, double_bool_base, NULL),
     //数组
     MEM(struct test1, Str, char, char_str_base_arr, NULL),
     MEM(struct test1, Num, char, char_num_base_arr, NULL),
     MEM(struct test1, Bool, char, char_bool_base_arr, NULL),
     MEM(struct test1, Str, uint8_t, uchar_str_base_arr, NULL),
     MEM(struct test1, Num, uint8_t, uchar_num_base_arr, NULL),
     MEM(struct test1, Bool, uint8_t, uchar_bool_base_arr, NULL),
     MEM(struct test1, Num, short, short_num_base_arr, NULL),
     MEM(struct test1, Bool, short, short_bool_base_arr, NULL),
     MEM(struct test1, Num, uint16_t, ushort_num_base_arr, NULL),
     MEM(struct test1, Bool, uint16_t, ushort_bool_base_arr, NULL),
     MEM(struct test1, Num, int, int_num_base_arr, NULL),
     MEM(struct test1, Bool, int, int_bool_base_arr, NULL),
     MEM(struct test1, Num, uint32_t, uint_num_base_arr, NULL),
     MEM(struct test1, Bool, uint32_t, uint_bool_base_arr, NULL),
     MEM(struct test1, Num, long long, ll_num_base_arr, NULL),
     MEM(struct test1, Bool, long long, ll_bool_base_arr, NULL),
     MEM(struct test1, Num, uint64_t, ull_num_base_arr, NULL),
     MEM(struct test1, Bool, uint64_t, ull_bool_base_arr, NULL),
     MEM(struct test1, Num, float, float_num_base_arr, NULL),
     MEM(struct test1, Bool, float, float_bool_base_arr, NULL),
     MEM(struct test1, Num, double, double_num_base_arr, NULL),
     MEM(struct test1, Bool, double, double_bool_base_arr, NULL),
     // 指针
     MEM(struct test1, Str, char *, p_char_str_base, NULL),
     MEM(struct test1, Num, char *, p_char_num_base, NULL),
     MEM(struct test1, Bool, char *, p_char_bool_base, NULL),
     MEM(struct test1, Str, uint8_t *, p_uchar_str_base, NULL),
     MEM(struct test1, Num, uint8_t *, p_uchar_num_base, NULL),
     MEM(struct test1, Bool, uint8_t *, p_uchar_bool_base, NULL),
     MEM(struct test1, Num, short *, p_short_num_base, NULL),
     MEM(struct test1, Bool, short *, p_short_bool_base, NULL),
     MEM(struct test1, Num, uint16_t *, p_ushort_num_base, NULL),
     MEM(struct test1, Bool, uint16_t *, p_ushort_bool_base, NULL),
     MEM(struct test1, Num, int *, p_int_num_base, NULL),
     MEM(struct test1, Bool, int *, p_int_bool_base, NULL),
     MEM(struct test1, Num, uint32_t *, p_uint_num_base, NULL),
     MEM(struct test1, Bool, uint32_t *, p_uint_bool_base, NULL),
     MEM(struct test1, Num, long long *, p_ll_num_base, NULL),
     MEM(struct test1, Bool, long long *, p_ll_bool_base, NULL),
     MEM(struct test1, Num, uint64_t *, p_ull_num_base, NULL),
     MEM(struct test1, Bool, uint64_t *, p_ull_bool_base, NULL),
     MEM(struct test1, Num, float *, p_float_num_base, NULL),
     MEM(struct test1, Bool, float *, p_float_bool_base, NULL),
     MEM(struct test1, Num, double *, p_double_num_base, NULL),
     MEM(struct test1, Bool, double *, p_double_bool_base, NULL),
     // 指针数组
     MEM(struct test1, Str, char *, p_char_str_base_arr, NULL),
     MEM(struct test1, Num, char *, p_char_num_base_arr, NULL),
     MEM(struct test1, Bool, char *, p_char_bool_base_arr, NULL),
     MEM(struct test1, Str, uint8_t *, p_uchar_str_base_arr, NULL),
     MEM(struct test1, Num, uint8_t *, p_uchar_num_base_arr, NULL),
     MEM(struct test1, Bool, uint8_t *, p_uchar_bool_base_arr, NULL),
     MEM(struct test1, Num, short *, p_short_num_base_arr, NULL),
     MEM(struct test1, Bool, short *, p_short_bool_base_arr, NULL),
     MEM(struct test1, Num, uint16_t *, p_ushort_num_base_arr, NULL),
     MEM(struct test1, Bool, uint16_t *, p_ushort_bool_base_arr, NULL),
     MEM(struct test1, Num, int *, p_int_num_base_arr, NULL),
     MEM(struct test1, Bool, int *, p_int_bool_base_arr, NULL),
     MEM(struct test1, Num, uint32_t *, p_uint_num_base_arr, NULL),
     MEM(struct test1, Bool, uint32_t *, p_uint_bool_base_arr, NULL),
     MEM(struct test1, Num, long long *, p_ll_num_base_arr, NULL),
     MEM(struct test1, Bool, long long *, p_ll_bool_base_arr, NULL),
     MEM(struct test1, Num, uint64_t *, p_ull_num_base_arr, NULL),
     MEM(struct test1, Bool, uint64_t *, p_ull_bool_base_arr, NULL),
     MEM(struct test1, Num, float *, p_float_num_base_arr, NULL),
     MEM(struct test1, Bool, float *, p_float_bool_base_arr, NULL),
     MEM(struct test1, Num, double *, p_double_num_base_arr, NULL),
     MEM(struct test1, Bool, double *, p_double_bool_base_arr, NULL));

typedef struct {
    //常规变量
    struct test1 normal_val;
    //数组
    struct test1 arr_val[2];
    //指针
    struct test1 *ptr_val;
    //指针数组
    struct test1 *ptr_arr_val[2];
} test2;

INIT(test2,
     test2,
     MEM(test2, Num, struct test1, normal_val, test1),
     MEM(test2, Num, struct test1, arr_val, test1),
     MEM(test2, Num, struct test1 *, ptr_val, test1),
     MEM(test2, Num, struct test1 *, ptr_arr_val, test1));

#endif
