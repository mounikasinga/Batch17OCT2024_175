#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define AREA_TRIANGLE(base, height) (0.5 * (base) * (height))  
#define AREA_CIRCLE(radius) (PI * (radius) * (radius))        

int main() {
    double base = 5, height = 10, radius = 7;

    printf("Area of triangle: %.2f\n", AREA_TRIANGLE(base, height));
    printf("Area of circle: %.2f\n", AREA_CIRCLE(radius));

    return 0;
}

