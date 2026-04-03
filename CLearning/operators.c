#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main(void) {
    // 按位移位运算符 左移<< 右移>>
    // 直接对二进制值进行操作

    int32_t apples = 22;
    printf("There are %" PRId32 " apples.\n", apples);

    apples = apples << 2;
    printf("There are %" PRId32 " apples.\n", apples);

    apples = apples >> 1;
    printf("There are %" PRId32 " apples.\n", apples);

    // int32_t 共4字节，32位
    int32_t orange = 1;
    orange = orange << 32;
    printf("%" PRId32 "\n", orange); // 值为1，会“绕”回来，是个圈！！

    return 0;
}