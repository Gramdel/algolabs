#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coordinates(n);

    for(auto& el : coordinates) {
        cin >> el;
    }
    sort(coordinates.begin(), coordinates.end());

    for(int el : coordinates) {
        cout << el << endl;
    }

    return 0;
}
