#include <iostream>
#include <string>
#include <list>

using namespace std;

bool choose_greater(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    list<string> chunks;
    string tmp;

    while (cin >> tmp) {
        chunks.push_front(tmp);
    }
    chunks.sort(choose_greater);

    for (const auto &el: chunks) {
        cout << el;
    }

    return 0;
}
