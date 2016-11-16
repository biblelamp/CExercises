#include <stdio.h>

int hashString(char * str)
{
    int result=0;
    for (int i = 0; str[i] != '\0'; i++)
        result += (int) str[i];
    return result;
}

int main()
{
    char string[80];
    puts("Enter the string of symbol:");
    gets(string);
    printf("Hash is %d.\n", hashString(string));
    return 0;
}
