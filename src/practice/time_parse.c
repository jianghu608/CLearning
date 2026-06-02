/*多组数据，每组数据为一个时间，时用字母H引导，分用字母M引导，秒用字母S引导。
输入数据中间不包含空格，如H22M23S55，合法的时间表达应为24小时制。*/
/*对于给定的每个时间，要按H:M:S的顺序给出规范的时间表达,
若检测到时间非法，则给出Error信息。每个结果占一行，行末回车。*/

#include <stdio.h>
int main(void) {

    char str[20];
    // 读取时间，分组处理
    while (scanf("%s", str) != EOF) {
        int h = 0;
        int m = 0;
        int s = 0;
        int i = 0;

        // 遍历整个字符串
        while (str[i] != '\0') {
            // 判断遇到的字母，分别处理
            // 处理小时
            if (str[i] == 'H') {
                i++;
                int val = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    val = val * 10 + (str[i] - '0');
                    i++;
                }
                h = val;
                continue;
            }
            // 处理分钟
            if (str[i] == 'M') {
                i++;
                int val = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    val = val * 10 + (str[i] - '0');
                    i++;
                }
                m = val;
                continue;
            }
            // 处理秒
            if (str[i] == 'S') {
                i++;
                int val = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    val = val * 10 + (str[i] - '0');
                    i++;
                }
                s = val;
                continue;
            }
            i++;
        }
        // 判断时间是否合法，然后输出
        if (h <= 23 && m <= 59 && s <= 59) {
            printf("%d:%d:%d\n", h, m, s);
        }
        else {
            printf("Error\n");
        }
    }

    return 0;
}