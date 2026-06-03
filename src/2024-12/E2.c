/* 2024-12 浙工大转专业机考 — Problem E: 分析文章

题目描述
Alex接到了一个给英文文章分级的任务：统计文章的实际词汇量（即不重复的单词数量），
并按出现顺序列出构成文章的所有词汇清单和出现的次数。

输入
多组数据，每组第一行给出文章的行数 N（1 ≤ N ≤ 30）。
随后 N 行文章内容，每行由空格分隔的若干单词和标点符号构成。
每行不超过 200 个字符。
单词仅由连续的大小写字母构成，如 I'm 当成 I 和 m 两个单词。
每篇文章至少包含 1 个单词，不超过 5000 个单词。

输出
第一行给出词汇量，第二行开始按出现顺序列出单词和出现次数。

样例输入
2
I love my home town.
I think she will  become better and better in the future.
1
!Let's*go!!!

样例输出
Sum of words:14
I:2
love:1
my:1
home:1
town:1
think:1
she:1
will:1
become:1
better:2
and:1
in:1
the:1
future:1
Sum of words:3
Let:1
s:1
go:1

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
2
I love my home town.
I think she will  become better and better in the future.
*/
int main(void) {
    int n;  // 行数


    while (scanf("%d", &n) != 0) {
        getchar();

        // 一篇文章所需的变量
        char words[5005][105];
        int count[5005] = {0};
        int total = 0;

        // 逐行读取
        for (int i = 0; i < n; i++) {
            // 读取行，存入line，以\0结束
            char line[205];
            fgets(line , 205, stdin);

            // 逐个字符遍历
            for (int j = 0; line[j] != '\0'; j++) {
                char word[205];
                int idx = 0;    // word的index
                char c = line[j];

                if (isalpha(c)) {
                    word[idx] = c;
                    idx++;
                } else {
                    if (idx > 0) {
                        word[idx] = '\0';

                        int found = 0;
                        for (int k = 0; k < total; k++) {
                            if (strcmp(words[k], word) == 0) {
                                found = 1;
                                count[k]++;
                                break;
                            }
                        }

                        if (!found) {
                            strcpy(words[total], word);
                            count[total] = 1;
                            total++;
                        }

                        idx = 0;
                    }
                }


            }
        }


    }


}
