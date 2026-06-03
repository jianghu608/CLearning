// 文章->行->单词

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        // 当前处于文章内了，先去掉上一个文章的\n
        getchar();
        // 准备记录整篇文章出现过的单词，出现次数，词汇量
        char words[5005][105];
        int count[5005];    // 并行记录
        int total = 0;
        // 现在进入行
        // 要逐行读取
        for (int i = 0; i < n; i++) {
            // 用line存行
            char line[205];
            fgets(line, 205, stdin);
            // 存到行了，去行内，读到\0结束
            //
            // 进入行内，准备记录单词
            char word[105];
            int idx = 0;
            for (int j = 0; line[j] != '\0'; j++) {
                // 令 c 为当前字符
                char c = line[j];
                // 判断是否为字母（是否构成单词）
                if (isalpha(c)) {
                    // 是字母，在字母内了，把字母存入单词
                    word[idx] = c;
                    idx++;
                } else { //不是字母，说明不在单词内，单词刚结束或者已经结束了，刚结束还要加\0，idx代表单词长度，为0就是没有单词
                    if (idx > 0) {
                        word[idx] = '\0';

                        // 记录好单词了，遍历数组查重
                        int found = 0;
                        for (int k = 0; k < total; k++) {   // 找，找到了标记一下
                            if (strcmp(words[k], word) == 0) {  // 存在了，计数+1即可
                                count[k]++;
                                found = 1;
                                break;
                            }
                        }
                        // 判断找没找到，没找到，计入词汇，初始化计数，词汇量+1
                        if (!found) {
                            strcpy(words[total], word);
                            count[total] = 1;
                            total++;
                        }
                        // 重置单词
                        idx = 0;
                    }
                }

            }
        }
        // 整篇文章都记完了，输出结果
        // 词汇量
        printf("Sum of words:%d\n", total);
        // 词汇统计
        for (int i = 0; i < total; i++) {
            printf("%s:%d\n", words[i], count[i]);
        }
    }

}
