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
#include <string.h>
#include <ctype.h>   // 提供 isalpha() 和 tolower()

int main(void) {
    /*
     * 核心思路：
     * 逐字符遍历文章，遇到字母就拼到当前单词里，
     * 遇到非字母（空格、标点、换行）就说明单词结束了，
     * 把拼好的单词拿去查重，没出现过就新增，出现过就次数+1。
     */

    int n;                     // 文章的行数
    char line[205];            // 存储一行文章（最多200字符 + 结尾\0）

    // words 和 count 一一对应，words[k] 是第 k 个单词，count[k] 是它出现的次数
    char words[5005][105];     // 存放所有不重复的单词（最多5000个，每个最长100字符）
    int  count[5005] = {0};    // 每个单词出现了几次
    int  total;                // 不重复单词的总数

    // ========== 第1步：多组数据输入 ==========
    // 每篇文章先给一个行数 n，读到 EOF 表示所有文章都处理完了
    while (scanf("%d", &n) != EOF) {

        // getchar() 吃掉 scanf 留在缓冲区里的换行符
        // 如果没有这一行，下面的 fgets 会先读到一个空行
        getchar();

        // 每开始一篇新文章，单词表要重置
        total = 0;

        // ========== 第2步：逐行读取文章 ==========
        for (int i = 0; i < n; i++) {

            // fgets 读到换行就停，把一整行存进 line 里
            fgets(line, 205, stdin);

            // word 是"临时缓冲区"，用来拼当前正在读的这个单词
            char word[105];
            int idx = 0;       // idx 指向 word 中下一个要写入的位置

            // ========== 第3步：逐字符遍历这一行 ==========
            // line[j] 是当前正在看的字符，'\0' 表示字符串结束
            for (int j = 0; line[j] != '\0'; j++) {

                char c = line[j];    // 当前字符，方便书写

                // ========== 第4步：判断这个字符是不是字母 ==========
                if (isalpha(c)) {
                    // 是字母 → 拼到当前单词里
                    // 统一转小写：这样 "The" 和 "the" 算同一个单词
                    word[idx] = tolower(c);
                    idx++;           // 指向下一个空位
                } else {
                    // 不是字母（空格、标点、换行）→ 说明单词结束了

                    // idx > 0 说明 word 里确实拼了一个单词
                    // idx == 0 说明连续遇到了多个非字母（比如多个空格），忽略
                    if (idx > 0) {

                        // 在 word 末尾加 \0，让它变成一个真正的 C 字符串
                        word[idx] = '\0';

                        // ========== 第5步：查重 ==========
                        // 在 words 数组里找，有没有和 word 一样的
                        int found = 0;
                        for (int k = 0; k < total; k++) {
                            // strcmp 比较两个字符串，相等返回 0
                            if (strcmp(words[k], word) == 0) {
                                // 找到了 → 计数 +1
                                count[k]++;
                                found = 1;       // 标记已找到
                                break;           // 不用继续找了
                            }
                        }

                        // ========== 第6步：没出现过就新增 ==========
                        if (found == 0) {
                            // strcpy 把 word 复制到 words[total]
                            strcpy(words[total], word);
                            count[total] = 1;    // 第一次出现，次数为1
                            total++;             // 单词总数 +1
                        }

                        // ========== 第7步：重置，准备拼下一个单词 ==========
                        idx = 0;
                    }
                    // 如果 idx == 0，说明是连续的非字母，什么都不做
                }
            }
            // 这一行处理完了，继续下一行
        }

        // ========== 第8步：输出结果 ==========
        printf("Sum of words:%d\n", total);
        for (int i = 0; i < total; i++) {
            printf("%s:%d\n", words[i], count[i]);
        }
    }

    return 0;
}
