#include <iostream>
using namespace std;

// Check if number is even or odd without using modulus operator
bool isEven(int n)
{
    return ((n / 2) * 2 == n);
}
int main() {
    isEven(15) ? cout << "True" : cout << "False";
    return 0;
}
