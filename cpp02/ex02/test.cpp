#include <stdio.h>
#include <cmath>

int main(void)
{
    // int c = 8;
    // int n = (int)(roundf((float)10 / (1 << c)));
    // float n1 = roundf(0.1f / (1 << c));
    // float n2 = 0.1f / (1 << c);
    // printf("%d\n", n);
    // printf("%f\n", (float)n);
    // printf("%d\n", n);
    // printf("%f\n", n1);
    // printf("%f\n", n2);

    float a = 1.23;
    int c = 8;

    // 부동 -> 고정
    printf("%f\n", (roundf(a * (1 << c))));
    // 고정 -> 부동
    printf("%f\n", ((float)(roundf(a * (1 << c)) / (1 << c))));
    float b = ((float)(roundf(a * (1 << c)) / (1 << c)));
    printf("%f\n", ++b);
}