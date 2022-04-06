#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int counters[26];
int weights[26];

bool compare(char a, char b) {
    if (counters[a - 97] == 1) {
        return counters[b - 97] != 1;
    }
    if (counters[b - 97] == 1) {
        return false;
    }
    return weights[a - 97] < weights[b - 97];
}

int main() {
    string word;
    cin >> word;
    std::fill(counters, counters + 26, 0);
    for (auto &el: word) {
        counters[el - 97]++;
    }
    for (auto &el: weights) {
        cin >> el;
    }
    sort(word.rbegin(), word.rend(), compare);

    for (int i = word.size() - 1; i >= 0; ) {
        if (counters[word[i] - 97] != 1) {
            word.push_back(word[i]);
            word.erase(word.begin() + i);
            i--;
        }
        i-=counters[word[i] - 97];
    }
    cout << word;

    return 0;
}
