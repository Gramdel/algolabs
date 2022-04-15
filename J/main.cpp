#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    list<string> left;
    list<string> right;
    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        if (tmp[0] == '+') {
            right.push_back(tmp.substr(2, tmp.length() - 2));
        } else if (tmp[0] == '*') {
            right.push_front(tmp.substr(2, tmp.length() - 2));
        } else {
            cout << left.front() << endl;
            left.pop_front();
        }
        if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    return 0;
}
