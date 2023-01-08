<!--
 * @Author       : lqm283
 * @Date         : 2023-01-06 08:56:26
 * @LastEditTime : 2023-01-08 23:31:53
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

##### char 单成员 Str 转换为 json

```c
char* test_change_non_non_single_char_str_to_json(char* exp, char* real);
```

##### json 转换为 char 单成员 str

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

##### char 单成员 Num 转换为 json

```c
char* test_change_non_non_single_char_num_to_json(char* exp, char* real);
```

##### json 转换为 char 单成员 Num

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

5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_single_bool_json_to_non_non_single_char_num(char* json);
   ```

6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_mult_bool_json_to_non_non_single_char_num(char* json);
   ```

7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_single_null_json_to_non_non_single_char_num(char* json);
   ```

8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 char

   ```c
    int test_change_mult_null_json_to_non_non_single_char_num(char* json);
   ```

#### char 单成员保存 bool

```c
struct TestNonNonSingleCharBool {
    char b;
};
INIT(TestNonNonSingleCharBool,
     struct TestNonNonSingleCharBool,
     MEM(struct TestNonNonSingleCharBool, Bool, char, b, NULL));
```

##### char 单成员 Bool 转换为 json

```c
char* test_change_non_non_single_char_bool_to_json(char* exp, char* real);
```

##### json 转换为 char 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_single_str_json_to_non_non_single_char_bool(char* json);
   ```

2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_mult_str_json_to_non_non_single_char_bool(char* json);
   ```

3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_single_num_json_to_non_non_single_char_bool(char* json);
   ```

4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_mult_num_json_to_non_non_single_char_bool(char* json);
   ```

5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_single_bool_json_to_non_non_single_char_bool(char* json);
   ```

6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_mult_bool_json_to_non_non_single_char_bool(char* json);
   ```

7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_single_null_json_to_non_non_single_char_bool(char* json);
   ```

8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 char

   ```c
    int test_change_mult_null_json_to_non_non_single_char_bool(char* json);
   ```

#### char 多成员保存 Str

```c
struct TestNonNonMultCharStr {
    char str1;
    char str2;
    char str3;
};
INIT(TestNonNonMultCharStr,
     struct TestNonNonMultCharStr,
     MEM(struct TestNonNonMultCharStr, Str, char, str1, NULL),
     MEM(struct TestNonNonMultCharStr, Str, char, str2, NULL),
     MEM(struct TestNonNonMultCharStr, Str, char, str3, NULL));
```

##### char 多成员 Str 转换为 json

```c
char* test_change_non_non_mult_char_str_to_json(char* exp, char* real);
```

##### json 转换为 char 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_equal_mult_str_json_to_non_non_mult_char_str(char* json);
   ```

2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_more_mult_str_json_to_non_non_mult_char_str(char* json);
   ```

3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_less_mult_str_json_to_non_non_mult_char_str(char* json);
   ```

4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_diff_mult_str_json_to_non_non_mult_char_str(char* json);
   ```

5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_equal_mult_num_json_to_non_non_mult_char_str(char* json);
   ```

6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_more_mult_num_json_to_non_non_mult_char_str(char* json);
   ```

7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_less_mult_num_json_to_non_non_mult_char_str(char* json);
   ```

8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_diff_mult_num_json_to_non_non_mult_char_str(char* json);
   ```

9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_equal_mult_bool_json_to_non_non_mult_char_str(char* json);
   ```

10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_more_mult_bool_json_to_non_non_mult_char_str(char* json);
    ```

11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_less_mult_bool_json_to_non_non_mult_char_str(char* json);
    ```

12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_diff_mult_bool_json_to_non_non_mult_char_str(char* json);
    ```

13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_equal_mult_null_json_to_non_non_mult_char_str(char* json);
    ```

14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_more_mult_null_json_to_non_non_mult_char_str(char* json);
    ```

15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char

    ```c
    int test_change_less_mult_null_json_to_non_non_mult_char_str(char* json);
    ```

16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 char

#### char 多成员保存 Num

##### char 多成员 Num 转换为 json

##### json 转换为 char 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 char
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 char
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 char
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 char

#### char 多成员保存 Bool

##### char 多成员 Bool 转换为 json

##### json 转换为 char 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 char
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 char
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 char
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 char
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 char
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 char
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 char
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 char
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 char
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 char
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 char
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 char
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 char

### uint8 类型

#### uint8 单成员保存 Str

##### uint8 单成员 Str 转换为 json

##### json 转换为 uint8 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint8
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint8
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint8
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint8
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint8
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint8
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint8
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint8

#### uint8 单成员保存 num

##### uint8 单成员 Num 转换为 json

##### json 转换为 uint8 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint8
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint8
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint8
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint8
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint8
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint8
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint8
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint8

#### uint8 单成员保存 bool

##### uint8 单成员 Bool 转换为 json

##### json 转换为 uint8 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint8
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint8
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint8
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint8
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint8
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint8
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint8
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint8

#### uint8 多成员保存 Str

##### uint8 多成员 Str 转换为 json

##### json 转换为 uint8 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint8
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint8
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint8
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint8
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint8
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint8
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint8
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint8
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint8
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint8
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint8
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint8
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint8
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint8
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint8
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint8

#### uint8 多成员保存 Num

##### uint8 多成员 Num 转换为 json

##### json 转换为 uint8 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint8
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint8
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint8
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint8
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint8
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint8
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint8
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint8
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint8
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint8
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint8
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint8
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint8
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint8
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint8
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint8

#### uint8 多成员保存 Bool

##### uint8 多成员 Bool 转换为 json

##### json 转换为 uint8 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint8
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint8
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint8
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint8
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint8
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint8
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint8
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint8
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint8
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint8
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint8
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint8
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint8
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint8
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint8
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint8

### int16 类型

#### int16 单成员保存 Str

##### int16 单成员 Str 转换为 json

##### json 转换为 int16 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 int16
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 int16
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 int16
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 int16
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 int16
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 int16
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 int16
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 int16

#### int16 单成员保存 num

##### int16 单成员 Num 转换为 json

##### json 转换为 int16 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 int16
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 int16
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 int16
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 int16
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 int16
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 int16
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 int16
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 int16

#### int16 单成员保存 bool

##### int16 单成员 Bool 转换为 json

##### json 转换为 int16 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 int16
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 int16
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 int16
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 int16
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 int16
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 int16
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 int16
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 int16

#### int16 多成员保存 Str

##### int16 多成员 Str 转换为 json

##### json 转换为 int16 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int16
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int16
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int16
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int16
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int16
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int16
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int16
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int16
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int16
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int16
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int16
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int16
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int16
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int16
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int16
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int16

#### int16 多成员保存 Num

##### int16 多成员 Num 转换为 json

##### json 转换为 int16 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int16
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int16
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int16
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int16
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int16
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int16
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int16
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int16
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int16
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int16
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int16
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int16
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int16
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int16
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int16
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int16

#### int16 多成员保存 Bool

##### int16 多成员 Bool 转换为 json

##### json 转换为 int16 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int16
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int16
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int16
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int16
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int16
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int16
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int16
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int16
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int16
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int16
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int16
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int16
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int16
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int16
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int16
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int16

### uint16 类型

#### uint16 单成员保存 Str

##### uint16 单成员 Str 转换为 json

##### json 转换为 uint16 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint16
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint16
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint16
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint16
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint16
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint16
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint16
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint16

#### uint16 单成员保存 num

##### uint16 单成员 Num 转换为 json

##### json 转换为 uint16 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint16
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint16
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint16
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint16
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint16
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint16
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint16
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint16

#### uint16 单成员保存 bool

##### uint16 单成员 Bool 转换为 json

##### json 转换为 uint16 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint16
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint16
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint16
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint16
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint16
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint16
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint16
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint16

#### uint16 多成员保存 Str

##### uint16 多成员 Str 转换为 json

##### json 转换为 uint16 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint16
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint16
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint16
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint16
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint16
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint16
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint16
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint16
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint16
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint16
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint16
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint16
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint16
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint16
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint16
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint16

#### uint16 多成员保存 Num

##### uint16 多成员 Num 转换为 json

##### json 转换为 uint16 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint16
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint16
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint16
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint16
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint16
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint16
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint16
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint16
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint16
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint16
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint16
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint16
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint16
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint16
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint16
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint16

#### uint16 多成员保存 Bool

##### uint16 多成员 Bool 转换为 json

##### json 转换为 uint16 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint16
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint16
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint16
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint16
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint16
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint16
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint16
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint16
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint16
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint16
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint16
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint16
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint16
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint16
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint16
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint16

### int32 类型

#### int32 单成员保存 Str

##### int32 单成员 Str 转换为 json

##### json 转换为 int32 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 int32
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 int32
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 int32
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 int32
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 int32
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 int32
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 int32
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 int32

#### int32 单成员保存 num

##### int32 单成员 Num 转换为 json

##### json 转换为 int32 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 int32
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 int32
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 int32
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 int32
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 int32
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 int32
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 int32
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 int32

#### int32 单成员保存 bool

##### int32 单成员 Bool 转换为 json

##### json 转换为 int32 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 int32
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 int32
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 int32
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 int32
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 int32
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 int32
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 int32
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 int32

#### int32 多成员保存 Str

##### int32 多成员 Str 转换为 json

##### json 转换为 int32 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int32
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int32
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int32
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int32
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int32
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int32
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int32
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int32
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int32
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int32
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int32
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int32
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int32
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int32
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int32
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int32

#### int32 多成员保存 Num

##### int32 多成员 Num 转换为 json

##### json 转换为 int32 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int32
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int32
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int32
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int32
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int32
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int32
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int32
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int32
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int32
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int32
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int32
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int32
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int32
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int32
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int32
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int32

#### int32 多成员保存 Bool

##### int32 多成员 Bool 转换为 json

##### json 转换为 int32 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int32
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int32
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int32
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int32
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int32
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int32
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int32
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int32
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int32
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int32
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int32
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int32
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int32
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int32
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int32
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int32

### uint32 类型

#### uint32 单成员保存 Str

##### uint32 单成员 Str 转换为 json

##### json 转换为 uint32 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint32
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint32
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint32
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint32
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint32
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint32
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint32
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint32

#### uint32 单成员保存 num

##### uint32 单成员 Num 转换为 json

##### json 转换为 uint32 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint32
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint32
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint32
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint32
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint32
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint32
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint32
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint32

#### uint32 单成员保存 bool

##### uint32 单成员 Bool 转换为 json

##### json 转换为 uint32 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint32
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint32
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint32
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint32
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint32
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint32
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint32
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint32

#### uint32 多成员保存 Str

##### uint32 多成员 Str 转换为 json

##### json 转换为 uint32 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint32
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint32
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint32
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint32
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint32
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint32
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint32
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint32
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint32
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint32
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint32
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint32
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint32
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint32
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint32
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint32

#### uint32 多成员保存 Num

##### uint32 多成员 Num 转换为 json

##### json 转换为 uint32 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint32
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint32
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint32
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint32
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint32
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint32
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint32
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint32
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint32
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint32
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint32
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint32
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint32
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint32
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint32
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint32

#### uint32 多成员保存 Bool

##### uint32 多成员 Bool 转换为 json

##### json 转换为 uint32 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint32
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint32
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint32
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint32
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint32
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint32
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint32
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint32
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint32
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint32
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint32
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint32
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint32
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint32
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint32
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint32

### int64 类型

#### int64 单成员保存 Str

##### int64 单成员 Str 转换为 json

##### json 转换为 int64 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 int64
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 int64
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 int64
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 int64
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 int64
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 int64
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 int64
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 int64

#### int64 单成员保存 num

##### int64 单成员 Num 转换为 json

##### json 转换为 int64 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 int64
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 int64
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 int64
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 int64
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 int64
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 int64
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 int64
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 int64

#### int64 单成员保存 bool

##### int64 单成员 Bool 转换为 json

##### json 转换为 int64 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 int64
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 int64
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 int64
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 int64
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 int64
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 int64
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 int64
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 int64

#### int64 多成员保存 Str

##### int64 多成员 Str 转换为 json

##### json 转换为 int64 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int64
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int64
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int64
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 int64
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int64
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int64
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int64
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 int64
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int64
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int64
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int64
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 int64
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int64
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int64
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int64
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 int64

#### int64 多成员保存 Num

##### int64 多成员 Num 转换为 json

##### json 转换为 int64 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int64
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int64
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int64
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 int64
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int64
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int64
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int64
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 int64
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int64
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int64
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int64
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 int64
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int64
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int64
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int64
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 int64

#### int64 多成员保存 Bool

##### int64 多成员 Bool 转换为 json

##### json 转换为 int64 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int64
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int64
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int64
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 int64
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int64
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int64
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int64
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 int64
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int64
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int64
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int64
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 int64
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int64
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int64
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int64
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 int64

### uint64 类型

#### uint64 单成员保存 Str

##### uint64 单成员 Str 转换为 json

##### json 转换为 uint64 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint64
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 uint64
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint64
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 uint64
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint64
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 uint64
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint64
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 uint64

#### uint64 单成员保存 num

##### uint64 单成员 Num 转换为 json

##### json 转换为 uint64 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint64
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 uint64
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint64
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 uint64
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint64
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 uint64
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint64
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 uint64

#### uint64 单成员保存 bool

##### uint64 单成员 Bool 转换为 json

##### json 转换为 uint64 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint64
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 uint64
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint64
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 uint64
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint64
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 uint64
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint64
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 uint64

#### uint64 多成员保存 Str

##### uint64 多成员 Str 转换为 json

##### json 转换为 uint64 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint64
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint64
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint64
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 uint64
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint64
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint64
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint64
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 uint64
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint64
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint64
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint64
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 uint64
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint64
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint64
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint64
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 uint64

#### uint64 多成员保存 Num

##### uint64 多成员 Num 转换为 json

##### json 转换为 uint64 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint64
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint64
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint64
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 uint64
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint64
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint64
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint64
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 uint64
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint64
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint64
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint64
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 uint64
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint64
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint64
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint64
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 uint64

#### uint64 多成员保存 Bool

##### uint64 多成员 Bool 转换为 json

##### json 转换为 uint64 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint64
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint64
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint64
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 uint64
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint64
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint64
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint64
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 uint64
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint64
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint64
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint64
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 uint64
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint64
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint64
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint64
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 uint64

### float 类型

#### float 单成员保存 Str

##### float 单成员 Str 转换为 json

##### json 转换为 float 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 float
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 float
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 float
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 float
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 float
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 float
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 float
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 float

#### float 单成员保存 num

##### float 单成员 Num 转换为 json

##### json 转换为 float 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 float
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 float
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 float
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 float
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 float
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 float
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 float
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 float

#### float 单成员保存 bool

##### float 单成员 Bool 转换为 json

##### json 转换为 float 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 float
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 float
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 float
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 float
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 float
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 float
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 float
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 float

#### float 多成员保存 Str

##### float 多成员 Str 转换为 json

##### json 转换为 float 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 float
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 float
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 float
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 float
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 float
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 float
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 float
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 float
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 float
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 float
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 float
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 float
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 float
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 float
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 float
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 float

#### float 多成员保存 Num

##### float 多成员 Num 转换为 json

##### json 转换为 float 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 float
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 float
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 float
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 float
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 float
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 float
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 float
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 float
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 float
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 float
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 float
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 float
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 float
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 float
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 float
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 float

#### float 多成员保存 Bool

##### float 多成员 Bool 转换为 json

##### json 转换为 float 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 float
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 float
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 float
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 float
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 float
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 float
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 float
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 float
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 float
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 float
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 float
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 float
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 float
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 float
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 float
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 float

### double 类型

#### double 单成员保存 Str

##### double 单成员 Str 转换为 json

##### json 转换为 double 单成员 str

1. 单元素 Str 类型的 json 转换为保存 Str 类型的单成员 double
2. 多元素 Str 类型的 json 转换为保存 Str 类型的单成员 double
3. 单元素 Num 类型的 json 转换为保存 Str 类型的单成员 double
4. 多元素 Num 类型的 json 转换为保存 Str 类型的单成员 double
5. 单元素 Bool 类型的 json 转换为保存 Str 类型的单成员 double
6. 多元素 Bool 类型的 json 转换为保存 Str 类型的单成员 double
7. 单元素 Null 类型的 json 转换为保存 Str 类型的单成员 double
8. 多元素 Null 类型的 json 转换为保存 Str 类型的单成员 double

#### double 单成员保存 num

##### double 单成员 Num 转换为 json

##### json 转换为 double 单成员 Num

1. 单元素 Str 类型的 json 转换为保存 Num 类型的单成员 double
2. 多元素 Str 类型的 json 转换为保存 Num 类型的单成员 double
3. 单元素 Num 类型的 json 转换为保存 Num 类型的单成员 double
4. 多元素 Num 类型的 json 转换为保存 Num 类型的单成员 double
5. 单元素 Bool 类型的 json 转换为保存 Num 类型的单成员 double
6. 多元素 Bool 类型的 json 转换为保存 Num 类型的单成员 double
7. 单元素 Null 类型的 json 转换为保存 Num 类型的单成员 double
8. 多元素 Null 类型的 json 转换为保存 Num 类型的单成员 double

#### double 单成员保存 bool

##### double 单成员 Bool 转换为 json

##### json 转换为 double 单成员 Bool

1. 单元素 Str 类型的 json 转换为保存 Bool 类型的单成员 double
2. 多元素 Str 类型的 json 转换为保存 Bool 类型的单成员 double
3. 单元素 Num 类型的 json 转换为保存 Bool 类型的单成员 double
4. 多元素 Num 类型的 json 转换为保存 Bool 类型的单成员 double
5. 单元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 double
6. 多元素 Bool 类型的 json 转换为保存 Bool 类型的单成员 double
7. 单元素 Null 类型的 json 转换为保存 Bool 类型的单成员 double
8. 多元素 Null 类型的 json 转换为保存 Bool 类型的单成员 double

#### double 多成员保存 Str

##### double 多成员 Str 转换为 json

##### json 转换为 double 多成员 Str

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 double
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 double
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 double
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Str 类型的多成员 double
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 double
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 double
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 double
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Str 类型的多成员 double
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 double
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 double
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 double
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Str 类型的多成员 double
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 double
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 double
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 double
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Str 类型的多成员 double

#### double 多成员保存 Num

##### double 多成员 Num 转换为 json

##### json 转换为 double 多成员 Num

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 double
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 double
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 double
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Num 类型的多成员 double
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 double
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 double
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 double
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Num 类型的多成员 double
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 double
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 double
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 double
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Num 类型的多成员 double
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 double
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 double
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 double
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Num 类型的多成员 double

#### double 多成员保存 Bool

##### double 多成员 Bool 转换为 json

##### json 转换为 double 多成员 Bool

1. 完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 double
2. 元素多于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 double
3. 元素少于成员的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 double
4. 不完全匹配的多元素 Str 类型的 json 转换为保存 Bool 类型的多成员 double
5. 完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 double
6. 元素多于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 double
7. 元素少于成员的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 double
8. 不完全匹配的多元素 Num 类型的 json 转换为保存 Bool 类型的多成员 double
9. 完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 double
10. 元素多于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 double
11. 元素少于成员的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 double
12. 不完全匹配的多元素 Bool 类型的 json 转换为保存 Bool 类型的多成员 double
13. 完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 double
14. 元素多于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 double
15. 元素少于成员的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 double
16. 不完全匹配的多元素 Null 类型的 json 转换为保存 Bool 类型的多成员 double

## 基本数组类型

## 基本指针类型
