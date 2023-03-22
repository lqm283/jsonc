/*
 * @Author       : lqm283
 * @Date         : 2023-01-14 08:27:47
 * @LastEditTime : 2023-03-22 14:21:31
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/com/test_comprehensive.c
 */

#include "../../include/com/test_comprehensive.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 发送
int test_change_non_non_single_com_uninfo_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"type\":1,\"id\":2165489,\"Num\":16548943,\"data\":{\"id\":1,\"sn\":\"1234-"
        "abcd-2022\",\"ext\":true,\"chnum\":3,\"ch\":[{\"ch\":1,\"num\":\"A\",\"sn\":"
        "\"5468-adsgae-aeef\",\"ft\":[\"4657486\",\"afeaf\",\"faefae\"]},{\"ch\":2,"
        "\"num\":\"B\",\"sn\":\"3456-adsgae-adsf\",\"ft\":[\"4657486\",\"afeaf\","
        "\"faefae\"]},{\"ch\":3,\"num\":\"C\",\"sn\":\"6574-adsgae-sdfg\",\"ft\":["
        "\"4657486\",\"afeaf\",null]}]}}";
    struct SendUnInfoFram s = {
        1,
        2165489,
        16548943,
        {1,
         "1234-abcd-2022",
         1,
         3,
         {{1, 'A', "5468-adsgae-aeef", {"4657486", "afeaf", "faefae"}},
          {2, 'B', "3456-adsgae-adsf", {"4657486", "afeaf", "faefae"}},
          {3, 'C', "6574-adsgae-sdfg", {"4657486", "afeaf"}}}},
        60};

    ret = JsoncSerialize(real, &s, SendUnInfoFram);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

int test_change_non_non_single_com_ack_to_json(char* exp, char* real) {
    int ret = 0;
    char* e = "{\"type\":1,\"id\":2165489,\"num\":16548943,\"data\":{\"ack\":465746}}";
    struct SendAckFram s = {1, 2165489, 16548943, {465746}};

    ret = JsoncSerialize(real, &s, SendAckFram);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

int test_change_non_non_single_com_stream_to_json(char* exp, char* real) {
    int ret = 0;
    char* e =
        "{\"type\":1,\"id\":2165489,\"num\":16548943,\"data\":{\"ch\":1,\"a\":16,\"b\":1."
        "230000,\"c\":true}}";
    struct SendStreamFram s = {1, 2165489, 16548943, {1, 16, 1.23, 1}};

    ret = JsoncSerialize(real, &s, SendStreamFram);
    if (!ret) {
        strcpy(exp, e);
    }
    return ret;
}

int test_change_single_uninfo_json_to_non_non_mult_com_data(char* json) {
    int ret = 0;
    struct GetDataFram s;
    ret = JsoncDeserialize(json, &s, GetDataFram);

    if (s.Type != 1 || s.Id != 2165489 || s.Num != 16548943) {
        return 1;
    }

    if (strcmp(s.Data.ObjInfo.Status, "nw")) {
        return 2;
    }

    if (s.Data.ObjInfo.Ch[0].Ch != 1 || s.Data.ObjInfo.Ch[0].Num != 'A') {
        return 3;
    }

    printf("s.Type = %d\n", s.Type);
    printf("s.Id = %d\n", s.Id);
    printf("s.Num = %d\n", s.Num);
    printf("s.Data.ObjInfo.Status = %s\n", s.Data.ObjInfo.Status);
    printf("s.Data.ObjInfo.Id = %d\n", s.Data.ObjInfo.Id);
    printf("s.Data.ObjInfo.Ch[0].Ch = %d\n", s.Data.ObjInfo.Ch[0].Ch);
    printf("s.Data.ObjInfo.Ch[0].Num = %c\n", s.Data.ObjInfo.Ch[0].Num);
    printf("s.Data.ObjInfo.Ch[1].Ch = %d\n", s.Data.ObjInfo.Ch[1].Ch);
    printf("s.Data.ObjInfo.Ch[1].Num = %c\n", s.Data.ObjInfo.Ch[1].Num);
    printf("s.Data.ObjInfo.Ch[2].Ch = %d\n", s.Data.ObjInfo.Ch[2].Ch);
    printf("s.Data.ObjInfo.Ch[2].Num = %c\n", s.Data.ObjInfo.Ch[2].Num);

    return ret;
}

int test_change_single_ack_json_to_non_non_mult_com_data(char* json) {
    int ret = 0;
    struct GetDataFram s;
    ret = JsoncDeserialize(json, &s, GetDataFram);

    if (s.Type != 1 || s.Id != 2165489 || s.Num != 16548943) {
        return 1;
    }
    if (s.Data.Ack.Ack != 98456321) {
        return 2;
    }
    printf("s.Type = %d\n", s.Type);
    printf("s.Id = %d\n", s.Id);
    printf("s.Num = %d\n", s.Num);
    printf("s.Num = %d\n", s.Data.Ack.Ack);

    return ret;
}

int test_change_single_cmd_json_to_non_non_mult_com_data(char* json) {
    int ret = 0;
    struct GetDataFram s;
    ret = JsoncDeserialize(json, &s, GetDataFram);

    if (s.Type != 1 || s.Id != 2165489 || s.Num != 16548943) {
        return 1;
    }

    if (s.Data.Cmd.Ch != 1 || s.Data.Cmd.Alarm != 3) {
        return 2;
    }

    printf("s.Type = %d\n", s.Type);
    printf("s.Id = %d\n", s.Id);
    printf("s.Num = %d\n", s.Num);
    printf("s.Data.Cmd.Ch= %d\n", s.Data.Cmd.Ch);
    printf("s.Data.Cmd.Speed = %f\n", s.Data.Cmd.Speed);
    printf("s.Data.Cmd.Alarm = %d\n", s.Data.Cmd.Alarm);

    if (ret) {
        return ret;
    }
    return ret;
}
