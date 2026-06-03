#include <stdio.h>
int fib(int n) {
    int a = 0;
    int b = 1;
    // 用n计数，让第一个数向前迭代n次
    while (n-- > 0) {
        int c = a + b;
        a = b;
        b = c;
        printf("1");
    }
    return a;
}

int main(void) {
    int n = 3;
    printf("%d", fib(n));

    return 0;
}
