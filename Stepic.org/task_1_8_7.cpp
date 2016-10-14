#include <iostream.h>
#define sqr(x) x * x

// define function via macros is a bad idea

int main()
{
    std::cout << sqr(3 + 0) << "\n";
    std::cout << sqr(3);
    return 0;
}
