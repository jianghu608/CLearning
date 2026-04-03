#include <stdio.h>
int main(void) {

	// 第一次赋值，初始化，定义
	// 定义一个int类型时，内存通常开辟一个4 bytes的空间
	// 1 byte = 8 bit
	int number = 123;
	printf("第一次number+12345的值是：%d\n", number + 12345);

	// 第二次赋值
	number = 234;
	printf("第二次number的值是：%d\n\n", number);

	// printf相关用法（格式化输出）
	
	// 十进制表示
	printf("Decimal: %d\n", number);

	// 八进制表示
	printf("Octal: %o\n", number);

	// 十六进制表示（小写）
	printf("Hexdecimal(lowercase): %x\n", number);

	// 十六进制表示（大写）
	printf("Hexdecimal(uppercase): %X\n\n", number);


	// 标识符 flags
	// 放在百分号后面
	printf("%#x\n", number);
	printf("%#X\n", number);

	// 前导零
	// 会补足前面为零
	printf("Leading zero: %010d\n", 100);

	// 缩进对齐
	printf("Left aligned: %-10d|\n", 100);
	printf("Right aligned: %10d|\n", 100);

	// 显示正负号
	printf("Show plus: %+d\n", -number);
	printf("Show plus: %+d\n", number);
	

	return 0;
}