#include <stdio.h>

int main()
{
    float m,h,i;
    printf("Enter weight and hight:\n");
    scanf("%f %f", &m, &h);
    i = m/(h*h);
    printf("Index of mass = %f\n", i);
    return 0;
}
