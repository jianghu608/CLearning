#include <stdio.h>
int main(void) {

    // 条件表达式运算符 格式：   <bool值> ? <A选项> : <B选项>
    // 如果给的 bool值为 true（非0），输出A；为 false（为0），输出B
    // 一个简化版的条件判断 if-else 语句？

    int apple = 6;

    printf("There are 8 apples, is this right？: %s", apple == 8 ? "yes" : "no");

    return 0;
}