#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    list<int> window;
    list<int> indexes;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        while (!window.empty() && window.back() > tmp) {
            window.pop_back();
            indexes.pop_back();
        }
        window.push_back(tmp);
        indexes.push_back(i);

        if (i + 1 >= k) {
            cout << window.front() << " ";
        }
        if (i + 1 - indexes.front() >= k) {
            window.pop_front();
            indexes.pop_front();
        }
    }
    return 0;
}
