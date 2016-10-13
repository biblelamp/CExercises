// Define the function power(), where
//    x - the number for exponentiation
//    p - the exponent
//
#include <iostream.h>

int power(int x, unsigned p) {
    int answer = 1;
    for (int i = 0; i < p; i++) answer = answer * x;
    return answer;

}

int main()
{
	std::cout << "2 ^ 2 = " << power(2, 2);
    return 0;
}

