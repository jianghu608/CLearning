#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main(void) {

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
	printf("Size of uint64_t: %zu byte(s)\n\n", sizeof(max_uint64));


	printf("Max of int16_t = %hd\n", max_int16);
	printf("Max of uint16_t = %hu\n", max_uint16);

	printf("Max of int32_t = %d\n", max_int32);
	printf("Max of uint32_t = %u\n", max_uint32);

	printf("Max of int64_t = %lld\n", max_int64);
	printf("Max of uint64_t = %llu\n\n", max_uint64);


	int8_t max_int8 = INT8_MAX;
	uint8_t max_uint8 = UINT8_MAX;

	printf("int8_t: %" PRId8 "\n", max_int8);
	printf("uint8_t: %" PRIu8 "\n", max_uint8);

	printf("int16_t: %" PRId16 "\n", max_int16);
	printf("uint16_t: %" PRIu16 "\n", max_uint16);

	printf("int32_t: %" PRId32 "\n", max_int32);
	printf("uint32_t: %" PRIu32 "\n", max_uint32);

	printf("int64_t: %" PRId64 "\n", max_int64);
	printf("uint64_t: %" PRIu64 "\n\n", max_uint64);


	int_least32_t playScore = 500;
	printf("the score is %" PRIdLEAST32 "\n", playScore);

	int_fast32_t pixelValue = 255;
	printf("the pixel value is %" PRIdFAST32 "\n", pixelValue);

	return 0;
}