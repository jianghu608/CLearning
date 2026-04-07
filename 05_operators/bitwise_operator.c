#include <stdio.h>
int main(void) {

    // 按位与操作符 &
    // 按位操作，对二进制数字的每一位进行 and 运算（都为1则为1，其余为0）
    // example
    printf("%d", 0b1001 & 0b11100);
    //    1001
    //   11100
    // -> 1000，即 8

    return 0;
}