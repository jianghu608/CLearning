#include <stdio.h>
#include <float.h>
#include <math.h>
int main(void) {

	// Postive infinity	正无穷
	float positive_infinity = INFINITY;
	
	// Negative infinity 负无穷
	float negative_infinity = -INFINITY;

	// NaN	Not a number
	float nan = sqrt(-1);

	printf("Positive infinity = %f\n", positive_infinity);

	printf("Negative infinity = %f\n", negative_infinity);

	printf("NaN: sqrt(-1) = %f\n", nan);

	return 0;
}