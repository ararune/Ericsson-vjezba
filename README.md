# Ericsson-vjezba
Vježba pred testiranje

```cpp
using namespace std;
// Check if number is even or odd without using modulus operator
bool isEven(int n)
{
    return ((n / 2) * 2 == n);
    // (15 / 2 ) = 7 (rounded down int) * 2 = 14 != 15; odd number
}
int main() {
    isEven(15) ? cout << "True" : cout << "False";
    return 0;
}
```
