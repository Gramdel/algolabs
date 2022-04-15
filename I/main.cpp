#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <functional>

using namespace std;

vector<list<int>> distances;

bool compare(int a, int b) {
    cout << a << " > " << b << " = ";
    if (distances[a - 1].empty()) {
        cout << false << endl;
        return false;
    } else if (distances[b - 1].empty()) {
        cout << true << endl;
        return true;
    }
    cout << (distances[a - 1].front() < distances[b - 1].front()) << endl;
    return distances[a - 1].front() < distances[b - 1].front();
}

int main() {
    int n, k, p, count = 0;
    cin >> n >> k >> p;

    vector<int> order(p);
    distances.resize(n);
    for (int i = 0; i < p; i++) {
        cin >> order[i];
        distances[order[i] - 1].push_back(i);
    }

    set<int> floor;
    for (int i = 0; i < p; i++) {
        if (floor.find(order[i]) == floor.end()) {
            if (floor.size() == k) {
                priority_queue<int, vector<int>, function<bool(int, int)>> priorities(compare);
                for (int j = 1; j <= n; j++) {
                    if (j != order[i]) {
                        priorities.push(j);
                    }
                }
                floor.erase(priorities.top());
            }
            floor.insert(order[i]);
            count++;
        }
        distances[order[i] - 1].pop_front();
    }
    cout << count;

    return 0;
}
