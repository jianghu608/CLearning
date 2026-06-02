/* P1914 凯撒密码 / 小书童

题目描述
蒟蒻在密码学中学到了凯撒密码。凯撒密码是一种简单且广为人知的加密技术。
加密方式是将明文中的所有字母在字母表上向后（或向前）按照一个固定数目进行偏移，
被替换成密文。例如，当偏移量是 3 的时候，字母 A 会被替换成 D，字母 B 替换成 E，
字母 Z 替换成 C。
现在，请你编程实现这个加密方法。

输入格式
第一行一个整数 n，表示偏移量。
第二行一个字符串 s，表示需要加密的明文。

输出格式
输出一行，表示加密后的密文。

样例
输入：
3
abc
输出：
def

输入：
3
xyz
输出：
abc

提示
|s| ≤ 50，n 为整数，可能很大（但只需要在字母表范围内循环偏移）

*/

#include <stdio.h>

char* caesar(int shift, char plaintext[]);
int main(void) {
    // 输入偏移量
    int shift;
    scanf("%d", &shift);

    // 输入字符串存入secret，加密后输出
    char secret[55];
    scanf("%s", secret);
    printf("%s\n", caesar(shift, secret));

    return 0;
}

char* caesar(int shift, char plaintext[]) {
    int i = 0;
    static char ciphertext[55];
    while (plaintext[i] != '\0') {  // 26一'圈'，算它的位移
        ciphertext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';    // 'z' -> 'c': 'z' - 'a' + s) % 26 + 'a'; 'a' -> 'd': 'a' - 'a' + s) % 26 + 'a'
        i++;
    }
    ciphertext[i] = '\0';
    return ciphertext;
}
