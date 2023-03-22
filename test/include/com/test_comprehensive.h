/*
 * @Author       : lqm283
 * @Date         : 2023-01-14 08:28:29
 * @LastEditTime : 2023-01-14 21:07:06
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/include/com/test_comprehensive.h
 */

#ifndef __TEST_COMPREHENSIVE_H_
#define __TEST_COMPREHENSIVE_H_

#include <bits/stdint-uintn.h>
#include <stdint.h>

#include "../../../jsonc.h"

struct InjectChInfo {
    uint32_t Ch;
    char Num;
    char* SN;
    char* Ft[3];
};
INIT(InjectChInfo,
     struct InjectChInfo,
     MEM(struct InjectChInfo, Num, uint32_t, Ch, NULL, "ch"),
     MEM(struct InjectChInfo, Str, char, Num, NULL, "num"),
     MEM(struct InjectChInfo, Str, char*, SN, NULL, "sn"),
     MEM(struct InjectChInfo, Str, char*, Ft, NULL, "ft"));

struct HarhwareInfo {
    uint32_t Id;
    char* SN;
    char Ext;
    uint32_t ChNum;
    struct InjectChInfo Ch[3];
};
INIT(HarhwareInfo,
     struct HarhwareInfo,
     MEM(struct HarhwareInfo, Num, uint32_t, Id, NULL, "id"),
     MEM(struct HarhwareInfo, Str, char*, SN, NULL, "sn"),
     MEM(struct HarhwareInfo, Bool, char, Ext, NULL, "ext"),
     MEM(struct HarhwareInfo, Num, uint32_t, ChNum, NULL, "chnum"),
     MEM(struct HarhwareInfo, Obj, struct InjectChInfo, Ch, InjectChInfo, "ch"));

struct InjectObjInfo {
    char Status[5];
    uint32_t Id;
    struct InjectChInfo Ch[5];
};
INIT(InjectObjInfo,
     struct InjectObjInfo,
     MEM(struct InjectObjInfo, Str, char, Status, NULL, "status"),
     MEM(struct InjectObjInfo, Num, uint32_t, Id, NULL, "id"),
     MEM(struct InjectObjInfo, Obj, struct InjectChInfo, Ch, InjectChInfo, "ch"));

struct Ack {
    uint32_t Ack;
};
INIT(Ack, struct Ack, MEM(struct Ack, Num, uint32_t, Ack, NULL, "ack"));

struct Stream {
    uint32_t Ch;
    uint32_t a;
    float b;
    char c;
};
INIT(Stream,
     struct Stream,
     MEM(struct Stream, Num, uint32_t, Ch, NULL, "ch"),
     MEM(struct Stream, Num, uint32_t, a, NULL),
     MEM(struct Stream, Num, float, b, NULL),
     MEM(struct Stream, Bool, char, c, NULL));

struct Cmd {
    uint32_t Ch;
    float Speed;
    uint32_t Alarm;
};
INIT(Cmd,
     struct Cmd,
     MEM(struct Cmd, Num, uint32_t, Ch, NULL, "ch"),
     MEM(struct Cmd, Num, float, Speed, NULL, "speed"),
     MEM(struct Cmd, Num, uint32_t, Alarm, NULL, "alarm"));

// 发送测试
struct SendUnInfoFram {
    int Type;
    uint32_t Id;
    uint32_t Num;
    struct HarhwareInfo Data;
    int pre;  // 私有数据，不转换
};
INIT(SendUnInfoFram,
     struct SendUnInfoFram,
     MEM(struct SendUnInfoFram, Num, int, Type, NULL, "type"),
     MEM(struct SendUnInfoFram, Num, uint32_t, Id, NULL, "id"),
     MEM(struct SendUnInfoFram, Num, uint32_t, Num, NULL, "Num"),
     MEM(struct SendUnInfoFram, Num, struct HarhwareInfo, Data, HarhwareInfo, "data"));

struct SendAckFram {
    int Type;
    uint32_t Id;
    uint32_t Num;
    struct Ack Ack;
};
INIT(SendAckFram,
     struct SendAckFram,
     MEM(struct SendAckFram, Num, int, Type, NULL, "type"),
     MEM(struct SendAckFram, Num, uint32_t, Id, NULL, "id"),
     MEM(struct SendAckFram, Num, uint32_t, Num, NULL, "num"),
     MEM(struct SendAckFram, Num, struct Ack, Ack, Ack, "data"));

struct SendStreamFram {
    int Type;
    uint32_t Id;
    uint32_t Num;
    struct Stream Stream;
};
INIT(SendStreamFram,
     struct SendStreamFram,
     MEM(struct SendStreamFram, Num, int, Type, NULL, "type"),
     MEM(struct SendStreamFram, Num, uint32_t, Id, NULL, "id"),
     MEM(struct SendStreamFram, Num, uint32_t, Num, NULL, "num"),
     MEM(struct SendStreamFram, Num, struct Stream, Stream, Stream, "data"));

// 接收数据

union Data {
    struct InjectObjInfo ObjInfo;
    struct Ack Ack;
    struct Cmd Cmd;
};
INIT(Data,
     union Data,
     MEM(union Data, Num, struct InjectObjInfo, ObjInfo, InjectObjInfo),
     MEM(union Data, Num, struct Ack, Ack, Ack),
     MEM(union Data, Num, struct Stream, Cmd, Cmd));

struct GetDataFram {
    int Type;
    uint32_t Id;
    uint32_t Num;
    union Data Data;
};
INIT(GetDataFram,
     struct GetDataFram,
     MEM(struct GetDataFram, Num, int, Type, NULL, "type"),
     MEM(struct GetDataFram, Num, uint32_t, Id, NULL, "id"),
     MEM(struct GetDataFram, Num, uint32_t, Num, NULL, "num"),
     MEM(struct GetDataFram, Num, union Data, Data, Data, "data"));

// 发送测试函数
int test_change_non_non_single_com_uninfo_to_json(char* exp, char* real);
int test_change_non_non_single_com_ack_to_json(char* exp, char* real);
int test_change_non_non_single_com_stream_to_json(char* exp, char* real);

// 接收测试函数
int test_change_single_uninfo_json_to_non_non_mult_com_data(char* json);
int test_change_single_ack_json_to_non_non_mult_com_data(char* json);
int test_change_single_cmd_json_to_non_non_mult_com_data(char* json);
#endif
