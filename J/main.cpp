#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> queue;
    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        if (tmp[0] == '+') {
            queue.push_back(tmp.substr(2,tmp.length()-2));
        } else if (tmp[0] == '*') {
            queue.insert(queue.end()-queue.size()/2, tmp.substr(2,tmp.length()-2));
        } else {
            cout << queue[0] << endl;
            queue.erase(queue.begin());
        }
    }

    return 0;
}
