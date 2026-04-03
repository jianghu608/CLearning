#include <stdio.h>
#include <stdint.h>
int main(void) {

	// type convertion 类型转换
	// 本质上是复制了目标的 数据类型，位宽，二进制数值
	
	int32_t smallNum;
	uint32_t bigNum = 2147483648;

	// 隐式转换：自动转换
	smallNum = bigNum; // smallNum获得了bigNum的二进制值：1000,0000,0000,0000 与数据类型 uint32_t
	printf("smallNum = %u\n", smallNum); // 转换为uint32_t，正常输出
	printf("smallNum = %d\n\n", smallNum); // 转换为int32_t，是有符号型，整型溢出，应该输出为-2^31


	// 显式转换：指定转换类型，也称强制转换
	// 为了更明显地看出转换结果，我们意图制造整型溢出
	// 这里的 target 指的是 目标数值（二进制）
	// original 类型实际上可随意定义，引入即可
	
	// 同位宽
	uint32_t target_01 = INT32_MAX; // 二进制为0111...
	uint32_t target_02 = UINT32_MAX; // 二进制为1111...
	int32_t ori_1;
	
	ori_1 = (int32_t)target_01;
	printf("tar01 converts: %d\n", ori_1); // 应该输出2147483647
	ori_1 = (int32_t)target_02;
	printf("tar02 converts: %d\n\n", ori_1); // 整型溢出，应该输出-1

	// 不同位宽
	// 猜测：大位宽转换至小位宽，高位被截断，保留低位
	int32_t target_11 = 131071; // 二进制为0000,0000,0000,0001,1111,1111,1111,1111
	int16_t ori_2;

	ori_2 = (int16_t)target_11; // 前16位被截断，转换为1111...
	printf("tar11 converts: %hd\n", ori_2); // 应该输出-1

	// 猜测正确
	// 那么，小位宽转换至大位宽，增加位宽，高位补零
	int16_t target_21 = 21; // 只要不大于同位宽的无符号类型数值（16位都溢出），都不影响输出结果，为现在定义的值
	int16_t target_22 = 65537; // 此时已经整型溢出了，target_22的实际值应该是1
	int32_t ori_3;

	ori_3 = (int32_t)target_21;
	printf("tar21 converts: %d\n", ori_3); // 输出应为21
	ori_3 = (int32_t)target_22;
	printf("tar22 converts: %d\n", ori_3); // 输出应为1


	// 尽量使用显示转换，增加可读性

	return 0;
}