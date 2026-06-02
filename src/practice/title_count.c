/* P5015 [NOIP2018 普及组] 标题统计

题目描述
凯凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？
注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。
统计标题字符数时，空格和换行符不计算在内。

输入格式
输入只有一行，一个字符串 s。

输出格式
输出一行，一个整数，即作文标题的字符数（不含空格和换行符）。

样例
输入：
Hello World
输出：
10

提示
|s| ≤ 5

*/

#include <stdio.h>
#include <string.h>

int count_string(char str[]);

int main(void) {
    char title[100];

    fgets(title, 100, stdin);
    printf("%d\n", count_string(title));

    return 0;
}

int count_string(char str[]) {
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if ((str[i] != ' ') && (str[i] != '\n')) {
            count++;
        }
        i++;
    }
    return count;
}

// 遍历字符串方式
// for 循环
// for (int i = 0; i < strlen(str); i++) {} 需#include <string.h>
//
// while 循环
// int i = 0;
// while (str[i] != '\0') ...
