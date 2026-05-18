#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main(void) {

    // 案例：饮料售货机。饮料价格 5$ ，币种 1$, 2$, 4$。

    const uint8_t PRICE = 5;
    uint8_t balance = 0;
    uint8_t coin;

    printf("本售货机只提供一种饮料，价格5$。\n");
    printf("只支持 1$, 2$, 4$ 的币种\n");

    while (balance < PRICE) {
        printf("钱不足，请投币：");
        scanf("%" PRIu8, &coin);
        
        if (coin == 1 || coin == 2 || coin == 4) {
            balance += coin;
        }
        else {
            printf("本售货机不支持%" PRIu8 "$的币种\n", coin);
        } 
    }

    if (balance > PRICE) {
        printf("\n请收好找零：%" PRIu8 "$\n", balance - PRICE);
    }

    printf("谢谢惠顾！请收好你的饮料\n");

    return 0;
}