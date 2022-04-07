#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int counters[26];
int weights[26];

bool compare(char a, char b) {
    return weights[a - 97] < weights[b - 97];
}

int main() {
    string word, new_word;
    cin >> word;

    std::fill(counters, counters + 26, 0);
    for (auto &el: word) {
        counters[el - 97]++;
    }

    for (int i = 0; i < 26; i++) {
        cin >> weights[i];
        if (weights[i] && counters[i] > 1) {
            new_word += (char) (97 + i);
            counters[i] -= 2;
        }
    }
    sort(new_word.rbegin(), new_word.rend(), compare);

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < counters[i]; j++) {
            new_word += (char) (97 + i);
        }
    }

    for (int i = word.length() - new_word.length() - 1; i >= 0; i--) {
        new_word += new_word[i];
    }
    cout << new_word;

    return 0;
}
