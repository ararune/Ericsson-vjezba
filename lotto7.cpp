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
