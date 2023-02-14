/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-02-14 11:09:55
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

#include "jsonc.h"
#include "test/include/test.h"

char *str = "{\"type\":2,\"id\":1,\"num\":145785451,\"data\":{\"id\":18,\"chnum\":3,\"ch\":[{\"ch\":1,\"num\":\"A\"},{\"ch\":1,\"num\":\"B\"},{\"ch\":1,\"num\":\"C\"}]}}";

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    struct MsgFrame frame;
    int ret = JsoncDeserialize(str, &frame, MsgFrame);

    if (ret != 0) {
        printf("change err");
    }

    printf("frame.type = %d\n",frame.type);
    printf("frame.id = %d\n",frame.id);
    printf("frame.num = %d\n",frame.num);

    // test();

    return 0;
}
