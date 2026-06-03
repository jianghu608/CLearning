/* 浙工大转专业机考真题 题5 — 整理高手（鸡尾酒排序）

题目描述
小张老师是数据整理高手，他喜欢用的数据整理方法描述如下：
一次整理由两趟比较构成：

1. 先从数据集头部开始两两比较元素，碰到逆序对则交换，
   这样将最大的元素放到数据集尾部；
2. 再从数据集尾部开始两两比较元素，碰到逆序对则交换，
   这样将最小的元素放到数据集的头部；
3. 然后缩小数据集规模，重复上述过程。

在整理的过程中，如果一趟比较发现数据已经有序，就结束整理工作。

输入
多组输入，每组输入由两行构成。
第一行描述待整理的集合规模 n（1 ≤ n < 100）；
第二行描述待整理的数据集合（由 n 个数据项构成的行）。

输出
每组输出结果为所有整理的经过，输出每次整理后集合内数据排列的情况，
每个数据间用逗号分隔，行末直接回车。

样例
输入：
6
3 2 5 4 7 1
4
999 888 777 666

输出：
1,2,3,4,5,7
666,888,777,999
666,777,888,999

*/

#include <stdio.h>

int main(void) {
    // 输入 n
    int n;
    while (scanf("%d", &n) != EOF) {
        // 输入数组
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);


        // 初始化标记
        int left = 0;
        int right = n-1;


        // 用标记遍历数组，排序
        while (left < right) {
            // 左右分开看
            int is_sorted = 0;   // 标记，确认是否有乱序，没有乱序，结束循环

            // 先看左边
            for (int i = left; i < right; i++) {
                if (arr[i] > arr[i+1]) {
                    int temp = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = temp;                // !!!

                    is_sorted = 1;
                }
            }
            right--;

            for (int j = right; j > left; j--) {
                // 再看右边
                if (arr[j-1] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;                // !!!

                    is_sorted = 1;
                }
            }
            left++;

            // 排序了，继续；没有排序，结束
            if (!is_sorted) break;

            // 排序一次完成，输出，重置标记
            printf("%d", arr[0]);
            for (int k = 1; k < n; k++) printf(",%d", arr[k]);
            printf("\n");


        }                                       // 不知道怎么直接对数组元素进行换序

    }
    return 0;
}
