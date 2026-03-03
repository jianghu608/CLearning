#include <stdio.h>
int main(void) {
	
	long number_1 = 10;
	unsigned long number_2 = 20;
	long long number_3 = 30;
	unsigned long long number_4 = 40;

	printf("number_1 = %ld\n", number_1);
	printf("number_2 = %lu\n", number_2);
	printf("number_3 = %lld\n", number_3);
	printf("number_4 = %llu\n", number_4);

	return 0;
}