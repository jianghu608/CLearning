#include <stdio.h>
int main(void) {

	int number;
	printf("Please input a number: ");
	// scanf_s() 用户输入的内容要与引号内的内容一一对应，也可以连续输入
	scanf_s("%d", &number);
	printf("Your number is %d\n", number);

	// 输入多个
	int number1, number2, number3;
	printf("Please input three numbers with ,: ");
	scanf_s("%d,%d,%d", &number1, &number2, &number3);
	printf("Your numbers are %d %d %d\n", number1, number2, number3);

	return 0;
}