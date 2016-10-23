#include <stdio.h>

float max_out_three(float a, float b, float c)
{
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

int main()
{
    float a,b,c;
    printf("Enter number A B and C:\n");
    scanf("%f %f %f", &a, &b, &c);
    printf("%f", max_out_three(a, b, c));
    return 0;
}
