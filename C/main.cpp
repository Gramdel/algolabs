#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <regex>

using namespace std;

int main() {
    map<string, stack<int> *> map_of_vars;
    string s;

    while (getline(cin, s)) {
        if (s.empty()) {
            break;
        } else if (s[0] == '{') {
            for (auto &pair: map_of_vars) {
                pair.second->push(pair.second->top());
            }
        } else if (s[0] == '}') {
            for (auto &pair: map_of_vars) {
                if (pair.second->size() == 1) {
                    pair.second->top() = 0;
                } else {
                    pair.second->pop();
                }
            }
        } else {
            int middle = (int) s.find('=');
            string left = s.substr(0, middle);
            string right = s.substr(middle + 1, s.length() - middle - 1);

            if (map_of_vars.find(left) == map_of_vars.end()) {
                map_of_vars[left] = new stack<int>;
                map_of_vars[left]->push(0);
            }

            if (left == right) {
                cout << map_of_vars[left]->top() << endl;
                continue;
            }

            regex exp("-?\\d+");
            if (regex_match(right, exp)) {
                map_of_vars[left]->top() = stoi(right);
            } else {
                if (map_of_vars.find(right) == map_of_vars.end()) {
                    map_of_vars[right] = new stack<int>;
                    map_of_vars[right]->push(0);
                }
                map_of_vars[left]->top() = map_of_vars[right]->top();
                cout << map_of_vars[right]->top() << endl;
            }
        }
    }

    for (auto &pair: map_of_vars) {
        delete pair.second;
    }

    return 0;
}
