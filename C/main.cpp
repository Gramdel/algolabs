#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <list>

using namespace std;

bool is_number(const string &s) {
    bool first_el = true;
    for (char const &c: s) {
        if (first_el) {
            first_el = false;
            if (c == '-') {
                continue;
            }
        }
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    map<string, stack<string> *> vars_and_values;
    stack<list<string> *> changes;
    string s;

    while (getline(cin, s)) {
        if (s.empty()) {
            break;
        } else if (s[0] == '{') {
            changes.push(new list<string>);
            continue;
        } else if (s[0] == '}') {
            for (const auto &name: *changes.top()) {
                vars_and_values[name]->pop();
            }
            changes.pop();
            continue;
        } else {
            int middle = (int) s.find('=');
            string left = s.substr(0, middle);
            string right = s.substr(middle + 1, s.length() - middle - 1);

            if (vars_and_values.find(left) == vars_and_values.end()) {
                vars_and_values[left] = new stack<string>;
                vars_and_values[left]->push("0");
            }
            if (left == right) {
                cout << vars_and_values[left]->top() << endl;
                continue;
            }
            if (!changes.empty()) {
                changes.top()->push_back(left);
            }

            if (is_number(right)) {
                vars_and_values[left]->push(right);
            } else {
                if (vars_and_values.find(right) == vars_and_values.end()) {
                    vars_and_values[right] = new stack<string>;
                    vars_and_values[right]->push("0");
                }
                vars_and_values[left]->push(vars_and_values[right]->top());
                cout << vars_and_values[right]->top() << endl;
            }
        }
    }

    for (auto &pair: vars_and_values) {
        delete pair.second;
    }

    return 0;
}