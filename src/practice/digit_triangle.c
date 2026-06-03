/* 画图题 — 数字三角形

题目描述
输入一个正整数 n（1 ≤ n ≤ 9），输出一个由数字 1~9 构成的等腰三角形。

输出由数字组成的等腰三角形，第一行 1 个数字，第二行 3 个数字，……，
第 n 行 2n-1 个数字。每个数字从 1 开始递增，到 9 之后回到 1 循环。
数字之间无空格，但每行前面有前导空格使三角形居中。

输入格式
一个正整数 n。

输出格式
等腰数字三角形。

样例
输入：
4

输出：
   1
  123
 12345
1234567

输入：
5

输出：
    1
   123
  12345
 1234567
123456789

提示
数字从 1 开始，依次递增输出，到 9 之后回到 1（不需要）。

*/


// 分析：
// 1.高度为输入值 h
// 2.宽度为 2h-1
// 3.前导空格为 h

#include <stdio.h>
int main(void) {
    // 输入高度
    int h;
    scanf("%d", &h);

    // 常量
    const int WIDTH = 2 * h - 1;

    // 随行数变化的量
    int total_num_count = 1;
    int space = (WIDTH - total_num_count) / 2;

    for (int line = 1; line <= h; line++) {
        // 每行初始化 1
        int number = 1;

        for (int i = 0; i < space; i++) printf(" "); // 输出前导空格
        for (int i = 0; i < total_num_count; i++) { // 输出数字
            // 超过 9 重置 1
            if (number > 9) number = 1;

            printf("%d", number);
            number++;
        }
        // 每一行输出完毕 换行。 变量迭代
        printf("\n");
        total_num_count++;
        total_num_count++;
        space--;
    }
    return 0;
}
