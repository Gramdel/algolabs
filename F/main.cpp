#include <iostream>
#include <string>
#include <vector>

using namespace std;

string choose_greater(string a, string b) {
    if (a.empty()) {
        return "";
    } else if (a[0] == b[0]) {
        return a[0] + choose_greater(a.substr(1, a.length() - 1), b.substr(1, b.length() - 1));
    } else if (a[0] > b[0]) {
        return a;
    } else {
        return b;
    }
}

int main() {
    short n;
    cin >> n;

    vector<string> chunks;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        chunks.push_back(tmp);
    }

    cout << choose_greater("123", "124") << endl;
    cout << choose_greater("123", "133") << endl;
    cout << choose_greater("3", "2") << endl;
    cout << choose_greater("123", "223") << endl;
    cout << choose_greater("1", "1");

    return 0;
}
