#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Check number of repetitions of columns in 2D matrix
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
//        v.resize(0);
    }
    int size1 = vOfVectors.size();
    set<vector<int>> s(std::make_move_iterator(vOfVectors.begin()),
                       std::make_move_iterator(vOfVectors.end()));
    cout << "Broj ponavljanja je : " << size1 - s.size();

//    if (equal(vOfVectors[0].begin(), vOfVectors[0].end(), vOfVectors[1].begin())){
//        cout << "columns are equal" << endl;
//    }
//    else
//        cout << "columns are not equal" << endl;

    return 0;
}

