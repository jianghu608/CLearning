#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>

int main (void) {

    char temperature = -12;
    unsigned char brightness = 200;

    short x_pixel = 1920;
    short y_pixel = 1080;
    unsigned short pixel_value = 8000;

    int max_int = 2147483647;
    int min_int = -2147483648;
    unsigned int max_uint = max_int - min_int;

    long a_long = 324;
    unsigned long a_ulong = 18312314;

    long long a_llong = 123134345;
    unsigned long long a_ullong = 18293861764;


    int8_t max_int8 = INT8_MAX;
    uint8_t max_uint8 = UINT8_MAX;
    int16_t max_int16 = INT16_MAX;
    uint16_t max_uint16 = UINT16_MAX;
    int32_t max_int32 = INT32_MAX;
    uint32_t max_uint32 = UINT32_MAX;
    int64_t max_int64 = INT64_MAX;
    uint64_t max_uint64 = UINT64_MAX;


    float body_temperature = 37.2;
    double pi = 3.14;

    float max_float = FLT_MAX;

    float positive_infinity = INFINITY;
    float negative_infinity = -INFINITY;


    printf("The temperature is %d°C\n", temperature);
    printf("The brightness is %u\n", brightness);

    printf("The size of screen is %hdx%hd\n", x_pixel, y_pixel);
    printf("The pixel value is %hu\n", pixel_value);

    printf("Max int: %d\n", max_int);
    printf("Min int: %d\n", min_int);
    printf("Max uint: %u\n", max_uint);

    printf("A long: %ld\n", a_long);
    printf("A unsigned long: %lu\n", a_ulong);
    printf("A long long: %lld\n", a_llong);
    printf("A unsigned long long: %llu\n", a_ullong);


    printf("Max int8: %" PRId8 "\n", max_int8);
    printf("Max uint8: %" PRIu8 "\n", max_uint8);
    printf("Max int16: %" PRId16 "\n", max_int16);
    printf("Max uint16: %" PRIu16 "\n", max_uint16);
    printf("Max int32: %" PRId32 "\n", max_int32);
    printf("Max uint32: %" PRIu32 "\n", max_uint32);
    printf("Max int64: %" PRId64 "\n", max_int64);
    printf("Max uint64: %" PRIu64 "\n", max_uint64);

    printf("The normal body temperature is below %.1f\n", body_temperature);
    printf("Pi: %.2lf\n", pi);
    printf("Max float is %f\n", max_float);
    
    printf("The positive infinity is %f\n", positive_infinity);
    printf("The negative infinity is %f\n", negative_infinity);

    printf("\nPlease input a number of students:\n");
    int stu_num;
    scanf("%d", &stu_num);
    printf("The number you input is %d\n", stu_num);


    return 0;
}