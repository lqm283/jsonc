<!--
 * @Author       : lqm283
 * @Date         : 2023-01-06 08:56:26
 * @LastEditTime : 2023-01-08 18:55:23
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

##### char单成员 Str 转换为 json

1. 单成员的 char 转换为 Str 类型的 json

   ```c
    char* test_change_non_non_single_char_str_to_json(char* exp, char* real);
   ```

##### json 转换为 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_single_str_json_to_non_non_single_char_str(char* json);
   ```

2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_mult_str_json_to_non_non_single_char_str(char* json);
   ```

3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_single_num_json_to_non_non_single_char_str(char* json);
   ```

4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_mult_num_json_to_non_non_single_char_str(char* json);
   ```

5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_single_bool_json_to_non_non_single_char_str(char* json);
   ```

6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_mult_bool_json_to_non_non_single_char_str(char* json);
   ```

7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_single_null_json_to_non_non_single_char_str(char* json);
   ```

8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 char

   ```c
    int test_change_mult_null_json_to_non_non_single_char_str(char* json);
   ```

#### char 单成员保存 num

```c
struct TestNonNonSingleCharNum {
    char num;
};
INIT(TestNonNonSingleCharNum,
     struct TestNonNonSingleCharNum,
     MEM(struct TestNonNonSingleCharNum, Num, char, num, NULL));
```

##### char单成员 Num 转换为 json

1. 单成员的 char 转换为 Num 类型的 json

   ```c
    char* test_change_non_non_single_char_num_to_json(char* exp, char* real);
   ```

##### json 转换为 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_single_str_json_to_non_non_single_char_num(char* json);
   ```

2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_mult_str_json_to_non_non_single_char_num(char* json);
   ```

3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_single_num_json_to_non_non_single_char_num(char* json);
   ```

4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_mult_num_json_to_non_non_single_char_num(char* json);
   ```

#### char 单成员布尔值

#### char 多成员字符串

#### char 多成员数字

#### char 多成员布尔值

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
