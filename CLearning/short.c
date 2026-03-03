#include <stdio.h>
int main(void) {

	short normal_short = 100;
	
	// screen resolution
	unsigned short screen_lenghth = 800;
	unsigned short screen_width = 600;
	
	// x, y
	unsigned short x = 5;
	unsigned short y = 1;

	printf("The normal short: %hd\n", normal_short);
	printf("The screen resolution is %hu X %hu\n", screen_lenghth, screen_width);
	printf("The dot is on (%hu, %hu)\n", x, y);

	return 0;
}

// short ¿‡–Õ’º 2 bytes