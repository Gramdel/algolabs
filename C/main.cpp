#include <iostream>
#include <string>
#include <map>
#include <regex>

using namespace std;

void parse(string s, map<string, int> map_of_vars) {
    if (s[0] == '{') {
        return;
        //next call
    } else if (s[0] == '}') {
        return;
        //next call
    } else {
        int middle = (int) s.find('=');
        string left = s.substr(0, middle);
        string right = s.substr(middle + 1, s.length() - middle-1);

        cout << left << " " << right << endl;

        regex exp("\\d+");
        if (regex_match(right, exp)) {
            cout << "MATCH\n";
        }
    }
}

int main() {
    map<string, int> map_of_vars;

    string s;

    while (getline(cin, s)) {
        if (s.empty()) {
            break;
        }
        parse(s, map_of_vars);
    }

    return 0;
}
