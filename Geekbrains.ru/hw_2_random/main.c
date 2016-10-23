#include <stdio.h>
#include <time.h>

int random(int range, int x) {
    int a=438, b=153;
    return (a*x + b) % range;
}

int main()
{
    unsigned long t=time(NULL);
    int x=t % 1000;
    int range=100;
    for (int i = 0; i < 100; i++) {
        x = random(range, x);
        printf("%d ", x);
    }
    return 0;
}
