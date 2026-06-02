// 求极差
// 给出 n 和 n 个整数 a_i，求这 n 个整数中的极差是什么。极差的意思是一组数中的最大值减去最小值的差。
// 输入格式：
// 第一行输入一个正整数 n，表示整数个数。
// 第二行输入 n 个整数，以空格隔开。


// 将输入的数字存在一个数组中，两次遍历找最大最小值。

#include <stdio.h>

int range(int n, int *nums) {
    int min = nums[0];
    int max = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    return max - min;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", range(n, nums));
}