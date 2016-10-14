#include <iostream.h>
using namespace std;

// The program can add integer numbers

int main()
{
    int k;
    int a;
    int b;
    //cout << "Enter value for k: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
    	cin >> a >> b;
    	cout << a + b << "\n";
    }
    return 0;
}
