/*给定 n 和 k，将从 1 到 n 之间的所有正整数可以分为两类：
A 类数可以被 k 整除（也就是说是 k 的倍数），而 B 类数不能。
请输出这两类数的平均数，精确到小数点后 1 位，用空格隔开。

数据保证两类数的个数都不会是 0。*/

// 输出一行，两个实数，分别表示 A 类数与 B 类数的平均数。精确到小数点后一位。

#include <stdio.h>

// 数学优化方法
void cat_ave(int n, int k) {
    // A类数只要看1到n之间k的倍数，B类数只要等差数列总和减去A就可以了，需要统计A类数的个数
    int count_A = n / k;
    int count_B = n - count_A;

    // A类数就是公差为k的等差数列，项数为count_A
    // int sum_A = (k + count_A * k) * count_A / 2;
    int sum_A = k * (1 + count_A) * count_A / 2;
    int sum_B = (1 + n) * n / 2 - sum_A;

    printf("%.1f %.1f\n", (float)sum_A / count_A, (float)sum_B / count_B);
}

int main(void) {

    int n, k;
    scanf("%d %d", &n, &k);

    cat_ave(n, k);
    /*
    int sum_A = 0;
    int sum_B = 0;
    int count_A = 0;
    int count_B = 0;

    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            sum_A += i;
            count_A ++;
        }
        else {
            sum_B += i;
            count_B++;
        }
    } 


    printf("%.1f %.1f\n", (float)sum_A / count_A, (float)sum_B / count_B);
    */

    return 0;
}