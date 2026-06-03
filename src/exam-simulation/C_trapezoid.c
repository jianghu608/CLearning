/* 模拟卷 — Problem C: 空心梯形 ⭐⭐⭐

题目描述
输入梯形的上底长度、下底长度和一个字符，
用该字符画出空心梯形。

梯形规则：
第 1 行是上底，每行比上一行多 2 个字符，直到下底。
第 1 行和最后一行全部是字符（实心），
中间行只有两端有字符（空心），中间是空格。

输入
多组输入，每组包含两个整数 up、down 和一个字符 ch。
3 ≤ up < down ≤ 30，up 和 down 都是奇数。

输出
用字符 ch 构成空心梯形，行末回车。
每组输出之间有一个空行。

样例输入
3 7 #

样例输出
  ###
 #   #
#######

解释（up=3, down=7，字符 #）：
总行数 = (7-3)/2 + 1 = 3
行1（上底）：前导空格2 + ###（3个字符，实心）
行2（空心）：前导空格1 + # + 空格3 + #（两端有字符）
行3（下底）：前导空格0 + #######（7个字符，实心）

*/
#include <stdio.h>
int main(void) {

    int up, down;
    char ch;
    int h;
    while (scanf("%d %d %c", &up, &down, &ch) != EOF) {
        getchar();
        int width = down;
        h = (down - up) / 2 + 1;

        // 开始逐行打印
        for (int i = 0; i < h; i++) {
            int line = i + 1;
            int front_space = (width - up) / 2 - i;
            int center_space = width - 2 * (1 + front_space);
            if (line == 1) {
                for (int j = 0; j < front_space; j++) printf(" ");
                for (int j = 0; j < up; j++) printf("%c", ch);
                printf("\n");
            }
            else if (line == h) {
                for (int j = 0; j < down; j++) printf("%c", ch);
                printf("\n");
            }
            else {
                for (int j = 0; j < front_space; j++) printf(" ");
                printf("%c", ch);
                for (int j = 0; j < center_space; j++) printf(" ");
                printf("%c\n", ch);
            }
        }
        printf("\n");
    }
    return 0;
}
