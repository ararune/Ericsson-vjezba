#include <iostream>
using namespace std;

// Check if n is power of 3
bool isPowerOfThreeRec(int n){
    if(n <= 0){
        return false;
    }
    if(n % 3 == 0){
        return isPowerOfThreeRec(n / 3);
    }
    if(n == 1){
        return true;
    }
    return false;
}
bool isPowerOfThreeIter(int n){
    if(n <= 0){
        return false;
    }
    while(n % 3 == 0){
        n /= 3;
    }
    if(n == 1){
        return true;
    }
    return false;
}
void print(int a, int b){
    while(b <= a){
        cout << "Invalid input, please enter a as low boundary, b as high boundary!" << endl;
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
    }
    for(a; a < b; a++){
        if(isPowerOfThreeIter(a)){
            cout << a;
            cout << "\t";
        }
    }
}
int main() {
    print(1, 85);
    return 0;
}
