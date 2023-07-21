/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-07-21 14:06:18
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/main.c
 */

#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "jsonc.h"
#include "test/include/test.h"

struct a{
    void *data;
};
INIT(a, struct a,
    MEM(struct a, Any, void *, data, NULL)
);


char *obj = "{\"data\":{\"a\":3}}";
char *arr = "{\"data\":[1,2,3,4,5]}";
char *str = "{\"data\":\"hello world\"}";
char *num = "{\"data\":10}";
char *bool = "{\"data\":false}";

char *ctrl  = "{\"type\":6,\"data\":{\"mm_h\":78.8,\"lv\":0}}";

struct ch_ctrl {
	float speed; // 注射速度
	uint32_t alarm; // 报警等级，0 关闭，1 低级， 2 中级， 3 高级
};
INIT(ch_ctrl, struct ch_ctrl, MEM(struct ch_ctrl, Num, float, speed, NULL,"mm_h"),
     MEM(struct ch_ctrl, Num, uint32_t, alarm, NULL,"lv"));

struct ch_obj_init {
	int obj;
};
INIT(ch_obj_init, struct ch_obj_init,
     MEM(struct ch_obj_init, Num, int, obj, NULL));

struct ch_obj_set {
	int obj;
	double val;
};
INIT(ch_obj_set, struct ch_obj_set, MEM(struct ch_obj_set, Num, int, obj, NULL),
     MEM(struct ch_obj_set, Num, double, val, NULL));

union ch_msg_enum {
	struct ch_ctrl ctrl;
	struct ch_obj_init init;
	struct ch_obj_set set;
};
INIT(ch_msg_enum, union ch_msg_enum,
     MEM(union ch_msg_enum, Obj, struct ch_ctrl, ctrl, ch_ctrl, "ctrl"),
     MEM(union ch_msg_enum, Obj, struct ch_obj_init, init, ch_obj_init),
     MEM(union ch_msg_enum, Obj, struct ch_obj_set, set, ch_obj_set));

struct ch_recv_msg_frame {
	uint32_t type;
	union ch_msg_enum data;
};
INIT(ch_recv_msg_frame, struct ch_recv_msg_frame,
     MEM(struct ch_recv_msg_frame, Num, uint32_t, type, NULL),
     MEM(struct ch_recv_msg_frame, Obj, union ch_msg_enum, data, ch_msg_enum));

struct ch_recv_msg_frame frame;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    test();
    struct a a = {
        .data = NULL,
    };
    JsoncDeserialize(obj, &a,a);
    printf("%s\r\n", (char *)a.data);
    JsoncDeserialize(arr, &a,a);
    printf("%s\r\n", (char *)a.data);
    JsoncDeserialize(str, &a,a);
    printf("%s\r\n", (char *)a.data);
    JsoncDeserialize(num, &a,a);
    printf("%d\r\n", (uint8_t)*(double *)a.data);
    JsoncDeserialize(bool, &a,a);
    printf("%d\r\n", (uint8_t)*(double *)a.data);



    JsoncDeserialize(ctrl, &frame, ch_recv_msg_frame);

    return 0;
}
