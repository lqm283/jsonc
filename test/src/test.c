/*
 * @Author       : lqm283
 * @Date         : 2023-01-06 09:09:02
 * @LastEditTime : 2023-01-11 20:15:23
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/test/src/test.c
 */

#include <stdio.h>
#include <string.h>

#include "../include/json_to_mult.h"
#include "../include/mult_to_json.h"

int test_change_mult_to_json() {
    int ret = 0;
    char exp[81920] = {0};
    char real[81920] = {0};
    const struct TestChangeToJson** Change = ChangeToJson;
    while (*Change != NULL) {
        for (const struct TestChangeToJson* c = *Change; *c->test_change_to_json != NULL;
             c++) {
            char* json = (c->test_change_to_json)(exp, real);

            if (json) {
                if (strcmp(exp, real)) {
                    ret++;
                    printf(
                        "\033[0m\033[1;31m%s\033[0m test failed !!\n\texp: %s \n\treal: "
                        "%s\n",
                        c->name,
                        exp,
                        real);
                }
            } else {
                ret++;
                printf("\033[0m\033[1;31m%s\033[0m Change error!!\041[0m\n", c->name);
            }
        }
        Change++;
    }

    return ret;
}

static int get_path(const char* src, char* path1, char* path2, char* path3, char* path4) {
    int ret = 0;
    int count = 0;
    const char* start;
    const char* end;
    for (int i = strlen(src) - 1; i >= 0; i--) {
        if (src[i] == '_') {
            count++;
            if (count == 1) {
                end = &src[i];
            } else if (count == 2) {
                start = &src[i + 1];
                memcpy(path1, start, end - start);
                path1[end - start] = '\0';
                end = &src[i];
            } else if (count == 3) {
                start = &src[i + 1];
                memcpy(path3, start, end - start);
                path3[end - start] = '\0';
                end = &src[i];
            } else if (count == 5) {
                start = &src[i + 1];
                memcpy(path2, start, end - start);
                path2[end - start] = '\0';
            } else if (count == 7) {
                end = &src[i];
            } else if (count == 8) {
                start = &src[i + 1];
                memcpy(path4, start, end - start);
                path4[end - start] = '\0';
                break;
            }
        }
    }
    return ret;
}

int test_change_json_to_mult() {
    int ret = 0;
    char path1[128];
    char path2[128];
    char path3[128];
    char path4[128];
    char path[4096];
    char json[81920];
    const struct TestChangeToMult** Change = ChangeToMult;
    while (*Change != NULL) {
        for (const struct TestChangeToMult* c = *Change; *c->test_change_to_mult != NULL;
             c++) {
            ret = get_path(c->name, path1, path2, path3, path4);

            if (!strcmp(path1, "struct") || !strcmp(path1, "union")) {
                sprintf(path, "json/%s/%s/%s/%s.json", path1, path2, path3, c->name);
                ;
            } else {
                sprintf(path,
                        "json/%s/%s/%s/%s/%s.json",
                        path1,
                        path2,
                        path3,
                        path4,
                        c->name);
                ;
            }
            FILE* file = fopen(path, "r");
            if (!file) {
                printf("\033[0m\033[1;31mRead %s.json err:\033[0m file is not exist\n",
                       c->name);
                ret++;
                continue;
            }
            int n = fread(json, 1, sizeof(json), file);

            if (n == 0) {
                printf("\033[0m\033[1;31mRead %s.json err:\033[0m file is empty\n",
                       c->name);
                ret++;
                continue;
            }

            json[n] = '\0';

            int result = c->test_change_to_mult(json);
            if (result) {
                printf("\033[0m\033[1;31m%s\033[0m test err!! num = %d\n",
                       c->name,
                       result);
                ret++;
            }
        }
        Change++;
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
