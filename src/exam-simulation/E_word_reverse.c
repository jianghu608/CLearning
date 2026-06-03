/* 模拟卷 — Problem E: 单词反转 ⭐⭐⭐⭐

题目描述
输入一段英文文章，将文章中的每个单词反转，但保留单词的顺序
和文章中的空格、标点符号不变。

单词由连续的字母构成，遇到非字母字符即视为单词结束。
标点符号和空格保留原位置。

例如 "hello world" 反转单词后变成 "olleh dlrow"。
"I'm a student." 中 I 和 m 是两个单词，分别反转。

输入
多组数据，每组数据第一行一个整数 n（1 ≤ n ≤ 10），
表示文章的行数。
随后 n 行，每行一个不超过 200 字符的字符串，表示文章内容。

输出
对于每组数据，输出反转后的文章。每组输出之间空一行。

样例输入
2
I love ZJUT.
I love Shang 9.
1
Hello!

样例输出
I evol TUJZ.

olleH!

*/

// 逐行逐字符读取，遇到不是字母的直接打印，遇到字母组成单词再打印
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // 读取行数，多组数据输入
    int n;
    while (scanf("%d", &n) != EOF) {
        getchar();
        // 文章开始，初始化所需变量
        char word[105]; // 单个单词
        int idx = 0;

        // 逐行读取
        char line[205];
        for (int i = 0; i < n; i++) {
            fgets(line, 205, stdin);    // 读入一行的字符串，以\0结束
            // 进入行内，逐字读取
            char c;
            for (int j = 0; line[j] != '\0'; j++) {
                // 已经进入行内了
                c = line[j]; // 读到字符，判断类型
                if (isalpha(c)) {
                    // 是字母，记录单词
                    word[idx] = c;
                    idx++;
                }
                else {
                    // 不是字母
                    // 判断是否刚读完单词
                    if (idx != 0) {
                        // 刚读完
                        // 先输出反转单词，再输出字符
                        word[idx] = '\0';       // 这个有用吗？
                        for (int k = idx-1; k >= 0; k--) {  // 逐字符反转输出
                            printf("%c", word[k]);
                        }   // 单词输出完毕，重置单词
                        idx = 0;
                        // 输出字符
                        printf("%c", c);
                    }
                    else {
                        // 是连续的字符，直接输出
                        printf("%c", c);
                    }
                }
            // 一行处理完毕
            }

        }   // 所有行处理完毕，文章处理完毕，打印空行
        printf("\n");
    }
}
