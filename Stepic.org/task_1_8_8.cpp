#include <iostream.h>
#define MAX(x, y, r) { int _x = (x); int _y = (y); r = _x < _y ? _y : _x; }

// macro MAX has three parameters/variable names and it assigns
// the third variable the highest value of the first two variables

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	MAX(a, b, c); // c to get the value 20
    std::cout << c << "\n";
    MAX(a += b, b, c); // c to get the value 30
    std::cout << c;
    return 0;
}
