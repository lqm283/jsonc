/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:59
 * @LastEditTime : 2022-06-09 15:50:39
 * @LastEditors  : lqm283 lanqianming@hotmail.com
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/struct_to_json_test.c
 */

#include <stdio.h>
#include <sys/types.h>

#include "jsonc.h"
#include "main.h"

extern void* jsonc_struct_to_json(char* buf, void* st, const struct type* type);
// enum json_bool { False, True };

char p_char_str_base[100] = "char_str_base";
char p_char_num_base = -50;
char p_char_bool_base = False;
uint8_t p_uchar_str_base[100] = "p_uchar_str_base";
uint8_t p_uchar_num_base = 255;
uint8_t p_uchar_bool_base = True;
short p_short_num_base = -30;
short p_short_bool_base = True;
uint16_t p_ushort_num_base = 65535;
uint16_t p_ushort_bool_base = False;
int p_int_num_base = -25185;
int p_int_bool_base = True;
uint32_t p_uint_num_base = 123456789;
uint32_t p_uint_bool_base = False;
long long p_ll_num_base = -85124;
long long p_ll_bool_base = True;
uint64_t p_ull_num_base = 985214755555;
uint64_t p_ull_bool_base = True;
float p_float_num_base = 123.234f;
float p_float_bool_base = False;
double p_double_num_base = -5921.5214;
double p_double_bool_base = False;

char p_char_str_base_arr[2][100] = {"p_char_str_base_arr[0]", "p_char_str_base_arr[1]"};
char p_char_num_base_arr[2] = {-50, -51};
char p_char_bool_base_arr[2] = {True, False};
uint8_t p_uchar_str_base_arr[2][100] = {"p_uchar_str_base_arr[0]", "p_uchar_str_base_arr[1]"};
uint8_t p_uchar_num_base_arr[2] = {255, 254};
uint8_t p_uchar_bool_base_arr[2] = {True, False};
short p_short_num_base_arr[2] = {-30, 30};
short p_short_bool_base_arr[2] = {True, False};
uint16_t p_ushort_num_base_arr[2] = {65535, 65534};
uint16_t p_ushort_bool_base_arr[2] = {False, True};
int p_int_num_base_arr[2] = {-25185, 2581};
int p_int_bool_base_arr[2] = {True, False};
uint32_t p_uint_num_base_arr[2] = {123456789, 987654321};
uint32_t p_uint_bool_base_arr[2] = {False, True};
long long p_ll_num_base_arr[2] = {-85124, 15845};
long long p_ll_bool_base_arr[2] = {True, False};
uint64_t p_ull_num_base_arr[2] = {985214755555, 1365214};
uint64_t p_ull_bool_base_arr[2] = {True, False};
float p_float_num_base_arr[2] = {123.234f, 432.211F};
float p_float_bool_base_arr[2] = {False, False};
double p_double_num_base_arr[2] = {-5921.5214, 18413};
double p_double_bool_base_arr[2] = {False, False};

int struct_to_json_test(void) {
    char buf[81920];
    char* json;
    struct test1 struct_to_json_base_test = {
        //
        .char_num_base = -50,
        .char_bool_base = False,
        .uchar_num_base = 255,
        .uchar_bool_base = True,
        .short_num_base = -30,
        .short_bool_base = True,
        .ushort_num_base = 65535,
        .ushort_bool_base = False,
        .int_num_base = -25185,
        .int_bool_base = True,
        .uint_num_base = 123456789,
        .uint_bool_base = False,
        .ll_num_base = -85124,
        .ll_bool_base = True,
        .ull_num_base = 985214755555,
        .ull_bool_base = True,
        .float_num_base = 123.234f,
        .float_bool_base = False,
        .double_num_base = -654.32152,
        .double_bool_base = False,
        //数组
        .char_str_base_arr = "My love",
        .char_num_base_arr = {2, 3},
        .char_bool_base_arr = {True, False},
        .uchar_str_base_arr = "Your love",
        .uchar_num_base_arr = {254, 255},
        .uchar_bool_base_arr = {False, False},
        .short_num_base_arr = {-200, 5246},
        .short_bool_base_arr = {True, True},
        .ushort_num_base_arr = {65535, 6554},
        .ushort_bool_base_arr = {False, False},
        .int_num_base_arr = {'A', 'R'},
        .int_bool_base_arr = {True, True},
        .uint_num_base_arr = {952154855, 1452589},
        .uint_bool_base_arr = {True, True},
        .ll_num_base_arr = {154978515122157, 897},
        .ll_bool_base_arr = {True, False},
        .ull_num_base_arr = {5487646487845451054, 168765487684541},
        .ull_bool_base_arr = {True, True},
        .float_num_base_arr = {-123.03f, 562.2355f},
        .float_bool_base_arr = {False, True},
        .double_num_base_arr = {3.14159265358, 3.71083},
        .double_bool_base_arr = {False, True},
        //指针
        .p_char_str_base = p_char_str_base,
        .p_char_num_base = &p_char_num_base,
        .p_char_bool_base = &p_char_bool_base,
        .p_uchar_str_base = p_uchar_str_base,
        .p_uchar_num_base = &p_uchar_num_base,
        .p_uchar_bool_base = &p_uchar_bool_base,
        .p_short_num_base = &p_short_num_base,
        .p_short_bool_base = &p_short_bool_base,
        .p_ushort_num_base = &p_ushort_num_base,
        .p_ushort_bool_base = &p_ushort_bool_base,
        .p_int_num_base = &p_int_num_base,
        .p_int_bool_base = &p_int_bool_base,
        .p_uint_num_base = &p_uint_num_base,
        .p_uint_bool_base = &p_uint_bool_base,
        .p_ll_num_base = &p_ll_num_base,
        .p_ll_bool_base = &p_ll_bool_base,
        .p_ull_num_base = &p_ull_num_base,
        .p_ull_bool_base = &p_ull_bool_base,
        .p_float_num_base = &p_float_num_base,
        .p_float_bool_base = &p_float_bool_base,
        .p_double_num_base = &p_double_num_base,
        .p_double_bool_base = &p_double_bool_base,
        //指针数组
        .p_char_str_base_arr = {p_char_str_base_arr[0], p_char_str_base_arr[1]},
        .p_char_num_base_arr = {&p_char_num_base_arr[0], &p_char_num_base_arr[1]},
        .p_char_bool_base_arr = {&p_char_bool_base_arr[0], &p_char_bool_base_arr[1]},
        .p_uchar_str_base_arr = {p_uchar_str_base_arr[0], p_uchar_str_base_arr[1]},
        .p_uchar_num_base_arr = {&p_uchar_num_base_arr[0], &p_uchar_num_base_arr[1]},
        .p_uchar_bool_base_arr = {&p_uchar_bool_base_arr[0], &p_uchar_bool_base_arr[1]},
        .p_short_num_base_arr = {&p_short_num_base_arr[0], &p_short_num_base_arr[1]},
        .p_short_bool_base_arr = {&p_short_bool_base_arr[0], &p_short_bool_base_arr[1]},
        .p_ushort_num_base_arr = {&p_ushort_num_base_arr[0], &p_ushort_num_base_arr[1]},
        .p_ushort_bool_base_arr = {&p_ushort_bool_base_arr[0], &p_ushort_bool_base_arr[1]},
        .p_int_num_base_arr = {&p_int_num_base_arr[0], &p_int_num_base_arr[1]},
        .p_int_bool_base_arr = {&p_int_bool_base_arr[0], &p_int_bool_base_arr[1]},
        .p_uint_num_base_arr = {&p_uint_num_base_arr[0], &p_uint_num_base_arr[1]},
        .p_uint_bool_base_arr = {&p_uint_bool_base_arr[0], &p_uint_bool_base_arr[1]},
        .p_ll_num_base_arr = {&p_ll_num_base_arr[0], &p_ll_num_base_arr[1]},
        .p_ll_bool_base_arr = {&p_ll_bool_base_arr[0], &p_ll_bool_base_arr[1]},
        .p_ull_num_base_arr = {&p_ull_num_base_arr[0], &p_ull_num_base_arr[1]},
        .p_ull_bool_base_arr = {&p_ull_bool_base_arr[0], &p_ull_bool_base_arr[1]},
        .p_float_num_base_arr = {&p_float_num_base_arr[0], &p_float_num_base_arr[1]},
        .p_float_bool_base_arr = {&p_float_bool_base_arr[0], &p_float_bool_base_arr[1]},
        .p_double_num_base_arr = {&p_double_num_base_arr[0], &p_double_num_base_arr[1]},
        .p_double_bool_base_arr = {&p_double_bool_base_arr[0], &p_double_bool_base_arr[1]},
    };
    json = jsonc_serialize(buf, &struct_to_json_base_test, STRUCT(test1));
    printf("%s\n", json);

    test2 struct_to_json_nult_test =
        {.normal_val =
             {
                 .char_num_base = -50,
                 .char_bool_base = False,
                 .uchar_num_base = 255,
                 .uchar_bool_base = True,
                 .short_num_base = -30,
                 .short_bool_base = True,
                 .ushort_num_base = 65535,
                 .ushort_bool_base = False,
                 .int_num_base = -25185,
                 .int_bool_base = True,
                 .uint_num_base = 123456789,
                 .uint_bool_base = False,
                 .ll_num_base = -85124,
                 .ll_bool_base = True,
                 .ull_num_base = 985214755555,
                 .ull_bool_base = True,
                 .float_num_base = 123.234f,
                 .float_bool_base = False,
                 .double_num_base = -654.32152,
                 .double_bool_base = False,
                 //数组
                 .char_str_base_arr = "My love",
                 .char_num_base_arr = {2, 3},
                 .char_bool_base_arr = {True, False},
                 .uchar_str_base_arr = "Your love",
                 .uchar_num_base_arr = {254, 255},
                 .uchar_bool_base_arr = {False, False},
                 .short_num_base_arr = {-200, 5246},
                 .short_bool_base_arr = {True, True},
                 .ushort_num_base_arr = {65535, 6554},
                 .ushort_bool_base_arr = {False, False},
                 .int_num_base_arr = {'A', 'R'},
                 .int_bool_base_arr = {True, True},
                 .uint_num_base_arr = {952154855, 1452589},
                 .uint_bool_base_arr = {True, True},
                 .ll_num_base_arr = {154978515122157, 897},
                 .ll_bool_base_arr = {True, False},
                 .ull_num_base_arr = {5487646487845451054, 168765487684541},
                 .ull_bool_base_arr = {True, True},
                 .float_num_base_arr = {-123.03f, 562.2355f},
                 .float_bool_base_arr = {False, True},
                 .double_num_base_arr = {3.14159265358, 2.71},
                 .double_bool_base_arr = {False, True},
                 //指针
                 .p_char_str_base = p_char_str_base,
                 .p_char_num_base = &p_char_num_base,
                 .p_char_bool_base = &p_char_bool_base,
                 .p_uchar_str_base = p_uchar_str_base,
                 .p_uchar_num_base = &p_uchar_num_base,
                 .p_uchar_bool_base = &p_uchar_bool_base,
                 .p_short_num_base = &p_short_num_base,
                 .p_short_bool_base = &p_short_bool_base,
                 .p_ushort_num_base = &p_ushort_num_base,
                 .p_ushort_bool_base = &p_ushort_bool_base,
                 .p_int_num_base = &p_int_num_base,
                 .p_int_bool_base = &p_int_bool_base,
                 .p_uint_num_base = &p_uint_num_base,
                 .p_uint_bool_base = &p_uint_bool_base,
                 .p_ll_num_base = &p_ll_num_base,
                 .p_ll_bool_base = &p_ll_bool_base,
                 .p_ull_num_base = &p_ull_num_base,
                 .p_ull_bool_base = &p_ull_bool_base,
                 .p_float_num_base = &p_float_num_base,
                 .p_float_bool_base = &p_float_bool_base,
                 .p_double_num_base = &p_double_num_base,
                 .p_double_bool_base = &p_double_bool_base,
                 //指针数组
                 .p_char_str_base_arr = {p_char_str_base_arr[0], p_char_str_base_arr[1]},
                 .p_char_num_base_arr = {&p_char_num_base_arr[0], &p_char_num_base_arr[1]},
                 .p_char_bool_base_arr = {&p_char_bool_base_arr[0], &p_char_bool_base_arr[1]},
                 .p_uchar_str_base_arr = {p_uchar_str_base_arr[0], p_uchar_str_base_arr[1]},
                 .p_uchar_num_base_arr = {&p_uchar_num_base_arr[0], &p_uchar_num_base_arr[1]},
                 .p_uchar_bool_base_arr = {&p_uchar_bool_base_arr[0], &p_uchar_bool_base_arr[1]},
                 .p_short_num_base_arr = {&p_short_num_base_arr[0], &p_short_num_base_arr[1]},
                 .p_short_bool_base_arr = {&p_short_bool_base_arr[0], &p_short_bool_base_arr[1]},
                 .p_ushort_num_base_arr = {&p_ushort_num_base_arr[0], &p_ushort_num_base_arr[1]},
                 .p_ushort_bool_base_arr = {&p_ushort_bool_base_arr[0], &p_ushort_bool_base_arr[1]},
                 .p_int_num_base_arr = {&p_int_num_base_arr[0], &p_int_num_base_arr[1]},
                 .p_int_bool_base_arr = {&p_int_bool_base_arr[0], &p_int_bool_base_arr[1]},
                 .p_uint_num_base_arr = {&p_uint_num_base_arr[0], &p_uint_num_base_arr[1]},
                 .p_uint_bool_base_arr = {&p_uint_bool_base_arr[0], &p_uint_bool_base_arr[1]},
                 .p_ll_num_base_arr = {&p_ll_num_base_arr[0], &p_ll_num_base_arr[1]},
                 .p_ll_bool_base_arr = {&p_ll_bool_base_arr[0], &p_ll_bool_base_arr[1]},
                 .p_ull_num_base_arr = {&p_ull_num_base_arr[0], &p_ull_num_base_arr[1]},
                 .p_ull_bool_base_arr = {&p_ull_bool_base_arr[0], &p_ull_bool_base_arr[1]},
                 .p_float_num_base_arr = {&p_float_num_base_arr[0], &p_float_num_base_arr[1]},
                 .p_float_bool_base_arr = {&p_float_bool_base_arr[0], &p_float_bool_base_arr[1]},
                 .p_double_num_base_arr = {&p_double_num_base_arr[0], &p_double_num_base_arr[1]},
                 .p_double_bool_base_arr = {&p_double_bool_base_arr[0], &p_double_bool_base_arr[1]},
             },
         .arr_val = {{
                         .char_num_base = -50,
                         .char_bool_base = False,
                         .uchar_num_base = 255,
                         .uchar_bool_base = True,
                         .short_num_base = -30,
                         .short_bool_base = True,
                         .ushort_num_base = 65535,
                         .ushort_bool_base = False,
                         .int_num_base = -25185,
                         .int_bool_base = True,
                         .uint_num_base = 123456789,
                         .uint_bool_base = False,
                         .ll_num_base = -85124,
                         .ll_bool_base = True,
                         .ull_num_base = 985214755555,
                         .ull_bool_base = True,
                         .float_num_base = 123.234f,
                         .float_bool_base = False,
                         .double_num_base = -654.32152,
                         .double_bool_base = False,
                         //数组
                         .char_str_base_arr = "My love",
                         .char_num_base_arr = {2, 3},
                         .char_bool_base_arr = {True, False},
                         .uchar_str_base_arr = "Your love",
                         .uchar_num_base_arr = {254, 255},
                         .uchar_bool_base_arr = {False, False},
                         .short_num_base_arr = {-200, 5246},
                         .short_bool_base_arr = {True, True},
                         .ushort_num_base_arr = {65535, 6554},
                         .ushort_bool_base_arr = {False, False},
                         .int_num_base_arr = {'A', 'R'},
                         .int_bool_base_arr = {True, True},
                         .uint_num_base_arr = {952154855, 1452589},
                         .uint_bool_base_arr = {True, True},
                         .ll_num_base_arr = {154978515122157, 897},
                         .ll_bool_base_arr = {True, False},
                         .ull_num_base_arr = {5487646487845451054, 168765487684541},
                         .ull_bool_base_arr = {True, True},
                         .float_num_base_arr = {-123.03f, 562.2355f},
                         .float_bool_base_arr = {False, True},
                         .double_num_base_arr = {3.14159265358, 2.71},
                         .double_bool_base_arr = {False, True},
                         //指针
                         .p_char_str_base = p_char_str_base,
                         .p_char_num_base = &p_char_num_base,
                         .p_char_bool_base = &p_char_bool_base,
                         .p_uchar_str_base = p_uchar_str_base,
                         .p_uchar_num_base = &p_uchar_num_base,
                         .p_uchar_bool_base = &p_uchar_bool_base,
                         .p_short_num_base = &p_short_num_base,
                         .p_short_bool_base = &p_short_bool_base,
                         .p_ushort_num_base = &p_ushort_num_base,
                         .p_ushort_bool_base = &p_ushort_bool_base,
                         .p_int_num_base = &p_int_num_base,
                         .p_int_bool_base = &p_int_bool_base,
                         .p_uint_num_base = &p_uint_num_base,
                         .p_uint_bool_base = &p_uint_bool_base,
                         .p_ll_num_base = &p_ll_num_base,
                         .p_ll_bool_base = &p_ll_bool_base,
                         .p_ull_num_base = &p_ull_num_base,
                         .p_ull_bool_base = &p_ull_bool_base,
                         .p_float_num_base = &p_float_num_base,
                         .p_float_bool_base = &p_float_bool_base,
                         .p_double_num_base = &p_double_num_base,
                         .p_double_bool_base = &p_double_bool_base,
                         //指针数组
                         .p_char_str_base_arr = {p_char_str_base_arr[0], p_char_str_base_arr[1]},
                         .p_char_num_base_arr = {&p_char_num_base_arr[0], &p_char_num_base_arr[1]},
                         .p_char_bool_base_arr = {&p_char_bool_base_arr[0], &p_char_bool_base_arr[1]},
                         .p_uchar_str_base_arr = {p_uchar_str_base_arr[0], p_uchar_str_base_arr[1]},
                         .p_uchar_num_base_arr = {&p_uchar_num_base_arr[0], &p_uchar_num_base_arr[1]},
                         .p_uchar_bool_base_arr = {&p_uchar_bool_base_arr[0], &p_uchar_bool_base_arr[1]},
                         .p_short_num_base_arr = {&p_short_num_base_arr[0], &p_short_num_base_arr[1]},
                         .p_short_bool_base_arr = {&p_short_bool_base_arr[0], &p_short_bool_base_arr[1]},
                         .p_ushort_num_base_arr = {&p_ushort_num_base_arr[0], &p_ushort_num_base_arr[1]},
                         .p_ushort_bool_base_arr = {&p_ushort_bool_base_arr[0], &p_ushort_bool_base_arr[1]},
                         .p_int_num_base_arr = {&p_int_num_base_arr[0], &p_int_num_base_arr[1]},
                         .p_int_bool_base_arr = {&p_int_bool_base_arr[0], &p_int_bool_base_arr[1]},
                         .p_uint_num_base_arr = {&p_uint_num_base_arr[0], &p_uint_num_base_arr[1]},
                         .p_uint_bool_base_arr = {&p_uint_bool_base_arr[0], &p_uint_bool_base_arr[1]},
                         .p_ll_num_base_arr = {&p_ll_num_base_arr[0], &p_ll_num_base_arr[1]},
                         .p_ll_bool_base_arr = {&p_ll_bool_base_arr[0], &p_ll_bool_base_arr[1]},
                         .p_ull_num_base_arr = {&p_ull_num_base_arr[0], &p_ull_num_base_arr[1]},
                         .p_ull_bool_base_arr = {&p_ull_bool_base_arr[0], &p_ull_bool_base_arr[1]},
                         .p_float_num_base_arr = {&p_float_num_base_arr[0], &p_float_num_base_arr[1]},
                         .p_float_bool_base_arr = {&p_float_bool_base_arr[0], &p_float_bool_base_arr[1]},
                         .p_double_num_base_arr = {&p_double_num_base_arr[0], &p_double_num_base_arr[1]},
                         .p_double_bool_base_arr = {&p_double_bool_base_arr[0], &p_double_bool_base_arr[1]},
                     },
                     {
                         .char_num_base = -50,
                         .char_bool_base = False,
                         .uchar_num_base = 255,
                         .uchar_bool_base = True,
                         .short_num_base = -30,
                         .short_bool_base = True,
                         .ushort_num_base = 65535,
                         .ushort_bool_base = False,
                         .int_num_base = -25185,
                         .int_bool_base = True,
                         .uint_num_base = 123456789,
                         .uint_bool_base = False,
                         .ll_num_base = -85124,
                         .ll_bool_base = True,
                         .ull_num_base = 985214755555,
                         .ull_bool_base = True,
                         .float_num_base = 123.234f,
                         .float_bool_base = False,
                         .double_num_base = -654.32152,
                         .double_bool_base = False,
                         //数组
                         .char_str_base_arr = "My love",
                         .char_num_base_arr = {2, 3},
                         .char_bool_base_arr = {True, False},
                         .uchar_str_base_arr = "Your love",
                         .uchar_num_base_arr = {254, 255},
                         .uchar_bool_base_arr = {False, False},
                         .short_num_base_arr = {-200, 5246},
                         .short_bool_base_arr = {True, True},
                         .ushort_num_base_arr = {65535, 6554},
                         .ushort_bool_base_arr = {False, False},
                         .int_num_base_arr = {'A', 'R'},
                         .int_bool_base_arr = {True, True},
                         .uint_num_base_arr = {952154855, 1452589},
                         .uint_bool_base_arr = {True, True},
                         .ll_num_base_arr = {154978515122157, 897},
                         .ll_bool_base_arr = {True, False},
                         .ull_num_base_arr = {5487646487845451054, 168765487684541},
                         .ull_bool_base_arr = {True, True},
                         .float_num_base_arr = {-123.03f, 562.2355f},
                         .float_bool_base_arr = {False, True},
                         .double_num_base_arr = {3.14159265358, 2.71},
                         .double_bool_base_arr = {False, True},
                         //指针
                         .p_char_str_base = p_char_str_base,
                         .p_char_num_base = &p_char_num_base,
                         .p_char_bool_base = &p_char_bool_base,
                         .p_uchar_str_base = p_uchar_str_base,
                         .p_uchar_num_base = &p_uchar_num_base,
                         .p_uchar_bool_base = &p_uchar_bool_base,
                         .p_short_num_base = &p_short_num_base,
                         .p_short_bool_base = &p_short_bool_base,
                         .p_ushort_num_base = &p_ushort_num_base,
                         .p_ushort_bool_base = &p_ushort_bool_base,
                         .p_int_num_base = &p_int_num_base,
                         .p_int_bool_base = &p_int_bool_base,
                         .p_uint_num_base = &p_uint_num_base,
                         .p_uint_bool_base = &p_uint_bool_base,
                         .p_ll_num_base = &p_ll_num_base,
                         .p_ll_bool_base = &p_ll_bool_base,
                         .p_ull_num_base = &p_ull_num_base,
                         .p_ull_bool_base = &p_ull_bool_base,
                         .p_float_num_base = &p_float_num_base,
                         .p_float_bool_base = &p_float_bool_base,
                         .p_double_num_base = &p_double_num_base,
                         .p_double_bool_base = &p_double_bool_base,
                         //指针数组
                         .p_char_str_base_arr = {p_char_str_base_arr[0], p_char_str_base_arr[1]},
                         .p_char_num_base_arr = {&p_char_num_base_arr[0], &p_char_num_base_arr[1]},
                         .p_char_bool_base_arr = {&p_char_bool_base_arr[0], &p_char_bool_base_arr[1]},
                         .p_uchar_str_base_arr = {p_uchar_str_base_arr[0], p_uchar_str_base_arr[1]},
                         .p_uchar_num_base_arr = {&p_uchar_num_base_arr[0], &p_uchar_num_base_arr[1]},
                         .p_uchar_bool_base_arr = {&p_uchar_bool_base_arr[0], &p_uchar_bool_base_arr[1]},
                         .p_short_num_base_arr = {&p_short_num_base_arr[0], &p_short_num_base_arr[1]},
                         .p_short_bool_base_arr = {&p_short_bool_base_arr[0], &p_short_bool_base_arr[1]},
                         .p_ushort_num_base_arr = {&p_ushort_num_base_arr[0], &p_ushort_num_base_arr[1]},
                         .p_ushort_bool_base_arr = {&p_ushort_bool_base_arr[0], &p_ushort_bool_base_arr[1]},
                         .p_int_num_base_arr = {&p_int_num_base_arr[0], &p_int_num_base_arr[1]},
                         .p_int_bool_base_arr = {&p_int_bool_base_arr[0], &p_int_bool_base_arr[1]},
                         .p_uint_num_base_arr = {&p_uint_num_base_arr[0], &p_uint_num_base_arr[1]},
                         .p_uint_bool_base_arr = {&p_uint_bool_base_arr[0], &p_uint_bool_base_arr[1]},
                         .p_ll_num_base_arr = {&p_ll_num_base_arr[0], &p_ll_num_base_arr[1]},
                         .p_ll_bool_base_arr = {&p_ll_bool_base_arr[0], &p_ll_bool_base_arr[1]},
                         .p_ull_num_base_arr = {&p_ull_num_base_arr[0], &p_ull_num_base_arr[1]},
                         .p_ull_bool_base_arr = {&p_ull_bool_base_arr[0], &p_ull_bool_base_arr[1]},
                         .p_float_num_base_arr = {&p_float_num_base_arr[0], &p_float_num_base_arr[1]},
                         .p_float_bool_base_arr = {&p_float_bool_base_arr[0], &p_float_bool_base_arr[1]},
                         .p_double_num_base_arr = {&p_double_num_base_arr[0], &p_double_num_base_arr[1]},
                         .p_double_bool_base_arr = {&p_double_bool_base_arr[0], &p_double_bool_base_arr[1]},
                     }},
         .ptr_val = &struct_to_json_base_test,
         .ptr_arr_val = {&struct_to_json_base_test, &struct_to_json_base_test}};

    json = jsonc_serialize(buf, &struct_to_json_nult_test, STRUCT(test2));
    printf("%s\n", json);

    return 0;
}
