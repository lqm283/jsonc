/*
 * @Author       : lqm283 lanqianming@hotmail.com
 * @Date         : 2022-06-09 15:36:54
 * @LastEditTime : 2023-02-24 16:55:50
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

    char buf[1024];
    struct UnitHardInfo info;

    for (int j = 0; j < sizeof(info.ch) / sizeof(struct ChHardInfo); j++) {
        for (int i = 0; i < sizeof(info.ch[j].ft) / sizeof(char *); i++) {
            info.ch[j].ft[i] = calloc(20,sizeof(char));
        }
    }



    FILE* f = fopen("./json/test.json", "rw");
    if (f == NULL) {
        printf("open json fail\n");
        return -1;
    }



    unsigned long len = fread(buf, 1, 1024, f);
    if (!len) {
        return -1;
    }
    fclose(f);

    printf("%s\n",buf);

    int ret = JsoncDeserialize(buf, &info, UnitHardInfo);

    for (int j = 0; j < sizeof(info.ch) / sizeof(struct ChHardInfo); j++) {
        for (int i = 0; i < sizeof(info.ch[j].ft) / sizeof(char *); i++) {
            free(info.ch[j].ft[i]);
        }
    }

    // test();

    return 0;
}
