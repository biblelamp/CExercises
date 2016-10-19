#include <stdio.h>

int main()
{
    int year;
    printf("Enter age in year:\n");
    scanf("%d", &year);

    // in English
    if (year == 1)
    {
        printf("Age is %d year\n", year);
    }
    else
    {
        printf("Age is %d years\n", year);
    }

    // in Russian
    if (year > 4 && year < 21)
    {
        printf("Возраст %d лет\n", year);
    }
    else if (year % 10 == 1)
    {
        printf("Возраст %d год\n", year);
    }
    else if (year % 10 > 1 && year % 10 < 5)
    {
        printf("Возраст %d года\n", year);
    }
    else
    {
        printf("Возраст %d лет\n", year);
    }

    return 0;
}
