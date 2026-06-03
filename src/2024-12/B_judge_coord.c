/* 2024-12 浙工大转专业机考 — Problem B: 判断坐标

题目描述
整数直角坐标系中的一个位置被描述为由横坐标和纵坐标构成的一对值，
可以使用(x,y)这样的形式描述。横纵坐标将直角坐标系分隔为7个不相交的部分，
包括：第1象限，第2象限，第3象限，第4象限，x轴，y轴和原点。
请你根据给定的坐标值判断位于直角坐标系的哪个部分？

7个部分分别表示如下：
(1) 第1象限: First quadrant
(2) 第2象限: Second quadrant
(3) 第3象限: Third quadrant
(4) 第4象限: Forth quadrant
(5) x轴: X axis
(6) y轴: Y axis
(7) 原点: Origin

输入
多组数据，每组数据一行，由一个坐标值构成，描述为(x,y)。
横纵坐标分别用逗号分隔，可能会使用 +/- 符号，无多余空格，
使用圆括号标记为一组。所有坐标值均不超过 int 范围。

输出
对应每组输入，输出一行描述对应坐标位于直角坐标系的哪个部分。
行末直接回车。

样例输入
(3,+3)
(-1,0)
(0,-0)

样例输出
First quadrant
X axis
Origin

提示
scanf 可以直接用 format "(%d,%d)" 读取括号和逗号。
需要 getchar() 吃掉换行符，否则会死循环。

*/

#include <stdio.h>
void is_where(int x, int y);

int main(void) {
    int x, y;
    while(scanf("(%d,%d)", &x, &y) != EOF) {
        is_where(x, y);
        getchar();  // 消除换行符
    }
    return 0;
}

void is_where(int x, int y) {
    if (x > 0 && y > 0) printf("First quadrant\n");
    else if (x < 0 && y > 0) printf("Second quadrant\n");
    else if (x < 0 && y < 0) printf("Third quadrant\n");
    else if (x > 0 && y < 0) printf("Forth quadrant\n");
    else if (x != 0 && y == 0) printf("X axis\n");
    else if (x == 0 && y != 0) printf("Y axis\n");
    else printf("Origin\n");
}
