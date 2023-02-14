/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 10:30:52
 * @LastEditTime : 2023-01-06 12:22:32
 * @LastEditors  : lqm283
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

enum msg_type {
    MsgUnitHardInfo = 1,
    MsgUnitObjInfo,
    MsgAck,
    MsgStream,
    MsgCmd
};

/**
 * @description: 注射通道的相关信息
 */
struct ChHardInfo {
    uint32_t ch;   // 通道的物理编号
    char sn[100];  // 通道的序列号
    char *ft[10];  // 通道拥有的功能
};
INIT(ChHardInfo, struct ChHardInfo,
     MEM(struct ChHardInfo, Num, uint32_t, ch, NULL),
     MEM(struct ChHardInfo, Str, char, sn, NULL),
     MEM(struct ChHardInfo, Str, char *, ft, NULL));

struct ChObjInfo {
    uint32_t ch;  // 通道的物理编号
    char num;     // 分配的逻辑通道号
};
INIT(ChObjInfo, struct ChObjInfo,
     MEM(struct ChObjInfo, Num, uint32_t, ch, NULL),
     MEM(struct ChObjInfo, Num, char, num, NULL));

struct UnitHardInfo {
    uint32_t id;     // 由后端分配， 0 为没有 id
    char sn[100];    // 注射单元的序列号
    char ext;        // 注射单元是内置或外置，0 内置， 1 外置
    uint32_t chnum;  // 注射单元拥有的物理通道数
    struct ChHardInfo ch[3];  // 各个通道拥有的功能
};
INIT(UnitHardInfo, struct UnitHardInfo,
     MEM(struct UnitHardInfo, Num, uint32_t, id, NULL),
     MEM(struct UnitHardInfo, Str, char, sn, NULL),
     MEM(struct UnitHardInfo, Num, char, ext, NULL),
     MEM(struct UnitHardInfo, Num, uint32_t, chnum, NULL),
     MEM(struct UnitHardInfo, Obj, struct ChHardInfo, ch, ChHardInfo));

struct UnitObjInfo {
    uint32_t id;             // 由后端分配， 0 为没有 id
    uint32_t chnum;          // 注射单元拥有的物理通道数
    struct ChObjInfo ch[3];  // 通道对象的信息
};
INIT(UnitObjInfo, struct UnitObjInfo,
     MEM(struct UnitObjInfo, Num, uint32_t, id, NULL),
     MEM(struct UnitObjInfo, Num, uint32_t, chnum, NULL),
     MEM(struct UnitObjInfo, Obj, struct ChObjInfo, ch, ChObjInfo));

struct Ack {
    uint32_t ack;  // 应答信息，值为要应答的消息的编号，即消息框架中的 num
};
INIT(Ack, struct Ack, MEM(struct Ack, Num, uint32_t, ack, NULL));

struct Stream {
    uint32_t ch;
    float pre;
};
INIT(Stream, struct Stream, MEM(struct Stream, Num, uint32_t, ch, NULL),
     MEM(struct Stream, Num, float, pre, NULL));

struct Cmd {
    uint32_t ch;     // 注射通道号
    float speed;     // 注射速度
    uint32_t alarm;  // 报警等级，0 关闭，1 低级， 2 中级， 3 高级
};
INIT(Cmd, struct Cmd, MEM(struct Cmd, Num, uint32_t, ch, NULL),
     MEM(struct Cmd, Num, float, speed, NULL),
     MEM(struct Cmd, Num, uint32_t, alarm, NULL));

union MsgData {
    struct UnitObjInfo Info;
    struct Ack Ack;
    struct Cmd Cmd;
};
INIT(MsgData, union MsgData,
     MEM(union MsgData, Obj, struct UnitObjInfo, Info, UnitObjInfo, "info"),
     MEM(union MsgData, Obj, struct Ack, Ack, Ack, "ack"),
     MEM(union MsgData, Obj, struct Cmd, Cmd, Cmd, "cmd"));

struct MsgFrame {
    uint32_t type;
    uint32_t id;
    uint32_t num;
    union MsgData data;
};
INIT(MsgFrame, struct MsgFrame, MEM(struct MsgFrame, Num, uint32_t, type, NULL),
     MEM(struct MsgFrame, Num, uint32_t, id, NULL),
     MEM(struct MsgFrame, Num, uint32_t, num, NULL),
     MEM(struct MsgFrame, Obj, union MsgData, data, MsgData));

/**
 * @description: 注射单元硬件信息消息
 */
struct UnitHardInfoMsgFrame {
    uint32_t type;
    uint32_t id;
    uint32_t num;
    struct UnitHardInfo data;
};
INIT(UnitHardInfoMsgFrame, struct UnitHardInfoMsgFrame,
     MEM(struct UnitHardInfoMsgFrame, Num, uint32_t, type, NULL),
     MEM(struct UnitHardInfoMsgFrame, Num, uint32_t, id, NULL),
     MEM(struct UnitHardInfoMsgFrame, Num, uint32_t, num, NULL),
     MEM(struct UnitHardInfoMsgFrame, Num, struct UnitHardInfo, data,
         UnitHardInfo));

/**
 * @description: 注射单元硬件信息消息
 */
struct UnitObjInfoMsgFrame {
    uint32_t type;
    uint32_t id;
    uint32_t num;
    struct UnitObjInfo data;
};
INIT(UnitObjInfoMsgFrame, struct UnitObjInfoMsgFrame,
     MEM(struct UnitObjInfoMsgFrame, Num, uint32_t, type, NULL),
     MEM(struct UnitObjInfoMsgFrame, Num, uint32_t, id, NULL),
     MEM(struct UnitObjInfoMsgFrame, Num, uint32_t, num, NULL),
     MEM(struct UnitObjInfoMsgFrame, Num, struct UnitObjInfo, data,
         UnitObjInfo));

/**
 * @description: 应答消息
 */
struct AckFrame {
    uint32_t type;
    uint32_t id;
    uint32_t num;
    struct Ack data;
};
INIT(AckFrame, struct AckFrame, MEM(struct AckFrame, Num, uint32_t, type, NULL),
     MEM(struct AckFrame, Num, uint32_t, id, NULL),
     MEM(struct AckFrame, Num, uint32_t, num, NULL),
     MEM(struct AckFrame, Num, struct Ack, data, Ack));

/**
 * @description: 数据流消息
 */
struct StreamFrame {
    uint32_t type;
    uint32_t id;
    uint32_t num;
    struct Stream data;
};
INIT(StreamFrame, struct StreamFrame,
     MEM(struct StreamFrame, Num, uint32_t, type, NULL),
     MEM(struct StreamFrame, Num, uint32_t, id, NULL),
     MEM(struct StreamFrame, Num, uint32_t, num, NULL),
     MEM(struct StreamFrame, Num, struct Stream, data, Stream));

/**
 * @description: 控制消息
 */
struct CmdFrame {
    uint32_t type;
    uint32_t id;
    uint32_t num;
    struct Cmd data;
};
INIT(CmdFrame, struct CmdFrame, MEM(struct CmdFrame, Num, uint32_t, type, NULL),
     MEM(struct CmdFrame, Num, uint32_t, id, NULL),
     MEM(struct CmdFrame, Num, uint32_t, num, NULL),
     MEM(struct CmdFrame, Num, struct Cmd, data, Cmd));

#endif
