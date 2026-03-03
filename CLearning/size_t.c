#include <stdio.h>
#include <stdint.h>
int main(void) {

	// size_t是sizeof()返回的数据类型，而不是int
	// sizeof() 测量数据类型所占用的字节数
	printf("Size of int: %zu byte(s)\n", sizeof(int));
	printf("Size of unsigned int: %zu byte(s)\n", sizeof(unsigned int));
	printf("Size of short: %zu byte(s)\n", sizeof(short));
	printf("Size of unsigned short: %zu byte(s)\n", sizeof(unsigned short));
	printf("Size of long: %zu byte(s)\n", sizeof(long));
	printf("Size of unsigned long: %zu byte(s)\n", sizeof(unsigned long));
	printf("Size of long long: %zu byte(s)\n", sizeof(long long));
	printf("Size of unsigned long long: %zu byte(s)\n\n", sizeof(unsigned long long));

	int16_t max_int16 = 32767;
	uint16_t max_uint16 = 65535;

	int32_t max_int32 = 2147483647;
	uint32_t max_uint32 = 4294967295U;

	int64_t max_int64 = 9223372036854775807LL;
	uint64_t max_uint64 = 18446744073709551615ULL;

	printf("Size of int16_t: %zu byte(s)\n", sizeof(max_int16));
	printf("Size of uint16_t: %zu byte(s)\n", sizeof(max_uint16));
	
	printf("Size of int32_t: %zu byte(s)\n", sizeof(max_int32));
	printf("Size of uint32_t: %zu byte(s)\n", sizeof(max_uint32));

	printf("Size of int64_t: %zu byte(s)\n", sizeof(max_int64));
	printf("Size of uint64_t: %zu byte(s)\n", sizeof(max_uint64));

	return 0;
}