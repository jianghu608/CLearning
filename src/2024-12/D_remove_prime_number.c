/*
问题D：去除质数
现在有个工作，需要挑拣两个正整数集合的所有非质数，现在请你来编程完成这个工作吧！

输入
多组数据输入，每组数据给定两个正整数集合，分别由两行给出。
每行的第一个数字给出集合的数据个数，随后跟随对应个数的正整数。
每个集合的数据规模不超过50，单个集合内无重复元素，集合的数据范围均不超过int。
参考输入样本示范。

输出
对于每组数据，挑拣出两个集合所有的非质数，并按升序输出求解结果，使用逗号分隔。
若没有非质数，那么输出" None " 。行末直接回车。参考输出样本示范。

样例输入：
5 23 12 4 7 9
9 4 6 13 3 12 7 23 2 11
4 2 1 3 7
5 3 13 17 1 7
2 3 5
1 2

样例输出：
4,6,9,12
1
None
*/

// 考虑使用桶标记
#include <stdio.h>
#include <stdbool.h>


bool is_prime_number(int n);
void sort(int arr[], int size);
bool is_sorted(int arr[], int size);

int main(void) {
    // 输入数组大小和数组
    // 一次输入两组数据且是多组两组数据
    int size1, size2;
    while(scanf("%d", &size1) != EOF) {
        // 每组数据开始，初始化桶
        // 不行，数据范围太大，用不了桶标记

        // 每组开始，初始化非质数数组
        int not_prime[55];
        int index = 0;

        // 第一组数据
        for (int i = 0; i < size1; i++) {
            int n;
            scanf("%d", &n);
            int already = 0;
            if (!is_prime_number(n)) {
                for (int j = 0; j < index; j++) {
                    if (n == not_prime[j]) {
                        already = 1;
                        break;
                    }
                }
                if (!already) {
                    not_prime[index] = n;
                    index++;
                }

            }
        }


        // 第二组数据
        // 清除空白符号
        while (getchar() != '\n') ;
        scanf("%d", &size2);
        for (int i = 0; i < size2; i++) {
            int n;
            scanf("%d", &n);
            int already = 0;
            if (!is_prime_number(n)) {
                for (int k = 0; k < index; k++) {
                    if (n == not_prime[k]) {
                        already = 1;
                        break;
                    }

                }
                if (!already) {
                    not_prime[index] = n;
                    index++;
                }
            }
        }


        // 排序
        while (!is_sorted(not_prime, index)) {
            sort(not_prime, index);
        }

        // 排序完成，输出
        if (index == 0) {
            printf("None");
        }
        else {
            printf("%d", not_prime[0]);
            for (int j = 1; j < index; j++) {
                printf(",%d", not_prime[j]);
            }
            printf("\n");
        }

    }

    return 0;
}

bool is_prime_number(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    else {
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        // 所有情况排除后，说明是质数
        return true;
    }
}

void sort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        if (arr[i] > arr[i+1]) {
            int tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
    }
}

bool is_sorted(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}
