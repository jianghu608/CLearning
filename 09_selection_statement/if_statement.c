#include <stdio.h>
#include <stdbool.h>
int main(void) {

    // example: 购物优惠
    // 1.是vip，且购物金额超过200，折扣20%
    // 2.不是vip，且购物金额超过100，折扣5%
    // 3.是vip，且购物金额超过100，折扣10%
    // 4.是vip，折扣5%
    // 5.不是VIP，且购物金额不超过100，无折扣

    // 共2类条件：vip，购物金额
    // 用嵌套

    unsigned int total_price;
    bool is_vip;
    double discount;

    is_vip = true;
    total_price = 150;

    if (is_vip) {                       // 是vip
        if (total_price > 200) {
            discount = 0.20f;
        }
        else if (total_price > 100) {
            discount = 0.10f;
        }
        else {
            discount = 0.05f;
        }
    }
    else if (total_price > 100) {   // 不是vip
        discount = 0.05f;
    }
    else {
        discount = 0.00f;
    }

    printf("Your discount is %.2lf%%\n", discount * 100);

    return 0;
}