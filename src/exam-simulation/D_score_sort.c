/* 模拟卷 — Problem D: 分数排名 ⭐⭐⭐

题目描述
一次考试结束后，老师想统计班级的成绩情况。
请你帮忙统计：最高分、最低分、平均分（保留1位小数）。
并将所有分数从高到低输出排名。3

输入
多组数据，每组数据两行。
第一行一个整数 n（1 ≤ n ≤ 100），表示学生人数。
第二行 n 个整数，表示每个学生的成绩（0~100）。

输出
对于每组数据，输出三行：
第一行：Max:最高分
第二行：Min:最低分
第三行：Avg:平均分（保留1位小数）
第四行：从高到低的排名（逗号分隔，无空格）
每组输出之间有一个空行。

样例输入
5
88 92 76 92 85

样例输出
Max:92
Min:76
Avg:86.6
92,92,88,85,76

*/


// 数据范围在0-100，可以使用桶标记
#include <stdio.h>
int main(void) {
    int n;
    // 多组输入数据，输入数据量
    while (scanf("%d", &n) != EOF) {
        getchar();
        // 初始化桶
        int flag[105] = {0};
        int sum = 0;
        int count = 0;
        // 按照n输入
        for (int i = 0; i < n; i++) {
            int score;
            scanf("%d", &score);
            // 将分数暂时输入到score中
            // 将score存入桶
            flag[score]++;
            sum += score;
            count++;
        }
        // 输入结束，flag内部为从小到大下标出现次数
        // 令下标为 a，最大值和最小值就是不为零的前/后端


        double average = (double)sum / (double)count;
        int max;
        int min;
        // j为下标，从下标1开始，遇到第一个值不为0的下标，存入min
        // max同理
        for (int j = 0; j <= 100; j++) {
            if (flag[j] != 0) {
                min = j;
                break;
            }
        }
        for (int j = 100; j >= 0; j--) {
            if (flag[j] != 0) {
                max = j;
                break;
            }
        }

        // 记录完成，输出
        /*  对于每组数据，输出三行：
        第一行：Max:最高分
        第二行：Min:最低分
        第三行：Avg:平均分（保留1位小数）
        第四行：从高到低的排名（逗号分隔，无空格）
        每组输出之间有一个空行。*/
        printf("Max:%d\nMin:%d\nAvg:%.1lf\n", max, min, average);
        int first = 1;
        for (int j = 100; j >= 0; j--) {
            if (flag[j] != 0) { // 下标不为0，出现过，打印
                for (int k = 0; k < flag[j]; k++) {
                    if (!first) {
                        printf(",");
                    }
                    printf("%d", j);
                    first = 0;
                }

            }
        }
        printf("\n");
        printf("\n");   // 打印空行
    }
}
