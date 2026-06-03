/* 2024-12 浙工大转专业机考 — Problem C: 画字母M

题目描述
小M想用计算机画自己的名字M，现在请你来帮达成这个心愿吧！

输入
多组数据输入，每组数据给出M的高度值 H 和构成的字符。

输出
输出由给定字符构成的字母 M 形状。

（注：原文样例被截断，以下规律是根据常见 M 形状推导的，如果不对请按实际题目调整）

规律分析（以 H=5，字符 * 为例）：
M 由 4 条线构成：左竖线、右竖线、左内斜线、右内斜线

总宽度 = 2 * H - 1

第 i 行（i 从 0 到 H-1）输出的位置：
  左竖线：位置 0
  右竖线：位置 2*H-2
  左内斜线：位置 H-1-i    （从底部中间到顶部左上）
  右内斜线：位置 H-1+i    （从底部中间到顶部右上）

H=5 时：
  i=0: 0,4,8     → *   *   *
  i=1: 0,3,5,8   → *  * *  *
  i=2: 0,2,6,8   → * *   * *
  i=3: 0,1,7,8   → **     **
  i=4: 0,8       → *       *

样例：
4
5

**   **
* * * *
*  *  *
*     *
**     **
* *   * *
*  * *  *
*   *   *
*       *

*/

#include <stdio.h>

int main(void) {
    // 多组高度输入
    int height;
    while(scanf("%d", &height) != EOF) {
        int width = height * 2 - 1;

        int center_space = width - 4;
        int side_space = 0;

        // 前 height-2 行
        for (int line = 1; line <= height-2; line++) {
            printf("*");
            for (int i =0; i < side_space; i++) printf(" ");
            printf("*");
            for (int i =0; i < center_space; i++) printf(" ");
            printf("*");
            for (int i =0; i < side_space; i++) printf(" ");
            printf("*");
            printf("\n");


            side_space++;
            center_space--;
            center_space--;
        }

        // 最后两行
        center_space--;
        printf("*");
        for (int i =0; i < side_space; i++) printf(" ");
        printf("*");
        for (int i =0; i < side_space; i++) printf(" ");
        printf("*");
        printf("\n");

        // 最后一行
        center_space = width - 2;
        printf("*");
        for (int i =0; i < center_space; i++) printf(" ");
        printf("*");
        printf("\n");
    }
    return 0;
}
