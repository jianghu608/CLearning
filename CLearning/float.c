#include <stdio.h>
#include <float.h>
int main(void) {

	float temperature = 37.2f;

	float sound_speed = 3.4e2f;

	float mout_height = 8848.86f;

	float length = 29.7f, width = 21.0f;

	printf("The temperature is %f °C\n", temperature);

	printf("The speed of sound is %f m/s\n", sound_speed);

	printf("The height of highest mountain is %f m\n", mout_height);

	printf("The size of A4 paper is %f x %f cm\n", length, width);

	printf("保留两位小数，四舍五入：%.2f\n\n", mout_height);


	// float 不同方式输出

	float num = 123.456f;

	// %f
	printf("Using %%f: %f\n", num);

	// %e %E 科学计数法输出
	printf("Using %%e: %e\n", num);
	printf("Using %%E: %E\n", num);

	// %a %A 十六进制浮点数 p计数法
	printf("Using %%a: %a\n", num);
	printf("Using %%A: %A\n\n", num);


	// double 双精度，精度更高
	double a_num = 34.71;
	printf("%lf\n\n", a_num);


	// 浮点数溢出，原理同样为二进制的模运算

	// Overflow
	float max_float = FLT_MAX;
	float overflow = max_float * 1000.0f;
	// Underflow
	float min_float = FLT_MIN;
	float underflow = min_float / 1000.0f;

	printf("Maximum of float = %e\n", max_float);
	printf("Overflow: %e\n", overflow);		
	
	printf("Minimum of float = %e\n", min_float);
	printf("Underflow: %e\n", underflow);

	return 0;
}