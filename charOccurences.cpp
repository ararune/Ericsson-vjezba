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

