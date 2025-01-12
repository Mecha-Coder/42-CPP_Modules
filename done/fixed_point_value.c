#include <stdio.h>

#define FRACTIONAL_BITS 8 // 8 vs 16 vs 32
#define SCALE_FACTOR (1ULL << FRACTIONAL_BITS) // 2^32 = 4294967296


long long float_to_fixed(float value)
{
    return (long long)(value * SCALE_FACTOR + (value >= 0 ? 0.5f : -0.5f)); // Manual rounding
}


float fixed_to_float(long long fixed_value) 
{
    return (float)fixed_value / SCALE_FACTOR; // Divide by scale factor
}

int main() {
    float original_float = 12.625;
    long long fixed_point;
    float converted_back;

     printf("SCALER_FACTOR = %llu\n\n", SCALE_FACTOR);

    fixed_point = float_to_fixed(original_float);
    converted_back = fixed_to_float(fixed_point);

    // Display results
    printf("Original float: %f\n", original_float);
    printf("Fixed-point representation: %lld\n", fixed_point);
    printf("Converted back to float: %f\n", converted_back);

    // Check for exactness
    if (original_float == converted_back) {
        printf("The conversion is exact.\n");
    } else {
        printf("The conversion is not exact.\n");
    }

    return 0;
}
