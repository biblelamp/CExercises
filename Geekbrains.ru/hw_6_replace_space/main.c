#include <stdio.h>

int len(char * str) // like function strlen
{
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

int isSourceInStr(char * str, char * source, int n)
{
    for(int i = 0; i < len(source); i++)
        if (str[i+n] != source[i]) return 0;
    return 1;
}

void changeLengthString(char * str, int source, int target, int pos)
{
    if (target > source)
    {
        int add = target - source;
        for(int i = len(str) + add; i > pos; i--)
            str[i] = str[i - add];
    }
    if (target < source)
    {
        int sub = source - target;
        for(int i = pos; i < len(str) - sub + 1; i++)
            str[i] = str[i + sub];
    }
}

void putTargetToStr(char * str, char * target, int pos)
{
    for(int i = 0; i < len(target); i++)
        str[i + pos] = target[i];
}

void replaceStr(char * str, char * source, char * target)
{
    for(int i = 0; i < len(str) - len(source); i++)
        if (isSourceInStr(str, source, i))
        {
            changeLengthString(str, len(source), len(target), i);
            putTargetToStr(str, target, i);
        }
}

int main()
{
    char buffer[128];
    char *string;

    string = buffer;
    puts("Input string:");
    gets(string);
    replaceStr(string, " ", "%20");
    printf("%s %d\n", string, len(string));
    replaceStr(string, "%20", "_");
    printf("%s %d\n", string, len(string));
    return 0;
}
