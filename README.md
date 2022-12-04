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
```js
// Count days until next birthday
function convertToDate(dateString) {

    let d = dateString.split("/");
    let dat = new Date(d[2] + '/' + d[1] + '/' + d[0]);
    return dat;
}
function daysTilBday(bdayString) {
    let today = new Date();
    let myBday = convertToDate(bdayString);
    let age = today.getFullYear() - myBday.getFullYear();
    let upcomingBday = new Date(today.getFullYear(), myBday.getMonth(), myBday.getDate());

    if (today > upcomingBday) {
        upcomingBday.setFullYear(today.getFullYear() + 1);
    }
    let oneDay = 24 * 60 * 60 * 1000;
    let daysLeft = Math.ceil((upcomingBday.getTime() - today.getTime()) / (oneDay));
    console.log(`In ${daysLeft} day(s), you will be ${age + 1}`);
}
console.log(daysTilBday('31/08/1995'));
```
```cpp
using namespace std;

// Check if n is power of 3, print all numbers in range that are power of 3
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
```
```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Check number of repeating columns in 2D matrix
int main() {
    vector<vector<int>> vOfVectors;
    int x[3][5] = {{0, 1, 1, 8, 1},
                   {2, 3, 2, 6, 6},
                   {4, 5, 4, 5, 5},
    };
    vector<int> v;
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 3; i++) {
            v.push_back(x[i][j]);
        }
        vOfVectors.push_back(v);
        v.clear();
    }
    int size1 = vOfVectors.size();
    set<vector<int>> s(std::make_move_iterator(vOfVectors.begin()),
                       std::make_move_iterator(vOfVectors.end()));
    cout << "Broj ponavljanja je : " << size1 - s.size();
    return 0;
}
```
```cpp
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
// Count occurence of each character in a string (mapping method)

std::map<char, int> getCharMap(string &str) {
    //Transform string to lowercase if we want to consider 'A' same as 'a'
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    
    map<char, int> charMap;
    set<char> charSet(str.begin(), str.end());
    set<char>::iterator itr;
    int count = 0;
    
    for (itr = charSet.begin(); itr != charSet.end(); itr++) {
        for (const auto &i: str) {
            if (*itr == i) {
                count++;
            }
        }
        charMap.insert(pair<char, int>(*itr, count));
        count = 0;
    }
    return charMap;
}
void printMap(map<char, int> charMap) {
    for (const auto &i: charMap) {
        std::cout << i.first << ':' << i.second << std::endl;
    }
}
int main() {
    string str = "Helloworld";
    map<char, int> mapToPrint = getCharMap(str);
    printMap(mapToPrint);
    return 0;
}
```
```cpp
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <time.h>

// Lotto 7, user enters 7 numbers in range 0 to 39 til matches >= 6 with winnin lotto numbers
using namespace std;
vector<int> userChoice(const int n, const int rangeLow, const int rangeHigh){
    int input;
    vector<int> userNumbers;
    for(int i = 0; i != n; i++){
        cout << "Enter a number in range of " << rangeLow << " to " << rangeHigh << " :" << endl;
        cin >> input;
        if(input >= rangeLow && input <= rangeHigh){
            userNumbers.push_back(input);
        }
        else{
            cout << "Input out of bounds, please enter an integer in range" << endl;
        }
    }
    return userNumbers;
}
int generateRandom(int rangeLow, int rangeHigh){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937_64 generator(seed);
    uniform_int_distribution<> distribution(rangeLow, rangeHigh);	// p(x|a, b) = 1/(b-a) , a <= x < b

    return distribution(generator);

}
vector<int> fillVector(int n, int rangeLow, int rangeHigh){
    vector<int> generatedVector;
    for(int i = 0; i != n; i++){
        generatedVector.push_back(generateRandom(rangeLow,rangeHigh));
    }
    return generatedVector;
}
void printVector(vector<int> v){
    for(const auto& num : v){
        cout << num << "\t";
    }
}
int matchingCount(vector<int> userNumbers, vector<int> lottoNumbers){
    vector<int> v;
    int count = 0;
    size_t size = lottoNumbers.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(userNumbers[i] == lottoNumbers[j]){
                count++;
            }
        }
    }
    return count;
}
void playLotto(int n, int rangeLow, int rangeHigh){
    // USER NUMBERS
    vector<int> userInput = userChoice(n, rangeLow, rangeHigh);
    cout << "User numbers :\t";
    printVector(userInput);
    cout << endl;

    // LOTTO NUMBERS
    vector<int> lottoNumbers = fillVector(n, rangeLow, rangeHigh);
    cout << "Lotto numbers :\t";
    printVector(lottoNumbers);
    cout << endl;
    int matches = matchingCount(userInput, lottoNumbers);
    cout << endl << "Match count : " << matches << endl;
    while(matches < 6){
        vector<int> userInput = userChoice(n, rangeLow, rangeHigh);
        vector<int> lottoNumbers = fillVector(n, rangeLow, rangeHigh);
        cout << "Lotto numbers :\t";
        printVector(lottoNumbers);
        cout << endl;
        matches = matchingCount(userInput, lottoNumbers);
        cout << endl << "Match count : " << matches << endl;
    }
}
int main() {
    int n = 7;
    int rangeLow = 0;
    int rangeHigh = 39;
    playLotto(n, rangeLow, rangeHigh);
    return 0;
}
```


