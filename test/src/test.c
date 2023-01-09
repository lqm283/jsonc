/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:09:02
 * @LastEditTime : 2023-01-08 23:51:05
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/test.c
 */

#include "../include/test.h"

#include <stdio.h>
#include <string.h>

#include "../include/json_to_mult.h"
#include "../include/mult_to_json.h"

int test_change_mult_to_json() {
    int ret = 0;
    char exp[81920];
    char real[81920];
    for (const struct TestChangeToJson* Change = ChangeToJson;
         *Change->test_change_to_json != NULL;
         Change++) {
        char* json = (Change->test_change_to_json)(exp, real);

        if (json) {
            if (strcmp(exp, real)) {
                ret++;
                printf(
                    "\033[0m\033[1;31m%s\033[0m test failed !!\n\texp: %s \n\treal: %s\n",
                    Change->name,
                    exp,
                    real);
            }
        } else {
            ret++;
            printf("\033[0m\033[1;31m%s\033[0m Change error!!\041[0m\n", Change->name);
        }
    }

    return ret;
}

int test_change_json_to_mult() {
    int ret = 0;
    char dir[128];
    char path[4096];
    char json[81920];
    int count = 0;
    char* p = NULL;
    char* d = dir;
    for (const struct TestChangeToMult* Change = ChangeToMult;
         *Change->test_change_to_mult != NULL;
         Change++) {
        for (int i = strlen(Change->name) - 1; i >= 0; i--) {
            if (Change->name[i] == '_') {
                count++;
                if (count == 2) {
                    p = (char*)&Change->name[i + 1];
                    break;
                }
            }
        }

        while (*p != '_' && *p != '\0') {
            *d++ = *p++;
        }

        sprintf(path, "json/%s/%s.json", dir, Change->name);

        FILE* file = fopen(path, "r");
        if (!file) {
            printf("\033[0m\033[1;31mRead %s.json err:\033[0m file is not exist\n",
                   Change->name);
            ret++;
            continue;
        }
        int n = fread(json, 1, sizeof(json), file);

        if (n == 0) {
            printf("\033[0m\033[1;31mRead %s.json err:\033[0m file is empty\n",
                   Change->name);
            ret++;
            continue;
        }

        json[n] = '\0';

        int result = Change->test_change_to_mult(json);
        if (result) {
            printf("\033[0m\033[1;31m%s\033[0m test err!! num = %d\n",
                   Change->name,
                   result);
            ret++;
        }
    }
    return ret;
}

void test() {
    int ret = 0;

    ret = test_change_mult_to_json();

    ret += test_change_json_to_mult();

    if (ret) {
        printf("Have %d times test failed!!!\n", ret);
    } else {
        printf("All tests ok!!!\n");
    }
}
