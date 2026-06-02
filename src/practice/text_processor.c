/* P5734 【深基6.例6】文字处理软件

题目描述
你需要开发一款文字处理软件。初始时有一个字符串（不超过 100 个字符）。
然后有 q 次操作，每次操作有以下四种类型之一：

1 str：向字符串末尾插入字符串 str
2 a b：从第 a 个字符开始截取长度为 b 的字符串（字符串下标从 0 开始）
3 a str：在第 a 个字符后面插入字符串 str
4 str：查找子串 str 在字符串中第一次出现的位置（从 0 开始），没有则输出 -1

每次操作后，如果是类型 1、2、3，输出操作后的字符串；
如果是类型 4，输出查找结果。

输入格式
第一行一个正整数 q，表示操作次数。
第二行一个字符串，表示初始字符串。
接下来 q 行，每行一个操作。

输出格式
对于每个操作，按题目要求输出一行。

样例
输入：
5
ILove
1 Luogu
2 5 5
3 3 guG
4 Gu

输出：
ILoveLuogu
Luogu
LuoguGuGu
4

*/

#include <stdio.h>
#include <string.h>

int main(void) {

    // 输入处理次数
    int q;
    scanf("%d", &q);

    // 输入初始文档
    char str[125];
    scanf("%s", str);

    // 进行q次操作
    for (int i = 0; i < q; i++) {
        // 根据第一个数字进行操作
        int n;
        scanf("%d", &n);

        int a;
        int b;
        char new_str[125];

        switch (n) {
            case 1:
            scanf("%s", new_str);
            strcat(str, new_str);
            printf("%s\n", str);
            break;

            case 2:
            scanf("%d %d", &a, &b);
            for (int i = 0; i < b; i++) {
                new_str[i] = str[a+i];
            }
            new_str[b] = '\0';
            strcpy(str, new_str);
            printf("%s\n", str);
            break;

            case 3:
            scanf("%d %s", &a, new_str);
            char str1[125], str2[125];

            int i = 0;
            while (i < a) {
                str1[i] = str[i];
                i++;
            }
            str1[i] = '\0';

            int j = 0;
            while (i < strlen(str)) {
                str2[j] = str[i];
                j++;
                i++;
            }
            str2[j] = '\0';

            strcat(str1, new_str);
            strcat(str1, str2);
            strcpy(str, str1);
            printf("%s\n", str);
            break;

            case 4:
            scanf("%s", new_str);

            char *p = strstr(str, new_str);
            int pos;

            if (p == NULL) {
                pos = -1;
            }
            else {
                pos = p - str;
            }
            printf("%d\n", pos);
            break;

            default:
            break;
        }
    }
    return 0;
}
