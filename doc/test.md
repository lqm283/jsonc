<!--
 * @Author       : lqm283
 * @Date         : 2023-01-06 08:56:26
 * @LastEditTime : 2023-01-07 17:31:09
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /jsonc/doc/test.md
-->

# 基本类型

## 基本常规类型

### char 类型

#### char 单成员保存 Str

```c
struct TestNonNonSingleCharStr {
    char str;
};
INIT(TestNonNonSingleCharStr,
     struct TestNonNonSingleCharStr,
     MEM(struct TestNonNonSingleCharStr, Str, char, str, NULL));
```

1. 单成员的 char 转换为 Str 类型的 json

   ```c
    char* test_change_non_non_single_char_str_to_json(char* exp, char* real);
   ```

2. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_chang_single_str_json_to_non_non_single_char_str(char* json);
   ```

3. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_chang_mult_str_json_to_non_non_single_char_str(char* json);
   ```

4. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_chang_single_num_json_to_non_non_single_char_str(char* json);
   ```

5. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_chang_mult_num_json_to_non_non_single_char_str(char* json);
   ```

#### char 单成员数字

```c
struct TestNonNonSingleCharNum {
    char num;
};
INIT(TestNonNonSingleCharNum,
     struct TestNonNonSingleCharNum,
     MEM(struct TestNonNonSingleCharNum, Num, char, num, NULL));
```

1. 单成员的 char 转换为 Num 类型的 json

   ```c
    char* test_change_non_non_single_char_num_to_json(char* exp, char* real);
   ```

2. 单元素的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_chang_single_json_to_non_non_single_char_num(char* json);
   ```

3. 多元素的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_chang_mult_json_to_non_non_single_char_num(char* json);
   ```

#### char 单成员布尔值

#### char 单成员空值

#### char 多成员字符串

#### char 多成员数字

#### char 多成员布尔值

#### char 多成员空值

### unsigned char 类型

#### unsigned char 单成员字符串

#### unsigned char 单成员数字

#### unsigned char 单成员布尔值

#### unsigned char 单成员空值

#### unsigned char 多成员字符串

#### unsigned char 多成员数字

#### unsigned char 多成员布尔值

#### unsigned char 多成员空值

## 基本数组类型

## 基本指针类型
